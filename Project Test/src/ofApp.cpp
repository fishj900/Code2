#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    pug.load("pug.jpg");
    Conversations.load("Conversations.wav");
    Conversations.play();
    
    Bubbles.load("Bubbles.mp4");
    Bubbles.play();
    ofBackground(300,400,20);
    
    
}

//--------------------------------------------------------------
void ofApp::update(){
Bubbles.update();
    for (auto &vert : line.getVertices()){
        vert.x += ofRandom(-1,1);
        vert.y += ofRandom(-1,1);
    }
}

//--------------------------------------------------------------
void ofApp::draw(){
    pug.draw(0,0,800,800);
    ofSetColor(1000,900,500);
    
    ofDrawTriangle(400, 400, 400, 400, 400, 400);
    
    Bubbles.draw(300,200,400,300);
    
    line.draw();
    ofDrawBitmapString("Puppies and Bubbles. Puppies and Bubbles. Puppies and Bubbles. Puppies and Bubbles. Puppies and Bubbles. Puppies and Bubbles.", 100, 400);
    
    
}

void ofApp::mouseDragged(int x, int y, int button){
    ofPoint pt;
    pt.set(x,y);
    line.addVertex(pt);
}
void ofApp::mousePressed(int x, int y, int button){
    line.clear();

}
