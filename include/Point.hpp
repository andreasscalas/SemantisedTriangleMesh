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

    /**
     * @class Point
     * @brief Represents a 3D point in space.
     *
     * The Point class represents a 3D point in space with x, y, and z coordinates. It provides various
     * member functions for performing operations on points and vectors, such as normalization, arithmetic,
     * distance calculations, projections, and more.
     */
    class Point
    {
    public:

        static constexpr double EPSILON = 1e-10;
        /**
         * @brief Default constructor for creating an uninitialized Point object.
         */
        inline Point(){
            x = std::numeric_limits<double>::max();
            y = std::numeric_limits<double>::max();
            z = std::numeric_limits<double>::max();
            info = nullptr;
        }

        /**
         * @brief Constructor for creating a Point object with specified x, y, and z coordinates.
         * @param x The x-coordinate of the point.
         * @param y The y-coordinate of the point.
         * @param z The z-coordinate of the point.
         */
        inline Point(double x, double y, double z){
            this->x = x;
            this->y = y;
            this->z = z;
            info = nullptr;
        }

        /**
         * @brief Compute the norm (length) of the point as a vector from the origin.
         * @return The norm of the point.
         */
        inline double norm() { return std::sqrt(x * x + y * y + z * z); }

        /**
         * @brief Normalize the point to have a unit length.
         */
        inline void normalise() { return (*this) /= norm(); }

        /**
         * @brief Compute two orthogonal versors (unit vectors) based on this vector.
         * @return A pair of pointers to Point objects representing the orthogonal versors.
         */
        inline std::pair<Point*, Point*> compute2OrthogonalVersors()
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

        /**
         * @brief Print the point's coordinates to the specified output stream.
         * @param[out] stream The output stream where the point's coordinates will be printed.
         * @param brackets_type The type of brackets to use for enclosing the point's coordinates.
         * @param separator The separator to use between the coordinates when printing.
         */
        inline virtual void print(std::ostream &stream, BracketsType brackets_type = BracketsType::ROUND, std::string separator = ",") {
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

        /**
         * @brief Set the coordinates of the point to match those of another point.
         * @param p The point whose coordinates will be copied to this point.
         */
        inline void setPosition(Point p)
        {
            this->x = p.getX();
            this->y = p.getY();
            this->z = p.getZ();
        }

        /**
         * @brief Get the x-coordinate of the point.
         * @return The x-coordinate of the point.
         */
        inline double getX() const { return x; }
        /**
         * @brief Set the x-coordinate of the point.
         * @param newX The new x-coordinate to set for the point.
         */
        inline void setX(double newX){ x = newX; }
        /**
         * @brief Get the y-coordinate of the point.
         * @return The y-coordinate of the point.
         */
        inline double getY() const { return y; }
        /**
         * @brief Set the y-coordinate of the point.
         * @param newY The new y-coordinate to set for the point.
         */
        inline void setY(double newY) { y = newY; }
        /**
         * @brief Get the z-coordinate of the point.
         * @return The z-coordinate of the point.
         */
        inline double getZ() const { return z; }
        /**
         * @brief Set the z-coordinate of the point.
         * @param newZ The new z-coordinate to set for the point.
         */
        inline void setZ(double newZ) { z = newZ; }

        /**
         * @brief Check if the point is equal to another point.
         * @param other The other point to compare with.
         * @return True if the two points are approximately equal, false otherwise.
         */
        inline bool operator==(const Point other) const
        {
            return ((*this) - other).norm() < EPSILON;
        }

        /**
         * @brief Check if the point is equal to a double array representing a point's coordinates.
         * @param doublePoint A pointer to a double array representing a point's coordinates (x, y, z).
         * @return True if the point is approximately equal to the coordinates in the double array, false otherwise.
         */
        inline bool operator==(const double* doublePoint) const
        {
            Point p(this->getX() - doublePoint[0], this->getY() - doublePoint[1], this->getZ() - doublePoint[2]);
            return p.norm() < EPSILON;
        }

        /**
         * @brief Check if the point is not equal to another point.
         * @param other The other point to compare with.
         * @return True if the two points are not approximately equal, false otherwise.
         */
        inline bool operator!=(const Point other) const
        {
            return !(*this==other);
        }

        /**
         * @brief Add two points together to get a new point.
         * @param other The point to add to this point.
         * @return A new Point object representing the result of the addition.
         */
        inline Point operator+(const Point other) const
        {
            return Point(x + other.getX(), y + other.getY(), z + other.getZ());
        }

        /**
         * @brief Add another point to this point.
         * @param other The point to add to this point.
         */
        inline void operator+=(const Point other)
        {
            this->x = x + other.getX();
            this->y = y + other.getY();
            this->z = z + other.getZ();
        }

        /**
         * @brief Subtract a point from this point to get a new point.
         * @param other The point to subtract from this point.
         * @return A new Point object representing the result of the subtraction.
         */
        inline Point operator-(const Point other) const
        {
            return Point(x - other.getX(), y - other.getY(), z - other.getZ());
        }

        /**
         * @brief Subtract another point from this point.
         * @param other The point to subtract from this point.
         */
        inline void operator-=(const Point other)
        {
            this->x = x - other.getX();
            this->y = y - other.getY();
            this->z = z - other.getZ();
        }

        /**
         * @brief Compute the dot product of two points (as vectors).
         * @param other The other point (vector) to compute the dot product with.
         * @return The dot product of the two points.
         */
        inline double operator*(const Point other) const
        {
            return x * other.getX() + y * other.getY() + z * other.getZ();
        }

        /**
         * @brief Multiply the point by a scalar value to get a new point.
         * @param val The scalar value to multiply the point with.
         * @return A new Point object representing the result of the multiplication.
         */
        inline Point operator*(const double val) const
        {
            return Point(x * val, y * val, z * val);
        }

        /**
         * @brief Multiply the point by a scalar value.
         * @param val The scalar value to multiply the point with.
         */
        inline void operator*=(const double val)
        {
            x = x * val;
            y = y * val;
            z = z * val;
        }

        /**
         * @brief Compute the cross product of two points (as vectors) to get a new point.
         * @param other The other point (vector) to compute the cross product with.
         * @return A new Point object representing the result of the cross product.
         */
        inline Point operator&(const Point other) const
        {
            return Point(y * other.z - z * other.getY(), z * other.getX() - x * other.z, x * other.getY() - y * other.getX());
        }

        /**
         * @brief Compute the cross product of two points (as vectors) and store the result in this point.
         * @param other The other point (vector) to compute the cross product with.
         */
        inline void operator&=(const Point other)
        {
            this->x = y * other.z - z * other.getY();
            this->y = z * other.getX() - x * other.z;
            this->z = x * other.getY() - y * other.getX();
        }

        /**
         * @brief Divide the point by a scalar value to get a new point.
         * @param val The scalar value to divide the point by.
         * @return A new Point object representing the result of the division.
         */
        inline Point operator/(const double val) const
        {
            return Point(x / val, y / val, z / val);
        }

        /**
         * @brief Divide the point by a scalar value.
         * @param val The scalar value to divide the point by.
         */
        inline void operator/=(const double val)
        {
            x = x / val;
            y = y / val;
            z = z / val;
        }

        /**
         * @brief Assign the coordinates of another point to this point.
         * @param other The other point whose coordinates will be copied to this point.
         */
        inline void operator=(const Point other)
        {
            this->x = other.getX();
            this->y = other.getY();
            this->z = other.getZ();
            this->info = other.getInfo();
        }

        /**
         * @brief Convert the point to a double array containing the x, y, and z coordinates.
         * @return A dynamically allocated double array containing the point's coordinates.
         *         The caller is responsible for freeing the memory when done using the array.
         */
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

        /**
         * @brief Compute the distance from this point to a line defined by two other points.
         * @param A The first point defining the line.
         * @param B The second point defining the line.
         * @return The distance from this point to the line defined by points A and B.
         */
        inline double distanceFromLine(const Point A, const Point B) const
        {
            Point BA = B - A;
            double ba_length = BA.norm();

            if (ba_length == 0.0) std::cerr << "distanceFromLine : Degenerate line passed !" << std::endl;

            return ((((*this) - A) & BA).norm()) / (ba_length);
        }

        /**
         * @brief Compute the distance from this point to a line segment defined by two endpoints.
         * @param A The first endpoint of the line segment.
         * @param B The second endpoint of the line segment.
         * @return The distance from this point to the line segment defined by endpoints A and B.
         */
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

        /**
         * @brief Compute the projection of this point on a line defined by two other points.
         * @param p1 The first point defining the line.
         * @param p2 The second point defining the line.
         * @return The projected point on the line.
         */
        inline Point computeProjectionOnLine(Point p1, Point p2)
        {
            Point n = p2 - p1;
            n /= n.norm();
            Point v = (*this) - p1;
            return p1 + n * (v * n);

        }

        /**
         * @brief Compute the signed distance from this point to a plane defined by an origin point and a normal vector.
         * @param origin The origin point of the plane.
         * @param normal The normal vector of the plane.
         * @return The signed distance from this point to the plane.
         */
        inline double computePointPlaneDistance(Point origin, Point normal)
        {
            Point po = (*this) - origin;
            return po * normal;
        }

        /**
         * @brief Check if this point lies within a line segment defined by two endpoints.
         * @param a The first endpoint of the line segment.
         * @param b The second endpoint of the line segment.
         * @return True if this point lies within the line segment, false otherwise.
         */
        inline bool isInSegment(Point a, Point b)
        {
            double l = (b - a).norm();
            double l1 = (*this - a).norm();
            double l2 = (b - *this).norm();
            double w1 = l1 / l;
            double w2 = l2 / l;

            return w1 + w2 <= 1.0 + 1e-5;
        }

        /**
         * @brief Get the additional information associated with the point.
         * @return A pointer to the additional information associated with the point.
         */
        inline void *getInfo() const
        {
            return info;
        }

        /**
         * @brief Set additional information to associate with the point.
         * @param value A pointer to the additional information to be associated with the point.
         */
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

        /**
         * @brief Find the extreme points in a vector of points along a given direction.
         * @param points The vector of points to search for the extreme points.
         * @param direction The direction along which to find the extreme points.
         * @return A pair of shared pointers to the extreme points found (min and max points).
         */
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
