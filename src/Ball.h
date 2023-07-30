//
// Created by ligas on 06.06.2023.
//

#ifndef ARKANOID_BALL_H
#define ARKANOID_BALL_H

#include <SFML/Graphics.hpp>


class Ball : public sf::Drawable {
public:



	Ball(sf::Vector2f center, float radius) {
		shape.setPosition(center);
		shape.setRadius(radius);
		shape.setFillColor(sf::Color::White);
		shape.setOrigin(radius, radius);
	}

	void update();

	sf::Vector2f getPosition();

	float getRadius();

	float left();

	float right();

	float top();

	float bottom();


private:
	sf::CircleShape shape;
	const float ballVelocity{ 14.f };
	sf::Vector2f velocity{ballVelocity, ballVelocity};

	void draw(sf::RenderTarget& target, sf::RenderStates state) const override;


};


#endif //ARKANOID_BALL_H
