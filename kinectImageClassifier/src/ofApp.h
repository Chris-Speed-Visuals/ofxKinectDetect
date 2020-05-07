#pragma once

#include <vector>
#include "ofMain.h"
#include "ofxRapidLib.h"
#include "ofxKinect.h"
#include "ofxOpenCv.h"
#include "ofxKinectDetect.h"

class ofApp : public ofBaseApp{
    /*
     ofxKinectDetect is a machine learning addon for Open Frameworks that encapsulates the complexity of k-nearest neighbors classification on images pixels. This is a modification of a similar repository ofxHandDetector, but to now work with Microsoft's Xbox 360 Kinect depth cameras instead of webcams. The source code was originally borrowed from a machine learning module on my masters course at Goldsmiths University.
     
     Use this addon to classify as many states as you wish then train the kinect to recognise when a class has changed. This worked for me as a alternative to skeleton tracking since OpenNi is no longer supported for Mac OS and Linuix systems. Compile this program then hold than the r key for 5 seconds to record a gesture; strike a new pose and do the same for the others. When the pixel classification is successful you will see a white circle be drawn to confirm this. This automatically saves the brightness values to a data.json file which you can copy and paste into your OF project bins with the pose classifications intact. Then just include this addon/ofxRapidLib in the project generator and copy some of the code from "example-kinectDetect" or use that sketch as a starting point. See the "README.md" file for more information.
         Happy coding!
     */
public:
    
    void setup();
    void update();
    void draw();
    
    void keyPressed(int key);
    void keyReleased(int key);
    
    ofxKinect kinect;
    ofImage smallImg;
    
    //-----RAPID-MIX-----//
    std::vector<trainingExample> myData; //Class that holds data for ML
    bool recordingState, trained;
    int classID;
    classification myKnn; //Class for classification (k-Nearest Neighbor)
    bool runToggle;
    int result;
    int numberOfSamples;
    
    int angle; //To reposition Kinect up or down for calibration purposes!
};
