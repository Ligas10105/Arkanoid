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



