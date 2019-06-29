#ifndef TIGREFRAMEWORK_DATAOBJECTSTATEMENT_H
#define TIGREFRAMEWORK_DATAOBJECTSTATEMENT_H


#include "Value.h"
#include "Line.h"

class DataObjectStatement {

public:
    virtual ~DataObjectStatement() = default;
    /**
     * Bind a column to a PHP variable
     */
    virtual void bindColumn() = 0;
    /**
     * Binds a parameter to the specified variable name
     */
    virtual void bindParam() = 0;
    /**
     * Binds a value to a parameter
     */
    virtual void bindValue() = 0;
    /**
     * Closes the cursor, enabling the statement to be executed again
     */
    virtual void closeCursor() = 0;
    /**
     * Returns the number of columns in the result set
     */
    virtual void columnCount() = 0;
    /**
     * Dump an SQL prepared command
     */
    virtual void debugDumpParams() = 0;
    /**
     * Fetch the SQLSTATE associated with the last operation on the statement handle
     */
    virtual void errorCode() = 0;
    /**
     * Fetch extended error information associated with the last operation on the statement handle
     */
    virtual void errorInfo() = 0;
    /**
     * Executes a prepared statement
     */
    /**
     * Use named field
     * @param params
     * @return bool
     */
    virtual bool execute(std::map<string, Value> params) = 0;
    /**
     * Use interrogation as marker
     * @param params
     * @return bool
     */
    virtual bool execute(std::vector<Value> params) = 0;
    /**
     * No bind Used
     * @return bool
     */
    virtual bool execute() = 0;
    /**
     * Fetches the next row from a result set
     */
    virtual Line fetch() = 0;
    /**
     * Returns an array containing all of the result set rows
     */
    virtual vector<Line> fetchAll() = 0;
    /**
     * Returns a single column from the next row of a result set
     */
    virtual void fetchColumn() = 0;
    /**
     * Fetches the next row and returns it as an object
     */
    virtual void fetchObject() = 0;
    /**
     * Retrieve a statement attribute
     */
    virtual void getAttribute() = 0;
    /**
     * Returns metadata for a column in a result set
     */
    virtual void getColumnMeta() = 0;
    /**
     * Advances to the next rowset in a multi-rowset statement handle
     */
    virtual void nextRowset() = 0;
    /**
     * Returns the number of rows affected by the last SQL statement
     */
    virtual int rowCount() = 0;
    /**
     * Define um atributo na instrução
     */
    virtual void setAttribute() = 0;
    /**
     * Define o modo de carga de dados para esta instrução
     */
    virtual void setFetchMode() = 0;
};


#endif //TIGREFRAMEWORK_DATAOBJECTSTATEMENT_H
