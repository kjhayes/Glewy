#ifndef GLEWY_ABSTRACTION_HPP
#define GLEWY_ABSTRACTION_HPP

class GLFWwindow;

namespace sml{
	class vec2;
}

namespace gly
{
	/// @brief Creates a window and initializes GLEW and GLFW (Run By gly::Instance constructor, so explicit calling is unadvisable)
	/// @param x Window Starting Width
	/// @param y Window Starting Height
	/// @param title Window Starting Display Title 
	GLFWwindow* glewyCreateWindow(const int& x, const int& y, const char* title);
	
	/// @brief Incomplete [DO NOT USE]
	sml::vec2 PixelCoordToViewPort(GLFWwindow*, sml::vec2);
	/// @brief Incomplete [DO NOT USE]
	sml::vec2 ViewPortToPixelCoord(GLFWwindow*, sml::vec2);
}

#endif