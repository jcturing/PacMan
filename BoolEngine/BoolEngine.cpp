#include "BoolEngine.h"

bool initializeFramework(bool keyboard, bool mouse, bool joystick, bool image, bool font, bool audio, int samples) {
	bool initialize = false;

	if (al_init()) {
		initialize = true;
		if (keyboard) al_install_keyboard();
		if (mouse) al_install_mouse();
		if (joystick) al_install_joystick();
		if (image) al_init_image_addon();
		if (font) {
			al_init_font_addon();
			al_init_ttf_addon();
		}
		if (audio) {
			al_install_audio();
			al_init_acodec_addon();
			al_reserve_samples(samples);
		}
	}
	return initialize;
}

void destroyFramework(bool keyboard, bool mouse, bool joystick, bool image, bool font, bool audio) {
	if (keyboard) al_uninstall_keyboard();
	if (mouse) al_uninstall_mouse();
	if (joystick) al_uninstall_joystick();
	if (image) al_shutdown_image_addon();
	if (font) 	al_shutdown_font_addon();
	if (audio) al_uninstall_audio();
}
