#include<Glewy/Rendering/material.hpp>

#include<Glewy/Core/macros.hpp>
#include<Glewy/Structures/mat.hpp>

#define GLEW_STATIC
#include<GL/glew.h>

#include<Glewy/Scene/camera.hpp>
#include<Glewy/Utilities/readfile.hpp>
#include<Glewy/Rendering/shaders.hpp>

namespace gly
{


void Debug_Shader_Test(GLuint shader){
	GLint success;
	glGetShaderiv(shader, GL_COMPILE_STATUS, &success);
	if (!success) {
		GLchar InfoLog[1024];
		glGetShaderInfoLog(shader, sizeof(InfoLog), NULL, InfoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_FRAGMENT_SHADER, InfoLog);
	}
	else{
	std::cout<<"Shader Compiled Sucessfully"<<std::endl;
	}
}

Material::Material(const char* vs, const char* fs, bool is_path)
{
	program = glCreateProgram();
	vert = glCreateShader(GL_VERTEX_SHADER);
	frag = glCreateShader(GL_FRAGMENT_SHADER);
	
	if(is_path){
		SetVert(vs);
		SetFrag(fs);
	}
	else{
		SetVert_Data(vs);
		SetFrag_Data(fs);
	}
	Link();
}

Material::~Material()
{
	glDeleteShader(vert);
	glDeleteShader(frag);
	glDeleteProgram(program);
}

Material::Material(bool load_def)
{
	program = glCreateProgram();
	vert = glCreateShader(GL_VERTEX_SHADER);
	frag = glCreateShader(GL_FRAGMENT_SHADER);
	
	if(load_def){
	this->SetVert_Data(Shaders::default_vert);
	this->SetFrag_Data(Shaders::default_frag);
	glLinkProgram(program);
	}	
}

void Material::SetVert(const char* vs_path)
{
	std::string data;
	if(ReadFile(vs_path, data)){return;}
	const char* c_str_data = data.c_str();
	glShaderSource(vert, 1, &c_str_data, NULL);
	glCompileShader(vert);
	
	#if defined(GLEWY_DEBUG) && defined(GLEWY_SHADER_DEBUG)
	Debug_Shader_Test(vert);
	#endif
	
	glAttachShader(program, vert);
}
void Material::SetVert_Data(const char* vs_data)
{
	glShaderSource(vert, 1, &vs_data, NULL);
	glCompileShader(vert);

	#if defined(GLEWY_DEBUG) && defined(GLEWY_SHADER_DEBUG)
	Debug_Shader_Test(vert);
	#endif
	
	glAttachShader(program, vert);
}
void Material::SetFrag(const char* fs_path)
{
	std::string data;
	if(ReadFile(fs_path, data)){return;}
	const char* c_str_data = data.c_str();
	glShaderSource(frag, 1, &c_str_data, NULL);
	glCompileShader(frag);
	
	#if defined(GLEWY_DEBUG) && defined(GLEWY_SHADER_DEBUG)
	Debug_Shader_Test(frag);
	#endif
	
	glAttachShader(program, frag);
}
void Material::SetFrag_Data(const char* fs_data)
{
	glShaderSource(frag, 1, &fs_data, NULL);
	glCompileShader(frag);

	#if defined(GLEWY_DEBUG) && defined(GLEWY_SHADER_DEBUG)
	Debug_Shader_Test(frag);
	#endif

	glAttachShader(program, frag);
}

void Material::Link() const
{
	glLinkProgram(program);

	#if defined(GLEWY_DEBUG) && defined(GLEWY_SHADER_DEBUG)
	GLint success;
	glGetProgramiv(program, GL_LINK_STATUS, &success);
	if (!success) {
	GLchar ErrorLog[1024];
    glGetProgramInfoLog(program, sizeof(ErrorLog), NULL, ErrorLog);
    fprintf(stderr, "Error linking shader program: '%s'\n", ErrorLog);
	}
	else{
	std::cout<<"Shader Program Linked Sucessfully"<<std::endl;
	}
	#endif
}

void Material::SetActive() const
{
	glUseProgram(program);
}

void Material::SetView(Camera* camera) const {
	GLuint gly_view_location = glGetUniformLocation(program, "gly_view");
	if(gly_view_location!=-1){mat4<gly_float> view = camera->GetGlobalMatrix();
		glUniformMatrix4fv(gly_view_location, 1, GL_FALSE, (const float*)&view);}	
}

}