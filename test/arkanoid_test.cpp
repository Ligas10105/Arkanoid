//
// Created by ligas on 14.06.2023.
//
#include "../src/Colission.h"
#include "../src/Ball.h"
#include <gtest/gtest.h>



TEST(ArkanoidTest, isColliding){
    Colission::Vertices vertices = {{200.f, 100.f}, {400.f, 100.f}, {400.f, 250.f}, {200.f, 250.f}};
    sf::Vector2f p1 = {vertices.at(0)};
    sf::Vector2f p2 = {vertices.at(1)};

    sf::Vector2f result = Colission::rectangleAxis(vertices,p1,p2);

    EXPECT_FLOAT_EQ(result.x, 200.f);
    EXPECT_FLOAT_EQ(result.y, 0.f);

}

