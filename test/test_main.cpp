//
// Created by ligas on 23.06.2023.
//
#include <gtest/gtest.h>
#include "../src/Colission.h"

TEST(PhysicsTest, NormalVectorTest) {
    sf::Vector2f point1 = {30.f,20.f};
    sf::Vector2f point2 = {50.f, 40.f};
    sf::Vector2f expected_output = {-20.f, 20.f};
    sf::Vector2f output = Colission::rectangleAxis(point1,point2);
    EXPECT_EQ(output, expected_output);
}

