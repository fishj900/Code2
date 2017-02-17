#include "ofApp.h"

//--------------------------------------------------------------
void ofApp::setup(){
    beat.load("beat.wav");
    sauce.load("sauce.jpg");
    
    fftSmooth = new float [8192];
    for (int i = 0; i < 8192; i++) {
        fftSmooth[i] = 0.0;
    }
    bands = 64;
    
    beat.setLoop(true);
    
}

//--------------------------------------------------------------
void ofApp::update(){
    ofSoundUpdate();
    sauce.load("sauce.jpg");
    
    float * value = ofSoundGetSpectrum(bands);
    for (int i = 0; i < bands; i++) {
        fftSmooth [i] *= 0.4f;
        if (fftSmooth[i] < value[i]) {
            fftSmooth[i] = value[i] ;
            
        }
    }
}


//--------------------------------------------------------------
void ofApp::draw(){
    sauce.draw(0,0);

    for (int i = 0; i < bands; i++) {
        ofDrawCircle(ofGetWidth()/2, ofGetHeight()/2, -(fftSmooth[i]*150));
            ofSetColor(255,0,i*4,125);
    }

}

//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch (key) {
        case '1':
            beat.play();
            break;
            
        case '2':
            beat.stop();
            break;
    }

}

//--------------------------------------------------------------
void ofApp::keyReleased(int key){

}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void ofApp::mouseEntered(int x, int y){

}

//--------------------------------------------------------------
void ofApp::mouseExited(int x, int y){

}

//--------------------------------------------------------------
void ofApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void ofApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void ofApp::dragEvent(ofDragInfo dragInfo){ 

}
