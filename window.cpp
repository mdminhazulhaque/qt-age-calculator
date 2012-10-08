/*****************************************************************************
age-calculator, an age calculator app for Android
Copyright (C) 2012 MD: Minhazul Haque;
mdminhazulhaque@gmail.com.

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 3 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*****************************************************************************/

#include "window.h"
#include "ui_window.h"

Window::Window(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::Window)
{
    ui->setupUi(this);
    connect(ui->quit, SIGNAL(clicked()), qApp, SLOT(quit()));
    ui->date->setText(QDate::currentDate().toString("dd-MM-yyyy"));
    showMaximized();
    on_calculate_clicked();
}

Window::~Window()
{
    delete ui;
}

void Window::on_calculate_clicked()
{
    if(ui->day->value()==0 or ui->year->value()==0)
        QMessageBox::warning(this, "Error", "You must fill all input fileds",QMessageBox::Ok);
    else
    {
        int bd,bm,by,cd,cm,cy,ad,am,ay;

        bd = ui->day->value();
        bm = ui->month->currentIndex()+1;
        by = ui->year->value();

        cd = QDate::currentDate().day();
        cm = QDate::currentDate().month();
        cy = QDate::currentDate().year();

        if(cd<bd)
        {
            cm=cm-1;
            cd=cd+30;
        }
        if(cm<bm)
        {
            cy=cy-1;
            cm=cm+12;
        }
        ad=cd-bd;
        am=cm-bm;
        ay=cy-by;

        ui->age->setText(QString(tr("<b>%1</b> years <b>%2</b> months <b>%3</b> days").arg(ay).arg(am).arg(ad)));
    }
}
