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
    shape.setFillColor(sf::Color::Green);
}

Colission::Vertices Block::getVertices() const{
    return {{x,           y},
            {(x + width), y},
            {(x + width), (y + height)},
            {x,           (y + height)}};
}

void Block::Destroy() {

    auto startTime = std::chrono::high_resolution_clock::now();
    isDestroyed = true;
    auto currentTime = std::chrono::high_resolution_clock::now();
    std::chrono::duration<float> elapsedTime = currentTime - startTime;
    if(elapsedTime.count() > invisibleTime){
        isDestroyed = false;
    }

}




