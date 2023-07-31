#ifndef LINEANNOTATION_H
#define LINEANNOTATION_H

#include <vector>
#include "annotation.hpp"
#include "Vertex.hpp"

namespace SemantisedTriangleMesh {

    /**
     * @class LineAnnotation
     * @brief Represents a line annotation associated with a triangle mesh.
     *
     * The LineAnnotation class is a subclass of the Annotation class and represents a line annotation defined on a triangle mesh.
     * Line annotations are used to mark and describe lines or polylines on the mesh surface.
     */
    class LineAnnotation : virtual public Annotation {
    public:
        /**
         * @brief Default constructor for the LineAnnotation class.
         */
        LineAnnotation();

        /**
         * @brief Constructor for the LineAnnotation class with mesh and copy of another LineAnnotation.
         * @param mesh The triangle mesh to which the line annotation is associated.
         * @param other A shared pointer to another LineAnnotation object from which attribute values are taken.
         */
        LineAnnotation(TriangleMesh* mesh, std::shared_ptr<LineAnnotation> other);

        /**
         * @brief Destructor for the LineAnnotation class.
         */
        virtual ~LineAnnotation() override;

        /**
         * @brief Print main information related to the line annotation.
         * @param os The stream onto which the information should be written.
         */
        virtual void print(std::ostream& os) override;

        /**
         * @brief Print main information related to the line annotation in JSON format.
         * @param writer The interface with the RapidJSON library for writing the information in JSON format.
         */
        virtual void printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer) override;

        /**
         * @brief Get the vertices involved in the line annotation.
         * @return A vector containing shared pointers to the involved vertices.
         */
        virtual std::vector<std::shared_ptr<Vertex>> getInvolvedVertices() override;

        /**
         * @brief Check if a given vertex is involved in this line annotation.
         * @param p The vertex that needs to be checked.
         * @return True if the vertex is involved in the annotation, false otherwise.
         */
        virtual bool isPointInAnnotation(std::shared_ptr<Vertex> p) override;

        /**
         * @brief Add a polyline to the line annotation.
         * @param value A vector containing shared pointers to the vertices forming the polyline.
         */
        void addPolyLine(std::vector<std::shared_ptr<Vertex>>& value);

        /**
         * @brief Get the polylines forming the line annotation.
         * @return A vector of vectors containing shared pointers to the vertices forming the polylines.
         */
        std::vector<std::vector<std::shared_ptr<Vertex>>> getPolyLines() const;

        /**
         * @brief Set the polylines for the line annotation.
         * @param value A vector of vectors containing shared pointers to the vertices forming the polylines.
         */
        void setPolyLines(const std::vector<std::vector<std::shared_ptr<Vertex>>>& value);

        /**
         * @brief Clear all the polylines in the line annotation.
         */
        void clearPolylines();

    protected:
        std::vector<std::vector<std::shared_ptr<Vertex>>> polyLines; // The polylines forming the line annotation
        const short BBOX_SPHERE_RATIO = 1000;                       // Divisive coefficient between the BBox longest diagonal and neighborhood sphere radius
        const bool POST_PROCESSING = true;                         // Spikes can be removed in postprocessing or avoided by inserting infinite weights in the shortest path computation.
    };

}

#endif // LINEANNOTATION_H
