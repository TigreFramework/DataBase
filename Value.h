//
// Created by pedro on 01/12/17.
//

#ifndef INTEGRATION_VALUE_H
#define INTEGRATION_VALUE_H

#include <string>

using namespace std;

class Value {

    public:
        Value(string rhs);
        Value(const char rhs[]);
        Value(int rhs);
        Value(double rhs);
        Value(float rhs);

        Value& operator=(const string& rhs);
        Value& operator=(const int& rhs);
        Value& operator=(const double& rhs);
        Value& operator=(const float& rhs);

        bool isFloat();
        bool isDouble();
        bool isInteger();
        bool isString();

        float getFloat();
        double getDouble();
        int getInteger();
        string getString();

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


#endif //INTEGRATION_VALUE_H
