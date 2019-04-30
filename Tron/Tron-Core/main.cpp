//#include<GLFW/glfw3.h>
#include<iostream>


#include"source/graphics/window.h"

int main()
{
	using namespace tron;
	using namespace graphics;

	Window window("Tron!", 800, 600);

	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	//std::cout << glGetString(GL_VERSION) << std::endl;

	while (!window.closed())
	{
		//std::cout << window.getWidth() << ", " << window.getHeight() << std::endl;
		window.clear();
		double x, y;
		window.getMousePosition(x, y);

		std::cout << x << ", " << y << std::endl;
		
		glBegin(GL_QUADS);
		glVertex2f(-0.5f, -0.5f);
		glVertex2f(-0.5f, 0.5f);
		glVertex2f(0.5f, 0.5f);
		glVertex2f(0.5f, -0.5f);

		glEnd();
		window.update();
	}

	return 0;
}