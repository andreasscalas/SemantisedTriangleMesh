#ifndef TRIANGLE_H
#define TRIANGLE_H

#include "Vertex.hpp"
#include "Edge.hpp"
#include "CommonDefinitions.hpp"
#include <vector>
#include <memory>

namespace SemantisedTriangleMesh {
    class Vertex;
    class Edge;

    /**
     * @class Triangle
     * @brief Represents a triangle in a geometric model.
     *
     * The Triangle class represents a triangle in a geometric model. It can be initialized with
     * different constructors and provides various member functions to access and modify information
     * associated with the triangle.
     */
    class Triangle {
    public:

        static constexpr double EPSILON_BC = 1e-7;
        /**
         * @brief Default constructor for creating an empty Triangle object.
         */
        Triangle();

        /**
         * @brief Constructor for creating a Triangle object with three shared pointers to edges.
         * @param e1 A shared pointer to the first edge of the triangle.
         * @param e2 A shared pointer to the second edge of the triangle.
         * @param e3 A shared pointer to the third edge of the triangle.
         */
        Triangle(const std::shared_ptr<Edge>& e1, const std::shared_ptr<Edge>& e2, const std::shared_ptr<Edge>& e3);

        /**
         * @brief Constructor for creating a Triangle object with a shared pointer to another Triangle object.
         * @param t A shared pointer to the Triangle object to initialize this triangle from.
         */
        Triangle(const std::shared_ptr<Triangle>& t);

        /**
         * @brief Destructor for the Triangle object.
         *
         * The destructor frees any allocated resources for the Triangle object.
         */
        ~Triangle();

        /**
         * @brief Get the ID of the triangle.
         * @return The ID of the triangle as a string.
         */
        std::string getId() const;

        /**
         * @brief Set the ID of the triangle.
         * @param newId The new ID to set for the triangle.
         */
        void setId(const std::string& newId);

        /**
         * @brief Get the first vertex of the triangle.
         * @return A shared pointer to the first vertex of the triangle.
         */
        std::shared_ptr<Vertex> getV1() const;

        /**
         * @brief Get the second vertex of the triangle.
         * @return A shared pointer to the second vertex of the triangle.
         */
        std::shared_ptr<Vertex> getV2() const;

        /**
         * @brief Get the third vertex of the triangle.
         * @return A shared pointer to the third vertex of the triangle.
         */
        std::shared_ptr<Vertex> getV3() const;

        /**
         * @brief Get the first edge of the triangle.
         * @return A shared pointer to the first edge of the triangle.
         */
        std::shared_ptr<Edge> getE1() const;

        /**
         * @brief Set the first edge of the triangle.
         * @param newE1 A shared pointer to the new first edge to be set.
         */
        void setE1(const std::shared_ptr<Edge>& newE1);

        /**
         * @brief Get the second edge of the triangle.
         * @return A shared pointer to the second edge of the triangle.
         */
        std::shared_ptr<Edge> getE2() const;

        /**
         * @brief Set the second edge of the triangle.
         * @param newE2 A shared pointer to the new second edge to be set.
         */
        void setE2(const std::shared_ptr<Edge>& newE2);

        /**
         * @brief Get the third edge of the triangle.
         * @return A shared pointer to the third edge of the triangle.
         */
        std::shared_ptr<Edge> getE3() const;

        /**
         * @brief Set the third edge of the triangle.
         * @param newE3 A shared pointer to the new third edge to be set.
         */
        void setE3(const std::shared_ptr<Edge>& newE3);

        /**
         * @brief Set an edge of the triangle with the given edge.
         * @param oldE A shared pointer to the edge to set.
         * @param newE A shared pointer to the new edge.
         * @return True if the edge was successfully set, false otherwise.
         */
        bool setEdge(const std::shared_ptr<Edge>& oldE, const std::shared_ptr<Edge>& newE);

        /**
         * @brief Get the previous vertex of the given vertex in the triangle.
         * @param v A shared pointer to the vertex for which to find the previous vertex.
         * @return A shared pointer to the previous vertex, or nullptr if v is not a vertex of the triangle.
         */
        std::shared_ptr<Vertex> getPreviousVertex(std::shared_ptr<Vertex> v);

        /**
         * @brief Get the next vertex of the given vertex in the triangle.
         * @param v A shared pointer to the vertex for which to find the next vertex.
         * @return A shared pointer to the next vertex, or nullptr if v is not a vertex of the triangle.
         */
        std::shared_ptr<Vertex> getNextVertex(std::shared_ptr<Vertex> v);

        /**
         * @brief Get the previous edge of the given edge in the triangle.
         * @param e A shared pointer to the edge for which to find the previous edge.
         * @return A shared pointer to the previous edge, or nullptr if e is not an edge of the triangle.
         */
        std::shared_ptr<Edge> getPreviousEdge(std::shared_ptr<Edge> e);

        /**
         * @brief Get the next edge of the given edge in the triangle.
         * @param e A shared pointer to the edge for which to find the next edge.
         * @return A shared pointer to the next edge, or nullptr if e is not an edge of the triangle.
         */
        std::shared_ptr<Edge> getNextEdge(std::shared_ptr<Edge> e);

        /**
         * @brief Get the information associated with the triangle.
         * @return A constant reference to the vector containing the associated information.
         */
        const std::vector<void*>& getInformation() const;

        /**
         * @brief Set the information associated with the triangle.
         * @param newInformation The vector containing the new information to be associated with the triangle.
         */
        void setInformation(const std::vector<void*>& newInformation);

        /**
         * @brief Get the associated flags of the triangle.
         * @return A constant reference to the vector containing the associated flags.
         */
        const std::vector<FlagType>& getAssociatedFlags() const;

        /**
         * @brief Set the associated flags of the triangle.
         * @param newAssociatedFlags The vector containing the new flags to be associated with the triangle.
         */
        void setAssociatedFlags(const std::vector<FlagType>& newAssociatedFlags);

        /**
         * @brief Get the edge opposite to the given vertex in the triangle.
         * @param v A shared pointer to the vertex for which to find the opposite edge.
         * @return A shared pointer to the edge opposite to the vertex, or nullptr if v is not a vertex of the triangle.
         */
        std::shared_ptr<Edge> getOppositeEdge(std::shared_ptr<Vertex> v) const;

        /**
         * @brief Get the vertex opposite to the given edge in the triangle.
         * @param e A shared pointer to the edge for which to find the opposite vertex.
         * @return A shared pointer to the vertex opposite to the edge, or nullptr if e is not an edge of the triangle.
         */
        std::shared_ptr<Vertex> getOppositeVertex(std::shared_ptr<Edge> e) const;

        /**
         * @brief Check if the triangle contains a specific edge.
         * @param e A shared pointer to the edge to check for.
         * @return True if the triangle contains the edge, false otherwise.
         */
        bool hasEdge(std::shared_ptr<Edge> e);

        /**
         * @brief Get the common edge shared between this triangle and the specified triangle.
         * @param t A shared pointer to the triangle to find the common edge with.
         * @return A shared pointer to the common edge, or nullptr if no common edge exists.
         */
        std::shared_ptr<Edge> getCommonEdge(std::shared_ptr<Triangle> t) const;

        /**
         * @brief Project a point onto the plane of the triangle.
         * @param p The point to be projected onto the triangle.
         * @return The projected point on the plane of the triangle.
         */
        Point project(Point p) const;

        /**
         * @brief Compute the normal vector of the triangle.
         * @return The normal vector of the triangle as a Point object.
         */
        Point computeNormal() const;

        /**
         * @brief Compute the barycentric coordinates of a point within the triangle.
         * @param p The point for which to compute the barycentric coordinates.
         * @param[out] alpha The computed alpha coordinate.
         * @param[out] beta The computed beta coordinate.
         * @param[out] gamma The computed gamma coordinate.
         */
        void computeBC(Point p, double& alpha, double& beta, double& gamma);

        /**
         * @brief Check if a point lies inside the triangle.
         * @param p The point to be checked.
         * @return True if the point is inside the triangle, false otherwise.
         */
        bool isPointInside(Point p);

        /**
         * @brief Compute the squared distance from a point to the triangle.
         * @param p The point for which to compute the squared distance.
         * @return The squared distance from the point to the triangle.
         */
        double squaredDistanceFromPoint(Point p) const;

        /**
         * @brief Compute the distance from a point to the triangle.
         * @param p The point for which to compute the distance.
         * @param[out] c The closest point on the triangle to the given point (optional).
         * @return The distance from the point to the triangle.
         */
        double computeDistanceFromPoint(Point p, Point* c = nullptr);

        /**
         * @brief Check if the triangle is coherently oriented with respect to another triangle.
         * @param t A shared pointer to the other triangle.
         * @return True if the triangle is coherently oriented with respect to the other triangle, false otherwise.
         */
        bool isCoherentlyOriented(std::shared_ptr<Triangle> t);

        /**
         * @brief Orient the triangle consistently.
         *
         * This function ensures that the triangle's vertices are ordered in a consistent
         * counter-clockwise manner when viewed from the outside of the surface.
         */
        void orient();

        /**
         * @brief Compute the area of the triangle.
         * @return The area of the triangle.
         */
        double computeArea();


        /**
         * @brief Add a flag to the associated flags of the triangle.
         * @param flag The flag to add to the associated flags.
         * @return True if the flag was successfully added, false otherwise.
         */
        bool addFlag(FlagType flag);

        /**
         * @brief Search for a specific flag in the associated flags of the triangle.
         * @param flag The flag to search for.
         * @return The index of the found flag if it exists, or -1 if the flag is not found.
         */
        int searchFlag(FlagType flag);

        /**
         * @brief Remove a flag from the associated flags of the triangle.
         * @param flag The flag to remove.
         * @return True if the flag was successfully removed, false otherwise.
         */
        bool removeFlag(FlagType flag);

        /**
         * @brief Remove a flag at the specified index from the associated flags of the triangle.
         * @param index The index of the flag to remove.
         * @return True if the flag at the specified index was successfully removed, false otherwise.
         */
        bool removeFlag(unsigned int index);

        /**
         * @brief Add information to associate with the triangle.
         * @param info A pointer to the information to be added.
         * @return True if the information was successfully added, false otherwise.
         */
        bool addInformation(void* info);

        /**
         * @brief Search for specific information associated with the triangle.
         * @param info A pointer to the information to search for.
         * @return The index of the found information if it exists, or -1 if the information is not found.
         */
        int searchInformation(void* info);

        /**
         * @brief Remove specific information associated with the triangle.
         * @param info A pointer to the information to be removed.
         * @return True if the information was successfully removed, false otherwise.
         */
        bool removeInformation(void* info);

        /**
         * @brief Remove information at the specified index associated with the triangle.
         * @param index The index of the information to remove.
         * @return True if the information at the specified index was successfully removed, false otherwise.
         */
        bool removeInformation(unsigned int index);

        /**
         * @brief Clear all associated information from the triangle.
         * @return True if all information was successfully removed, false otherwise.
         */
        bool clearInformation();

        /**
         * @brief Print the triangle information to the specified output stream.
         * @param[out] os The output stream where the triangle information will be printed.
         */
        void print(std::ostream& os);

    protected:
        std::string id;
        std::shared_ptr<Edge> e1;
        std::shared_ptr<Edge> e2;
        std::shared_ptr<Edge> e3;
        std::vector<void*> information;
        std::vector<FlagType> associated_flags;
    };

}

#endif // TRIANGLE_H
