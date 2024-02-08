/*
 * @file
 * @brief Файл реализации класса DialogSorting
 */
#include "dialogsorting.h"
#include "ui_dialogsorting.h"

DialogSorting::DialogSorting(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DialogSorting)
{
    ui->setupUi(this);

}

DialogSorting::~DialogSorting()
{
    delete ui;
}

formatSorting DialogSorting::getSorting()
{
    return sorting;
}

void DialogSorting::on_radioButtonAsc_clicked()
{
    sorting.order = 0;
}


void DialogSorting::on_radioButtonDsc_clicked()
{
    sorting.order = 1;
}


void DialogSorting::on_comboBox_currentIndexChanged(int index)
{
    sorting.column = index;
}

