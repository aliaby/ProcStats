//
// Created by ali on 2020-12-06.
//

#include "ray/core_worker/ProcStats/ProcStats.h"

void ProcStats::read_data(bool utilization, bool memory, bool net) {
    if(utilization){
        try {
            read_time();
        }catch(const std::logic_error& e){
            std::cerr << e.what();
        }
    }
    if(memory){
        read_mem();
    }
    if(net){

    }

}


void ProcStats::read_mem() {
    std::string dir = "/proc/" + std::to_string(pid_);
    std::string::size_type sz;
    std::ifstream mem_stats(dir+"/statm", std::ifstream::in);
    std::vector<std::string> tokens;
    std::copy(std::istream_iterator<std::string>(mem_stats),
              std::istream_iterator<std::string>(),
              std::back_inserter(tokens));
    if(tokens.size() != 0) {
        total_program_size = std::stoi(tokens[TOTAL_PROGRAM_SIZE], &sz);
        total_shared_pages = std::stoi(tokens[SHARED_PAGES], &sz);
        total_data_stack_size = std::stoi(tokens[DATA_PLUS_STACK], &sz);
        resident_set_size = std::stoi(tokens[RESIDENT_SET_SIZE], &sz);
        mem_stats.close();
    }
}

void ProcStats::read_net() {}

void ProcStats::read_time() {
    std::string dir = "/proc/" + std::to_string(pid_);
    std::string::size_type sz;
    std::ifstream proc_stats(dir + "/stat", std::ifstream::in);
    std::string line;
    std::getline(proc_stats, line);
    proc_stats.close();
    std::istringstream iss(line);
    std::vector<std::string> tokens{std::istream_iterator<std::string>{iss},
                          std::istream_iterator<std::string>{}};
    if (std::stoul(tokens[0], &sz) != pid_)
        throw std::logic_error("reading wrong pid file!\n");

    curr_active_time = std::stoi(tokens[UTIME], &sz) +
                       std::stoi(tokens[STIME], &sz) +
                       std::stoi(tokens[CUTIME], &sz) +
                       std::stoi(tokens[CSTIME], &sz);

    start_time = std::stoi(tokens[STARTTIME], &sz);

}