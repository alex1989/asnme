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

#include <QPushButton>
#include <QRegExp>
#include <QRegExpValidator>
#include "serverdialog.h"
#include "ui_serverdialog.h"

ServerDialog::ServerDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ServerDialog)
{
    ui->setupUi(this);
    QPushButton *ok = ui->buttonBox->button(QDialogButtonBox::Ok);
    ok->setDisabled(true);
}

ServerDialog::~ServerDialog()
{
    delete ui;
}

QString ServerDialog::get_name()
{
    QString name = this->ui->nameLineEdit->text();
    Q_ASSERT(name.size() > 0);
    return name;
}


QString ServerDialog::get_host()
{
    QString host = this->ui->hostLineEdit->text();
    Q_ASSERT(host > 0);
    return host;
}

QString ServerDialog::get_port()
{
    QString port;
    port.setNum(this->ui->portSpinBox->value());
    Q_ASSERT(port > 0);
    return port;
}

void ServerDialog::checkFields()
{
    if( this->ui->nameLineEdit->text().size() > 0 && this->ui->hostLineEdit->text().size() > 0)
    {
        this->ui->buttonBox->button(QDialogButtonBox::Ok)->setDisabled(false);
    }
    else
    {
        this->ui->buttonBox->button(QDialogButtonBox::Ok)->setDisabled(true);
    }
}

