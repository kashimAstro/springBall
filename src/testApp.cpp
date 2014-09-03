#include "testApp.h"

ofPolyline mesh;

void testApp::setup(){
    ofSetFrameRate(60);
    mesh.simplify(1.);
    mesh.getSmoothed(3);
}

void testApp::update(){
    ofSetWindowTitle(ofToString(ofGetFrameRate()));
    mesh.clear();
    for (int i = 0; i < balls.size(); i++) {
        balls[i].update();
	float z = 0;
	ofPoint sp = ofPoint(balls[i].getPos().x, balls[i].getPos().y, z);
	mesh.curveTo(sp*1.0);
    }
}

void testApp::draw(){
    ofBackgroundGradient(ofColor(0,0,0),ofColor(40,40,40));
    ofNoFill();
    ofSetColor(255,255,255);
    mesh.draw();
    ofFill();
    for (int i = 0; i < balls.size(); i++) {
        balls[i].draw();
    }
}

void testApp::keyPressed(int key){
}

void testApp::keyReleased(int key){
    switch (key) {
        case 'f': 
            ofToggleFullscreen();
            break;
        case 'r': 
            balls.clear();
    }
}

void testApp::mouseMoved(int x, int y){
}

void testApp::mouseDragged(int x, int y, int button){
}

void testApp::mousePressed(int x, int y, int button){
}

void testApp::mouseReleased(int x, int y, int button){
    int bSize = balls.size(); 
    if (bSize < 1) { 
        Ball b = Ball(); 
        float radius = ofGetHeight()/4;
        b.setRadius(radius); 
        b.setSpeed(ofPoint(0,0));
        b.setPos(ofPoint(mouseX, mouseY)); 
        balls.push_back(b); 
    }

    for (int i=0; i<bSize; i++) { 
        ofPoint pos = balls[i].getPos(); 
        float radius = balls[i].getRadius(); 
        float dist = ofDist(pos.x, pos.y, mouseX, mouseY); 
        if(dist < radius){ 
            balls[i].setRadius(radius*0.6);
            balls[i].setPos(ofPoint(pos.x-radius*0.7,pos.y));
            balls[i].setSpeed(ofPoint(ofRandom(-radius/150,radius/150), ofRandom(-radius/150,radius/150)));
            Ball b1 = Ball();
            b1.setRadius(radius*0.6);
            b1.setPos(ofPoint(pos.x+radius*0.7,pos.y));
            b1.setSpeed(ofPoint(ofRandom(-radius/150,radius/150), ofRandom(-radius/150,radius/150)));
            balls.push_back(b1);
            
            Ball b2 = Ball();
            b2.setRadius(radius*0.6);
            b2.setPos(ofPoint(pos.x,pos.y-radius*0.7));
            b2.setSpeed(ofPoint(ofRandom(-radius/150,radius/150), ofRandom(-radius/150,radius/150)));
            balls.push_back(b2);
            
            Ball b3 = Ball();
            b3.setRadius(radius*0.6);
            b3.setPos(ofPoint(pos.x,pos.y+radius*0.7));
            b3.setSpeed(ofPoint(ofRandom(-radius/150,radius/150), ofRandom(-radius/150,radius/150)));
            balls.push_back(b3);
        }
    }
}


void testApp::windowResized(int w, int h){
    
}

void testApp::gotMessage(ofMessage msg){
    
}

void testApp::dragEvent(ofDragInfo dragInfo){ 
    
}
