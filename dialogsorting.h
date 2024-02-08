/*!
* @file
* @brief dialogsorting.h
*
* Заголовочный файл, описывающий класс диалогового окна для выбора сортировки
*
*/

#ifndef DIALOGSORTING_H
#define DIALOGSORTING_H

#include <QDialog>

/*!
 * @brief Структура, содержащая правила сортировки
 */
struct formatSorting {
    /*!
     * @brief индекс столбца
     */
    int column;
    /*!
     * @brief порядок сортировки
     *
     * 0 - по возрастанию
     * 1 - по убыванию
     */
    int order;
};


namespace Ui {
class DialogSorting;
}
/*!
 * @brief Класс, описывающий диалог для сортировки таблицы
 *
 *
 */
class DialogSorting : public QDialog
{
    Q_OBJECT

public:
    /*!
     * @brief Конструктор класса
     * @param parent указатель на родителя объекта
     */
    explicit DialogSorting(QWidget *parent = nullptr);
    /*!
     * @brief Деструктор класса
     */
    ~DialogSorting();

    /*!
     * @brief возвращает значение атрибута sorting
     * @return атрибут sorting
     */
    formatSorting getSorting();

private slots:
    /*!
     * @brief слот radioButton кнопки, указывающая на возрастание
     */
    void on_radioButtonAsc_clicked();

    /*!
     * @brief слот radioButton кнопки, указывающая на возрастание
     */
    void on_radioButtonDsc_clicked();

    /*!
     * @brief Слот on_comboBox_currentIndexChanged
     * @param index индекс измененного элемента
     *
     */
    void on_comboBox_currentIndexChanged(int index);

private:
    Ui::DialogSorting *ui;

    /*!
     * @brief объект структуры formatSorting. Устанавливает правила сортировки
     */
    formatSorting sorting;
};

#endif // DIALOGSORTING_H
