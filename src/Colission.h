//
// Created by ligas on 06.06.2023.
//

#ifndef ARKANOID_COLISSION_H
#define ARKANOID_COLISSION_H

#include "SFML/Graphics.hpp"
#include <array>


class Colission {
public:

    struct Circle {
        sf::Vector2f center;
        float radius;
    };
    struct Rectangle {
        std::array<sf::Vector2f, 4> vertices;
    };

    sf::Vector2f normalVector(const sf::Vector2f &p1, const sf::Vector2f &p2);

    void projectVertices(const Circle &circle, const Rectangle &rectangle, const sf::Vector2f &axis, float min, float max);

    static bool isColliding(const Rectangle &shape, const Circle &circle);


};


#endif //ARKANOID_COLISSION_H
