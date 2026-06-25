#include <fstream>
#include <string>

float getMemoryUsage()
{
    std::ifstream file("/proc/meminfo");

    std::string key;
    long total = 0;
    long available = 0;
    std::string unit;

    while(file >> key)
    {
        if(key == "MemTotal:")
        {
            file >> total >> unit;
        }
        else if(key == "MemAvailable:")
        {
            file >> available >> unit;
        }

        if(total && available)
            break;
    }

    return ((float)(total - available) /
            total) * 100;
}
