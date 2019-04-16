#ifndef REFRESH_DRAW
#define REFRESH_DRAW

#include "Enemies.h"
#include "ScoreObjects.h"
#include <iostream>

//CONSTANTS

const int RESET_SECONDS = 3;
const int DEAD_ANIMATION_SECONDS = 2;
const float GENERAL_REFRESH_FPS = 29.4;
const int RESET_COUNTER_MAX = RESET_SECONDS / (1 / GENERAL_REFRESH_FPS);
const int DEAD_ANIMATION_COUNTER_MAX = 40;

//USER INTERFACE

class UserInterface {
public:
	UserInterface();

	void drawUI();
	void PlayThisSound(ALLEGRO_SAMPLE * sound);
	void PlayThisSong(ALLEGRO_SAMPLE_INSTANCE * instance);
	void StopThisSong(ALLEGRO_SAMPLE_INSTANCE * instance);
	void copyLives(int l);
	void increaseLevel();
	void resetLevel();
	void refreshScoreboard(const playerArray & p);
	void SetPause(bool option);
	void SetGameOver(bool option);
	void SetAuxGameOver(bool option);
	void SetReset(bool option);
	void SetResetCounter(int i);
	void SetAudio(bool option);
	void SetNameDone(bool option);
	void SetKeyAudio();
	void SetPlayerName(std::string name);
	void SetSubLiveReset(bool option);

	void MakeReset(Level &level, Player &pacman, Enemy &rg, Enemy &pg, Enemy &og, Enemy &bg);
	void MakeGameOver(Level &level, Player &pacman, Enemy &rg, Enemy &pg, Enemy &og, Enemy &bg);
	
	void drawName();
	void drawGameOver();
	void drawPause();
	void drawReset();
	void drawGhostDead(int i, int j, int num);

	bool GetPause() const;
	bool GetGameOver() const;
	bool GetAuxGameOver() const;
	bool GetReset() const;
	bool GetAudio() const;
	bool GetNameDone() const;
	Score GetScore() const;
	std::string GetPlayerName() const;
	int GetResetCounter() const;
	ALLEGRO_SAMPLE_INSTANCE *GetpacmanSongInstance() const;
	ALLEGRO_SAMPLE *GetpacmanFXSound() const;

	~UserInterface();

	Score score;

private:
	ALLEGRO_BITMAP *life, *livesUI, *scoreUI, *scoreBoardUI, *levelBannerUI, *controlsUI_sound, *controlsUI_muted;
	ALLEGRO_FONT *font1, *font2, *font3, *font_gameover, *font_pause, *font_reset, *font_gameover_text, *ghost_dead;

	float UI_LIVES_POS_X, UI_LIVES_POS_Y, LIFE_X_OFFSET, swidth_UI_lives, sheight_UI_lives, swidth_inital_life, sheight_initial_life;
	float CONTROLS_POS_X, CONTROLS_POS_Y, swidth_controls, sheight_controls;

	float LEVEL_BANNER_POS_X, LEVEL_BANNER_POS_Y, swidth_level_banner, sheight_level_banner;
	float LEVEL_TEXT_POS_X, LEVEL_TEXT_POS_Y, LEVEL_TEXT_CONSTRAINT_X, LEVEL_TEXT_CONSTRAINT_Y;

	float SCORE_POS_X, SCORE_POS_Y, swidth_score, sheight_score;
	float SCORE_TEXT_POS_X, SCORE_TEXT_POS_Y, SCORE_TEXT_CONSTRAINT_X, SCORE_TEXT_CONSTRAINT_Y;
	float SCOREBOARD_POS_X, SCOREBOARD_POS_Y, swidth_scoreboard, sheight_scoreboard;
	float TOPSCORES_POS_X, TOPSCORES_POS_Y, TOPSCORES_CONSTRAINT_X, TOPSCORES_CONSTRAINT_Y, TOPSCORES_JUMP_Y;
	float TOPSCORES_SCORE_POS_X, TOPSCORES_SCORE_POS_Y;

	int currentLevel, numLives, reset_counter;
	bool pause, reset, game_over, aux_gameover, audio, key_audio, name_done, sub_live_reset;
	std::string playerName;

	ALLEGRO_SAMPLE * pacmanSong = nullptr, *pacmanFX = nullptr;
	ALLEGRO_SAMPLE_INSTANCE * songInstance = nullptr;
};

//REFRESH & DRAWING FUNCTIONS

void refreshLevel(Level &level, Player &pacman, Enemy &rg, Enemy &pg, Enemy &og, Enemy &bg, UserInterface &UI);
void pacmanRefreshPosition(Level &level, Player &pacman, Enemy &rg, Enemy &pg, Enemy &og, Enemy &bg, UserInterface &UI);
void pacmanRefreshPixel(Level &level, Player &pacman);
void ghostRefreshPosition(Level &level, Enemy &enemy, Player &pacman, Enemy &rg);
void ghostRefreshPixel(Level &level, Enemy &enemy, Player &pacman);
void ghostRefreshState(Enemy &enemy);
void checkCollision(Player &pacman, Enemy &rg, Enemy &pg, Enemy &og, Enemy &bg, UserInterface &UI);
int numDeadGhost(Enemy &rg, Enemy &pg, Enemy &og, Enemy &bg);
void drawLevel(Level &level, Player &pacman, Enemy &rg, Enemy &pg, Enemy &og, Enemy &bg, ALLEGRO_COLOR back_color, int SCREEN_WIDTH, int SCREEN_HEIGHT);

#endif
