#ifndef TIGREFRAMEWORK_DATAOBJECT_H
#define TIGREFRAMEWORK_DATAOBJECT_H

#include <string>
#include <map>
#include "DataObjectStatement.h"

using namespace std;

class DataObject {

    public:
        /**
         * Creates a PDO instance representing a connection to a database
         */
        DataObject(string dns, string username, string passwd, map<string, string> options={});
        virtual ~DataObject();
        //DataObject * Create(string dns, string username, string passwd, map<string, string> options);
        /**
         * Inicia uma transação
         */
        virtual void beginTransaction();
        /**
         * Envia uma transação
         */
        virtual void commit();
        /**
         * Fetch the SQLSTATE associated with the last operation on the database handle
         */
        virtual void errorCode();
        /**
         * Fetch extended error information associated with the last operation on the database handle
         */
        virtual void errorInfo();
        /**
         * Executa uma instrução SQL e retornar o número de linhas afetadas
         */
        virtual void exec();
        /**
         * Recuperar um atributo da conexão com o banco de dados
         */
        virtual void getAttribute();
        /**
         * Retorna um array com os drivers PDO disponíveis
         */
        virtual void getAvailableDrivers();
        /**
         * Checks if inside a transaction
         */
        virtual void inTransaction();
        /**
         * Returns the ID of the last inserted row or sequence value
         */
        virtual int lastInsertId();
        /**
         * Prepares a statement for execution and returns a statement object
         */
        virtual DataObjectStatement* prepare(std::string sql);
        /**
         * Executes an SQL statement, returning a result set as a PDOStatement object
         */
        virtual void query();
        /**
         * Quotes a string for use in a query
         */
        virtual void quote();
        /**
         * Rolls back a transaction
         */
        virtual void rollBack();
        /**
         * Set an attribute
         */
        virtual void setAttribute();

    protected:
        DataObject() = default;

    private:
        /**
         * Store current driver connection
         */
        DataObject * instance = nullptr;

};


#endif //TIGREFRAMEWORK_DATAOBJECT_H
