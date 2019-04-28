#include"window.h"
#include<iostream>

namespace tron {
	namespace graphics {

		Window::Window(const char *title, int width, int height)
		{
			m_Title = title;
			m_Width = width;
			m_Height = height;
			if (!init())
			{
				glfwTerminate();
			}
		}

		Window::~Window()
		{
			glfwTerminate();
		}

		bool Window::init()
		{
			if (!glfwInit())
			{
				std::cout << "Failed to initiliaze glfw" << std::endl;
				return false;
			}
			

			m_Window = glfwCreateWindow(m_Width, m_Height,m_Title, NULL, NULL);
			if (!m_Window)
			{
				glfwTerminate();
				std::cout << "Failed to create GLFW window" << std::endl;
				return false;
			}
			glfwMakeContextCurrent(m_Window);
			return true;

		}

		bool Window::closed() const
		{
			return glfwWindowShouldClose(m_Window);
		}

		void Window::update() const
		{
			glfwSwapBuffers(m_Window);
			glfwPollEvents();

		}
	}
}