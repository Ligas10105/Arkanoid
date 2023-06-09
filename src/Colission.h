//
// Created by ligas on 06.06.2023.
//

#ifndef ARKANOID_COLISSION_H
#define ARKANOID_COLISSION_H

#include "SFML/Graphics.hpp"
#include <array>
#include <math.h>


class Colission {
public:

    struct Shape {
        sf::Vector2f center;
        float radius;
        std::vector<sf::Vector2f> vertices;
    };

    static sf::Vector2f normalVector(const sf::Vector2f &p1, const sf::Vector2f &p2);

    static void projectVertices(const Shape &shape, const sf::Vector2f &axis, float &min, float &max);

    static bool isColliding(const Shape &shape1, const Shape &shape2);

    static bool Overlap(float min1, float max1, float min2, float max2);

    static sf::Vector2f closestVertice(const Shape &rectangle, const Shape &circle);

    static void circleProjection(const Shape &circle, const sf::Vector2f &axis, float &min, float &max);

    static sf::Vector2f circleAxis(const Colission::Shape &circle, const sf::Vector2f &closest_vertice);


};


#endif //ARKANOID_COLISSION_H
