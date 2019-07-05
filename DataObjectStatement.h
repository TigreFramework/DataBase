#ifndef TIGREFRAMEWORK_DATAOBJECTSTATEMENT_H
#define TIGREFRAMEWORK_DATAOBJECTSTATEMENT_H


#include "Value.h"
#include "Line.h"
#include "Param.h"

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
    virtual void bindValue(int index, Value value) = 0;
    virtual void bindValue(std::string name, Value value) = 0;
    /**
     * Closes the cursor, enabling the statement to be executed again
     */
    virtual void closeCursor() = 0;
    /**
     * Returns the number of columns in the result set
     */
    virtual int columnCount() = 0;
    /**
     * Dump an SQL prepared command
     */
    virtual std::string debugDumpParams() = 0;
    /**
     * Fetch the SQLSTATE associated with the last operation on the statement handle
     */
    virtual int errorCode() = 0;
    /**
     * Fetch extended error information associated with the last operation on the statement handle
     */
    virtual std::string errorInfo() = 0;
    /**
     * Executes a prepared statement
     */
    /**
     * Use named field or
     * Use interrogation as marker
     * @param params
     * @return bool
     */
    virtual bool execute(const Param& params) = 0;
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
     * Returns the number of rows affected by the last SQL statement
     */
    virtual int rowCount() = 0;
    /**
     * Quotes a string for use in a query
     */
    virtual std::string quote(const std::string& value) = 0;

};


#endif //TIGREFRAMEWORK_DATAOBJECTSTATEMENT_H
