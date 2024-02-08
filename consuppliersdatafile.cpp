/*
 * @file
 * @brief Файл реализации класса ConsuppliersDataFile
 */

#include "consuppliersdatafile.h"
#include <QTextStream>

ConsuppliersDataFile::ConsuppliersDataFile()
{

}

void ConsuppliersDataFile::readFile(QString fileName)
{
    QFile file(fileName);
    if(file.open(QIODevice::ReadOnly)){
        QTextStream stream(&file);
        this->removeAll();
        while (!stream.atEnd()) {
            QString line = stream.readLine();
            if(line.isEmpty()) continue;
            QList<QString> lineElems = line.split(";");
            format temp = {
                lineElems.at(0),
                lineElems.at(1),
                lineElems.at(2),
                lineElems.at(3),
                lineElems.at(4),
                lineElems.at(5)
            };
            this->consuppliers.append(temp);
        }
    }else
        return;
    file.close();
    return;
}

void ConsuppliersDataFile::saveFile(QString fileName)
{
    QFile file(fileName);
    if(file.open(QIODevice::WriteOnly)){
        QTextStream stream(&file);
        for (int i=0; i<consuppliers.count(); i++) {
            stream << consuppliers.at(i).name <<";"
                   << consuppliers.at(i).location <<";"
                   << consuppliers.at(i).inn <<";"
                   << consuppliers.at(i).phone <<";"
                   << consuppliers.at(i).email <<";"
                   << consuppliers.at(i).contact_name <<";";
            stream << "\n";
        }
    }
    else
        return;
    file.close();
    return;
}
