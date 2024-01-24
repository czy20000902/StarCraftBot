#include "BT_ACTION_BUILD_SPAWNING_POOL.h"
#include "../../Tools.h"
#include "../Data.h"

BT_ACTION_BUILD_SPAWNING_POOL::BT_ACTION_BUILD_SPAWNING_POOL(std::string name, BT_NODE* parent)
    : BT_ACTION(name, parent)
{
}

BT_NODE::State BT_ACTION_BUILD_SPAWNING_POOL::Evaluate(void* data)
{
    return ReturnState(BuildSpawningPool(data));
}

std::string BT_ACTION_BUILD_SPAWNING_POOL::GetDescription()
{
    return "BUILD SUPPLY PROVIDER";
}


BT_NODE::State BT_ACTION_BUILD_SPAWNING_POOL::BuildSpawningPool(void* data)
{
    Data* pData = (Data*)data;

    // let's build a supply provider
    const BWAPI::UnitType unitType = BWAPI::UnitTypes::Enum::Enum::Zerg_Spawning_Pool;

    const bool startedBuilding = Tools::BuildBuilding(unitType);

    if (startedBuilding)
        BWAPI::Broodwar->printf("Started Building %s", unitType.getName().c_str());

    return startedBuilding ? BT_NODE::SUCCESS : BT_NODE::FAILURE;
}