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
        Point();

        virtual ~Point();
        Point(const Point& other);

        /**
         * @brief Constructor for creating a Point object with specified x, y, and z coordinates.
         * @param x The x-coordinate of the point.
         * @param y The y-coordinate of the point.
         * @param z The z-coordinate of the point.
         */
        Point(const double x, const double y, const double z);

        /**
         * @brief Compute the norm (length) of the point as a vector from the origin.
         * @return The norm of the point.
         */
        double norm();

        /**
         * @brief Normalize the point to have a unit length.
         */
        void normalise();

        /**
         * @brief Compute two orthogonal versors (unit vectors) based on this vector.
         * @return A pair of pointers to Point objects representing the orthogonal versors.
         */
        std::pair<Point*, Point*> compute2OrthogonalVersors() const;

        /**
         * @brief Print the point's coordinates to the specified output stream.
         * @param[out] stream The output stream where the point's coordinates will be printed.
         * @param brackets_type The type of brackets to use for enclosing the point's coordinates.
         * @param separator The separator to use between the coordinates when printing.
         */
        virtual void print(std::ostream &stream,
                           const BracketsType& brackets_type = BracketsType::ROUND,
                           const std::string& separator = ",") const;

        /**
         * @brief Set the coordinates of the point to match those of another point.
         * @param p The point whose coordinates will be copied to this point.
         */
        void setPosition(const Point& p);

        /**
         * @brief Get the x-coordinate of the point.
         * @return The x-coordinate of the point.
         */
        double getX() const;
        /**
         * @brief Set the x-coordinate of the point.
         * @param newX The new x-coordinate to set for the point.
         */
        void setX(const double& newX);
        /**
         * @brief Get the y-coordinate of the point.
         * @return The y-coordinate of the point.
         */
        double getY() const;
        /**
         * @brief Set the y-coordinate of the point.
         * @param newY The new y-coordinate to set for the point.
         */
        void setY(const double& newY);
        /**
         * @brief Get the z-coordinate of the point.
         * @return The z-coordinate of the point.
         */
        double getZ() const;
        /**
         * @brief Set the z-coordinate of the point.
         * @param newZ The new z-coordinate to set for the point.
         */
        void setZ(const double& newZ);

        /**
         * @brief Check if the point is equal to another point.
         * @param other The other point to compare with.
         * @return True if the two points are approximately equal, false otherwise.
         */
        bool operator==(const Point& other) const;

        /**
         * @brief Check if the point is equal to a double array representing a point's coordinates.
         * @param doublePoint A pointer to a double array representing a point's coordinates (x, y, z).
         * @return True if the point is approximately equal to the coordinates in the double array, false otherwise.
         */
        bool operator==(const double* doublePoint) const;

        /**
         * @brief Check if the point is not equal to another point.
         * @param other The other point to compare with.
         * @return True if the two points are not approximately equal, false otherwise.
         */
        bool operator!=(const Point& other) const;

        /**
         * @brief Add two points together to get a new point.
         * @param other The point to add to this point.
         * @return A new Point object representing the result of the addition.
         */
        Point operator+(const Point& other) const;

        /**
         * @brief Add another point to this point.
         * @param other The point to add to this point.
         */
        void operator+=(const Point& other);

        /**
         * @brief Subtract a point from this point to get a new point.
         * @param other The point to subtract from this point.
         * @return A new Point object representing the result of the subtraction.
         */
        Point operator-(const Point& other) const;

        /**
         * @brief Subtract another point from this point.
         * @param other The point to subtract from this point.
         */
        void operator-=(const Point& other);

        /**
         * @brief Compute the dot product of two points (as vectors).
         * @param other The other point (vector) to compute the dot product with.
         * @return The dot product of the two points.
         */
        double operator*(const Point& other) const;

        /**
         * @brief Multiply the point by a scalar value to get a new point.
         * @param val The scalar value to multiply the point with.
         * @return A new Point object representing the result of the multiplication.
         */
        Point operator*(const double val) const;

        /**
         * @brief Multiply the point by a scalar value.
         * @param val The scalar value to multiply the point with.
         */
        void operator*=(const double val);

        /**
         * @brief Compute the cross product of two points (as vectors) to get a new point.
         * @param other The other point (vector) to compute the cross product with.
         * @return A new Point object representing the result of the cross product.
         */
        Point operator&(const Point& other) const;

        /**
         * @brief Compute the cross product of two points (as vectors) and store the result in this point.
         * @param other The other point (vector) to compute the cross product with.
         */
        void operator&=(const Point& other);

        /**
         * @brief Divide the point by a scalar value to get a new point.
         * @param val The scalar value to divide the point by.
         * @return A new Point object representing the result of the division.
         */
        Point operator/(const double val) const;

        /**
         * @brief Divide the point by a scalar value.
         * @param val The scalar value to divide the point by.
         */
        void operator/=(const double val);

        /**
         * @brief Assign the coordinates of another point to this point.
         * @param other The other point whose coordinates will be copied to this point.
         */
        void operator=(const Point& other);

        /**
         * @brief Convert the point to a double array containing the x, y, and z coordinates.
         * @return A dynamically allocated double array containing the point's coordinates.
         *         The caller is responsible for freeing the memory when done using the array.
         */
        double* toDoubleArray() const;

        /**
         * @brief computeAngle compute angle between vectors (this and p)
         * @param p the second vector
         * @return the value of the angle between the two vectors
         */
        double computeAngle(const Point& p) const;

        /**
         * @brief Compute the distance from this point to a line defined by two other points.
         * @param a The first point defining the line.
         * @param b The second point defining the line.
         * @return The distance from this point to the line defined by points A and B.
         */
        double distanceFromLine(const Point a, const Point b) const;

        /**
         * @brief Compute the distance from this point to a line segment defined by two endpoints.
         * @param a The first endpoint of the line segment.
         * @param b The second endpoint of the line segment.
         * @return The distance from this point to the line segment defined by endpoints A and B.
         */
        double computePointSegmentDistance(const Point& a, const Point& b) const;

        /**
         * @brief Compute the projection of this point on a line defined by two other points.
         * @param p1 The first point defining the line.
         * @param p2 The second point defining the line.
         * @return The projected point on the line.
         */
        Point computeProjectionOnLine(const Point& p1, const Point& p2);

        /**
         * @brief Compute the signed distance from this point to a plane defined by an origin point and a normal vector.
         * @param origin The origin point of the plane.
         * @param normal The normal vector of the plane.
         * @return The signed distance from this point to the plane.
         */
        double computePointPlaneDistance(const Point& origin, const Point& normal);

        /**
         * @brief Check if this point lies within a line segment defined by two endpoints.
         * @param a The first endpoint of the line segment.
         * @param b The second endpoint of the line segment.
         * @return True if this point lies within the line segment, false otherwise.
         */
        bool isInSegment(const Point& a, const Point& b);

        /**
         * @brief Get the additional information associated with the point.
         * @return A pointer to the additional information associated with the point.
         */
        void *getInfo() const;

        /**
         * @brief Set additional information to associate with the point.
         * @param value A pointer to the additional information to be associated with the point.
         */
        void setInfo(void *value);

        /**
         * @brief orientation checks if the three points define a left or right turn or rather are collinear
         * @param p first point
         * @param q second point
         * @param r third point
         * @return -1 if it is a left turn, 0 if the points are collinear, 1 if it is a right turn
         */
        static int orientation(const Point& p, const Point& q, const Point& r);

        /**
         * @brief Find the extreme points in a vector of points along a given direction.
         * @param points The vector of points to search for the extreme points.
         * @param direction The direction along which to find the extreme points.
         * @return A pair of shared pointers to the extreme points found (min and max points).
         */
        static std::pair<std::shared_ptr<Point>, std::shared_ptr<Point>> findExtremePoints(const std::vector<std::shared_ptr<Point> >& points, const Point& direction);

    protected:
        double x;
        double y;
        double z;
        void* info; //AAAAAARGH IL RITORNO

    };

    typedef Point Vector;




}
#endif // POINT_H
