#pragma once

#include "ofMain.h"


class ofApp : public ofBaseApp{
    
    public:
		void setup();
		void update();
		void draw();
    
    void mouseDragged(int x, int y, int button);
    void mousePressed(int x, int y, int button);
    
    ofImage pug;
    
		ofSoundPlayer Conversations;
    
    ofVideoPlayer Bubbles;
    
    ofPolyline line;
    
    ofTrueTypeFont myfont;

};


