//
// Created by ligas on 06.06.2023.
//

#include "Colission.h"
#include <cmath>

void Colission::whichEdge(const ball &b, const rectangle &rec, test_edges &edg) {
    if (b.cx < rec.rx ){
        edg.x = rec.rx;
    }
    else if (b.cx > rec.rx + rec.rw){
        edg.x = rec.rx + rec.rw;
    }
    else if (b.cy < rec.ry){
        edg.y = rec.ry;
    }
    else if (b.cy > rec.ry + rec.rh){
        edg.y = rec.ry + rec.rh;
    }

}

double Colission::getDistance(distance &d, ball &b, test_edges &t_edg) {
    d.distance_x = b.cx - t_edg.x;
    d.distance_y = b.cy - t_edg.y;
    double distance = sqrt(pow(d.distance_x,2) + pow(d.distance_y, 2));
    return distance;
}

bool Colission::isColliding(const ball &b, double distance) {

    return (distance <= b.radius) ? true : false;


}
