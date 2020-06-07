#include "PixelR.h"
#define STB_IMAGE_IMPLEMENTATION
#include "stb_image.h"
unsigned int Texture2D::loadtexture(std::string pathtotexture)
{
	
	unsigned int textureid;
	glGenTextures(1, &textureid);
	glBindTexture(GL_TEXTURE_2D, textureid);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);
	glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
	int w, h, n;
	unsigned char* imagedata = stbi_load(pathtotexture.c_str(), &w, &h, &n, 0);
	if (imagedata)
	{
		std::cout << "data found:image" << std::endl;
		glTexImage2D(GL_TEXTURE_2D, GL_RGBA, w, h, NULL, GL_RGBA, 0, GL_UNSIGNED_BYTE, imagedata);
		glGenerateMipmap(textureid);
		stbi_image_free(imagedata);
		return textureid;
	}
	else
	{
		std::cout << "bad data" << std::endl;
		return -1;
	}
	}