#pragma once

#include "ofMain.h"

class Ball {

 public:
    ofPoint pos; 
    float radius; 
    ofPoint speed;
    float phase; 
    float phaseSpeed;
    float strechedRadius;
    
    Ball();
    void draw();
    void update();
    void setRadius(float radius);
    float getRadius();
    void setPos(ofPoint pos);
    ofPoint getPos();
    void setSpeed(ofPoint speed);
    ofPoint getSpeed();
};
