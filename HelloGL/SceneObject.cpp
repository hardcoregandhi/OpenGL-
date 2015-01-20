#include "SceneObject.h"


SceneObject::SceneObject(Mesh* mesh) // this had void needs to match the constructor 
{
	_mesh = mesh;
}


SceneObject::~SceneObject(void)
{
}
