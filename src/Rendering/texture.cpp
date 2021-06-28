#include<Glewy/Rendering/texture.hpp>

#include<SOIL/SOIL.h>

#define GLEW_STATIC
#include "GL/glew.h"

#include<iostream>

namespace gly
{
	void Texture::SingleColor(const vec4<gly_float>& color){
		vec4<unsigned char> data;
		data = color * 255;
		this->handle = SOIL_create_OGL_texture(
			(unsigned char*)&data,
			1,
			1,
			4,
			handle,
			SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_MULTIPLY_ALPHA
		);

		if(handle == 0){std::cout<<"Error Creating Texture"<<std::endl;}	
		x_size = 1;
		y_size = 1;
	}
	
	void Texture::LoadFromFile(const File& f){
		this->handle = SOIL_load_OGL_texture
		(
			f.file_name,
			4,
			handle,
			SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_MULTIPLY_ALPHA
		);
		
		if(handle == 0){std::cout<<"Error Loading Image: "<<f.file_name<<std::endl;}
		
		glBindTexture(GL_TEXTURE_2D, handle);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &x_size);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &y_size);
	}

	void Texture::LoadFromData(const Data& d){
		this->handle = SOIL_load_OGL_texture_from_memory
		(
			d.data,
			d.size,
			4,
			handle,
			SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_MULTIPLY_ALPHA
		);
		
		if(handle == 0){std::cout<<"Error Loading Image From Memory: "<<(int)d.data<<" |Size: "<<d.size<<" bytes|"<<std::endl;}
		
		glBindTexture(GL_TEXTURE_2D, handle);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &x_size);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &y_size);	
	}

	Texture::Texture(const Data& d){LoadFromData(d);SetFilter(GL_NEAREST);}
	Texture::Texture(const File& f){LoadFromFile(f);SetFilter(GL_NEAREST);}

	void Texture::SetFilter(GLenum filter)
	{
		glBindTexture(GL_TEXTURE_2D, handle);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, filter);
		glTexParameterf(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, filter);
	}
	
	int Texture::GetTexUnit(){
		return tex_unit;		
	}

	void Texture::Bind()
	{
		glActiveTexture(GL_TEXTURE0+tex_unit);
		glBindTexture(GL_TEXTURE_2D, handle);
	}

}