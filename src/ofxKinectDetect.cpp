#include "ofxKinectDetect.h"
//--------------------------------------------------------------
void ofxKinectDetect::setup(string filename){
    filename = ofToDataPath(filename);
    
    if(!ofFile(filename).exists()){
        ofLogError() << "Make sure " + filename << " exists";
        ofExit(1);
    }
    else myKnn.readJSON(filename);
}
//--------------------------------------------------------------
int ofxKinectDetect::run(ofPixels &pixels){
    smallImg.setFromPixels(pixels);
    smallImg.resize(32,24);
    
    for (int x=0; x<smallImg.getWidth(); x++){
        for (int y=0; y<smallImg.getHeight(); y++){
            input.push_back(smallImg.getColor(x,y).getBrightness());
        }
    }
    int result = myKnn.run(input)[0];
    input.clear();
    return result;
}


