#ifndef BOUNDINGMEASURE_H
#define BOUNDINGMEASURE_H

#include <rapidjson/prettywriter.h>

#include "Point.hpp"
#include "geometricattribute.hpp"

namespace SemantisedTriangleMesh {

    class BoundingMeasure : public virtual SemantisedTriangleMesh::GeometricAttribute
    {
    public:
        BoundingMeasure();
        ~BoundingMeasure();

        virtual void print(std::ostream &) override;
        virtual void printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer> &) override;


        const std::shared_ptr<SemantisedTriangleMesh::Point> &getOrigin() const;
        void setOrigin(const std::shared_ptr<SemantisedTriangleMesh::Point> &newOrigin);

        const std::shared_ptr<SemantisedTriangleMesh::Point> &getDirection() const;
        void setDirection(const std::shared_ptr<SemantisedTriangleMesh::Point> &newDirection);
        void setDirection(const SemantisedTriangleMesh::Point &newDirection);

    protected:
        std::shared_ptr<SemantisedTriangleMesh::Point> origin;
        std::shared_ptr<SemantisedTriangleMesh::Point> direction;
        SemantisedTriangleMesh::Point extreme0;
        SemantisedTriangleMesh::Point extreme1;
    };
}
#endif // BOUNDINGMEASURE_H
