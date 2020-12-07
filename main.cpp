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
    int j = 1;
    int* t = new int[10000000];
    while(j != 0) j++;
    std::cout << j;
    return t[j];
}

int main()
{
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