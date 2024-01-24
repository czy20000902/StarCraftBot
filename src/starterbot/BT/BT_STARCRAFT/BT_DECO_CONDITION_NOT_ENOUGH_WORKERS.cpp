#include "BT_DECO_CONDITION_NOT_ENOUGH_WORKERS.h"
#include "../Data.h"
#include <BWAPI.h>
#include "../../Tools.h"

BT_DECO_CONDITION_NOT_ENOUGH_WORKERS::BT_DECO_CONDITION_NOT_ENOUGH_WORKERS(std::string name, BT_NODE* parent)
	: BT_DECO_CONDITION(name, parent, IsThereNotEnoughWorkers)
{
}


std::string BT_DECO_CONDITION_NOT_ENOUGH_WORKERS::GetDescription()
{
	return "DECO_CONDITION_NOT_ENOUGH_WORKERS";
}

bool BT_DECO_CONDITION_NOT_ENOUGH_WORKERS::IsThereNotEnoughWorkers(void* data)
{
	Data* pData = (Data*)data;

	const BWAPI::UnitType workerType = BWAPI::Broodwar->self()->getRace().getWorker();
	const int workersOwned = Tools::CountUnitsOfType(workerType, BWAPI::Broodwar->self()->getUnits());
	const int morphing = Tools::CountUnitsOfType(BWAPI::UnitTypes::Zerg_Egg, BWAPI::Broodwar->self()->getUnits());
	if (morphing > 0)
		return false;
	else
		return workersOwned < pData->nWantedWorkersTotal;
}
