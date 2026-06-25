#include <sstream>
#include "../include/uptime.h"
#include "../include/disk.h"
#include "../include/cpu.h"
#include "../include/memory.h"
#include "../include/process.h"
#include "../include/database.h"
#include "../include/analytics.h"
#include <ncurses.h>
#include "../include/ui.h"
#include <iostream>
#include <thread>
#include <chrono>
#include <iomanip>

using namespace std;

int main()
{   
    while(true)
{
    system("clear");

    float cpu = getCPUUsage();
    float mem = getMemoryUsage();
    float disk = getDiskUsage();

    cout << fixed << setprecision(2);

    cout << "===== Linux System Monitor =====" << endl;
    cout << "CPU Usage    : " << cpu << "%" << endl;
    cout << "Memory Usage : " << mem << "%" << endl;
    cout << "Disk Usage   : " << disk << "%" << endl;

    long uptime = getUptime();
    long hours = uptime / 3600;
    long minutes = (uptime % 3600) / 60;
    long seconds = uptime % 60;

    cout << "Uptime       : "
         << hours << "h "
         << minutes << "m "
         << seconds << "s" << endl;

    showProcesses();
    showAnalytics();

    static int counter = 0;

    if(counter == 0 || counter >= 60)
    {
        saveMetrics(cpu, mem, disk);
        counter = 0;
    }

    counter++;

    this_thread::sleep_for(
        chrono::seconds(1)
    );
}
    endwin();
    return 0;
}
