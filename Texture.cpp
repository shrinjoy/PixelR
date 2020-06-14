#include "PixelR.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
void Texture2D::loadtexture(std::string pathtotexture)
{

	stbi_set_flip_vertically_on_load(true);
	glGenTextures(1, &textureid);
	glBindTexture(GL_TEXTURE_2D, textureid);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);

	unsigned char* imagedata = stbi_load(pathtotexture.c_str(), &w, &h, &n, 0);
	if (imagedata)
	{
		std::cout << "data found:image:" << std::endl;
		glTexImage2D(GL_TEXTURE_2D, 0, GL_RGBA, w, h, 0, GL_RGBA, GL_UNSIGNED_BYTE, imagedata);


		glGenerateMipmap(GL_TEXTURE_2D);

		stbi_image_free(imagedata);


	}
	else
	{
		std::cout << "bad data" << std::endl;

	}
}
void Texture2D::usetexture()
{
	glBindTexture(GL_TEXTURE_2D, textureid);
}