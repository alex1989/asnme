#ifndef MONGODATABASE_H
#define MONGODATABASE_H

#include <QStandardItem>
#include "mongo/client/dbclient.h"

class MongoDatabase : public QStandardItem
{
public:
    MongoDatabase(QString a_name);
    void createColumns();
};

#endif // MONGODATABASE_H
