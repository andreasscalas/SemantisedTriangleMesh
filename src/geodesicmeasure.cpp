#include "geodesicmeasure.hpp"

using namespace SemantisedTriangleMesh;
GeodesicMeasure::GeodesicMeasure()
{

}

const std::vector<std::shared_ptr<SemantisedTriangleMesh::Vertex> > &GeodesicMeasure::getPoints() const
{
    return points;
}

void GeodesicMeasure::setPoints(const std::vector<std::shared_ptr<SemantisedTriangleMesh::Vertex> > &newPoints)
{
    points = newPoints;
}


void GeodesicMeasure::print(std::ostream &writer)
{
    GeometricAttribute::print(writer);
    writer<< "Measure taken with a tape" << std::endl;

}

void GeodesicMeasure::printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer)
{
    GeometricAttribute::printJson(writer);
    writer.Key("tool");
    writer.String("tape");
}
