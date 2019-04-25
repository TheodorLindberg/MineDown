#pragma once
#include <glad/glad.h>

class Texture
{
public:
	unsigned int ID;

	int width, height, nrChannels;

	bool LoadFromFile(const char* filePath);
	void Use();

};