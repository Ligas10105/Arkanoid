//
// Created by ligas on 06.06.2023.
//

#include "Block.h"


void Block::draw(sf::RenderTarget &target, sf::RenderStates state) const {
    target.draw(this->shape, state);
}

void Block::setCollisionColor() {
    shape.setFillColor(sf::Color::Red);
}

void Block::setNoCollisionColor() {
    shape.setFillColor(sf::Color::White);
}

Colission::Vertices Block::getVertices() {
    return {{x,y },{(x+width), y}, {(x+width),(y+height)}, {x, (y+height)}};
}



