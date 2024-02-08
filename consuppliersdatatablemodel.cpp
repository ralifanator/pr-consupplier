/*
 * @file
 * @brief Файл реализации класса ConsuppliersDataTableModel
 */
#include "consuppliersdatatablemodel.h"


ConsuppliersDataTableModel::ConsuppliersDataTableModel()
{
    Consuppliers = new ConsuppliersDataFile();

    edited = false;

}

int ConsuppliersDataTableModel::rowCount(const QModelIndex &parent) const
{
     Q_UNUSED(parent);
    return Consuppliers->count();

}

int ConsuppliersDataTableModel::columnCount(const QModelIndex &parent) const
{
     Q_UNUSED(parent);
    return 6;
}

QVariant ConsuppliersDataTableModel::data(const QModelIndex &index, int role) const{
    if(!index.isValid())
        return QVariant();
    QVariant answer;
    ConsuppliersDataFile::format El = Consuppliers->get(index.row());
    switch (role) {
        case Qt::DisplayRole:
            switch (index.column()) {
                case 0:
                    answer = El.name;
                    break;
                case 1:
                    answer = El.location;
                    break;
                case 2:
                    answer = El.inn;
                    break;
                case 3:
                    answer = El.phone;
                    break;
                case 4:
                    answer = El.email;
                    break;
                case 5:
                    answer = El.contact_name;
                    break;
            }
            break;
    }
    return answer;
}

QVariant ConsuppliersDataTableModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (role == Qt::DisplayRole && orientation == Qt::Horizontal) {
        switch (section) {
        case 0:
            return tr("Company");
        case 1:
            return tr("City");
        case 2:
            return tr("inn");
        case 3:
            return tr("Phone Number");
        case 4:
            return tr("e-mail");
        case 5:
            return tr("Contact Person");
        }
    }
    return QVariant();
}

void ConsuppliersDataTableModel::readData(QString fileName)
{
    Consuppliers->readFile(fileName);
}

void ConsuppliersDataTableModel::clearAll()
{
    this->beginResetModel();
    Consuppliers->removeAll();
    this->endResetModel();
}


void ConsuppliersDataTableModel::appendLine(){
    this->beginResetModel();
    ConsuppliersDialog *Dialog = new ConsuppliersDialog({"", "", "", "", "", ""});
    if(Dialog->exec()==QDialog::Accepted) {
        edited = true;
        Consuppliers->insert(Consuppliers->count(), Dialog->getConsupplier());
    }
    this->endResetModel();
}

void ConsuppliersDataTableModel::editLine(int at){
    ConsuppliersDialog *Dialog = new ConsuppliersDialog(Consuppliers->get(at));
    if(Dialog->exec()==QDialog::Accepted) {
        edited = true;
        Consuppliers->edit(at, Dialog->getConsupplier());
    }
}

void ConsuppliersDataTableModel::removeLine(int at){
    this->beginResetModel();
    edited = true;
    Consuppliers->remove(at);
    this->endResetModel();
}

void ConsuppliersDataTableModel::setFile(QString f)
{
    file = f;
}

void ConsuppliersDataTableModel::setEdited(bool w)
{
    edited = w;
}

bool ConsuppliersDataTableModel::getEdited()
{
    return edited;
}

QString ConsuppliersDataTableModel::getFile()
{
    return file;
}


//void ConsuppliersDataTableModel::filterData(ConsuppliersData::format temp)
//{
 //   for (int i = 0; i < Consuppliers->count(), ++i)
  //  {
   //     if ()
   // }
//}

void ConsuppliersDataTableModel::saveFile(QString fileName){
    Consuppliers->saveFile(fileName);
}
