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
