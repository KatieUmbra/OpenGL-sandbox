#include "vertex_buffer.hpp"
#include <GLAD/glad.h>
#include <initializer_list>

namespace gl
{
template <typename T> requires has_size<T>
vertex_buffer::vertex_buffer(T& data, size_t size)
{
	glGenBuffers(1, &this->m_id);
	this->bind();
	glBufferData(GL_ARRAY_BUFFER, size, data, GL_STATIC_DRAW);
}

vertex_buffer::~vertex_buffer()
{
	glDeleteBuffers(1, &this->m_id);
}

void vertex_buffer::bind() const
{
	glBindBuffer(GL_ARRAY_BUFFER, this->m_id);
}

void vertex_buffer::unbind()
{
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

constexpr inline auto vertex_buffer::get_id() const -> unsigned int
{
	return this->m_id;
}
} //namespace gl
