//
// Created by pedro on 01/12/17.
//

#include <iostream>
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

bool Value::isDouble() {
    return this->type == 4;
}

bool Value::isFloat() {
    return this->type == 3;
}

bool Value::isInteger() {
    return this->type == 2;
}

bool Value::isString() {
    return this->type == 1;
}

double Value::getDouble() {
    return this->dValue;
}

float Value::getFloat() {
    return this->fValue;
}

int Value::getInteger() {
    return this->iValue;
}

string Value::getString() {
    return this->sValue;
}