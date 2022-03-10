#include <Windows.h>
#include <Defines.h>
#include "main.h"
#include <cstdio>
#include <crtdbg.h>

//timeGetTime周りの使用
#pragma comment(lib,"winmm.lib")

//--プロトタイプ宣言--//
LRESULT CALLBACK WndProc(HWND hWnd,UINT message,WPARAM wParam,LPARAM lParam);

//	エントリポイント
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow) {
	
	//メモリのデバッグ？
	_CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);

	//変数宣言
	WNDCLASSEX wcex;
	HWND hWnd;
	MSG message;

	//	ウィンドウクラス情報の設定
	ZeroMemory(&wcex,sizeof(wcex));		//wcexの初期化
	wcex.hInstance = hInstance;
	wcex.lpszClassName = "Class Name";
	wcex.lpfnWndProc = WndProc;
	wcex.style = CS_CLASSDC | CS_DBLCLKS;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.hIcon = LoadIcon(nullptr,IDI_APPLICATION);
	wcex.hIconSm = wcex.hIcon;
	wcex.hCursor = LoadCursor(nullptr,IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)GetStockObject(WHITE_BRUSH);
	
	//ウィンドウクラス情報の登録
	if (!RegisterClassEx(&wcex)) {
		MessageBox(nullptr,"Fail to RegisterClassEx","Error",MB_OK);
		return 0;
	}

	//ウィンドウの作成

}