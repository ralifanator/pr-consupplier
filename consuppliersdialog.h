/**
* @file
* @brief содержит класс окна для удаления и редактирования записей в таблице
*
* Данный класс описывает окно для удаления и редактирования записей в таблице
*/


#ifndef CONSUPPLIERSDIALOG_H
#define CONSUPPLIERSDIALOG_H

#include <QDialog>
#include "ConsuppliersDataFile.h"


namespace Ui {
class ConsuppliersDialog;
}

/**
 * @brief Класс ConsuppliersDialog
 *
 * Класс диалога для содержимого строки таблицы
 */
class ConsuppliersDialog : public QDialog
{
    Q_OBJECT

public:
    /**
     * @brief конструктор класса ConsuppliersDialog
     * @param consupplier данные о поставщике
     * @param parent указатель на родителя объекта
     */
    explicit ConsuppliersDialog(ConsuppliersDataFile::format consupplier, QWidget *parent = nullptr);

    /**
     * @brief ~ConsuppliersDialog() деструктор класса ConsuppliersDialog
     */
    ~ConsuppliersDialog();

    /**
     * @brief метод возвращает содержимое атрибута Consupplier
     * @return атрибут Consupplier
     */
    ConsuppliersDataFile::format getConsupplier();


private slots:
    /**
     * @brief слот кнопки accepted on_buttonBox_accepted
     *
     * Изменяет значения атрибута Consupplier
     */
    void on_buttonBox_accepted();

private:
    Ui::ConsuppliersDialog *ui;

    /**
     *
     *
     * @brief структура, содержащая значения столбцов одного элемента
     */
    ConsuppliersDataFile::format Consupplier;
};

#endif // CONSUPPLIERSDIALOG_H
