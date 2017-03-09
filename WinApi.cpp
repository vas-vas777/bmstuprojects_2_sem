#include<windows.h>
#include<math.h>

//Идентификаторы наших контролов: полей ввода и кнопки
#define EDIT1  110
#define EDIT3  112
#define BUTTON 113

//Глобальные переменные
static TCHAR szWindowClass[] = ("win32app");//Имя класса главного окна
static TCHAR szTitle[] = ("Перевод из 10 СС в 8 СС  ");//Заголовок окна

												   // Список функций
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
void Addition(HWND hWnd);

//Главная функция
int WINAPI WinMain(HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nCmdShow)
{
	//Определим внешний вид окна
	WNDCLASSEX wcex;
	wcex.cbSize = sizeof(WNDCLASSEX);
	wcex.style = CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc = WndProc;//Тут прописана та функция, в которой прописан главный функционал
	wcex.cbClsExtra = 0;
	wcex.cbWndExtra = 0;
	wcex.hInstance = hInstance;
	wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_APPLICATION));
	wcex.hCursor = LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
	wcex.lpszMenuName = NULL;
	wcex.lpszClassName = szWindowClass;
	wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_APPLICATION));

	//Зарегистрируем наше окно
	if (!RegisterClassEx(&wcex))
	{
		MessageBox(NULL,
			("Call to RegisterClassEx failed!"),
			("Win32 Guided Tour"),
			NULL);

		return 1;
	}

	//Создадим окно
	HWND hWnd = CreateWindow(
		szWindowClass,
		szTitle,
		WS_OVERLAPPEDWINDOW,
		CW_USEDEFAULT, CW_USEDEFAULT,
		350, 350,//Размеры окна
		NULL,
		NULL,
		hInstance,
		NULL
	);
	if (!hWnd)
	{
		MessageBox(NULL,
			("Создать окно не получилось"),
			("Ошибка"),
			NULL);

		return 1;
	}

	// Теперь можем запустить наше окно
	ShowWindow(hWnd,
		nCmdShow);
	UpdateWindow(hWnd);

	// Слушаем сообщения от ОС
	MSG msg;
	BOOL bret;
	while ((bret = GetMessage(&msg, NULL, 0, 0)) != 0)
	{
		if (bret == -1) break;
		else
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int)msg.wParam;
}


void Addition(HWND hWnd)
{
	BOOL success = false;
	int a = GetDlgItemInt(hWnd, EDIT1, &success, true);
	if (!success) {
		MessageBox(hWnd, TEXT("В первом поле не целое число"), TEXT("Ошибка"), MB_OK);
	}
	int c[100],d=0;
	for (int i = 0; i < 100; ++i)
	{
		c[i] = 0;
	}
	int i = 0;
	while (a != 0)
	{
		c[i] = a % 8;
		a = a / 8;
		i++;
	}
	i--;
	
	for (; i >= 0; i--)
	{
		d += c[i] * pow(10, i);
		
	}
	SetDlgItemInt(hWnd, EDIT3, d, true);
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	switch (message)
	{
	case WM_CREATE:
		//Первое число
		CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT("0"),
			WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | WS_TABSTOP,
			20, 10, 85, 25, hWnd, HMENU(EDIT1), GetModuleHandle(NULL), NULL);

		
		//Сюда будем выводить результат
		CreateWindowEx(WS_EX_CLIENTEDGE, TEXT("EDIT"), TEXT("0"),
			WS_CHILD | WS_VISIBLE | ES_AUTOHSCROLL | WS_TABSTOP,
			20, 85, 85, 25, hWnd, HMENU(EDIT3), GetModuleHandle(NULL), NULL);

		//Кнопка сложения
		CreateWindowEx(NULL, TEXT("BUTTON"), TEXT("change"),
			WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON | WS_TABSTOP,
			115, 45, 60, 30, hWnd, HMENU(BUTTON), GetModuleHandle(NULL), NULL);

		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case BUTTON:
			Addition(hWnd);
			return 1;
		}
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
		break;
	}

	return 0;
}

