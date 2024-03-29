#include "attribute.hpp"
#include <iostream>

using namespace SemantisedTriangleMesh;

std::string Attribute::getKey() const
{
    return key;
}

void Attribute::setKey(const std::string &value)
{
    key = value;
}

void *Attribute::getValue() const
{
    return value;
}

void Attribute::setValue(void *value)
{
    this->value = value;
}

void Attribute::setValue(int value)
{
    this->value = static_cast<void*>(new int(value));
}

void Attribute::setValue(double value)
{
    this->value = static_cast<void*>(new double(value * 1000));
}

void Attribute::setValue(std::string value)
{
    this->value = static_cast<void*>(new std::string(value));
}

unsigned int Attribute::getId() const
{
    return id;
}

void Attribute::setId(unsigned int value)
{
    id = value;
}

bool Attribute::isGeometric() const
{
    return geometric;
}

void Attribute::setIsGeometric(bool newGeometric)
{
    geometric = newGeometric;
}


void Attribute::print(std::ostream &os)
{
    os << "id: " << id << ", name: " << key << std::endl;

}

void Attribute::printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer)
{
   writer.Key("id");
   writer.Uint(id);
   writer.Key("name");
   writer.String(key.c_str());
}
