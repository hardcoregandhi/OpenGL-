#pragma once

#include <Windows.h> //Required for OpenGL on Windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL/freeglut.h" //freeglut library

#include "MeshLoader.h"

#include "GLUTCallbacks.h"
#include "Structures.h"
#include "Cube.h"
#include "Texture2D.h"

//#include "SceneObject.h"

class Player
{
private:
	OBJMesh*	pMesh;

	Texture2D*	pTexture;
	Material*	pMaterial; 
	
	
	



public:
	Player(OBJMesh* mesh, Texture2D* texture);
	~Player(void);
	void Draw();
	void Update();
	
	Vector3 pPosition;
	float	pRotation;
	float	pMoveSpeed;
	float	pRotSpeed;
};

