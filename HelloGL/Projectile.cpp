#include "Projectile.h"



Projectile::Projectile(void)
{
	firstLaser = nullptr;
	lastLaser = nullptr;

}


Projectile::~Projectile(void)
{
}

Laser* Projectile::NewLaser(float x,float y, float z)

{

	if(firstLaser=nullptr) //set up first laser

	{

		firstLaser=new Laser; //set first laser
		lastLaser=firstLaser; //set last laser

		lastLaser->next=nullptr;
		lastLaser->previous=nullptr;

	}
	else
	{

		lastLaser->next=new Laser; //setup next lasers

		lastLaser->next->previous=lastLaser; //the last->next becomes next->last

		lastLaser=lastLaser->next; //move last Laser pointer to the end

		lastLaser->next=nullptr; //new last laser points to nothing

	}

	//setup unique new laser
	lastLaser->x=x;
	lastLaser->y=y;
	lastLaser->z=z;

	lastLaser->dead=false; 

	return lastLaser; //return new laser

}

void Projectile::UpdateLaser()
{

}