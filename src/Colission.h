//
// Created by ligas on 06.06.2023.
//

#ifndef ARKANOID_COLISSION_H
#define ARKANOID_COLISSION_H


class Colission {
public:

    struct ball {
        double cx, cy, radius;
    };
    struct rectangle {
        double rx, ry, rw, rh;
    };
    struct test_edges{
        double x, y;
    };
    struct distance{
        double distance_x, distance_y;
    };

    static void whichEdge(const ball &b, const rectangle &rec, test_edges &edg);

    static double getDistance(distance &d, ball &b, test_edges &t_edg);

    static bool isColliding(const ball &b, double distance);
};


#endif //ARKANOID_COLISSION_H
