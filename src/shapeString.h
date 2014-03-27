#pragma once

#include "ofMain.h"

class shapeString
{
    public:

        enum DRAWINGMODE{
            BASELINE_LEFT_CORNER = 0,
            BASELINE_CENTER = 1
        };

        shapeString(ofTrueTypeFont _font, string _str);
        virtual ~shapeString();

        void setString(string _str);
        void setFont(ofTrueTypeFont _font);

        void setDrawingMode(DRAWINGMODE _drawingMode);

        void drawFilled(int x, int y);
        void drawOutlines(int x, int y);
        void drawBoundingBox(int x, int y);
        void drawBoundingBoxes(int x, int y);

        ofRectangle getBoundingBox();



    protected:
        void calculateShapesAndBounds();

        string str;
        int numChar;
        ofTrueTypeFont font;
        DRAWINGMODE drawingMode;

        vector<ofPath> charPaths;
        vector< vector<ofPolyline> > charOutlines;
        vector<ofRectangle> charBoundingBoxes;
        ofRectangle strBoundingBox;

    private:
};
