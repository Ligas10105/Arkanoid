//
// Created by ligas on 06.06.2023.
//
#include "Colission.h"
#include "Ball.h"
#include <cmath>

sf::Vector2f Colission::normalVector(const sf::Vector2f &p1, const sf::Vector2f &p2) {
    float edge_vertice_x = p2.x - p1.x;
    float edge_vertice_y = p2.y - p1.y;
    sf::Vector2f axis = {-edge_vertice_y, edge_vertice_x};
    return axis;
}


bool Colission::isColliding(const Colission::Shape &shape1, const Colission::Shape &shape2) {
    for (int i = 0; i < 4; i++) {
        const sf::Vector2f &p1 = shape1.vertices[i];
        const sf::Vector2f &p2 = shape1.vertices[(i + 1 % 4)];
        const sf::Vector2f r_axis = normalVector(p1, p2);
        const sf::Vector2f c_axis = circleAxis(shape2, closestVertice(shape1, shape2));

        float min1, min2, max1, max2;
        projectVertices(shape1, r_axis, min1, min2);
        circleProjection(shape2, r_axis, min2, max2);
        projectVertices(shape1, c_axis, min1, min2);
        circleProjection(shape2, c_axis, min2, max2);

        if (!Overlap(min1, max1, min2, max2)) {
            return false;
        }


    }
}


sf::Vector2f Colission::closestVertice(const Colission::Shape &rectangle, const Colission::Shape &circle) {

    sf::Vector2f closest_vertice = rectangle.vertices[0];
    float closest_distance = std::sqrt(std::pow((circle.center.x - closest_vertice.x), 2) +
                                       std::pow((circle.center.y - closest_vertice.y), 2));
    for (int i = 1; i < 4; i++) {
        float distance = std::sqrt(std::pow((circle.center.x - rectangle.vertices[i].x), 2) +
                                   std::pow((circle.center.y - rectangle.vertices[i].y), 2));
        if (distance < closest_distance) {
            closest_distance = distance;
            closest_vertice = rectangle.vertices[i];
        }
    }
    return closest_vertice;

}


void Colission::projectVertices(const Colission::Shape &shape, const sf::Vector2f &r_axis, float &min, float &max) {


    min = max = r_axis.x * shape.vertices[0].x + r_axis.y * shape.vertices[0].y;
    for (int i = 1; i < 4; i++) {
        const float project = r_axis.x * shape.vertices[i].x + r_axis.y * shape.vertices[i].y;
        if (min > project) min = project;
        if (max < project) max = project;

    }


}


void Colission::circleProjection(const Colission::Shape &circle, const sf::Vector2f &axis, float &min, float &max) {
    const float project = circle.center.x * axis.x + circle.center.y * axis.y;
    min = project + circle.radius;
    max = project + circle.radius;
}

sf::Vector2f Colission::circleAxis(const Colission::Shape &circle, const sf::Vector2f &closest_vertice) {
    float axis_coordinate_x = circle.center.x - closest_vertice.x;
    float axis_coordinate_y = circle.center.y - closest_vertice.y;
    return {axis_coordinate_x, axis_coordinate_y};

}

bool Colission::Overlap(float min1, float max1, float min2, float max2) {
    return (max1 >= min2) && (max2 >= min1);

}
