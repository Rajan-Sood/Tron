#include"source/graphics/window.h"
#include"source/maths/maths.h"
#include"source/graphics/shader.h"

#include"source/graphics/buffers/buffer.h"
#include"source/graphics/buffers/indexbuffer.h"
#include"source/graphics/buffers/vertexarray.h"

#include"source/graphics/renderer2d.h"
#include"source/graphics/simple2drenderer.h"
#include"source/graphics/batchrenderer2D.h"

#include"source/graphics/static_sprite.h"
#include"source/graphics/sprite.h"
#include"source/utility/timer.h"

#include"source/graphics/layers/tilelayer.h"

#include"source/graphics/layers/group.h"

#include<time.h>

#define BATCH_RENDERER 1
#define TEST_50K_SPRITES 0
int main()
{
	using namespace tron;
	using namespace graphics;
	using namespace maths;

	
	Window window("Tron!", 960, 540);

	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);



	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	
	Shader* s = new Shader("source/shaders/basic.vert", "source/shaders/basic.frag");
	Shader* s2 = new Shader("source/shaders/basic.vert", "source/shaders/basic.frag");
	Shader& shader = *s;
	Shader& shader2 = *s2;
	shader.enable();
	shader2.enable();
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));
	shader2.setUniform2f("light_pos", vec2(4.0f, 1.5f));

	TileLayer layer(&shader);


#if TEST_50K_SPRITES

	for (float y = -9.0f; y < 9.0f; y += 0.1)
	{
		for (float x = -16.0f; x < 16.0f; x += 0.1)
		{
			layer.add(new Sprite(x, y, 0.09f, 0.09f, maths::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
		}
	}

#else
	mat4 transform = mat4::translation(vec3(-15.0f, 5.0f, 0.0));
	Group* group = new Group(transform);
	group->add( new Sprite(0,0, 6, 3, maths::vec4(1, 1, 1, 1)));

	Group* button = new Group(mat4::translation(vec3(0.5f, 0.5f, 0.0f)));
	button->add(new Sprite(0, 0, 5.0f, 2.0f, maths::vec4(1, 0, 1, 1)));
	button->add(new Sprite(0.5f, 0.5f, 3.0f, 1.0f, maths::vec4(0.2f, 0.3f, 0.8f, 1)));
	group->add(button);

	layer.add(group);


#endif 

	
	TileLayer layer2(&shader2);
	layer2.add(new Sprite(-2, -2, 4, 4, maths::vec4(1, 0, 1, 1)));



	Timer  time;
	float timer = 0;;
	unsigned int frames = 0;

	while (!window.closed())
	{
		window.clear();
		double x, y;
		window.getMousePosition(x, y);
		shader.enable();
		shader.setUniform2f("light_pos", vec2((float)(x*32.0f / 960.0f - 16.0f), (float)(9.0f - y * 18.0f / 540.0f )));
		shader2.enable();
		shader.setUniform2f("light_pos", vec2((float)(x*32.0f / 960.0f - 16.0f), (float)(9.0f - y * 18.0f / 540.0f )));

		
		layer.render();
		//layer2.render();

		window.update();
		frames++;

		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			printf("%d fps\n" ,frames);
			frames = 0;
		}

	}
	
	return 0;
}