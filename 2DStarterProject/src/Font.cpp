#include "gl_core_4_4.h"
#include "Font.h"
#define STB_TRUETYPE_IMPLEMENTATION
#include <stb_truetype.h>
#include <stdio.h>

Font::Font(const char* trueTypeFontFile, unsigned short fontHeight) 
	: m_glyphData(nullptr),
	m_glHandle(0),
	m_pixelBufferHandle(0),
	m_sizeOfBytesX(0),
	m_sizeOfBytesY(0) {
	
	FILE* file = nullptr;
	fopen_s(&file, trueTypeFontFile, "rb");
	if (file != nullptr) {
		
		unsigned char* ttf_buffer = new unsigned char[4096 * 1024];

		fread(ttf_buffer, 1, 4096 * 1024, file);
		fclose(file);

		m_sizeOfBytesX = fontHeight / 16 * 128;
		m_sizeOfBytesY = fontHeight / 16 * 128;

		if (fontHeight <= 16) {
			m_sizeOfBytesX = 128;
			m_sizeOfBytesY = 128;
		}

		glGenBuffers(1, &m_pixelBufferHandle);
		glBindBuffer(GL_PIXEL_UNPACK_BUFFER, m_pixelBufferHandle);
		glBufferData(GL_PIXEL_UNPACK_BUFFER, m_sizeOfBytesX * m_sizeOfBytesY, nullptr, GL_STREAM_COPY);
		unsigned char* tempBitmapData = (GLubyte*)glMapBufferRange(GL_PIXEL_UNPACK_BUFFER, 0, 
																   m_sizeOfBytesX * m_sizeOfBytesY,
																   GL_MAP_WRITE_BIT | GL_MAP_INVALIDATE_BUFFER_BIT);

		m_glyphData = new stbtt_bakedchar[256];
		memset(m_glyphData, 0, sizeof(stbtt_bakedchar) * 256);
		stbtt_BakeFontBitmap(ttf_buffer, 0, fontHeight, tempBitmapData, m_sizeOfBytesX, m_sizeOfBytesY, 0, 256, (stbtt_bakedchar*)m_glyphData);

		glUnmapBuffer(GL_PIXEL_UNPACK_BUFFER);

		glGenTextures(1, &m_glHandle);
		glBindTexture(GL_TEXTURE_2D, m_glHandle);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_BASE_LEVEL, 0);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAX_LEVEL, 0);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_S, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_T, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_WRAP_R, GL_REPEAT);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MAG_FILTER, GL_LINEAR);
		glTexParameteri(GL_TEXTURE_2D, GL_TEXTURE_MIN_FILTER, GL_LINEAR);

		glTexStorage2D(GL_TEXTURE_2D, 1, GL_R8, m_sizeOfBytesX, m_sizeOfBytesY);

		glTexSubImage2D(GL_TEXTURE_2D, 0, 0, 0, m_sizeOfBytesX, m_sizeOfBytesY, GL_RED, GL_UNSIGNED_BYTE, nullptr);
		glBindBuffer(GL_PIXEL_UNPACK_BUFFER, 0);

		delete[] ttf_buffer;
	}
}

Font::~Font() {
	delete[] (stbtt_bakedchar*)m_glyphData;

	glDeleteTextures(1, &m_glHandle);
	glDeleteBuffers(1, &m_pixelBufferHandle);
}