#ifndef ENEMIES_H
#define ENEMIES_H
#include <cmath>
#include <stdlib.h>
#include <time.h>

#include "Level_Load.h"
#include "Player.h";

typedef enum tState { IDLE, TRANSITION, SCATTER, CHASE, FRIGHTENED, DEAD};
typedef enum tGhost { RED, PINK, BLUE, ORANGE};
const float HUGE_DISTANCE = 1000000;

class Enemy
{
public:
	//Constructors
	Enemy(tGhost type, Level const& level);

	//Methods
	void Reset(Level &level);
	void SetState(tState s);
	void SetPosition(int posX, int posY);
	void SetNextPosition(int posX, int posY);
	void SetInitialPosition(int posX, int posY);
	void SetPixelPosition(float pixel_x, float pixel_y);

	void Draw(float swidth, float sheight, int x, int y);
	void SetTarget(int targetX, int targetY);
	void MoveToTarget(Level &level);

	void SetCounter(int i);
	void SetStateCounter(int i);
	void SetMaxCounter(int i);
	void ResetCounter();

	ALLEGRO_BITMAP *GetBitmap() const;
	tDirection GetDirection() const;
	int GetPositionX() const;
	int GetPositionY() const;
	int GetNextPositionX() const;
	int GetNextPositionY() const;
	int GetInitialPositionX() const;
	int GetInitialPositionY() const;
	int GetHousePositionX() const;
	int GetHousePositionY() const;
	float GetPixelPositionX() const;
	float GetPixelPositionY() const;
	tState GetState() const;
	int GetCounter() const;
	int GetStateCounter() const;
	float GetMaxCounter() const;
	tGhost GetType() const;
	int GetIdleTime() const;

	~Enemy();
private:
	tState state;
protected:
	int counter, state_counter, idle_time;
	int target[2], ScatterTarget[2], IdleTarget[2];
	float max_counter;
	tDirection direction;
	tGhost type;
	pixel_position initial_position, position, next_position, initial_house;
	short int animationState;
	std::vector<ALLEGRO_BITMAP *> sprite; //REMEMBER TO DESTROY THE SPRITES
	std::vector<ALLEGRO_BITMAP *> scared_sprite;
	std::vector<ALLEGRO_BITMAP *> eaten_sprite;
};

//Here go the external functions needed 

float distance(int posX, int posY, int targetX, int targetY);
//This funcion simply returns the addition of the horizontal an vertical distance between coordinates of the ghost and its target.

#endif
