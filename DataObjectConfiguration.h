#ifndef TIGREFRAMEWORK_DATAOBJECTCONFIGURATION_H
#define TIGREFRAMEWORK_DATAOBJECTCONFIGURATION_H


#include "DataObject.h"

class DataObjectConfiguration {

public:
    virtual ~DataObjectConfiguration() = default;
    virtual DataObject* getInstance(const string &dns, const string &username, const string &passwd, const map<string, string> &options){};

};


#endif //TIGREFRAMEWORK_DATAOBJECTCONFIGURATION_H
