#pragma once

#include <cstddef>
#include <array>

namespace gl
{
	class index_buffer
	{
		unsigned int m_renderer_id;
		unsigned int m_count;
	public:
		template <size_t N>
		index_buffer(const std::array<unsigned int, N>&, unsigned int);
		~index_buffer();

		auto bind() const -> void;
		static auto unbind() -> void;

		[[nodiscard]] inline auto get_count() const -> unsigned int;
	};
} //namespace gl
