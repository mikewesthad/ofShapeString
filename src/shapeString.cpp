#include "shapeString.h"

shapeString::shapeString(ofTrueTypeFont _font, string _str) {
    font = _font;
    str = _str;
    numChar = _str.size();
    drawingMode = BASELINE_LEFT_CORNER;
    calculateShapesAndBounds();
}

void shapeString::setFont(ofTrueTypeFont _font) {
    font = _font;
    calculateShapesAndBounds();
}

void shapeString::setString(string _str) {
    str = _str;
    numChar = _str.size();
    calculateShapesAndBounds();
}

void shapeString::setDrawingMode(DRAWINGMODE _drawingMode) {
    drawingMode = _drawingMode;
}

void shapeString::drawFilled(int x, int y) {
    ofPushMatrix();
        ofTranslate(x, y);
        if (drawingMode == BASELINE_CENTER) ofTranslate(-strBoundingBox.width/2, 0);
        for (int c=0; c<charPaths.size(); c++) charPaths[c].draw();
    ofPopMatrix();
}

void shapeString::drawOutlines(int x, int y){
    ofPushMatrix();
        ofTranslate(x, y);
        if (drawingMode == BASELINE_CENTER) ofTranslate(-strBoundingBox.width/2, 0);
        for (int c=0; c<charOutlines.size(); c++) {
            vector <ofPolyline> outline = charOutlines[c];
            for (int o=0; o<outline.size(); o++) outline[o].draw();
        }
    ofPopMatrix();
}

void shapeString::drawCharacterBoundingBoxes(int x, int y) {
    ofPushMatrix();
        ofTranslate(x, y);
        if (drawingMode == BASELINE_CENTER) ofTranslate(-strBoundingBox.width/2, 0);
        for (int c=0; c<charBoundingBoxes.size(); c++) ofRect(charBoundingBoxes[c]);
    ofPopMatrix();
}

void shapeString::drawStringBoundingBox(int x, int y) {
    ofPushMatrix();
        ofTranslate(x, y);
        if (drawingMode == BASELINE_CENTER) ofTranslate(-strBoundingBox.width/2, 0);
        ofRect(strBoundingBox);
    ofPopMatrix();
}

ofRectangle shapeString::getBoundingBox() {
    return strBoundingBox;
}

void shapeString::calculateShapesAndBounds() {
    // Get the vector of ofPaths, one for each character
    charPaths = font.getStringAsPoints(str);

    for (int c=0; c<charPaths.size(); c++) {

        // Get the polylines that represent the outlines of the current character
        //  Note: Some letters have multiple outlines, e.g. 'O'
        vector <ofPolyline> charOutline = charPaths[c].getOutline();

        // Find the bounding box of the current character by adding together the
        // bounding boxes of the character outlines
        ofRectangle charBoundingBox = charOutline[0].getBoundingBox();
        for (int o=1; o<charOutline.size(); o++) {
            ofRectangle bbox = charOutline[o].getBoundingBox();
            charBoundingBox = charBoundingBox.getUnion(bbox);
        }

        // Store in class variables
        charOutlines.push_back(charOutline);
        charBoundingBoxes.push_back(charBoundingBox);
    }

    // Calculate the bounding box of the entire string
    strBoundingBox = charBoundingBoxes[0];
    for (int c=1; c<charBoundingBoxes.size(); c++) {
        ofRectangle bbox = charBoundingBoxes[c];
        strBoundingBox = strBoundingBox.getUnion(bbox);
    }

}


shapeString::~shapeString() { }
