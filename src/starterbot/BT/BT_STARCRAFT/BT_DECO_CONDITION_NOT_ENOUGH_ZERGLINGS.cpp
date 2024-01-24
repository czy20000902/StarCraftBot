#include "BT_DECO_CONDITION_NOT_ENOUGH_ZERGLINGS.h"
#include "../Data.h"
#include <BWAPI.h>
#include "../../Tools.h"

BT_DECO_CONDITION_NOT_ENOUGH_ZERGLINGS::BT_DECO_CONDITION_NOT_ENOUGH_ZERGLINGS(std::string name, BT_NODE* parent)
    : BT_DECO_CONDITION(name, parent, IsThereNotEnoughZerglings)
{
}


std::string BT_DECO_CONDITION_NOT_ENOUGH_ZERGLINGS::GetDescription()
{
    return "DECO_CONDITION_NOT_ENOUGH_ZERGLINGS";
}

bool BT_DECO_CONDITION_NOT_ENOUGH_ZERGLINGS::IsThereNotEnoughZerglings(void* data)
{
    Data* pData = (Data*)data;

    const BWAPI::UnitType unitType = BWAPI::UnitTypes::Zerg_Zergling;
    const int zerglingsOwned = Tools::CountUnitsOfType(unitType, BWAPI::Broodwar->self()->getUnits());

    return zerglingsOwned < pData->nWantedZerglingsTotal;
}
