/*
 * @file
 * @brief Файл реализации класса ConsuppliersDialog
 */
#include "consuppliersdialog.h"
#include "ui_consuppliersdialog.h"

ConsuppliersDialog::ConsuppliersDialog(ConsuppliersDataFile::format consupplier, QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ConsuppliersDialog)
{
    ui->setupUi(this);

    ui->inn->setInputMask("9999999999");
    ui->Phone->setInputMask("+99999999999");
    ui->CompanyName->setText(consupplier.name);
    ui->City->setText(consupplier.location);
    ui->inn->setText(consupplier.inn);
    ui->Phone->setText(consupplier.phone);
    ui->email->setText(consupplier.email);
    ui->ContactPerson->setText(consupplier.contact_name);


}

ConsuppliersDialog::~ConsuppliersDialog()
{
    delete ui;
}

ConsuppliersDataFile::format ConsuppliersDialog::getConsupplier()
{
    return Consupplier;
}


void ConsuppliersDialog::on_buttonBox_accepted()
{
    Consupplier = {ui->CompanyName->text(),
                   ui->City->text(),
                   ui->inn->text(),
                   ui->Phone->text(),
                   ui->email->text(),
                   ui->ContactPerson->text()};
}

