#include "Enemy.h"


Enemy::Enemy(Mesh* mesh,Texture2D *texture)
{
	eMesh = mesh;
	eTexture = texture;
	eRotation = 0.0f;
	ePosition.x = 20;
	ePosition.y = 20;
	ePosition.z = -20;

	eMoveSpeed = 0.1;

	eMaterial = new Material(); 
	eMaterial->Ambient.x = 0.8; eMaterial->Ambient.y = 0.05; eMaterial->Ambient.z = 0.05; 
	eMaterial->Ambient.w = 1.0; 
	eMaterial->Diffuse.x = 0.8; eMaterial->Diffuse.y = 0.05; eMaterial->Diffuse.z = 0.05; 
	eMaterial->Diffuse.w = 1.0; 
	eMaterial->Specular.x = 1.0; eMaterial->Specular.y = 1.0; eMaterial->Specular.z = 1.0; 
	eMaterial->Specular.w = 1.0; 
	eMaterial->Shininess = 200.0f; 
}

Enemy::~Enemy(void)
{

}

void Enemy::Draw()
{
	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glBindTexture(GL_TEXTURE_2D, eTexture->GetID());
	glNormalPointer(GL_FLOAT, 0, eMesh->Normals);
	glVertexPointer(3, GL_FLOAT, 0, eMesh->Vertices);
	glTexCoordPointer(2, GL_FLOAT, 0, eMesh->TexCoords);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glPushMatrix();

	glTranslatef(ePosition.x, ePosition.y, ePosition.z);
	glRotatef(eRotation, 1.0f, 0.0f, 0.0f);
	glDrawElements(GL_TRIANGLES, eMesh->numIndices, GL_UNSIGNED_SHORT, eMesh->indices);

	glPopMatrix();

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
}

void Enemy::Update()
{
	
}
