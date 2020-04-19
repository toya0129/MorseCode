#pragma once

#include "ofMain.h"
#include <stdio.h>
#include <list>
#include <string>

class ofApp : public ofBaseApp{

    private:
        // 0:none 1:type_start 2:morse_start
        int text_trigger = 0;
        ofTrueTypeFont font;
    
        // 0:* 1:-
        const string morse_data[26] = { "01","1000","1010","100","0","0010","110","0000","00","0111","101","0100","11","10","111","0110","1101","010","000","1","001","0001","011","1001","1011","1100"
        };
    
        int circle_alpha = 0;
        const int circle_alpha_max[2] = { 200, 400};
        bool flash_trigger = true;
        int code_trigger = 0;
    
        bool timer_trigger = false;
        int time_count = 0;
	public:
        std::list<std::string> words;
        std::list<std::string>::iterator itr_words;
    
        std::list<int> codes;
    
		void setup();
        void initialized();
		void update();
        void TimeCount();
		void draw();
    
        void drawMenuText();
        void drawInputText();
        void MorseSignal();
    
		void keyPressed(int key);
		void keyReleased(int key);
		void mouseMoved(int x, int y );
		void mouseDragged(int x, int y, int button);
		void mousePressed(int x, int y, int button);
		void mouseReleased(int x, int y, int button);
		void mouseEntered(int x, int y);
		void mouseExited(int x, int y);
		void windowResized(int w, int h);
		void dragEvent(ofDragInfo dragInfo);
		void gotMessage(ofMessage msg);
		
};
