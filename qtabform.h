/*!
* @file
* @brief Заголовочный файл, описывающий класс формы, помещенной в QTabWidget
*/


#ifndef QTABFORM_H
#define QTABFORM_H

#include <QWidget>
#include "consuppliersdatatablemodel.h"
#include <QMessageBox>
#include "consuppliersdialog.h"
#include "dialogsorting.h"
#include <QSortFilterProxyModel>
#include <QMenu>
#include <QInputDialog>


namespace Ui {
class QTabForm;
}

/**
 * @brief Класс формы, помещенной в QTabWidget
 */
class QTabForm : public QWidget
{
    Q_OBJECT

public:
    explicit QTabForm(QWidget *parent = nullptr);
    ~QTabForm();
    /**
     * @brief Метод назначает модель для tableView виджета
     * @param TableModel модель таблицы
     */
    void setTableModel(ConsuppliersDataTableModel *TableModel);

    ConsuppliersDataFile::format getLine();


private slots:
    void on_pushButtonAdd_clicked();

    void on_pushButtonEdit_clicked();

    void on_pushButtonDelete_clicked();

    void on_pushButtonFilter_clicked();

    void on_lineEdit_textChanged(const QString &arg1);

    void on_pushButtonSort_clicked();

    void on_tableView_customContextMenuRequested(const QPoint &pos);


private:
    Ui::QTabForm *ui;
    ConsuppliersDataTableModel* TableModel;


};

#endif // QTABFORM_H
