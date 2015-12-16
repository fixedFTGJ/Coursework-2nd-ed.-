#pragma once
#ifndef __TEXTURE_H
#define __TEXTURE_H

// ������ ���������� DevIL
#include "IL\il.h"
#include "IL\ilu.h"
#include <glew.h>

// �������� ��������� TextureImage ��� �������� ������ ��������.
typedef struct TextureImage
{
	GLubyte *imageData;     // ������ ��������
	GLuint  bpp;            // ���� �� ������
	GLuint width, height;        // ������ � ������
	GLuint texID;           // ID ��������
}TextureImage;


// ����� �������. �������� � �������������.
class CTexture {
public:

	CTexture();
	~CTexture();

	// ����������, ����� ��� ������ ������� - � �� ������ 2 ������� - 
	// �������� � ������������ ������� =)
	void LoadTexture(ILenum FileType, char *filename, TextureImage *texture);
	void FreeTexture(TextureImage *texture);
};


#endif