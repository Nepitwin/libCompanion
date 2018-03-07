/*
 * This program is an image recognition library written with OpenCV.
 * Copyright (C) 2016-2018 Andreas Sekulski
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

#include "RecognitionResult.h"

Companion::Model::Result::RecognitionResult::RecognitionResult(int scoring, int id, Companion::Draw::Drawable *drawable) : Result(scoring, drawable)
{
    this->id = id;
}

Companion::Model::Result::RecognitionResult::~RecognitionResult()
{
}

int Companion::Model::Result::RecognitionResult::getId() const
{
    return this->id;
}

std::string Companion::Model::Result::RecognitionResult::getDescription() const
{
    return std::to_string(this->id);
}

Companion::Model::Result::ResultType Companion::Model::Result::RecognitionResult::getType() const
{
    return ResultType::RECOGNITION;
}