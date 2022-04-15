#include "Video.h"
Video::Video() {
    name = new char [50];
}
Video::~Video() {
    delete [] name;
}
