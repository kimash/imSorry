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
    player[0].setFrame(141);
    player[1].setFrame(171);
    player[2].setFrame(187);
    
    for (int i = 0; i < 3; i++) {
        player[i].play();
    }
//    vidFbo.allocate(player[0].getWidth()*3, player[0].getHeight());
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
//    vidFbo.begin();
    //want subsection of video - get rid of black bars
    for (int i = 0; i < 3; i++) {
//        player[i].draw(-player[i].getWidth()/4, 0);
        //player[i].draw((i+0.5)*player[i].getWidth()/2, 0);
        player[i].draw(i*player[i].getWidth(), 0);
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