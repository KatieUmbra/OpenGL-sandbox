#pragma once

#include "vertex_buffer.hpp"
#include "buffer_layout.hpp"

namespace gl
{
	class vertex_array
	{
		unsigned int m_renderer_id;
	public:
		vertex_array();
		~vertex_array();
		auto add_buffer(const vertex_buffer&, const buffer_layout&) const -> void;
		auto bind() const -> void;
		static auto unbind() -> void;
	};
} //namespace gl
