#include"source/graphics/window.h"
#include"source/maths/maths.h"

int main()
{
	using namespace tron;
	using namespace graphics;
	using namespace maths;

	Window window("Tron!", 800, 600);

	glClearColor(0.2f, 0.3f, 0.8f, 1.0f);

	vec3 a(1.0f, 2.0f,5.0f);
	vec3 b(2, 4,6);

	vec3 c = a + b;

	mat4 position = mat4::translation(vec3(2, 3, 4));

	while (!window.closed())
	{
		

		std::cout << a << std::endl;
		
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