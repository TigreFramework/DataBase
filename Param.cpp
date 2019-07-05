#include <TigreFramework/String/String.h>
#include "DataObjectStatement.h"
#include "Param.h"

Param::Param(std::initializer_list<Value>  params) {
    int j = 0;
    for(const auto &i : params) {
        this->paramsByIndex[j++] = i;
    }
}

Param::Param(std::initializer_list<std::pair<int, Value>>  params) {
    for(const auto &i : params) {
        this->paramsByIndex[i.first] = i.second;
    }
}

Param::Param(std::initializer_list<std::pair<std::string, Value>>  params) {
    for(const auto &i : params) {
        this->paramsByName[i.first] = i.second;
    }
}

Param::Param(map<int, Value> params) {
    this->paramsByIndex = std::move(params);
}

Param::Param(map<string, Value> params) {
    this->paramsByName = std::move(params);
}

Param::Param(vector<Value> params) {
    for (int i = 0; i < params.size(); ++i) {
        this->paramsByIndex[i] = params[i];
    }
}


void Param::set(map<int, Value> params) {
    this->paramsByIndex = std::move(params);
}

void Param::set(map<string, Value> params) {
    this->paramsByName = std::move(params);
}

void Param::set(vector<Value> params) {
    for (int i = 0; i < params.size(); ++i) {
        this->paramsByIndex[i] = params[i];
    }
}

Param& Param::operator=(const vector<Value> &params) {
    for (int i = 0; i < params.size(); ++i) {
        this->paramsByIndex[i] = params[i];
    }
    return *this;
}

Param& Param::operator=(const map<int, Value> &params) {
    this->paramsByIndex = params;
    return *this;
}

Param& Param::operator=(const map<string, Value> &params) {
    this->paramsByName = params;
    return *this;
}

std::string Param::bind(const std::string& sql, DataObjectStatement* statement) const {
    Tigre::String sql_1 = sql;

    for(auto param : this->paramsByName){
        sql_1.replace(param.first, this->valueToSting(param.second, statement));
    }

    std::string sql_2;
    int j = -1;
    for (char i : sql_1.getValue()) {
        if (i == '?' && this->paramsByIndex.find(++j) != this->paramsByIndex.end()) {
            sql_2 += this->valueToSting(this->paramsByIndex.at(j), statement);
        } else {
            sql_2 += std::string(1, i);
        }
    }

    return sql_2;
}

std::string Param::valueToSting(const Value& value, DataObjectStatement* statement) const {
    std::string result;
    if (value.isString()) {
        result += statement->quote(value.getString());
    } else if (value.isInteger()) {
        result += std::to_string(value.getInteger());
    } else if (value.isFloat()) {
        result += std::to_string(value.getFloat());
    } else if (value.isDouble()) {
        result += std::to_string(value.getDouble());
    }
    return result;
}