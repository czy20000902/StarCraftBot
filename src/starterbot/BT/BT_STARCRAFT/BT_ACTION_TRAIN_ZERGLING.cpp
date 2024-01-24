#include "BT_ACTION_TRAIN_ZERGLING.h"
#include "../../Tools.h"
#include "../Data.h"

BT_ACTION_TRAIN_ZERGLING::BT_ACTION_TRAIN_ZERGLING(std::string name, BT_NODE* parent)
    : BT_ACTION(name, parent)
{
}

BT_NODE::State BT_ACTION_TRAIN_ZERGLING::Evaluate(void* data)
{
    return ReturnState(TrainZergling(data));
}

std::string BT_ACTION_TRAIN_ZERGLING::GetDescription()
{
    return "TRAIN ZERGLING";
}


BT_NODE::State BT_ACTION_TRAIN_ZERGLING::TrainZergling(void* data)
{
    Data* pData = (Data*)data;

    const BWAPI::UnitType unitType = BWAPI::UnitTypes::Enum::Enum::Zerg_Zergling;
    const BWAPI::Unit myDepot = Tools::GetDepot();

    // if we have a valid depot unit and it's currently not training something, train a worker
    // there is no reason for a bot to ever use the unit queueing system, it just wastes resources

    if (myDepot && !myDepot->isTraining())
    {
        myDepot->train(unitType);
        BWAPI::Error error = BWAPI::Broodwar->getLastError();
        if (error != BWAPI::Errors::None)
            return BT_NODE::FAILURE;
        else return BT_NODE::SUCCESS;
    }

    return BT_NODE::FAILURE;
}