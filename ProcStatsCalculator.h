//
// Created by ali on 2020-12-06.
//

#ifndef PROCSTATS_PROCSTATSCALCULATOR_H
#define PROCSTATS_PROCSTATSCALCULATOR_H

#include "ProcStats.h"
#include <vector>

class ProcStatsCalculator {
public:
    ProcStatsCalculator(unsigned pid, bool utilization = true, bool memory = true, bool net = true):
            pid_(pid), utilization_(utilization), memory_(memory), net_(net){};
    void start();
    void finish();
    ProcessStatistics get_stats();

private:
    unsigned pid_;
    bool utilization_;
    bool memory_;
    bool net_;
    std::vector<std::pair<ProcStats, ProcStats>> measurements_;
};


#endif //PROCSTATS_PROCSTATSCALCULATOR_H
