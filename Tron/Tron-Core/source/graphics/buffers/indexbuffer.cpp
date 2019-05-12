#include"indexBuffer.h"

namespace tron {
	namespace graphics {

		IndexBuffer::IndexBuffer(GLushort* data, GLsizei count)
			:m_Count(count)
		{
			glGenBuffers(1, &m_BuffeID);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BuffeID);
			glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(GLfloat), data, GL_STATIC_DRAW);
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

		void IndexBuffer::bind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, m_BuffeID);
		}

		void IndexBuffer::unbind() const
		{
			glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
		}

	}
}