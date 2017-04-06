#include "ofApp.h"


//--------------------------------------------------------------
void ofApp::setup(){
    fishlogo.load("fish.png");
    fishthekid.load ("fishbackground.jpg");
    note.load("note.png");
    basspic.load("basspic.png");
    snarepic.load("snarepic.png");
    cymbolpic.load("cymbalspic.png");
    shakerpic.load("shakerpic.png");
    
    
	// load in sounds:
	snare.load("sounds/sound 1.wav");
	high.load("sounds/sound 3.wav");
	bass.load("sounds/sound 2.wav");
	fish.load("sounds/sound 4.wav");
    pianoconstant.load("sounds/piano.wav");
	
	// we will bounce a circle using these variables:
	px = 700;
	py = 700;
	vx = 0;
	vy = 0;	

	// the fft needs to be smoothed out, so we create an array of floats
	// for that purpose:
	fftSmoothed = new float[8192];
	for (int i = 0; i < 8192; i++){
		fftSmoothed[i] = 0;
	}
	
	nBandsToGet = 100;
    
    
    
}


//--------------------------------------------------------------
void ofApp::update(){
	
	ofBackground(255,192,205);

	// update the sound playing system:
	ofSoundUpdate();	
	
	// (1) we increase px and py by adding vx and vy
	px += vx;
	py += vy;
	
	// (2) check for collision, and trigger sounds:
	// horizontal collisions:
	if (px < 0){
		px = 0;
		vx *= -1;
		snare.play();
	} else if (px > ofGetWidth()){
		px = ofGetWidth();
		vx *= -1;
		bass.play();
	}
	// vertical collisions:
	if (py < 0 ){
		py = 0;
		vy *= -1;
		high.play();
	} else if (py > ofGetHeight()){
		py = ofGetHeight();
		vy *= -1;
		fish.play();
	}
	// (3) slow down velocity:
	vx 	*= 0.996f;
	vy 	*= 0.996f;

	// (4) we use velocity for volume of the samples:
	float vel = sqrt(vx*vx + vy*vy);
	snare.setVolume(MIN(vel/5.0f, 1));
	bass.setVolume(MIN(vel/5.0f, 1));
	high.setVolume(MIN(vel/5.0f, 1));
	fish.setVolume(MIN(vel/5.0f, 1));

	// (5) grab the fft, and put in into a "smoothed" array,
	//		by taking maximums, as peaks and then smoothing downward
	float * val = ofSoundGetSpectrum(nBandsToGet);		// request 128 values for fft
	for (int i = 0;i < nBandsToGet; i++){
		
		// let the smoothed value sink to zero:
		fftSmoothed[i] *= 0.96f;
		
		// take the max, either the smoothed or the incoming:
		if (fftSmoothed[i] < val[i]) fftSmoothed[i] = val[i];
		
	}


}

//--------------------------------------------------------------
void ofApp::draw(){
    ofSetColor(255,255, 255);
    fishthekid.draw (179,100);
    fishthekid.resize(900,600);
    fishlogo.draw (ofGetWidth()/2 -200,ofGetHeight()/2 -200);
    fishlogo.resize(400, 400);
    snarepic.draw (30,350);
    snarepic.resize(100, 100);
    basspic.draw(1125, 350);
    basspic.resize(100, 100);
    cymbolpic.draw(570,690);
    cymbolpic.resize(120,120);
    shakerpic.draw(600,10);
    shakerpic.resize(90, 85);
    
    


	

	
	// draw the fft resutls:
ofSetColor (253, 253, 150);
	float width = 450/ nBandsToGet;
    float height = 0;
	for (int i = 20;i < nBandsToGet; i++){
		ofDrawRectangle(i*10.5,700,8,-(fftSmoothed[i] * 200));
    
        
        
	
    }
    note.draw(px,py,50,50);
    

}


//--------------------------------------------------------------
void ofApp::keyPressed  (int key){ 
}



//--------------------------------------------------------------
void ofApp::keyReleased(int key){ 
	
}

//--------------------------------------------------------------
void ofApp::mouseMoved(int x, int y ){
	
}

//--------------------------------------------------------------
void ofApp::mouseDragged(int x, int y, int button){
	// add into vx and vy a small amount of the change in mouse:
	vx += (x - prevx) / 40.0f;
	vy += (y - prevy) / 40.0f;
	// store the previous mouse position:
	prevx = x;
	prevy = y;
}
 
//--------------------------------------------------------------
void ofApp::mousePressed(int x, int y, int button){
	prevx = x;
	prevy = y;
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

