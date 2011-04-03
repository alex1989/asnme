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

#include "mongoserver.h"
#include "mongodatabase.h"
#include "mongocollection.h"

MongoDatabase::MongoDatabase(QString a_name) :
        QStandardItem()
{
    setData(a_name,Qt::DisplayRole);
    setData(QIcon(":icons/database"),Qt::DecorationRole);
}

void MongoDatabase::createColumns()
{
    // Create the variables needed to populate the collections list
     list<string> mongo_collections;
     MongoCollection *col;

     // Get the connection to the server from the parent
     MongoServer *daddy = dynamic_cast<MongoServer*>(this->parent());
     Q_ASSERT(daddy);
     mongo::DBClientConnection *connection = daddy->get_connection();

     // Get the collections
     mongo_collections = connection->getCollectionNames(data(Qt::DisplayRole).toString().toStdString());

     // Create the collections list

     int size = (int)mongo_collections.size();
     for(int i = 0; i < size ; i++)
     {
         //Create the variables needed
         string col_name;
         QString qstring_col_name;
         QStringList col_name_parts;

         // Convert the name of the last collection to a usable format
         col_name = mongo_collections.back();
         qstring_col_name = qstring_col_name.fromStdString(col_name);
         col_name_parts = qstring_col_name.split(".");

         // Create a new collection and assign it to this database
         col = new MongoCollection(col_name_parts.at(1));
         this->appendRow(col);

         // Pop the last item from the collections lists
         mongo_collections.pop_back();
     }

}
