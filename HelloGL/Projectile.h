#pragma once
#include "Structures.h"

class Projectile
{
public:
	Projectile(void);
	~Projectile(void);
	Laser* NewLaser(float x, float y, float z); 
	void UpdateLaser(); 
	void RenderLaser(); 
	void DeleteAllLasers();

	Laser* firstLaser;
	Laser* lastLaser;

private:
	
};

