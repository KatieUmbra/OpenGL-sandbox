#include "buffer_layout.hpp"
#include "index_buffer.hpp"
#include "vertex_array.hpp"
#include "vertex_buffer.hpp"
#include <iostream>
#include <variant>

#include <GLAD/glad.h>
#include <GLFWPP/glfwpp.h>

#include <GLM/ext/vector_float4.hpp>

auto main() -> int
{
	// GLFW Setup
	[[maybe_unused]]
	auto library = glfw::init();
	glfw::WindowHints {
		.resizable = false,
		.decorated = false,
		.floating = true,
		.contextVersionMajor = 4,
		.contextVersionMinor = 6,
		.openglProfile = glfw::OpenGlProfile::Compat,
		.x11ClassName = "oglfun",
		}.apply();
	constexpr unsigned int size = 800;
	glfw::Window window { size, size, "Hello OpenGL" };
	glfw::makeContextCurrent(window);

	// GLAD Setup
	if (gladLoadGLLoader((GLADloadproc)glfwGetProcAddress) == 0) //NOLINT
	{
		std::cout << "Failed to initialized GLAD." << '\n';
		return -1;
	}

	glViewport(0, 0, size, size);

	{
		constexpr std::array<float, 12> vertex_data {
			-0.5F, -0.5F,
			 0.5F, -0.5F,
			 0.5F,  0.5F,
			-0.5F,  0.5F
		};

		constexpr std::array<unsigned int, 6> index_data {
			0, 1, 2,
			2, 3, 0
		};

		gl::vertex_array vao;
		gl::vertex_buffer vb {vertex_data, vertex_data.size() * sizeof(float)};
		gl::buffer_layout bl;
		bl.push<float>(2);
		vao.add_buffer(vb, bl);
		gl::index_buffer ib {index_data, 6u};
		
		glVertexAttribPointer(0, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), 0);
		glVertexAttribPointer(1, 2, GL_FLOAT, GL_FALSE, 4 * sizeof(float), reinterpret_cast<void*>(2 * sizeof(float)));
		glEnableVertexAttribArray(0);
		glEnableVertexAttribArray(1);

		while(!window.shouldClose())
		{
			glClear(GL_COLOR_BUFFER_BIT);
			vao.bind();
			ib.bind();
			glDrawElements(GL_TRIANGLES, 6, GL_UNSIGNED_INT, nullptr);
			window.swapBuffers();
			glfw::pollEvents();
		}
	}
}
