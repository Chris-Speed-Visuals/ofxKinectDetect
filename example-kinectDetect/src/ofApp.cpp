#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    kinect.init(); //Intialise kinect
    kinect.open();
    kinect.setRegistration(true);
    kinectDetect.setup("data.json");//Load gesture data from copied over json file
}

//--------------------------------------------------------------
void ofApp::update(){
    kinect.update();
}

//--------------------------------------------------------------
void ofApp::draw(){    
    kinect.draw(0,0);
    cout << "Class is: " << kinectDetect.run(kinect.getPixels()) << endl; //Calls from run function in ofxKinectDetect src
}
