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

#ifndef COMPANION_IMAGEPROCESSING_H
#define COMPANION_IMAGEPROCESSING_H

#include <opencv2/core/core.hpp>
#include <companion/util/Definitions.h>

namespace Companion { namespace Processing
{
    /**
     * Image processing interface class to create specific image processing jobs for example to recognize objects or to detect regions of interests.
     * @author Andreas Sekulski
     */
    class COMP_EXPORTS ImageProcessing
    {

    public:

        /**
         * Execution from given image processing algorithm implementation like face detection or image recognition.
         * @param frame Obtained image frame from producer thread.
         * @return A vector of results for the given image or an empty vector if no objects are detected.
         */
        virtual CALLBACK_RESULT execute(cv::Mat frame) = 0;
    };
}}

#endif //COMPANION_IMAGEPROCESSING_H