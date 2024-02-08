/*
 * @file
 * @brief Файл реализации класса ConsuppliersData
 */
#include "ConsuppliersData.h"

void ConsuppliersData::append(format consupplier)
{
    this->consuppliers.append(consupplier);
}

void ConsuppliersData::edit(int num, format consupplier)
{
    this->consuppliers[num] = consupplier;
}

void ConsuppliersData::remove(int num)
{
    this->consuppliers.removeAt(num);
}

void ConsuppliersData::insert(int num, format consupplier)
{
    this->consuppliers.insert(num, consupplier);
}

ConsuppliersData::format ConsuppliersData::get(int num)
{
    return this->consuppliers.at(num);
}

int ConsuppliersData::count()
{
    return this->consuppliers.count();
}

void ConsuppliersData::removeAll()
{
    this->consuppliers.clear();
}



