/**
 * @file ConsuppliersData.h
 *
 * Заголовочный файл, описывающий класс ConsuppliersData.
 */

#ifndef CONSUPPLIERSDATA_H
#define CONSUPPLIERSDATA_H

#include <QList>
#include <QString>

/**
 * @brief Класс ConsuppliersData
 *
 * Класс, описывающий список поставщиков
 */
class ConsuppliersData
{
public:
    /**
     * @brief структура, содержащая данные об 1 поставщике
     */
    struct format {
        /**
         * @brief название компании поставщика
         */
        QString name;
        /**
         * @brief местоположение поставщика
         */
        QString location;
        /**
         * @brief ИНН поставщика
         */
        QString inn;
        /**
         * @brief телефон поставщика
         */
        QString phone;
        /**
         * @brief e-mail поставщика
         */
        QString email;
        /**
         * @brief контактное лицо
         */
        QString contact_name;
    };

    /**
     * @brief метод добавляет запись в список consuppliers
     * @param consupplier
     */
    void append(format consupplier);

    /**
     * @brief Метод изменяет запись с индексом num в списке consuppliers
     * @param num индекс строки
     * @param consupplier
     */
    void edit(int num, format consupplier);

    /**
     * @brief Метод удаляет запись с индексом num в списке consuppliers
     * @param num индекс строки
     */
    void remove(int num);

    /**
     * @brief Метод изменяет запись с индексом num в списке consuppliers
     * @param num индекс строки
     * @param consupplier информация о поставщике
     */
    void insert(int num, format consupplier);
    /**
     * @brief Метод получает содержимое строки в consuppliers
     * @param num индекс строки
     * @return информация о поставщике
     */
    format get(int num);
    /**
     * @brief Метод считает количество значений в списке с поставщиками consuppliers
     * @return число поставщиков
     */
    int count();
    /**
     * @brief полностью очищает список поставщиков consuppliers
     */
    void removeAll();

protected:
    /**
     * @brief Список с поставщиками
     */
    QList<format> consuppliers;

};

#endif // CONSUPPLIERSDATA_H
