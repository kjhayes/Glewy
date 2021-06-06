#ifndef GLEWY_TEXTURE_HPP
#define GLEWY_TEXTURE_HPP

typedef unsigned int GLuint;
typedef unsigned int GLenum;

#include<Glewy/Structures/vec.hpp>

namespace gly
{

class Texture
{
	public:
		int tex_unit;
		GLuint handle = 0;
		int x_size, y_size;
		
	Texture();
	Texture(const char*);
	Texture(const char*, const int&);
	Texture(const vec4<gly_float>& color);
	
	void SetTexture(const char*);
	void SetTexture(const vec4<gly_float>& color);

	void SetFilter(GLenum);
	
	void Bind();
};

}

#endif