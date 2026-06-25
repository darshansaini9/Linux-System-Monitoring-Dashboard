# Linux System Monitoring Dashboard

A real-time Linux System Monitoring Dashboard built with **C++**, **Linux System APIs**, and **MySQL**. The application monitors system resources, tracks running processes, stores historical performance metrics, and provides basic analytics through a terminal-based interface.

## Features

* Real-time CPU usage monitoring
* Memory usage monitoring
* Disk usage monitoring
* System uptime tracking
* Top 10 memory-consuming processes
* Automatic MySQL logging of system metrics
* Historical performance analytics
* Average CPU usage calculation
* Average memory usage calculation
* Peak CPU usage tracking
* Recent system log display
* Modular C++ architecture

## Technologies Used

* C++
* Linux `/proc` filesystem
* MySQL
* MySQL Connector/C++
* STL (Vector, Sort, Filesystem)
* GNU g++

## Project Structure

```text
linux-system-monitor/
│
├── include/
│   ├── analytics.h
│   ├── cpu.h
│   ├── database.h
│   ├── disk.h
│   ├── memory.h
│   ├── process.h
│   └── uptime.h
│
├── src/
│   ├── analytics.cpp
│   ├── cpu.cpp
│   ├── database.cpp
│   ├── disk.cpp
│   ├── main.cpp
│   ├── memory.cpp
│   ├── process.cpp
│   └── uptime.cpp
│
├── Makefile
├── README.md
└── .gitignore
```

## Installation

Clone the repository:

```bash
git clone https://github.com/YOUR_USERNAME/linux-system-monitor.git
cd linux-system-monitor
```

Compile:

```bash
g++ -std=c++17 src/*.cpp -Iinclude -lmysqlcppconn -o monitor
```

Run:

```bash
./monitor
```

## Sample Output

```text
===== Linux System Monitor =====

CPU Usage    : 2.50%
Memory Usage : 12.57%
Disk Usage   : 6.62%
Uptime       : 1h 32m 17s

===== Top 10 Memory Consuming Processes =====

PID     NAME                MEM(KB)
5658    brave               717900
7933    mysqld              533340
5560    brave               380468

===== Analytics =====

Average CPU Usage : 3.39%
Average Memory Usage : 12.15%
Peak CPU Usage : 26.67%

Recent Logs
2026-06-24 18:23:38 | CPU=0.84% | MEM=12.60% | DISK=6.61%
```

## Future Improvements

* Process CPU utilization
* Network monitoring
* Multi-machine distributed monitoring
* Export reports to CSV
* ncurses-based interactive dashboard
* Web dashboard
* Alert system for high resource usage

## Author

**Darshan Saini**

B.Tech Computer Science & Engineering (Cyber Security)

Poornima College of Engineering, Jaipur
