#include "relationship.hpp"
using namespace SemantisedTriangleMesh;

Relationship::Relationship()
{
    type = "";
    weight = 0.0;
    minValue = -std::numeric_limits<double>::max();
    maxValue = std::numeric_limits<double>::max();
    id = 0;
}

Relationship::~Relationship()
{
    annotations.clear();
}

std::string Relationship::getType() const
{
    return type;
}

void Relationship::setType(const std::string &value)
{
    type = value;
}

std::vector<std::shared_ptr<Annotation> > Relationship::getAnnotations() const
{
    return annotations;
}

void Relationship::setAnnotations(const std::vector<std::shared_ptr<Annotation> > &value)
{
    annotations = value;
}

double Relationship::getWeight() const
{
    return weight;
}

void Relationship::setWeight(double value)
{
    weight = value;
}

double Relationship::getMinValue() const
{
    return minValue;
}

void Relationship::setMinValue(double value)
{
    minValue = value;
}

double Relationship::getMaxValue() const
{
    return maxValue;
}

void Relationship::setMaxValue(double value)
{
    maxValue = value;
}

void Relationship::print(std::ostream &os)
{
    os << "id: " << id << std::endl;
    os << "type: " << type << std::endl;
    os << "weight: " << weight << std::endl;
    if(type.compare("Surfaces same measure") == 0)
    {
        os << "minimum value:" << minValue << std::endl;
        os << "maximum value: " << maxValue << std::endl;
    }
    os << "annotations ids: [";
    for(unsigned int i = 0; i < annotations.size(); i++){
        os << annotations[i]->getId();
        if(i < annotations.size() - 1)
            os << ",";
    }
    os << "]" << std::endl;

}


void Relationship::printJSON(rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer)
{
    writer.Key("type");
    writer.String(type.c_str());
    writer.Key("weight");
    writer.Double(weight);
    writer.Key("minimum value");
    writer.Double(minValue);
    writer.Key("maximum value");
    writer.Double(maxValue);
    writer.Key("annotations");
    writer.StartArray();
    for(unsigned int i = 0; i < annotations.size(); i++)
        writer.Uint(std::stoi(annotations[i]->getId()));

}

unsigned int Relationship::getId() const
{
    return id;
}

void Relationship::setId(unsigned int value)
{
    id = value;
}
