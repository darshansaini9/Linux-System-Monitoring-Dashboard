#include "../include/cpu.h"
#include <fstream>
#include <string>
#include <thread>
#include <chrono>

float getCPUUsage()
{
    unsigned long user1, nice1, system1, idle1;
    unsigned long user2, nice2, system2, idle2;
    std::string cpu;

    std::ifstream file1("/proc/stat");
    file1 >> cpu >> user1 >> nice1 >> system1 >> idle1;
    file1.close();

    std::this_thread::sleep_for(
        std::chrono::milliseconds(100));

    std::ifstream file2("/proc/stat");
    file2 >> cpu >> user2 >> nice2 >> system2 >> idle2;
    file2.close();

    unsigned long total1 =
        user1 + nice1 + system1 + idle1;

    unsigned long total2 =
        user2 + nice2 + system2 + idle2;

    unsigned long totalDiff =
        total2 - total1;

    unsigned long idleDiff =
        idle2 - idle1;

    return 100.0 *
           (totalDiff - idleDiff) /
           totalDiff;
}
