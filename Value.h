//
// Created by pedro on 01/12/17.
//

#ifndef INTEGRATION_VALUE_H
#define INTEGRATION_VALUE_H

#include <string>
#include <nlohmann/json/single_include/nlohmann/json.hpp>

using namespace std;

class Value {

    public:
        Value() = default;
        Value(string rhs);
        Value(const char rhs[]);
        Value(int rhs);
        Value(double rhs);
        Value(float rhs);

        Value& operator=(const string& rhs);
        Value& operator=(const int& rhs);
        Value& operator=(const double& rhs);
        Value& operator=(const float& rhs);

        //explicit operator std::string() const;
        operator int() const;
        operator double() const;
        operator float() const;

        bool isFloat() const;
        bool isDouble() const ;
        bool isInteger() const;
        bool isString() const;

        float getFloat() const;
        double getDouble() const;
        int getInteger() const;
        string getString() const;

    private:
        string  sValue;
        int     iValue;
        double  dValue;
        float   fValue;
        /**
         * 1 String
         * 2 Integer
         * 3 Float
         * 4 Double
         */
        int     type = 0;
};

void to_json(nlohmann::json& j, const Value& p);

#endif //INTEGRATION_VALUE_H
