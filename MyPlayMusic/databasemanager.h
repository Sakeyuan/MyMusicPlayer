#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QString>
#include <QStringList>
#include <QDebug>
#include <QVariantMap>

class DatabaseManager
{
public:
    explicit DatabaseManager();
    ~DatabaseManager();

    bool connect();
    void disconnect();
    bool createTable(const QString &createSql);
    bool insertData(const QString &insertSql, const QVariantMap &params);
    QList<QVariantMap> queryData(const QString &querySql);

private:
    bool execSql(const QString &sql, const QVariantMap &params = QVariantMap());

    QSqlDatabase* db;
    QString dbPath;
};

#endif // DATABASEMANAGER_H
