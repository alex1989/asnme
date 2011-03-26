#ifndef MONGOEXPLORERMODEL_H
#define MONGOEXPLORERMODEL_H

#include <QStandardItemModel>

class MongoExplorerModel : public QStandardItemModel
{
    Q_OBJECT
public:
    explicit MongoExplorerModel(QObject *parent = 0);

signals:

public slots:

};

#endif // MONGOEXPLORERMODEL_H
