#include "../include/database.h"

#include <iostream>
#include <mysql_driver.h>
#include <mysql_connection.h>
#include <cppconn/statement.h>
#include <cppconn/exception.h>

void saveMetrics(
    float cpu,
    float memory,
    float disk
)
{
    try
    {
        sql::mysql::MySQL_Driver *driver;
        sql::Connection *con;
        sql::Statement *stmt;

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

        stmt->execute(
            "INSERT INTO system_metrics "
            "(cpu_usage,memory_usage,disk_usage)"
            " VALUES ("
            + std::to_string(cpu)
            + ","
            + std::to_string(memory)
            + ","
            + std::to_string(disk)
            + ")"
        );

        delete stmt;
        delete con;
    }
    catch(sql::SQLException &e)
    {
        std::cerr
            << "Database Error: "
            << e.what()
            << std::endl;
    }
}
