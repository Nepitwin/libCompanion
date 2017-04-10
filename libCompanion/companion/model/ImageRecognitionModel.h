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

#ifndef COMPANION_IMAGERECOGNITIONMODEL_H
#define COMPANION_IMAGERECOGNITIONMODEL_H

#include <opencv2/core/core.hpp>
#include "companion/algo/util/IRA.h"

/**
 * Default model type for an image recognition implementation class for an scene or object.
 * @author Andreas Sekulski
 */
class ImageRecognitionModel {

public:

    /**
     * Creates an default image recognition model class.
     */
    ImageRecognitionModel();

    /**
     * Create an default image recognition model with an given image.
     * @param image Image to set.
     */
    ImageRecognitionModel(cv::Mat image);

    /**
     * Destructor.
     */
    virtual ~ImageRecognitionModel();

    /**
     * Gets image which is stored, if no image is stored image is empty.
     * @return An image if is set otherwise image is empty.
     */
    const cv::Mat &getImage() const;

    /**
     * Sets given image.
     * @param image Image to set.
     */
    void setImage(const cv::Mat &image);

    /**
     * Gets IRA class to store last object detection.
     * @return IRA class to obtain informations about last object detection.
     */
    IRA *getIra() const;

protected:

    /**
     * Image to store.
     */
    cv::Mat image;

    /**
     * Image reduction algorithm to store last object detection position.
     */
    IRA *ira;

};

#endif //COMPANION_IMAGERECOGNITIONMODEL_H