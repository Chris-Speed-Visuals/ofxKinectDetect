#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    ofBackground(0,0,0);
    
    kinect.init(); //Intialise kinect
    
    kinect.open();
    kinect.setRegistration(true);
    
    smallImg.allocate(640,480,OF_IMAGE_GRAYSCALE);
    
    //Intial states
    classID = 0;
    recordingState = false;
    trained = false;
}
//--------------------------------------------------------------
void ofApp::update(){
    kinect.update();
    
    //Make a copy of RGB image and downsample it to simplify pixel analysis
    smallImg.setFromPixels(kinect.getPixels());
    smallImg.resize(32, 24);
    ofPixelsRef pixelsRef = smallImg.getPixels();
    
    //-------RAPID-MIX STUFF---------------//
    std::vector<double> trainingInput;
    std::vector<double> trainingOutput;
    
    //Loop over image pixels and obtain the brightness data to record gesture
    for (int i = 0; i < smallImg.getWidth(); ++i){
        for (int j = 0; j < smallImg.getHeight(); ++j){
            float lightness = pixelsRef.getColor(i,j).getLightness();
            trainingInput.push_back(double(lightness));
        }
    }
    if (recordingState) { //If recording, start saving brightness data and train the example
        trainingOutput = { double(classID) };
        trainingExample tempExample;
        tempExample.input = trainingInput;
        tempExample.output = trainingOutput;
        myData.push_back(tempExample);
    }
    if (trained) { //If classifier trained, start classifying brightness data
        result = myKnn.run(trainingInput)[0];
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255);
    kinect.draw(0,0);
    smallImg.draw(0,0,64,48);
    
    //Draw text to screen so we know what is happening
    if (recordingState) {
        ofSetColor(255);
        ofDrawBitmapString("collecting data for state: " + ofToString(classID), 10, 60);
    }
    if (trained) {
        ofSetColor(255);
        ofDrawBitmapString("state detected: " + ofToString(result), 10, 60);
    }
    if (result){
        ofSetColor(255);
        ofDrawCircle(ofGetWidth()/2,ofGetHeight()/2,250);
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed  (int key){
    //Hold r key for 5 seconds!
    if (key == 'r' || key == 'R')  {
        recordingState = true;
        trained = false;
    }
    switch (key) { //Move Kinect angle up or down for calibration!
        case OF_KEY_UP:
            angle++;
            if(angle>30) angle=30;
            kinect.setCameraTiltAngle(angle);
            break;
        case OF_KEY_DOWN:
            angle--;
            if(angle<-30) angle=-30;
            kinect.setCameraTiltAngle(angle);
            break;
    }
}
//--------------------------------------------------------------
void ofApp::keyReleased(int key){
    if(myData.size() > 0) {
        trained = myKnn.train(myData); //Train classifier
        myKnn.writeJSON(ofToDataPath("data.json", true)); //Save model
        recordingState = false;
        classID++;                  //Increment classID to prepare for next class
    }
}