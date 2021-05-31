#ifndef GLEWY_TEXTURE_HPP
#define GLEWY_TEXTURE_HPP

typedef unsigned int GLuint;
typedef unsigned int GLenum;

namespace gly
{

class Texture
{
	public:
		int tex_unit;
		GLuint handle;
		int x_size, y_size;
		
	Texture();
	Texture(const char*);
	Texture(const char*, const int&);
	
	void SetTexture(const char*);
	void SetFilter(GLenum);
	
	void Bind();
};

}

#endif