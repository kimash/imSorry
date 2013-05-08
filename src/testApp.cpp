#include "testApp.h"

//--------------------------------------------------------------
void testApp::setup(){
//    if(!player.loadMovie("EPVAmjpg.mov"))   {
//        ofLogError("Video failed to load!");
//    }
//    else    {
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            player[i][j].loadMovie("EPVA_finalmjpg.mov");
        }
    }
    ofBackground(0);
    ofSetFullscreen(true);   
//    ofEnableAlphaBlending();
    ofEnableSmoothing();
    player[0][0].setFrame(1574);
    player[0][1].setFrame(761);
    player[0][2].setFrame(368);
    player[1][0].setFrame(171);
    player[1][1].setFrame(419);
    player[1][2].setFrame(295);
    player[2][0].setFrame(1509);
    player[2][1].setFrame(1165);
    player[2][2].setFrame(930);
    player[3][0].setFrame(1233);
    player[3][1].setFrame(512);
    player[3][2].setFrame(874);
    player[4][0].setFrame(406);
    player[4][1].setFrame(230);
    player[4][2].setFrame(811);
    player[5][0].setFrame(699);
    player[5][1].setFrame(141);
    player[5][2].setFrame(993);
    player[6][0].setFrame(467);
    player[6][1].setFrame(1651);
    player[6][2].setFrame(1311);
    
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            player[i][j].play();
        }
    }
}

//--------------------------------------------------------------
void testApp::update(){
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            player[i][j].update();
        }
    }
}

//--------------------------------------------------------------
void testApp::draw(){
    for (int i = 0; i < 7; i++) {
        for (int j = 0; j < 3; j++) {
            player[i][j].draw(i*200 + 25, j*300, 200, 300);
        }
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