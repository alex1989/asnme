/*
This file is part of asnme.

asnme is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

asnme is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with asnme.  If not, see <http://www.gnu.org/licenses/>.
*/

#include <QMenu>
#include <QList>
#include <QAction>
#include <QDebug>
#include "mongoexplorerview.h"
#include "../../mongoexplorermodel.h"
#include "../../mongoexploreraction.h"
#include "../../mongoserver.h"
#include "../../preferences.h"

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
           int item_row = item->row();
           MongoExplorerAction *action_serverConnect = new MongoExplorerAction(tr("&Connect to Server"), item_row, this);
           action_serverConnect->setIcon(QIcon(":icons/server_go"));
           connect(action_serverConnect,SIGNAL(triggered_with_row(int)),
                   mem,SLOT(connectToServer(int)));

           MongoExplorerAction *action_serverDelete = new MongoExplorerAction(tr("&Delete Server"), item_row, this);
           action_serverDelete->setIcon(QIcon(":icons/server_delete"));

           QList<QAction *> actions;
           actions.append(action_serverConnect);
           actions.append(action_serverDelete);
           QMenu::exec(actions, this->mapToGlobal(point));
       }
    }
}
