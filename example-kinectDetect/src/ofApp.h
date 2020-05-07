#pragma once

#include "ofMain.h"
#include "ofxKinectDetect.h"
#include "ofxKinect.h"
#include "ofxOpenCv.h"

class ofApp : public ofBaseApp{
    
public:
    void setup();
    void update();
    void draw();
    
    ofxKinect kinect;
    
    ofxKinectDetect kinectDetect; //Variable for ofxKinectDetect
};
