//
// Created by pedrosoares on 5/8/18.
//

#include "Database.h"
#include <TigreFramework/Core/Kernel/Exception.h>

Database* Database::connection() {
    throw Exception("Driver not Set Up");
}
