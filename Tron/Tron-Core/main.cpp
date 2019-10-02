#include"source/graphics/window.h"
#include"source/maths/maths.h"
#include"source/utility/timer.h"
#include"source/graphics/shader.h"

#include"source/graphics/buffers/buffer.h"
#include"source/graphics/buffers/indexbuffer.h"
#include"source/graphics/buffers/vertexarray.h"

#include"source/graphics/renderer2d.h"
#include"source/graphics/simple2drenderer.h"
#include"source/graphics/batchrenderer2D.h"

#include"source/graphics/static_sprite.h"
#include"source/graphics/sprite.h"

#include"source/graphics/layers/tilelayer.h"

#include"source/graphics/layers/group.h"

#include<time.h>
#include"source/graphics/texture.h"

#define BATCH_RENDERER 1

#if 1
int main()
{
	using namespace tron;
	using namespace graphics;
	using namespace maths;

	
	Window window("Tron!", 960, 540);

	//glClearColor(1.0f, 1.0f, 1.0f, 1.0f);



	mat4 ortho = mat4::orthographic(0.0f, 16.0f, 0.0f, 9.0f, -1.0f, 1.0f);

	
	Shader* s = new Shader("source/shaders/basic.vert", "source/shaders/basic.frag");
	Shader& shader = *s;
	shader.enable();
	shader.setUniform2f("light_pos", vec2(4.0f, 1.5f));

	TileLayer layer(&shader);
	Texture* textures[] = 
	{
		new Texture("test.png"),
		new Texture("tb.png"),
		new Texture("tc.png")

	};
	
	for (float y = -9.0f; y < 9.0f; y +=0.1)
	{
		for (float x = -16.0f; x < 16.0f; x +=0.1)
		{
			layer.add(new Sprite(x, y, 0.9f, 0.9f, maths::vec4(rand() % 1000 / 1000.0f, 0, 1, 1)));
			//layer.add(new Sprite(x, y, 0.9f, 0.9f, textures[rand()% 3]));
		}
	}
	

	for (int y = -5; y < 5; y+=4)
	{
		for (int x = -5; x < 5; x+=4)
		{
			layer.add(new Sprite(x, y, 4.0f, 4.0f, textures[rand() % 3]));

		}
	}

	GLint texIDs[] = 
	{
		0,1,2,3,4,5,6,7,8,9
	};

	shader.enable();
	shader.setUniform1iv("textures", texIDs, 10);
	shader.setUniformMat4("pr_matrix", maths::mat4::orthographic(-16.0f, 16.0f, -9.0f, 9.0f, -1.0f, 1.0f));

	
	Timer  time;
	float timer = 0;;
	unsigned int frames = 0;

	while (!window.closed())
	{
		window.clear();
		
		double x, y;
		window.getMousePosition(x, y);
		shader.setUniform2f("light_pos", vec2((float)(x*32.0f / 960.0f - 16.0f), (float)(9.0f - y * 18.0f / 540.0f)));
		layer.render();
			
		window.update();
		frames++;

		if (time.elapsed() - timer > 1.0f)
		{
			timer += 1.0f;
			printf("%d fps\n", frames);
			frames = 0;
		}

	}
		delete[] textures;
	return 0;
}
#endif


#if 0
int main()
{
	const char* filename = "test.png";

	//image format
	FREE_IMAGE_FORMAT fif = FIF_UNKNOWN;
	//pointer to the image, once loaded
	FIBITMAP *dib(0);
	//pointer to the image data
	BYTE* bits(0);
	//image width and height
	unsigned int width(0), height(0);
	//OpenGL's image ID to map to
	GLuint gl_texID;

	//check the file signature and deduce its format
	fif = FreeImage_GetFileType(filename, 0);
	//if still unknown, try to guess the file format from the file extension
	if (fif == FIF_UNKNOWN)
		fif = FreeImage_GetFIFFromFilename(filename);
	//if still unkown, return failure
	if (fif == FIF_UNKNOWN)
		return false;

	//check that the plugin has reading capabilities and load the file
	if (FreeImage_FIFSupportsReading(fif))
		dib = FreeImage_Load(fif, filename);
	//if the image failed to load, return failure
	if (!dib)
		return false;

	
	//retrieve the image data
	bits = FreeImage_GetBits(dib);
	unsigned int bitsPerPixel = FreeImage_GetBPP(dib);
	//get the image width and height
	width = FreeImage_GetWidth(dib);
	height = FreeImage_GetHeight(dib);
	//if this somehow one of these failed (they shouldn't), return failure
	if ((bits == 0) || (width == 0) || (height == 0))
		return false;

	std::cout << width << ", " << height << std::endl;

	for (int i = 0; i < width*height*3; i+=3)
	{
		//std::cout << +bits[i] <<" " << +bits[i+1] <<" " << +bits[i+2] << std::endl;
		printf("%d\n", bits[i+2]);
	}

	FreeImage_Unload(dib);


	return 0;
}
#endif