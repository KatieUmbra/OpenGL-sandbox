#pragma once

#include <exception>
#include <vector>
#include <GLAD/glad.h>

namespace gl
{
	struct vertex_buffer_element
	{
		unsigned int type;
		unsigned int count;
		bool normalize;

		static auto get_size_of_type(unsigned int type) -> unsigned int
		{
			switch(type)
			{
				case GL_FLOAT: return 4;
				case GL_UNSIGNED_INT: return 4;
				case GL_UNSIGNED_BYTE: return 1;
			}
			return 0;
		}
	};
	class buffer_layout
	{
		std::vector<vertex_buffer_element> m_elements;
		unsigned int m_stride;
	public:
		buffer_layout() :m_stride{0} {}

		template <typename T>
		void push(unsigned int count)
		{
			std::terminate();
		}

		template <>
		void push<float>(unsigned int count)
		{
			vertex_buffer_element element {GL_FLOAT, count, false};
			this->m_elements.emplace_back(element);
			this->m_stride += vertex_buffer_element::get_size_of_type(GL_FLOAT) * count;
		}

		template <>
		void push<unsigned int>(unsigned int count)
		{
			vertex_buffer_element element {GL_UNSIGNED_INT, count, false};
			this->m_elements.emplace_back(element);
			this->m_stride += vertex_buffer_element::get_size_of_type(GL_UNSIGNED_INT) * count;
		}

		template <>
		void push<unsigned char>(unsigned int count)
		{
			vertex_buffer_element element {GL_UNSIGNED_BYTE, count, false};
			this->m_elements.emplace_back(element);
			this->m_stride += vertex_buffer_element::get_size_of_type(GL_UNSIGNED_BYTE) * count;
		}

		inline auto get_stride() const -> unsigned int
		{
			return this->m_stride;
		}

		inline auto get_elements() const -> const std::vector<vertex_buffer_element>&
		{
			return this->m_elements;
		}
	};
} //namespace gl
