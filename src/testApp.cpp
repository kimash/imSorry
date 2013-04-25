#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
    if(!player.loadMovie("EPVAmjpg.mov"))   {
        ofLogError("Video failed to load!");
    }
    else    {
        ofEnableAlphaBlending();
        ofEnableSmoothing();
        player.play();
        vidFbo.allocate(player.getWidth()/2, player.getHeight());
    }
}

//--------------------------------------------------------------
void testApp::update(){
    player.update();
}

//--------------------------------------------------------------
void testApp::draw(){
    vidFbo.begin();
    //want subsection of video - get rid of black bars
    player.draw(-player.getWidth()/4, 0);
    vidFbo.end();
    
    ofVec3f center = ofVec3f(ofGetWidth()/4, ofGetHeight()/2, 0);
    ofRectangle fboRectangle = ofRectangle(0,0,vidFbo.getWidth(), vidFbo.getHeight());
    //mapping texture to mesh
    for (int i = 0; i < 3; i++) {
        mesh[i].addTexCoord(fboRectangle.getTopLeft());
        mesh[i].addVertex(ofVec3f((i+0.5)*player.getWidth()/2, center.y, center.z) + ofVec3f(-fboRectangle.getWidth()/2, -fboRectangle.getHeight()/2, 0));
        mesh[i].addTexCoord(fboRectangle.getBottomLeft());
        mesh[i].addVertex(ofVec3f((i+0.5)*player.getWidth()/2, center.y, center.z) + ofVec3f(-fboRectangle.getWidth()/2, fboRectangle.getHeight()/2, 0));
        mesh[i].addTexCoord(fboRectangle.getTopRight());
        mesh[i].addVertex(ofVec3f((i+0.5)*player.getWidth()/2, center.y, center.z) + ofVec3f(fboRectangle.getWidth()/2, -fboRectangle.getHeight()/2, 0));
        mesh[i].addTexCoord(fboRectangle.getBottomRight());
        mesh[i].addVertex(ofVec3f((i+0.5)*player.getWidth()/2, center.y, center.z) + ofVec3f(fboRectangle.getWidth()/2, fboRectangle.getHeight()/2, 0));
        mesh[i].setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
        
        vidFbo.getTextureReference().bind();
        mesh[i].draw();
        vidFbo.getTextureReference().unbind();
    }
}

//--------------------------------------------------------------
void testApp::keyPressed(int key){

}

//--------------------------------------------------------------
void testApp::keyReleased(int key){

}

//--------------------------------------------------------------
void testApp::mouseMoved(int x, int y ){

}

//--------------------------------------------------------------
void testApp::mouseDragged(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mousePressed(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::mouseReleased(int x, int y, int button){

}

//--------------------------------------------------------------
void testApp::windowResized(int w, int h){

}

//--------------------------------------------------------------
void testApp::gotMessage(ofMessage msg){

}

//--------------------------------------------------------------
void testApp::dragEvent(ofDragInfo dragInfo){ 

}