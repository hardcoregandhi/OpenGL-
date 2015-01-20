#pragma once
#include <Windows.h> //Required for OpenGL on Windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL/freeglut.h" //freeglut library

class Texture2D
{
private:
	GLuint _ID; //Texture ID
	int _width, _height;

public:
	Texture2D(void);
	~Texture2D(void);

	bool Load(char*path, int width, int hieght);

	GLuint GetID() const {return _ID;};
	int GetWidth() const {return _width;};
	int GetHeight() const {return _height;};

};

