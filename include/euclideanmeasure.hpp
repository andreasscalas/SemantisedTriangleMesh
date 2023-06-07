#ifndef EUCLIDEANMEASURE_H
#define EUCLIDEANMEASURE_H

#include <memory>

#include "Point.hpp"
#include "geometricattribute.hpp"

namespace SemantisedTriangleMesh {
    class EuclideanMeasure : public virtual SemantisedTriangleMesh::GeometricAttribute
    {
    public:
        EuclideanMeasure();
        EuclideanMeasure(std::shared_ptr<EuclideanMeasure> measure);
        const std::shared_ptr<SemantisedTriangleMesh::Point> &getP0() const;
        void setP0(const std::shared_ptr<SemantisedTriangleMesh::Point> &newP0);

        const std::shared_ptr<SemantisedTriangleMesh::Point> &getP1() const;
        void setP1(const std::shared_ptr<SemantisedTriangleMesh::Point> &newP1);
        virtual void print(std::ostream &) override;
        virtual void printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer> &) override;

    protected:
        std::shared_ptr<SemantisedTriangleMesh::Point> p0;
        std::shared_ptr<SemantisedTriangleMesh::Point> p1;
    };
}
#endif // EUCLIDEANMEASURE_H
