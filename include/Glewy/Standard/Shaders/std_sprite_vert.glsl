#version 330

layout (location = 0) in vec3 Position;

out vec2 TextureCoord;

uniform mat4 gly_transform;
uniform mat4 gly_view;

void main()
{
	TextureCoord = Position.xy+vec2(0.5,0.5);
	gl_Position = gly_view*gly_transform*vec4(Position, 1.0);
}