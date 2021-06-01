#include<Glewy/Rendering/texture.hpp>

#include<SOIL/SOIL.h>

#define GLEW_STATIC
#include "GL/glew.h"

#include<iostream>

namespace gly
{
	Texture::Texture():tex_unit(0){}
	
	Texture::Texture(const char* file_name):tex_unit(0)
	{
		SetTexture(file_name);
		SetFilter(GL_NEAREST);
	}
	
	Texture::Texture(const char* file_name, const int& tex_unit):tex_unit(tex_unit)
	{
		SetTexture(file_name);	
		SetFilter(GL_NEAREST);
	}

	void Texture::SetTexture(const char* file_name)
	{
		this->handle = SOIL_load_OGL_texture
		(
			file_name,
			4,
			0,
			SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_MULTIPLY_ALPHA
		);
		
		if(handle == 0){std::cout<<"Error Loading Image: "<<file_name<<std::endl;}
		
		glBindTexture(GL_TEXTURE_2D, handle);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &x_size);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &y_size);
	}

	void Texture::SetFilter(GLenum filter)
	{
		glBindTexture(GL_TEXTURE_2D, handle);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
	}
	
	void Texture::Bind()
	{
		glActiveTexture(GL_TEXTURE0+tex_unit);
		glBindTexture(GL_TEXTURE_2D, handle);
	}
	
}