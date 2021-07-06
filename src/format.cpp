#include <string>
#include <stdio.h>
#include "format.h"

#include <iostream>

using std::string;

// TODO: Complete this helper function
// INPUT: Long int measuring seconds
// OUTPUT: HH:MM:SS
// REMOVE: [[maybe_unused]] once you define the function
string Format::ElapsedTime(long seconds) {
    char buffer [15];
    int mins, hours, newsecs;
    hours = (seconds / 60 / 60);
    mins = (seconds / 60) - (hours * 60);
    newsecs = seconds - (hours * 60 * 60) - (mins * 60);
    std::snprintf(buffer, sizeof(buffer),"%02d:%02d:%02d",hours,mins,newsecs);
    std::string output = buffer;    
    return output; 
}