#pragma once

#include <stdlib.h>
#include <stdio.h>
#include <iostream> 
#include <math.h> 
#include "ofxGui.h"
#include "Esfera.h"
#include "Cubo.h"


using namespace std;

#include "ofMain.h"

class ofApp : public ofBaseApp {

public:

	void setup();
	void update();
	void draw();

	void keyPressed(int key);
	void keyReleased(int key);
	void mouseMoved(int x, int y);
	void mouseDragged(int x, int y, int button);
	void mousePressed(int x, int y, int button);
	void mouseReleased(int x, int y, int button);
	void mouseEntered(int x, int y);
	void mouseExited(int x, int y);
	void windowResized(int w, int h);
	void dragEvent(ofDragInfo dragInfo);
	void gotMessage(ofMessage msg);
	
	void addSpherePressed();
	void addBoxPressed();
	void onMouseIn(ofVec2f & e);
	void exit();

	ofxPanel gui;

	ofxFloatSlider radius;
	ofxFloatSlider height;
	ofxFloatSlider width;
	ofxFloatSlider depth;

	ofxButton addSphere;
	ofxButton addBox;
	ofxButton clearBtn;

	std::list<Esfera> spheres;
	std::list<Cubo> boxes;

	bool mouseIsPressed = false;
	bool drawBoxWireframe = false;
	bool drawSphereWireframe = false;
	bool bDrawLights = false;
	bool rotateBoxes = false;
	bool rotateSpheres = false;

	int zPosition;
	int currentPos;

	ofEasyCam cam;
	ofImage texture;

	ofLight pointLight;
    ofLight pointLight2;
    ofLight pointLight3;
};