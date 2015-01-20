#include "Cube.h"

Cube::Cube(Mesh* mesh,Texture2D *texture) : SceneObject(mesh) 

{
	//_tmesh = texmesh; 
	_texture = texture; 
	_mesh = mesh;

	_material = new Material(); 
	_material->Ambient.x = 0.8; _material->Ambient.y = 0.05; _material->Ambient.z = 0.05; 
	_material->Ambient.w = 1.0; 
	_material->Diffuse.x = 0.8; _material->Diffuse.y = 0.05; _material->Diffuse.z = 0.05; 
	_material->Diffuse.w = 1.0; 
	_material->Specular.x = 1.0; _material->Specular.y = 1.0; _material->Specular.z = 1.0; 
	_material->Specular.w = 1.0; 
	_material->Shininess = 100.0f; 
	_rotation=0.0f;
	_position = new Vector3(50 -(rand() % 100),50-(rand() % 100),-300-(rand() % 100));
	rotSpeed = (rand() % 100)*0.01f;
	moveSpeed = (rand() % 2)+1;

	/*x = (rand() % 3)-1;
	y = (rand() % 3)-1;
	z = (rand() % 6)-4;*/
}

Cube::~Cube(void)
{
}

void Cube::Draw()
{
	//glTranslatef(_position->x,_position->y,_position->z);
	//glRotatef(_rotation,x,y,z);
	//glBegin(GL_TRIANGLES);
	//// face v0-v1-v2
	//glColor3f(1,1,1);
	//glVertex3f(1,1,1);
	//glColor3f(1,1,0);
	//glVertex3f(-1,1,1);
	//glColor3f(1,0,0);
	//glVertex3f(-1,-1,1);
	//// face v2-v3-v0
	//glColor3f(1,0,0);
	//glVertex3f(-1,-1,1);
	//glColor3f(1,0,1);
	//glVertex3f(1,-1,1);
	//glColor3f(1,1,1);
	//glVertex3f(1,1,1);

	//// face v0-v3-v4
	//glColor3f(1,1,1);
	//glVertex3f(1,1,1);
	//glColor3f(1,0,1);
	//glVertex3f(1,-1,1);
	//glColor3f(0,0,1);
	//glVertex3f(1,-1,-1);
	//// face v4-v5-v0
	//glColor3f(0,0,1);
	//glVertex3f(1,-1,-1);
	//glColor3f(0,1,1);
	//glVertex3f(1,1,-1);
	//glColor3f(1,1,1);
	//glVertex3f(1,1,1);

	//// face v0-v5-v6
	//glColor3f(1,1,1);
	//glVertex3f(1,1,1);
	//glColor3f(0,1,1);
	//glVertex3f(1,1,-1);
	//glColor3f(0,1,0);
	//glVertex3f(-1,1,-1);
	//// face v6-v1-v0
	//glColor3f(0,1,0);
	//glVertex3f(-1,1,-1);
	//glColor3f(1,1,0);
	//glVertex3f(-1,1,1);
	//glColor3f(1,1,1);
	//glVertex3f(1,1,1);

	//// face  v1-v6-v7
	//glColor3f(1,1,0);
	//glVertex3f(-1,1,1);
	//glColor3f(0,1,0);
	//glVertex3f(-1,1,-1);
	//glColor3f(0,0,0);
	//glVertex3f(-1,-1,-1);
	//// face v7-v2-v1
	//glColor3f(0,0,0);
	//glVertex3f(-1,-1,-1);
	//glColor3f(1,0,0);
	//glVertex3f(-1,-1,1);
	//glColor3f(1,1,0);
	//glVertex3f(-1,1,1);

	//// face v7-v4-v3
	//glColor3f(0,0,0);
	//glVertex3f(-1,-1,-1);
	//glColor3f(0,0,1);
	//glVertex3f(1,-1,-1);
	//glColor3f(1,0,1);
	//glVertex3f(1,-1,1);
	//// face v3-v2-v7
	//glColor3f(1,0,1);
	//glVertex3f(1,-1,1);
	//glColor3f(1,0,0);
	//glVertex3f(-1,-1,1);
	//glColor3f(0,0,0);
	//glVertex3f(-1,-1,-1);

	//// face v4-v7-v6
	//glColor3f(0,0,1);
	//glVertex3f(1,-1,-1);
	//glColor3f(0,0,0);
	//glVertex3f(-1,-1,-1);
	//glColor3f(0,1,0);
	//glVertex3f(-1,1,-1);
	//// face v6-v5-v4
	//glColor3f(0,1,0);
	//glVertex3f(-1,1,-1);
	//glColor3f(0,1,1);
	//glVertex3f(1,1,-1);
	//glColor3f(0,0,1);
	//glVertex3f(1,-1,-1);

	//glEnd();

	glEnableClientState(GL_VERTEX_ARRAY);
	glEnableClientState(GL_NORMAL_ARRAY);
	//glEnableClientState(GL_COLOR_ARRAY);
	glEnableClientState(GL_TEXTURE_COORD_ARRAY);

	glBindTexture(GL_TEXTURE_2D, _texture->GetID());
	glNormalPointer(GL_FLOAT, 0, _mesh->Normals);
	glVertexPointer(3, GL_FLOAT, 0, _mesh->Vertices);
	//glColorPointer(3, GL_FLOAT, 0, tMesh->mesh->normals);
	glTexCoordPointer(2, GL_FLOAT, 0, _mesh->TexCoords);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	glPushMatrix();

	glTranslatef(_position->x, _position->y, _position->z);
	glRotatef(_rotation, 1.0f, 0.0f, 0.0f);
	glDrawElements(GL_TRIANGLES, _mesh->numIndices, GL_UNSIGNED_SHORT, _mesh->indices);

	glPopMatrix();

	glDisableClientState(GL_TEXTURE_COORD_ARRAY);
	//glDisableClientState(GL_COLOR_ARRAY);
	glDisableClientState(GL_NORMAL_ARRAY);
	glDisableClientState(GL_VERTEX_ARRAY);

}

void Cube::Update()
{

	_rotation += rotSpeed;

	if (_rotation >= 360.0f)
		_rotation = 0.0f;

	_position->z += moveSpeed;

	if (_position->z > 1)
	{
		_position->z=-300-(rand() % 100);
		rotSpeed = (rand() % 100)*0.01f;
		moveSpeed = (rand() % 2)+1;
		/*x = (rand() % 3)-1;
		y = (rand() % 3)-1;
		z = (rand() % 3)-1;*/
	}
}


