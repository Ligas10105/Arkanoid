//
// Created by ligas on 06.06.2023.
//
#include "Colission.h"
#include "Ball.h"
#include <cmath>

sf::Vector2f Colission::rectangleAxis(sf::Vector2f &p1, sf::Vector2f &p2) {

    float edge_vertice_x = p2.x - p1.x;
    float edge_vertice_y = p2.y - p1.y;
    sf::Vector2f axis = {-edge_vertice_y, edge_vertice_x};
    return axis;

}


bool Colission::isColliding(const Vertices &vertices, const Circle &circle) {
    sf::Vector2f p1;
    sf::Vector2f p2;
    sf::Vector2f r_axis;
    float min1, min2, max1, max2;
    for (int i = 0; i < vertices.size(); i++) {
        p1 = vertices[0];
        p2 = vertices[(i + 1) % vertices.size()];
        sf::Vector2f axis = rectangleAxis(p1, p2);
        projectVertices(vertices, axis, min1, max1);
        circleProjection(circle, axis, min2, max2);
        if (!Overlap(min1, max1, min2, max2)) {
            return false;
        }
    }
    projectVertices(vertices, circleAxis(vertices, circle), min1, max1);
    circleProjection(circle, circleAxis(vertices, circle), min2, max2);
    if (!Overlap(min1, max1, min2, max2)) {
        return false;
    }

    return true;
}


sf::Vector2f Colission::circleAxis(const Vertices &vertices, const Circle &circle) {
    sf::Vector2f closest_vertice {};
    sf::Vector2f circle_axis{};
    float closest_distance = std::numeric_limits<float>::max();
    for (int i = 0; i < vertices.size(); i++) {
        float distance = std::sqrt((circle.center - vertices[i]).x * (circle.center - vertices[i]).x +
                                   (circle.center - vertices[i]).y * (circle.center - vertices[i]).y);
        if (distance < closest_distance) {
            closest_distance = distance;
            closest_vertice = vertices.at(i);
            circle_axis = (circle.center - closest_vertice);
        }

    }

    return circle_axis;
}


void Colission::projectVertices(const Vertices &vertices, const sf::Vector2f &axis, float &min, float &max) {

    min = max = axis.x * vertices.at(0).x + axis.y * vertices.at(0).y;
    for (int i = 1; i < 4; i++) {
        const float project = axis.x * vertices[i].x + axis.y * vertices[i].y;
        if (min > project) min = project;
        if (max < project) max = project;
    }


}


sf::Vector2f Colission::circleProjection(const Circle &circle, const sf::Vector2f &axis, float &min, float &max) {


    min = (circle.center.x * axis.x + circle.center.y * axis.y) - circle.radius;
    max = (circle.center.x * axis.x + circle.center.y * axis.y) + circle.radius;

    return {min, max};

}


bool Colission::Overlap(float min1, float max1, float min2, float max2) {
    return (max1 >= min2) && (max2 >= min1);
}