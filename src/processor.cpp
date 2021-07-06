#include "processor.h"
#include <unistd.h>
#include <cctype>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>
#include <iostream>

// TODO: Return the aggregate CPU utilization
float Processor::Utilization() {
    float util;
    std::vector<long> v;
    std::string data;
    std::string inputfile = "/proc/stat";
    std::ifstream filestream(inputfile);
    std::string line;

    if (filestream.is_open()) {
        std::getline(filestream, line);
    }
    
    std::istringstream linestream(line);

    while(linestream >> data) {
        if (data != "cpu") {
            v.push_back(std::stol(data));
        }
    }

    //Calculate utilisation from stored data
    long Idle,NonIdle,Total,idle,iowait,user,nice,system,irq,softirq,steal;
    
    idle = v[3];
    iowait = v[4];
    user = v[0];
    nice = v[1];
    system = v[2];
    irq = v[5];
    softirq = v[6];
    steal = v[7];

    Idle = idle + iowait;
    NonIdle = user + nice + system + irq + softirq + steal;
    Total = Idle + NonIdle;

    std::cout << Total << std::endl;
    std::cout << Idle << std::endl;
    std::cout << (Total - Idle) << std::endl;

    util = ((float)(Total - Idle) / (float)Total);

    return util; 
}