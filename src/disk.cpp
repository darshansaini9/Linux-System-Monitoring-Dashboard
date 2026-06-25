#include "../include/disk.h"
#include <sys/statvfs.h>

float getDiskUsage()
{
    struct statvfs stat;

    statvfs("/", &stat);

    unsigned long total =
        stat.f_blocks * stat.f_frsize;

    unsigned long free =
        stat.f_bfree * stat.f_frsize;

    unsigned long used =
        total - free;

    return ((float)used / total) * 100;
}
