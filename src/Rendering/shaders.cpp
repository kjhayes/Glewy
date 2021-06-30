#include<Glewy/Rendering/shaders.hpp>

namespace gly{


const char* Shaders::default_vert = 
    "#version 330\n"
	"layout (location = 0) in vec3 Position;\n"
	"void main(){\n"
	"gl_Position = vec4(Position, 1.0);\n"
	"}\n";
	
const char* Shaders::default_frag = 
    "#version 330\n"
	"out vec4 color;\n"
	"void main(){\n"
	"color = vec4(1.0,0.0,1.0,1.0);\n"
	"}\n";

const char* Shaders::solid_color_frag = 
    "#version 330\n"
	"out vec4 color;\n"
    "uniform vec4 gly_color;\n"
	"void main(){\n"
	"color = gly_color;\n"
	"}\n";

const char* Shaders::default_line_vert =
    "#version 330\n"
    "uniform vec3 gly_pos_x;\n"
    "uniform vec3 gly_pos_y;\n"
    "uniform vec4 gly_color_x;\n"
    "uniform vec4 gly_color_y;\n"
    "out vec4 col;\n"
	"void main(){\n"
	"if(gl_VertexID == 0){col = gly_color_x; gl_Position = vec4(gly_pos_x, 1.0);}\n"
	"else{col = gly_color_y; gl_Position = vec4(gly_pos_y, 1.0);}\n"
    "}\n";
	
const char* Shaders::default_line_frag =
    "#version 330\n"
	"out vec4 color;\n"
    "in vec4 col;\n"
	"void main(){\n"
	"color = col;\n"
	"}\n";

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

const char* Shaders::renderer_vert = 
    "#version 330\n"
    "layout (location = 0) in vec3 Position;\n"
    "out vec2 TextureCoord;\n"
    "void main()\n"
    "{\n"
    "TextureCoord = (Position.xy*0.5)+vec2(0.5,0.5);\n"
    "gl_Position = vec4(Position, 1.0);\n"
    "}\n";
    
const char* Shaders::renderer_frag = 
    "#version 330\n"   
    "in vec2 TextureCoord;\n"
    "out vec4 _color;\n"
    "uniform sampler2D gly_texture;\n"
    "void main()\n"
    "{\n"
    "vec4 color = vec4(texture(gly_texture, TextureCoord).rgb, 1.0);\n"
    "_color = color;\n" //It seems important to pass the texture value in two steps: Not Sure Why
    "}\n";

const char* Shaders::transform_texture_instance2i_vert =    
    "#version 330\n"
    "layout (location = 0) in vec3 Position;\n"
    "layout (location = 1) in vec2 Offset;\n"
    "out vec2 TextureCoord;\n"
    "uniform mat4 gly_transform;\n"
    "uniform mat4 gly_view;\n"
    "void main()\n"
    "{\n"
	"TextureCoord = Position.xy+vec2(0.5,0.5);\n"
	"gl_Position = gly_view*gly_transform*vec4(Position.xy+Offset, Position.z, 1.0);}";
}