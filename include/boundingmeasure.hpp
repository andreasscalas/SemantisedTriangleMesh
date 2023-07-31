#ifndef BOUNDINGMEASURE_H
#define BOUNDINGMEASURE_H

#include <rapidjson/prettywriter.h>

#include "Point.hpp"
#include "geometricattribute.hpp"

namespace SemantisedTriangleMesh {

    /**
     * @class BoundingMeasure
     * @brief Represents a bounding measure as a geometric attribute.
     *
     * The BoundingMeasure class is a subclass of the GeometricAttribute class and represents a bounding measure defined on a triangle mesh.
     * Bounding measures are used to measure the bounds or extents of certain geometric entities in the mesh.
     */

    class BoundingMeasure : public virtual SemantisedTriangleMesh::GeometricAttribute {
    public:
        /**
         * @brief Default constructor for the BoundingMeasure class.
         */
        BoundingMeasure();

        /**
         * @brief Destructor for the BoundingMeasure class.
         */
        ~BoundingMeasure();

        /**
         * @brief Print main information related to the bounding measure.
         * @param os The stream onto which the information should be written.
         */
        virtual void print(std::ostream& os) override;

        /**
         * @brief Print main information related to the bounding measure in JSON format.
         * @param writer The interface with the RapidJSON library for writing the information in JSON format.
         */
        virtual void printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer) override;

        /**
         * @brief Get the origin of the bounding measure.
         * @return A shared pointer to the point representing the origin.
         */
        const std::shared_ptr<SemantisedTriangleMesh::Point>& getOrigin() const;

        /**
         * @brief Set the origin of the bounding measure.
         * @param newOrigin A shared pointer to the point representing the new origin.
         */
        void setOrigin(const std::shared_ptr<SemantisedTriangleMesh::Point>& newOrigin);

        /**
         * @brief Get the direction of the bounding measure.
         * @return A shared pointer to the point representing the direction.
         */
        const std::shared_ptr<SemantisedTriangleMesh::Point>& getDirection() const;

        /**
         * @brief Set the direction of the bounding measure using a shared pointer to a point.
         * @param newDirection A shared pointer to the point representing the new direction.
         */
        void setDirection(const std::shared_ptr<SemantisedTriangleMesh::Point>& newDirection);

        /**
         * @brief Set the direction of the bounding measure using a point object.
         * @param newDirection The point representing the new direction.
         */
        void setDirection(const SemantisedTriangleMesh::Point& newDirection);

    protected:
        std::shared_ptr<SemantisedTriangleMesh::Point> origin;     // The origin of the bounding measure
        std::shared_ptr<SemantisedTriangleMesh::Point> direction;  // The direction of the bounding measure
        SemantisedTriangleMesh::Point extreme0;                   // An extreme point used for bounding calculations
        SemantisedTriangleMesh::Point extreme1;                   // Another extreme point used for bounding calculations
    };

}
#endif // BOUNDINGMEASURE_H
