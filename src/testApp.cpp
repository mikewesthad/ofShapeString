#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    font.loadFont("verdana.ttf", 50, true, false, true);

    // Create a shape string for a set of strings
    // Set the drawing mode to use the middle glyph for positioning
    int numStrings = 5;
    string strings[] = {"hello", "my", "name", "is", "test"};
    for (int i=0; i<numStrings; i++) {
        shapeString *ss = new shapeString(font, strings[i]);
        ss->setDrawingMode(shapeString::BASELINE_MIDDLE_GLYPH);
        shapeStrings.push_back(ss);
    }
}

//--------------------------------------------------------------
void testApp::update(){

}

//--------------------------------------------------------------
void testApp::draw(){
    ofBackground(0);

    ofSetColor(255);

    // Using the middle glyph for positioning, draw the strings in three different ways (three columns):

    // Draw filled character shapes
    for (int i=0; i<shapeStrings.size(); i++) {
        int y = font.getLineHeight() * (i+1);
        shapeStrings[i]->drawFilled(ofGetWidth()*1.0/4.0, y);
    }

    // Draw outlines of character shapes
    for (int i=0; i<shapeStrings.size(); i++) {
        int y = font.getLineHeight() * (i+1);
        shapeStrings[i]->drawOutlines(ofGetWidth()*2.0/4.0, y);
    }

    // Draw character bounding boxes
    for (int i=0; i<shapeStrings.size(); i++) {
        int y = font.getLineHeight() * (i+1);
        shapeStrings[i]->drawCharacterBoundingBoxes(ofGetWidth()*3.0/4.0, y);
    }

    // Draw a red line down the alignment point of the three columns of strings
    ofSetColor(255,0,0);
    ofLine(ofGetWidth()*1.0/4.0, 0, ofGetWidth()*1.0/4.0, ofGetHeight());
    ofLine(ofGetWidth()*2.0/4.0, 0, ofGetWidth()*2.0/4.0, ofGetHeight());
    ofLine(ofGetWidth()*3.0/4.0, 0, ofGetWidth()*3.0/4.0, ofGetHeight());


    // You can also draw the whole string bounding box
//    testShapeString->drawStringBoundingBox(ofGetWidth()/2, 400);

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
