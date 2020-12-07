//
// Created by ali on 2020-12-06.
//

#include "ProcStatsCalculator.h"


void ProcStatsCalculator::start() {
    measurements_.push_back(std::pair<ProcStats, ProcStats> (ProcStats(pid_, utilization_, memory_, net_, true),
                                                          ProcStats(pid_, utilization_, memory_, net_, false)));
    measurements_.back().first.print();
}

void ProcStatsCalculator::finish() {
    measurements_.back().second.read_data(utilization_, memory_, net_);
    measurements_.back().first.print();
    measurements_.back().second.print();
}