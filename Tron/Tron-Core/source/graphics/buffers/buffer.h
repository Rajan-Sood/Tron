#pragma once

#include"GL/glew.h"

namespace tron {
	namespace graphics {
		class Buffer
		{

		private:
			GLuint m_BuffeID;
			GLuint m_ComponentCount;

		public:
			Buffer(GLfloat* data, GLsizei count, GLuint componentCount);

			void bind() const;
			void unbind() const;

			inline GLuint getComponentCount() const { return m_ComponentCount; }


		};
	}
}



