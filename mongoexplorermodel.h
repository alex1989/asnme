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
    void updateTree();
    void connectToServer(int a_index);

};

#endif // MONGOEXPLORERMODEL_H
