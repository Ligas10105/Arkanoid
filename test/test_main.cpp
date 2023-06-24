//
// Created by ligas on 23.06.2023.
//
#include <gtest/gtest.h>
#include "../src/Colission.h"

TEST(PhysicsTest, NormalVectorTest) {
    sf::Vector2f point1 = {400.f, 100.f};
    sf::Vector2f point2 = {400.f, 250.f};
    sf::Vector2f expected_output = {-1.f, 0};
    sf::Vector2f output = Colission::rectangleAxis(point1, point2);
    EXPECT_EQ(output, expected_output);
}

TEST(PhysicsTest, ClosestVerticeTest) {
    Colission::Vertices rectangle_vertices = {{200.f, 100.f},
                                              {400,   100},
                                              {200,   350},
                                              {400,   350}};
    Colission::Circle center = {{100.f, 100.f}, 30.f};
    sf::Vector2f expected_output = {-1.f, 0};
    sf::Vector2f output = Colission::circleAxis(rectangle_vertices, center);
    EXPECT_EQ(output, expected_output);
}

TEST(PhysicsTest, ProjectRectanglevertice) {
    float min{};
    float max{};
    Colission::Vertices rectangle_vertices = {{200.f, 100.f},
                                              {400,   100},
                                              {200,   350},
                                              {400,   350}};
    sf::Vector2f axis = {0, 200.f};
    Colission::projectVertices(rectangle_vertices, axis, min, max);
    sf::Vector2f expected_output = {20000, 70000};
    sf::Vector2f output = {min, max};
    EXPECT_EQ(output, expected_output);
}

TEST(PhysicsTest, CircleProjectionTest) {
    sf::Vector2f axis = {-1.f, 0};
    Colission::Circle center = {{199.f, 200.f}, 30.f};
    std::pair<float, float> expected_output = {-229.f, -169.f};
    const auto output = Colission::circleProjection(center, axis);
    EXPECT_EQ(expected_output, output);
}

TEST(PhysicsTest, isCollidingTest) {
    Colission::Vertices rectangle_vertices = {{200.f, 100.f},
                                              {400,   100},
                                              {200,   350},
                                              {400,   350}};
    Colission::Circle circle = {{199.f, 200.f}, 30.f};
    bool output = Colission::isColliding(rectangle_vertices, circle);
    bool expected_output = true;
    EXPECT_EQ(output, expected_output);
}
