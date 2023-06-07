#include "boundingmeasure.hpp"
using namespace SemantisedTriangleMesh;

BoundingMeasure::BoundingMeasure() : GeometricAttribute()
{
    direction = nullptr;
}

BoundingMeasure::~BoundingMeasure()
{
    if(direction != nullptr)
        direction.reset();
}

void BoundingMeasure::print(std::ostream &writer)
{
    GeometricAttribute::print(writer);
    writer<< "Measure taken with a bounding tool. It is defined in the direction: (" <<
             direction->getX() << "," << direction->getY() << "," << direction->getZ() << ")"<< std::endl;
}

void BoundingMeasure::printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer)
{
    GeometricAttribute::printJson(writer);
    writer.Key("tool");
    writer.String("bounding");
    writer.Key("direction");
    writer.StartArray();
    writer.Double(direction->getX());
    writer.Double(direction->getY());
    writer.Double(direction->getZ());
    writer.EndArray();
}

const std::shared_ptr<SemantisedTriangleMesh::Point> &BoundingMeasure::getOrigin() const
{
    return origin;
}

void BoundingMeasure::setOrigin(const std::shared_ptr<SemantisedTriangleMesh::Point> &newOrigin)
{
    origin = newOrigin;
}

const std::shared_ptr<SemantisedTriangleMesh::Point> &BoundingMeasure::getDirection() const
{
    return direction;
}

void BoundingMeasure::setDirection(const std::shared_ptr<SemantisedTriangleMesh::Point> &newDirection)
{
    direction = newDirection;
}

void BoundingMeasure::setDirection(const SemantisedTriangleMesh::Point &newDirection)
{
    direction = std::make_shared<SemantisedTriangleMesh::Point>(newDirection);
}
