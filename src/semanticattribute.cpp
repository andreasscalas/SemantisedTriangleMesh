#include "semanticattribute.hpp"
#include <iostream>

using namespace SemantisedTriangleMesh;

SemanticAttribute::SemanticAttribute(){

}

void SemanticAttribute::print(std::ostream &writer)
{
    writer << key << " : " << *static_cast<std::string*>(value) << std::endl;
}

void SemanticAttribute::printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer)
{
    writer.Key("type");
    writer.String("Semantic");
    writer.Key("id");
    writer.Uint(id);
    writer.Key("name");
    writer.String(key.c_str());
    writer.Key("value");
    writer.String(static_cast<std::string*>(value)->c_str());
}

