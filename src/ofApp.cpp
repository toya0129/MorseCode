#include "ofApp.h"
//--------------------------------------------------------------
void ofApp::setup(){
    ofSetFrameRate(60);
    ofSetCircleResolution(64);
    ofBackground(0, 0, 0);
    
    font.load("fonts/Line-Light.otf", 30);
}

void ofApp::initialized(){
    text_trigger = 0;
    words.clear();
    codes.clear();
    
    circle_alpha = 0;
    flash_trigger = true;
    code_trigger = 0;
    
    timer_trigger = false;
    time_count = 0;
}
//--------------------------------------------------------------
void ofApp::update(){

}
void ofApp::TimeCount(){
    if(time_count > 500){
        timer_trigger = true;
        time_count = 0;
    }else{
        time_count += 50;
    }
}
//--------------------------------------------------------------
void ofApp::draw(){
    drawMenuText();
    drawInputText();
    if(text_trigger == 2){
        if(timer_trigger){
            MorseSignal();
        }else{
            TimeCount();
        }
    }
}

void ofApp::drawMenuText(){
    ofSetColor(255, 255, 0);
    
    // 0:none 1:type_start 2:morse_start
    switch(text_trigger){
        case 1:
            font.drawString("Type a Message - Max 50 -", 200, 200);
            font.drawString("Press Enter to Finish", 300, 250);
            break;
        case 2:
            break;
        default:
            font.drawString("Press the Enter", 300, 200);
            break;
    }
    
}

void ofApp::drawInputText(){
    int n = 0;
    int x = -50;
    int y = 300;
    for(itr_words = words.begin(); itr_words != words.end(); itr_words++){
        if(text_trigger == 2){
            if(words.size() - codes.size() == n){
                ofSetColor(255, 0, 0);
            }else{
                ofSetColor(0, 255, 255);
            }
        }else{
            ofSetColor(0, 255, 255);
        }
        x += 100;
        font.drawString(*itr_words, x, y);
        if(x % 95 == 0){
            x = -50;
            y += 100;
        }
        n++;
    }
    if(words.size() >= 50){
        text_trigger = 2;
    }
}

void ofApp::MorseSignal(){
    string out_data = morse_data[*codes.begin()];
    int data_num = (int)(out_data[code_trigger] - '0');
    
    if(code_trigger >= out_data.size()){
        timer_trigger = false;
        codes.pop_front();
        code_trigger = 0;
        circle_alpha = 0;
    }else{
        ofSetColor(255, 255, 255, circle_alpha);
        ofCircle(500, 150, 100);
    }
            
    if(circle_alpha > circle_alpha_max[data_num]){
        flash_trigger = false;
    }else if(circle_alpha < 0){
        flash_trigger = true;
        code_trigger++;
    }
        
    if(flash_trigger){
        circle_alpha += 100;
    }else{
        circle_alpha -= 5;
    }
    
    if(codes.size() <= 0){
        initialized();
    }
}
//--------------------------------------------------------------
void ofApp::keyPressed(int key){
    switch(text_trigger){
        case 0:
            if(key == 13){
                text_trigger = 1;
            }
            break;
        case 1:
            switch(key){
                case 'a':
                    words.push_back("a");
                    codes.push_back(0);
                    break;
                case 'b':
                    words.push_back("b");
                    codes.push_back(1);
                    break;
                case 'c':
                    words.push_back("c");
                    codes.push_back(2);
                    break;
                case 'd':
                    words.push_back("d");
                    codes.push_back(3);
                    break;
                case 'e':
                    words.push_back("e");
                    codes.push_back(4);
                    break;
                case 'f':
                    words.push_back("f");
                    codes.push_back(5);
                    break;
                case 'g':
                    words.push_back("g");
                    codes.push_back(6);
                    break;
                case 'h':
                    words.push_back("h");
                    codes.push_back(7);
                    break;
                case 'i':
                    words.push_back("i");
                    codes.push_back(8);
                    break;
                case 'j':
                    words.push_back("j");
                    codes.push_back(9);
                    break;
                case 'k':
                    words.push_back("k");
                    codes.push_back(10);
                    break;
                case 'l':
                    words.push_back("l");
                    codes.push_back(11);
                    break;
                case 'm':
                    words.push_back("m");
                    codes.push_back(12);
                    break;
                case 'n':
                    words.push_back("n");
                    codes.push_back(13);
                    break;
                case 'o':
                    words.push_back("o");
                    codes.push_back(14);
                    break;
                case 'p':
                    words.push_back("p");
                    codes.push_back(15);
                    break;
                case 'q':
                    words.push_back("q");
                    codes.push_back(16);
                    break;
                case 'r':
                    words.push_back("r");
                    codes.push_back(17);
                    break;
                case 's':
                    words.push_back("s");
                    codes.push_back(18);
                    break;
                case 't':
                    words.push_back("t");
                    codes.push_back(19);
                    break;
                case 'u':
                    words.push_back("u");
                    codes.push_back(20);
                    break;
                case 'v':
                    words.push_back("v");
                    codes.push_back(21);
                    break;
                case 'w':
                    words.push_back("w");
                    codes.push_back(22);
                    break;
                case 'x':
                    words.push_back("x");
                    codes.push_back(23);
                    break;
                case 'y':
                    words.push_back("y");
                    codes.push_back(24);
                    break;
                case 'z':
                    words.push_back("z");
                    codes.push_back(25);
                    break;
                    
                case 13:
                    text_trigger = 2;
                    break;
            }
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
