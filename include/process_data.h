#ifndef PROCESS_DATA_H
#define PROCESS_DATA_H

#include <string>

struct Process
{
    std::string pid;
    std::string name;
    long memory;
};

#endif
