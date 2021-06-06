#include<Glewy/Standard/sprite.hpp>

#include<Glewy/Structures/mat.hpp>

#include<Glewy/Core/logging.hpp>

#define GLEW_STATIC
#include<GL/glew.h>

#include<Glewy/Core/root.hpp>
#include<Glewy/Rendering/material.hpp>
#include<Glewy/Rendering/texture.hpp>
#include<Glewy/Scene/entity.hpp>
#include<Glewy/Structures/transform.hpp>

namespace gly
{

Material* Sprite::sprite_material_default = nullptr;

const char* Sprite::sprite_vert_shader_default = "#version 330\n"
    "layout (location = 0) in vec3 Position;\n"
    "out vec2 TextureCoord;\n"
    "uniform mat4 gly_transform;\n"
    "uniform mat4 gly_view;\n"
    "void main()\n"
    "{\n"
	"TextureCoord = Position.xy+vec2(0.5,0.5);\n"
	"gl_Position = gly_view*gly_transform*vec4(Position, 1.0);}";
    
const char* Sprite::sprite_frag_shader_default = "#version 330\n"
    "in vec2 TextureCoord;\n"
    "out vec4 _color;\n"
    "uniform sampler2D gly_texture;\n"
    "void main()\n"
    "{\n"
	"_color = texture2D(gly_texture, TextureCoord);\n"
    "}\n";

vec3<gly_float> sprite_vertices_default[4]
{
	{-0.5f,-0.5f,0.0f},
	{0.5f,-0.5f,0.0f},
	{-0.5f,0.5f,0.0f},
	{0.5f,0.5f,0.0f}
};

Sprite::Sprite(Entity* entity):Attachment(entity)
{
	if(sprite_material_default==nullptr){
		sprite_material_default = new Material(sprite_vert_shader_default, sprite_frag_shader_default, false);
	} 
	SetMaterial(sprite_material_default);
	InitVBO();
	GetEntity()->GetRoot()->LoadRenderable(this);
}

Sprite::~Sprite(){
	GetEntity()->GetRoot()->UnloadRenderable(this);
}

void Sprite::InitVBO()
{
	glGenBuffers(1, &VBO);
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	glBufferData(GL_ARRAY_BUFFER, sizeof(sprite_vertices_default), sprite_vertices_default, GL_STATIC_DRAW);
	glBindBuffer(GL_ARRAY_BUFFER, 0);
}

void Sprite::Render()
{
	GLuint gly_texture_location = glGetUniformLocation(GetMaterial()->program, "gly_texture");
	if(gly_texture_location!=-1){glUniform1i(gly_texture_location, texture->tex_unit);}
	
	GLuint gly_transform_location = glGetUniformLocation(GetMaterial()->program, "gly_transform");
	if(gly_transform_location!=-1){
		mat4<gly_float> mat = entity->GetTransform()->GlobalMatrix();
		glUniformMatrix4fv(gly_transform_location, 1, GL_FALSE, (const float*)&mat);}
	
	glEnableVertexAttribArray(0);
	
	glBindBuffer(GL_ARRAY_BUFFER, VBO);
	
	glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, 0);
	
	texture->Bind();
	
	glDrawArrays(GL_TRIANGLE_STRIP, 0, 4);
	
	glDisableVertexAttribArray(0);
}

}