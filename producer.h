#ifndef PRODUCER_H
#define PRODUCER_H
#include <QString>

class Producer
{
public:
    Producer();
    void set_id(int id_new);
    void set_city(QString city_new);
    void set_inn(QString inn_new);
    void set_contact(QString contact_new);
    void set_contact_name(QString contact_name_new);

private:
    int id;
    std::string name;
    QString city;
    QString inn;
    QString contact;
    QString contact_name;

};

#endif // PRODUCER_H
