#include "euclideanmeasure.hpp"

using namespace SemantisedTriangleMesh;
EuclideanMeasure::EuclideanMeasure() : SemantisedTriangleMesh::GeometricAttribute()
{

}

const std::shared_ptr<SemantisedTriangleMesh::Point> &EuclideanMeasure::getP0() const
{
    return p0;
}

void EuclideanMeasure::setP0(const std::shared_ptr<SemantisedTriangleMesh::Point> &newP0)
{
    p0 = newP0;
}

const std::shared_ptr<SemantisedTriangleMesh::Point> &EuclideanMeasure::getP1() const
{
    return p1;
}

void EuclideanMeasure::setP1(const std::shared_ptr<SemantisedTriangleMesh::Point> &newP1)
{
    p1 = newP1;
}

void EuclideanMeasure::print(std::ostream &writer)
{
    GeometricAttribute::print(writer);
    writer<< "Measure taken with a ruler" << std::endl;
}

void EuclideanMeasure::printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer )
{
    GeometricAttribute::printJson(writer);
    writer.Key("tool");
    writer.String("ruler");
}
