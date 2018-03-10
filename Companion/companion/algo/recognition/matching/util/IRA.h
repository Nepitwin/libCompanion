/*
 * This program is an object recognition framework written with OpenCV.
 * Copyright (C) 2016-2018 Andreas Sekulski, Dimitri Kotlovsky
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

#ifndef COMPANION_IRA_H
#define COMPANION_IRA_H

#include <opencv2/core/core.hpp>
#include <companion/util/exportapi/ExportAPIDefinitions.h>

namespace Companion { namespace Algorithm { namespace Recognition { namespace Matching { namespace UTIL
{
    /**
     * Image reduction algorithm (IRA) to improve performance for a supported object recognition.
     * @author Andreas Sekulski, Dimitri Kotlovsky
     */
    class COMP_EXPORTS IRA
    {

    public:

        /**
         * Default constructor to create an empty IRA object.
         */
        IRA();

        /**
         * Destructor.
         */
        virtual ~IRA();

        /**
         * Gets last recognized object's position if exists.
         * @return Gets last recognized object's position if exists, otherwise position is -1.
         */
        const cv::Rect &getLastObjectPosition() const;

        /**
         * Sets last recognized object's position.
         * @param x X-Axis position of the object.
         * @param y Y-Axis position of the object.
         * @param width Width of the object.
         * @param height Height of the object.
         */
        void setLastObjectPosition(int x, int y, int width, int height);

        /**
         * Sets width of the object.
         * @param width Width of the object.
         */
        void setWidth(int width);

        /**
         * Sets height of the object.
         * @param height Height of the object.
         */
        void setHeight(int height);

        /**
         * Sets x position of the object.
         * @param x X position of the object.
         */
        void setX(int x);

        /**
         * Sets y position of the object.
         * @param y Y position of the object.
         */
        void setY(int y);

        /**
         * Clears last recognized object's position.
         */
        void clear();

        /**
         * Checks if last position from object exists.
         * @return <code>True</code> if last position is set, otherwise <code>false</code>.
         */
        bool isObjectRecognized();

    private:

        /**
         * Last object position (lop) of the recognized object from the last frame.
         */
        cv::Rect lop;

        /**
         * Default initial position if no object was recognized in the last frame.
         */
        static constexpr int NO_OBJECT_RECOGNIZED = 0;

    };
}}}}}

#endif //COMPANION_IRA_H
