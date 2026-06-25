#include "../include/uptime.h"
#include <fstream>

long getUptime()
{
    std::ifstream file("/proc/uptime");

    double uptime;

    file >> uptime;

    return (long)uptime;
}
