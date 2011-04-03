#include "mongocollection.h"

MongoCollection::MongoCollection(QString a_name) :
        QStandardItem()
{
    setData(a_name,Qt::DisplayRole);
    setData(QIcon(":icons/collection"),Qt::DecorationRole);
}
