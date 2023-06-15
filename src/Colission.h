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

    struct Circle {
        sf::Vector2f center;
        float radius;
    };

    using Vertices = std::vector<sf::Vector2f>;

    static sf::Vector2f rectangleAxis(sf::Vector2f &p1, sf::Vector2f &p2);

    static void projectVertices(const Vertices &vertices, const sf::Vector2f &axis, float &min, float &max);

    static bool isColliding(const Vertices &vertices, const Circle &circle);

    static bool Overlap(float min1, float max1, float min2, float max2);

    static sf::Vector2f circleProjection(const Circle &circle,const sf::Vector2f &axis, float &min, float &max);

    static sf::Vector2f circleAxis(const Vertices &rectangle, const Circle &circle);


};


#endif //ARKANOID_COLISSION_H
