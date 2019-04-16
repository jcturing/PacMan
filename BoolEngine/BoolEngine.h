#ifndef BOOLENGINE_H
#define BOOLENGINE_H

/*   ______                 _____    ___
*   /\  _  \               /\__  \  /\__\
*   \ \ \L\/_    ____    __\/__\  \ \/__/_     ____   _______   _______   ______
*    \ \  _  \  /  _ \  /  _ \\ \  \  /\  \   / _  \ /\  ___ \ /\  ___ \ /\  ___\
*     \ \ \L\ |/\ \L\ \/\ \L\ \\_\  \_\ \  \ /\ \L\ \\ \ \__\ \\ \ \_/\ \\ \____ \
*      \ \____/\ \____/\ \____//\_____\\ \__\\ \____ \\ \_\_/\_\\ \_\\ \_\\/\_____\
*	    \/___/  \/___/  \/___/ \/_____/ \/__/ \/___L\ \\/_/ \/_/ \/_/ \/_/ \/_____/
*                                                /\___/
*                                                \/__/
*
*       Main file for the Booligans Engine.
*/

//Framework Libraries
#include "Collision.h"
#include "Control.h"
#include "Graphics.h"
#include "Audio.h"

//GENERAL CONSTANTS
const int FPS = 60;

//GENERAL FUNCTIONS
//Initialize the framework specified. | PARAMETERS: keyboard, mouse, joystick, image, font, audio and the number of audios to use.
bool initializeFramework(bool keyboard, bool mouse, bool joystick, bool image, bool font, bool audio, int samples = 0);
//Destroys the framework specified so that it stops working | PARAMETERS: keyboard, mouse, joystick, image, font, audio and the number of audios to use.
void destroyFramework(bool keyboard, bool mouse, bool joystick, bool image, bool font, bool audio);

#endif
