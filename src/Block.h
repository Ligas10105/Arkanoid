//
// Created by ligas on 06.06.2023.
//

#ifndef ARKANOID_BLOCK_H
#define ARKANOID_BLOCK_H

#include <SFML/Graphics.hpp>
#include "Colission.h"
#include <chrono>


class Block : public sf::Drawable {

public:

    float x{};
    float y{};
    float width{};
    float height{};
    float invisibleTime{5.f};
    bool isDestroyed = false;


    Block(float x, float y, float width, float height) : x(x), y(y), width(width), height(height) {
        shape.setPosition(x, y);
        shape.setSize({width, height});
        shape.setFillColor(sf::Color::White);
    }

    void setCollisionColor();

    void setNoCollisionColor();

    void Destroy();

    Colission::Vertices getVertices() const;


private:
    void draw(sf::RenderTarget &target, sf::RenderStates state) const override;

    sf::RectangleShape shape;


};


#endif //ARKANOID_BLOCK_H
