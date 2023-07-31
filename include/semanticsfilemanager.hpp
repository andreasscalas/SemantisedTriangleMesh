#ifndef SEMANTICSFILEMANAGER_H
#define SEMANTICSFILEMANAGER_H

#include <string>
#include <iostream>
#include "TriangleMesh.hpp"

namespace SemantisedTriangleMesh
{
    /**
     * @class SemanticsFileManager
     * @brief Manages reading and writing annotations and relationships from/to files.
     *
     * The SemanticsFileManager class provides functionalities to read and write annotations and relationships from/to files.
     * It can read and write annotations from a file, read and store annotations into memory, and read and write relationships
     * between annotations. The class also allows the association of a mesh to facilitate data storage and retrieval.
    */
    class SemanticsFileManager
    {
    public:
        static const int BUFFER_SIZE = 65536; // The buffer size for reading/writing data

        /**
         * @brief Default constructor for the SemanticsFileManager class.
         */
        SemanticsFileManager();
        /**
         * @brief Write the annotations to a file.
         * @param fileName The name of the file to which the annotations should be written.
         * @return True if the annotations were successfully written, false otherwise.
         */
        bool writeAnnotations(std::string fileName);

        /**
         * @brief Read the annotations from a file.
         * @param fileName The name of the file from which the annotations should be read.
         * @return True if the annotations were successfully read, false otherwise.
         */
        bool readAnnotations(std::string fileName);

        /**
         * @brief Read and store annotations from a file.
         * @param fileName The name of the file from which the annotations should be read and stored.
         * @return A vector containing shared pointers to the stored annotations.
         */
        std::vector<std::shared_ptr<SemantisedTriangleMesh::Annotation>> readAndStoreAnnotations(std::string fileName);

        /**
         * @brief Write the relationships between annotations to a file.
         * @param fileName The name of the file to which the relationships should be written.
         * @return True if the relationships were successfully written, false otherwise.
         */
        bool writeRelationships(std::string fileName);

        /**
         * @brief Read the relationships between annotations from a file.
         * @param fileName The name of the file from which the relationships should be read.
         * @return True if the relationships were successfully read, false otherwise.
         */
        bool readRelationships(std::string fileName);

        /**
         * @brief Get the mesh associated with the SemanticsFileManager.
         * @return A shared pointer to the SemantisedTriangleMesh::TriangleMesh representing the mesh.
         */
        std::shared_ptr<SemantisedTriangleMesh::TriangleMesh> getMesh() const;

        /**
         * @brief Set the mesh associated with the SemanticsFileManager.
         * @param value A shared pointer to the SemantisedTriangleMesh::TriangleMesh representing the new mesh to be associated.
         */
        void setMesh(std::shared_ptr<SemantisedTriangleMesh::TriangleMesh> value);

    private:
        std::shared_ptr<SemantisedTriangleMesh::TriangleMesh> mesh;
    };
}

#endif // SEMANTICSFILEMANAGER_H
