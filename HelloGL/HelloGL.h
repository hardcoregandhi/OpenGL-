#pragma once

#include <Windows.h> //Required for OpenGL on Windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL/freeglut.h" //freeglut library

#include "MeshLoader.h"
#include "OBJLoader.h"

#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"
#include "Texture2D.h"
#include "Player.h"
#include "Projectile.h"
#include "Enemy.h"
//#include "SceneObject.h"


#define REFRESHRATE 16


class HelloGL
{
public:
	HelloGL(int argc, char* argv[]);
	~HelloGL(void);

	void Display();
	void Update();
	void Keyboard(unsigned char key, int x, int y);
	//void processMouseActiveMotion(int x, int y);
	void Reshape(int width, int height);


	void InitObjects(); 
	void InitGL(); 
	void HelloGL::DrawString(const char* text, const Vector3* position, const Color* color);


	

private:

	Vector3 position;
	Player* player;
	Enemy* enemy;
	Camera* camera;
	Cube* cube;
	static const int numObjects = 500;
	//Cube * cubeArray[numCubes];
	SceneObject* objects[numObjects]; 

	Vector4* _lightPosition; 
	Lighting* _lightData; 	bool behind;
};