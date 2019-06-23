//
// Created by pedrosoares on 5/8/18.
//

#ifndef TGDATABASE_DATABASE_H
#define TGDATABASE_DATABASE_H

#include <string>
#include <vector>
#include <TigreFramework/Core/Kernel/Application/Configurable.h>
#include "Value.h"
#include "Line.h"

class Database : public Configurable {

    public:
        Database() = default;
        ~Database() = default;
        /**
         * This could be a singleton or a pool
         * that's depends on the Driver Implementation
         * @return Database Connection
         */
        static Database* connection();
        /**
         * This could be a singleton or a pool
         * that's depends on the Driver Implementation
         * @return Database Connection
         */
        static Database* connection(std::string driver);
        /**
         * Prepare SQL with parameters and Execute
         * @param sql
         * @param values
         * @return Result of the Query
         */
        virtual Lines execute(std::string sql, std::vector<Value> values) = 0;
        /**
         * Just execute the SQL and Return the result
         * @param sql
         * @return Result of the Query
         */
        virtual Lines execute(std::string sql) = 0;

    protected:
        static std::string default_connection;
        static std::map<std::string, std::map<std::string, std::string>> connections;

        static std::map<std::string, std::string> getConfiguration(std::string connection_name = "");


};


#endif //TGDATABASE_DATABASE_H
