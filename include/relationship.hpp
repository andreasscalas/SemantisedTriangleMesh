#ifndef RELATIONSHIP_H
#define RELATIONSHIP_H

#include <vector>
#include <string>

#include "annotation.hpp"

namespace SemantisedTriangleMesh {
    /**
     * @class Relationship
     * @brief Represents a relationship between annotations in a triangle mesh.
     *
     * The Relationship class represents a relationship between annotations in a triangle mesh.
     * It can define how different annotations are related to each other, such as a spatial relationship or a semantic relationship.
     */

    class Relationship {
    public:
        /**
         * @brief Default constructor for the Relationship class.
         */
        Relationship();

        /**
         * @brief Destructor for the Relationship class.
         */
        virtual ~Relationship();

        /**
         * @brief Get the ID of the relationship.
         * @return The ID of the relationship as an unsigned integer.
         */
        unsigned int getId() const;

        /**
         * @brief Set the ID of the relationship.
         * @param value The new ID value to be set.
         */
        void setId(unsigned int value);

        /**
         * @brief Get the type of the relationship.
         * @return The type of the relationship as a string.
         */
        std::string getType() const;

        /**
         * @brief Set the type of the relationship.
         * @param value The new type value to be set.
         */
        void setType(const std::string& value);

        /**
         * @brief Get the annotations involved in the relationship.
         * @return A vector of shared pointers to Annotation objects representing the annotations involved in the relationship.
         */
        std::vector<std::shared_ptr<Annotation>> getAnnotations() const;

        /**
         * @brief Set the annotations involved in the relationship.
         * @param value A vector of shared pointers to Annotation objects representing the new annotations to be set.
         */
        void setAnnotations(const std::vector<std::shared_ptr<Annotation>>& value);

        /**
         * @brief Get the weight of the relationship.
         * @return The weight of the relationship as a double value.
         */
        double getWeight() const;

        /**
         * @brief Set the weight of the relationship.
         * @param value The new weight value to be set.
         */
        void setWeight(double value);

        /**
         * @brief Get the minimum value associated with the relationship.
         * @return The minimum value of the relationship as a double value.
         */
        double getMinValue() const;

        /**
         * @brief Set the minimum value associated with the relationship.
         * @param value The new minimum value to be set.
         */
        void setMinValue(double value);

        /**
         * @brief Get the maximum value associated with the relationship.
         * @return The maximum value of the relationship as a double value.
         */
        double getMaxValue() const;

        /**
         * @brief Set the maximum value associated with the relationship.
         * @param value The new maximum value to be set.
         */
        void setMaxValue(double value);

        /**
         * @brief Print main information related to the relationship.
         * @param os The stream onto which the information should be written.
         */
        virtual void print(std::ostream& os);

        /**
         * @brief Print main information related to the relationship in JSON format.
         * @param writer The interface with the RapidJSON library for writing the information in JSON format.
         */
        virtual void printJSON(rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer);

    protected:
        unsigned int id;                                  // The ID of the relationship
        std::vector<std::shared_ptr<Annotation>> annotations;  // The annotations involved in the relationship
        std::string type;                                // The type of the relationship
        double weight;                                   // The weight of the relationship
        double minValue, maxValue;                       // The minimum and maximum values associated with the relationship
};

}
#endif // RELATIONSHIP_H
