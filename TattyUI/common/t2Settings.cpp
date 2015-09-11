﻿#include <TattyUI/common/t2Settings.h>
#include <stddef.h>
#include <assert.h>
#include <float.h>
#include <stdio.h>
#include <stdarg.h>
#include <stdlib.h>

// --！重大革新:小改动:BUG修复
t2Version tattyVersion = { 0, 0, 4 };

// 注意:只能在Debug模式下才能使用
void t2Log(const char* string, ...)
{
#ifdef _DEBUG
	va_list args;
	va_start(args, string);
	vprintf(string, args);
	va_end(args);
#endif
}

#ifdef T2_PLATFORM_WINDOWS
int strcasecmp(const char *a, const char *b)
{
	char ca, cb;
	do
	{
		ca = *a++;
		cb = *b++;
		ca = tolower(ca);
		cb = tolower(cb);
	} while((ca == cb) && (ca));
	return (int)ca - cb;
}
#endif


static int t2WindowWidth = 0, t2WindowHeight = 0;

void t2SetWindowWidth(int width)
{
	t2WindowWidth = width;
}

void t2SetWindowHeight(int height)
{
	t2WindowHeight = height;
}

int t2GetWindowWidth()
{
    return t2WindowWidth;
}

int t2GetWindowHeight()
{
    return t2WindowHeight;
}

int glVersionMinor = 4, glVersionMajor = 4;

int t2GetGLVersionMajor() 
{
    return glVersionMajor;
}

int t2GetGLVersionMinor() 
{
    return glVersionMinor;
}

void t2SetGLVersionMajor(int major) 
{
    glVersionMajor = major;
}

void t2SetGLVersionMinor(int minor) 
{
    glVersionMinor = minor;
}