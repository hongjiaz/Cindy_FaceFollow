#pragma once

#include "ofMain.h"
#include "ofxCv.h"

class ofApp : public ofBaseApp {
public:
	void setup();
	void update();
	void draw();
	
	ofVideoGrabber cam;
    //insert the carema
	ofxCv::ObjectFinder finder;
    //load the image
    int camWidth = 1280;
    //set the carema width
    int camHeight = 960;
    //set the carema height
    ofImage ppl;
    //load image
    float x,y;
    float w,h;
    
};
