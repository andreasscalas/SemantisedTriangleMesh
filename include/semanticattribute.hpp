#ifndef SEMANTICATTRIBUTE_H
#define SEMANTICATTRIBUTE_H

#include <attribute.hpp>

namespace SemantisedTriangleMesh {
    /**
     * @class SemanticAttribute
     * @brief Represents a semantic attribute associated with an annotation.
     *
     * The SemanticAttribute class is a subclass of the Attribute class and represents a semantic attribute that can be associated with an annotation.
     * Semantic attributes provide functionalities to store and manage information related to the semantic meaning of an annotation.
     */

    class SemanticAttribute : virtual public Attribute {
    public:
        /**
         * @brief Default constructor for the SemanticAttribute class.
         */
        SemanticAttribute();

        /**
         * @brief Print the main information related to the semantic attribute.
         * @param os The stream onto which the information should be written.
         */
        virtual void print(std::ostream& os);

        /**
         * @brief Print the main information related to the semantic attribute in JSON format.
         * @param writer The interface with the RapidJSON library for writing the information in JSON format.
         */
        virtual void printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer);
    };

}
#endif // SEMANTICATTRIBUTE_H
