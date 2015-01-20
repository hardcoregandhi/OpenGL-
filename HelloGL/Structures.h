#pragma once

#include <Windows.h> //Required for OpenGL on Windows
#include <gl/GL.h> //OpenGL
#include <gl/GLU.h> //OpenGL Utilities
#include "GL/freeglut.h" //freeglut library
#include <vector>
#include "Texture2D.h"

using namespace std;

struct Vector3
{
	float x, y, z;

	Vector3(float xPos, float yPos, float zPos){
		x = xPos;
		y = yPos;
		z = zPos;
	}

	Vector3(){
		x = 0.0f;
		y = 0.0f;
		z = 0.0f;
	}
};

struct Camera
{
	Vector3 eye;
	Vector3 center;
	Vector3 up;
};

struct Color
{
	GLfloat r, g, b;
};

struct Vertex
{
	GLfloat x, y, z;
};

struct TexCoord
{
	GLfloat u, v;
};
struct Mesh
{
	Vertex * Vertices;
	Vector3 * Normals;
	GLushort * indices;
	TexCoord * TexCoords;
	int numVertices;
	int numNormals;
	int numIndices;
	int TexCoordCount;
	
};

struct OBJMesh
{
	vector<string> MeshNames;
	vector<vector<GLushort>> MeshIndices;
	vector<Vertex> Vertices;
	vector<Vector3> Normals;
	vector<TexCoord> TexCoords;
};

struct Face
{
	int aV; //Vector
	int aT; //TextureCoord
	int aN; //Normal
	int bV;
	int bT;
	int bN;
	int cV;
	int cT;
	int cN;
};


struct TexturedMesh
{
	Mesh* Mesh;
	TexCoord* TexCoords;
	Texture2D* texture;
	int TexCoordCount;
};

struct Vector4
{
	GLfloat x, y, z, w;
};

struct Lighting
{
	Vector4 Ambient, Diffuse, Specular;
};

struct Material
{
	Vector4 Ambient, Diffuse, Specular;
	GLfloat Shininess;
};
struct node
{
	int x;
	int y;
	node* next;
};
struct Laser
{
  float x;
  float y;
  float z;
  bool dead;

  Laser* next; //The next laser node on the list
  Laser* previous; //The previous laser node on the list
};