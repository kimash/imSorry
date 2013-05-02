#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
//    if(!player.loadMovie("EPVAmjpg.mov"))   {
//        ofLogError("Video failed to load!");
//    }
//    else    {
    for (int i = 0; i < 3; i++) {
        player[i].loadMovie("EPVAmjpg.mov");
    }
    
    ofEnableAlphaBlending();
    ofEnableSmoothing();
    player[0].setFrame(60);
    player[1].setFrame(120);
    player[2].setFrame(180);
    
    for (int i = 0; i < 3; i++) {
        player[i].play();
    }
    vidFbo.allocate(player[0].getWidth()*3, player[0].getHeight());
//    }
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i < 3; i++) {
         player[i].update();
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    vidFbo.begin();
    //want subsection of video - get rid of black bars
    for (int i = 0; i < 3; i++) {
        player[i].draw(-player[i].getWidth()/4, 0);
    }
    vidFbo.end();
    
    ofVec3f center = ofVec3f(ofGetWidth()/4, ofGetHeight()/2, 0);
    ofRectangle fboRectangle = ofRectangle(0,0,vidFbo.getWidth(), vidFbo.getHeight());
    //mapping texture to mesh - take out of for loop to include all vids?
    mesh.addTexCoord(fboRectangle.getTopLeft());
    mesh.addVertex(ofVec3f((0.5)*player[0].getWidth()/2, center.y, center.z) + ofVec3f(-fboRectangle.getWidth()/2, -fboRectangle.getHeight()/2, 0));
    mesh.addTexCoord(fboRectangle.getBottomLeft());
    mesh.addVertex(ofVec3f((0.5)*player[0].getWidth()/2, center.y, center.z) + ofVec3f(-fboRectangle.getWidth()/2, fboRectangle.getHeight()/2, 0));
    mesh.addTexCoord(fboRectangle.getTopRight());
    mesh.addVertex(ofVec3f((0.5)*player[2].getWidth()/2, center.y, center.z) + ofVec3f(fboRectangle.getWidth()/2, -fboRectangle.getHeight()/2, 0));
    mesh.addTexCoord(fboRectangle.getBottomRight());
    mesh.addVertex(ofVec3f((0.5)*player[2].getWidth()/2, center.y, center.z) + ofVec3f(fboRectangle.getWidth()/2, fboRectangle.getHeight()/2, 0));
    mesh.setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
    
    vidFbo.getTextureReference().bind();
    mesh.draw();
    vidFbo.getTextureReference().unbind();
//    for (int i = 0; i < 3; i++) {
//        mesh[i].addTexCoord(fboRectangle.getTopLeft());
//        mesh[i].addVertex(ofVec3f((i+0.5)*player[i].getWidth()/2, center.y, center.z) + ofVec3f(-fboRectangle.getWidth()/2, -fboRectangle.getHeight()/2, 0));
//        mesh[i].addTexCoord(fboRectangle.getBottomLeft());
//        mesh[i].addVertex(ofVec3f((i+0.5)*player[i].getWidth()/2, center.y, center.z) + ofVec3f(-fboRectangle.getWidth()/2, fboRectangle.getHeight()/2, 0));
//        mesh[i].addTexCoord(fboRectangle.getTopRight());
//        mesh[i].addVertex(ofVec3f((i+0.5)*player[i].getWidth()/2, center.y, center.z) + ofVec3f(fboRectangle.getWidth()/2, -fboRectangle.getHeight()/2, 0));
//        mesh[i].addTexCoord(fboRectangle.getBottomRight());
//        mesh[i].addVertex(ofVec3f((i+0.5)*player[i].getWidth()/2, center.y, center.z) + ofVec3f(fboRectangle.getWidth()/2, fboRectangle.getHeight()/2, 0));
//        mesh[i].setMode(OF_PRIMITIVE_TRIANGLE_STRIP);
//        
//        vidFbo.getTextureReference().bind();
//        mesh[i].draw();
//        vidFbo.getTextureReference().unbind();
//    }
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