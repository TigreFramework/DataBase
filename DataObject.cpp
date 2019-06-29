#include <TigreFramework/String/String.h>
#include <TigreFramework/Database/Exceptions/DataObjectException.h>
#include <TigreFramework/Core/Kernel/Application/Configuration.h>
#include "DataObject.h"
#include "DataObjectConfiguration.h"

DataObject::DataObject(string dns, string username, string passwd, map<string, string> options) {
    Tigre::String dnsParse = std::move(dns);

    //Parse the dns string
    auto pieces = dnsParse.explode(":");
    //Dns shouldn't have more or less than 2 pieces
    if(pieces.size() != 2) {
        throw DataObjectException("invalid dns format");
    }

    auto driver = pieces[0];
    auto dns_connection = pieces[1];

    auto doc = (DataObjectConfiguration *) Configuration::get("Database.driver." + driver.getValue());
    this->instance = doc->getInstance(dns_connection.getValue(), username, passwd, options);
}

DataObject::~DataObject() {
    delete this->instance;
}

/*DataObject* DataObject::Create(string dns, string username, string passwd, map<string, string> options) {
    Tigre::String dnsParse = std::move(dns);

    //Parse the dns string
    auto pieces = dnsParse.explode(":");
    //Dns shouldn't have more or less than 2 pieces
    if(pieces.size() != 2) {
        throw DataObjectException("invalid dns format");
    }

    auto driver = pieces[0];
    auto dns_connection = pieces[1];

    auto doc = (DataObjectConfiguration *) Configuration::get("Database.driver." + driver.getValue());
    return doc->getInstance(dns_connection.getValue(), username, passwd, options);
}*/


/**
 * Inicia uma transação
 */
void DataObject::beginTransaction() {
    return this->instance->beginTransaction();
}
/**
 * Envia uma transação
 */
void DataObject::commit() {
    return this->instance->commit();
}
/**
 * Fetch the SQLSTATE associated with the last operation on the database handle
 */
void DataObject::errorCode() {
    return this->instance->errorCode();
}
/**
 * Fetch extended error information associated with the last operation on the database handle
 */
void DataObject::errorInfo() {
    return this->instance->errorInfo();
}
/**
 * Executa uma instrução SQL e retornar o número de linhas afetadas
 */
int DataObject::exec(std::string sql) {
    return this->instance->exec(sql);
}
/**
 * Recuperar um atributo da conexão com o banco de dados
 */
void DataObject::getAttribute() {
    return this->instance->getAttribute();
}
/**
 * Retorna um array com os drivers PDO disponíveis
 */
void DataObject::getAvailableDrivers() {
    return this->instance->getAvailableDrivers();
}
/**
 * Checks if inside a transaction
 */
void DataObject::inTransaction() {
    return this->instance->inTransaction();
}
/**
 * Returns the ID of the last inserted row or sequence value
 */
int DataObject::lastInsertId() {
    return this->instance->lastInsertId();
}
/**
 * Prepares a statement for execution and returns a statement object
 */
DataObjectStatement* DataObject::prepare(std::string sql) {
    return this->instance->prepare(sql);
}
/**
 * Executes an SQL statement, returning a result set as a PDOStatement object
 */
void DataObject::query() {
    return this->instance->query();
}
/**
 * Quotes a string for use in a query
 */
void DataObject::quote() {
    return this->instance->quote();
}
/**
 * Rolls back a transaction
 */
void DataObject::rollBack() {
    return this->instance->rollBack();
}
/**
 * Set an attribute
 */
void DataObject::setAttribute() {
    return this->instance->setAttribute();
}