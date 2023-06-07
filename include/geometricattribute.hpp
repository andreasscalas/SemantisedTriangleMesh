#ifndef GEOMETRICATTRIBUTE_H
#define GEOMETRICATTRIBUTE_H

#include "attribute.hpp"
#include <memory>
#include <vector>

namespace SemantisedTriangleMesh {

    enum class GeometricAttributeType {
        EUCLIDEAN_MEASURE,
        GEODESIC_MEASURE,
        BOUNDING_MEASURE
    };

    class GeometricAttribute : virtual public Attribute
    {
    public:
        GeometricAttribute();
        GeometricAttribute(std::shared_ptr<GeometricAttribute>);
        virtual ~GeometricAttribute() override;

        virtual void print(std::ostream&) override;
        virtual void printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer>&) override;

        std::vector<unsigned int> getMeasurePointsID() const;
        void setMeasurePointsID(const std::vector<unsigned int> &value);
        void addMeasurePointID(const unsigned int &value);
        void removeMeasurePointID(const unsigned int value);
        void clearMeasurePointsID();

        GeometricAttributeType getType() const;
        void setType(GeometricAttributeType newType);

    protected:
        std::vector<unsigned int> measurePointsID;
        GeometricAttributeType type;

    };
}

#endif // GEOMETRICATTRIBUTE_H
