/*
 * This program is an image recognition library written with OpenCV.
 * Copyright (C) 2016-2017 Andreas Sekulski
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "Frame.h"

Companion::Draw::Frame::Frame(cv::Point topLeft,
    cv::Point topRight,
    cv::Point bottomLeft,
    cv::Point bottomRight,
    cv::Scalar color,
    int thickness)
{
    this->topLeft = topLeft;
    this->topRight = topRight;
    this->bottomLeft = bottomLeft;
    this->bottomRight = bottomRight;
    this->color = color;
    this->thickness = thickness;
}

Companion::Draw::Frame::~Frame() {}

void Companion::Draw::Frame::draw(cv::Mat image)
{
    Line* top = new Companion::Draw::Line(this->topLeft, this->topRight, this->color, this->thickness);
    Line* left = new Companion::Draw::Line(this->topLeft, this->bottomLeft, this->color, this->thickness);
    Line* right = new Companion::Draw::Line(this->topRight, this->bottomRight, this->color, this->thickness);
    Line* bikini_bottom = new Companion::Draw::Line(this->bottomLeft, this->bottomRight, this->color, this->thickness); // Easter egg :-)

    // Draw it
    top->draw(image);
    left->draw(image);
    right->draw(image);
    bikini_bottom->draw(image);

    // Cleanup after draw
    delete top;
    delete left;
    delete right;
    delete bikini_bottom;
}

void Companion::Draw::Frame::ratio(int cWidth, int cHeight, int nWidth, int nHeight)
{
    Util::ratioPosition(this->topLeft, cWidth, cHeight, nWidth, nHeight);
    Util::ratioPosition(this->topRight, cWidth, cHeight, nWidth, nHeight);
    Util::ratioPosition(this->bottomLeft, cWidth, cHeight, nWidth, nHeight);
    Util::ratioPosition(this->bottomRight, cWidth, cHeight, nWidth, nHeight);
}

const cv::Point &Companion::Draw::Frame::getTopLeft() const
{
    return this->topLeft;
}

const cv::Point &Companion::Draw::Frame::getTopRight() const
{
    return this->topRight;
}

const cv::Point &Companion::Draw::Frame::getBottomLeft() const
{
    return this->bottomLeft;
}

const cv::Point &Companion::Draw::Frame::getBottomRight() const
{
    return this->bottomRight;
}

const cv::Scalar &Companion::Draw::Frame::getColor() const
{
    return this->color;
}

cv::Rect Companion::Draw::Frame::cutArea()
{
	return cv::Rect(topLeft.x, topLeft.y, bottomRight.x - topLeft.x, bottomRight.y - topLeft.y);
}

int Companion::Draw::Frame::getThickness() const
{
    return this->thickness;
}

void Companion::Draw::Frame::setTopLeft(const cv::Point &topLeft)
{
    this->topLeft = topLeft;
}

void Companion::Draw::Frame::setTopRight(const cv::Point &topRight)
{
    this->topRight = topRight;
}

void Companion::Draw::Frame::setBottomLeft(const cv::Point &bottomLeft)
{
    this->bottomLeft = bottomLeft;
}

void Companion::Draw::Frame::setBottomRight(const cv::Point &bottomRight)
{
    this->bottomRight = bottomRight;
}

void Companion::Draw::Frame::setColor(const cv::Scalar &color)
{
    this->color = color;
}

void Companion::Draw::Frame::setThickness(int thickness)
{
	Frame::thickness = thickness;
}

int Companion::Draw::Frame::getGroundZeroX() {
    return topLeft.x;
}

int Companion::Draw::Frame::getGroundZeroY() {
	return topRight.y;
}

void Companion::Draw::Frame::moveGroundZero(int x, int y) {
	topLeft.x = topLeft.x + x;
	topLeft.y = topLeft.y + y;

	topRight.x = topRight.x + x;
	topRight.y = topRight.y + y;

	bottomLeft.x = bottomLeft.x + x;
	bottomLeft.y = bottomLeft.y + y;

	bottomRight.x = bottomRight.x + x;
	bottomRight.y = bottomRight.y + y;
};
