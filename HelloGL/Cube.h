#pragma once
#include <Windows.h> //Required for OpenGL on Windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL/freeglut.h" //freeglut library

#include "Structures.h"
//#include "HelloGL.h"
#include "SceneObject.h"  // add these to get the variables out of other files
#include "MeshLoader.h"
#include "Texture2D.h"
#include <iostream>
#include <fstream>
using namespace std;


class Cube : public SceneObject 
	
{
private:
	Mesh* _mesh;
//	TexturedMesh* _tmesh;
	Texture2D * _texture;
	Material* _material; 
	float _rotation;
	Vector3* _position;
	float rotSpeed;
	float moveSpeed;
	/*int x;
	int y;
	int z;*/

	

public:
	//Cube(void);
	~Cube(void);
	Cube(Mesh* mesh, Texture2D *texture ); //pass in texture

	void Draw();
	void Update();
	float getRotation();

	//static bool Load(char* path);

};