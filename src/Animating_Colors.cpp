//============================================================================
// Name        : Animating_Colors.cpp
// Author      : 
// Version     :
// Copyright   : 
// Description : Hello World in C++, Ansi-style
//============================================================================

#include "Screen.h"

using namespace cave;

int main(int argc, char *argv[]) {
    Screen screen;

    //initalize everything, if something is wrong cout error
    if (screen.init() == false) {
	cout << "Error initialising SDL!" << endl;
    }

    /*int max = 0; //this is to check what our max number is reaching during the loops*/

    //game loop	-update particles, draw particles, check for messages/events
    while (true) {
	int elapsed = SDL_GetTicks(); // SDL_GetTicks returns number of milliseconds since program was started
	unsigned char green = (unsigned char) ((1 + sin(elapsed * .001)) * 128);
	unsigned char red = (unsigned char) ((1 + sin(elapsed * .002)) * 128);
	unsigned char blue = (unsigned char) ((1 + sin(elapsed * .003)) * 128);
	/* sin retuns a number ranging from -1 to +1
	 * we multi by .001 to get a smoother trans between returns
	 * the +1 moves the range from -1 to +1 now to 0 - +2
	 * b/c the returns were so small we used 'double' instead of in in begining
	 * the values we want are 0-255 so we multi by 128 to get to that range
	 * using 'unsigned char' b/c char only goes to 255, so if numb hits 256 it'll jump randomly
	 * need to cast [(unsig char) (1+sin..)] b/c ((1+sin...) is not a char
	 * */

	/*if (green > max) {
	 max = green; //sets 'max' to whatever the highest numb green gets too
	 }*/

	//set a big block of color
	for (int y = 0; y < Screen::SCREEN_HEIGHT; y++) { //work your way down screen
	    for (int x = 0; x < Screen::SCREEN_WIDTH; x++) { //work your way across screen
		screen.setPixel(x, y, red, green, blue, 255);
	    }
	}

	//draw onto screen
	screen.update();

	if (screen.processEvents() == false) {
	    break; //break out of loop!
	}
    }
    /*cout << "Max: " << max << endl;*/
    screen.close();

    return 0;
}
