//
// Created by pedrosoares on 6/23/19.
//

#include "DataObjectException.h"

DataObjectException::DataObjectException() : Exception() {}

DataObjectException::DataObjectException(std::string message) : Exception(std::move(message)) {}