/*
 * @file
 * @brief Файл реализации класса QTabForm
 */
#include "qtabform.h"
#include "ui_qtabform.h"

QTabForm::QTabForm(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::QTabForm)
{
    ui->setupUi(this);

    ui->tableView->setContextMenuPolicy(Qt::CustomContextMenu);
    ui->tableView->setAcceptDrops(true);


}

QTabForm::~QTabForm()
{
    delete ui;
}

void QTabForm::setTableModel(ConsuppliersDataTableModel *TableModell)
{
    ui->tableView->setModel(TableModell);
    TableModel = TableModell;

}

void QTabForm::on_pushButtonAdd_clicked()
{
    TableModel->appendLine();
}


void QTabForm::on_pushButtonEdit_clicked()
{
    if (ui->tableView->selectionModel()->hasSelection()) {
        QModelIndexList l = ui->tableView->selectionModel()->selectedIndexes();
        TableModel->editLine(l[0].row());
    }

}


void QTabForm::on_pushButtonDelete_clicked()
{
    if (ui->tableView->selectionModel()->hasSelection())
        TableModel->removeLine(ui->tableView->selectionModel()->selectedRows()[0].row());
}


void QTabForm::on_pushButtonFilter_clicked()
{
    ConsuppliersDialog *Dialog = new ConsuppliersDialog({"", "", "", "", "", ""});
    if(Dialog->exec() == QDialog::Accepted) {
    ConsuppliersDataFile::format consupplier = Dialog->getConsupplier();
    QString filterName = consupplier.name;
    QString filterLocation = consupplier.location;
    QString filterinn = consupplier.inn;
    QString filterPhone = consupplier.phone;
    QString filteremail = consupplier.email;
    QString filterContactPerson = consupplier.contact_name;

    int lines = ui->tableView->model()->rowCount();
    for (int i=0; i<lines; i++) {
        QAbstractItemModel *M = ui->tableView->model();
        QString Name = M->data(M->index( i, 0, QModelIndex())).toString();
        QString Location = M->data(M->index( i, 1, QModelIndex())).toString();
        QString inn = M->data(M->index( i, 2, QModelIndex())).toString();
        QString Phone = M->data(M->index( i, 3, QModelIndex())).toString();
        QString email = M->data(M->index( i, 4, QModelIndex())).toString();
        QString ContactPerson = M->data(M->index( i, 5, QModelIndex())).toString();

        bool flag = true;

        if(filterName==""	|| Name.contains(filterName)) flag&=true; else flag&=false;
        if(filterLocation==""	|| Location.contains(filterLocation)) flag&=true; else flag&=false;
        if(filterinn==""	|| inn.contains(filterinn)) flag&=true; else flag&=false;
        if(filterPhone=="+"       || Phone.contains(filterPhone)) flag&=true; else flag&=false;
        if(filteremail==""	|| email.contains(filteremail)) flag&=true; else flag&=false;
        if(filterContactPerson == "" || ContactPerson.contains(filterContactPerson)) flag&=true; else flag&=false;

        if(flag)
            ui->tableView->showRow(i);
        else
            ui->tableView->hideRow(i);
    }
    }
}



void QTabForm::on_lineEdit_textChanged(const QString &arg1)
{
    int lines = ui->tableView->model()->rowCount();
    bool flag = false;

    for (int i=0; i<lines; i++) {
        QAbstractItemModel *M = ui->tableView->model();
        for (int j = 0; j < 6; j++) {
            QString column_data = M->data(M->index( i, j, QModelIndex())).toString();
            if (column_data.contains(&arg1))
                flag = true;

        }
        if (flag)
            ui->tableView->showRow(i);
        else
            ui->tableView->hideRow(i);

        flag = false;
    }

}


void QTabForm::on_pushButtonSort_clicked()
{
    DialogSorting* dialog = new DialogSorting();

    if(dialog->exec() == QDialog::Accepted)
    {
        formatSorting format = dialog->getSorting();
        QSortFilterProxyModel *proxyModel = new QSortFilterProxyModel();

                proxyModel->setSourceModel(TableModel);
                if (format.order == 0)
                    proxyModel->sort(format.column, Qt::AscendingOrder);
                else
                    proxyModel->sort(format.column, Qt::DescendingOrder);

                ui->tableView->setModel(proxyModel);
    }

}


void QTabForm::on_tableView_customContextMenuRequested(const QPoint &pos)
{
QPoint globalPos = ui->tableView->mapToGlobal(pos);
// for QAbstractScrollArea and derived classes you would use:
// QPoint globalPos = myWidget->viewport()->mapToGlobal(pos);
QMenu myMenu;
myMenu.addAction(tr("Add"), this, SLOT(on_pushButtonAdd_clicked()));
myMenu.addAction(tr("Edit"), this, SLOT(on_pushButtonEdit_clicked()));
myMenu.addAction(tr("Delete"), this, SLOT(on_pushButtonDelete_clicked()));
myMenu.exec(globalPos);

}




