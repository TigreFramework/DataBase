//
// Created by pedrosoares on 6/23/19.
//

#ifndef TIGREFRAMEWORK_DATAOBJECTEXCEPTION_H
#define TIGREFRAMEWORK_DATAOBJECTEXCEPTION_H


#include <TigreFramework/Core/Kernel/Exception.h>

class DataObjectException : public Exception {

    public:
        DataObjectException();
        DataObjectException(std::string message);

};


#endif //TIGREFRAMEWORK_DATAOBJECTEXCEPTION_H
