#include "GLUTCallbacks.h"
#include "HelloGL.h"

namespace GLUTCallbacks
{
	namespace 
	{
		HelloGL * helloGL = nullptr;
	}

	void Init(HelloGL * helloGL)
	{
		GLUTCallbacks::helloGL = helloGL;
	}

	void Display()
	{
		helloGL->Display();
	}

	void Reshape(int width, int height)
	{
		helloGL->Reshape(width, height);
	}

	void Timer(int value)
	{
		int updateTime = glutGet(GLUT_ELAPSED_TIME);
		helloGL->Update();
		updateTime = glutGet(GLUT_ELAPSED_TIME) - updateTime;

		glutTimerFunc(value - updateTime, GLUTCallbacks::Timer, value);
	}

	void Keyboard(unsigned char key, int x, int y)
	{
		helloGL->Keyboard(key, x, y);
		
	}

	/*void Mouse(int x, int y)
	{
		helloGL->processMouseActiveMotion(x,y);
	}*/

}