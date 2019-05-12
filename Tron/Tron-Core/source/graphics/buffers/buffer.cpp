#include"buffer.h"

namespace tron {
	namespace graphics {

		Buffer::Buffer(GLfloat* data, GLsizei count, GLuint componentCount)
			:m_ComponentCount(componentCount)
		{
			glGenBuffers(1, &m_BuffeID);
			glBindBuffer(GL_ARRAY_BUFFER, m_BuffeID);
			glBufferData(GL_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

		void Buffer::bind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, m_BuffeID);
		}

		void Buffer::unbind() const
		{
			glBindBuffer(GL_ARRAY_BUFFER, 0);
		}

	}
}