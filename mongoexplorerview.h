#ifndef MONGOEXPLORERVIEW_H
#define MONGOEXPLORERVIEW_H

#include <QTreeView>

class MongoExplorerView : public QTreeView
{
    Q_OBJECT
public:
    explicit MongoExplorerView(QWidget *parent = 0);

signals:

public slots:
    void createCustomContextMenu(QPoint point);
    void deleteServer();

};

#endif // MONGOEXPLORERVIEW_H
