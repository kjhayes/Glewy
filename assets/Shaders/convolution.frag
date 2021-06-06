#version 330

in vec2 TextureCoord;
out vec4 _color;

uniform sampler2D gly_texture;

const float offset = 1.0 / 500.0;

void main(){

vec2 offsets[9] = vec2[](
    vec2(-offset,  offset), // top-left
    vec2( 0.0f,    offset), // top-center
    vec2( offset,  offset), // top-right
    vec2(-offset,  0.0f),   // center-left
    vec2( 0.0f,    0.0f),   // center-center
    vec2( offset,  0.0f),   // center-right
    vec2(-offset, -offset), // bottom-left
    vec2( 0.0f,   -offset), // bottom-center
    vec2( offset, -offset)  // bottom-right    
);


float kernel[9] = float[](
    -2, -2, -2,
    -2, 16, -2,
    -2, -2, -2
);

vec3 sampleTex[9];
for(int i = 0; i < 9; i++)
{
    sampleTex[i] = vec3(texture(gly_texture, TextureCoord.st + offsets[i]));
}
vec3 col = vec3(0.0, 0.0, 0.0);
for(int i = 0; i < 9; i++){
    col += sampleTex[i] * kernel[i];
}
_color = vec4(col, 1.0);

}