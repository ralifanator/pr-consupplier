#include "producer.h"

Producer::Producer()
{

}

void Producer::set_id(int id_new)
{
    this->id = id_new;
}

void Producer::set_city(QString city_new)
{
    this->city = city_new;
}

void Producer::set_inn(QString inn_new)
{
    this->inn = inn_new;
}

void Producer::set_contact(QString contact_new)
{
    this->contact = contact_new;
}

void Producer::set_contact_name(QString contact_name_new)
{
    this->contact_name = contact_name_new;
}

