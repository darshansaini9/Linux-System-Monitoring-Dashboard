#include <string>
#include "../include/analytics.h"

#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/resultset.h>

void showAnalytics()
{
    try
    {
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;
        sql::ResultSet *res;

        driver =
            sql::mysql::get_mysql_driver_instance();

        con =
            driver->connect(
                "tcp://127.0.0.1:3306",
                "monitor",
                "monitor123"
            );

        con->setSchema("system_monitor");

        stmt = con->createStatement();

        std::cout
            << "\n===== Analytics =====\n";

        res =
            stmt->executeQuery(
                "SELECT AVG(cpu_usage) avg_cpu "
                "FROM system_metrics"
            );

        if(res->next())
        {
            std::cout
                << "Average CPU Usage : "
                << res->getDouble("avg_cpu")
                << "%\n";
        }

        delete res;

        res =
            stmt->executeQuery(
                "SELECT AVG(memory_usage) avg_mem "
                "FROM system_metrics"
            );

        if(res->next())
        {
            std::cout
                << "Average Memory Usage : "
                << res->getDouble("avg_mem")
                << "%\n";
        }

        delete res;

        res =
            stmt->executeQuery(
                "SELECT MAX(cpu_usage) peak_cpu "
                "FROM system_metrics"
            );

        if(res->next())
        {
            std::cout
                << "Peak CPU Usage : "
                << res->getDouble("peak_cpu")
                << "%\n";
        }
     delete res;

std::cout
    << "\nRecent Logs\n";

res =
    stmt->executeQuery(
        "SELECT * "
        "FROM system_metrics "
        "ORDER BY created_at DESC "
        "LIMIT 5"
    );

while(res->next())
{
    std::cout
        << res->getString("created_at")
        << " | CPU="
        << res->getDouble("cpu_usage")
        << "% | MEM="
        << res->getDouble("memory_usage")
        << "% | DISK="
        << res->getDouble("disk_usage")
        << "%\n";
}
        delete res;
        delete stmt;
        delete con;
    }
    catch(sql::SQLException &e)
    {
        std::cerr
            << "Analytics Error: "
            << e.what()
            << std::endl;
    }
}
