#ifndef ATTRIBUTE_H
#define ATTRIBUTE_H

#include <string>
#include <rapidjson/prettywriter.h>

namespace SemantisedTriangleMesh {

    /**
     * @class Attribute
     * @brief Represents an attribute associated with a geometric element in a 3D mesh.
     *
     * The Attribute class is an abstract base class representing an attribute associated with an annotationof a 3D mesh.
     * It provides a common interface for accessing and setting the attribute key and value. The class also allows checking
     * if the attribute is considered "geometric", i.e. has a geometric embedding.
     */
    class Attribute
    {
    public:

        /**
         * @brief Destructor for the Attribute object.
         */
        virtual ~Attribute() {}

        /**
         * @brief Print the attribute information to an output stream.
         * @param os The output stream to print the attribute information to.
         */
        virtual void print(std::ostream &os);

        /**
         * @brief Print the attribute information as JSON to a PrettyWriter.
         * @param writer The PrettyWriter to print the attribute information to.
         */
        virtual void printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer);

        /**
         * @brief Get the key associated with the attribute.
         * @return The attribute key as a string.
         */
        std::string getKey() const;

        /**
         * @brief Set the key associated with the attribute.
         * @param value The new key to be set for the attribute.
         */
        void setKey(const std::string &value);

        /**
         * @brief Get the value associated with the attribute as a void pointer.
         * @return A void pointer to the value associated with the attribute.
         */
        void *getValue() const;

        /**
         * @brief Set the value associated with the attribute as a void pointer.
         * @param value A void pointer to the new value to be set for the attribute.
         */
        void setValue(void *value);

        /**
         * @brief Set the value associated with the attribute as an integer.
         * @param value The new integer value to be set for the attribute.
         */
        void setValue(int value);

        /**
         * @brief Set the value associated with the attribute as a double.
         * @param value The new double value to be set for the attribute.
         */
        void setValue(double value);

        /**
         * @brief Set the value associated with the attribute as a string.
         * @param value The new string value to be set for the attribute.
         */
        void setValue(std::string value);

        /**
         * @brief Get the unique identifier (ID) of the attribute.
         * @return The ID of the attribute as an unsigned integer.
         */
        unsigned int getId() const;

        /**
         * @brief Set the unique identifier (ID) of the attribute.
         * @param value The new ID to be set for the attribute.
         */
        void setId(unsigned int value);

        /**
         * @brief Check if the attribute is considered geometric.
         * @return True if the attribute is considered geometric, false otherwise.
         */
        bool isGeometric() const;

        /**
         * @brief Set whether the attribute is considered geometric.
         * @param newGeometric The new value indicating whether the attribute is geometric.
         */
        void setIsGeometric(bool newGeometric);

    protected:
        unsigned int id;
        std::string key;
        void* value;
        bool geometric;
    };
}
#endif // ATTRIBUTE_H
