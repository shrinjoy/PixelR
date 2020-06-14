#version 330 core
out vec4 FragColor;
in vec4 SColor;
in vec2 STexCoord;
uniform sampler2D Texturedata;//sampler cant be empty
void main()
{
         FragColor = texture(Texturedata,STexCoord)*SColor;  
}
//