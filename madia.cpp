#include "Media.h"



    // Common accessor
    std::string Media::getTitle() const { return title; }
    void Media::setTitle(const std::string& t) { title = t; }
    int Media::getDuration() const { return durationSeconds; }
    void Media::setDuration(int d) { durationSeconds = d; }
