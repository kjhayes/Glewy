#ifndef GLEWY_TEXTURE_HPP
#define GLEWY_TEXTURE_HPP

typedef unsigned int GLuint;
typedef unsigned int GLenum;

#include<Glewy/Structures/vec.hpp>
#include<Glewy/Content/asset.hpp>

namespace gly
{

class Texture : public Asset<Texture>
{
friend class Asset<Texture>;

protected:
	GLuint handle = 0;
	int x_size, y_size;
	
	Texture(const AssetCode& code);

	void SingleColor(const vec4<gly_float>& color);

	void LoadFromFile(const char* file_name);
	void LoadFromData(const AssetCode& code) override;

	void SetFilter(GLenum);

	int tex_unit = 0;

public:
	int GetTexUnit();
	void Bind();
};

}

#endif