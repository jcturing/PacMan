#include "Control.h"

void initializeEvent(ALLEGRO_DISPLAY *display, ALLEGRO_EVENT_QUEUE * &event_queue, bool use_display, bool use_keyboard, bool use_mouse) {
	event_queue = al_create_event_queue();
	if (use_display) al_register_event_source(event_queue, al_get_display_event_source(display));
	if (use_keyboard) al_register_event_source(event_queue, al_get_keyboard_event_source());
	if (use_mouse) al_register_event_source(event_queue, al_get_mouse_event_source());
}

void waitEvent(ALLEGRO_EVENT_QUEUE * &event_queue, ALLEGRO_EVENT &events) {
	al_wait_for_event(event_queue, &events);
}

void destroyEvent(ALLEGRO_EVENT_QUEUE * &event_queue) {
	al_destroy_event_queue(event_queue);
	event_queue = nullptr;
}

void waitSeconds(double seconds) {
	al_rest(seconds);
}

void createDisplay(ALLEGRO_DISPLAY * &display, int const& screenHeight, int const& screenWidth, int const& screen_x_position, int const& screen_y_position, std::string screenName, screenType const& screenType) {
	int screenFlag = standard;

	switch (screenType) {
	case standard: screenFlag = ALLEGRO_WINDOWED; break;
	case fullscreen: screenFlag = ALLEGRO_FULLSCREEN; break;
	case fullscreen_window: screenFlag = ALLEGRO_FULLSCREEN_WINDOW; break;
	case resizable: screenFlag = ALLEGRO_WINDOWED | ALLEGRO_RESIZABLE; break;
	case noframe: screenFlag = ALLEGRO_NOFRAME;
	}

	al_set_new_display_flags(screenFlag);
	display = al_create_display(screenHeight, screenWidth);
	al_set_window_position(display, screen_x_position, screen_y_position);
	al_set_window_title(display, screenName.c_str());
}

void destroyDisplay(ALLEGRO_DISPLAY * &display) {
	al_destroy_display(display);
	display = nullptr;
}

void createMessageBox(ALLEGRO_DISPLAY *display, std::string title, std::string heading, std::string text, boxType box_type) {
	al_show_native_message_box(display, title.c_str(), heading.c_str(), text.c_str(), NULL, box_type);
}

void createTimer(ALLEGRO_TIMER * &timer, const double FPS) {
	timer = al_create_timer(1 / FPS);
}

void registerTimer(ALLEGRO_EVENT_QUEUE * &event_queue, ALLEGRO_TIMER *timer) {
	al_register_event_source(event_queue, al_get_timer_event_source(timer));
}

void startTimer(ALLEGRO_TIMER *timer) {
	al_start_timer(timer);
}

void stopTimer(ALLEGRO_TIMER *timer) {
	al_stop_timer(timer);
}

void destroyTimer(ALLEGRO_TIMER * &timer) {
	al_destroy_timer(timer);
	timer = nullptr;
}

void getKeyboard(ALLEGRO_KEYBOARD_STATE &keyState) {
	al_get_keyboard_state(&keyState);
}

bool keyPressed(ALLEGRO_KEYBOARD_STATE &keyState, keycodes key) {
	return al_key_down(&keyState, key);
}
