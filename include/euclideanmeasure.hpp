#ifndef EUCLIDEANMEASURE_H
#define EUCLIDEANMEASURE_H

#include <memory>

#include "Point.hpp"
#include "geometricattribute.hpp"

namespace SemantisedTriangleMesh {
    /**
     * @class EuclideanMeasure
     * @brief Represents a Euclidean measure attribute associated with an annotation.
     *
     * The EuclideanMeasure class is a subclass of the GeometricAttribute class and represents a Euclidean measure attribute that can be associated
     * with an annotation. It provides functionalities to store and manage two points (p0 and p1) defining the Euclidean measure.
     * Euclidean measures are used to represent the Euclidean distance between two points in 3D space.
     */

    class EuclideanMeasure : public virtual SemantisedTriangleMesh::GeometricAttribute {
    public:
        /**
         * @brief Default constructor for the EuclideanMeasure class.
         */
        EuclideanMeasure();

        /**
         * @brief Copy constructor for the EuclideanMeasure class.
         * @param measure The EuclideanMeasure from which attribute values are taken.
         */
        EuclideanMeasure(std::shared_ptr<EuclideanMeasure> measure);

        /**
         * @brief Get the first point (p0) of the Euclidean measure.
         * @return A shared pointer to the first point of the Euclidean measure.
         */
        const std::shared_ptr<SemantisedTriangleMesh::Point>& getP0() const;

        /**
         * @brief Set the first point (p0) of the Euclidean measure.
         * @param newP0 A shared pointer to the new first point to be set.
         */
        void setP0(const std::shared_ptr<SemantisedTriangleMesh::Point>& newP0);

        /**
         * @brief Get the second point (p1) of the Euclidean measure.
         * @return A shared pointer to the second point of the Euclidean measure.
         */
        const std::shared_ptr<SemantisedTriangleMesh::Point>& getP1() const;

        /**
         * @brief Set the second point (p1) of the Euclidean measure.
         * @param newP1 A shared pointer to the new second point to be set.
         */
        void setP1(const std::shared_ptr<SemantisedTriangleMesh::Point>& newP1);

        /**
         * @brief Print the main information related to the Euclidean measure (p0 and p1 points).
         * @param os The stream onto which the information should be written.
         */
        virtual void print(std::ostream& os) override;

        /**
         * @brief Print the main information related to the Euclidean measure (p0 and p1 points) in JSON format.
         * @param writer The interface with the RapidJSON library for writing the information in JSON format.
         */
        virtual void printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer) override;

    protected:
        std::shared_ptr<SemantisedTriangleMesh::Point> p0; // The first point (p0) of the Euclidean measure
        std::shared_ptr<SemantisedTriangleMesh::Point> p1; // The second point (p1) of the Euclidean measure
    };

}
#endif // EUCLIDEANMEASURE_H
