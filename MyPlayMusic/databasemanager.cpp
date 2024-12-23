#include "DatabaseManager.h"

DatabaseManager::DatabaseManager(const QString &dbPath)
    : dbPath(dbPath)
{
    db = std::unique_ptr<QSqlDatabase>(new QSqlDatabase(QSqlDatabase::addDatabase("QSQLITE")));
}

DatabaseManager::~DatabaseManager() {
    disconnect();
}

bool DatabaseManager::connect() {
    if (db->isOpen()) {
        return true;
    }

    db->setDatabaseName(dbPath);
    if (!db->open()) {
        qDebug() << "Database connection failed: " << db->lastError().text();
        return false;
    }
    return true;
}

void DatabaseManager::disconnect() {
    if (db && db->isOpen()) {
        db->close();
    }
}

bool DatabaseManager::createTable(const QString &createSql) {
    return execSql(createSql);
}

bool DatabaseManager::insertData(const QString &insertSql, const QVariantMap &params) {
    return execSql(insertSql, params);
}

QList<QVariantMap> DatabaseManager::queryData(const QString &querySql) {
    QList<QVariantMap> result;

    QSqlQuery query(*db);
    if (!query.exec(querySql)) {
        qDebug() << "Query failed: " << query.lastError().text();
        return result;
    }

    while (query.next()) {
        QVariantMap row;
        QSqlRecord record = query.record();
        for (int i = 0; i < record.count(); ++i) {
            row[record.fieldName(i)] = query.value(i);
        }
        result.append(row);
    }
    return result;
}

bool DatabaseManager::execSql(const QString &sql, const QVariantMap &params) {
    QSqlQuery query(*db);
    query.prepare(sql);

    // 绑定参数
    for (auto it = params.begin(); it != params.end(); ++it) {
        query.bindValue(it.key(), it.value());
    }

    if (!query.exec()) {
        qDebug() << "SQL execution failed: " << query.lastError().text();
        return false;
    }
    return true;
}
