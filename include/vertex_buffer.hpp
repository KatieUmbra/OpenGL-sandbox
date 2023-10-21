#pragma once

#include <initializer_list>
#include "concepts.hpp"

namespace gl
{
	class vertex_buffer
	{
		unsigned int m_id;
	public:
		template <typename T> requires has_size<T>
		vertex_buffer(T& data, size_t size);
		~vertex_buffer();
		[[nodiscard]] inline constexpr auto get_id() const -> unsigned int;
		template<typename T> requires has_size<T>
		auto data(T&, size_t) const -> void;
		auto bind() const -> void;
		static auto unbind() -> void;
	};
} //namespace gl
