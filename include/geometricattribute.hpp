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

    /**
     * @class GeometricAttribute
     * @brief Represents a geometric attribute associated with an annotation.
     *
     * The GeometricAttribute class is a subclass of the Attribute class and represents a geometric attribute that can be associated
     * with an annotation. It provides functionalities to store and manage measure points' IDs and the geometric attribute type.
     * Geometric attributes are used to define additional geometric information related to an annotation.
     */
    class GeometricAttribute : virtual public Attribute
    {
    public:
        /**
         * @brief Default constructor for the GeometricAttribute class.
         */
        GeometricAttribute();

        /**
         * @brief Copy constructor for the GeometricAttribute class.
         * @param other The GeometricAttribute from which attribute values are taken.
         */
        GeometricAttribute(std::shared_ptr<GeometricAttribute> other);

        /**
         * @brief Destructor for the GeometricAttribute class.
         */
        virtual ~GeometricAttribute() override;

        /**
         * @brief Print the main information related to the geometric attribute (measure points' IDs and attribute type).
         * @param os The stream onto which the information should be written.
         */
        virtual void print(std::ostream& os) override;

        /**
         * @brief Print the main information related to the geometric attribute (measure points' IDs and attribute type) in JSON format.
         * @param writer The interface with the RapidJSON library for writing the information in JSON format.
         */
        virtual void printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer) override;

        /**
         * @brief Get the IDs of the measure points associated with the geometric attribute.
         * @return A vector containing the IDs of the measure points.
         */
        std::vector<unsigned int> getMeasurePointsID() const;

        /**
         * @brief Set the IDs of the measure points associated with the geometric attribute.
         * @param value A vector containing the IDs of the measure points to be associated.
         */
        void setMeasurePointsID(const std::vector<unsigned int>& value);

        /**
         * @brief Add a measure point ID to the geometric attribute.
         * @param value The ID of the measure point to be added.
         */
        void addMeasurePointID(const unsigned int& value);

        /**
         * @brief Remove a measure point ID from the geometric attribute.
         * @param value The ID of the measure point to be removed.
         */
        void removeMeasurePointID(const unsigned int value);

        /**
         * @brief Clear all measure point IDs associated with the geometric attribute.
         */
        void clearMeasurePointsID();

        /**
         * @brief Get the type of the geometric attribute.
         * @return The GeometricAttributeType representing the type of the geometric attribute.
         */
        GeometricAttributeType getType() const;

        /**
         * @brief Set the type of the geometric attribute.
         * @param newType The GeometricAttributeType representing the new type to be set.
         */
        void setType(GeometricAttributeType newType);

    protected:
        std::vector<unsigned int> measurePointsID; // The IDs of the measure points associated with the geometric attribute
        GeometricAttributeType type;

    };
}

#endif // GEOMETRICATTRIBUTE_H
