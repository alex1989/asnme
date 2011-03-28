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

#ifndef MONGOEXPLORERACTION_H
#define MONGOEXPLORERACTION_H

#include <QAction>

class MongoExplorerAction : public QAction
{
    Q_OBJECT
public:
    explicit MongoExplorerAction(QString text, int row, QObject *parent = 0);

signals:
    void triggered_with_row(int row);

public slots:
    void trigger_with_row();

private:
    int m_row;
};

#endif // MONGOEXPLORERACTION_H
