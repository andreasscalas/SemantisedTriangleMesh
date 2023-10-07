#ifndef TRIANGLEMESH_H
#define TRIANGLEMESH_H

#include "Vertex.hpp"
#include "Edge.hpp"
#include "Triangle.hpp"
#include "annotation.hpp"
#include "graph.hpp"
#include <memory>
#include <KDTree.hpp>
#include <map>

namespace SemantisedTriangleMesh {

    const double EPSILON = 1e-6;
    //Enumeration of distance metrics used for shortest path computation
    enum class DistanceType {SEGMENT_DISTANCE, EUCLIDEAN_DISTANCE, COMBINED_DISTANCE};
    //Enumeration of laplacian weights for smoothing
    enum class WeightType { Linear, Cotangent };

    //Forward declaration to avoid cyclic dependencies issues
    class Annotation;

    /**
     * @brief The TriangleMesh class allows to manage 3D triangle meshes.
     */
    class TriangleMesh
    {
    public:
        //Default constructor
        TriangleMesh();
        //Copy-constructor (copies attributes values)
        TriangleMesh(const std::shared_ptr<TriangleMesh>&);
        //Default destructor
        ~TriangleMesh();

        /**
         * @brief getVerticesNumber method that returns the number of vertices defining the mesh
         * @return the number of vertices
         */
        unsigned int getVerticesNumber();
        /**
         * @brief getEdgesNumber method that returns the number of edges defining the mesh
         * @return the number of edges
         */
        unsigned int getEdgesNumber();
        /**
         * @brief getTrianglesNumber method that returns the number of triangles defining the mesh
         * @return the number of triangles
         */
        unsigned int getTrianglesNumber();

        /**
         * @brief addNewVertex method that adds a new vertex to the mesh without initialization.
         * @return the added vertex
         */
        std::shared_ptr<Vertex> addNewVertex();

        /**
         * @brief addNewVertex method that adds a new vertex to the mesh initializing its spatial coordinates.
         * @return the added vertex
         */
        std::shared_ptr<Vertex> addNewVertex(double, double, double);

        /**
         * @brief addNewVertex method that adds a new vertex to the mesh copying the attributes defined by the parameter
         * @param p the point from which attributes will be copied
         * @return the added vertex
         */
        std::shared_ptr<Vertex> addNewVertex(Point p);

        /**
         * @brief addNewVertex method that adds a new vertex to the mesh copying the attributes defined by the parameter
         * @param v the point from which attributes will be copied
         * @return the added vertex
         */
        std::shared_ptr<Vertex> addNewVertex(std::shared_ptr<Vertex> v);

        /**
         * @brief getVertex method that returns a vertex positionally (should be removed, users shouldn't know the mechanisms of the class)
         * @param position positive value referring to the position inside the vertices array
         * @return nullptr if the vertex does not exist (parameter higher than number of vertices), otherwise a pointer to the found vertex
         */
        std::shared_ptr<Vertex> getVertex(uint position);

        /**
         * @brief getVertex method that returns a vertex by id.
         * @param vid string id of the vertex (represents a number)
         * @return nullptr if the vertex does not exist (vid not found in vertices list), otherwise a pointer to the found vertex
         */
        std::shared_ptr<Vertex> getVertex(std::string vid);

        /**
         * @brief removeFlaggedVertices method that remove vertices that have been flagged as FlagType::TO_BE_REMOVED
         */
        void removeFlaggedVertices();

        /**
         * @brief removeVertex method that remove a vertex positionally (should be removed, users shouldn't know the mechanisms of the class)
         * @param pos positive value referring to the position inside the vertices array
         * @return false if the vertex does not exist (pos higher than vertices number), true otherwise
         */
        bool removeVertex(uint pos);

        /**
         * @brief removeVertex method that remove a vertex by id.
         * @param vid string id of the vertex (represents a number)
         * @return false if the vertex does not exist (vid not found in vertices list), true otherwise
         */
        bool removeVertex(std::string vid);

        /**
         * @brief getEdge method that returns an edge positionally (should be removed, users shouldn't know the mechanisms of the class)
         * @param position positive value referring to the position inside the edges array
         * @return nullptr if the edge does not exist (parameter higher than number of edges), otherwise a pointer to the found edge
         */
        std::shared_ptr<Edge> getEdge(uint position);

        /**
         * @brief getEdge method that returns an edge by id.
         * @param eid string id of the edge (represents a number)
         * @return nullptr if the edge does not exist (eid not found in edges list), otherwise a pointer to the found edge
         */
        std::shared_ptr<Edge> getEdge(std::string eid);

        /**
         * @brief addNewEdge method that adds a new edge to the mesh without initialization
         * @return the added edge
         */
        std::shared_ptr<Edge> addNewEdge();

        /**
         * @brief addNewEdge method that adds a new edge between the vertices passed as parameter to the mesh
         * @param v1 first vertex of the edge
         * @param v2 second vertex of the edge
         * @return the added edge
         */
        std::shared_ptr<Edge> addNewEdge(std::shared_ptr<Vertex> v1, std::shared_ptr<Vertex> v2);

        /**
         * @brief addNewEdge method that adds a new edge initializing its attribute using the parameter
         * @param e the edge from which attributes will be copied
         * @return the added edge
         */
        std::shared_ptr<Edge> addNewEdge(std::shared_ptr<Edge> e);

        /**
         * @brief removeFlaggedEdges method that remove edges that have been flagged as FlagType::TO_BE_REMOVED
         */
        void removeFlaggedEdges();

        /**
         * @brief removeEdge method that remove a edge positionally (should be removed, users shouldn't know the mechanisms of the class)
         * @param pos positive value referring to the position inside the edges array
         * @return false if the edge does not exist (pos higher than edges number), true otherwise
         */
        bool removeEdge(uint pos);

        /**
         * @brief removeEdge method that remove a edge by id.
         * @param eid string id of the edge (represents a number)
         * @return false if the edge does not exist (vid not found in edges list), true otherwise
         */
        bool removeEdge(std::string eid);

        /**
         * @brief getTriangle method that returns a triangle positionally (should be removed, users shouldn't know the mechanisms of the class)
         * @param position positive value referring to the position inside the triangles array
         * @return nullptr if the triangle does not exist (parameter higher than number of triangles), otherwise a pointer to the found triangle
         */
        std::shared_ptr<Triangle> getTriangle(uint position);

        /**
         * @brief getTriangle method that returns a triangle by id.
         * @param tid string id of the triangle (represents a number)
         * @return nullptr if the triangle does not exist (tid not found in triangles list), otherwise a pointer to the found triangle
         */
        std::shared_ptr<Triangle> getTriangle(std::string tid);


        /**
         * @brief getTriangle method that returns an triangle by the vertices defining it.
         * @param v1 the first vertex
         * @param v2 the second vertex
         * @param v3 the third vertex
         * @return nullptr if the triangle does not exist, otherwise a pointer to the found triangle
         */
        std::shared_ptr<Triangle> getTriangle(std::shared_ptr<Vertex> v1,
                                              std::shared_ptr<Vertex> v2,
                                              std::shared_ptr<Vertex> v3);

        /**
         * @brief getTriangles method that compiles a list of triangles composed by the vertices contained in the parameter list (at least one vertex).
         * @param vertices a list of vertices from which the triangles are taken
         * @return the produced list of triangles.
         */
        std::vector<std::shared_ptr<Triangle> > getTriangles(std::vector<std::shared_ptr<Vertex> > vertices);

        /**
         * @brief addNewTriangle method that adds a new triangle without initialization
         * @return the added triangle
         */
        std::shared_ptr<Triangle> addNewTriangle();

        /**
         * @brief addNewTriangle method that adds a new triangle defined by the edges passed as parameters
         * @param e1 first edge of the triangle
         * @param e2 second edge of the triangle
         * @param e3 third edge of the triangle
         * @return the added triangle
         */
        std::shared_ptr<Triangle> addNewTriangle(std::shared_ptr<Edge> e1, std::shared_ptr<Edge> e2, std::shared_ptr<Edge> e3);


        /**
         * @brief addNewTriangle method that adds a new triangle initializing its attribute using the parameter
         * @param t the triangle from which attributes will be copied
         * @return the added triangle
         */
        std::shared_ptr<Triangle> addNewTriangle(std::shared_ptr<Triangle> t);


        /**
         * @brief removeTriangle method that remove a triangle positionally (should be removed, users shouldn't know the mechanisms of the class)
         * @param pos positive value referring to the position inside the triangles array
         * @return false if the triangle does not exist (pos higher than triangles number), true otherwise
         */
        bool removeTriangle(uint pos);

        /**
         * @brief removeTriangle method that remove a triangle by id.
         * @param tid string id of the triangle (represents a number)
         * @return false if the triangle does not exist (vid not found in triangles list), true otherwise
         */
        bool removeTriangle(std::string tid);

        /**
         * @brief removeFlaggedTriangles method that remove triangles that have been flagged as FlagType::TO_BE_REMOVED
         */
        void removeFlaggedTriangles();

        /**
         * @brief load method for loading a triangular 3D mesh. Currently only ascii-based ply file are supported.
         * @param filename the complete filepath of the mesh file
         * @return 0 if no error occurred during loading, other values define a specific error (list will be produced in the future)
         */
        int load(std::string filename);

        /**
         * @brief save method for saving a triangular 3D mesh. Currently only ascii-based ply file are supported.
         * @param filename the complete filepath of the mesh file
         * @param precision number of decimal numbers to be used when saving the vertices coordinates
         * @return 0 if no error occurred during saving, other values define a specific error (list will be produced in the future)
         */
        int save(std::string filename, unsigned int precision = 5);

        /**
         * @brief removeIsolatedVertices method for removing vertices that aren't connected to any edge.
         * @return the number of removed vertices.
         */
        unsigned int removeIsolatedVertices();

        /**
         * @brief triangulate method for triangulating (in 2 dimensions) the area defined by a set of boundaries' lists (the first one should contain all the others), so that
         * it satisfies a set of constraints (defined as polylines or single points
         * @param boundaries the set of boundaries' lists.
         * @param constraints the set of polylines to be inserted in the triangulation
         * @param constraintVertices the set of vertices to be inserted in the triangulation
         * @return 0 if no error occurred during the triangulation, other values define a specific error (list will be produced in the future)
         */
        int triangulate(std::vector<std::vector<std::vector<std::shared_ptr<Vertex> > > > &boundaries, std::vector<std::vector<std::shared_ptr<Vertex> > > &constraints, std::vector<std::shared_ptr<Vertex> > constraintVertices);

        /**
         * @brief searchEdgeContainingVertex method that searches for the first edge containing a certain vertex in a certain list
         * @param list the list of edges
         * @param v the vertex
         * @return the found edge or nullptr if no edge has been found.
         */
        std::shared_ptr<Edge> searchEdgeContainingVertex(std::vector<std::shared_ptr<Edge> > list, std::shared_ptr<Vertex> v);

        /**
         * @brief computeShortestPath approximate version of the famous Dijkstra algorithm for the shortest path computation. The method stops the search for better paths whenever
         * it finds the target vertex v2
         * @param v1 the origin of the path
         * @param v2 the target position of the path
         * @param metric the metric to be used for the distance computation
         * @param avoidUsed if checked, gives &infin; weight to the already used arcs, to avoid intersections
         * @param directed if checked allows to reduce computation time choosing vertices in the frontier that are closer to the target in an Euclidean way
         * (doesn't work well with very geodesically distant target vertices in high curvature meshes)
         * @return the shortest path (as list of successive vertices) connecting v1 and v2
         */
        std::vector<std::shared_ptr<Vertex> > computeShortestPath(std::shared_ptr<Vertex> v1, std::shared_ptr<Vertex> v2, const DistanceType metric, const bool useHeight, const bool directed, const bool avoidUsed);

        /**
         * @brief getAnnotations getter method for the annotations associated to the mesh.
         * @return the list of annotations of the mesh.
         */
        const std::vector<std::shared_ptr<Annotation> > &getAnnotations() const;

        /**
         * @brief clearAnnotations method for clearing the annotations list.
         */
        void clearAnnotations();

        /**
         * @brief setAnnotations setter method for the annotations list
         * @param newAnnotations the set of list to be associated to the mesh.
         */
        void setAnnotations(const std::vector<std::shared_ptr<Annotation> > &newAnnotations);

        /**
         * @brief addAnnotation method for associating a new annotation to the mesh.
         * @param newAnnotation the new annotation
         * @return true if no error occurred, false otherwise.
         */
        bool addAnnotation(const std::shared_ptr<Annotation> newAnnotation);

        /**
         * @brief getAnnotation getter method based on position for a certain annotation in the list
         * @param position the position in which the annotation is stored
         * @return the found annotation or nullptr if the position is out-of-bounds
         */
        std::shared_ptr<Annotation> getAnnotation(uint position);

        /**
         * @brief getAnnotation getter method based on id for a certain annotation in the list
         * @param id the id of the annotation to be returned
         * @return the found annotation or nullptr if no annotation with the required id has been found.
         */
        std::shared_ptr<Annotation> getAnnotation(std::string id);

        /**
         * @brief removeAnnotation method for removing a certain annotation from the list
         * @param pos the position of the annotation in the list
         * @return false if pos is out-of-bounds, true otherwise
         */
        bool removeAnnotation(uint pos);

        /**
         * @brief removeAnnotation method for removing a certain annotation from the list
         * @param id the id of the annotation to be removed
         * @return false if no annotation in the list has the defined id, true otherwise
         */
        bool removeAnnotation(std::string id);

        /**
         * @brief orientTrianglesCoherently method for orienting the triangles coherently based on normal direction
         */
        void orientTrianglesCoherently();

        /**
         * @brief resetIds method for resetting the ids so that they respect the position in the lists
         */
        void resetIds();

        /**
         * @brief computeProperties method for explicitly requesting the computation of some useful properties (BB, minEdgeLength, etc.). I'm considering its removal
         */
        void computeProperties();

        /**
         * @brief getNearestNeighbours method for searching for the maxNumber nearest neighbours to a query point p inside a certain sphere with a certain radius
         * @param p the query point
         * @param maxNumber optional parameter for limiting the number of neighbours to be returned
         * @param radius optional parameter for taking only the vertices beneath a certain distance
         * @return the list of selected vertices
         */
        std::vector<std::shared_ptr<Vertex> > getNearestNeighbours(Point p, uint maxNumber = -1, double radius = 0.0);

        /**
         * @brief getClosestPoint method for searching for the maxNumber nearest neighbours inside a certain sphere with a certain radius
         * I'm considering to merge this method with getNearestNeighbours
         * @param p the query point
         * @return the closest vertex
         */
        std::shared_ptr<Vertex> getClosestPoint(const Point& p);

        std::vector<std::shared_ptr<Vertex> > getVerticesCloseToLine(const Point& a, const Point& b, double threshold = 0.0);

        /**
         * @brief regionGrowing method for applying a region growing on the mesh's surface inside a contour given a seed triangle
         * @param contour the contour
         * @param seed the seed triangle
         * @return the list of selected triangles
         */
        std::vector<std::shared_ptr<Triangle> > regionGrowing(std::vector<std::shared_ptr<Vertex> > contour, std::shared_ptr<Triangle> seed);

        /**
         * @brief getOutlines method for extract the boundaries of a set of triangles defining one or more areas (sort of the inverse of region growing)
         * @param set the set of triangles
         * @return the outline(s), defined as list of lists of successive vertices
         */
        std::vector<std::vector<std::shared_ptr<Vertex > > > getOutlines(std::vector<std::shared_ptr<Triangle> > set);

        /**
         * @brief smooth method for smoothing the mesh using Laplacian smooth. Currently mean weights and Cotangent weights are supported.
         * @param type
         * @param iterations
         * @param step
         */
        void smooth(WeightType type, uint iterations, double step);

        /**
         * @brief getMin getter method for the min corner of the AABB (minX, minY, minZ)
         * @return the corner Point
         */
        Point getMin() const;

        /**
         * @brief getMax getter method for the max corner of the AABB (maxX, maxY, maxZ)
         * @return the corner Point
         */
        Point getMax() const;

        /**
         * @brief addAnnotationsRelationship add an arc to the annotations relationships graph. Relations between more than two annotations can
         * be defined as a set of one ore more relations between two annotations.
         * @param a1 the first annotation of the relation
         * @param a2 the second annotation of the relation
         * @param relationshipType the type of the relation (currently can be free text)
         * @param directed true if the arc is directed, false otherwise.
         * @return
         */
        bool addAnnotationsRelationship(std::shared_ptr<Annotation> a1, std::shared_ptr<Annotation> a2, std::string relationshipType, bool directed = false);

        /**
         * @brief removeRelationship method for removing an arc from the relationships graph. The arc is found as the one connecting two nodes containing
         * the parameter annotations as data and with a certain type
         * @param a1 the first annotation
         * @param a2 the second annotation
         * @param type the relation's type, as defined when inserting it in the graph
         * @return true if an arc has been removed, false otherwise
         */
        bool removeRelationship(std::shared_ptr<Annotation> a1, std::shared_ptr<Annotation> a2, std::string type = "");

        /**
         * @brief getRelationshipsGraph getter method for the relationships graph.
         * @return the graph.
         */
        const std::shared_ptr<GraphTemplate::Graph<std::shared_ptr<Annotation> > > &getRelationshipsGraph() const;

        /**
         * @brief setRelationshipsGraph setter method for the relationships graph.
         * @return the graph.
         */
        void setRelationshipsGraph(const std::shared_ptr<GraphTemplate::Graph<std::shared_ptr<Annotation> > > &newRelationshipsGraph);

        /**
         * @brief clearRelationships method for resetting the relationships graph
         */
        void clearRelationships();

        /**
         * @brief getAABBDiagonalLength getter for the AABB's diagonal length
         * @return the diagonal length
         */
        double getAABBDiagonalLength();

        /**
         * @brief minEdgeLength getter for the length of the shortest edge in the mesh
         * @return the length
         */
        double getMinEdgeLength();

        /**
         * @brief maxEdgeLength getter for the length of the longest edge in the mesh
         * @return the length
         */
        double getMaxEdgeLength();

    protected:
        /**
         * @brief vertices the list of vertices composing the triangle mesh
         */
        std::vector<std::shared_ptr<Vertex> > vertices;
        /**
         * @brief edges the list of edges composing the triangle mesh
         */
        std::vector<std::shared_ptr<Edge> > edges;

        /**
         * @brief triangles the list of triangles composing the triangle mesh
         */
        std::vector<std::shared_ptr<Triangle> > triangles;

        /**
         * @brief annotations the list of annotations associated to the mesh
         */
        std::vector<std::shared_ptr<Annotation> > annotations;

        /**
         * @brief kdtree data structure for speeding up spatial queries
         */
        std::shared_ptr<KDTree> kdtree;

        /**
         * @brief min, max min and max corner of the AABB, meaning the points with, respectively, lowest and highest X, Y and Z value
         */
        Point min, max;

        /**
         * @brief minEdgeLength, maxEdgeLength attributes keeping track of the length of, respectively, the shortest and the longest edges of the mesh
         */
        double minEdgeLength, maxEdgeLength;

        /**
         * @brief relationshipsGraph graph encoding the relations among annotations of the mesh
         */
        std::shared_ptr<GraphTemplate::Graph<std::shared_ptr<Annotation> > > relationshipsGraph;

        /**
         * @brief loadPLY method for loading the mesh from a .ply file.
         * @param filename the complete file path
         * @return error code, 0 if no error occurred. Other values define a specific error (list will be produced in the future)
         */
        int loadPLY(std::string filename);

        /**
         * @brief initialiseKDTree method for explicitly requesting the initialisation of the kd-tree
         */
        void initialiseKDTree();

        /**
         * @brief extractNearestVertex support method for the Dijkstra algorithm. Given a list of vertices in the frontier, it extracts the "closest" one,
         * in terms of the value contained into the list of distances
         * @param frontier the list of vertices to be checked
         * @param distances the list of distances corresponding to the vertices in frontier
         * @return the closest vertex
         */
        int extractNearestVertex(std::vector<uint> &frontier, std::map<uint, double> distances);

        /**
         * @brief extractStraightestVertex support method for the Dijkstra algorithm. Given a list of vertices in the frontier, it extracts the one which is most in the direction of the target
         * @param frontier the list of vertices to be checked
         * @param start the previous vertex (for computing direction)
         * @param direction the vector defining the direction
         * @return the closest vertex
         */
        int extractStraightestVertex(std::vector<uint> &frontier, std::shared_ptr<Vertex> start, Vector direction);
    };

}
#endif // TRIANGLEMESH_H
