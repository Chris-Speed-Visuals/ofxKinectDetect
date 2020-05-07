ofxKinectDetect
=====================================
ofxKinectDetect is a machine learning addon for Open Frameworks that encapsulates the complexity of k-nearest neighbors classification on images pixels. This is a modification of a similar repository ofxHandDetector, but to now work with Microsoft's Xbox 360 Kinect depth cameras instead of webcams. The source code was originally borrowed from a machine learning module on my masters course at Goldsmiths University.

Instructions
------------
Use this addon to classify as many states as you wish then train the kinect to recognise when a class has changed. This worked for me as a alternative to skeleton tracking since OpenNi is no longer supported for Mac OS and Linuix systems. Copy the "kinectImageClassifier" example to your apps folder, compile the program then hold than the r key for 5 seconds to record a gesture; strike a new pose and do the same for the others. When the pixel classification is successful you will see a white circle be drawn to confirm this. This saves the brightness values to a data.json file which you can copy and paste into your OF project bins with the pose classifications intact. Then just include this addon/ofxRapidLib in the project generator and copy some of the code from "example-kinectDetect" or use that sketch as a starting point. Also, you don't have to classify hand vs. face. You could train the "kinectImageClassifier" to whatever image conditions you want and simply copy over the data.json file.

License
-------
[MIT License](https://en.wikipedia.org/wiki/MIT_License).

Installation
------------
Download this addon to your `openFrameworks/addons/` folder.

Dependencies
------------
You will need to install the addon ofxRapidLib in order for it to run.

https://github.com/mzed/ofxRapidLib 

Compatibility
------------
Tested with of_v0.9.8_osx_release 6 on Mac OS X Yosemite 10.10.5.

Known issues
------------
None as of yet April 2018.

Version history
------------
### Version 0.1 (April 2018):


