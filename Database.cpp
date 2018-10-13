//
// Created by pedrosoares on 5/8/18.
//

#include "Database.h"
#include <TigreFramework/Core/Kernel/Exception.h>
#include <TigreFramework/Core/Kernel/Application/Configuration.h>

Database::Database() : Configurable(false) {

}

Database* Database::connection() {
    return Database::connection("");
}

Database* Database::connection(std::string driver) {
    return (Database *) Configuration::get("Database.driver." + (driver.empty() ? Database::default_connection : driver));
}

std::map<std::string, std::string> Database::getConfiguration(string connection_name) {
    return Database::connections[connection_name.empty() ? Database::default_connection : connection_name];
}