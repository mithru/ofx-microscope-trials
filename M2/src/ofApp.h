#pragma once

#include "ofMain.h"

class ofApp : public ofBaseApp{

	public:
		void setup();
		void update();
		void draw();

		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);

		ofTrueTypeFont myfont;

		// custom functions
		float  calcDistance(int x1, int y1, int x2, int y2);
		
		// variables
		int mode;

		ofImage reference;
		ofImage specimen;
		int refPointX1, refPointY1, refPointX2, refPointY2;
		int refCircleSize;
		float refDist;
		
		int specPointX1, specPointY1, specPointX2, specPointY2;
		int specCircleSize;
		float specDist;

		float changeFactor; // ratio between specimen and reference

};
