#pragma once

//#include "HelloGL.h"
#include "Structures.h"

namespace MeshLoader
{
	Mesh* Load(char* path);
	Mesh* LoadTextured(char* path);
};

