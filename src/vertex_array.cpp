#include "buffer_layout.hpp"
#include "vertex_array.hpp"
#include "vertex_buffer.hpp"
#include <GLAD/glad.h>

namespace gl
{
vertex_array::vertex_array()
{
	glGenVertexArrays(1, &this->m_renderer_id);
}

vertex_array::~vertex_array()
{
	glDeleteVertexArrays(1, &this->m_renderer_id);
}

auto vertex_array::bind() const -> void
{
	glBindVertexArray(this->m_renderer_id);
}

auto vertex_array::unbind() -> void
{
	glBindVertexArray(0);
}

auto vertex_array::add_buffer(const vertex_buffer& vb, const buffer_layout& bl) const -> void
{
	this->bind();
	vb.bind();
	const auto elements = bl.get_elements();
	for (unsigned int i = 0; i < elements.size(); i++)
	{
		const auto& element = elements[i];
		unsigned int offset = 0;
		glEnableVertexAttribArray(i);
		glVertexAttribPointer(
			i, 
			element.count, 
			element.type, 
			(element.normalize ? GL_TRUE : GL_FALSE ),
			bl.get_stride(),
			reinterpret_cast<const void*>(offset)
		);
		offset += element.count * vertex_buffer_element::get_size_of_type(element.type);
	}
}
} //namespace gl
