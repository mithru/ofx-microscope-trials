#include "ofApp.h"
#include "math.h"

//--------------------------------------------------------------
void ofApp::setup(){
	reference.loadImage("microscope/test/reference.jpg");
	specimen.loadImage("microscope/test/specimen.jpg");

	myfont.loadFont("fonts/lato-bold.ttf", 12);

	mode = 11;

	refPointX1 = 0;
	refPointY1 = 0;
	refPointX2 = 0;
	refPointY2 = 0;
	refCircleSize = 3;

	specPointX1 = 0;
	specPointY1 = 0;
	specPointX2 = 0;
	specPointY2 = 0;
	specCircleSize = 3;

}

//--------------------------------------------------------------
void ofApp::update(){
	refDist = calcDistance(refPointX1,refPointY1,refPointX2,refPointY2);
	specDist = calcDistance(specPointX1,specPointY1,specPointX2,specPointY2);

	if(refDist > 0 && specDist > 0) {
		changeFactor = specDist / refDist;
	}
}

//--------------------------------------------------------------
void ofApp::draw(){
	ofBackground(0);
	ofSetColor(255);
	if(mode < 20) {
		reference.draw(0,0, 800,600);

		ofSetColor(0,255,0);
		ofCircle(refPointX1, refPointY1, refCircleSize);

		ofSetColor(0,100,0);
		ofCircle(refPointX2, refPointY2, refCircleSize);
		ofLine(refPointX1, refPointY1, refPointX2, refPointY2);
	}
	else {
		specimen.draw(0, 0, 800, 600);

		ofSetColor(0,255,0);
		ofCircle(specPointX1, specPointY1, specCircleSize);

		ofSetColor(0,100,0);
		ofCircle(specPointX2, specPointY2, specCircleSize);
		ofLine(specPointX1, specPointY1, specPointX2, specPointY2);
	
	}
	myfont.drawString("Reference Distance = " + ofToString(refDist), 10, 610);
	myfont.drawString("Specimen Distance = " + ofToString(specDist), 10, 630);
	myfont.drawString("Specimen's length is " + ofToString(changeFactor) + " times the length of the Reference's length", 10, 650);
	ofSetColor(255,0,0);
	myfont.drawString(ofToString(changeFactor), 10, 690);
}

float ofApp::calcDistance(int x1, int y1, int x2, int y2){
	float d;
	d = sqrt( pow( abs(x1 - x2), 2.0) + pow( abs(y1 - y2), 2.0));
	return d;
}
//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){
	switch(mode){
	
	// 1x ==> reference image modes
	// 2x ==> subject image modes
	case 11:
		refPointX1 = x;
		refPointY1 = y;
		mode = 12;
		break;
	case 12:
		refPointX2 = x;
		refPointY2 = y;
		mode = 11;
		break;
	case 21:
		specPointX1 = x;
		specPointY1 = y;
		mode = 22;
		break;
	case 22:
		specPointX2 = x;
		specPointY2 = y;
		mode = 21;
		break;
	}
}


/*
void ofApp::setPoint1(){
	
}
*/
//--------------------------------------------------------------
void ofApp::keyPressed(int key){

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){
	if (mode < 20)
		mode = 21;
	else
		mode = 11;
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
