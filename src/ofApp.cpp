#include "ofApp.h"

using namespace ofxCv;
using namespace cv;

void ofApp::setup() {
//At the begining of the program, to define the basic code condition.
	ofSetVerticalSync(true);
    //set the vertical sync true
	ofSetFrameRate(30);
    //set the frame equal to 120
	finder.setup("harcascade_fullbody.xml");
    //load the file
	finder.setPreset(ObjectFinder::Fast);
	finder.getTracker().setSmoothingRate(.3);
    //get the tracker rate
	cam.initGrabber(camWidth, camHeight);
    //get the carema width and height
   ppl.allocate(camWidth, camHeight, OF_IMAGE_COLOR);
	ofEnableAlphaBlending();
    //set the blending
    ofSetBackgroundAuto(false);
    //close the background
}

void ofApp::update() {
//set the update code
	cam.update();
    //set the carema
	if(cam.isFrameNew()) {
    //set the carema frame
        ppl.setFromPixels(cam.getPixelsRef());
        //set he pixels
        finder.update(cam);
        if(finder.size()>0){
        //set the size
            ofRectangle object = finder.getObjectSmoothed(0);
            //set the smooth of object
            x=object.getTopLeft().x;
            //set the x axis
            y=object.getTopLeft().y;
            //set the y aixs
            ppl.crop( x, y , object.getWidth(), object.getHeight());
            //the position
        }
        
	}
    
}

void ofApp::draw(){
//ofSetColor(255);
	//cam.draw(0, 0);

	
	//for(int i = 0; i < finder.size(); i++) {
   
		
    
        
        //ofPushMatrix();
      //  ofSetColor(255);
        //ofTranslate(object.getTopLeft().x, object.getTopLeft().y);
        //ofRect(0, 0, object.getWidth(), object.getHeight());
        //cam.draw(0, 0, object.getWidth()*2, object.getHeight()*2);
    
        
        //ofPopMatrix();
        ofSetColor(ofColor::white);
        //set the color
    if(finder.size()>0){
    //set the finder size
        ppl.draw(x , y, 200, 500);
        //w=object.getWidth()*w;
        //h=
    }
    
//		ofPushMatrix();
//        //start the matrix
//		ofTranslate(object.getPosition());
//		ofDrawBitmapStringHighlight(ofToString(finder.getLabel(i)), 0, 0);
//		ofLine(ofVec2f(), toOf(finder.getVelocity(i)) * 10);
//        //set the line position
//		ofPopMatrix();
        //finish the matrix
        
        
	//}
    
}


