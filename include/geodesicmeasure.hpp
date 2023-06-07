#ifndef GEODESICMEASURE_H
#define GEODESICMEASURE_H

#include <memory>

#include "geometricattribute.hpp"
#include "Vertex.hpp"

namespace SemantisedTriangleMesh {
    class GeodesicMeasure : public virtual SemantisedTriangleMesh::GeometricAttribute
    {
    public:
        GeodesicMeasure();
        const std::vector<std::shared_ptr<SemantisedTriangleMesh::Vertex> > &getPoints() const;
        void setPoints(const std::vector<std::shared_ptr<SemantisedTriangleMesh::Vertex> > &newPoints);

        virtual void print(std::ostream &) override;
        virtual void printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer> &) override;
    protected:

        std::vector<std::shared_ptr<SemantisedTriangleMesh::Vertex> > points;
    };
}
#endif // GEODESICMEASURE_H
