#include "HelloGL.h"
#include <iostream>
#include <fstream>


HelloGL::HelloGL(int argc, char* argv[])
{
	glutInit(&argc, argv);
	InitGL();
	InitObjects();
	glutMainLoop();
	
}

HelloGL::~HelloGL(void)
{
}

void HelloGL::InitObjects()
{

	_lightPosition = new Vector4(); 
	_lightPosition->x = 0.0; 
	_lightPosition->y = 0.0; 
	_lightPosition->z = 1.0; 
	_lightPosition->w = 0.0; 

	_lightData = new Lighting(); 
	_lightData->Ambient.x = 0.2f; 
	_lightData->Ambient.y = 0.2f; 
	_lightData->Ambient.z = 0.2f; 
	_lightData->Ambient.w = 1.0f; 
	_lightData->Diffuse.x = 0.8f; 
	_lightData->Diffuse.y = 0.8f; 
	_lightData->Diffuse.z = 0.8f; 
	_lightData->Diffuse.w = 1.0f; 
	_lightData->Specular.x = 0.2f; 
	_lightData->Specular.y = 0.2f; 
	_lightData->Specular.z = 0.2f; 
	_lightData->Specular.w = 1.0f; 


	camera = new Camera();
	camera->eye.x = 0; camera->eye.y = 0; camera->eye.z = 10; 
	camera->center.x = 0.0f; camera->center.y = 0.0f; camera->center.z = 0.0f; 
	camera->up.x = 0.0f; camera->up.y = 1; camera->up.z = 0.0f;

	//MESHLOADER


	OBJMesh* playerMesh = OBJLoader::LoadOBJ("slimcube.obj");
	Texture2D* playerTexture = new Texture2D();
	playerTexture->Load("goat_D.raw",1024,1024);
	//playerTexture->Load("stars.raw", 512, 512);
	//Player
	player = new Player(playerMesh, playerTexture);

	Mesh* cubeMesh = MeshLoader::LoadTextured("cube.txt");
	//Mesh* cubeMesh = MeshLoader::Load("cube.txt"); 

	Texture2D* texture = new Texture2D();

	texture->Load("stars.raw", 512, 512);
	//CUBES

	for(int i =0;i<numObjects;i++)
	{
		objects[i] = new Cube(cubeMesh, texture);
	}

	//Enemy
	Texture2D* eTexture = new Texture2D();
	eTexture->Load("Penguins.raw",512,512);
	enemy = new Enemy(cubeMesh,eTexture);

}
void HelloGL::InitGL()
{
	GLUTCallbacks::Init(this);

	
	glutInitDisplayMode(GLUT_DOUBLE | GLUT_DEPTH);
	glutInitWindowSize(800, 800);
	glutInitWindowPosition(200, 200);
	glutCreateWindow("Simple OpenGL Program");
	glutDisplayFunc(GLUTCallbacks::Display);
	glutReshapeFunc(GLUTCallbacks::Reshape);
	glutTimerFunc(REFRESHRATE, GLUTCallbacks::Timer, REFRESHRATE);
	glutKeyboardFunc(GLUTCallbacks::Keyboard);
	//glutMotionFunc(GLUTCallbacks::Mouse);

	glEnable(GL_TEXTURE_2D);
	glEnable(GL_DEPTH_TEST);
	glEnable(GL_CULL_FACE);
	glCullFace(GL_BACK);
	
}


void HelloGL::Display() 
{
	glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT); //This clears the scene so we start a fresh each time
	glPushMatrix();
	//cube->Draw();
	for(int i =0;i<numObjects;i++)
	{
		
		//glRotatef(cubeArray[i]->getRotation() * i, 1.0f, 0.0f, 0.0f);
		//glTranslatef(i*2,1.0f,1.0f);
		objects[i]->Draw();
		
	}
	player->Draw();
	enemy->Draw();
	glPopMatrix();
	//winning
	if (player->pPosition.z < -300)
	{
		cout << "you win";

		Color c = {1.0f, 0.0f, 0.0f};
		DrawString("You win, yay!", &player->pPosition, &c);

	}
	glFlush(); //Flushes the scene we just drew to the graphics card
	glutSwapBuffers();
}

void HelloGL::Update()
{
	glLoadIdentity();

	//CAMERA
	camera->center.x = (player->pPosition.x);
	camera->center.y = (player->pPosition.y);
	camera->center.z = (player->pPosition.z);

	camera->eye.x = (player->pPosition.x);
	camera->eye.y = (player->pPosition.y)+1;
	if (behind==true)
		camera->eye.z = (player->pPosition.z)-10;
	else
		camera->eye.z = (player->pPosition.z)+10;

	gluLookAt(camera->eye.x, camera->eye.y, camera->eye.z, camera->center.x, camera->center.y, camera->center.z, camera->up.x, camera->up.y, camera->up.z);

	//FIELD
	for(int i =0;i<numObjects;i++)
	{
		objects[i]->Update();
	}

	//ENEMY
	if(player->pPosition.x < enemy->ePosition.x)
		enemy->ePosition.x -= enemy->eMoveSpeed;
	else
		enemy->ePosition.x += enemy->eMoveSpeed;

	if(player->pPosition.y < enemy->ePosition.y)
		enemy->ePosition.y -= enemy->eMoveSpeed;
	else
		enemy->ePosition.y += enemy->eMoveSpeed;

	if(player->pPosition.z < enemy->ePosition.z)
		enemy->ePosition.z -= enemy->eMoveSpeed;
	else
		enemy->ePosition.z += enemy->eMoveSpeed;
	

	glutPostRedisplay();
}

void HelloGL::Keyboard(unsigned char key, int x, int y)
{
	if (key == 'd')
		player->pPosition.x += player->pMoveSpeed;
	if (key == 'a')
		player->pPosition.x -= player->pMoveSpeed;
	if (key == 'w')
		player->pPosition.z -= player->pMoveSpeed;
	if (key == 's')
		player->pPosition.z += player->pMoveSpeed;
	if (key == 'p')
		player->pPosition.y += player->pMoveSpeed;
	if (key == 'l')
		player->pPosition.y -= player->pMoveSpeed;
	if (key == 'q')
		player->pRotation -= player->pRotSpeed;
	if (key == 'e')
		player->pRotation += player->pRotSpeed;
	if (key == 'b')
		behind=true;
	else
		behind=false;
		


	
}
//void HelloGL::processMouseActiveMotion(int x, int y) {
//
//	int specialKey = glutGetModifiers();
//	if (specialKey == GLUT_LEFT_BUTTON) 
//	{
//		Projectile::NewLaser(player->pPosition.x,player->pPosition.y, player->pPosition.z);
//	}
//}
void HelloGL::DrawString(const char* text, const Vector3* position, const Color* color)
{
       glPushMatrix();

              glDisable(GL_TEXTURE);

              glDisable(GL_LIGHTING);

              glColor3f(1.0f, 0.0f, 0.0f);

              glTranslatef(position->x+1, position->y, position->z);

              glRasterPos2f(0.0f, 0.0f);

              glutBitmapString(GLUT_BITMAP_TIMES_ROMAN_24, (unsigned char*)text);

              glEnable(GL_LIGHTING);

              glEnable(GL_TEXTURE);

       glPopMatrix();

}
void HelloGL::Reshape(int width, int height)
{
	if(height == 0)
		height = 1;
	float ratio = 1.0f * width / height;

	// Use the Projection Matrix
	glMatrixMode(GL_PROJECTION);

	// Reset Matrix
	glLoadIdentity();

	// Set the viewport to be the entire window
	glViewport(0, 0, width, height);

	// Set the correct perspective.
	gluPerspective(45, ratio, 0.1, 1000);

	// Get Back to the Modelview
	glMatrixMode(GL_MODELVIEW);

}

