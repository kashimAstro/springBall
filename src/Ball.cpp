#include "Ball.h"

Ball::Ball() {
    pos = ofPoint(ofGetWidth()/2, ofGetHeight()/2); 
    radius = 30.0; 
    speed = ofPoint(0, 0); 
    phaseSpeed = ofRandom(0.1, 0.5); 
    phase = 0;
}

void Ball::draw() {
    ofNoFill();
    ofSetColor(ofColor(100,100,100, 125));
    ofDrawBox(pos.x, pos.y, 0,  strechedRadius, strechedRadius, strechedRadius); 

    ofSetColor(ofColor(255, 55, 55, 255));
    ofDrawIcoSphere(pos.x, pos.y, radius/4);
}

void Ball::update() {
    strechedRadius = radius + sin(phase)*radius/6;
    phase += phaseSpeed;
    if(phase > TWO_PI){
        phase -= TWO_PI;
    }
    
    pos += speed;
    if(pos.x < radius || pos.x > ofGetWidth()-radius){
        speed.x *= -1;
    }
    if(pos.y < radius || pos.y > ofGetHeight()-radius){
        speed.y *= -1;
    }
}

void Ball::setPos(ofPoint _pos) {
    pos = _pos;
}

ofPoint Ball::getPos() {
    return pos;
}

void Ball::setRadius(float _radius) {
    radius = _radius;
}

float Ball::getRadius() {
    return radius;
}

void Ball::setSpeed(ofPoint _speed) {
    speed = _speed;
}

ofPoint Ball::getSpeed() {
    return speed;
}
