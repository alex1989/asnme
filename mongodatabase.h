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
