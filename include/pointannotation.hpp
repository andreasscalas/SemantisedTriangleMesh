#ifndef POINTANNOTATION_H
#define POINTANNOTATION_H

#include "annotation.hpp"
#include "TriangleMesh.hpp"


namespace SemantisedTriangleMesh {
/**
 * @class PointAnnotation
 * @brief Represents a point annotation associated with a triangle mesh.
 *
 * The PointAnnotation class is a subclass of the Annotation class and represents a point annotation defined on a triangle mesh.
 * Point annotations are used to mark and describe individual points on the mesh surface.
 */

class PointAnnotation : virtual public Annotation {
public:
    /**
     * @brief Default constructor for the PointAnnotation class.
     */
    PointAnnotation();

    /**
     * @brief Constructor for the PointAnnotation class with mesh and copy of another PointAnnotation.
     * @param mesh The triangle mesh to which the point annotation is associated.
     * @param other A shared pointer to another PointAnnotation object from which attribute values are taken.
     */
    PointAnnotation(TriangleMesh* mesh, std::shared_ptr<PointAnnotation> other);

    /**
     * @brief Destructor for the PointAnnotation class.
     */
    virtual ~PointAnnotation() override;

    /**
     * @brief Print main information related to the point annotation.
     * @param os The stream onto which the information should be written.
     */
    virtual void print(std::ostream& os) override;

    /**
     * @brief Print main information related to the point annotation in JSON format.
     * @param writer The interface with the RapidJSON library for writing the information in JSON format.
     */
    virtual void printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer) override;

    /**
     * @brief Get the vertices involved in the point annotation.
     * @return A vector containing shared pointers to the involved vertices.
     */
    virtual std::vector<std::shared_ptr<Vertex>> getInvolvedVertices() override;

    /**
     * @brief Check if a given vertex is involved in this point annotation.
     * @param annotatedPoint The vertex that needs to be checked.
     * @return True if the vertex is involved in the annotation, false otherwise.
     */
    virtual bool isPointInAnnotation(std::shared_ptr<Vertex> annotatedPoint) override;

    /**
     * @brief Get the points associated with the point annotation.
     * @return A vector containing shared pointers to the points forming the annotation.
     */
    std::vector<std::shared_ptr<Vertex>> getPoints() const;

    /**
     * @brief Set the points for the point annotation.
     * @param value A vector containing shared pointers to the points forming the annotation.
     */
    void setPoints(const std::vector<std::shared_ptr<Vertex>>& value);

    /**
     * @brief Add a point to the point annotation.
     * @param value A shared pointer to the point to be added.
     */
    void addPoint(std::shared_ptr<Vertex> value);

protected:
    std::vector<std::shared_ptr<Vertex>> points; // The points forming the point annotation
};

}

#endif // POINTANNOTATION_H
