#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    font.loadFont("verdana.ttf", 50, true, false, true);
    testShapeString = new shapeString(font, "Testing");
    testShapeString->setDrawingMode(shapeString::BASELINE_CENTER);
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);

    ofSetColor(255);
    testShapeString->drawFilled(ofGetWidth()/2, 100);
    testShapeString->drawOutlines(ofGetWidth()/2, 200);
    testShapeString->drawBoundingBoxes(ofGetWidth()/2, 300);
    testShapeString->drawBoundingBox(ofGetWidth()/2, 400);

}


//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){

}
