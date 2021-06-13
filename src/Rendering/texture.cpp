#include<Glewy/Rendering/texture.hpp>

#include<SOIL/SOIL.h>

#define GLEW_STATIC
#include "GL/glew.h"

#include<iostream>

namespace gly
{
	void Texture::SingleColor(const vec4<gly_float>& color){
		vec4<unsigned char> data;
		data.r = color.r*255;
		data.g = color.g*255;
		data.b = color.b*255;
		data.a = color.a*255;
		this->handle = SOIL_create_OGL_texture(
			data.array,
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
	
	void Texture::LoadFromFile(const char* file_name){
		this->handle = SOIL_load_OGL_texture
		(
			file_name,
			4,
			handle,
			SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_MULTIPLY_ALPHA
		);
		
		if(handle == 0){std::cout<<"Error Loading Image: "<<file_name<<std::endl;}
		
		glBindTexture(GL_TEXTURE_2D, handle);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &x_size);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &y_size);
	}

	void Texture::LoadFromData(const AssetCode& code){
		this->handle = SOIL_load_OGL_texture_from_memory
		(
			code.data_addr,
			code.size,
			4,
			handle,
			SOIL_FLAG_TEXTURE_REPEATS | SOIL_FLAG_INVERT_Y | SOIL_FLAG_MULTIPLY_ALPHA
		);
		
		if(handle == 0){std::cout<<"Error Loading Image From Memory: "<<(int)code.data_addr<<" |Size: "<<code.size<<" bytes|"<<std::endl;}
		
		glBindTexture(GL_TEXTURE_2D, handle);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_WIDTH, &x_size);
		glGetTexLevelParameteriv(GL_TEXTURE_2D, 0, GL_TEXTURE_HEIGHT, &y_size);	
	}

	Texture::Texture(const AssetCode& code){LoadFromData(code);SetFilter(GL_NEAREST);}

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