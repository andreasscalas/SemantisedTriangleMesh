#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>
#include <rapidjson/prettywriter.h>

namespace SemantisedTriangleMesh {

    class Attribute
    {
    public:
        virtual ~Attribute() {  }
        virtual void print(std::ostream& os);
        virtual void printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer);

        std::string getKey() const;
        void setKey(const std::string &value);
        void *getValue() const;
        void setValue(void *value);
        void setValue(int);
        void setValue(double);
        void setValue(std::string);
        unsigned int getId() const;
        void setId(unsigned int value);

        bool isGeometric() const;
        void setIsGeometric(bool newGeometric);

    protected:
        unsigned int id;
        std::string key;
        void* value;
        bool geometric;
    };
}
#endif // ATTRIBUTE_H
