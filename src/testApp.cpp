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
    
    ofVec3f center = ofVec3f(ofGetWidth()/2, ofGetHeight()/2, 0);
    ofRectangle fboRectangle = ofRectangle(0,0,vidFbo.getWidth(), vidFbo.getHeight());
    
    mesh.addTexCoord(fboRectangle.getTopLeft());
    mesh.addVertex( center + ofVec3f(-fboRectangle.getWidth()/2, -fboRectangle.getHeight()/2, 0));
    mesh.addTexCoord(fboRectangle.getBottomLeft());
    mesh.addVertex( center + ofVec3f(-fboRectangle.getWidth()/2, fboRectangle.getHeight()/2, 0));
    mesh.addTexCoord(fboRectangle.getTopRight());
    mesh.addVertex(center + ofVec3f(fboRectangle.getWidth()/2, -fboRectangle.getHeight()/2, 0));
    mesh.addTexCoord(fboRectangle.getBottomRight());
    mesh.addVertex(center + ofVec3f(fboRectangle.getWidth()/2, fboRectangle.getHeight()/2, 0));
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    vidFbo.getTextureReference().bind();
	mesh.draw();
	vidFbo.getTextureReference().unbind();
    
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