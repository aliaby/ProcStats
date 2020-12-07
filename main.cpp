//
// Created by ali on 2020-12-06.
//
#include "ProcStatsCalculator.h"
#include <chrono>
#include <thread>
#include <iostream>
#include <unistd.h>
#include <chrono>

int tureWhile(){
    int j = 0;
    for(int i = 0; i < 1000000; i++){
        j++;
    }
    //while(j != 0) j++;
}

int main()
{
    std::cout << sysconf(_SC_CLK_TCK) << std::endl;
    ProcStatsCalculator stat(getpid(), true, true, true);
    stat.start();
    auto start = std::chrono::high_resolution_clock::now();
    std::this_thread::sleep_for(std::chrono::milliseconds(1000));
    tureWhile();
    stat.finish();
    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;
    std::cout << "Elapsed time: " << elapsed.count() << " s\n";

}