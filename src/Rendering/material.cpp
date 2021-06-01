#include<Glewy/Rendering/material.hpp>

#include<Glewy/Core/macros.hpp>
#include<Glewy/Structures/mat.hpp>

#define GLEW_STATIC
#include<GL/glew.h>

#include<Glewy/Rendering/materialrenderable.hpp>
#include<Glewy/Scene/camera.hpp>
#include<Glewy/Utilities/readfile.hpp>

namespace gly
{

std::list<Material*> Material::registry;

const char* def_vert = "#version 330\n"
	"layout (location = 0) in vec3 Position;\n"
	"void main(){\n"
	"gl_Position = vec4(Position, 1.0);\n"
	"}\n";
	
const char* def_frag = "#version 330\n"
	"out vec4 color;\n"
	"void main(){\n"
	"color = vec4(1.0,0.0,1.0,1.0);\n"
	"}\n";

Material::Material(const char* vs, const char* fs, bool is_path)
{
	registry.push_back(this);

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
	Load();
}

Material::~Material()
{
	registry.remove(this);

	glDeleteShader(vert);
	glDeleteShader(frag);
	glDeleteProgram(program);
}

Material::Material(bool load_def)
{
	registry.push_back(this);
	
	program = glCreateProgram();
	vert = glCreateShader(GL_VERTEX_SHADER);
	frag = glCreateShader(GL_FRAGMENT_SHADER);
	
	if(load_def){
	this->SetVert_Data(def_vert);
	this->SetFrag_Data(def_frag);
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
	#ifdef GLEWY_DEBUG
	GLint success;
	glGetShaderiv(vert, GL_COMPILE_STATUS, &success);
	if (!success) {
		GLchar InfoLog[1024];
		glGetShaderInfoLog(vert, sizeof(InfoLog), NULL, InfoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_VERTEX_SHADER, InfoLog);
	}
	else{
	std::cout<<"Vertex Shader Compiled Sucessfully"<<std::endl;
	}
	#endif
	glAttachShader(program, vert);
}

void Material::SetVert_Data(const char* vs_data)
{
	glShaderSource(vert, 1, &vs_data, NULL);
	glCompileShader(vert);
	#ifdef GLEWY_DEBUG
	GLint success;
	glGetShaderiv(vert, GL_COMPILE_STATUS, &success);
	if (!success) {
		GLchar InfoLog[1024];
		glGetShaderInfoLog(vert, sizeof(InfoLog), NULL, InfoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_VERTEX_SHADER, InfoLog);
	}
	else{
	std::cout<<"Vertex Shader Compiled Sucessfully"<<std::endl;
	}
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
	#ifdef GLEWY_DEBUG
	GLint success;
	glGetShaderiv(frag, GL_COMPILE_STATUS, &success);
	if (!success) {
		GLchar InfoLog[1024];
		glGetShaderInfoLog(frag, sizeof(InfoLog), NULL, InfoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_FRAGMENT_SHADER, InfoLog);
	}
	else{
	std::cout<<"Fragment Shader Compiled Sucessfully"<<std::endl;
	}
	#endif
	glAttachShader(program, frag);
}

void Material::SetFrag_Data(const char* fs_data)
{
	glShaderSource(frag, 1, &fs_data, NULL);
	glCompileShader(frag);
	#ifdef GLEWY_DEBUG
	GLint success;
	glGetShaderiv(frag, GL_COMPILE_STATUS, &success);
	if (!success) {
		GLchar InfoLog[1024];
		glGetShaderInfoLog(frag, sizeof(InfoLog), NULL, InfoLog);
		fprintf(stderr, "Error compiling shader type %d: '%s'\n", GL_FRAGMENT_SHADER, InfoLog);
	}
	else{
	std::cout<<"Fragment Shader Compiled Sucessfully"<<std::endl;
	}
	#endif
	glAttachShader(program, frag);
}

void Material::Load()
{
	glLinkProgram(program);
	#ifdef GLEWY_DEBUG
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

void Material::SetActive()
{
	glUseProgram(program);
}
	
void Material::Queue(MaterialRenderable* ren)
{to_render.push_back(ren);}

void Material::ClearQueue()
{
	to_render.clear();
}

void Material::RenderQueue(Camera* camera)
{
	SetActive();
	GLuint gly_view_location = glGetUniformLocation(program, "gly_view");
	if(gly_view_location!=-1){mat4<gly_float> view = camera->ViewMatrix();
		glUniformMatrix4fv(gly_view_location, 1, GL_FALSE, (const float*)&view);}
	for(auto iter = to_render.begin(); iter != to_render.end(); iter++)
	{(*iter)->Render();}
}

void Material::RenderAll(Camera* camera)
{
	for(auto iter = registry.begin(); iter != registry.end(); iter++)
	{
		(*iter)->RenderQueue(camera);
		(*iter)->ClearQueue();
	}
}

}