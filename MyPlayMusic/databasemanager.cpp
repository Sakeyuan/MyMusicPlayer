#include "databasemanager.h"

DatabaseManager::DatabaseManager(const QString &dbPath) : dbPath(dbPath)
{

}

DatabaseManager::~DatabaseManager()
{
    disconnect();
}

bool DatabaseManager::connect()
{

    db = QSqlDatabase::addDatabase("QSQLITE");
    db.setDatabaseName(dbPath);
    if (!db.open()) {
        qDebug() << "Failed to connect to database:" << db.lastError().text();
        return false;
    }

    qDebug() << "Database connected successfully.";
    return true;
}

void DatabaseManager::disconnect()
{
    if (db.isOpen()) {
        db.close();
        qDebug() << "Database disconnected.";
    }
}

bool DatabaseManager::createTable(const QString &createSql)
{
    QSqlQuery query;
    if(!query.exec(createSql)){
        qDebug() << "Failed to create table:" << query.lastError().text();
        return false;
    }
    qDebug() << "Table created or already exists.";
    return true;
}

bool DatabaseManager::insertData(const QString &insertSql, const QVariantMap &params)
{
    QSqlQuery query;
    query.prepare(insertSql);
    for(auto it = params.begin(); it != params.end(); ++it){
        query.bindValue(it.key(),it.value());
    }

    if (!query.exec()) {
        qDebug() << "Failed to insert data:" << query.lastError().text();
        return false;
    }

    qDebug() << "Data inserted successfully.";
    return true;
}

QList<QVariantMap> DatabaseManager::queryData(const QString &querySql)
{
    QList<QVariantMap>results;
    QSqlQuery query;

    if(!query.exec(querySql)){
        qDebug() << "Failed to execute query:" << query.lastError().text();
        return results;
    }
    while (query.next()) {
        QVariantMap row;
        for (int i = 0; i < query.record().count(); ++i){
            row.insert(query.record().fieldName(i),query.value(i));
        }
        results.append(row);
    }
    return results;
}
