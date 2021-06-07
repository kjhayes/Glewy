#include<Glewy/Rendering/shaders.hpp>

namespace gly{

const char* Shaders::transform_texture_vert = 
    "#version 330\n"
    "layout (location = 0) in vec3 Position;\n"
    "out vec2 TextureCoord;\n"
    "uniform mat4 gly_transform;\n"
    "uniform mat4 gly_view;\n"
    "void main()\n"
    "{\n"
	"TextureCoord = Position.xy+vec2(0.5,0.5);\n"
	"gl_Position = gly_view*gly_transform*vec4(Position, 1.0);}";
    
const char* Shaders::transform_texture_frag = 
    "#version 330\n"
    "in vec2 TextureCoord;\n"
    "out vec4 _color;\n"
    "uniform sampler2D gly_texture;\n"
    "void main()\n"
    "{\n"
	"_color = texture2D(gly_texture, TextureCoord);\n"
    "}\n";

const char* Shaders::transform_texture_atlas_frag = 
    "#version 330\n"
    "in vec2 TextureCoord;\n"
    "out vec4 _color;\n"
    "uniform sampler2D gly_texture;\n"
    "uniform vec2 gly_atlas_offset;\n"
    "uniform vec2 gly_atlas_size;\n"
    "void main()\n"
    "{\n"
    "vec2 atlas_pos = vec2((TextureCoord.x*gly_atlas_size.x)+gly_atlas_offset.x, (TextureCoord.y*gly_atlas_size.y)+gly_atlas_offset.y);\n"
	"_color = texture2D(gly_texture, atlas_pos);\n"
    "}\n";

}