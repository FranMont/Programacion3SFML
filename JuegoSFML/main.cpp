#include<iostream>
#include <windows.h>
#include"Juego.h"

#if _DEBUG
#define USE_CONSOLE true
#else
#define USE_CONSOLE false
#endif

int main()
{
	Juego * GG = new Juego();
	if (!USE_CONSOLE)
	{
		ShowWindow(GetConsoleWindow(), SW_HIDE);
	}
	GG->Run();
	delete GG;
	return 0;
}