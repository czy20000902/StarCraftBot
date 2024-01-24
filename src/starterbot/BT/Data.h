#pragma once
#include <unordered_set>
#include <BWAPI.h>

#define THRESHOLD1_MINERALS 200
#define THRESHOLD1_UNUSED_SUPPLY -1 //Never build supply

#define NWANTED_WORKERS_TOTAL 6
#define NWANTED_WORKERS_FARMING_MINERALS 10
#define NWANTED_ZERGLINGS_TOTAL 6

#define NWANTED_SPAWNING_POOL_TOTAL 1


class Data {
public:
	int currMinerals;
	int thresholdMinerals;
	int currSupply;
	int thresholdSupply;

	int nWantedWorkersTotal;
	int nWantedWorkersFarmingMinerals;
	int nWantedZerglingsTotal;

	int nWantedSpawningPoolTotal;

	std::unordered_set<BWAPI::Unit> unitsFarmingMinerals;
};
