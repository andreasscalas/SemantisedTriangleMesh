#include "annotation.hpp"

using namespace SemantisedTriangleMesh;

Annotation::Annotation(){ color = static_cast<unsigned char*>(std::malloc(3 * sizeof(unsigned char)));}

Annotation::Annotation(std::shared_ptr<Annotation> other) {
    mesh = other->getMesh();
    type = other->getType();
    id = other->getId();
    tag = other->getTag();
    auto otherAttributes = other->getAttributes();
    attributes.insert(attributes.end(), otherAttributes.begin(), otherAttributes.end());
    color = static_cast<unsigned char*>(std::malloc(3 * sizeof(unsigned char)));
    setColor(other->getColor());
}

Annotation::~Annotation(){ delete color; }

void Annotation::print(std::ostream &os)
{
    os << "id: " << id << std::endl;
    os << "tag: " << tag << std::endl;
    //os << "level: " << hierarchyLevel << std::endl;
    os << "attributes:" << std::endl;
    if(attributes.size() != 0){
        os << "[" << std::endl;
        for(unsigned int i = 0; i < attributes.size(); i++)
            attributes[i]->print(os);
        os << "]";
    }
    os << std::endl;
}

void Annotation::printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer)
{
    writer.Key("id");
    writer.Uint(std::stoi(id));
    writer.Key("tag");
    writer.String(tag.c_str());

    writer.Key("color");
    writer.StartArray();
    writer.Int(color[0]);
    writer.Int(color[1]);
    writer.Int(color[2]);
    writer.EndArray();

    writer.Key("attributes");
    writer.StartArray();
    for(unsigned int i = 0; i < attributes.size(); i++)
    {
        writer.StartObject();
        attributes[i]->printJson(writer);
        writer.EndObject();
    }
    writer.EndArray();
}

void Annotation::removeAttribute(std::shared_ptr<Attribute> value){
    std::vector<std::shared_ptr<Attribute> >::iterator it = std::find(attributes.begin(), attributes.end(), value);
    if(it != attributes.end())
        attributes.erase(it);
}

void Annotation::resetAttributes()
{
    attributes.clear();
}

std::string Annotation::getId() const { return id; }

void Annotation::setId(std::string value){ id = value; }

Point Annotation::getCenter()
{
    Point centroid(0,0,0);
    auto list = getInvolvedVertices();
    for(auto v : list)
        centroid += *v;
    return centroid /list.size();
}

Vector Annotation::getOrientation()
{
    std::vector<std::shared_ptr<Vertex>> involvedVertices = getInvolvedVertices();
    Eigen::MatrixXd eigenPoints;
    eigenPoints.resize(3, static_cast<Eigen::Index>(involvedVertices.size()));

    for(unsigned int i = 0; i < involvedVertices.size(); i++ )
    {
        Eigen::Vector3d p = {involvedVertices[i]->getX(), involvedVertices[i]->getY(), involvedVertices[i]->getZ()};
        eigenPoints.col(i) = p;
    }

    Eigen::Vector3d mean_vector = eigenPoints.rowwise().mean();
    eigenPoints.colwise() -= mean_vector;
    Eigen::Matrix3d U = eigenPoints.bdcSvd(Eigen::ComputeFullU | Eigen::ComputeThinV).matrixU();
    Point orientation;
    orientation.setX(U(0,2));
    orientation.setY(U(1,2));
    orientation.setZ(U(2,2));

    return orientation;
}


std::shared_ptr<TriangleMesh> Annotation::getMesh() const
{
    return mesh;
}

void Annotation::setMesh(std::shared_ptr<TriangleMesh> value)
{
    this->mesh = value;
}

AnnotationType Annotation::getType() const
{
    return type;
}

std::string Annotation::getTag() const
{
    return tag;
}

void Annotation::setTag(const std::string &value)
{
    this->tag = value;
}

unsigned char *Annotation::getColor()
{
    return color;
}

void Annotation::setColor(unsigned char value[])
{
    this->color[0] = value[0];
    this->color[1] = value[1];
    this->color[2] = value[2];
}

std::vector<std::shared_ptr<Attribute> > Annotation::getAttributes() const
{
    return attributes;
}

void Annotation::setAttributes(const std::vector<std::shared_ptr<Attribute> > &value)
{
    this->attributes = value;
}

void Annotation::addAttribute(std::shared_ptr<Attribute> value)
{
    this->attributes.push_back(value);
}
