#ifndef CHELLODATABASE_H
#define CHELLODATABASE_H

#include <QObject>
#include <QtSql/qsql.h>


class CHelloDatabase : public QObject
{
    Q_OBJECT
public:
    explicit CHelloDatabase(QObject *parent = 0);

signals:

public slots:

};

#endif // CHELLODATABASE_H
