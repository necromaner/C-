#include <iostream>
#include "cpptoml.h"

struct MySQLArg{
    std::string host;
    int32_t port;
    std::string database;
    std::string username;
    std::string password;
};

bool readMySQLConfig(const char *file, MySQLArg &mysqlArg);

int main()
{
    char filename[] = "/Users/necromaner/program/C-/BioHit/cpptoml/mysql.toml";
    MySQLArg mysqlArg;

    if (readMySQLConfig(filename, mysqlArg)) {
        std::cout << "    Host:" << mysqlArg.host << std::endl;
        std::cout << "    Port:" << mysqlArg.port << std::endl;
        std::cout << "Database:" << mysqlArg.database << std::endl;
        std::cout << "Username:" << mysqlArg.username << std::endl;
        std::cout << "Password:" << mysqlArg.password << std::endl;
    }

    return 0;
}

bool readMySQLConfig(const char *file, MySQLArg &mysqlArg)
{
    std::shared_ptr<cpptoml::table> g;
    try {
        g = cpptoml::parse_file(file);
    } catch (const cpptoml::parse_exception &e) {
        std::cerr << "parse_file error: " << e.what() << std::endl;
        return false;
    }

    auto Strings = [&](const char *key, const char * value)->std::string {
        if (g->contains_qualified(key)) {
            return g->get_qualified(key)->as<std::string>()->get();
        }
        if (!value)
            return std::string();
        return std::string(value);
    };

    auto Integer = [&](const char *key, int value)->int {
        if (g->contains_qualified(key)) {
            auto integer = g->get_qualified(key)->as<int64_t>()->get();
            return static_cast<int>(integer);
        }
        return value;
    };


    mysqlArg.host = Strings("MySQL.Host", "127.0.0.1");
    mysqlArg.port = Integer("MySQL.Port", 3306);
    mysqlArg.database = Strings("MySQL.Database", "testdb");
    mysqlArg.username = Strings("MySQL.Useranme", "root");
    mysqlArg.password = Strings("MySQL.Password", "123456");

    return true;
}