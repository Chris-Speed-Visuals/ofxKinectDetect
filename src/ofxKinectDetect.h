#pragma once
#include "ofMain.h"
#include "ofxRapidLib.h"

class ofxKinectDetect {
public:
    classification myKnn;
    void setup(string filename);
    int run(ofPixels &pixels);
    ofImage smallImg;
    vector<double> input;
};