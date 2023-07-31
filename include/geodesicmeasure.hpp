#ifndef GEODESICMEASURE_H
#define GEODESICMEASURE_H

#include <memory>

#include "geometricattribute.hpp"
#include "Vertex.hpp"

namespace SemantisedTriangleMesh {
    /**
     * @class GeodesicMeasure
     * @brief Represents a geodesic measure attribute associated with an annotation.
     *
     * The GeodesicMeasure class is a subclass of the GeometricAttribute class and represents a geodesic measure attribute that can be associated
     * with an annotation. It provides functionalities to store and manage a set of points defining the geodesic measure.
     * Geodesic measures are used to represent the shortest distance between a given set of points along the surface of a 3D mesh.
     */

    class GeodesicMeasure : public virtual SemantisedTriangleMesh::GeometricAttribute {
    public:
        /**
         * @brief Default constructor for the GeodesicMeasure class.
         */
        GeodesicMeasure();

        /**
         * @brief Get the vector of points defining the geodesic measure.
         * @return A constant reference to the vector of shared pointers to the points.
         */
        const std::vector<std::shared_ptr<SemantisedTriangleMesh::Vertex>>& getPoints() const;

        /**
         * @brief Set the vector of points defining the geodesic measure.
         * @param newPoints The vector of shared pointers to the points to be set.
         */
        void setPoints(const std::vector<std::shared_ptr<SemantisedTriangleMesh::Vertex>>& newPoints);

        /**
         * @brief Print the main information related to the geodesic measure (points).
         * @param os The stream onto which the information should be written.
         */
        virtual void print(std::ostream& os) override;

        /**
         * @brief Print the main information related to the geodesic measure (points) in JSON format.
         * @param writer The interface with the RapidJSON library for writing the information in JSON format.
         */
        virtual void printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer) override;

    protected:
        std::vector<std::shared_ptr<SemantisedTriangleMesh::Vertex>> points; // The vector of points defining the geodesic measure
    };

}
#endif // GEODESICMEASURE_H
