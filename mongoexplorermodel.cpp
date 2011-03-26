#include "mongoexplorermodel.h"

MongoExplorerModel::MongoExplorerModel(QObject *parent) :
    QStandardItemModel(parent)
{
    this->setColumnCount(1);
    QStringList labels;
    labels.append(tr("Explorer"));
    this->setHorizontalHeaderLabels(labels);
}
