#include <iostream>
#include <fstream>
#include <semanticsfilemanager.hpp>
#include "TriangleMesh.hpp"

using namespace SemantisedTriangleMesh;
const int MAX_VALUE = 10000;
int main(int argc, char* argv[])
{

    auto mesh = std::make_shared<TriangleMesh>();
    mesh->load(argv[1]);
    SemanticsFileManager manager;
    manager.setMesh(mesh);
    manager.readAnnotations(argv[2]);
    auto it = mesh->getAnnotations().begin();
    std::vector<std::shared_ptr<Annotation> > newAnnotations;
    while(it != mesh->getAnnotations().end())
    {
        if((*it)->getType() != AnnotationType::Point)
        {
            (*it)->setId(std::to_string(newAnnotations.size()));
            newAnnotations.push_back((*it));
        }
        it++;
    }
    mesh->setAnnotations(newAnnotations);
    manager.writeAnnotations("without_points.ant");
    return 0;
}

