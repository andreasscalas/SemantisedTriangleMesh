#ifndef RELATIONSHIP_H
#define RELATIONSHIP_H

#include <vector>
#include <string>

#include "annotation.hpp"

namespace SemantisedTriangleMesh {
    class Relationship
    {
    public:
        Relationship();

        virtual ~Relationship();
        unsigned int getId() const;
        void setId(unsigned int value);
        std::string getType() const;
        void setType(const std::string &value);
        std::vector<std::shared_ptr<Annotation> > getAnnotations() const;
        void setAnnotations(const std::vector<std::shared_ptr<Annotation> > &value);
        double getWeight() const;
        void setWeight(double value);
        double getMinValue() const;
        void setMinValue(double value);
        double getMaxValue() const;
        void setMaxValue(double value);

        virtual void print(std::ostream &os);
        virtual void printJSON(rapidjson::PrettyWriter<rapidjson::StringBuffer> &writer);


    protected:
        unsigned int id;
        std::vector<std::shared_ptr<Annotation> > annotations;
        std::string type;
        double weight;
        double minValue, maxValue;
    };
}
#endif // RELATIONSHIP_H
