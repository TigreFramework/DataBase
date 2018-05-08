//
// Created by pedrosoares on 5/8/18.
//

#ifndef TGDATABASE_DATABASE_H
#define TGDATABASE_DATABASE_H

#include <string>
#include <vector>
#include "Value.h"
#include "Line.h"

class Database {

    public:
        /**
         * This could be a singleton or a pool
         * that's depends on the Driver Implementation
         * @return Database Connection
         */
        static Database* connection();
        /**
         * Prepare SQL with parameters and Execute
         * @param sql
         * @param values
         * @return Result of the Query
         */
        virtual Line execute(std::string sql, std::vector<Value> values) = 0;
        /**
         * Just execute the SQL and Return the result
         * @param sql
         * @return Result of the Query
         */
        virtual Line execute(std::string sql) = 0;

};


#endif //TGDATABASE_DATABASE_H
