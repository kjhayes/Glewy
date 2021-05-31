#version 330

in vec2 TextureCoord;

out vec4 _color;

uniform sampler2D gly_texture;

void main()
{
	_color = texture2D(gly_texture, TextureCoord);
}
