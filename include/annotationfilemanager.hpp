#ifndef ANNOTATIONFILEMANAGER_H
#define ANNOTATIONFILEMANAGER_H

#include <string>
#include <iostream>
#include "TriangleMesh.hpp"

namespace SemantisedTriangleMesh
{
    class AnnotationFileManager
    {
    public:
        static const int BUFFER_SIZE = 65536;

        AnnotationFileManager();
        bool writeAnnotations(std::string fileName);
        bool readAnnotations(std::string fileName);
        std::vector<std::shared_ptr<SemantisedTriangleMesh::Annotation> > readAndStoreAnnotations(std::string fileName);


        bool writeRelationships(std::string fileName);
        bool readRelationships(std::string fileName);

        std::shared_ptr<SemantisedTriangleMesh::TriangleMesh> getMesh() const;
        void setMesh(std::shared_ptr<SemantisedTriangleMesh::TriangleMesh>value);

    private:
        std::shared_ptr<SemantisedTriangleMesh::TriangleMesh> mesh;
    };
}

#endif // ANNOTATIONFILEMANAGER_H
