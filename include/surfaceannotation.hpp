#ifndef AREAANNOTATION_H
#define AREAANNOTATION_H

#include "annotation.hpp"

namespace SemantisedTriangleMesh {
/**
 * @class SurfaceAnnotation
 * @brief Represents a surface annotation associated with a triangle mesh.
 *
 * The SurfaceAnnotation class is a subclass of the Annotation class and represents a surface annotation defined on a triangle mesh.
 * Surface annotations are used to mark and describe regions enclosed by contours on the mesh surface.
 */

class SurfaceAnnotation : virtual public Annotation {
    public:
        /**
         * @brief Default constructor for the SurfaceAnnotation class.
         */
        SurfaceAnnotation();

        /**
         * @brief Constructor for the SurfaceAnnotation class with mesh and copy of another SurfaceAnnotation.
         * @param mesh The triangle mesh to which the surface annotation is associated.
         * @param other A shared pointer to another SurfaceAnnotation object from which attribute values are taken.
         */
        SurfaceAnnotation(TriangleMesh* mesh, std::shared_ptr<SurfaceAnnotation> other);

        /**
         * @brief Destructor for the SurfaceAnnotation class.
         */
        virtual ~SurfaceAnnotation() override;

        /**
         * @brief Print main information related to the surface annotation.
         * @param os The stream onto which the information should be written.
         */
        virtual void print(std::ostream& os) override;

        /**
         * @brief Print main information related to the surface annotation in JSON format.
         * @param writer The interface with the RapidJSON library for writing the information in JSON format.
         */
        virtual void printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer) override;

        /**
         * @brief Get the vertices involved in the surface annotation.
         * @return A vector containing shared pointers to the involved vertices.
         */
        virtual std::vector<std::shared_ptr<Vertex>> getInvolvedVertices() override;

        /**
         * @brief Get the inner vertices within the surface annotation.
         * @return A vector containing shared pointers to the inner vertices.
         */
        virtual std::vector<std::shared_ptr<Vertex>> getInnerVertices();

        /**
         * @brief Check if a given vertex is involved in this surface annotation.
         * @param p The vertex that needs to be checked.
         * @return True if the vertex is involved in the annotation, false otherwise.
         */
        virtual bool isPointInAnnotation(std::shared_ptr<Vertex> p) override;

        /**
         * @brief Check if a given vertex is inside this surface annotation.
         * @param p The vertex that needs to be checked.
         * @return True if the vertex is inside the annotation, false otherwise.
         */
        virtual bool isPointInsideAnnotation(std::shared_ptr<Vertex> p);

        /**
         * @brief Check if a given vertex lies on the border of this surface annotation.
         * @param p The vertex that needs to be checked.
         * @return True if the vertex lies on the border, false otherwise.
         */
        bool isPointOnBorder(std::shared_ptr<Vertex> p);

        /**
         * @brief Check if a given vertex lies on the border of this surface annotation and get the boundary index.
         * @param p The vertex that needs to be checked.
         * @param boundaryIndex Reference to store the boundary index (if found).
         * @return True if the vertex lies on the border, false otherwise.
         */
        bool isPointOnBorder(std::shared_ptr<Vertex> p, unsigned int& boundaryIndex);

        /**
         * @brief Check if a given triangle is part of this surface annotation.
         * @param p The triangle that needs to be checked.
         * @return True if the triangle is part of the annotation, false otherwise.
         */
        virtual bool isTriangleInAnnotation(std::shared_ptr<Triangle> p);

        /**
         * @brief Get the adjacent boundary indices with another surface annotation.
         * @param a Another SurfaceAnnotation object.
         * @return A pair of boundary indices corresponding to the adjacent boundaries with the other annotation.
         */
        std::pair<unsigned int, unsigned int> getAdjacentBoundary(SurfaceAnnotation* a);

        /**
         * @brief Check the adjacency of this surface annotation with another.
         * @param a Another SurfaceAnnotation object.
         * @return True if the annotations are adjacent, false otherwise.
         */
        bool checkAdjacency(SurfaceAnnotation* a);

        // Getter and setter methods
        std::vector<std::vector<std::shared_ptr<Vertex>>> getOutlines() const;
        void setOutlines(const std::vector<std::vector<std::shared_ptr<Vertex>>>& value);
        void addOutline(const std::vector<std::shared_ptr<Vertex>> value);
        std::vector<std::shared_ptr<Triangle>> getTriangles();
        std::vector<std::string> getTrianglesIds();

        /**
         * @brief Region growing method for obtaining the set of triangles composing a region enclosed by some contours.
         * @param contours The contours enclosing the region.
         * @return The set of triangles composing the region.
         */
        static std::vector<std::shared_ptr<Triangle>> regionGrowing(std::vector<std::vector<std::shared_ptr<Vertex>>> contours);

        /**
         * @brief Get the outlines of a set of triangles.
         * @param set The set of triangles.
         * @return The outlines of the triangles.
         */
        static std::vector<std::vector<std::shared_ptr<Vertex>>> getOutlines(std::vector<std::shared_ptr<Triangle>> set);

    protected:
        std::vector<std::vector<std::shared_ptr<Vertex>>> outlines;  // The outline of the annotated region
        const short BBOX_SPHERE_RATIO = 100;                          // Divisive coefficient between the BBox longest diagonal and neighborhood sphere radius
        const bool ORDER = true;                                      // Order of the outline: if TRUE then it is counterclockwise, otherwise is clockwise
        const bool POST_PROCESSING = false;                           // Spikes can be removed in postprocessing or avoided by inserting infinite weights in the shortest path computation.
    };

}

#endif // AREAANNOTATION_H
