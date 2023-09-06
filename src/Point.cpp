#include "Point.hpp"
using namespace SemantisedTriangleMesh;
using namespace std;

Point::Point(){
    x = numeric_limits<double>::max();
    y = numeric_limits<double>::max();
    z = numeric_limits<double>::max();
    info = nullptr;
}

Point::~Point()
{

}

Point::Point(const Point &other)
{
    this->x = other.getX();
    this->y = other.getY();
    this->z = other.getZ();
    this->info = other.getInfo();
}

Point::Point(const double x, const double y, const double z){
    this->x = x;
    this->y = y;
    this->z = z;
    info = nullptr;
}

double Point::norm() { return sqrt(x * x + y * y + z * z); }

void Point::normalise() { return (*this) /= norm(); }

pair<Point *, Point *> Point::compute2OrthogonalVersors() const
{
    Point* v1 = new Point();
    double value1 = rand(), value2 = rand();
    if(abs(this->x) > 1e-6)
    {
        v1->x = (-value1 * this->y - value2 * this->z) / this->x;
        v1->y = value1;
        v1->z = value2;
    } else if (abs(this->y) > 1e-6)
    {
        v1->x = value1;
        v1->y = (-value1 * this->x - value2 * this->z) / this->y;
        v1->z = value2;
    } else if (abs(this->z) > 1e-6)
    {
        v1->x = value1;
        v1->y = value2;
        v1->z = (-value1 * this->x - value2 * this->y) / this->z;
    } else
    {
        v1->x = rand();
        v1->y = value1;
        v1->z = value2;
    }

    v1->normalise();

    Point* v2 = new Point((*this) & (*v1));
    v2->normalise();

    return make_pair(v1, v2);
}

void Point::print(ostream &stream, const BracketsType &brackets_type, const string &separator) const
{
    stream.precision(15);
    string opening_bracket;
    string closing_bracket;
    switch(brackets_type)
    {
    case BracketsType::ROUND:
    {
        opening_bracket = "(";
        closing_bracket = ")";
        break;
    }
    case BracketsType::SQUARE:
    {
        opening_bracket = "[";
        closing_bracket = "]";
        break;
    }
    case BracketsType::NONE:
    {
        opening_bracket = "";
        closing_bracket = "";
        break;
    }
    }

    stream << opening_bracket << x << separator << y << separator << z << closing_bracket << endl;
}

void Point::setPosition(const Point &p)
{
    this->x = p.getX();
    this->y = p.getY();
    this->z = p.getZ();
}

double Point::getX() const { return x; }

void Point::setX(const double &newX){ x = newX; }

double Point::getY() const { return y; }

void Point::setY(const double &newY) { y = newY; }

double Point::getZ() const { return z; }

void Point::setZ(const double &newZ) { z = newZ; }

bool Point::operator==(const Point &other) const
{
    return ((*this) - other).norm() < EPSILON;
}

bool Point::operator==(const double* doublePoint) const
{
    Point p(this->getX() - doublePoint[0], this->getY() - doublePoint[1], this->getZ() - doublePoint[2]);
    return p.norm() < EPSILON;
}

bool Point::operator!=(const Point &other) const
{
    return !(*this==other);
}

Point Point::operator+(const Point &other) const
{
    return Point(x + other.getX(), y + other.getY(), z + other.getZ());
}

void Point::operator+=(const Point &other)
{
    this->x = x + other.getX();
    this->y = y + other.getY();
    this->z = z + other.getZ();
}

Point Point::operator-(const Point &other) const
{
    return Point(x - other.getX(), y - other.getY(), z - other.getZ());
}

void Point::operator-=(const Point &other)
{
    this->x = x - other.getX();
    this->y = y - other.getY();
    this->z = z - other.getZ();
}

double Point::operator*(const Point &val) const
{
    return x * val.getX() + y * val.getY() + z * val.getZ();
}

Point Point::operator*(const double val) const
{
    return Point(x * val, y * val, z * val);
}

void Point::operator*=(const double val)
{
    x = x * val;
    y = y * val;
    z = z * val;
}

Point Point::operator&(const Point &other) const
{
    return Point(y * other.z - z * other.getY(), z * other.getX() - x * other.z, x * other.getY() - y * other.getX());
}

void Point::operator&=(const Point &other)
{
    this->x = y * other.z - z * other.getY();
    this->y = z * other.getX() - x * other.z;
    this->z = x * other.getY() - y * other.getX();
}

Point Point::operator/(const double val) const
{
    return Point(x / val, y / val, z / val);
}

void Point::operator/=(const double val)
{
    x = x / val;
    y = y / val;
    z = z / val;
}

void Point::operator=(const Point &other)
{
    this->x = other.getX();
    this->y = other.getY();
    this->z = other.getZ();
    this->info = other.getInfo();
}

double *Point::toDoubleArray() const
{
    double* doublePoint = new double(3);
    doublePoint[0] = x;
    doublePoint[1] = y;
    doublePoint[2] = z;
    return doublePoint;
}

double Point::computeAngle(const Point &p) const
{
    double angle;
    angle = atan2(((*this) & p).norm(), (*this) * p);
    return angle;
}

double Point::distanceFromLine(const Point A, const Point B) const
{
    Point BA = B - A;
    double ba_length = BA.norm();

    if (ba_length == 0.0) cerr << "distanceFromLine : Degenerate line passed !" << endl;

    return ((((*this) - A) & BA).norm()) / (ba_length);
}

double Point::computePointSegmentDistance(const Point &A, const Point &B) const
{
    Point p(this->getX(), this->getY(), this->getZ());
    Point AP = (A) - p;
    Point BP = (B) - p;
    double ap_length = AP.norm();
    double bp_length = BP.norm();

    if (ap_length == 0 || bp_length == 0.0) return 0.0;

    Point AB = (A) - (B);
    double ab_length = AP.norm();
    Point BA = (B) - (A);

    if (ab_length * ap_length == 0.0 || ab_length * bp_length == 0.0) return ap_length;

    if (AB.computeAngle(AP) > M_PI / 2.0) return ap_length;
    else if (BA.computeAngle(BP) > M_PI / 2.0) return bp_length;

    return distanceFromLine(A,B);
}

Point Point::computeProjectionOnLine(const Point& p1, const Point& p2)
{
    Point n = p2 - p1;
    n /= n.norm();
    Point v = (*this) - p1;
    return p1 + n * (v * n);

}

double Point::computePointPlaneDistance(const Point &origin, const Point &normal)
{
    Point po = (*this) - origin;
    return po * normal;
}

bool Point::isInSegment(const Point &a, const Point &b)
{
    double l = (b - a).norm();
    double l1 = (*this - a).norm();
    double l2 = (b - *this).norm();
    double w1 = l1 / l;
    double w2 = l2 / l;

    return w1 + w2 <= 1.0 + 1e-5;
}

void *Point::getInfo() const
{
    return info;
}

void Point::setInfo(void *value)
{
    info = value;
}

int Point::orientation(const Point &p, const Point &q, const Point &r)
{
    Point pq = q - p;
    Point pr = r - p;
    Eigen::Matrix2d matrix;
    matrix << pq.getX(), pr.getX(),
        pq.getY(), pr.getY();
    if(matrix.determinant() < 0)
        return 1;
    if(matrix.determinant() > 0)
        return -1;
    return 0;
}

static pair<shared_ptr<Point>, shared_ptr<Point>> findExtremePoints(const vector<shared_ptr<Point> >& points, const Point& direction)
{
    double min = numeric_limits<double>::max(), max = -numeric_limits<double>::max();
    int minPos = -1, maxPos = -1;
    for(unsigned int i = 0; i < points.size(); i++)
    {
        Point projected = direction * ((*points[i]) * direction);
        double length = projected.norm();
        if(projected * direction < 0 )
            length *= -1;
        if(length > max)
        {
            max = length;
            maxPos = i;
        }
        if(length < min)
        {
            min = length;
            minPos = i;
        }

    }

    return make_pair(points[minPos], points[maxPos]);
}
