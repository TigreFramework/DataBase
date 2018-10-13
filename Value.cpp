//
// Created by pedro on 01/12/17.
//

#include <iostream>
#include <TigreFramework/Core/Kernel/Exception.h>
#include <TigreFramework/Types/Math.h>
#include "Value.h"

Value::Value(int rhs) : iValue(rhs), type(2) { }

Value::Value(float rhs) : fValue(rhs), type(3) { }

Value::Value(double rhs) : dValue(rhs), type(4) { }

Value::Value(string rhs) : sValue(rhs), type(1) { }

Value::Value(const char rhs[]) : sValue(rhs), type(1) { }

Value& Value::operator=(const int &rhs) {
    this->type   = 2;
    this->iValue = rhs;
    return *this;
}

Value& Value::operator=(const float &rhs) {
    this->type   = 3;
    this->fValue = rhs;
    return *this;
}

Value& Value::operator=(const double &rhs) {
    this->type   = 4;
    this->dValue = rhs;
    return *this;
}

Value& Value::operator=(const string &rhs) {
    this->type   = 1;
    this->sValue = rhs;
    return *this;
}

/*Value::operator std::string() const {
    if(isString()){
        return this->sValue;
    } else if(isInteger()) {
        return to_string(this->iValue);
    } else if(isFloat()) {
        return to_string(this->fValue);
    } else if(isDouble()) {
        return to_string(this->dValue);
    }
    throw Exception("Value not found");
}*/

Value::operator int() const {
    if(isString()){
        return Math::toInt(this->sValue);
    } else if(isInteger()) {
        return this->iValue;
    } else if(isFloat()) {
        return (int)(this->fValue);
    } else if(isDouble()) {
        return (int)(this->dValue);
    }
    throw Exception("Value not found, the type is (" + std::to_string(this->type) + ")");
}

Value::operator float() const {
    if(isString()){
        return Math::toFloat(this->sValue);
    } else if(isInteger()) {
        return (float)(this->iValue);
    } else if(isFloat()) {
        return this->fValue;
    } else if(isDouble()) {
        return (float)(this->dValue);
    }
    throw Exception("Value not found, the type is (" + std::to_string(this->type) + ")");
}

Value::operator double() const {
    if(isString()){
        return Math::toDouble(this->sValue);
    } else if(isInteger()) {
        return (double)(this->iValue);
    } else if(isFloat()) {
        return (double)(this->fValue);
    } else if(isDouble()) {
        return this->dValue;
    }
    throw Exception("Value not found, the type is (" + std::to_string(this->type) + ")");
}

bool Value::isDouble() const {
    return this->type == 4;
}

bool Value::isFloat() const {
    return this->type == 3;
}

bool Value::isInteger() const {
    return this->type == 2;
}

bool Value::isString() const {
    return this->type == 1;
}

double Value::getDouble() const {
    return this->dValue;
}

float Value::getFloat() const {
    return this->fValue;
}

int Value::getInteger() const {
    return this->iValue;
}

string Value::getString() const {
    return this->sValue;
}

void to_json(nlohmann::json& j, const Value& p) {
    if(p.isDouble()){
        j = p.getDouble();
    }
    if(p.isFloat()){
        j = p.getFloat();
    }
    if(p.isInteger()){
        j = p.getInteger();
    }
    if(p.isString()){
        j = p.getString();
    }
}