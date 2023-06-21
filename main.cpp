#include <iostream>
#include <fstream>
#include <annotationfilemanager.hpp>
#include "TriangleMesh.hpp"
#include "trianglehelper.hpp"
#include "quadtree.hpp"

using namespace SemantisedTriangleMesh;
const int MAX_VALUE = 10000;
int main(int argc, char* argv[])
{
////    std::vector<Point*> points;
////    bool ended = false;
////    double x, y;
////    srand(time(nullptr));
////    for(uint i = 0; i < MAX_VALUE; i++)
////    {
////        x = rand() % MAX_VALUE - MAX_VALUE / 2;
////        y = rand() % MAX_VALUE - MAX_VALUE / 2;
////        auto point = new Point(x, y, 0);
////        points.push_back(point);

////    }

////    std::vector<Node<void*>* > nodes;
////    for(auto point : points)
////    {
////        auto n = new Node<void*>(*point, static_cast<void*>(nullptr));
////        nodes.push_back(n);
////    }

////    auto root = new QuadTree<void*>();
////    root->setTopLeft(Point(-MAX_VALUE / 2,MAX_VALUE / 2,0));
////    root->setWidth(MAX_VALUE);
////    root->setHeight(MAX_VALUE);
////    root->setMaxNodes(4);
////    std::ofstream stream("prova.txt");
////    stream << "A=[" << std::endl;
////    for(auto node : nodes)
////    {
////        node->getPos().print(stream, BracketsType::NONE, " ");
////        root->insert(node);
////    }
////    stream << "];" << std::endl;
////    stream << std::endl;
////    root->drawForMatlab(stream);
////    stream << std::endl;
////    do
////    {
////        std::cout << "Insert query point coordinates separated with a space or press q and enter to close application" << std::endl;
////        std::cin >> x;
////        std::cin >> y;
////        if(std::cin.good())
////        {
////            auto point = new Point(x, y, 0);
////            auto node = new Node<void*>(*point,  static_cast<void*>(nullptr));
////            auto closest = root->getClosest(node);
////            closest->getPos().print(std::cout);
////            std::cout << std::endl;
////            delete node;
////        } else
////            break;

////    } while(true);

////    for(auto point : points)
////        delete point;
////    for(auto node : nodes)
////        delete node;
////    delete root;

////    if(argc < 2)
////        return -1;

//    std::shared_ptr<TriangleMesh> mesh = std::make_shared<TriangleMesh>();
//    int retValue = mesh->load(argv[1]);
//    if(retValue == 0)
//    {
//        double max_length = -std::numeric_limits<double>::max();
//        double mean_length = 0;
//        double min_z = std::numeric_limits<double>::max();
//        double max_z = -std::numeric_limits<double>::max();
//        for(uint i = 0; i < mesh->getVerticesNumber(); i++)
//        {
//            if(mesh->getVertex(i)->getZ() < min_z)
//                min_z = mesh->getVertex(i)->getZ();
//            if(mesh->getVertex(i)->getZ() > max_z)
//                max_z = mesh->getVertex(i)->getZ();
//        }

//        for(uint i = 0; i < mesh->getEdgesNumber(); i++)
//        {
//            auto l = mesh->getEdge(i)->computeLength();
//            if(l > max_length)
//                max_length = l;
//            mean_length += l;
//        }
//        mean_length /= mesh->getEdgesNumber();


//        for(uint i = 0; i < mesh->getEdgesNumber(); i++)
//        {
//            auto e = mesh->getEdge(i);

//            if(e->computeLength() < 0.5 && e->searchFlag(FlagType::TO_BE_REMOVED) == -1)
//            {
//                e->collapse();
//            }
//        }

//        mesh->removeFlaggedVertices();
//        mesh->removeFlaggedEdges();
//        mesh->removeFlaggedTriangles();
//        mesh->resetIds();
////        std::shared_ptr<Vertex> minxminy = mesh->getVertex(0), minxmaxy = mesh->getVertex(0), maxxminy = mesh->getVertex(0), maxxmaxy = mesh->getVertex(0);
////        for(uint i = 0; i < mesh->getVerticesNumber(); i++)
////        {
////            auto v = mesh->getVertex(i);
////            if(v->getX() <= minxminy->getX() && v->getY() <= minxminy->getY())
////                minxminy = v;
////            if(v->getX() <= minxmaxy->getX() && v->getY() >= minxmaxy->getY())
////                minxmaxy = v;
////            if(v->getX() >= maxxminy->getX() && v->getY() <= maxxminy->getY())
////                maxxminy = v;
////            if(v->getX() >= maxxmaxy->getX() && v->getY() >= maxxmaxy->getY())
////                maxxmaxy = v;
////        }
////        minxminy->setZ(1000);
////        minxmaxy->setZ(1000);
////        maxxminy->setZ(1000);
////        maxxmaxy->setZ(1000);
//        mesh->save("prova.ply", 15);
//    } else
//        std::cerr << "Error loading mesh" << std::endl;

////    std::vector<std::vector<std::shared_ptr<Point>> > boundaries;
////    std::vector<std::vector<std::shared_ptr<Point>> > constraints;
////    std::vector<std::shared_ptr<Point>> boundary = {
////        std::make_shared<Point>(0,-3,0),
////        std::make_shared<Point>(3,0,0),
////        std::make_shared<Point>(0,3,0),
////        std::make_shared<Point>(-3,0,0)
////    };
////    boundaries.push_back(boundary);
////    std::vector<std::shared_ptr<Point>> hole = {
////        std::make_shared<Point>(-1,-1,0),
////        std::make_shared<Point>(-1,1,0),
////        std::make_shared<Point>(1,1,0),
////        std::make_shared<Point>(1,-1,0)
////    };
////    boundaries.push_back(hole);

////    std::vector<std::shared_ptr<Point>> constraint = {
////        std::make_shared<Point>(-0.5,0.5,0),
////        std::make_shared<Point>(-0.5,-0.5,0)
////    };
////    constraints.push_back(constraint);
////    mesh->triangulate(boundaries, constraints);
//////    TriHelper::TriangleHelper helper(boundary, boundaries, constraints);
//////    std::vector<unsigned int> triangles = helper.getTriangles();
//////    for(unsigned int i = 0; i < triangles.size() / 3; i++)
//////        std::cout << triangles[i * 3] << " " << triangles[i * 3 + 1] << " " << triangles[i * 3 + 2] << std::endl;
////    mesh->save("prova_triangulation.ply");
////    mesh.reset();
    std::shared_ptr<TriangleMesh> original = std::make_shared<TriangleMesh>();
    original->load(argv[1]);
//    TriangleMesh* target = new TriangleMesh();
//    target->load(argv[2]);
    AnnotationFileManager manager;
    manager.setMesh(original);
    auto annotations = manager.readAndStoreAnnotations(argv[2]);
    //original->tr

//    auto mesh = new TriangleMesh();
//    mesh->load(argv[1]);
//    //mesh->smooth(WeightType::Cotangent, 10, 1);
//    mesh->save("smoothed.ply", 15);

//    auto v1 = original->getVertex("0");
//    auto v2 = original->getVertex(std::to_string(original->getVerticesNumber() - 1));
//    auto path = original->computeShortestPath(v1, v2, DistanceType::EUCLIDEAN_DISTANCE, true, true);
//    v1->print(std::cout);
//    v2->print(std::cout);
//    std::cout << std::endl;
//    for(auto p : path)
//        p->print(std::cout);
    original->setAnnotations(annotations);
    auto mesh1 = std::make_shared<TriangleMesh>(original);
    return 0;
}

