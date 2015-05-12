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
	ofImage sunglasses;
    //load the image
};
