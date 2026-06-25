#include "../include/process.h"
#include <iomanip>
#include <iostream>
#include <filesystem>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

namespace fs = std::filesystem;

struct Process
{
    std::string pid;
    std::string name;
    long memory;
};

void showProcesses()
{
    std::vector<Process> processes;

    for(const auto& entry : fs::directory_iterator("/proc"))
    {
        std::string pid = entry.path().filename();

        if(!isdigit(pid[0]))
            continue;

        std::ifstream commFile(
            "/proc/" + pid + "/comm"
        );

        std::ifstream statusFile(
            "/proc/" + pid + "/status"
        );

        std::string name;
        std::string line;
        long memory = 0;

        if(commFile >> name)
        {
            while(std::getline(statusFile, line))
            {
                if(line.find("VmRSS:") == 0)
                {
                    std::stringstream ss(line);
                    std::string temp;

                    ss >> temp >> memory;

                    break;
                }
            }

            processes.push_back(
                {pid, name, memory}
            );
        }
    }

    std::sort(
        processes.begin(),
        processes.end(),
        [](const Process& a,
           const Process& b)
        {
            return a.memory > b.memory;
        }
    );

    std::cout
        << "\nTop 10 Memory Consuming Processes\n";

    std::cout
    << std::left
    << std::setw(8)  << "PID"
    << std::setw(20) << "NAME"
    << std::setw(12) << "MEM(KB)"
    << "\n";

    int limit =
        std::min(10,
                 (int)processes.size());

    for(int i = 0; i < limit; i++)
    {
        std::cout
    << std::left
    << std::setw(8)  << processes[i].pid
    << std::setw(20) << processes[i].name
    << std::setw(12) << processes[i].memory
    << "\n";
    }
}
