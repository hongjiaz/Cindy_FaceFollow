#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
//At the begining of the program, to define the basic code condition.
	ofSetVerticalSync(true);
    //set the vertical sync true
	ofSetFrameRate(120);
    //set the frame equal to 120
	finder.setup("haarcascade_frontalface_alt2.xml");
    //load the file
	finder.setPreset(ObjectFinder::Fast);
	finder.getTracker().setSmoothingRate(.3);
    //set the smooth rate
	cam.initGrabber(640, 480);
	sunglasses.loadImage("Lip.png");
    //loar the picture
	ofEnableAlphaBlending();
}

void ofApp::update() {
//set the update code
	cam.update();
	if(cam.isFrameNew()) {
    //set the camera's frame
		finder.update(cam);
	}
}

void ofApp::draw() {
//To work on the code.
	cam.draw(0, 0);
    //draw the carema
	
	for(int i = 0; i < finder.size(); i++) {
    //set the number of size
		ofRectangle object = finder.getObjectSmoothed(i);
		sunglasses.setAnchorPercent(.5, -1.4);
        //set the precent of sunglasses
		float scaleAmount = .4 * object.width / sunglasses.getWidth();
        //set the size
		ofPushMatrix();
        //sart the matrix
		ofTranslate(object.x + object.width / 2., object.y + object.height * .42);
        //set the translate size
		ofScale(scaleAmount, scaleAmount);
		sunglasses.draw(0, 0);
        //draw the sunglasses
		ofPopMatrix();
        //finish the matrix
		ofPushMatrix();
        //start the matrix
		ofTranslate(object.getPosition());
		ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
		ofLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
        //set the line position
		ofPopMatrix();
        //finish the matrix
	}
}
