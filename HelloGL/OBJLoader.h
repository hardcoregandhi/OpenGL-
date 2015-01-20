#pragma once
#include "Structures.h"
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <vector>

using namespace std;

namespace OBJLoader
{
	OBJMesh* LoadOBJ(char* path);
	void LoadVertex(vector<Vertex>& vertices, string& lastLine);
	void LoadNormal(vector<Vector3>& normals, string& lastLine);
	void LoadTexCoord(vector<TexCoord>& texCoords, string& lastLine);
	void LoadIndex(vector<GLushort>& indices, string& lastLine);
	void ConvertToMesh(OBJMesh& mesh, vector<Vertex>& vertices, vector<Vector3>& normals, vector<TexCoord>& texCoords, vector<vector<GLushort>>& indices);
	int LoadTextureTGA(const char* textureFileName);
	
};

