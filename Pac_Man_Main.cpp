#include "Refresh_Draw.h"
#include "DataSave.h"

#include <iostream>
#include <cmath>

//bool newGame(PARAMETERS int level, )
//{
//First we create a window

//We load the scoreboards from the PLAYER_DATAPATH

//Now we load the UI elements
/*
LIVES ----------             LEVEL X                  SCORE: XXXXX
|--------------|									  |-------------|
|			   |									  |				|
|	CONTROLS   |           MAIN LEVEL FRAME           |	 SCOREBOARD	|
|			   |									  |			    |
|--------------|									  |-------------|
*/
//We load the level progression

//We start the gameloop

//IF the game is lost the data of the current player is saved
//}

//const float GENERAL_REFRESH_FPS = 29.4;

int main()
{
	FreeConsole(); //Hides the console.
	srand(time(NULL)); //Random numbers.

	bool done = false, draw = false, nextLevel = false;
	playerArray data;
	playerData currentPlayer;
	std::string introduce_name = "";
	ALLEGRO_DISPLAY * display = nullptr;
	ALLEGRO_TIMER *general_timer = nullptr;
	ALLEGRO_EVENT_QUEUE *event_queue = nullptr;
	ALLEGRO_KEYBOARD_STATE keyState;
	ALLEGRO_COLOR back_color = al_map_rgb(0, 0, 0);

	//Initialize Programme

	initializeFramework(true, true, false, true, true, true, 2);
	createDisplay(display, SCREEN_WIDTH, SCREEN_HEIGHT, 0, 0, "Pacman", standard);
	initializeEvent(display, event_queue, true, true, false);

	//Creating Classes

	Level level;
	UserInterface UI;
	Player pacman(level);
	Enemy rg(RED, level);
	Enemy bg(BLUE, level);
	Enemy og(ORANGE, level);
	Enemy pg(PINK, level);

	//Load Data

	LoadAndDecryptFile(data);

	//Initial

	UI.drawUI();
	UI.refreshScoreboard(data);
	drawLevel(level, pacman, rg, pg, og, bg, back_color, SCREEN_WIDTH, SCREEN_HEIGHT);
	showScreen(back_color);
	
	//Set Timer

	createTimer(general_timer, GENERAL_REFRESH_FPS);
	registerTimer(event_queue, general_timer);
	startTimer(general_timer);	

	//Game Loop

	while (!done) {
		ALLEGRO_EVENT events;
		waitEvent(event_queue, events);

		//Keyboard events
		if (events.type == EVENT_KEY_DOWN) {
			if (UI.GetNameDone()) {
				switch (events.keyboard.keycode) {
				case KEY_D:
				case KEY_RIGHT: {
					if (!(UI.GetPause() || UI.GetReset() || UI.GetGameOver() || pacman.GetDead())) {
						if (movementPossible(level.GetMap(), pacman.GetPositionX() + 1, pacman.GetPositionY())) {
							pacman.SetDirection(RIGHT);
						}
							pacman.SetNextDirection(RIGHT);
					}
				}break;
				case KEY_A:
				case KEY_LEFT: {
					if (!(UI.GetPause() || UI.GetReset() || UI.GetGameOver() || pacman.GetDead())) {
						if (movementPossible(level.GetMap(), pacman.GetPositionX() - 1, pacman.GetPositionY())) {
							pacman.SetDirection(LEFT);
						}
							pacman.SetNextDirection(LEFT);
					}
				}break;
				case KEY_W:
				case KEY_UP: {
					if (!(UI.GetPause() || UI.GetReset() || UI.GetGameOver() || pacman.GetDead())) {
						if (movementPossible(level.GetMap(), pacman.GetPositionX(), pacman.GetPositionY() - 1)) {
							pacman.SetDirection(UP);
						}
							pacman.SetNextDirection(UP);
					}
				}break;
				case KEY_S:
				case KEY_DOWN: {
					if (!(UI.GetPause() || UI.GetReset() || UI.GetGameOver() || pacman.GetDead())) {
						if (movementPossible(level.GetMap(), pacman.GetPositionX(), pacman.GetPositionY() + 1)) {
							pacman.SetDirection(DOWN);
						}
							pacman.SetNextDirection(DOWN);
					}
				}break;
				case KEY_P: {
					if (!UI.GetGameOver()) {
						if (UI.GetPause()) {
							UI.SetPause(false);
							UI.SetAudio(true);
							UI.PlayThisSong(UI.GetpacmanSongInstance());
						}
						else {
							UI.SetPause(true);
							UI.SetAudio(false);
						}
					}
				}break;
				case KEY_O: {
					UI.SetKeyAudio();
				}break;
				case KEY_ENTER: {
					if (UI.GetGameOver()) {
						UI.SetGameOver(false);
						UI.SetReset(true);
						UI.SetResetCounter(2);
					}
				}break;
				case KEY_N: {
					nextLevel = true;
				}break;
				case KEY_ESCAPE: {
					done = true;
				}
				}
			}
			else {
					switch (events.keyboard.keycode) {
					case KEY_A:	if (introduce_name.length() < 10) introduce_name += 'a'; break;
					case KEY_B: if (introduce_name.length() < 10) introduce_name += 'b'; break;
					case KEY_C: if (introduce_name.length() < 10) introduce_name += 'c'; break;
					case KEY_D: if (introduce_name.length() < 10) introduce_name += 'd'; break;
					case KEY_E: if (introduce_name.length() < 10) introduce_name += 'e'; break;
					case KEY_F: if (introduce_name.length() < 10) introduce_name += 'f'; break;
					case KEY_G: if (introduce_name.length() < 10) introduce_name += 'g'; break;
					case KEY_H: if (introduce_name.length() < 10) introduce_name += 'h'; break;
					case KEY_I: if (introduce_name.length() < 10) introduce_name += 'i'; break;
					case KEY_J: if (introduce_name.length() < 10) introduce_name += 'j'; break;
					case KEY_K: if (introduce_name.length() < 10) introduce_name += 'k'; break;
					case KEY_L: if (introduce_name.length() < 10) introduce_name += 'l'; break;
					case KEY_M: if (introduce_name.length() < 10) introduce_name += 'm'; break;
					case KEY_N: if (introduce_name.length() < 10) introduce_name += 'n'; break;
					case KEY_O: if (introduce_name.length() < 10) introduce_name += 'o'; break;
					case KEY_P: if (introduce_name.length() < 10) introduce_name += 'p'; break;
					case KEY_Q: if (introduce_name.length() < 10) introduce_name += 'q'; break;
					case KEY_R: if (introduce_name.length() < 10) introduce_name += 'r'; break;
					case KEY_S: if (introduce_name.length() < 10) introduce_name += 's'; break;
					case KEY_T: if (introduce_name.length() < 10) introduce_name += 't'; break;
					case KEY_U: if (introduce_name.length() < 10) introduce_name += 'u'; break;
					case KEY_V: if (introduce_name.length() < 10) introduce_name += 'v'; break;
					case KEY_W: if (introduce_name.length() < 10) introduce_name += 'w'; break;
					case KEY_X: if (introduce_name.length() < 10) introduce_name += 'x'; break;
					case KEY_Y: if (introduce_name.length() < 10) introduce_name += 'y'; break;
					case KEY_Z: if (introduce_name.length() < 10) introduce_name += 'z'; break;
					case KEY_BACKSPACE: if (introduce_name.length() > 0) introduce_name.pop_back(); break;
					case KEY_ENTER: {
						UI.SetNameDone(true);
						UI.SetPlayerName(introduce_name);
						introduce_name = "";
						UI.SetReset(true);
						UI.SetSubLiveReset(false);
						
					} break;
					case KEY_ESCAPE: {
						done = true;
					}
					}
					if(!UI.GetNameDone()) UI.SetPlayerName(introduce_name);
				}
			}
			
		//Display events
		else if (events.type == EVENT_DISPLAY_CLOSE) {
			done = true;
		}
		//Timer Events
		else if (events.type == EVENT_TIMER) {
			draw = true;
			if (UI.GetNameDone()) {
				if (!UI.GetPause() && !UI.GetReset() && !UI.GetGameOver()) {
					refreshLevel(level, pacman, rg, pg, og, bg, UI);

					if (pacman.GetProgress() == level.GetObjective() || nextLevel)
					{
						if (level.GetCurrentLevel() < level.GetNumMap()) {
							level.NextLevel();
							UI.increaseLevel();
							UI.SetReset(true);
							UI.SetSubLiveReset(false);
							pacman.ResetProgress();
							nextLevel = false;
						}
						else {
							level.GameReset();
							UI.resetLevel();
							UI.SetReset(true);
							UI.SetSubLiveReset(false);
							pacman.ResetProgress();
							nextLevel = false;
						}
					}

				}
				else if (UI.GetReset() && !UI.GetPause()) {
					UI.SetAudio(false);
					if (UI.GetResetCounter() == 1) {
						UI.MakeReset(level, pacman, rg, pg, og, bg);
					}
					if (UI.GetResetCounter() < RESET_COUNTER_MAX) {
						UI.SetResetCounter(UI.GetResetCounter() + 1);
					}
					else {
						UI.SetAudio(true);
						UI.PlayThisSong(UI.GetpacmanSongInstance());
						UI.SetResetCounter(1);
						UI.SetReset(false);
					}
				}
				else if (UI.GetGameOver() && UI.GetAuxGameOver()) {
					UI.SetAudio(false);
					currentPlayer.name = UI.GetPlayerName();
					currentPlayer.score = UI.GetScore();
					AddData(data, currentPlayer);
					UI.MakeGameOver(level, pacman, rg, pg, og, bg);
					UI.SetAuxGameOver(false);
				}
			}
		}
		
		if (draw) {
			UI.drawUI();
			UI.refreshScoreboard(data);
			drawLevel(level, pacman, rg, pg, og, bg, back_color, SCREEN_WIDTH, SCREEN_HEIGHT);
			if (UI.GetReset() && !UI.GetPause()) {
				UI.drawReset();
			}
			if (UI.GetGameOver()) {
				UI.drawGameOver();
			}
			if (UI.GetPause() && !UI.GetGameOver()) {
				UI.drawPause();
			}
			if (!UI.GetNameDone()) {
				UI.drawName();
			}
			showScreen(back_color);
			draw = false;
		}
	}

	//Saving Data

	SaveAndEncrypt(data);

	//Destroying programme

	destroyFramework(true, true, false, true, true, true);

	return 0;
}