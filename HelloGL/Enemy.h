#pragma once

#include "Structures.h"
#include "SceneObject.h"
#include "MeshLoader.h"
#include "Texture2D.h"

using namespace std;

class Enemy
{
private:
	Mesh* eMesh;
	Texture2D * eTexture;
	Material* eMaterial; 
	float eRotation;
	
	float eRotSpeed;


public:
	Enemy(Mesh* mesh,Texture2D *texture);
	~Enemy(void);
	void Draw();
	void Update();
	Vector3 ePosition;
	float eMoveSpeed;
};

