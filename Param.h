#ifndef TIGREFRAMEWORK_PARAM_H
#define TIGREFRAMEWORK_PARAM_H

#include <map>
#include <vector>
#include "Value.h"

class DataObjectStatement;

using namespace std;

class Param {

    public:
        Param() = default;

        Param(std::initializer_list<Value>  params);

        Param(std::initializer_list<std::pair<int, Value>>  params);

        Param(std::initializer_list<std::pair<std::string, Value>>  params);

        explicit Param(map<int, Value>  params);
        explicit Param(map<string, Value>  params);
        explicit Param(vector<Value>  params);

        Param& operator=(const map<int, Value>&  params);
        Param& operator=(const map<string, Value>&  params);
        Param& operator=(const vector<Value>&  params);

        void set(map<int, Value>  params);
        void set(map<string, Value>  params);
        void set(vector<Value>  params);

        std::string bind(const std::string& sql, DataObjectStatement* statement) const ;

    protected:
        virtual std::string valueToSting(const Value& value, DataObjectStatement* statement) const ;

    private:
        map<int, Value>  paramsByIndex;
        map<string, Value>  paramsByName;

};


#endif //TIGREFRAMEWORK_PARAM_H
