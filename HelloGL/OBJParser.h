#pragma once
#include "Structures.h"
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
class OBJParser
{
private:

	vector<string*> coordinates;
	vector<Vector3*> vertexs;
	vector<Vector3*> normals;
	vector<Vector3*> texcoords;
	vector<Face*> faces;

	char * lineBuffer;

public:

	OBJParser(void);
	~OBJParser(void);
	Mesh* Load(char* path);
	void assignValues();

};

