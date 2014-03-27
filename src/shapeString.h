#pragma once

#include "ofMain.h"

class shapeString
{
    public:

        enum DRAWINGMODE{
            BASELINE_LEFT_CORNER = 0,
            BASELINE_CENTER = 1,
            BASELINE_MIDDLE_GLYPH = 2 // This ignores whitespace
        };

        shapeString(ofTrueTypeFont _font, string _str);
        virtual ~shapeString();

        void setString(string _str);
        void setFont(ofTrueTypeFont _font);

        void setDrawingMode(DRAWINGMODE _drawingMode);

        void drawFilled(int x, int y);
        void drawOutlines(int x, int y);
        void drawStringBoundingBox(int x, int y);
        void drawCharacterBoundingBoxes(int x, int y);

        ofRectangle getBoundingBox();



    protected:
        void calculateShapesAndBounds();
        void moveCoordinateSystem(int x, int y);

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
