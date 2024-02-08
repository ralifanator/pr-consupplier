/**
* @file
* @brief consuppliersdatatablemodel.hЗаголовочный файл класса модели таблицы
*
* Данный класс описывает класс модели таблицы. Унаследован от класса QAbstractTableModel.
*
*/


#ifndef CONSUPPLIERSDATATABLEMODEL_H
#define CONSUPPLIERSDATATABLEMODEL_H
#include <QAbstractTableModel>
#include "ConsuppliersDataFile.h"
#include "consuppliersdialog.h"

/**
 * @brief Класс ConsuppliersDataTableModel.
 *
 * Данный класс описывает класс модели таблицы. Унаследован от класса QAbstractTableModel.
 */
class ConsuppliersDataTableModel : public QAbstractTableModel
{
public:
    /**
     * @brief ConsuppliersDataTableModel Конструктор класса
     */
    ConsuppliersDataTableModel();

    /**
     * @brief метод возвращает количество строк
     * @param parent указатель на родителя объекта
     * @return  количество строк
     */
    int rowCount(const QModelIndex &parent) const;

    /**
     * @brief метод возвращает количество столбцов
     * @param parent указатель на родителя объекта
     * @return количество столбцов
     */
    int columnCount(const QModelIndex &parent) const;

    QVariant data(const QModelIndex &index, int role) const;

    /**
     * @brief метод устанавливает заголовки столбцов
     * @param section
     * @param orientation
     * @param role
     *
     */
    QVariant headerData(int section, Qt::Orientation orientation, int role) const;

    /**
     * @brief метод считывает содержимое файла и записывает в модель таблицы
     * @param fileName путь к файлу
     */
    void readData(QString fileName);

    /**
     * @brief метод записывает содержимое модели таблицы в файл
     * @param fileName путь к файлу
     */
    void saveFile(QString fileName);

    /**
     * @brief метод очищает модель таблицы
     */
    void clearAll();

    /**
     * @brief метод записывает строку в таблицу
     */
    void appendLine();

    /**
     * @brief метод редактирует содержимое строки
     * @param at индекс строки
     */
    void editLine(int at);

    /**
     * @brief метод удаляет содержимое строки
     * @param at индекс строки
     */
    void removeLine(int at);


    /**
     * @brief метод фильтрует модель по содержимому всех столбцов
     * @param temp структура поставщика, по которой нужно отбирать
     */
    void filterData(ConsuppliersDataFile::format temp);

    /**
     * @brief метод устанавливает значения атрибута file
     * @param f строка с путем к файлу
     */
    void setFile(QString f);

    /**
     * @brief метод устанавливает значение атрибута edited
     * @param w на какое значение заменить
     */
    void setEdited(bool w);

    /**
     * @brief Метод возвращает значение атрибута edited
     * @return значение атрибута edited
     */
    bool getEdited();

    /**
     * @brief Метод возвращает значение атрибута file
     * @return значение атрибута file
     */
    QString getFile();



private:
    /**
     * @brief указатель на объект класса ConsuppliersDataFile
     */
    ConsuppliersDataFile* Consuppliers;

    /**
     * @brief путь к файлу, откуда берется модель
     */
    QString file;

    /**
     * @brief флаг изменения файла
     * 0 - файл не изменен
     * 1 - файл изменен
     */
    bool edited;
};

#endif // CONSUPPLIERSDATATABLEMODEL_H
