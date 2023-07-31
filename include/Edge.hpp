#ifndef EDGE_H
#define EDGE_H

#include "Vertex.hpp"
#include "Triangle.hpp"
#include "CommonDefinitions.hpp"
#include <vector>
#include <memory>

namespace SemantisedTriangleMesh {
    class Vertex;
    class Triangle;

    /**
     * @class Edge
     * @brief Represents an edge connecting two vertices in a 3D triangle mesh.
     *
     * The Edge class represents an edge that connects two vertices in a 3D triangle mesh. It stores references
     * to the two vertices, as well as the triangles on the left and right sides of the edge (if present). The class
     * provides member functions for retrieving common and opposite vertices, adjacent triangles, and other edge properties.
     */
    class Edge
    {
    public:

        /**
         * @brief Default constructor for creating an uninitialized Edge object.
         */
        Edge();

        /**
         * @brief Constructor for creating an Edge object with specified vertices.
         * @param v1 The first vertex of the edge.
         * @param v2 The second vertex of the edge.
         */
        Edge(std::shared_ptr<Vertex> v1, std::shared_ptr<Vertex> v2);

        /**
         * @brief Copy constructor for creating an Edge object from another edge.
         * @param other The other edge to copy from.
         */
        Edge(std::shared_ptr<Edge> other);

        /**
         * @brief Destructor for the Edge object.
         */
        ~Edge();

        /**
         * @brief Get the common vertex between this edge and another edge.
         * @param e2 The other edge to find the common vertex with.
         * @return A shared pointer to the common vertex, or nullptr if there is no common vertex.
         */
        std::shared_ptr<Vertex> getCommonVertex(std::shared_ptr<Edge> e2);

        /**
         * @brief Get the vertex that is opposite to the given vertex in this edge.
         * @param v The vertex whose opposite vertex is requested.
         * @return A shared pointer to the opposite vertex, or nullptr if the given vertex is not part of this edge.
         */
        std::shared_ptr<Vertex> getOppositeVertex(std::shared_ptr<Vertex> v);

        /**
         * @brief Get the triangle on the left side of this edge that contains the given vertex.
         * @param v The vertex whose containing triangle is requested.
         * @return A shared pointer to the left triangle containing the vertex, or nullptr if no such triangle exists.
         */
        std::shared_ptr<Triangle> getLeftTriangle(std::shared_ptr<Vertex> v);

        /**
         * @brief Get the triangle on the right side of this edge that contains the given vertex.
         * @param v The vertex whose containing triangle is requested.
         * @return A shared pointer to the right triangle containing the vertex, or nullptr if no such triangle exists.
         */
        std::shared_ptr<Triangle> getRightTriangle(std::shared_ptr<Vertex> v);

        /**
         * @brief Get the triangle that is opposite to the given triangle with respect to this edge.
         * @param v The triangle whose opposite triangle is requested.
         * @return A shared pointer to the opposite triangle, or nullptr if the given triangle is not adjacent to this edge.
         */
        std::shared_ptr<Triangle> getOppositeTriangle(std::shared_ptr<Triangle> v);

        /**
         * @brief Check if this edge contains the given vertex.
         * @param v The vertex to check for.
         * @return True if the vertex is part of this edge, false otherwise.
         */
        bool hasVertex(std::shared_ptr<Vertex> v);

        /**
         * @brief Check if this edge contains the given vertex.
         * @param v The raw pointer to the vertex to check for.
         * @return True if the vertex is part of this edge, false otherwise.
         */
        bool hasVertex(Vertex* v);

        /**
         * @brief Get the first vertex of the edge.
         * @return A shared pointer to the first vertex of the edge.
         */
        std::shared_ptr<Vertex> getV1() const;

        /**
         * @brief Set the first vertex of the edge.
         * @param newV1 A shared pointer to the new first vertex of the edge.
         */
        void setV1(std::shared_ptr<Vertex> newV1);

        /**
         * @brief Get the second vertex of the edge.
         * @return A shared pointer to the second vertex of the edge.
         */
        std::shared_ptr<Vertex> getV2() const;

        /**
         * @brief Set the second vertex of the edge.
         * @param newV2 A shared pointer to the new second vertex of the edge.
         */
        void setV2(std::shared_ptr<Vertex> newV2);

        /**
         * @brief Set the vertices of the edge to the specified vertices.
         * @param v1 The first vertex of the edge.
         * @param v2 The second vertex of the edge.
         * @return True if the vertices were set successfully, false otherwise.
         */
        bool setVertex(std::shared_ptr<Vertex> v1, std::shared_ptr<Vertex> v2);

        /**
         * @brief Get the first triangle adjacent to the edge.
         * @return A shared pointer to the first triangle adjacent to the edge.
         */
        std::shared_ptr<Triangle> getT1() const;

        /**
         * @brief Set the first triangle adjacent to the edge.
         * @param newT1 A shared pointer to the new first triangle adjacent to the edge.
         */
        void setT1(std::shared_ptr<Triangle> newT1);

        /**
         * @brief Get the second triangle adjacent to the edge.
         * @return A shared pointer to the second triangle adjacent to the edge.
         */
        std::shared_ptr<Triangle> getT2() const;

        /**
         * @brief Set the second triangle adjacent to the edge.
         * @param newT2 A shared pointer to the new second triangle adjacent to the edge.
         */
        void setT2(std::shared_ptr<Triangle> newT2);

        /**
         * @brief Set the adjacent triangles of the edge to the specified triangles.
         * @param t The first triangle adjacent to the edge.
         * @param newT The second triangle adjacent to the edge.
         * @return True if the triangles were set successfully, false otherwise.
         */
        bool setTriangle(std::shared_ptr<Triangle> t, std::shared_ptr<Triangle> newT);

        /**
         * @brief Get the additional information associated with the edge.
         * @return A constant reference to the vector containing additional information associated with the edge.
         */
        const std::vector<void *> &getInformation() const;

        /**
         * @brief Set additional information to associate with the edge.
         * @param newInformation The vector containing the additional information to be associated with the edge.
         */
        void setInformation(const std::vector<void *> &newInformation);

        /**
         * @brief Get the flags associated with the edge.
         * @return A constant reference to the vector containing the flags associated with the edge.
         */
        const std::vector<FlagType> &getAssociatedFlags() const;

        /**
         * @brief Set the flags associated with the edge.
         * @param newAssociatedFlags The vector containing the flags to be associated with the edge.
         */
        void setAssociatedFlags(const std::vector<FlagType> &newAssociatedFlags);

        /**
         * @brief Add a flag to the edge.
         * @param flag The flag to be added.
         * @return True if the flag was added successfully, false if the flag already exists.
         */
        bool addFlag(FlagType flag);

        /**
         * @brief Search for a flag in the edge.
         * @param flag The flag to search for.
         * @return The index of the flag if found, or -1 if the flag does not exist in the edge.
         */
        int searchFlag(FlagType flag);

        /**
         * @brief Remove a flag from the edge.
         * @param flag The flag to be removed.
         * @return True if the flag was removed successfully, false if the flag does not exist in the edge.
         */
        bool removeFlag(FlagType flag);

        /**
         * @brief Remove a flag from the edge by index.
         * @param index The index of the flag to be removed.
         * @return True if the flag was removed successfully, false if the index is out of range.
         */
        bool removeFlag(unsigned int index);

        /**
         * @brief Add additional information to the edge.
         * @param info A pointer to the additional information to be added.
         * @return True if the information was added successfully, false if it already exists in the edge.
         */
        bool addInformation(void *info);

        /**
         * @brief Search for additional information in the edge.
         * @param info A pointer to the information to search for.
         * @return The index of the information if found, or -1 if the information does not exist in the edge.
         */
        int searchInfo(void *info);

        /**
         * @brief Remove additional information from the edge.
         * @param info A pointer to the information to be removed.
         * @return True if the information was removed successfully, false if the information does not exist in the edge.
         */
        bool removeInfo(void *info);

        /**
         * @brief Remove additional information from the edge by index.
         * @param index The index of the information to be removed.
         * @return True if the information was removed successfully, false if the index is out of range.
         */
        bool removeInfo(unsigned int index);

        /**
         * @brief Clear all additional information associated with the edge.
         * @return True if all information was cleared successfully, false if there was no information to clear.
         */
        bool clearInfo();

        /**
         * @brief Get the ID of the edge.
         * @return The ID of the edge as a string.
         */
        std::string getId() const;

        /**
         * @brief Set the ID of the edge.
         * @param newId The new ID to be set for the edge.
         */
        void setId(std::string newId);

        /**
         * @brief Compute the length of the edge.
         * @return The length of the edge.
         */
        double computeLength() const;

        /**
         * @brief Collapse the edge by removing one of its vertices and updating adjacent elements accordingly.
         * The vertex that will be removed is the one that forms a fan triangle with the two vertices of the edge.
         * @note This function should be used carefully as it may result in a change of mesh topology.
         */
        void collapse();

        /**
         * @brief Print the edge information to an output stream.
         * @param stream The output stream to print the edge information to.
         */
        void print(std::ostream &stream);

        // ... The end of the class and member function comments.


    protected:
        std::string id;
        std::shared_ptr<Vertex>  v1;
        std::shared_ptr<Vertex>  v2;
        std::shared_ptr<Triangle> t1;
        std::shared_ptr<Triangle> t2;
        std::vector<void*> information;
        std::vector<FlagType> associated_flags;
    };
}
#endif // EDGE_H
