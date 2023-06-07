#include <memory>
#include "Edge.hpp"
#include <algorithm>
#include <map>

using namespace SemantisedTriangleMesh;

Edge::Edge()
{
    setId("-1");
    v1 = nullptr;
    v2 = nullptr;
    t1 = nullptr;
    t2 = nullptr;
}

Edge::Edge(std::shared_ptr<Vertex> v1, std::shared_ptr<Vertex> v2)
{
    setId("-1");
    setV1(v1);
    setV2(v2);
    t1 = nullptr;
    t2 = nullptr;
}

Edge::Edge(std::shared_ptr<Edge> e)
{
    setId(e->getId());
    setV1(e->getV1());
    setV2(e->getV2());
    setT1(e->getT1());
    setT2(e->getT2());
    this->associated_flags.insert(this->associated_flags.end(), e->getAssociatedFlags().begin(), e->getAssociatedFlags().end());
    this->information.insert(this->information.end(), e->getInformation().begin(), e->getInformation().end());
}

Edge::~Edge()
{
    v1.reset();
    v2.reset();
    t1.reset();
    t2.reset();


}

std::shared_ptr<Vertex> Edge::getV1() const
{
    return v1;
}

void Edge::setV1(std::shared_ptr<Vertex> newV1)
{
    v1 = newV1;
}

std::shared_ptr<Vertex> Edge::getV2() const
{
    return v2;
}

void Edge::setV2(std::shared_ptr<Vertex> newV2)
{
    v2 = newV2;
}

bool Edge::setVertex(std::shared_ptr<Vertex> v, std::shared_ptr<Vertex> newV)
{
    if(v1->getId().compare(v->getId()) == 0)
    {
        setV1(newV);
        return true;
    } else if (v2->getId().compare(v->getId()) == 0)
    {
        setV2(newV);
        return true;
    }
    return false;
}

const std::vector<void *> &Edge::getInformation() const
{
    return information;
}

void Edge::setInformation(const std::vector<void *> &newInformation)
{
    information = newInformation;
}

const std::vector<FlagType> &Edge::getAssociatedFlags() const
{
    return associated_flags;
}

void Edge::setAssociatedFlags(const std::vector<FlagType> &newAssociatedFlags)
{
    associated_flags = newAssociatedFlags;
}

std::shared_ptr<Vertex> Edge::getCommonVertex(std::shared_ptr<Edge> e)
{
    if(e->hasVertex(v1))
        return v1;
    if(e->hasVertex(v2))
        return v2;
    return nullptr;

}

std::shared_ptr<Vertex> Edge::getOppositeVertex(std::shared_ptr<Vertex> v)
{
    if(v1 != nullptr && v1->getId().compare( v->getId()) == 0)
        return v2;
    if(v2 != nullptr && v2->getId().compare( v->getId()) == 0)
        return v1;

    return nullptr;
}

std::shared_ptr<Triangle> Edge::getLeftTriangle(std::shared_ptr<Vertex>  v)
{
    std::shared_ptr<Vertex>  v_;
    std::shared_ptr<Vertex>  v__ = this->getOppositeVertex(v);
    std::shared_ptr<Vertex> t1v1, t1v2, t1v3, t2v1, t2v2, t2v3;
    if(t1 != nullptr)
    {
        t1v1 = t1->getV1();
        t1v2 = t1->getV2();
        t1v3 = t1->getV3();
        v_ = t1->getNextVertex(v);
        if(v_->getId().compare( v__->getId()) == 0)
            return t1;
    }
    if(t2 != nullptr)
    {
        t2v1 = t2->getV1();
        t2v2 = t2->getV2();
        t2v3 = t2->getV3();
        v_ = t2->getNextVertex(v);
        if(v_->getId().compare( v__->getId()) == 0)
            return t2;
    }

    return nullptr;

}

std::shared_ptr<Triangle> Edge::getRightTriangle(std::shared_ptr<Vertex>  v)
{

    if(t1 != nullptr && t1->getPreviousVertex(v)->getId().compare( this->getOppositeVertex(v)->getId()) == 0)
        return t1;
    if(t2 != nullptr && t2->getPreviousVertex(v)->getId().compare( this->getOppositeVertex(v)->getId()) == 0)
        return t2;

    return nullptr;

}

std::shared_ptr<Triangle> Edge::getOppositeTriangle(std::shared_ptr<Triangle> t)
{
    if(t != nullptr)
    {
        if(t1 != nullptr && t->getId().compare( t1->getId()) == 0)
            return t2;
        if(t2 != nullptr && t->getId().compare( t2->getId()) == 0)
            return t1;
    }
    return nullptr;
}

bool Edge::hasVertex(std::shared_ptr<Vertex>  v)
{
    return ((v1 != nullptr && v1->getId().compare( v->getId()) == 0) ||
            (v2 != nullptr && v2->getId().compare( v->getId())) == 0);
}

bool Edge::hasVertex(Vertex *v)
{
    return ((v1 != nullptr && v1->getId().compare( v->getId()) == 0) ||
            (v2 != nullptr && v2->getId().compare( v->getId())) == 0);
}


std::shared_ptr<Triangle> Edge::getT1() const
{
    return t1;
}

void Edge::setT1(std::shared_ptr<Triangle> newT1)
{
    t1 = newT1;
}

std::shared_ptr<Triangle> Edge::getT2() const
{
    return t2;
}

void Edge::setT2(std::shared_ptr<Triangle> newT2)
{
    t2 = newT2;
}

bool Edge::setTriangle(std::shared_ptr<Triangle> t, std::shared_ptr<Triangle> newT)
{
    if(t != nullptr)
    {
        if(t1 != nullptr && t1->getId().compare(t->getId()) == 0)
        {
            setT1(newT);
            return true;
        } else if (t2 != nullptr && t2->getId().compare(t->getId()) == 0)
        {
            setT2(newT);
            return true;
        }
    }
    return false;
}


bool Edge::addFlag(FlagType f)
{
    if(std::find(associated_flags.begin(), associated_flags.end(), f) == associated_flags.end())
    {
        associated_flags.push_back(f);
        return true;
    }
    return false;
}

int Edge::searchFlag(FlagType f)
{
    std::vector<FlagType>::iterator it = std::find(associated_flags.begin(), associated_flags.end(), f);
    if(it != associated_flags.end())
        return it - associated_flags.begin();
    return -1;
}

bool Edge::removeFlag(FlagType f)
{
    int flagPosition = searchFlag(f);
    if(flagPosition >= 0)
    {
        associated_flags.erase(associated_flags.begin() + flagPosition);
        return true;
    }
    return false;

}

bool Edge::removeFlag(unsigned int position)
{
    if(position < associated_flags.size())
    {
        associated_flags.erase(associated_flags.begin() + position);
        return true;
    }
    return false;

}

bool Edge::addInformation(void *info)
{
    if(std::find(information.begin(), information.end(), info) == information.end())
    {
        information.push_back(info);
        return true;
    }
    return false;
}


int Edge::searchInfo(void * info)
{
    std::vector<void*>::iterator it = std::find(information.begin(), information.end(), info);
    if(it != information.end())
        return  it - information.begin();
    return -1;
}

bool Edge::removeInfo(void *info)
{
    int flagPosition = searchInfo(info);
    if(flagPosition >= 0)
    {
        information.erase(information.begin() + flagPosition);
        return true;
    }
    return false;
}

bool Edge::removeInfo(unsigned int position)
{
    if(position < information.size())
    {
        information.erase(information.begin() + position);
        return true;
    }
    return false;
}

bool Edge::clearInfo()
{
    information.clear();
    return true;
}

std::string Edge::getId() const
{
    return id;
}

void Edge::setId(std::string newId)
{
    id = newId;
}

double Edge::computeLength() const
{
    return ((*v1) - (*v2)).norm();
}

void Edge::collapse()
{
    if(this->getId().compare("114") == 0)
        std::cout << "a";

    auto vv1 = this->getV1()->getVV();
    auto vv2 = this->getV2()->getVV();
    uint counter = 0;
    for(auto v : vv1)
    {
        auto it = std::find_if(vv2.begin(), vv2.end(), [v](std::shared_ptr<Vertex> v_){ return v->getId().compare(v_->getId()) == 0; });
        if(it != vv2.end())
            counter++;
    }
    if(counter != 2)
        return;


    auto point = (*this->getV1() + *this->getV2()) / 2;
    auto lt = this->getLeftTriangle(this->getV1());
    auto rt = this->getRightTriangle(this->getV1());
    auto vl = lt->getNextVertex(this->getV2());
    auto vr = rt->getNextVertex(this->getV1());
    auto e1 = this->getV2()->getCommonEdge(vl);
    auto e2 = this->getV1()->getCommonEdge(vl);
    auto e3 = this->getV2()->getCommonEdge(vr);
    auto e4 = this->getV1()->getCommonEdge(vr);
    auto e1ot = e1->getOppositeTriangle(lt);
    auto e2ot = e2->getOppositeTriangle(lt);
    auto e3ot = e3->getOppositeTriangle(rt);
    auto e4ot = e4->getOppositeTriangle(rt);
    auto vt1 = this->getV1()->getVT();
    auto vt2 = this->getV2()->getVT();
    std::map<std::shared_ptr<Triangle>, SemantisedTriangleMesh::Point> normals;
    for(auto t : vt1)
        if(normals.find(t) == normals.end())
            normals.insert(std::make_pair(t, t->computeNormal()));

    for(auto t : vt2)
        if(normals.find(t) == normals.end())
            normals.insert(std::make_pair(t, t->computeNormal()));

    auto ve = v2->getVE();
    for(auto e_ : ve)
        if(e_->getId().compare(this->getId()) != 0)
            e_->setVertex(this->getV2(), this->getV1());
    if(e1ot != nullptr)
        e1ot->setEdge(e1, e2);
    if(e3ot != nullptr)
        e3ot->setEdge(e3, e4);
    e2->setTriangle(lt, e1ot);
    e4->setTriangle(rt, e3ot);
    auto v1olde0 = this->getV1()->getE0();
    auto vlolde0 = vl->getE0();
    auto vrolde0 = vr->getE0();
    this->getV1()->setE0(e2);
    vl->setE0(e2);
    vr->setE0(e4);
    //this->getV1()->setPosition(point);

    bool triangleFlipped = false;

    for(auto it = normals.begin(); it != normals.end(); it++)
    {
        auto t = it->first;
        auto newNormal = t->computeNormal() ;
        if(newNormal * it->second <= 0)
        {
            triangleFlipped = true;
            break;
        }
    }

    if(triangleFlipped)
    {
        vr->setE0(vrolde0);
        vl->setE0(vlolde0);
        this->getV1()->setE0(v1olde0);
        e4->setTriangle(e3ot, rt);
        e2->setTriangle(e1ot, lt);
        if(e3ot != nullptr)
            e3ot->setEdge(e4, e3);
        if(e1ot != nullptr)
            e1ot->setEdge(e2,e1);
        for(auto e_ : ve)
            if(e_->getId().compare(this->getId()) != 0)
            {
                e_->setVertex(this->getV1(), this->getV2());
            }
    } else
    {
        this->getV2()->addFlag(FlagType::TO_BE_REMOVED);
        this->addFlag(FlagType::TO_BE_REMOVED);
        e1->addFlag(FlagType::TO_BE_REMOVED);
        e3->addFlag(FlagType::TO_BE_REMOVED);
        lt->addFlag(FlagType::TO_BE_REMOVED);
        rt->addFlag(FlagType::TO_BE_REMOVED);
    }

}

void Edge::print(std::ostream &stream)
{
    stream << "Edge with id: " << id << " connecting vertices with ids: " << v1->getId() << " and " << v2->getId()<< ". Incident triangles have ids: "  << std::endl;
    if(t1 != nullptr)
        stream << t1->getId();
    else
        stream << "not available";
    stream << " and ";
    if(t2 != nullptr)
        stream << t2->getId();
    else
        stream << "not available";
    stream << std::endl;
}
