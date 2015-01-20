#pragma once

class HelloGL;

namespace GLUTCallbacks
{
	void Init(HelloGL * helloGL);
	void Display();
	void Reshape(int width, int height);
	void Timer(int preferredRefresh);
	void Keyboard(unsigned char key, int x, int y);
	void Mouse(int x, int y);
};

