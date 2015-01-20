#include "Player.h"
#include <vector>

Player::Player(OBJMesh* mesh, Texture2D* texture)
{

	pMesh = mesh;
	pTexture = texture;
	pRotation=0.0f;
	pPosition.x =0;
	pPosition.y =0;
	pPosition.z =0;

	pMoveSpeed = 0.5;

	pMaterial = new Material(); 
	pMaterial->Ambient.x = 0.8; pMaterial->Ambient.y = 0.05; pMaterial->Ambient.z = 0.05; 
	pMaterial->Ambient.w = 1.0; 
	pMaterial->Diffuse.x = 0.8; pMaterial->Diffuse.y = 0.05; pMaterial->Diffuse.z = 0.05; 
	pMaterial->Diffuse.w = 1.0; 
	pMaterial->Specular.x = 1.0; pMaterial->Specular.y = 1.0; pMaterial->Specular.z = 1.0; 
	pMaterial->Specular.w = 1.0; 
	pMaterial->Shininess = 100.0f; 

}


Player::~Player(void)
{
}

void Player::Draw()
{
	glBindTexture(GL_TEXTURE_2D, pTexture->GetID());
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glPushMatrix();

	glTranslatef(pPosition.x, pPosition.y, pPosition.z);
	glRotatef(pRotation, 1.0f, 0.0f, 1.0f);

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);


	

	for (int i = 0; i < pMesh->MeshIndices.size();i++)
	{
		glVertexPointer(3, GL_FLOAT, 0, &pMesh->Vertices[0]);
		glNormalPointer(GL_FLOAT,0,&pMesh->Normals[0]);
		glTexCoordPointer(2, GL_FLOAT, 0, &pMesh->TexCoords[0]);

		glDrawElements(GL_TRIANGLES, pMesh->MeshIndices[i].size(), GL_UNSIGNED_SHORT, &pMesh->MeshIndices[i][0]);
	}
	

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);
	glPopMatrix();
}

void Player::Update()
{

		

}
