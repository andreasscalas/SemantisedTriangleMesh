#ifndef POINT_H
#define POINT_H

#include <limits>
#include <math.h>
#include <iostream>
#include <memory>
#include <vector>
#include <eigen3/Eigen/Dense>


namespace SemantisedTriangleMesh {
    enum class BracketsType
    {
        ROUND,
        SQUARE,
        NONE
    };

    class Point
    {
    public:

        static constexpr double EPSILON = 1e-10;
        Point(){
            x = std::numeric_limits<double>::max();
            y = std::numeric_limits<double>::max();
            z = std::numeric_limits<double>::max();
            info = nullptr;
        }

        Point(double x, double y, double z){
            this->x = x;
            this->y = y;
            this->z = z;
            info = nullptr;
        }


        double norm() { return std::sqrt(x * x + y * y + z * z); }
        void normalise() { return (*this) /= norm(); }
        std::pair<Point*, Point*> compute2OrthogonalVersors()
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

            return std::make_pair(v1, v2);
        }

        virtual void print(std::ostream &stream, BracketsType brackets_type = BracketsType::ROUND, std::string separator = ",") {
            stream.precision(15);
            std::string opening_bracket;
            std::string closing_bracket;
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

            stream << opening_bracket << x << separator << y << separator << z << closing_bracket << std::endl;
        }

        inline void setPosition(Point p)
        {
            this->x = p.getX();
            this->y = p.getY();
            this->z = p.getZ();
        }

        inline double getX() const { return x; }
        inline void setX(double newX){ x = newX; }
        inline double getY() const { return y; }
        inline void setY(double newY) { y = newY; }
        inline double getZ() const { return z; }
        inline void setZ(double newZ) { z = newZ; }


        inline bool operator==(const Point other) const
        {
            return ((*this) - other).norm() < EPSILON;
        }

        inline bool operator==(const double* doublePoint) const
        {
            Point p(this->getX() - doublePoint[0], this->getY() - doublePoint[1], this->getZ() - doublePoint[2]);
            return p.norm() < EPSILON;
        }

        inline bool operator!=(const Point other) const
        {
            return !(*this==other);
        }

        inline Point operator+(const Point other) const
        {
            return Point(x + other.getX(), y + other.getY(), z + other.getZ());
        }

        inline void operator+=(const Point other)
        {
            this->x = x + other.getX();
            this->y = y + other.getY();
            this->z = z + other.getZ();
        }

        inline Point operator-(const Point other) const
        {
            return Point(x - other.getX(), y - other.getY(), z - other.getZ());
        }

        inline void operator-=(const Point other)
        {
            this->x = x - other.getX();
            this->y = y - other.getY();
            this->z = z - other.getZ();
        }

        inline double operator*(const Point other) const
        {
            return x * other.getX() + y * other.getY() + z * other.getZ();
        }

        inline Point operator*(const double val) const
        {
            return Point(x * val, y * val, z * val);
        }

        inline void operator*=(const double val)
        {
            x = x * val;
            y = y * val;
            z = z * val;
        }

        inline Point operator&(const Point other) const
        {
            return Point(y * other.z - z * other.getY(), z * other.getX() - x * other.z, x * other.getY() - y * other.getX());
        }

        inline void operator&=(const Point other)
        {
            this->x = y * other.z - z * other.getY();
            this->y = z * other.getX() - x * other.z;
            this->z = x * other.getY() - y * other.getX();
        }

        inline Point operator/(const double val) const
        {
            return Point(x / val, y / val, z / val);
        }

        inline void operator/=(const double val)
        {
            x = x / val;
            y = y / val;
            z = z / val;
        }

        inline void operator=(const Point other)
        {
            this->x = other.getX();
            this->y = other.getY();
            this->z = other.getZ();
            this->info = other.getInfo();
        }

        inline double* toDoubleArray() const
        {
            double* doublePoint = new double(3);
            doublePoint[0] = x;
            doublePoint[1] = y;
            doublePoint[2] = z;
            return doublePoint;
        }

        /**
         * @brief computeAngle compute angle between vectors (this and p)
         * @param p the second vector
         * @return the value of the angle between the two vectors
         */
        inline double computeAngle(Point p)
        {
            double angle;
            angle = atan2(((*this) & p).norm(), (*this) * p);
            return angle;
        }

        inline double distanceFromLine(const Point A, const Point B) const
        {
            Point BA = B - A;
            double ba_length = BA.norm();

            if (ba_length == 0.0) std::cerr << "distanceFromLine : Degenerate line passed !" << std::endl;

            return ((((*this) - A) & BA).norm()) / (ba_length);
        }

        inline double computePointSegmentDistance(const Point A, const Point B) const
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

        inline Point computeProjectionOnLine(Point p1, Point p2)
        {
            Point n = p2 - p1;
            n /= n.norm();
            Point v = (*this) - p1;
            return p1 + n * (v * n);

        }

        inline double computePointPlaneDistance(Point origin, Point normal)
        {
            Point po = (*this) - origin;
            return po * normal;
        }



        inline bool isInSegment(Point a, Point b)
        {
            double l = (b - a).norm();
            double l1 = (*this - a).norm();
            double l2 = (b - *this).norm();
            double w1 = l1 / l;
            double w2 = l2 / l;

            return w1 + w2 <= 1.0 + 1e-5;
        }

        inline void *getInfo() const
        {
            return info;
        }

        inline void setInfo(void *value)
        {
            info = value;
        }

        /**
         * @brief orientation checks if the three points define a left or right turn or rather are collinear
         * @param p first point
         * @param q second point
         * @param r third point
         * @return -1 if it is a left turn, 0 if the points are collinear, 1 if it is a right turn
         */
        static inline int orientation(Point p, Point q, Point r)
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


        static inline std::pair<std::shared_ptr<Point>, std::shared_ptr<Point>> findExtremePoints(std::vector<std::shared_ptr<Point> > points, Point direction)
        {
            double min = std::numeric_limits<double>::max(), max = -std::numeric_limits<double>::max();
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

            return std::make_pair(points[minPos], points[maxPos]);
        }

    protected:
        double x;
        double y;
        double z;
        void* info; //AAAAAARGH IL RITORNO

    };

    typedef Point Vector;
}
#endif // POINT_H
