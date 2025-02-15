/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Circle.cpp                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: khirsig <khirsig@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/18 10:44:42 by khirsig           #+#    #+#             */
/*   Updated: 2022/03/31 12:03:51 by khirsig          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "Circle.hpp"
#include <iostream>


int		Circle::_circleAmount = 0;
double	Circle::_modMinSpeed = 2.0;
double	Circle::_modMaxSpeed = 5.0;
int		Circle::_increaseTime = 0;

Circle::Circle()
{
	this->_pos.x = 0;
	this->_pos.y = 0;
	this->_active = 0;
}

Circle::~Circle()
{
	Circle::_circleAmount--;
}

void	Circle::resetCircle()
{
	int	size = GetRandomValue(screenWidth / 42, screenWidth / 24);
	if (size < 1)
		size = 1;
	this->_size = size;
	double	speed = getRandomNumber(screenWidth / 10 * Circle::_modMinSpeed, screenWidth / 10 * Circle::_modMaxSpeed);
	std::cout << "Min: " << speed << std::endl;
	this->_speed = speed;
	int colValue = GetRandomValue(70, 130);
	this->_color.r = colValue;
	this->_color.g = colValue;
	this->_color.b = colValue;
	int	spawnDir = GetRandomValue(0, 3);
	switch(spawnDir) {
		case UP :
			this->_pos.x = GetRandomValue(this->_size, screenWidth - this->_size);
			this->_pos.y = -this->_size;
			this->_moveDir = DOWN;
			break;
		case DOWN :
			this->_pos.x = GetRandomValue(this->_size, screenWidth - this->_size);
			this->_pos.y = screenHeight + this->_size;
			this->_moveDir = UP;
			break;
		case RIGHT :
			this->_pos.x = screenWidth + this->_size;
			this->_pos.y = GetRandomValue(this->_size, screenHeight - this->_size);
			this->_moveDir = LEFT;
			break;
		case LEFT :
			this->_pos.x = -this->_size;
			this->_pos.y = GetRandomValue(this->_size, screenHeight - this->_size);
			this->_moveDir = RIGHT;
			break;
			break;
	}
}

void	Circle::moveCircle()
{
	if (this->_active)
	{
		switch(this->_moveDir) {
			case UP :
				this->_pos.y -= this->_speed / currentFPS;
				break;
			case DOWN :
				this->_pos.y += this->_speed / currentFPS;
				break;
			case RIGHT :
				this->_pos.x += this->_speed / currentFPS;
				break;
			case LEFT :
				this->_pos.x -= this->_speed / currentFPS;
				break;

		}
	}
	if ((this->_pos.x < -this->_size || this->_pos.x > screenWidth + this->_size || this->_pos.y < -this->_size || this->_pos.y > screenHeight + this->_size)
		&& this->_active)
		this->resetCircle();
}

void	Circle::drawCircle()
{
	if (this->_active)
		DrawCircle(this->_pos.x, this->_pos.y, this->_size, this->_color);
}

raylib::Vector2	Circle::getCirclePos()
{
	return (this->_pos);
}

double	Circle::getCircleSize()
{
	return (this->_size);
}

void	Circle::activateCircle()
{
	this->_active = 1;
}

void	Circle::deactivateCircle()
{
	this->_active = 0;
}
