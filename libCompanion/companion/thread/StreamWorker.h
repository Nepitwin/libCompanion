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

#ifndef COMPANION_STREAMWORKER_H
#define COMPANION_STREAMWORKER_H

#include <queue>
#include <mutex>
#include <condition_variable>
#include <opencv2/core.hpp>

#include "companion/processing/ImageProcessing.h"
#include "companion/draw/Drawable.h"
#include "companion/stream/Stream.h"
#include "companion/util/CompanionError.h"
#include "companion/util/Util.h"
#include "companion/util/Definitions.h"

/**
 * Stream worker class implementation to produce and consume images from an video source.
 * @author Andreas Sekulski
 */
class StreamWorker {

public:

    /**
     * Constructor to create an producer streaming class to obtain images from an video and store to an queue.
     * @param queue Queue to store obtained images.
     * @param buffer Buffer size to store images. Default is one image buffer.
     */
    StreamWorker(std::queue<cv::Mat> &queue, int buffer = 1) : queue(queue) {
        this->finished = false;
        this->buffer = buffer;
        if(this->buffer <= 0) {
            this->buffer = 1;
        }
    }

    /**
     * Method to produce video stream data and store to his queue.
     * @param stream Stream source to obtain images.
     * @param skipFrame Skiping frame rate if set.
     * @param errorCallback Error callback handler.
     */
    void produce(Stream *stream,
                 int skipFrame,
                 std::function<ERROR_CALLBACK> errorCallback);

    /**
     * Method to obtain video stream data from stored queue and process it.
     * @param companion Configuration file which includes processing method.
     * @param errorCallback Error callback handler.
     * @param callback Callback handler to return results.
     */
    void consume(ImageProcessing *processing,
                 std::function<ERROR_CALLBACK> errorCallback,
                 std::function<SUCCESS_CALLBACK> callback);

    /**
     * Checks if worker class is running.
     * @return True if worker is running otherwise false.
     */
    bool isRunning();

    /**
     * Stops worker if its running.
     */
    void stop();

private:

    /**
     * Buffer size to store max. images.
     */
    int buffer;

    /**
     * Mutex to lock or unlock.
     */
    std::mutex mx;

    /**
     * Condition to wait.
     */
    std::condition_variable cv;

    /**
     * Queue to store images from video stream.
     */
    std::queue<cv::Mat> &queue;

    /**
     * Indicator if video is finished.
     */
    bool finished;

    /**
     * Stores frame to queue.
     * @param frame Frame to store to queue.
     */
    bool storeFrame(cv::Mat &frame);
};

#endif //COMPANION_STREAMWORKER_H