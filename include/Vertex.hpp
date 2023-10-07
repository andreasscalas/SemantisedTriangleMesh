#ifndef VERTEX_H
#define VERTEX_H

#include "Point.hpp"
#include "Edge.hpp"
#include "Triangle.hpp"
#include "CommonDefinitions.hpp"
#include <memory>
#include <vector>

namespace SemantisedTriangleMesh {
    class Edge;
    class Triangle;

    /**
     * @class Vertex
     * @brief Represents a vertex in a geometric model.
     *
     * The Vertex class represents a vertex in a geometric model. It can be initialized with different constructors
     * and provides various member functions to access and modify information associated with the vertex.
     */
    class Vertex : public Point
    {
    public:
        /**
         * @brief Vertex default constructor
         */
        Vertex();
        /**
         * @brief Vertex constructor for initialising only coordinates
         * @param x
         * @param y
         * @param z
         */
        Vertex(double x, double y, double z);
        /**
         * @brief Vertex constructor for initialising only coordinates
         * @param p array of coordinates
         */
        Vertex(double p[3]);
        /**
         * @brief Constructor for initializing a vertex with a Point object.
         * @param p The Point object to initialize the vertex with.
         */
        Vertex(Point p);
        /**
         * @brief Constructor for initializing a vertex with a shared pointer to a Point object.
         * @param p A shared pointer to the Point object to initialize the vertex with.
         */
        Vertex(std::shared_ptr<Point> p);
        /**
         * @brief Constructor for initializing a vertex with a shared pointer to another Vertex object.
         * @param v A shared pointer to the Vertex object to initialize the vertex with.
         */
        Vertex(std::shared_ptr<Vertex> v);
        /**
         * @brief Destructor for the Vertex object.
         *
         * The destructor frees any allocated resources for the Vertex object.
         */
        ~Vertex();

        /**
         * @brief Get the ID of the vertex.
         * @return The ID of the vertex as a string.
         */
        std::string getId() const;

        /**
         * @brief Set the ID of the vertex.
         * @param newId The new ID to set for the vertex.
         */
        void setId(std::string newId);

        /**
         * @brief Get the first outgoing edge of the vertex.
         * @return A shared pointer to the first outgoing edge of the vertex.
         */
        std::shared_ptr<Edge> getE0() const;
        /**
         * @brief Set the first outgoing edge of the vertex.
         * @param newE0 A shared pointer to the new first outgoing edge to be set.
         */
        void setE0(std::shared_ptr<Edge> newE0);

        /**
         * @brief Get the information associated with the vertex.
         * @return A constant reference to the vector containing the associated information.
         */
        const std::vector<void *> &getInformation() const;

        /**
         * @brief Set the information associated with the vertex.
         * @param newInformation The vector containing the new information to be associated with the vertex.
         */
        void setInformation(const std::vector<void *> &newInformation);

        /**
         * @brief Get the associated flags of the vertex.
         * @return A constant reference to the vector containing the associated flags.
         */
        const std::vector<FlagType> &getAssociatedFlags() const;

        /**
         * @brief Set the associated flags of the vertex.
         * @param newAssociatedFlags The vector containing the new flags to be associated with the vertex.
         */
        void setAssociatedFlags(const std::vector<FlagType> &newAssociatedFlags);

        /**
         * @brief Get the neighboring vertices of the vertex.
         * @return A vector containing shared pointers to the neighboring vertices.
         */
        std::vector<std::shared_ptr<Vertex> > getVV();

        /**
         * @brief Get the incident edges of the vertex.
         * @return A vector containing shared pointers to the incident edges.
         */
        std::vector<std::shared_ptr<Edge> > getVE();

        /**
         * @brief Get the incident triangles of the vertex.
         * @return A vector containing shared pointers to the incident triangles.
         */
        std::vector<std::shared_ptr<Triangle> > getVT();

        /**
         * @brief Get the common edge shared between this vertex and the specified vertex.
         * @param v A shared pointer to the vertex to find the common edge with.
         * @return A shared pointer to the common edge, or nullptr if none exists.
         */
        std::shared_ptr<Edge> getCommonEdge(std::shared_ptr<Vertex> v);

        /**
         * @brief Compute the normal vector of the vertex.
         * @return The normal vector of the vertex as a Point object.
         */
        Point computeNormal();
        /**
         * @brief Get the neighborhood vertices of the vertex within a specified size.
         * @param size The size of the neighborhood to consider.
         * @return A vector containing shared pointers to the neighboring vertices within the specified size.
         */
        std::vector<std::shared_ptr<Vertex>> getNeighbourhood(uint size);

        /**
         * @brief Add a flag to the associated flags of the vertex.
         * @param flag The flag to add to the associated flags.
         * @return True if the flag was successfully added, false otherwise.
         */
        bool addFlag(FlagType flag);

        /**
         * @brief Search for a specific flag in the associated flags of the vertex.
         * @param flag The flag to search for.
         * @return The index of the found flag if it exists, or -1 if the flag is not found.
         */
        int searchFlag(FlagType flag);

        /**
         * @brief Remove a flag from the associated flags of the vertex.
         * @param flag The flag to remove.
         * @return True if the flag was successfully removed, false otherwise.
         */
        bool removeFlag(FlagType flag);

        /**
         * @brief Remove a flag at the specified index from the associated flags of the vertex.
         * @param index The index of the flag to remove.
         * @return True if the flag at the specified index was successfully removed, false otherwise.
         */
        bool removeFlag(unsigned int index);

        /**
         * @brief Remove all flags from those associated to the vertex.
         */
        void clearFlags();

        /**
         * @brief Add information to associate with the vertex.
         * @param info A pointer to the information to be added.
         * @return True if the information was successfully added, false otherwise.
         */
        bool addInformation(void* info);

        /**
         * @brief Search for specific information associated with the vertex.
         * @param info A pointer to the information to search for.
         * @return The index of the found information if it exists, or -1 if the information is not found.
         */
        int searchInfo(void* info);

        /**
         * @brief Remove specific information associated with the vertex.
         * @param info A pointer to the information to be removed.
         * @return True if the information was successfully removed, false otherwise.
         */
        bool removeInfo(void* info);

        /**
         * @brief Remove information at the specified index associated with the vertex.
         * @param index The index of the information to remove.
         * @return True if the information at the specified index was successfully removed, false otherwise.
         */
        bool removeInfo(unsigned int index);

        /**
         * @brief Clear all associated information from the vertex.
         * @return True if all information was successfully removed, false otherwise.
         */
        bool clearInfo();


        /**
         * @brief Print the vertex information to the specified output stream.
         * @param[out] os The output stream where the vertex information will be printed.
         */
        virtual void print(std::ostream& os);

    protected:
        std::string id;
        std::shared_ptr<Edge> e0;
        std::vector<void*> information;
        std::vector<FlagType> associated_flags;
    };
}
#endif // VERTEX_H
