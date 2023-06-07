#include "surfaceannotation.hpp"
#include <rapidjson/writer.h>
#include <eigen3/Eigen/Dense>
#include <queue>

using namespace std;
using namespace SemantisedTriangleMesh;

SurfaceAnnotation::SurfaceAnnotation()
{
    type = AnnotationType::Surface;
}

SurfaceAnnotation::SurfaceAnnotation(TriangleMesh *mesh, std::shared_ptr<SurfaceAnnotation> other) : Annotation(other)
{
    auto otherOutlines = other->getOutlines();
    for(auto otherOutline : otherOutlines)
    {
        std::vector<std::shared_ptr<Vertex> > outline;
        for(auto v : otherOutline)
            outline.push_back(mesh->getVertex(v->getId()));
        outlines.push_back(outline);
    }
}


SurfaceAnnotation::~SurfaceAnnotation()
{
    outlines.clear();
}

void SurfaceAnnotation::print(ostream &os)
{
    Annotation::print(os);
    os << "type: Region" << std::endl << "contours:" << std::endl << "[" << std::endl;
    for(unsigned int i = 0; i < outlines.size(); i++){
        os << "[ " ;
        for(unsigned j = 0; j < outlines[i].size(); j++){
            os << outlines[i][j]->getId();
            if(j < outlines[i].size() - 1)
                os << ", ";
        }

        os << " ]," << std::endl;
    }
    os << "]" << std::endl;
}

void SurfaceAnnotation::printJson(rapidjson::PrettyWriter<rapidjson::StringBuffer>& writer)
{
    writer.StartObject();
    Annotation::printJson(writer);
    writer.Key("type");
    writer.String("Area");
    writer.Key("boundaries");
    writer.StartArray();
    for(unsigned int i = 0; i < outlines.size(); i++){
        writer.StartArray();
        for(unsigned j = 0; j < outlines[i].size(); j++)
        {
            std::shared_ptr<Vertex> v = outlines[i][j];
            writer.Int(stoi(v->getId()));
        }
        writer.EndArray();
    }
    writer.EndArray();
    writer.EndObject();
}

bool SurfaceAnnotation::isPointInAnnotation(std::shared_ptr<Vertex>p)
{
    return isPointInsideAnnotation(p) || isPointOnBorder(p);
}

bool SurfaceAnnotation::isPointInsideAnnotation(std::shared_ptr<Vertex> p)
{
    vector<std::shared_ptr<Vertex>> involved = getInnerVertices();
    for(unsigned int i = 0; i < involved.size(); i++){
        if(involved[i] == p)
            return true;
    }

    return false;
}


bool SurfaceAnnotation::isPointOnBorder(std::shared_ptr<Vertex> p)
{
    for(unsigned int i = 0; i < outlines.size(); i++)
        for(unsigned int j = 0; j < outlines[i].size(); j++)
            if(outlines[i][j] == p)
                return true;

    return false;
}

bool SurfaceAnnotation::isPointOnBorder(std::shared_ptr<Vertex>p, unsigned int &boundaryIndex)
{
    for(unsigned int i = 0; i < outlines.size(); i++)
        for(unsigned int j = 0; j < outlines[i].size(); j++)
            if(outlines[i][j] == p){
                boundaryIndex = i;
                return true;
            }
    return false;
}

bool SurfaceAnnotation::isTriangleInAnnotation(std::shared_ptr<Triangle>t)
{
    vector<std::shared_ptr<Triangle>> triangles = getTriangles();

    for(unsigned int i = 0; i < triangles.size(); i++)
        if(triangles[i] == t)
            return true;
    return false;
}

std::pair<unsigned int, unsigned int> SurfaceAnnotation::getAdjacentBoundary(SurfaceAnnotation *a)
{
    vector<vector<std::shared_ptr<Vertex>> > aOutlines = a->getOutlines();
    std::vector<std::shared_ptr<Triangle>> aTriangles = a->getTriangles();
    std::vector<std::shared_ptr<Triangle>> thisTriangles = this->getTriangles();
    for(unsigned int i = 0; i < this->outlines.size(); i++)
        for(unsigned int j = 0; j < this->outlines[i].size(); j++)
            for(unsigned int k = 0; k < aOutlines.size(); k++){
                vector<std::shared_ptr<Vertex>>::iterator vit = std::find(aOutlines[k].begin(), aOutlines[k].end(), this->outlines[i][j]);
                if(vit != aOutlines[k].end())
                    return make_pair(i, k);
            }

    return make_pair(this->outlines.size(), a->getOutlines().size());

}

bool SurfaceAnnotation::checkAdjacency(SurfaceAnnotation *a)
{
    vector<vector<std::shared_ptr<Vertex>> > aOutlines = a->getOutlines();
    std::vector<std::shared_ptr<Triangle>> aTriangles = a->getTriangles();
    std::vector<std::shared_ptr<Triangle>> thisTriangles = this->getTriangles();
    vector<std::shared_ptr<Triangle>>::iterator tit1 = std::find(aTriangles.begin(), aTriangles.end(), thisTriangles[0]);
    vector<std::shared_ptr<Triangle>>::iterator tit2 = std::find(thisTriangles.begin(), thisTriangles.end(), aTriangles[0]);
    for(unsigned int i = 0; i < this->outlines.size(); i++)
        for(unsigned int j = 0; j < this->outlines[i].size(); j++)
            for(unsigned int k = 0; k < aOutlines.size(); k++){
                vector<std::shared_ptr<Vertex>>::iterator vit = std::find(aOutlines[k].begin(), aOutlines[k].end(), this->outlines[i][j]);
                if(vit != aOutlines[k].end() && tit1 == aTriangles.end() && tit2 == thisTriangles.end())
                    return true;
            }



    return false;
}

//Annotation *SurfaceAnnotation::transfer(TriangleMesh *otherMesh, short metric)
//{
//    SurfaceAnnotation* otherAnnotation = new SurfaceAnnotation(); //The transferred annotation
//    std::shared_ptr<Vertex> v, initialVertex;                      //Some support variable

//    sphereRay = otherMesh->getAABBDiagonalLength() / BBOX_SPHERE_RATIO;
//    for(uint i = 0; i < this->getMesh()->getVerticesNumber(); i++)
//        this->mesh->getVertex(i)->setInfo(nullptr);


//    for(vector<vector<std::shared_ptr<Vertex> > >::iterator oit = outlines.begin(); oit != outlines.end(); oit++){

//        std::vector<std::shared_ptr<Vertex> > otherOutline;              //The outline of the transferred annotation

//        if(oit->size() != 0)
//        {
//            bool alreadyUsed = true;
//            vector<std::shared_ptr<Vertex> > outline = static_cast<vector<std::shared_ptr<Vertex> > >(*oit);
//            std::vector<std::shared_ptr<Vertex> >::iterator vit = outline.begin();
//            std::shared_ptr<Vertex>  v1, *v2;

//            outline.pop_back();

//            do{
//                v = static_cast<std::shared_ptr<Vertex> >(*vit);
//                auto neighbors = otherMesh->getNearestNeighbours(*v, sphereRay);
//                vector<Triangle*> toCheckTriangles;
//                Utilities::findFaces(toCheckTriangles, neighbors);
//                v1 = Utilities::findCorrespondingVertex(v, toCheckTriangles);
//                if(v1 == nullptr)
//                    sphereRay *= 2;
//            }while(v1 == nullptr);
//            sphereRay = otherMesh->bboxLongestDiagonal() / BBOX_SPHERE_RATIO;
//            initialVertex = v1;
//            //v1->info = &alreadyUsed;

//            for(; vit != outline.end(); vit++){
//                do{
//                    v = static_cast<Vertex*>(*vit);
//                    vector<Vertex*> neighbors = otherMesh->getNeighboursInSphere(*v, sphereRay);
//                    vector<Triangle*> toCheckTriangles;
//                    Utilities::findFaces(toCheckTriangles, neighbors);
//                    v2 = Utilities::findCorrespondingVertex(v, toCheckTriangles);
//                    if(v2 == nullptr)
//                        sphereRay *= 2;
//                    if(sphereRay > otherMesh->bboxLongestDiagonal())
//                    {
//                        std::cerr << "Isolated vertex" << std::endl;
//                        std::cerr << "(" << v1->x << "," << v1->y << "," << v1->z << ")" << std::endl;
//                        exit(9);
//                    }

//                }while(v2 == nullptr);

//                sphereRay = otherMesh->bboxLongestDiagonal() / BBOX_SPHERE_RATIO;
//                if(v2->info == nullptr || !(*static_cast<bool*>(v2->info))){
//                    vector<Vertex*> path = Utilities::dijkstra(v1, v2, metric, !POST_PROCESSING);
//                    for (vector<Vertex*>::iterator pit = path.begin(); pit != path.end(); pit++)
//                        (*pit)->info = &alreadyUsed;

//                    otherOutline.insert(otherOutline.end(), path.begin(), path.end());
//                    v1 = v2;
//                }
//            }

//            v2 = initialVertex;
//            initialVertex->info = nullptr;
//            vector<Vertex*> path = Utilities::dijkstra(v1, v2, metric, false);
//            otherOutline.insert(otherOutline.end(), path.begin(), path.end());

//            for(unsigned int i = 0; i < otherOutline.size(); i++)
//                otherOutline[i]->info = nullptr;


//            while((otherOutline[0] == otherOutline[otherOutline.size() - 1]) && (otherOutline[1] == otherOutline[otherOutline.size() - 2])){
//                otherOutline.erase(otherOutline.begin());
//                otherOutline.erase(otherOutline.begin() + static_cast<long>(otherOutline.size()) - 1);
//            }


//            if(POST_PROCESSING){
//                v = otherOutline[0];
//                otherOutline.erase(otherOutline.begin());
//                std::vector<Vertex*> crossedVertices;

//                for(vector<Vertex*>::iterator vit1 = otherOutline.begin(); vit1 != otherOutline.end(); vit1++){
//                    v1 = static_cast<Vertex*>(*vit1);
//                    if(std::find(crossedVertices.begin(), crossedVertices.end(), v1) == crossedVertices.end())
//                        crossedVertices.push_back(v1);
//                    else
//                        for(vector<Vertex*>::iterator vit2 = vit1 - 1; vit2 != otherOutline.begin(); vit2--){
//                            v2 = static_cast<Vertex*>(*vit2);

//                            if(v2 == v1){
//                                otherOutline.erase(vit2, vit1);
//                                vit1 = vit2;
//                                break;
//                            }
//                        }
//                }

//                otherOutline.insert(otherOutline.begin(), v);
//            }

//            outline.push_back(*outline.begin());
//            otherOutline.push_back(*otherOutline.begin());
//        }

//        otherAnnotation->addOutline(otherOutline);  //The new annotation outline is computed
//    }

//    //The Outline and inner vertex have been found, the tag and color are the same, so the process ends.
//    otherAnnotation->setId(this->id);
//    otherAnnotation->setMesh(otherMesh);
//    otherAnnotation->setTag(this->tag);
//    otherAnnotation->setColor(this->color);
//    otherAnnotation->setAttributes(this->attributes);
//    otherAnnotation->setHierarchyLevel(this->hierarchyLevel);
//    for(Node* n = otherMesh->V.head(); n != nullptr; n=n->next())
//        static_cast<Vertex*>(n->data)->info = nullptr;

//    return otherAnnotation;
//}

vector<vector<std::shared_ptr<Vertex>> > SurfaceAnnotation::getOutlines() const{
    return outlines;
}

void SurfaceAnnotation::setOutlines(const vector<vector<std::shared_ptr<Vertex>> > value){
    outlines.clear();
    outlines.insert(outlines.end(), value.begin(), value.end());
}

void SurfaceAnnotation::addOutline(const vector<std::shared_ptr<Vertex>> value){
    outlines.push_back(value);
}

vector<std::shared_ptr<Triangle>> SurfaceAnnotation::getTriangles(){
    vector<std::shared_ptr<Triangle>> annotationTriangles;
    if(outlines.size() == 0){
        for(unsigned int i = 0; i < mesh->getTrianglesNumber(); i++){
            std::shared_ptr<Triangle> t = mesh->getTriangle(i);
            annotationTriangles.push_back(t);
        }
    } else
        annotationTriangles = regionGrowing(outlines);

    return annotationTriangles;
}

std::vector<std::string> SurfaceAnnotation::getTrianglesIds()
{

    vector<std::string> annotationTrianglesIds;
    if(outlines.size() == 0){
        for(unsigned int i = 0; i < mesh->getTrianglesNumber(); i++){
            std::shared_ptr<Triangle> t = mesh->getTriangle(i);
            annotationTrianglesIds.push_back(t->getId());
        }
    } else
    {
        auto annotationTriangles = regionGrowing(outlines);
        for(auto t : annotationTriangles)
            annotationTrianglesIds.push_back(t->getId());
    }

    return annotationTrianglesIds;
}

Point *SurfaceAnnotation::getCenter()
{
    vector<std::shared_ptr<Vertex>> involvedVertices = getInvolvedVertices();
    Point* center = new Point(0,0,0);
    for(unsigned int i = 0; i < involvedVertices.size(); i++ )
    {
        *center += *(involvedVertices[i]);
    }

    *center /= involvedVertices.size();

    return center;
}

Point *SurfaceAnnotation::getOrientation()
{
    vector<std::shared_ptr<Vertex>> involvedVertices = getInvolvedVertices();
    Eigen::MatrixXd eigenPoints;
    eigenPoints.resize(3, static_cast<Eigen::Index>(involvedVertices.size()));

    for(unsigned int i = 0; i < involvedVertices.size(); i++ )
    {
        Eigen::Vector3d p = {involvedVertices[i]->getX(), involvedVertices[i]->getY(), involvedVertices[i]->getZ()};
        eigenPoints.col(i) = p;
    }

    Eigen::Vector3d mean_vector = eigenPoints.rowwise().mean();
    eigenPoints.colwise() -= mean_vector;
    Eigen::Matrix3d U = eigenPoints.bdcSvd(Eigen::ComputeFullU | Eigen::ComputeThinV).matrixU();
    Point* orientation = new Point();
    orientation->setX(U(0,2));
    orientation->setX(U(1,2));
    orientation->setX(U(2,2));
    return orientation;
}

std::vector<std::shared_ptr<Triangle> > SurfaceAnnotation::regionGrowing(std::vector<std::vector<std::shared_ptr<Vertex> > > contours)
{

        // neighbors is a queue that stores the list of the reachable triangles.
        queue<std::shared_ptr<Triangle>> neighbors;

        //List of triangles of the annotation (initially empty)
        vector<std::shared_ptr<Triangle>> internalTriangles;

        //We iterate over the list of contours
        for(unsigned int i = 0; i < contours.size(); i++){

            //This is the i-th boundary
            std::vector<std::shared_ptr<Vertex> > boundary = contours[i];
            /* For each boundary, we take the first two vertices (boundary[0] and boundary[1]) in the boundary.
             * The boundary is ordered counterclockwise, so you have to consider the triangle (t) on the left of
             * the edge connecting the two vertices.
             */
            std::shared_ptr<Triangle> t = boundary[0]->getCommonEdge(boundary[1])->getLeftTriangle(boundary[0]);
            if(t != nullptr)
            {
                internalTriangles.push_back(t);
                t->addFlag(FlagType::USED);
                //We insert the triangle (or seed of the region growing algorithm) in the queue of available triangles
                neighbors.push(t);
                //We mark each edge in the boundary as a boundary edge
                for(unsigned int i = 1; i < boundary.size(); i++){

                    std::shared_ptr<Vertex> v1 = boundary[i - 1];
                    std::shared_ptr<Vertex> v2 = boundary[i]; //% is the modulo operator. If i is equal to boundary.size() we use boundary[0].

                    std::shared_ptr<Edge> e = v1->getCommonEdge(v2);
                    if(e != nullptr)
                        e->addFlag(FlagType::ON_BOUNDARY);
                    else {
                        std::cerr << "This shouldn't happen. Error in the identification of the edge." << std::endl << std::flush;
                        std::cerr << "Local neighbourhood" << std::endl;
                        std::cerr.precision(15);
                        std::cerr << "Starting vertex: ";
                        v1->print(std::cerr);
                        unsigned int counter = 0;
                        std::vector<std::shared_ptr<Edge> > ve1 = v1->getVE();
                        for(unsigned int i = 0; i < ve1.size(); i++)
                        {
                            std::shared_ptr<Vertex> v_ = ve1.at(i)->getOppositeVertex(v1);
                            std::cerr << counter + 1 << "-th neighbour: ";
                            v_->print(std::cerr);
                            counter++;
                        }

                        std::cerr << "Wanted vertex: ";
                        v2->print(std::cerr);
                        counter = 0;
                        std::vector<std::shared_ptr<Edge> > ve2 = v2->getVE();
                        for(unsigned int i = 0; i < ve2.size(); i++)
                        {
                            std::shared_ptr<Vertex> v_ = ve2.at(i)->getOppositeVertex(v2);
                            std::cerr << counter + 1 << "-th neighbour: ";
                            v_->print(std::cerr);
                            counter++;
                        }

                        for(unsigned int i = 0; i < contours.size(); i++){

                            std::vector<std::shared_ptr<Vertex> > boundary = contours[i];
                            std::cout << "B" << i << "=[" << std::endl;
                            for(uint j = 0; j < boundary.size(); j++)
                            {
                                std::static_pointer_cast<Point>(boundary.at(j))->print(std::cout, BracketsType::NONE, " ");
                            }
                            std::cout << "];" << std::endl;
                            std::cout << "plot(B" << i << "(:,1), B" << i << "(:,2));" << std::endl;
                            std::cout << "labels=num2cell(0:length(B" << i << ")-1);" << std::endl;
                            std::cout << "text(B" << i << "(:,1), B" << i << "(:,2), labels);" << std::endl << std::endl;
                        }

                        exit(5);

                    }
                }

            } else
            {
                std::cerr << "Error in the identification of annotated triangles: boundary is not closed!" << std::endl;
                for(auto b : boundary)
                {
                    std::static_pointer_cast<Point>(b)->print(std::cerr, BracketsType::NONE, " ");
                }
                exit(245);
            }
        }

        //We will analyse triangles until the queue of available triangles is not empty.
        while(neighbors.size() > 0){
            //We take the first triangle (t) from the queue and remove it from there
            std::shared_ptr<Triangle> t = neighbors.front();
            neighbors.pop();
            //We take the first edge (e) of t
            std::shared_ptr<Edge> e = t->getE1();
            //t has 3 edges, so we will perform the analysis 3 times
            for(int i = 0; i < 3; i++){
                //If e is not on the boundary
                if((e->getV1()->getId().compare("92253") == 0 && e->getV2()->getId().compare("92254") == 0) ||
                   (e->getV2()->getId().compare("92253") == 0 && e->getV1()->getId().compare("92254") == 0) ||
                   (e->getV1()->getId().compare("92265") == 0 || e->getV2()->getId().compare("92265") == 0))
                    std::cout << std::endl;
                if(e->searchFlag(FlagType::ON_BOUNDARY) == -1){
                    //We take the triangle (t_) on the opposite side of e with respect to t.
                    std::shared_ptr<Triangle> t_ = e->getOppositeTriangle(t);
                    if(t_ == nullptr)
                        continue;   //the mesh is not watertight and the edge is on the bounday of the mesh
                    //If t_ has't been used yet, we insert it in the queue of usable triangles and in the list of triangles that are part of the annotation
                    if(t_->searchFlag(FlagType::USED) == -1){
                        internalTriangles.push_back(t_);
                        t_->addFlag(FlagType::USED);
                        neighbors.push(t_);
                    }
                }
                //We take the next edge of t.
                e = t->getNextEdge(e);
            }
        }

        //The actual algorithm is ended.

        //Ignore this for cycle, I am just removing the markings from the edges
        for(unsigned int i = 0; i < contours.size(); i++){

            vector<std::shared_ptr<Vertex>> boundary = contours[i];
            for(unsigned int i = 1; i < boundary.size(); i++){

                std::shared_ptr<Vertex> v1 = boundary[i - 1];
                std::shared_ptr<Vertex> v2 = boundary[i];

                std::shared_ptr<Edge> e = v1->getCommonEdge(v2);
                e->removeFlag(FlagType::ON_BOUNDARY);
            }
        }


        //Ignore this for cycle, I am just removing the markings from the triangles
        for(std::vector<std::shared_ptr<Triangle>>::iterator it = internalTriangles.begin(); it != internalTriangles.end(); it++)
            (*it)->removeFlag(FlagType::USED);


        //Now the list has all the triangles in the annotation.
        return internalTriangles;
}

vector<vector<std::shared_ptr<Vertex>> > SurfaceAnnotation::getOutlines(vector<std::shared_ptr<Triangle>> set){

    vector<std::pair<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>> > setOutlineEdges;
    vector<vector<std::shared_ptr<Vertex>> > outlines;
    std::shared_ptr<Vertex> v, v_;
    int IS_INSIDE = 738;

    for(std::vector<std::shared_ptr<Triangle>>::iterator tit = set.begin(); tit != set.end(); tit++)
        (*tit)->addInformation(&IS_INSIDE);

    for(std::vector<std::shared_ptr<Triangle>>::iterator tit = set.begin(); tit != set.end(); tit++){
        std::shared_ptr<Triangle> t = static_cast<std::shared_ptr<Triangle>>(*tit);
        std::shared_ptr<Edge> e = t->getE1();
        for(int i = 0; i < 3; i++){
            std::shared_ptr<Triangle> t_ = e->getOppositeTriangle(t);
            if(t_ == nullptr || !t_->searchInformation(&IS_INSIDE)){
                std::shared_ptr<Edge> e_ = t->getPreviousEdge(e);
                v = e_->getCommonVertex(e);
                setOutlineEdges.push_back(std::make_pair(v, e->getOppositeVertex(v)));
            }
            e = t->getNextEdge(e);
        }
    }

    while(setOutlineEdges.size() != 0){

        vector<std::shared_ptr<Vertex>> outline;
        v = setOutlineEdges[0].first;
        std::shared_ptr<Vertex>initialVertex = v;

        std::pair<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>> pPrev = std::make_pair(nullptr, nullptr);
        do{
            outline.push_back(v);
            std::vector<std::shared_ptr<Vertex> > vv = v->getVV();
            for(unsigned int i = 0; i < vv.size(); i++){
                v_ = vv.at(i);
                std::pair<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>> p = std::make_pair(v, v_);
                for(vector<pair<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>> >::iterator pit = setOutlineEdges.begin(); pit != setOutlineEdges.end(); pit++){
                    pair<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>> tmp = static_cast<pair<std::shared_ptr<Vertex>, std::shared_ptr<Vertex>> >(*pit);
                    if(p != pPrev &&
                       ((p.first->getId().compare(tmp.second->getId()) == 0 && p.second->getId().compare(tmp.first->getId()) == 0) ||
                       (p.first->getId().compare(tmp.second->getId()) == 0 && p.second->getId().compare(tmp.first->getId()) == 0)) ){
                        v = v_;
                        pPrev = p;
                        setOutlineEdges.erase(pit);
                        break;
                    }
                }

                if(v->getId().compare(v_->getId()) == 0)
                    break;
            }
        }while(v != initialVertex);
        outline.push_back(outline[0]);
        outlines.push_back(outline);
    }

    for(vector<vector<std::shared_ptr<Vertex>> >::iterator oit = outlines.begin(); oit != outlines.end(); oit++){
        vector<std::shared_ptr<Vertex>> outline = static_cast<vector<std::shared_ptr<Vertex>> >(*oit);
        std::shared_ptr<Triangle> t = nullptr;
        for (unsigned int i = 1; i < outline.size(); i++) {
            t = outline[i - 1]->getCommonEdge(outline[i])->getLeftTriangle(outline[i - 1]);
            if(t != nullptr)
                break;
        }
        if(t == nullptr || std::find(set.begin(), set.end(), t) == set.end())
            std::reverse(oit->begin(), oit->end());
    }

    for(std::vector<std::shared_ptr<Triangle>>::iterator tit = set.begin(); tit != set.end(); tit++){
        (*tit)->clearInformation();
    }

    return outlines;

}

std::vector<std::shared_ptr<Vertex>> SurfaceAnnotation::getInvolvedVertices()
{
    vector<std::shared_ptr<Vertex>> vertices = getInnerVertices();

    for(unsigned int i = 0; i < outlines.size(); i++)
        vertices.insert(vertices.end(), outlines[i].begin(), outlines[i].end());

    return vertices;
}

std::vector<std::shared_ptr<Vertex>> SurfaceAnnotation::getInnerVertices()
{

    vector<std::shared_ptr<Vertex>> vertices;

    if(outlines.size() == 0){

        for(unsigned int i = 0; i < mesh->getVerticesNumber(); i++){
            std::shared_ptr<Vertex> v = mesh->getVertex(i);
            vertices.push_back(v);
        }

    }else{
        for(vector<vector<std::shared_ptr<Vertex>> >::iterator oit = outlines.begin(); oit != outlines.end(); oit++){
            vector<std::shared_ptr<Vertex>> outline = static_cast<vector<std::shared_ptr<Vertex>> >(*oit);
            for(vector<std::shared_ptr<Vertex>>::iterator vit = outline.begin(); vit != outline.end(); vit++){
                std::shared_ptr<Vertex> v = static_cast<std::shared_ptr<Vertex>>(*vit);
                v->addFlag(FlagType::ON_BOUNDARY);
            }
        }

        vector<std::shared_ptr<Triangle>> triangles = regionGrowing(outlines);
        for(unsigned int i = 0; i < triangles.size(); i++){
            std::shared_ptr<Vertex> v = triangles[i]->getV1();
            for(unsigned int j = 0; j < 3; j++){
                v = triangles[i]->getNextVertex(v);
                if(v->searchFlag(FlagType::USED) == -1 && v->searchFlag(FlagType::ON_BOUNDARY) == -1){
                    vertices.push_back(v);
                    v->addFlag(FlagType::USED);
                }
            }
        }

        for(vector<vector<std::shared_ptr<Vertex>> >::iterator oit = outlines.begin(); oit != outlines.end(); oit++)
            for(vector<std::shared_ptr<Vertex>>::iterator vit = (*oit).begin(); vit != (*oit).end(); vit++)
                (*vit)->removeFlag(FlagType::ON_BOUNDARY);


        for(unsigned int i = 0; i < vertices.size(); i++)
            vertices.at(i)->removeFlag(FlagType::USED);

    }

    return vertices;

}


