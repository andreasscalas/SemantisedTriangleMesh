#include "TriangleMesh.hpp"
#include "surfaceannotation.hpp"
#include "pointannotation.hpp"
#include "lineannotation.hpp"
#include "trianglehelper.hpp"
#include <fstream>
#include <sstream>
#include <map>
#include <exception>
#include <queue>
#include <set>


using namespace SemantisedTriangleMesh;

TriangleMesh::TriangleMesh()
{
    relationshipsGraph = std::make_shared<GraphTemplate::Graph<std::shared_ptr<Annotation> > >();
    minEdgeLength = std::numeric_limits<double>::max();
    maxEdgeLength = -std::numeric_limits<double>::max();
}

TriangleMesh::TriangleMesh(const std::shared_ptr<TriangleMesh> &other)
{

    for(uint i = 0; i < other->getVerticesNumber(); i++)
    {
        auto v = other->getVertex(i);
        auto newV = std::make_shared<Vertex>(v->getX(), v->getY(), v->getZ());
        newV->setId(v->getId());
        newV->setInfo(v->getInfo());
        newV->setAssociatedFlags(v->getAssociatedFlags());
        this->vertices.push_back(newV);
    }

    for(uint i = 0; i < other->getEdgesNumber(); i++)
    {
        auto e = other->getEdge(i);
        auto newE = std::make_shared<Edge>();
        newE->setId(e->getId());
        newE->setV1(this->getVertex(e->getV1()->getId()));
        newE->setV2(this->getVertex(e->getV2()->getId()));
        newE->setAssociatedFlags(e->getAssociatedFlags());
        newE->setInformation(e->getInformation());
        this->edges.push_back(newE);
    }

    for(uint i = 0; i < other->getVerticesNumber(); i++)
    {
        auto v = other->getVertex(i);
        if(v->getE0() != nullptr)
        {
            auto newV = this->getVertex(i);
            newV->setE0(this->getEdge(v->getE0()->getId()));
        }
    }

    for(uint i = 0; i < other->getTrianglesNumber(); i++)
    {
        auto t = other->getTriangle(i);
        auto newT = std::make_shared<Triangle>();
        newT->setId(t->getId());
        newT->setE1(this->getEdge(t->getE1()->getId()));
        newT->setE2(this->getEdge(t->getE2()->getId()));
        newT->setE3(this->getEdge(t->getE3()->getId()));
        newT->setAssociatedFlags(t->getAssociatedFlags());
        newT->setInformation(t->getInformation());
        this->triangles.push_back(newT);
    }
    for(uint i = 0; i < other->getEdgesNumber(); i++)
    {
        auto e = other->getEdge(i);
        auto newE = getEdge(i);
        if(e->getT1() == nullptr)
            newE->setT1(nullptr);
        else
            newE->setT1(this->getTriangle(e->getT1()->getId()));
        if(e->getT2() == nullptr)
            newE->setT2(nullptr);
        else
            newE->setT2(this->getTriangle(e->getT2()->getId()));
    }

    for(uint i = 0; i < other->getAnnotations().size(); i++)
    {
        switch(other->getAnnotation(i)->getType())
        {
            case AnnotationType::Point:
            {
                auto a = std::dynamic_pointer_cast<PointAnnotation>(other->getAnnotation(i));
                annotations.push_back(std::make_shared<PointAnnotation>(this, a));
                break;
            }
            case AnnotationType::Line:
            {
                auto a = std::dynamic_pointer_cast<LineAnnotation>(other->getAnnotation(i));
                annotations.push_back(std::make_shared<LineAnnotation>(this, a));
                break;
            }
            case AnnotationType::Surface:
            {
                auto a = std::dynamic_pointer_cast<SurfaceAnnotation>(other->getAnnotation(i));
                annotations.push_back(std::make_shared<SurfaceAnnotation>(this, a));
                break;
            }
            default :
            {
                std::cout << "This kind of annotation is still to be implemented" << std::endl;
                exit(44);
            }
        }

    }
    minEdgeLength = other->getMinEdgeLength();
    maxEdgeLength = other->getMaxEdgeLength();

}

TriangleMesh::~TriangleMesh()
{

    for(unsigned int i = 0; i < vertices.size(); i++)
        if(vertices.at(i) != nullptr)
            vertices.at(i).reset();
    for(unsigned int i = 0; i < edges.size(); i++)
        if(edges.at(i) != nullptr)
            edges.at(i).reset();
    for(unsigned int i = 0; i < triangles.size(); i++)
        if(triangles.at(i) != nullptr)
            triangles.at(i).reset();
}

unsigned int TriangleMesh::getVerticesNumber()
{
    return vertices.size();
}

unsigned int TriangleMesh::getEdgesNumber()
{
    return edges.size();
}

unsigned int TriangleMesh::getTrianglesNumber()
{
    return triangles.size();
}

std::shared_ptr<Vertex> TriangleMesh::addNewVertex()
{
    vertices.push_back(std::make_shared<Vertex>());
    return vertices.back();
}

std::shared_ptr<Vertex> TriangleMesh::addNewVertex(double x, double y, double z)
{
    vertices.push_back(std::make_shared<Vertex>(x, y, z));
    return vertices.back();
}

std::shared_ptr<Vertex> TriangleMesh::addNewVertex(Point p)
{
    std::shared_ptr<Vertex> v = addNewVertex(p.getX(), p.getY(), p.getZ());
    v->setInfo(p.getInfo());
    return v;
}

std::shared_ptr<Vertex> TriangleMesh::addNewVertex(std::shared_ptr<Vertex> v)
{
    auto it = std::find_if(vertices.begin(), vertices.end(), [v](std::shared_ptr<Vertex> v1){
            auto p1 = *v;
            auto p2 = *v1;
            p1.setZ(0);
            p2.setZ(0);
            return p1 == p2;
    });
    if(it != vertices.end()) //La gestione delle strade che intersecano boundary interni dati da unione di edifici è lasciata da parte
    {
        return *it;
    }
    vertices.push_back(v);
    return vertices.back();
}

std::shared_ptr<Vertex> TriangleMesh::getVertex(uint pos)
{
    if(pos >= vertices.size())
        return nullptr;
    return vertices.at(pos);
}

std::shared_ptr<Vertex> TriangleMesh::getVertex(std::string id)
{
    return getVertex(stoi(id));
}

void TriangleMesh::removeFlaggedVertices()
{
    std::vector<std::shared_ptr<Vertex> > newVertices;
    for(auto it = vertices.begin(); it != vertices.end(); it++)
        if((*it)->searchFlag(FlagType::TO_BE_REMOVED) < 0)
        {
            newVertices.push_back((*it));
        }
    vertices.clear();
    vertices = newVertices;
}

bool TriangleMesh::removeVertex(uint pos)
{
    if(pos >= vertices.size())
        return false;

    vertices.erase(vertices.begin() + pos);
    return true;
}

bool TriangleMesh::removeVertex(std::string vid)
{
    for(auto vit = vertices.begin(); vit != vertices.end(); vit++)
        if((*vit)->getId().compare(vid) == 0)
        {
            vit = vertices.erase(vit);
            return true;
        }
    return true;
}

std::shared_ptr<Edge> TriangleMesh::getEdge(uint pos)
{
    if(pos >= edges.size())
        return nullptr;
    return edges.at(pos);
}

std::shared_ptr<Edge> TriangleMesh::getEdge(std::string id)
{
    return getEdge(stoi(id));
}

std::shared_ptr<Triangle> TriangleMesh::getTriangle(uint pos)
{
    if(pos >= triangles.size())
        return nullptr;
    return triangles.at(pos);
}

std::shared_ptr<Triangle> TriangleMesh::getTriangle(std::string id)
{
    return getTriangle(stoi(id));
}

std::vector<std::shared_ptr<Triangle> > TriangleMesh::getTriangles(std::vector<std::shared_ptr<Vertex> > vertices)
{
    std::vector<std::shared_ptr<Triangle> > correspondingTriangles;
    for(auto t : triangles)
        t->removeFlag(FlagType::USED);

    for(auto v : vertices)
    {
        auto vt = v->getVT();
        for(auto t : vt)
            if(t->searchFlag(FlagType::USED) == -1)
            {
                triangles.push_back(t);
                t->addFlag(FlagType::USED);
            }
    }
    for(auto t : triangles)
        t->removeFlag(FlagType::USED);

    return triangles;
}

std::shared_ptr<Edge> TriangleMesh::addNewEdge()
{
    edges.push_back(std::make_shared<Edge>());
    return edges.back();
}

std::shared_ptr<Edge> TriangleMesh::addNewEdge(std::shared_ptr<Vertex> v1, std::shared_ptr<Vertex> v2)
{
    edges.push_back(std::make_shared<Edge>(v1, v2));
    return edges.back();
}

std::shared_ptr<Edge> TriangleMesh::addNewEdge(std::shared_ptr<Edge> e)
{
    edges.push_back(std::make_shared<Edge>(e));
    return edges.back();
}

void TriangleMesh::removeFlaggedEdges()
{
    std::vector<std::shared_ptr<Edge> > newEdges;
    for(auto it = edges.begin(); it != edges.end(); it++)
        if((*it)->searchFlag(FlagType::TO_BE_REMOVED) < 0)
        {
            newEdges.push_back((*it));
        }
    edges.clear();
    edges = newEdges;
}

bool TriangleMesh::removeEdge(uint pos)
{
    if(pos >= edges.size())
        return false;

    edges.erase(edges.begin() + pos);
    return true;
}

bool TriangleMesh::removeEdge(std::string eid)
{
    for(auto eit = edges.begin(); eit != edges.end(); eit++)
        if((*eit)->getId().compare(eid) == 0)
        {
            eit = edges.erase(eit);
            return true;
        }
    return false;
}

std::shared_ptr<Triangle> TriangleMesh::addNewTriangle()
{
    triangles.push_back(std::make_shared<Triangle>());
    return triangles.back();
}

std::shared_ptr<Triangle> TriangleMesh::addNewTriangle(std::shared_ptr<Edge> e1, std::shared_ptr<Edge> e2, std::shared_ptr<Edge> e3)
{
    triangles.push_back(std::make_shared<Triangle>(e1, e2, e3));
    return triangles.back();
}

std::shared_ptr<Triangle> TriangleMesh::addNewTriangle(std::shared_ptr<Triangle> t)
{
    triangles.push_back(std::make_shared<Triangle>(t));
    return triangles.back();
}

bool TriangleMesh::removeTriangle(uint pos)
{
        if(pos > triangles.size())
            return false;
        triangles.erase(triangles.begin() + pos);
        return true;
}

bool TriangleMesh::removeTriangle(std::string tid)
{
    for(auto tit = triangles.begin(); tit != triangles.end(); tit++)
        if((*tit)->getId().compare(tid) == 0)
        {
            tit = triangles.erase(tit);
            return true;
        }
    return false;
}

void TriangleMesh::removeFlaggedTriangles()
{
    std::vector<std::shared_ptr<Triangle> > newTriangles;
    for(auto it = triangles.begin(); it != triangles.end(); it++)
        if((*it)->searchFlag(FlagType::TO_BE_REMOVED) < 0)
        {
            newTriangles.push_back((*it));
        }
    triangles.clear();
    triangles = newTriangles;
}

bool TriangleMesh::addAnnotationsRelationship(std::shared_ptr<Annotation> a1, std::shared_ptr<Annotation> a2, std::string relationshipType, bool directed)
{

    auto n1 = relationshipsGraph->getNodeFromData(a1);
    auto n2 = relationshipsGraph->getNodeFromData(a2);
    char* relType = new char[relationshipType.length() + 1];
    strcpy(relType, relationshipType.c_str());
    auto a = new GraphTemplate::Arc<std::shared_ptr<Annotation> >(
                n1, n2, 1, directed, static_cast<unsigned int>(relationshipsGraph->getArcs().size()), relType);
    relationshipsGraph->addArc(a);
    return true;
}

bool TriangleMesh::removeRelationship(std::shared_ptr<Annotation> a1, std::shared_ptr<Annotation> a2, std::string type)
{
    auto n1 = relationshipsGraph->getNodeFromData(a1);
    auto n2 = relationshipsGraph->getNodeFromData(a2);
    if(n1 == nullptr || n2 == nullptr)
        return false;
    auto rels = relationshipsGraph->getArcsFromEndpoints(n1, n2, type);
    for(auto rel : rels)
        relationshipsGraph->removeArc(rel);
    return true;
}

const std::shared_ptr<GraphTemplate::Graph<std::shared_ptr<Annotation> > > &TriangleMesh::getRelationshipsGraph() const
{
    return relationshipsGraph;
}

void TriangleMesh::setRelationshipsGraph(const std::shared_ptr<GraphTemplate::Graph<std::shared_ptr<Annotation> > > &newRelationshipsGraph)
{
    relationshipsGraph = newRelationshipsGraph;
}

void TriangleMesh::clearRelationships()
{
    relationshipsGraph->clearArcs();
}


int TriangleMesh::load(std::string filename)
{
    if(filename.compare("") == 0)
        return -std::numeric_limits<int>::max();
    int retValue = loadPLY(filename);
    if(retValue == 0)
    {
        orientTrianglesCoherently();
        computeProperties();
        initialiseKDTree();
    }

    return retValue;
}

int TriangleMesh::save(std::string filename, unsigned int precision)
{

    orientTrianglesCoherently();
    std::cout << "Saving " << filename  << std::endl;
    int return_code;
    std::ofstream meshStream(filename);
    std::string format = filename.substr(filename.find(".") + 1);
    meshStream.precision(precision);
    if(meshStream.is_open())
    {
        if(format.compare("ply") == 0)
        {
            std::cout << "Writing as PLY" << std::endl;
            meshStream << "ply" << std::endl;
            meshStream << "format ascii 1.0" << std::endl;
            meshStream << "element vertex " << getVerticesNumber() << std::endl;
            meshStream << "property double x" << std::endl;
            meshStream << "property double y" << std::endl;
            meshStream << "property double z" << std::endl;
            meshStream << "element face " << getTrianglesNumber() << std::endl;
            meshStream << "property list uchar int vertex_indices" << std::endl;
            meshStream << "end_header" << std::endl;
            std::cout << "Writing vertices:" << std::endl;
            for(unsigned int i = 0; i < getVerticesNumber(); i++)
            {
                meshStream << vertices.at(i)->getX() << " " << vertices.at(i)->getY() << " " << vertices.at(i)->getZ() << std::endl;
                if(i % 100 == 0)
                    std::cout << i * 100 / getVerticesNumber() << "%\r" << std::flush;
            }

            std::cout << "Ended! Written " << getVerticesNumber() << " vertices." << std::endl << "Writing triangles:" << std::endl;
            for(unsigned int i = 0; i < getTrianglesNumber(); i++)
            {

                auto v1 = triangles.at(i)->getV1();
                auto v2 = triangles.at(i)->getV2();
                auto v3 = triangles.at(i)->getV3();
                meshStream << "3 " << v1->getId() << " " << v2->getId() << " " << v3->getId() << std::endl;

                if(i % 100 == 0)
                    std::cout << i * 100 / getTrianglesNumber() << "%\r" << std::flush;
            }
            std::cout << "Ended! Written " << getTrianglesNumber() << " triangles." << std::endl;
            return_code = 0;
        } else if(format.compare("xyz") == 0)
        {
            std::cout << "Writing as XYZ" << std::endl;

            for(uint i = 0; i < getVerticesNumber(); i++)
                meshStream << getVertex(i)->getX() << " " << getVertex(i)->getY() << " " << getVertex(i)->getZ() << std::endl;
            std::cout << "Ended! Written " << getVerticesNumber() << " points" << std::endl;
            return_code = 0;
        }else
            return_code = 1;


        meshStream.close();
    } else
        return_code = -1;
    return return_code;
}

unsigned int TriangleMesh::removeIsolatedVertices()
{
    uint numberOfRemovedVertices = vertices.size();
    for(uint i = 0; i < vertices.size(); i++)
        if(vertices.at(i)->getE0() == nullptr)
        {
            vertices.erase(vertices.begin() + i);
            i--;
        }
    numberOfRemovedVertices -= vertices.size();
    return numberOfRemovedVertices;
}

std::shared_ptr<Edge> TriangleMesh::searchEdgeContainingVertex(std::vector<std::shared_ptr<Edge> > list, std::shared_ptr<Vertex> v)
{
    for(unsigned int i = 0; i < list.size(); i++)
        if(list.at(i)->hasVertex(v))
            return list.at(i);

    return nullptr;
}

uint TriangleMesh::extractNearestVertex(std::vector<uint> &frontier, std::map<uint, double> distances)
{

    double minDist = std::numeric_limits<double>::max();
    int minPos = -1;
    for(unsigned int i = 0; i < frontier.size(); i++){
        if(distances.at(frontier.at(i)) < minDist){
            minPos = i;
            minDist = distances.at(frontier.at(i));
        }
    }

    if(minPos == -1)
        return minPos;

    uint nearest = frontier.at(minPos);

    frontier.erase(frontier.begin() + minPos);

    return nearest;

}

uint TriangleMesh::extractStraightestVertex(std::vector<uint> &frontier, std::shared_ptr<Vertex> start, Vector direction)
{
    double minAngle = std::numeric_limits<double>::max();
    int minPos = -1;
    direction.normalise();
    for(unsigned int i = 0; i < frontier.size(); i++){
        auto newDirection = (*vertices.at(frontier.at(i)) ) - (*start);
        newDirection.normalise();
        double angle = direction.computeAngle(newDirection);
        if(angle < minAngle)
        {
            minAngle = angle;
            minPos = i;
        }
    }

    if(minPos == -1)
        return minPos;

    uint nearest = frontier.at(minPos);

    frontier.erase(frontier.begin() + minPos);

    return nearest;
}

std::vector<std::shared_ptr<Vertex> > TriangleMesh::computeShortestPath(std::shared_ptr<Vertex> v1, std::shared_ptr<Vertex> v2, const DistanceType metric, const bool directed, const bool avoidUsed)
{
    std::vector<uint> frontier;
    std::map<uint, double> distances = {{std::stoi(v1->getId()), 0}};
    std::map<uint, std::shared_ptr<Vertex> > predecessors = {{std::stoi(v1->getId()), nullptr}};
    std::set<uint> v21RingNeighbors;
    std::vector<std::shared_ptr<Vertex> > shortestPath;
    std::shared_ptr<Vertex> v = nullptr;
    bool v2visited = false;

    if(((*v1) - (*v2)).norm() == 0.0){
        return shortestPath;
    }

    frontier.push_back(std::stoi(v1->getId()));

    do {
        uint vid;
        if(directed && v != nullptr)
            vid = extractStraightestVertex(frontier, v, (*v2) - (*v));
        else
            vid = extractNearestVertex(frontier, distances);

        if(vid == -1)
        {
            return shortestPath;
        }

        v = this->getVertex(vid);
        if(v == nullptr)
        {
            return shortestPath;
        }

        auto neighbors = v->getVV();
        for(auto n : neighbors){

            auto vit = v21RingNeighbors.find(std::stoi(v->getId()));
            if(n->getId().compare(v2->getId()) == 0 && vit == v21RingNeighbors.end())
                v21RingNeighbors.insert(std::stoi(v->getId()));

            auto pit = predecessors.find(std::stoi(n->getId()));
            double distanceVX;
            if(!avoidUsed || n->searchFlag(FlagType::USED) == -1){
                switch(metric){
                    case DistanceType::SEGMENT_DISTANCE:
                        distanceVX = distances.at(std::stoi(v->getId())) + n->computePointSegmentDistance(*v1, *v2);
                        break;
                    case DistanceType::COMBINED_DISTANCE:
                        distanceVX = distances.at(std::stoi(v->getId())) + (*n - *v).norm() + n->computePointSegmentDistance(*v1, *v2);
                        break;
                    default:
                        distanceVX = distances.at(std::stoi(v->getId())) + (*n - *v).norm();
                }
            } else
                distanceVX = std::numeric_limits<double>::max();

            if(pit != predecessors.end()){
                if(distances.at(std::stoi(n->getId())) > distanceVX){
                    distances.at(std::stoi(n->getId())) = distanceVX;
                    predecessors.at(std::stoi(n->getId())) = v;
                }
            } else {
                distances.insert(std::make_pair(std::stoi(n->getId()), distanceVX));
                predecessors.insert(std::make_pair(std::stoi(n->getId()), v));
                frontier.push_back(std::stoi(n->getId()));
            }
        }
        if(v == v2)
            v2visited = true;

    } while(!v2visited);

    shortestPath.push_back(v2);
    v = predecessors.at(std::stoi(v2->getId()));
    while(v != v1){
        shortestPath.insert(shortestPath.begin(), v);
        v = predecessors.at(std::stoi(v->getId()));
    }

    return shortestPath;
}

const std::vector<std::shared_ptr<Annotation> > &TriangleMesh::getAnnotations() const
{
    return annotations;
}

void TriangleMesh::clearAnnotations()
{
    annotations.clear();
}

void TriangleMesh::setAnnotations(const std::vector<std::shared_ptr<Annotation> > &newAnnotations)
{
    annotations = newAnnotations;
    if(relationshipsGraph == nullptr)
        return;
    for(auto ann : annotations)
        relationshipsGraph->addNode(ann);
}

bool TriangleMesh::addAnnotation(const std::shared_ptr<Annotation> newAnnotation)
{
    if(newAnnotation == nullptr)
        return false;
    auto id = newAnnotation->getId();
    try {
        uint pos = std::stoi(id);
        annotations.insert(annotations.begin() + pos, newAnnotation);
    } catch (std::exception &err) {
        annotations.push_back(newAnnotation);
    }

    try {
        relationshipsGraph->addNode(newAnnotation);
    } catch (std::exception &err)
    {
        std::cout << err.what() << std::endl;
    }

    return true;
}

std::shared_ptr<Annotation> TriangleMesh::getAnnotation(unsigned int id)
{
    if(id < 0 || id >= annotations.size())
        return nullptr;
    return annotations.at(id);
}

std::shared_ptr<Annotation> TriangleMesh::getAnnotation(std::string id)
{
    for(auto a : annotations)
        if(a->getId().compare(id) == 0)
            return a;
    return nullptr;
}

bool TriangleMesh::removeAnnotation(unsigned int id)
{
    if(id >= annotations.size())
        return false;
    auto a = annotations.at(id);
    annotations.erase(annotations.begin() + id);
    if(relationshipsGraph == nullptr)
        return true;
    auto n = relationshipsGraph->getNodeFromData(a);
    auto outgoingRelationships = relationshipsGraph->getArcsFromFletching(n);
    auto incomingRelationships = relationshipsGraph->getArcsFromTip(n);
    outgoingRelationships.insert(outgoingRelationships.end(), incomingRelationships.begin(), incomingRelationships.end());
    for(auto r : outgoingRelationships)
    {
        relationshipsGraph->removeArc(r);
        delete r;
    }

    relationshipsGraph->removeNode(n);

    delete n;

    return true;
}

bool TriangleMesh::removeAnnotation(std::string id)
{
    for(uint i = 0; i < annotations.size(); i++)
    {
        auto a = annotations.at(i);
        if(a->getId().compare(id) == 0)
            removeAnnotation(i);
        return true;
    }

    return false;
}

void TriangleMesh::orientTrianglesCoherently()
{
    std::shared_ptr<Triangle> t = triangles[0];
    std::queue<std::shared_ptr<Triangle> > q;
    for(uint i = 0; i < triangles.size(); i++)
        triangles[i]->removeFlag(FlagType::VISITED);
    t->addFlag(FlagType::VISITED);
    q.push(t);
    while(!q.empty())
    {
        t = q.front();
        q.pop();
        std::shared_ptr<Edge> e = t->getE1();
        for(uint i = 0; i < 3; i++)
        {
            auto t_ = e->getOppositeTriangle(t);
            if(t_ != nullptr)
            {
                if(t_->searchFlag(FlagType::VISITED) < 0)
                {
                    if(!t->isCoherentlyOriented(t_))
                        t_->orient();
                    t_->addFlag(FlagType::VISITED);
                    q.push(t_);
                }

            }
            e = t->getNextEdge(e);
        }
    }

    for(uint i = 0; i < triangles.size(); i++)
        triangles[i]->removeFlag(FlagType::VISITED);

}

void TriangleMesh::resetIds()
{
    for(uint i = 0; i < getVerticesNumber(); i++)
        getVertex(i)->setId(std::to_string(i));
    for(uint i = 0; i < getEdgesNumber(); i++)
        getEdge(i)->setId(std::to_string(i));
    for(uint i = 0; i < getTrianglesNumber(); i++)
        getTriangle(i)->setId(std::to_string(i));
}

void TriangleMesh::computeProperties()
{

    min.setX(std::numeric_limits<double>::max());
    min.setY(std::numeric_limits<double>::max());
    min.setZ(std::numeric_limits<double>::max());
    max.setX(-std::numeric_limits<double>::max());
    max.setY(-std::numeric_limits<double>::max());
    max.setZ(-std::numeric_limits<double>::max());

    for(auto v : vertices)
    {
        if(v->getX() < min.getX())
            min.setX(v->getX());
        if(v->getY() < min.getY())
            min.setY(v->getY());
        if(v->getZ() < min.getZ())
            min.setZ(v->getZ());
        if(v->getX() > max.getX())
            max.setX(v->getX());
        if(v->getY() > max.getY())
            max.setY(v->getY());
        if(v->getZ() > max.getZ())
            max.setZ(v->getZ());
    }

    for(auto e : edges)
    {
        double length = e->computeLength();
        if(length < minEdgeLength)
            minEdgeLength = length;
        if(length > maxEdgeLength)
            maxEdgeLength = length;
    }


}

double TriangleMesh::getAABBDiagonalLength()
{
    return (min - max).norm();
}

double TriangleMesh::getMinEdgeLength()
{
    return minEdgeLength;
}

double TriangleMesh::getMaxEdgeLength()
{
    return maxEdgeLength;
}

std::vector<std::shared_ptr<Vertex> > TriangleMesh::getNearestNeighbours(Point queryPt, uint maxNumber, double radius)
{
    if(kdtree == nullptr)
        initialiseKDTree();
    std::vector<double> point = {queryPt.getX(), queryPt.getY(), queryPt.getZ()};
    std::vector<std::pair<size_t, double> > neighbors_distances;
    std::vector<std::shared_ptr<Vertex> > neighbors;

    neighbors_distances.clear();
    std::vector<size_t> neighbors_indices = kdtree->neighborhood_indices(point, radius);
    for(auto it = neighbors_indices.begin(); it != neighbors_indices.end(); it++){
        neighbors.push_back(vertices.at(*it));
    }

    return neighbors;

}

std::shared_ptr<Vertex> TriangleMesh::getClosestPoint(Point queryPt)
{
    if(kdtree == nullptr)
        initialiseKDTree();
    std::vector<double> point = {queryPt.getX(), queryPt.getY(), queryPt.getZ()};
    auto index = kdtree->nearest_index(point);
    return vertices.at(index);
}

std::vector<std::shared_ptr<Triangle> > TriangleMesh::regionGrowing(std::vector<std::shared_ptr<Vertex> > contour, std::shared_ptr<Triangle> seed)
{

    std::queue<std::shared_ptr<Triangle> > neighbors;
    std::vector<std::shared_ptr<Triangle> > internalTriangles;

    neighbors.push(seed);

    for(unsigned int i = 1; i <= static_cast<unsigned int>(contour.size()); i++){

        std::shared_ptr<Vertex> v1, v2;
        if(i < contour.size()){
            v1 = contour[i - 1];
            v2 = contour[i];
        }else{
            v1 = contour[i - 1];
            v2 = contour[0];
        }

        auto e = v1->getCommonEdge(v2);
        if(e != nullptr)
            e->addFlag(FlagType::ON_BOUNDARY);
    }


    while(neighbors.size() > 0){
        auto t = neighbors.front();
        neighbors.pop();
        auto e = t->getE1();
        for(int i = 0; i < 3; i++){
            if(e->searchFlag(FlagType::ON_BOUNDARY) == -1){
                auto t_ = e->getOppositeTriangle(t);
                if(t_->searchFlag(FlagType::USED) == -1){
                    internalTriangles.push_back(t_);
                    t_->addFlag(FlagType::USED);
                    neighbors.push(t_);
                }
            }
            e = t->getNextEdge(e);
        }
    }

    for(unsigned int i = 1; i <= static_cast<unsigned int>(contour.size()); i++){

        std::shared_ptr<Vertex> v1, v2;
        if(i < contour.size()){
            v1 = contour[i - 1];
            v2 = contour[i];
        }else{
            v1 = contour[i - 1];
            v2 = contour[0];
        }

        auto e = v1->getCommonEdge(v2);
        if(e != nullptr)
            e->removeFlag(FlagType::ON_BOUNDARY);
    }

    for(auto it = internalTriangles.begin(); it != internalTriangles.end(); it++)
        (*it)->removeFlag(FlagType::USED);


    return internalTriangles;

}

std::vector<std::vector<std::shared_ptr<Vertex> > > TriangleMesh::getOutlines(std::vector<std::shared_ptr<Triangle> > set)
{

    std::vector<std::pair<std::shared_ptr<Vertex>, std::shared_ptr<Vertex> > > setOutlineEdges;
    std::vector<std::vector<std::shared_ptr<Vertex> > > outlines;
    std::shared_ptr<Vertex> v, v_;

    for(auto tit = set.begin(); tit != set.end(); tit++)
        (*tit)->addFlag(FlagType::INSIDE);

    for(auto tit = set.begin(); tit != set.end(); tit++){
        auto t = *tit;
        auto e = t->getE1();
        for(int i = 0; i < 3; i++){
            auto t_ = e->getOppositeTriangle(t);
            if(t_->searchFlag(FlagType::INSIDE) == -1){
                auto e_ = t->getPreviousEdge(e);
                v = e_->getCommonVertex(e);
                setOutlineEdges.push_back(std::make_pair(v, e->getOppositeVertex(v)));
            }
            e = t->getNextEdge(e);
        }
    }

    while(setOutlineEdges.size() != 0){

        std::vector<std::shared_ptr<Vertex> > outline;
        v = setOutlineEdges[0].first;
        auto initialVertex = v;

        std::pair<std::shared_ptr<Vertex>, std::shared_ptr<Vertex> > pPrev = std::make_pair(nullptr, nullptr);
        do{
            outline.push_back(v);
            for(auto v_ : v->getVV()){
                auto p = std::make_pair(v, v_);
                for(auto pit = setOutlineEdges.begin(); pit != setOutlineEdges.end(); pit++){
                    auto tmp = *pit;
                    if(p != pPrev &&
                       ((p.first == tmp.second && p.second == tmp.first) ||
                       (p.first == tmp.second && p.second == tmp.first)) ){
                        v = v_;
                        pPrev = p;
                        setOutlineEdges.erase(pit);
                        break;
                    }
                }

                if(v == v_)
                    break;
            }
        }while(v != initialVertex);
        outline.push_back(outline[0]);
        outlines.push_back(outline);
    }

    for(auto oit = outlines.begin(); oit != outlines.end(); oit++){
        auto outline = *oit;
        std::shared_ptr<Triangle> t = nullptr;
        for (unsigned int i = 1; i < outline.size(); i++) {
            t = outline[i - 1]->getCommonEdge(outline[i])->getLeftTriangle(outline[i - 1]);
            if(t != nullptr)
                break;
        }
        if(t == nullptr || std::find(set.begin(), set.end(), t) == set.end())
            std::reverse(oit->begin(), oit->end());
    }

    for(auto tit = set.begin(); tit != set.end(); tit++){
        (*tit)->removeFlag(FlagType::INSIDE);
    }

    return outlines;

}

double cotan(const Point& a, const Point& b)
{
    return (a * b) / (EPSILON + (a & b).norm());
}

double compute_cotan_weight(std::shared_ptr<Vertex> vi, std::shared_ptr<Vertex> vj)
{
    auto e = vi->getCommonEdge(vj);
    auto t1 = e->getLeftTriangle(vi);
    auto t2 = e->getRightTriangle(vi);
    std::shared_ptr<Vertex> next, prev;
    Point v1, v2, v3, v4;
    double cotan_alpha = 0.0, cotan_beta = 0.0;
    if(t1 != nullptr)
    {
        next = t1->getNextVertex(vj);
        v3 = (*vi) - (*next);
        v4 = (*vj) - (*next);
        cotan_beta = cotan(v3, v4);
    }
    if(t2 != nullptr)
    {
        prev = t2->getNextVertex(vi);
        v1 = (*vi) - (*prev);
        v2 = (*vj) - (*prev);
        cotan_alpha = cotan(v1, v2);
    }


    double wij = cotan_alpha + cotan_beta;
    if(isnan(wij))
        wij = 0.0;
    double cotan_max = cos(EPSILON) / sin(EPSILON);
    wij = std::clamp(wij, -cotan_max, cotan_max);
    return wij;
}

void TriangleMesh::smooth(WeightType type, uint k, double t)
{
    for(uint i = 0; i < k; i++)
    {
        std::vector<Point> newPositions;
        for(auto vi : vertices)
        {
            std::vector<double> edges_weights;
            double area = 0.0, weights_sum = 0.0;
            auto vv = vi->getVV();
            Point laplacian(0,0,0);
            for(auto vj : vv)
            {
                double wij = 1.0;
                if(type == WeightType::Cotangent)
                    wij = compute_cotan_weight(vi, vj);

                edges_weights.push_back(wij);
                laplacian += *vj * wij;
                weights_sum += wij;
            }

            newPositions.push_back((laplacian / weights_sum) * t + *vi * (1.0 - t));
        }

        for(uint i = 0; i < vertices.size(); i++)
            vertices[i]->setPosition(newPositions[i]);
    }

}

Point TriangleMesh::getMin() const
{
    return min;
}

Point TriangleMesh::getMax() const
{
    return max;
}

int TriangleMesh::triangulate(std::vector<std::vector<std::vector<std::shared_ptr<Vertex> > > > &boundaries, std::vector<std::vector<std::shared_ptr<Vertex> > > &constraints, std::vector<std::shared_ptr<Vertex> > constraintVertices)
{
    if(boundaries.size() < 1)
        return -1;

    std::vector<double*> points;
    std::vector<std::vector<unsigned int> > polylines;
    std::map<std::shared_ptr<Vertex>, std::vector<std::shared_ptr<Edge> > > vertices_edges;
    unsigned int vertices_id = vertices.size();
    unsigned int edges_id = edges.size();
    unsigned int triangles_id = triangles.size();
    /**The first boundary is the exterior boundary**/

    std::vector<unsigned int> exterior_boundary_polyline;

    for(unsigned int i = 0; i < boundaries.at(0).at(0).size(); i++)
    {
        std::vector<std::shared_ptr<Edge> > incident;
        addNewVertex(boundaries.at(0).at(0).at(i));
        points.push_back(boundaries.at(0).at(0).at(i)->toDoubleArray());
        exterior_boundary_polyline.push_back(vertices_id);
        vertices.back()->setId(std::to_string(vertices_id++));
        vertices_edges.insert(std::make_pair(vertices.back(), incident));
    }
    exterior_boundary_polyline.push_back(0);
    polylines.push_back(exterior_boundary_polyline);

    /**The remaining boundaries are holes**/
    std::vector<double*> holes_seeds;


    std::cout << "Fixing repeated nodes" << std::endl;
    for(unsigned int i = 1; i < boundaries.size(); i++)
    {
        std::vector<std::shared_ptr<Vertex> > outline = boundaries.at(i).at(0);

        double v[2] = {(outline[1]->getX() - outline[0]->getX()) * 1E-2, (outline[1]->getY() - outline[0]->getY()) * 1E-2};
        double vec[2] = {-v[1], v[0]};
        double middle[2] = {(outline[1]->getX() + outline[0]->getX()) / 2, (outline[1]->getY() + outline[0]->getY()) / 2};
        double* innerpoint = new double(2);
        innerpoint[0] = vec[0] + middle[0];
        innerpoint[1] = vec[1] + middle[1];

        holes_seeds.push_back(innerpoint);

        for(unsigned int j = 0; j < boundaries.at(i).size(); j++)
        {
            unsigned int counter = 0;
            std::vector<unsigned int> polyline;
            for(unsigned int k = 0; k < boundaries.at(i).at(j).size() - 1; k++)
            {
                std::vector<std::shared_ptr<Vertex> >::iterator it = std::find_if(vertices.begin(), vertices.end(),
                          [boundaries, i, j, k](std::shared_ptr<Vertex> p)
                {
                    auto p1 = *boundaries.at(i).at(j).at(k);
                    auto p2 = *p;
                    p1.setZ(0);
                    p2.setZ(0);

                    return  p1 == p2;
                });

                if(it != vertices.end())
                {
                    counter++;
                    *boundaries.at(i).at(j).at(k) = **it;
                }

                if(it == vertices.end())
                {
                    std::vector<std::shared_ptr<Edge> > incident;
                    addNewVertex(boundaries.at(i).at(j).at(k));
                    points.push_back(boundaries.at(i).at(j).at(k)->toDoubleArray());
                    boundaries.at(i).at(j).at(k)->setId(std::to_string(vertices_id++));
                    vertices_edges.insert(std::make_pair(boundaries.at(i).at(j).at(k), incident));
                } else if(k > 0 && *boundaries.at(i).at(j).at(k) == *boundaries.at(i).at(j).at(k - 1))
                {
                    std::cerr << "Boundary must be clean at this point." << std::endl;
                    exit(88);
                }

                polyline.push_back(static_cast<unsigned int>(std::stoi(boundaries.at(i).at(j).at(k)->getId())));
            }

            *boundaries.at(i).at(j).back() = *boundaries.at(i).at(j).at(0);

            polyline.push_back(static_cast<unsigned int>(std::stoi(boundaries.at(i).at(j).at(0)->getId())));
            polylines.push_back(polyline);

        }
    }

    for(unsigned int i = 0; i < constraints.size(); i++)
    {
        std::vector<unsigned int> polyline;
        for(unsigned int j = 0; j < constraints.at(i).size(); j++)
        {
            std::vector<std::shared_ptr<Vertex> >::iterator it = std::find_if(vertices.begin(), vertices.end(),
                      [constraints, i, j](std::shared_ptr<Vertex> p)
            {
                auto p1 = *constraints.at(i).at(j);
                auto p2 = *p;
                p1.setZ(0);
                p2.setZ(0);
                return *constraints.at(i).at(j) == *p;
            });

            if(it != vertices.end())
            {
                std::shared_ptr<Vertex> tmp = constraints.at(i).at(j);
                *constraints.at(i).at(j) = **it;
                tmp.reset();
            }

            if(it == vertices.end())
            {
                std::vector<std::shared_ptr<Edge> > incident;
                addNewVertex(constraints.at(i).at(j));
                points.push_back(constraints.at(i).at(j)->toDoubleArray());
                constraints.at(i).at(j)->setId(std::to_string(vertices_id++));
                vertices_edges.insert(std::make_pair(constraints.at(i).at(j), incident));
            }
            polyline.push_back(static_cast<unsigned int>(std::stoi(constraints.at(i).at(j)->getId())));
        }
        polylines.push_back(polyline);
    }

    for(auto v : constraintVertices)
    {
        std::vector<std::shared_ptr<Edge> > incident;
        vertices.push_back(v);
        v->setId(std::to_string(vertices_id++));
        vertices_edges.insert(std::make_pair(v, incident));
        points.push_back(v->toDoubleArray());
    }
    std::cout << "Ended" << std::endl;
    uint noDEMPointsNumber = points.size();
    std::cout << "Starting triangulation " << std::endl;
    TriHelper::TriangleHelper helper(points, polylines, holes_seeds, true);

    for(auto p : points)
        delete p;

    std::vector<unsigned int> generated_triangles = helper.getTriangles();
    //std::vector<double*> generated_points = helper.getAddedPoints();
    std::vector<double*> generated_points(helper.getPoints().begin() + noDEMPointsNumber, helper.getPoints().end());
    for(unsigned int i = 0; i < generated_points.size(); i++)
    {
        std::vector<std::shared_ptr<Edge> > incident;
        std::shared_ptr<Vertex> v = addNewVertex(generated_points.at(i)[0], generated_points.at(i)[1], 0/*generated_points.at(i)[2]*/);
        v->setId(std::to_string(vertices_id++));
        vertices_edges.insert(std::make_pair(vertices.back(), incident));
    }

    std::cout << "Ended! Created " << generated_triangles.size() / 3 << " triangles." << std::endl << "Building mesh structure:" << std::endl;
    for(unsigned int i = 0; i < generated_triangles.size() / 3; i++)
    {
        unsigned int v1 = generated_triangles.at(i * 3), v2 = generated_triangles.at(i * 3 + 1), v3 = generated_triangles.at(i * 3 + 2);
        std::shared_ptr<Edge> e1, e2, e3;

        e1 = searchEdgeContainingVertex(vertices_edges.at(vertices.at(v1)), vertices.at(v2));
        if(e1 == nullptr)
            e1 = searchEdgeContainingVertex(vertices_edges.at(vertices.at(v2)), vertices.at(v1));
        if(e1 == nullptr)
        {
            addNewEdge(vertices.at(v1), vertices.at(v2));
            e1 = edges.back();
            e1->setId(std::to_string(edges_id++));
            vertices_edges.at(vertices.at(v1)).push_back(e1);
        }
        vertices.at(v1)->setE0(e1);
        e2 = searchEdgeContainingVertex(vertices_edges.at(vertices.at(v2)), vertices.at(v3));
        if(e2 == nullptr)
            e2 = searchEdgeContainingVertex(vertices_edges.at(vertices.at(v3)), vertices.at(v2));
        if(e2 == nullptr)
        {
            addNewEdge(vertices.at(v2), vertices.at(v3));
            e2 = edges.back();
            e2->setId(std::to_string(edges_id++));
            vertices_edges.at(vertices.at(v2)).push_back(e2);
        }
        vertices.at(v2)->setE0(e2);
        e3 = searchEdgeContainingVertex(vertices_edges.at(vertices.at(v3)), vertices.at(v1));
        if(e3 == nullptr)
            e3 = searchEdgeContainingVertex(vertices_edges.at(vertices.at(v1)), vertices.at(v3));
        if(e3 == nullptr)
        {
            addNewEdge(vertices.at(v3), vertices.at(v1));
            e3 = edges.back();
            e3->setId(std::to_string(edges_id++));
            vertices_edges.at(vertices.at(v3)).push_back(e3);
        }
        vertices.at(v3)->setE0(e3);

        addNewTriangle(e1, e2, e3);
        triangles.back()->setId(std::to_string(triangles_id++));
        if(e1->getT1() == nullptr)
           e1->setT1(triangles.back());
        else if(e1->getT2() == nullptr)
            e1->setT2(triangles.back());
        else
            return 9;
        if(e2->getT1() == nullptr)
            e2->setT1(triangles.back());
        else if(e2->getT2() == nullptr)
            e2->setT2(triangles.back());
        else
            return 9;
        if(e3->getT1() == nullptr)
            e3->setT1(triangles.back());
        else if(e3->getT2() == nullptr)
            e3->setT2(triangles.back());
        else
            return 9;

        if(i % 100 == 0)
            std::cout << i * 100 / generated_triangles.size() << "%\r" << std::flush;;

    }

    std::cout << "Ended!" << std::endl;
    return 0;
}

int TriangleMesh::loadPLY(std::string filename)
{
    std::ifstream fileStream(filename);

    if(fileStream.is_open())
    {
        unsigned int vertices_number = 0;
        unsigned int triangles_number = 0;
        unsigned int reached_vertex_id = 0;
        unsigned int reached_edge_id = 0;
        unsigned int reached_triangle_id = 0;
        std::map<std::shared_ptr<Vertex>, std::vector<std::shared_ptr<Edge> > > vertices_edges;
        std::string line;
        std::getline(fileStream, line);
        if(line.compare("ply") != 0)
        {
            std::cerr << "Current implementation only deals with PLY file format!" << std::endl;
            fileStream.close();
            return 1;
        }
        std::getline(fileStream, line);
        if(line.compare("format ascii 1.0") == 0)
        {
            while(std::getline(fileStream, line) && line.substr(0, 7).compare("comment") == 0); //removing all comments
            if(line.substr(0, 14).compare("element vertex") != 0)
            {
                std::cerr << "File has to start with vertices specification!" << std::endl;
                fileStream.close();
                return 2;
            }
            vertices_number = stoi(line.substr(15, line.size() - 15));
            while(std::getline(fileStream, line) && line.substr(0, 7).compare("comment") == 0); //removing all comments
            if(line.substr(0, 8).compare("property") != 0)
            {
                std::cerr << "X coordinate format needs to be specified!" << std::endl;
                fileStream.close();
                return 3;
            }
            while(std::getline(fileStream, line) && line.substr(0, 7).compare("comment") == 0); //removing all comments
            if(line.substr(0, 8).compare("property") != 0)
            {
                std::cerr << "Y coordinate format needs to be specified!" << std::endl;
                fileStream.close();
                return 3;
            }
            while(std::getline(fileStream, line) && line.substr(0, 7).compare("comment") == 0); //removing all comments
            if(line.substr(0, 8).compare("property") != 0)
            {
                std::cerr << "Z coordinate format needs to be specified!" << std::endl;
                fileStream.close();
                return 3;
            }
            while(std::getline(fileStream, line) &&
                  (line.substr(0, 7).compare("comment") == 0 ||
                   line.compare("property uchar red") == 0 ||
                   line.compare("property uchar green") == 0 ||
                   line.compare("property uchar blue") == 0 ||
                   line.compare("property uchar alpha") == 0)); //removing all comments and unuseful things
            if(line.substr(0, 12).compare("element face") != 0)
            {
                std::cerr << "After vertices specification there must be faces specification!" << std::endl;
                fileStream.close();
                return 4;
            }
            triangles_number = stoi(line.substr(13, line.size() - 13));
            while(std::getline(fileStream, line) && line.substr(0, 7).compare("comment") == 0); //removing all comments
            if(line.compare("property list uchar int vertex_indices") != 0)
            {
                std::cerr << "Current implementation only manages faces defined as \"property list uchar int vertex_indices\"" << std::endl;
                fileStream.close();
                return 5;
            }
            while(std::getline(fileStream, line) &&
                  (line.substr(0, 7).compare("comment") == 0 ||
                   line.compare("property list uchar float texcoord") == 0 ||
                   line.compare("property uchar red") == 0 ||
                   line.compare("property uchar green") == 0 ||
                   line.compare("property uchar blue") == 0 ||
                   line.compare("property uchar alpha") == 0)); //removing all comments
            if(line.compare("end_header") != 0)
            {
                std::cerr << "At this point the header must be closed." << std::endl;
                fileStream.close();
                return 6;
            }
            std::cout << "Loading vertices: " << std::endl;
            for(unsigned int i = 0; i < vertices_number; i++)
            {
                if(!std::getline(fileStream, line))
                {
                    fileStream.close();
                    return 7;
                }
                std::stringstream sstream(line);
                double x, y, z;
                sstream >> x;
                sstream >> y;
                sstream >> z;
                std::shared_ptr<Vertex> v = addNewVertex(x, y, z);
                v->setId(std::to_string(reached_vertex_id++));
                std::vector<std::shared_ptr<Edge> > incident;
                vertices_edges.insert(std::make_pair(v, incident));
                if(i % 100 == 0)
                    std::cout << i * 100 / vertices_number << "%\r" << std::flush;
            }
            std::cout << "Ended! Loaded " << vertices_number << " vertices." << std::endl << "Loading triangles:" << std::endl;
            for(unsigned int i = 0; i < triangles_number; i++)
            {
                if(!std::getline(fileStream, line))
                {
                    std::cerr << "Unexpected end of file." << std::endl;
                    fileStream.close();
                    return 8;
                }
                std::stringstream sstream(line);
                unsigned int polyVertNum;
                unsigned int v1, v2, v3;
                std::shared_ptr<Edge> e1, e2, e3;
                sstream >> polyVertNum;
                sstream >> v1;
                sstream >> v2;
                sstream >> v3;

                e1 = searchEdgeContainingVertex(vertices_edges.at(vertices.at(v1)), vertices.at(v2));
                if(e1 == nullptr)
                    e1 = searchEdgeContainingVertex(vertices_edges.at(vertices.at(v2)), vertices.at(v1));
                if(e1 == nullptr)
                {
                    addNewEdge(vertices.at(v1), vertices.at(v2));
                    e1 = edges.back();
                    e1->setId(std::to_string(reached_edge_id++));
                    vertices_edges.at(vertices.at(v1)).push_back(e1);
                }
                vertices.at(v1)->setE0(e1);
                e2 = searchEdgeContainingVertex(vertices_edges.at(vertices.at(v2)), vertices.at(v3));
                if(e2 == nullptr)
                    e2 = searchEdgeContainingVertex(vertices_edges.at(vertices.at(v3)), vertices.at(v2));
                if(e2 == nullptr)
                {
                    addNewEdge(vertices.at(v2), vertices.at(v3));
                    e2 = edges.back();
                    e2->setId(std::to_string(reached_edge_id++));
                    vertices_edges.at(vertices.at(v2)).push_back(e2);
                }
                vertices.at(v2)->setE0(e2);
                e3 = searchEdgeContainingVertex(vertices_edges.at(vertices.at(v3)), vertices.at(v1));
                if(e3 == nullptr)
                    e3 = searchEdgeContainingVertex(vertices_edges.at(vertices.at(v1)), vertices.at(v3));
                if(e3 == nullptr)
                {
                    addNewEdge(vertices.at(v3), vertices.at(v1));
                    e3 = edges.back();
                    e3->setId(std::to_string(reached_edge_id++));
                    vertices_edges.at(vertices.at(v3)).push_back(e3);
                }
                vertices.at(v3)->setE0(e3);

                addNewTriangle(e1, e2, e3);
                triangles.back()->setId(std::to_string(reached_triangle_id++));
                if(e1->getT1() == nullptr)
                   e1->setT1(triangles.back());
                else if(e1->getT2() == nullptr)
                    e1->setT2(triangles.back());
                else
                {
                    fileStream.close();
                    return 9;
                }
                if(e2->getT1() == nullptr)
                    e2->setT1(triangles.back());
                else if(e2->getT2() == nullptr)
                    e2->setT2(triangles.back());
                else
                {
                    fileStream.close();
                    return 9;
                }
                if(e3->getT1() == nullptr)
                    e3->setT1(triangles.back());
                else if(e3->getT2() == nullptr)
                    e3->setT2(triangles.back());
                else
                {
                    fileStream.close();
                    return 9;
                }

                if(i % 100 == 0)
                    std::cout << i * 100 / triangles_number << "%\r" << std::flush;;

            }
            std::cout << "Ended! Loaded " << triangles_number << " triangles." << std::endl;

        } else
        {
            std::cerr << "This file format is currently not supported" << std::endl;
            return 10;
        }
        fileStream.close();
        return 0;
    }
    else
        return -1;

}

void TriangleMesh::initialiseKDTree()
{
    if(kdtree != nullptr)
        kdtree.reset();
    std::vector<std::vector<double> > pointsVector;
    for(auto v : vertices)
    {
        std::vector<double> point = {v->getX(), v->getY(), v->getZ()};
        pointsVector.push_back(point);
    }
    kdtree = std::make_shared<KDTree>(pointsVector);
}
