/*!
* @file
* @brief Заголовочный файл, описывающий класс главного окна
*
*
*
*/

#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "ConsuppliersDataFile.h"
#include "consuppliersdatatablemodel.h"
#include <QFileDialog>
#include <QFile>
#include <QTextStream>
#include "qtabform.h"
#include <QTranslator>
#include <QSettings>
#include <QProcess>
#include <QEvent>


QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

/*!
 * @brief Класс MainWindow
 *
 * Данный класс описывает главное окно нашей программы
 */

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    /*!
     * @brief MainWindow конструктор класса
     * @param parent указатель на родителя объекта
     */
    MainWindow(QWidget *parent = nullptr);
    /*!
     * @brief ~MainWindow() деструктор класса
     *
     */
    ~MainWindow();

private slots:
    /*!
     * @brief on_actionOpen_triggered
     *
     * Слот действия меню Open.
     * Открывает файл и записывает содержимое файла в таблицу.
     */
    void on_actionOpen_triggered();

    /*!
     * @brief on_actionNew_triggered
     *
     * Слот действия меню New.
     * Создает новый файл.
     */
    void on_actionNew_triggered();

    /*!
     * @brief on_actionSave_triggered
     *
     * Слот действия меню Save.
     * Сохраняет текущее содержимое таблицы.
     */
    void on_actionSave_triggered();


    /*!
     * @brief on_tabWidget_tabCloseRequested
     * @param index индекс вкладки
     *
     * Слот объекта класса QTabWidget, вызываемый при закрытии вкладки.
     */
    void on_tabWidget_tabCloseRequested(int index);

    /*!
     * @brief on_actionSave_as_triggered
     *
     * Слот действия меню Save as.
     * Сохраняет текущее содержимое таблицы в новый файл.
     */
    void on_actionSave_as_triggered();

    /*!
     * @brief on_actionRussian_triggered
     *
     * Слот действия меню Language.
     * Меняет язык программы на русский.
     */
    void on_actionRussian_triggered();

    /*!
     * @brief on_actionEnglish_triggered
     *
     * Слот действия меню Language.
     * Меняет язык программы на английский.
     */
    void on_actionEnglish_triggered();

    /*!
     * @brief on_actionGerman_triggered
     *
     * Слот действия меню Language.
     * Меняет язык программы на немецкий.
     */
    void on_actionGerman_triggered();

    void on_actionChoose_Language_triggered();

    void aboutProgram();
    void on_actionAbout_Program_triggered();

private:
    Ui::MainWindow *ui;
    QSettings *settings;

    QString file;
    bool edited;

    QVector<QTabForm*> qtabForms;
    QVector<ConsuppliersDataTableModel*> dtModels;

    QTranslator* translator;
    QString language;
    void ChangeTranslator(QString lang);
    void changeEvent(QEvent *event);

    bool AskSave();
    void CloseFile();

    void saveSettings();
    void loadSettings();
    void Reboot();
};
#endif // MAINWINDOW_H
