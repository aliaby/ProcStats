//
// Created by ali on 2020-12-06.
//

#include "ray/core_worker/ProcStats/ProcStatsCalculator.h"


void ProcStatsCalculator::start() {
    measurements_.push_back(std::pair<ProcStats, ProcStats> (ProcStats(pid_, utilization_, memory_, net_, true),
                                                          ProcStats(pid_, utilization_, memory_, net_, false)));
}

void ProcStatsCalculator::finish() {
    measurements_.back().second.read_data(utilization_, memory_, net_);
}

ProcessStatistics ProcStatsCalculator::get_stats() {
  return (measurements_.back().second - measurements_.back().first).get_stats();
}