//
// Created by ligas on 06.06.2023.
//

#ifndef ARKANOID_BLOCK_H
#define ARKANOID_BLOCK_H
#include <SFML/Graphics.hpp>
#include "Colission.h"


class Block : public sf::Drawable{

public:
    float rx {};
    float ry {};
    float rw {};
    float rh{};
    Block(float RX, float RY, float RW, float RH) : rx(RX), ry(RY), rw(RW), rh(RH) {
        shape.setPosition(rx, ry);
        shape.setSize({rw, rh});
        shape.setFillColor(sf::Color::White);
    }

    void setCollisionColor();
    void setNoCollisionColor();
    sf::Vector2f getPosition();


private:
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
    sf::RectangleShape shape;
    //const float blockWidth {100.f};
    //const float blockHeight{50.f};


};


#endif //ARKANOID_BLOCK_H
