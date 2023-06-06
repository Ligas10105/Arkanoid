//
// Created by ligas on 06.06.2023.
//

#include "Block.h"

Block::Block(float rx, float ry) {
    shape.setPosition(rx, ry);
    shape.setSize({blockWidth, blockHeight});
    shape.setFillColor(sf::Color::White);
}

void Block::draw(sf::RenderTarget &target, sf::RenderStates state) const {
    target.draw(this->shape, state);
}

void Block::setCollisionColor() {
    shape.setFillColor(sf::Color::Red);
}

void Block::setNoCollisionColor() {
    shape.setFillColor(sf::Color::White);
}

sf::Vector2f Block ::getPosition() {
    return shape.getPosition();
}

Colission::rectangle Block::getVertices() {
    return
}
