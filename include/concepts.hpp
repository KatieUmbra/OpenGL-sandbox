#pragma once

#include <concepts>

template <typename T>
concept has_size = requires(T t)
{
	{ t.size() } -> std::same_as<size_t>;
};
