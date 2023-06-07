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
       std::string type;
       sf::Vector2f center;
       float radius;
       std::vector<sf::Vector2f> vertices;

   };
    sf::Vector2f normalVector(const sf::Vector2f &p1, const sf::Vector2f &p2);

    void projectVertices(const Shape &shape, const sf::Vector2f &axis, sf::Vector2f &circle_axis, float min, float max);

    static bool isColliding(const Shape &shape1, const Shape &shape2);

    sf::Vector2f closestVertice(const Shape &rectangle, const Shape &circle);

    sf::Vector2f circleAxis(const sf::Vector2f &closest_vertice, const Shape &circle);




};


#endif //ARKANOID_COLISSION_H
