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


bool Colission::isColliding(const Vertices &vertices, const Circle &circle) {
    for (int i = 0; i < 4; i++) {//TODO: for vertices.size
        const sf::Vector2f &p1 = vertices[i];
        const sf::Vector2f &p2 = vertices[(i + 1 % 4)];
        const sf::Vector2f r_axis = normalVector(p1, p2);
        const sf::Vector2f c_axis = circleAxis(circle, closestVertice(vertices, circle));

        float min1, min2, max1, max2;
        projectVertices(vertices, r_axis, min1, min2);
        circleProjection(circle, r_axis, min2, max2);
        projectVertices(vertices, c_axis, min1, min2);
        circleProjection(circle, c_axis, min2, max2);

        if (!Overlap(min1, max1, min2, max2)) {
            return false;
        }


    }
}


sf::Vector2f Colission::closestVertice(const Vertices &vertices, const Circle &circle) {

    sf::Vector2f closest_vertice = vertices[0];
    float closest_distance = std::sqrt(std::pow((circle.center.x - closest_vertice.x), 2.f) +
                                       std::pow((circle.center.y - closest_vertice.y), 2.f));
    for (int i = 1; i < 4; i++) {
        float distance = std::sqrt(std::pow((circle.center.x - vertices[i].x), 2.f) +
                                   std::pow((circle.center.y - vertices[i].y), 2.f));
        if (distance < closest_distance) {
            closest_distance = distance;
            closest_vertice = vertices[i];
        }
    }
    return closest_vertice;

}


void Colission::projectVertices(const Vertices &vertices, const sf::Vector2f &r_axis, float &min, float &max) {


    min = max = r_axis.x * vertices[0].x + r_axis.y * vertices[0].y;
    for (int i = 1; i < 4; i++) {
        const float project = r_axis.x * vertices[i].x + r_axis.y * vertices[i].y;
        if (min > project) min = project;
        if (max < project) max = project;

    }


}


void Colission::circleProjection(const Circle &circle, const sf::Vector2f &axis, float &min, float &max) {
    const float project = circle.center.x * axis.x + circle.center.y * axis.y;
    min = project - circle.radius;
    max = project + circle.radius;
}

sf::Vector2f Colission::circleAxis(const Circle &circle, const sf::Vector2f &closest_vertice) {
    float axis_coordinate_x = circle.center.x - closest_vertice.x;
    float axis_coordinate_y = circle.center.y - closest_vertice.y;
    return {axis_coordinate_x, axis_coordinate_y};

}

bool Colission::Overlap(float min1, float max1, float min2, float max2) {
    return (max1 >= min2) && (max2 >= min1);

}
