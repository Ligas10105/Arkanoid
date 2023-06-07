//
// Created by ligas on 06.06.2023.
//
#include "Colission.h"
#include "Ball.h"
#include "Block.h"
#include <cmath>

sf::Vector2f Colission::normalVector(const sf::Vector2f &p1, const sf::Vector2f &p2) {
    float edge_vertice_x = p2.x - p1.x;
    float edge_vertice_y = p2.y - p1.y;
    sf::Vector2f axis = {-edge_vertice_y, edge_vertice_x};
    return axis;
}


bool Colission::isColliding(const Colission::Shape &shape1, const Colission::Shape &shape2) {

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

sf::Vector2f Colission::circleAxis(const sf::Vector2f &closest_vertice, const Shape &circle) {
    float circle_axis_x = closest_vertice.x - circle.center.x;
    float circle_axis_y = closest_vertice.y - circle.center.y;
    return {circle_axis_x, circle_axis_y};
}

void Colission::projectVertices(const Colission::Shape &shape, const sf::Vector2f &axis, sf::Vector2f &circle_axis,
                                float min, float max) {

    if (shape.type == "Rectangle") {
        min = max = axis.x * shape.vertices[0].x + axis.y * shape.vertices[0].y;
        for (int i = 1; i < 4; i++) {
            const float project = axis.x * shape.vertices[i].x + axis.y * shape.vertices[i].y;
            if (min > project) min = project;
            if (max < project) max = project;
        }

    } else if (shape.type == "Circle") {
        min = max = circle_axis.x * shape.vertices[0].x + circle_axis.y * shape.vertices[0].y;

    }

}
