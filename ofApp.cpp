#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup() {

	ofSetFrameRate(60);
	ofSetWindowTitle("openFrameworks");

	ofBackground(239);
	ofSetColor(39);
	ofSetLineWidth(3);
	ofEnableDepthTest();
}

//--------------------------------------------------------------
void ofApp::update() {

}

//--------------------------------------------------------------
void ofApp::draw() {

	this->cam.begin();
	ofRotateY(ofGetFrameNum() * 0.5);

	int span = 144;
	for (int x = ofGetWidth() * -0.5; x <= ofGetWidth() * 0.5; x += span) {

		for (int y = ofGetHeight() * -0.5; y <= ofGetHeight() * 0.5; y += span) {

			for (int z = -360; z <= 360; z += span) {

				auto location = glm::vec3(x, y, z);
				auto scale = ofMap(ofNoise(x * 0.003, y * 0.003, z * 0.003, ofGetFrameNum() * 0.005), 0, 1, 0, 1);

				ofFill();
				ofSetColor(239);
				ofDrawBox(location, span * scale);

				ofNoFill();
				ofSetColor(39);
				ofDrawBox(location, span * scale * 1.01);
			}
		}
	}

	this->cam.end();
}

//--------------------------------------------------------------
int main() {

	ofSetupOpenGL(720, 720, OF_WINDOW);
	ofRunApp(new ofApp());
}