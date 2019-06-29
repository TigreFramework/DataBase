#include "DataObjectStatement.h"

/**
 * Bind a column to a PHP variable
 */
void DataObjectStatement::bindColumn() {}
/**
 * Binds a parameter to the specified variable name
 */
void DataObjectStatement::bindParam() {}
/**
 * Binds a value to a parameter
 */
void DataObjectStatement::bindValue() {}
/**
 * Closes the cursor, enabling the statement to be executed again
 */
void DataObjectStatement::closeCursor() {}
/**
 * Returns the number of columns in the result set
 */
void DataObjectStatement::columnCount() {}
/**
 * Dump an SQL prepared command
 */
void DataObjectStatement::debugDumpParams() {}
/**
 * Fetch the SQLSTATE associated with the last operation on the statement handle
 */
void DataObjectStatement::errorCode() {}
/**
 * Fetch extended error information associated with the last operation on the statement handle
 */
void DataObjectStatement::errorInfo() {}
/**
 * Executes a prepared statement
 */
void DataObjectStatement::execute(std::map<string, Value> params) {

}
/**
 * Fetches the next row from a result set
 */
void DataObjectStatement::fetch() {}
/**
 * Returns an array containing all of the result set rows
 */
void DataObjectStatement::fetchAll() {}
/**
 * Returns a single column from the next row of a result set
 */
void DataObjectStatement::fetchColumn() {}
/**
 * Fetches the next row and returns it as an object
 */
void DataObjectStatement::fetchObject() {}
/**
 * Retrieve a statement attribute
 */
void DataObjectStatement::getAttribute() {}
/**
 * Returns metadata for a column in a result set
 */
void DataObjectStatement::getColumnMeta() {}
/**
 * Advances to the next rowset in a multi-rowset statement handle
 */
void DataObjectStatement::nextRowset() {}
/**
 * Returns the number of rows affected by the last SQL statement
 */
void DataObjectStatement::rowCount() {}
/**
 * Define um atributo na instrução
 */
void DataObjectStatement::setAttribute() {}
/**
 * Define o modo de carga de dados para esta instrução
 */
void DataObjectStatement::setFetchMode() {}
