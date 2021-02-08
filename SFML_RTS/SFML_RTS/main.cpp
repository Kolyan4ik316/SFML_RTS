#include "Game.h"
#include <Windows.h>
#pragma comment(lib, "Winmm.lib")


/*int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)*/
int main()
{
	try
	{
		Game game;
		game.Run();

	}
	catch (std::exception& e)
	{
		MessageBoxA(NULL, e.what(), "Exception was throwned!", MB_OK | MB_ICONERROR | MB_APPLMODAL);
	}
	catch (...)
	{
		MessageBoxA(NULL, "Uknown reason", "Exception was throwned!", MB_OK | MB_ICONERROR | MB_APPLMODAL);
	}
	return 0;
}