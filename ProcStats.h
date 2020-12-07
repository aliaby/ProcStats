//
// Created by Ali Abyaneh on 2020-12-06.
//

#ifndef PROCSTATS_PROCSTATS_H
#define PROCSTATS_PROCSTATS_H

#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <iterator>

#define UTIME 13
#define STIME 14
#define CUTIME 15
#define CSTIME 16
#define NICE 18
#define STARTTIME 21
#define TOTAL_PROGRAM_SIZE 0
#define RESIDENT_SET_SIZE 1
#define SHARED_PAGES 2
#define DATA_PLUS_STACK 5

class ProcStats {
public:
    ProcStats(unsigned pid, bool utilization, bool memory, bool net, bool read): pid_(pid) {
        curr_active_time = curr_idle_time = curr_net_usage = 0;
        if(read)
            read_data(utilization, memory, net);
    };
    void read_data(bool utilization, bool memory, bool net);
    void print(){
        std::cout << "pid : "<< pid_ << std::endl;
        std::cout << "curr_active_time : "<< curr_active_time << std::endl;
        std::cout << "curr_mem_usage : "<< curr_net_usage << std::endl;
        std::cout << "curr_net_usage : "<< curr_net_usage << std::endl;
        std::cout << "start time : "<< start_time << std::endl;
    }

private:
    unsigned pid_;
    unsigned curr_active_time;
    unsigned curr_idle_time;
    unsigned total_program_size;
    unsigned resident_set_size;
    unsigned total_shared_pages;
    unsigned total_data_stack_size;
    unsigned curr_net_usage;
    unsigned start_time;

    void read_time();
    void read_mem();
    void read_net();
};


#endif //PROCSTATS_PROCSTATS_H
