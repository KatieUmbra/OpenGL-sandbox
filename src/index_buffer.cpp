#include "index_buffer.hpp"

#include <GLAD/glad.h>

namespace gl
{
template <size_t N>
index_buffer::index_buffer(const std::array<unsigned int, N>& data, unsigned int count)
	:m_count{count}
{
	glGenBuffers(1, &this->m_renderer_id);
	this->bind();
	glBufferData(GL_ELEMENT_ARRAY_BUFFER, count * sizeof(unsigned int), &data, GL_STATIC_DRAW);
}

index_buffer::~index_buffer()
{
	glDeleteBuffers(1, &this->m_renderer_id);
}

void index_buffer::bind() const
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, this->m_renderer_id);
}

void index_buffer::unbind()
{
	glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
}

inline auto index_buffer::get_count() const -> unsigned int
{
	return this->m_count;
}
}
