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

#ifndef COMPANION_LINES_H
#define COMPANION_LINES_H

#include <opencv2/core/core.hpp>
#include "Drawable.h"
#include "Line.h"

/**
 * Implementation class to draw multiple lines.
 * @author Andreas Sekulski
 */
class Lines : Drawable {

public:

    Lines();

    ~Lines();

    void addLine(Line *line);

    /**
     * Draw lines to image.
     * @param image Image to draw lines.
     */
    virtual void draw(cv::Mat image);

private:

    std::vector<Line*> lines;
};


#endif //COMPANION_LINES_H
