//
// Created by ligas on 06.06.2023.
//

#ifndef ARKANOID_BLOCK_H
#define ARKANOID_BLOCK_H
#include <SFML/Graphics.hpp>
#include "Colission.h"


class Block : public sf::Drawable{
public:
    Block(float rx, float ry);

    void setCollisionColor();
    void setNoCollisionColor();
    sf::Vector2f getPosition();
    Colission::rectangle getVertices();

private:
    void draw(sf::RenderTarget& target, sf::RenderStates state) const override;
    sf::RectangleShape shape;
    const float blockWidth {100.f};
    const float blockHeight{50.f};


};


#endif //ARKANOID_BLOCK_H
