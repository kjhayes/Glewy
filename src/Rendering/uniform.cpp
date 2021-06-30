#include<Glewy/Rendering/uniform.hpp>

#define GLEW_STATIC
#include<GL/glew.h>

#include<Glewy/Rendering/material.hpp>
#include<Glewy/Rendering/texture.hpp>
#include<Glewy/Structures/transform.hpp>

namespace gly
{

Uniform::Uniform(Material* material):material(material){}
Uniform::Uniform(Material* material, const char* name):material(material){
    SetUniformName(name);
}

int Uniform::GetLocation(){return location;}

void Uniform::SetUniformName(const char* name){
    location = glGetUniformLocation(material->program, name);
}

bool Uniform::Exists(){return (location != -1);}


void Uniform::SetUniform(Uniform* u, const float& f){glUniform1f(u->GetLocation(),f);}
void Uniform::SetUniform(Uniform* u, const vec2<float>& f){glUniform2f(u->GetLocation(),f.x,f.y);}
void Uniform::SetUniform(Uniform* u, const vec3<float>& f){glUniform3f(u->GetLocation(),f.x,f.y,f.z);}
void Uniform::SetUniform(Uniform* u, const vec4<float>& f){glUniform4f(u->GetLocation(),f.x,f.y,f.z,f.w);}
 
void Uniform::SetUniform(Uniform* u, const int& i){glUniform1i(u->GetLocation(),i);}
void Uniform::SetUniform(Uniform* u, const vec2<int>& i){glUniform2i(u->GetLocation(),i.x,i.y);}
void Uniform::SetUniform(Uniform* u, const vec3<int>& i){glUniform3i(u->GetLocation(),i.x,i.y,i.z);}
void Uniform::SetUniform(Uniform* u, const vec4<int>& i){glUniform4i(u->GetLocation(),i.x,i.y,i.z,i.w);}
 
void Uniform::SetUniform(Uniform* u, const unsigned int& ui){glUniform1ui(u->GetLocation(),ui);}
void Uniform::SetUniform(Uniform* u, const vec2<unsigned int>& ui){glUniform2ui(u->GetLocation(),ui.x,ui.y);}
void Uniform::SetUniform(Uniform* u, const vec3<unsigned int>& ui){glUniform3ui(u->GetLocation(),ui.x,ui.y,ui.z);}
void Uniform::SetUniform(Uniform* u, const vec4<unsigned int>& ui){glUniform4ui(u->GetLocation(),ui.x,ui.y,ui.z,ui.w);}
 
void Uniform::SetUniform(Uniform* u, const mat2<float>& m){glUniformMatrix2fv(u->GetLocation(), 1, GL_FALSE, (const float*)&m); }
void Uniform::SetUniform(Uniform* u, const mat3<float>& m){glUniformMatrix3fv(u->GetLocation(), 1, GL_FALSE, (const float*)&m); }
void Uniform::SetUniform(Uniform* u, const mat4<float>& m){glUniformMatrix4fv(u->GetLocation(), 1, GL_FALSE, (const float*)&m); }
 
void Uniform::SetUniform(Uniform* u, Transform* trans){Uniform::SetUniform(u,trans->GetGlobalMatrix());}
void Uniform::SetUniform(Uniform* u, Texture* tex){glUniform1i(u->GetLocation(), tex->GetTexUnit());}

}
