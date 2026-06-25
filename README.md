# Linux System Monitoring Dashboard

A real-time **Linux System Monitoring Dashboard** built using **C++**, **Linux System APIs**, and **MySQL**. This project monitors system resources, tracks running processes, stores historical performance data, and provides analytics through a terminal-based interface.

---

## Features

### Real-Time System Monitoring

* CPU Usage Monitoring
* Memory Usage Monitoring
* Disk Usage Monitoring
* System Uptime Monitoring

### Process Monitoring

* Displays the Top 10 Memory-Consuming Processes
* Reads process information directly from the Linux `/proc` filesystem
* Sorts processes using C++ STL algorithms

### Database Integration

* MySQL database connectivity
* Automatic periodic logging of system metrics
* Historical performance data storage

### Analytics

* Average CPU Usage
* Average Memory Usage
* Peak CPU Usage
* Recent System Logs

### Software Design

* Modular C++ architecture
* Separate source and header files
* Easy to extend with additional monitoring modules

---

## Technologies Used

* C++
* Linux
* MySQL
* MySQL Connector/C++
* GNU g++
* STL (Vector, Sort, Filesystem)
* Linux `/proc` Filesystem
* Object-Oriented Programming

---

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
├── database/
│   └── schema.sql
│
├── screenshots/
│   └── dashboard.png
│
├── Makefile
├── README.md
└── .gitignore
```

---

# Dashboard Preview

Add your dashboard screenshot here.

```markdown
<img width="490" height="521" alt="image" src="https://github.com/user-attachments/assets/12c2f822-6174-4282-9819-2610e62bc9bd" />

```

---

# Installation

## 1. Clone the Repository

```bash
git clone https://github.com/darshansaini9/Linux-System-Monitoring-Dashboard

cd Linux-System-Monitoring-Dashboard
```

---

## 2. Install MySQL

Ubuntu

```bash
sudo apt update

sudo apt install mysql-server

sudo systemctl enable mysql

sudo systemctl start mysql
```

---

## 3. Install MySQL Connector for C++

```bash
sudo apt install libmysqlcppconn-dev
```

---

## 4. Create the Database

Run

```bash
sudo mysql < database/schema.sql
```

or manually

```bash
sudo mysql
```

```sql
CREATE DATABASE system_monitor;

USE system_monitor;

CREATE TABLE system_metrics
(
    id INT AUTO_INCREMENT PRIMARY KEY,
    cpu_usage FLOAT,
    memory_usage FLOAT,
    disk_usage FLOAT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
```

---

## 5. Create Database User

Inside MySQL

```sql
CREATE USER 'monitor'@'localhost'
IDENTIFIED BY 'monitor123';

GRANT ALL PRIVILEGES
ON system_monitor.*
TO 'monitor'@'localhost';

FLUSH PRIVILEGES;
```

---

## 6. Compile

```bash
g++ -std=c++17 src/*.cpp \
-Iinclude \
-lmysqlcppconn \
-o monitor
```

---

## 7. Run

```bash
./monitor
```

---

# Sample Output

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
3124    gnome-shell         302964
5611    brave               242556

===== Analytics =====

Average CPU Usage : 3.39%

Average Memory Usage : 12.15%

Peak CPU Usage : 26.67%

Recent Logs

2026-06-24 18:33:51 | CPU=5.04% | MEM=12.51% | DISK=6.62%
2026-06-24 18:31:07 | CPU=5.00% | MEM=12.83% | DISK=6.62%
2026-06-24 18:23:38 | CPU=0.84% | MEM=12.60% | DISK=6.62%
```

---

# Database Schema

```sql
CREATE DATABASE system_monitor;

USE system_monitor;

CREATE TABLE system_metrics
(
    id INT AUTO_INCREMENT PRIMARY KEY,
    cpu_usage FLOAT,
    memory_usage FLOAT,
    disk_usage FLOAT,
    created_at TIMESTAMP DEFAULT CURRENT_TIMESTAMP
);
```

---

# Future Enhancements

* CPU Usage Per Process
* Network Monitoring
* GPU Monitoring
* Temperature Monitoring
* CSV Report Export
* PDF Report Generation
* ncurses-based Interactive Dashboard
* Web Dashboard
* REST API
* Distributed Monitoring Across Multiple Linux Systems
* Email Alerts for High Resource Usage
* Docker Support

---

# Learning Outcomes

This project helped in understanding:

* Linux `/proc` Filesystem
* Linux System Programming
* Process Management
* Memory Monitoring
* File System APIs
* C++ STL
* Sorting Algorithms
* MySQL Integration
* Database Connectivity
* Modular Software Design

---

# Author

**Darshan Saini**

B.Tech Computer Science & Engineering (Cyber Security)

Poornima College of Engineering, Jaipur


---

# License

This project is released under the MIT License.
