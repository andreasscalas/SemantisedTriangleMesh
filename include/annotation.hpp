#ifndef ANNOTATION_H
#define ANNOTATION_H

#include "Vertex.hpp"
#include "TriangleMesh.hpp"
#include "attribute.hpp"
#include <vector>
#include <string>
#include <ostream>
#include <algorithm>
#include <rapidjson/prettywriter.h>

namespace SemantisedTriangleMesh {
    class TriangleMesh;

    enum class AnnotationType{
        Volume,
        Surface,
        Line,
        Point
    };

    /**
     * @class Annotation
     * @brief Represents an annotation associated with a geometric selection of a 3D mesh.
     *
     * The Annotation class represents an annotation associated with a geometric selection (i.e. sets of vertices, polylines (sets of connected edges)
     * and areas (collections of connected triangles) of a 3D mesh. It provides a common interface for accessing and setting various attributes of
     * the annotation, such as mesh, type, ID, tag, color, and attributes. The class also provides methods for printing the annotation
     * information and computing the centroid and orientation of the annotation.
     */
    class Annotation {

        public:

        /**
             * @brief Annotation Constructor of the annotation class. The only property that is initialized is the color,
             * to which we only associate a memory portion (3 bytes, corresponding to 3 slots containing numbers from 0 to 255).
             */
            Annotation();

            /**
             * @brief Annotation copy constructor
             * @param other The annotation from which attribute values are taken.
             */
            Annotation(std::shared_ptr<Annotation> other);

            /**
             * @brief Destructor for the Annotation class.
             */
            virtual ~Annotation();

            /**
             * @brief Print main information related to the annotation (ID, tag, and attributes).
             * @param os The output stream onto which the information should be written.
             */
            virtual void print(std::ostream& os);

            /**
             * @brief Print main information related to the annotation (ID, tag, and attributes) in JSON format.
             * @param writer The interface with the RapidJSON library for writing the information in JSON format.
             */
            virtual void printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer);

            /**
             * @brief Get the ID of the annotation.
             * @return The ID string associated with the annotation.
             */
            std::string getId() const;

            /**
             * @brief Set the ID of the annotation.
             * @param value The ID string to be set for the annotation.
             */
            void setId(std::string value);

            /**
             * @brief Get the mesh onto which the annotation is defined.
             * @return A shared pointer to the TriangleMesh representing the mesh.
             */
            std::shared_ptr<TriangleMesh> getMesh() const;

            /**
             * @brief Set the mesh onto which the annotation is defined.
             * @param value A shared pointer to the TriangleMesh representing the new mesh to be set.
             */
            void setMesh(std::shared_ptr<TriangleMesh> value);

            /**
             * @brief Get the type of the annotation (Surface, Line, Point).
             * @return The AnnotationType representing the type of the annotation.
             */
            AnnotationType getType() const;

            /**
             * @brief Get the tag of the annotation.
             * @return The tag string associated with the annotation.
             */
            std::string getTag() const;

            /**
             * @brief Set the tag of the annotation.
             * @param value The tag string to be set for the annotation.
             */
            void setTag(const std::string& value);

            /**
             * @brief Get the color associated with the annotation.
             * @return A pointer to an array of three unsigned char values representing the RGB color.
             */
            unsigned char* getColor();

            /**
             * @brief Set the color associated with the annotation.
             * @param value An array of three unsigned char values representing the RGB color.
             */
            void setColor(unsigned char value[3]);

            /**
             * @brief Get the attributes of the annotation.
             * @return A vector containing shared pointers to the attributes of the annotation.
             */
            std::vector<std::shared_ptr<Attribute>> getAttributes() const;

            /**
             * @brief Set the attributes of the annotation.
             * @param value A vector containing shared pointers to the attributes to be set for the annotation.
             */
            void setAttributes(const std::vector<std::shared_ptr<Attribute>>& value);

            /**
             * @brief Add an attribute to the annotation.
             * @param value A shared pointer to the attribute to be added.
             */
            void addAttribute(std::shared_ptr<Attribute> value);

            /**
             * @brief Remove an attribute from the annotation.
             * @param value A shared pointer to the attribute to be removed.
             */
            void removeAttribute(std::shared_ptr<Attribute> value);

            /**
             * @brief Reset the attributes of the annotation (clear all attributes).
             */
            void resetAttributes();

            /**
             * @brief Get the centroid of the annotation.
             * @return A Point with the coordinates of the centroid.
             */
            virtual Point getCenter();

            /**
             * @brief Get the overall orientation of the annotation.
             * @return A Vector defining the orientation.
             */
            virtual Vector getOrientation();

            /**
             * @brief Get the vertices involved in the annotation.
             * @return A vector containing shared pointers to the involved vertices.
             */
            virtual std::vector<std::shared_ptr<Vertex> > getInvolvedVertices() = 0;

            /**
             * @brief Check if a given vertex is involved in the annotation.
             * @param p The vertex that needs to be checked.
             * @return True if the vertex is involved in the annotation, false otherwise.
             */
            virtual bool isPointInAnnotation(std::shared_ptr<Vertex> p) = 0;

    protected:
            std::shared_ptr<TriangleMesh> mesh;                     //The mesh onto which the annotation is defined
            AnnotationType type;                                    //Type of the annotation (Surface, Line, Point)
            std::string id;                                         //Id of the annotation
            std::string tag;                                        //The tag of the annotation
            std::vector<std::shared_ptr<Attribute> > attributes;    //List of attributes of the annotation
            unsigned char* color;                                   //The color associated to the annotation
            static constexpr unsigned short NUM_OF_THREADS = 8;     //Number of threads used for the transfer procedure
            double sphereRay;                                       //The radius of the sphere for the neighborhood search

    };

}
#endif // ANNOTATION_H

