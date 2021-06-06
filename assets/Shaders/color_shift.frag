#version 330

in vec2 TextureCoord;
uniform sampler2D gly_texture;
out vec4 _color;

void main(){
    vec4 col = texture(gly_texture, TextureCoord).rgba;
    col.g = (col.r+col.g+col.b)/3.0;
    col.r = 0.0;
    col.b = 0.0;
    _color = col;
}