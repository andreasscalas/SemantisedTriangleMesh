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
    enum class DistanceType {SEGMENT_DISTANCE, EUCLIDEAN_DISTANCE, COMBINED_DISTANCE};
    enum class WeightType { Linear, Cotangent };

    class Annotation;

    class TriangleMesh
    {
    public:
        TriangleMesh();
        TriangleMesh(std::shared_ptr<TriangleMesh>);
        ~TriangleMesh();
        unsigned int getVerticesNumber();
        unsigned int getEdgesNumber();
        unsigned int getTrianglesNumber();
        std::shared_ptr<Vertex> addNewVertex();
        std::shared_ptr<Vertex> addNewVertex(double, double, double);
        std::shared_ptr<Vertex> addNewVertex(Point);
        std::shared_ptr<Vertex> addNewVertex(std::shared_ptr<Vertex> );
        std::shared_ptr<Vertex> getVertex(unsigned int);
        std::shared_ptr<Vertex> getVertex(std::string);
        void removeFlaggedVertices();
        bool removeVertex(uint pos);
        bool removeVertex(std::string vid);
        std::shared_ptr<Edge> getEdge(unsigned int);
        std::shared_ptr<Edge> getEdge(std::string);
        std::shared_ptr<Edge> addNewEdge();
        std::shared_ptr<Edge> addNewEdge(std::shared_ptr<Vertex>, std::shared_ptr<Vertex>);
        std::shared_ptr<Edge> addNewEdge(std::shared_ptr<Edge>);
        void removeFlaggedEdges();
        bool removeEdge(uint pos);
        bool removeEdge(std::string eid);
        std::shared_ptr<Triangle> getTriangle(unsigned int);
        std::shared_ptr<Triangle> getTriangle(std::string);
        std::vector<std::shared_ptr<Triangle> > getTriangles(std::vector<std::shared_ptr<Vertex> > vertices);
        std::shared_ptr<Triangle> addNewTriangle();
        std::shared_ptr<Triangle> addNewTriangle(std::shared_ptr<Edge>,std::shared_ptr<Edge>, std::shared_ptr<Edge>);
        std::shared_ptr<Triangle> addNewTriangle(std::shared_ptr<Triangle>);

        bool removeTriangle(uint pos);
        bool removeTriangle(std::string tid);
        void removeFlaggedTriangles();


        int load(std::string filename);
        int save(std::string filename, unsigned int precision = 5);
        unsigned int removeIsolatedVertices();
        int triangulate(std::vector<std::vector<std::shared_ptr<Point> > > &boundaries, std::vector<std::vector<std::shared_ptr<Point> > > &constraints);
        int triangulate(std::vector<std::vector<std::vector<std::shared_ptr<Point> > > > &boundaries, std::vector<std::vector<std::shared_ptr<Point> > > &constraints);
        int triangulate(std::vector<std::vector<std::vector<std::shared_ptr<Vertex> > > > &boundaries, std::vector<std::vector<std::shared_ptr<Vertex> > > &constraints, std::vector<std::shared_ptr<Vertex> > constraintVertices);
        std::shared_ptr<Edge> searchEdgeContainingVertex(std::vector<std::shared_ptr<Edge> > list, std::shared_ptr<Vertex> v);

        /**
         * @brief computeShortestPath approximate version of the famous Dijkstra algorithm for the shortest path computation. The method stops the search for better paths whenever
         * it finds the target vertex v2
         * @param v1 the origin of the path
         * @param v2 the target position of the path
         * @param metric the metric to be used for the distance computation
         * @param avoidUsed if checked, gives &infin; weight to the already used arcs, to avoid intersections
         * @return the shortest path (as list of successive vertices) connecting v1 and v2
         */
        std::vector<std::shared_ptr<Vertex> > computeShortestPath(std::shared_ptr<Vertex> v1, std::shared_ptr<Vertex> v2, const DistanceType metric, const bool directed, const bool avoidUsed);

        const std::vector<std::shared_ptr<Annotation> > &getAnnotations() const;
        void clearAnnotations();
        void setAnnotations(const std::vector<std::shared_ptr<Annotation> > &newAnnotations);
        bool addAnnotation(const std::shared_ptr<Annotation> newAnnotation);
        std::shared_ptr<Annotation> getAnnotation(unsigned int);
        std::shared_ptr<Annotation> getAnnotation(std::string);
        bool removeAnnotation(unsigned int);

        void orientTrianglesCoherently();
        void resetIds();

        void computeProperties();
        double getAABBDiagonalLength();
        double getMinEdgeLength();
        double getMaxEdgeLength();

        std::vector<std::shared_ptr<Vertex> > getNearestNeighbours(Point, uint maxNumber = -1, double radius = 0.0);
        std::shared_ptr<Vertex> getClosestPoint(Point);

        std::vector<std::shared_ptr<Triangle> > regionGrowing(std::vector<std::shared_ptr<Vertex> > contour, std::shared_ptr<Triangle> seed);

        std::vector<std::vector<std::shared_ptr<Vertex > > > getOutlines(std::vector<std::shared_ptr<Triangle> > set);

        void smooth(WeightType type, uint k, double t);

        Point getMin() const;
        Point getMax() const;

        bool addAnnotationsRelationship(std::shared_ptr<Annotation> a1, std::shared_ptr<Annotation> a2, std::string relationshipType, bool directed = false);
        bool removeRelationship(std::shared_ptr<Annotation> a1, std::shared_ptr<Annotation> a2, std::string type = "");


        const std::shared_ptr<GraphTemplate::Graph<std::shared_ptr<Annotation> > > &getRelationshipsGraph() const;
        void setRelationshipsGraph(const std::shared_ptr<GraphTemplate::Graph<std::shared_ptr<Annotation> > > &newRelationshipsGraph);
        void clearRelationships();

    protected:
        std::vector<std::shared_ptr<Vertex> > vertices;
        std::vector<std::shared_ptr<Edge> > edges;
        std::vector<std::shared_ptr<Triangle> > triangles;
        std::vector<std::shared_ptr<Annotation> > annotations;
        std::shared_ptr<KDTree> kdtree;
        Point min, max;
        double minEdgeLength, maxEdgeLength;

        std::shared_ptr<GraphTemplate::Graph<std::shared_ptr<Annotation> > > relationshipsGraph;
        int loadPLY(std::string filename);

        void initialiseKDTree();

        /**
         * @brief extractNearestVertex support method for the Dijkstra algorithm. Given a list of vertices in the frontier, it extracts the "closest" one,
         * in terms of the value contained into the list of distances
         * @param frontier the list of vertices to be checked
         * @param distances the list of distances corresponding to the vertices in frontier
         * @return the closest vertex
         */
        uint extractNearestVertex(std::vector<uint> &frontier, std::map<uint, double> distances);

        /**
         * @brief extractStraightestVertex support method for the Dijkstra algorithm. Given a list of vertices in the frontier, it extracts the one which is most in the direction of the target
         * @param frontier the list of vertices to be checked
         * @param distances the list of distances corresponding to the vertices in frontier
         * @return the closest vertex
         */
        uint extractStraightestVertex(std::vector<uint> &frontier, std::shared_ptr<Vertex> start, Vector direction);
    };

}
#endif // TRIANGLEMESH_H
