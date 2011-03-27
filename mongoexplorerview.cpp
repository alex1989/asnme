#include <QMenu>
#include <QList>
#include <QAction>
#include <QDebug>
#include "mongoexplorerview.h"
#include "mongoexplorermodel.h"
#include "mongoserver.h"
#include "preferences.h"

MongoExplorerView::MongoExplorerView(QWidget *parent) :
    QTreeView(parent)
{
    connect(this,SIGNAL(customContextMenuRequested(QPoint)),
            this,SLOT(createCustomContextMenu(QPoint)));
}

void MongoExplorerView::deleteServer()
{
    QModelIndex index = this->currentIndex();
    const MongoExplorerModel *mem = (MongoExplorerModel*)index.model();
    QStandardItem *item = mem->item(index.row(),0);
    QString item_name = item->data(Qt::DisplayRole).toString();
    Preferences::instance()->deleteServer(item_name);
}

void MongoExplorerView::createCustomContextMenu(QPoint point)
{
    if(this->indexAt(point).isValid())
    {
        QModelIndex index = this->indexAt(point);
        const MongoExplorerModel *mem = (MongoExplorerModel*)index.model();
        QStandardItem *item = mem->item(index.row(),0);

       if( dynamic_cast<MongoServer*>(item) != NULL)
       {
           QAction *action_serverConnect = new QAction(tr("&Connect to Server"),this);
           action_serverConnect->setIcon(QIcon(":icons/server_go"));

           QAction *action_serverDelete = new QAction(tr("&Delete Server"),this);
           action_serverDelete->setIcon(QIcon(":icons/server_delete"));
           int item_row = item->row();
           connect(action_serverDelete,SIGNAL(triggered()),
                   this, SLOT(deleteServer()));

           QList<QAction *> actions;
           actions.append(action_serverConnect);
           actions.append(action_serverDelete);
           QMenu::exec(actions, this->mapToGlobal(point));
       }
    }
}


