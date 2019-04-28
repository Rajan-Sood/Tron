#include<GLFW/glfw3.h>
#include<iostream>

#include"source/graphics/window.h"

int main()
{
	using namespace tron;
	using namespace graphics;

	Window window("Tron!", 800, 600);

	while (!window.closed())
	{
		window.update();
	}

	return 0;
}