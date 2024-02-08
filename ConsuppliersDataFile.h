/**
 * @file
 * @brief ConsuppliersDataFile.h
 *
 * Заголовочный файл, описывающий класс-наследник от ConsuppliersData, ConsuppliersDataFile.
 */

#ifndef CONSUPPLIERSDATAFILE_H
#define CONSUPPLIERSDATAFILE_H

#include "ConsuppliersData.h"
#include <QFile>

/**
 * @brief Класс ConsuppliersDataFile
 *
 * Класс-наследник от ConsuppliersData. Определены новые методы для чтения данных из файла и записи данных в файл.
 */
class ConsuppliersDataFile : public ConsuppliersData
{
public:
    /**
     * @brief ConsuppliersDataFile конструктор класса
     *
     *
     */
    ConsuppliersDataFile();

    /**
     * @brief Метод сохраняет значение списка поставщиков в файл fileName
     * @param fileName путь к файлу
     */
    void saveFile(QString fileName);

    /**
     * @brief Метод считывает файл fileName и записывает в список поставщиков
     * @param fileName путь к файлу
     */
    void readFile(QString fileName);
};

#endif // CONSUPPLIERSDATAFILE_H
