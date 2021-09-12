#ifndef GLEWY_ABSTRACTION_HPP
#define GLEWY_ABSTRACTION_HPP

#include<Glewy/Core/typedef.hpp>

class GLFWwindow;

namespace gly
{
	template<typename T> class vec2;

	/// @brief Creates a window and initializes GLEW and GLFW (Run By gly::Instance constructor, so explicit calling is inadvisable)
	/// @param x Window Starting Width
	/// @param y Window Starting Height
	/// @param title Window Starting Display Title 
	GLFWwindow* glewyCreateWindow(const int& x, const int& y, const char* title);
	
	/// @brief Incomplete [DO NOT USE]
	vec2<gly_float> PixelCoordToViewPort(GLFWwindow*, vec2<gly_float>);
	/// @brief Incomplete [DO NOT USE]
	vec2<gly_float> ViewPortToPixelCoord(GLFWwindow*, vec2<gly_float>);
}

#endif