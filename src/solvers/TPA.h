#pragma once

#include "structures/Array.h"
#include "structures/Vector2.h"
#include <cmath>


/*
Try find the shortest path passing by a specific set point
*/


// This class is a point
class Point : public Vector2<float> {
    public:
        uint16_t index;

        Point(Vector2<float> coord, uint16_t index = 0) : Vector2(coord.x, coord.y), index(index) {}
};


// A set of points (automatically set the 'index' member of a point when added)
class Points {
    private:
        Array<Point> points;

    public:
        Points(size_t nb_points) : points(nb_points) {}

        inline Point& add(Vector2<float> point) {
            points.add(Point(point, points.length()));
            return points.getLast();
        }
};


// This class store for each point the distance to each other points
class PointsMap {
    private:
        float* lengths;
        const size_t nb_points;
        const size_t total_len;


    public:
        PointsMap(size_t nb_points) : nb_points(nb_points), total_len(nb_points*nb_points) {
            lengths = new float[total_len];
            for (size_t i = total_len; i--; )
                lengths[i] = NAN;
        }

        inline void set(Point& p1, Point& p2, float length) {
            lengths[p1.index * nb_points + p2.index] = length;
        }

        inline float get(Point& p1, Point& p2) {
            return lengths[p1.index * nb_points + p2.index];
        }
};


// This class store a path with a set of points
class Path {
    private:
        float length;
        Array<Point> points;


    public:
        Path(size_t nb_points) : length(0), points(nb_points) {}

        inline void add(Point& point) {
            points.add(point);
        }
};


Path tpaSolveNearest(PointsMap& map, Point start, Point end) {
    
}


Path tpaSolveBruteForce(PointsMap& map) {
    
}


Path tpaSolveSmart(PointsMap& map) {
    
}
