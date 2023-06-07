#ifndef SEMANTICATTRIBUTE_H
#define SEMANTICATTRIBUTE_H

#include <attribute.hpp>

namespace SemantisedTriangleMesh {
    class SemanticAttribute : virtual public Attribute
    {
    public:
        SemanticAttribute();


        virtual void print(std::ostream&);
        virtual void printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer>&);

    };
}
#endif // SEMANTICATTRIBUTE_H
