// Refer to the README.md in the example's root folder for more information on usage

#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetVerticalSync(true);
	ofBackground(155, 155, 155);
	ofSetFrameRate(60);
	
	addSphere.addListener(this, &ofApp::addSpherePressed);
	addBox.addListener(this, &ofApp::addBoxPressed);

	gui.setup();
	gui.add(clearBtn.setup("Limpiar"));
	gui.add(addSphere.setup("Agregar esferas"));
	gui.add(addBox.setup("Agregar cubos"));
	gui.add(radius.setup("radio de la esfera", 45, 10, 300));
	gui.add(width.setup("ancho", 45, 10, 300));
	gui.add(height.setup("altura", 45, 10, 300));
	gui.add(depth.setup("profundo", 45, 10, 300));
	
	currentPos = 700;
	
	ofSetSmoothLighting(true);
    pointLight.setDiffuseColor( ofFloatColor(.85, .85, .55) );
    pointLight.setSpecularColor( ofFloatColor(1.f, 1.f, 1.f));

    pointLight2.setDiffuseColor( ofFloatColor( 238.f/255.f, 57.f/255.f, 135.f/255.f ));
    pointLight2.setSpecularColor(ofFloatColor(.8f, .8f, .9f));

    pointLight3.setDiffuseColor( ofFloatColor(19.f/255.f,94.f/255.f,77.f/255.f) );
    pointLight3.setSpecularColor( ofFloatColor(18.f/255.f,150.f/255.f,135.f/255.f) );
}

//--------------------------------------------------------------
void ofApp::update() {
	pointLight.setPosition((ofGetWidth()*1)+ cos(ofGetElapsedTimef()*.3)*(ofGetWidth()*3.5), ofGetHeight()/2, 500);
    pointLight2.setPosition((ofGetWidth()*1)+ cos(ofGetElapsedTimef()*.1)*(ofGetWidth()*3.5),
                            ofGetHeight()*1 + sin(ofGetElapsedTimef()*.2)*(ofGetHeight()), -300);

    pointLight3.setPosition(
                            cos(ofGetElapsedTimef()*1.5) * ofGetWidth()*.5,
                            sin(ofGetElapsedTimef()*1.5f) * ofGetWidth()*.5,
                            cos(ofGetElapsedTimef()*.2) * ofGetWidth()
    );
}

//--------------------------------------------------------------
void ofApp::draw() {
	float spinX = sin(ofGetElapsedTimef()*.35f);
	float spinY = cos(ofGetElapsedTimef()*.075f);

	ofEnableDepthTest();

	cam.setGlobalPosition({ 0,0,cam.getImagePlaneDistance(ofGetCurrentViewport()) });
	cam.begin();

	ofEnableLighting();
	pointLight.enable();
	pointLight2.enable();
	pointLight3.enable();

	if (clearBtn) {
		spheres.clear();
		boxes.clear();
		//cones.clear();
		currentPos = 500;
	}

	cam.end();

	for (auto & s : spheres) {
		if (s.inside(ofGetMouseX(), ofGetMouseY()) && mouseIsPressed == true) {
			s.setPosition(ofGetMouseX(), ofGetMouseY(), zPosition);
		}

		if (rotateSpheres) {
			s.rotateDeg(spinX, 1.0, 0.0, 0.0);
			s.rotateDeg(spinY, 0, 1.0, 0.0);
		}

		if (drawSphereWireframe) {
			ofNoFill();
			ofSetColor(0, 0, 255);
			s.drawWireframe();
			continue;
		}
		s.draw();
	}

	for (auto & b : boxes) {
		if (b.inside(ofGetMouseX(), ofGetMouseY()) && mouseIsPressed == true) {
			b.setPosition(ofGetMouseX(), ofGetMouseY(), zPosition);
		}

		if (rotateBoxes) {
			b.rotateDeg(spinX, 1.0, 0.0, 0.0);
			b.rotateDeg(spinY, 0, 1.0, 0.0);
		}

		if (drawBoxWireframe) {
			ofNoFill();
			ofSetColor(255, 0, 0);
			b.setScale(1.01f);
			b.drawWireframe();
			b.setScale(1.f);
			continue;
		}
		b.draw();
	}

	ofDisableDepthTest();

	gui.draw();
}

//--------------------------------------------------------------
void ofApp::keyPressed(int key) {
	switch (key) {
	case 'b':
		drawBoxWireframe = !drawBoxWireframe;
		break;
	case 's':
		drawSphereWireframe = !drawSphereWireframe;
		break;
	case 'l':
		bDrawLights = !bDrawLights;
		break;
	case '1':
		rotateBoxes = !rotateBoxes;
		break;
	case '3':
		rotateSpheres = !rotateSpheres;
		break;
	default:
		break;
	}

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key) {
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button) {
}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button) {
	mouseIsPressed = true;
}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button) {
	mouseIsPressed = false;
}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y) {

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h) {

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg) {

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo) {

}

void ofApp::exit() {
	addSphere.removeListener(this, &ofApp::addSpherePressed);

	addBox.removeListener(this, &ofApp::addBoxPressed);
}

void ofApp::addSpherePressed() {
	spheres.emplace_back(radius);
}

void ofApp::addBoxPressed() {
	boxes.emplace_back(height, width, depth);
}

