#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H

#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QSqlRecord>
#include <QString>
#include <QStringList>
#include <QDebug>

class DatabaseManager
{
public:
    explicit DatabaseManager(const QString &dbPath);
    ~DatabaseManager();

    bool connect();
    void disconnect();
    bool createTable(const QString &createSql);
    bool insertData(const QString &insertSql, const QVariantMap &params);
    QList<QVariantMap> queryData(const QString &querySql);

private:
    QSqlDatabase db;
    QString dbPath;
};

#endif // DATABASEMANAGER_H
