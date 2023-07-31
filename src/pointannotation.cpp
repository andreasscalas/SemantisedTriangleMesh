#include "pointannotation.hpp"
#include <eigen3/Eigen/Dense>

using namespace SemantisedTriangleMesh;

PointAnnotation::PointAnnotation()
{
    type = AnnotationType::Point;
}

PointAnnotation::PointAnnotation(TriangleMesh *mesh, std::shared_ptr<PointAnnotation> other) : Annotation(other)
{
    auto otherPoints = other->getPoints();
    for(auto v : otherPoints)
        points.push_back(mesh->getVertex(v->getId()));
}

PointAnnotation::~PointAnnotation()
{
    this->points.clear();
}


void PointAnnotation::print(std::ostream &os)
{
    Annotation::print(os);
    os << "Annotation on points: [" << std::endl;
    for(unsigned int i = 0; i < points.size(); i++){
        os << "(" << points[i]->getX() << "," << points[i]->getY() << "," << points[i]->getZ() << ")";
        if(i != points.size() - 1)
            os <<",";
        os << std::endl;
    }
}

void PointAnnotation::printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer)
{
    writer.StartObject();
    Annotation::printJson(writer);
    writer.Key("type");
    writer.String("Point");
    writer.Key("points");
    writer.StartArray();
    for(unsigned int i = 0; i < points.size(); i++)
        writer.Int(stoi(points[i]->getId()));
    writer.EndArray();
    writer.EndObject();
}

std::vector<std::shared_ptr<Vertex>> PointAnnotation::getInvolvedVertices()
{
    return points;
}

bool PointAnnotation::isPointInAnnotation(std::shared_ptr<Vertex>v)
{
    for(unsigned int i = 0; i < points.size(); i++)
        if(points[i] == v)
            return true;
    return false;
}

std::vector<std::shared_ptr<Vertex>> PointAnnotation::getPoints() const
{
    return points;
}

void PointAnnotation::setPoints(const std::vector<std::shared_ptr<Vertex>> &value)
{
    points = value;
}

void PointAnnotation::addPoint(std::shared_ptr<Vertex>value)
{
    this->points.push_back(value);
}

