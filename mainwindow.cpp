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

#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "src/widgets/serverdialog.h"
#include "preferences.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    MongoExplorerModel *explorer = new MongoExplorerModel;
    ui->mongoExplorerView->setModel(explorer);
    connect(Preferences::instance(),SIGNAL(serversUpdated()),
            explorer,SLOT(updateTree()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::openServerDialog()
{
    ServerDialog serverdialog(this);
    if (serverdialog.exec())
    {
        Preferences* prefs = Preferences::instance();
        prefs->addServer(serverdialog.get_name(),
                         serverdialog.get_host(),
                         serverdialog.get_port());

    }
}
