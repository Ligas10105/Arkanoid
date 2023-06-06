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
    return {-edge_vertice_y, edge_vertice_x};
}

bool Colission::isColliding(const Colission::Rectangle &shape, const Colission::Circle &circle) {

}
