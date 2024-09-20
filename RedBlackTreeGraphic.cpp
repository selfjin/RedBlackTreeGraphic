//
//#include "framework.h"
//#include "RedBlackTreeGraphic.h"
//#include "RedBlackTreeClass.h"
//#include <Windows.h>
//
//#define MAX_LOADSTRING 100
//#define GRID_SIZE 16
//#define IDT_TIMER1 1  // 타이머 ID
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//// 전역 변수:
//HINSTANCE hInst;
//WCHAR szTitle[MAX_LOADSTRING];
//WCHAR szWindowClass[MAX_LOADSTRING];
//
//int GRID_HEIGHT = 100;
//int GRID_WIDTH = 110;
//
//bool g_Erase = false;
//bool g_Drag = false;
//
//char g_Tile[100][110];
//wchar_t g_Text_String[1024];
//
//RedBlackTree g_Tree;
//bool g_AutoInsertMode = false; // 자동 삽입/삭제 모드를 위한 플래그
//int g_CurrentKey = 0;
//
//// 전역 윈도우:
//HWND hEdit;
//HWND hButton;
//
//// 함수 전방 선언
//void RenderGrid(HDC hdc);
//void RenderObstacle(HDC hdc);
//
//// 전역 GDI Object / 변수
//HPEN g_GridPen;
//HBRUSH g_Brush;
//
//float g_Scale = 1.0f;
//const float g_ScaleStep = 0.1f;
//const float g_MinScale = 0.1f;
//const float g_MaxScale = 3.0f;
//
//HBITMAP g_MemDcBitmap;
//HBITMAP g_MemDcBitmap_Old;
//HDC g_MemDc;
//RECT g_MemDcRect;
//
///////////////////////////////////////////////////////////////////////////////////////////////////////////////////
//
//// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
//ATOM MyRegisterClass(HINSTANCE hInstance);
//BOOL InitInstance(HINSTANCE, int);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);
//
//int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
//    _In_opt_ HINSTANCE hPrevInstance,
//    _In_ LPWSTR lpCmdLine,
//    _In_ int nCmdShow)
//{
//    UNREFERENCED_PARAMETER(hPrevInstance);
//    UNREFERENCED_PARAMETER(lpCmdLine);
//
//    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
//    LoadStringW(hInstance, IDC_REDBLACKTREEGRAPHIC, szWindowClass, MAX_LOADSTRING);
//    MyRegisterClass(hInstance);
//
//    if (!InitInstance(hInstance, nCmdShow))
//    {
//        return FALSE;
//    }
//
//    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_REDBLACKTREEGRAPHIC));
//
//    MSG msg;
//
//    while (GetMessage(&msg, nullptr, 0, 0))
//    {
//        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
//        {
//            TranslateMessage(&msg);
//            DispatchMessage(&msg);
//        }
//    }
//
//    return (int)msg.wParam;
//}
//
//ATOM MyRegisterClass(HINSTANCE hInstance)
//{
//    WNDCLASSEXW wcex;
//
//    wcex.cbSize = sizeof(WNDCLASSEX);
//    wcex.style = CS_HREDRAW | CS_VREDRAW;
//    wcex.lpfnWndProc = WndProc;
//    wcex.cbClsExtra = 0;
//    wcex.cbWndExtra = 0;
//    wcex.hInstance = hInstance;
//    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_REDBLACKTREEGRAPHIC));
//    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
//    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
//    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_REDBLACKTREEGRAPHIC);
//    wcex.lpszClassName = szWindowClass;
//    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));
//
//    return RegisterClassExW(&wcex);
//}
//
//BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
//{
//    hInst = hInstance;
//
//    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
//        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);
//
//    if (!hWnd)
//    {
//        return FALSE;
//    }
//
//    ShowWindow(hWnd, nCmdShow);
//    UpdateWindow(hWnd);
//
//    return TRUE;
//}
//
//LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    switch (message)
//    {
//    case WM_CREATE:
//    {
//        HDC hdc = GetDC(hWnd);
//        GetClientRect(hWnd, &g_MemDcRect);
//        g_MemDcBitmap = CreateCompatibleBitmap(hdc, g_MemDcRect.right, g_MemDcRect.bottom);
//        g_MemDc = CreateCompatibleDC(hdc);
//        ReleaseDC(hWnd, hdc);
//        g_MemDcBitmap_Old = (HBITMAP)SelectObject(g_MemDc, g_MemDcBitmap);
//
//        hEdit = CreateWindowW(L"edit", NULL, WS_BORDER | WS_CHILD | WS_VISIBLE | ES_NUMBER | ES_RIGHT,
//            20, 20, 100, 25, hWnd, NULL, hInst, NULL);
//
//        CreateWindowW(
//            L"button",
//            L"Node Insert",
//            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
//            20, 40, 100, 25,
//            hWnd,
//            (HMENU)100,
//            hInst,
//            NULL);
//
//        CreateWindowW(
//            L"button",
//            L"Node Delete",
//            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
//            20, 65, 100, 25,
//            hWnd,
//            (HMENU)101,
//            hInst,
//            NULL);
//
//        CreateWindowW(
//            L"button",
//            L"Start Auto Insert/Delete",
//            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
//            20, 90, 150, 25,
//            hWnd,
//            (HMENU)102,
//            hInst,
//            NULL);
//
//        CreateWindowW(
//            L"button",
//            L"Stop Auto Insert/Delete",
//            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
//            20, 115, 150, 25,
//            hWnd,
//            (HMENU)103,
//            hInst,
//            NULL);
//
//        g_GridPen = CreatePen(PS_SOLID, 1, RGB(200, 200, 200));
//        g_Brush = CreateSolidBrush(RGB(100, 100, 100));
//        break;
//    }
//    case WM_COMMAND:
//    {
//        int wmId = LOWORD(wParam);
//        switch (wmId)
//        {
//        case 100:
//        {
//            memset(g_Text_String, 0, sizeof(g_Text_String));
//            GetWindowTextW(hEdit, g_Text_String, GetWindowTextLengthW(hEdit) + 1);
//
//            int key = (int)_wtoi(g_Text_String);
//            g_Tree.insertNode(key);
//
//            InvalidateRect(hWnd, NULL, FALSE);
//        }
//        break;
//        case 101:
//        {
//            memset(g_Text_String, 0, sizeof(g_Text_String));
//            GetWindowTextW(hEdit, g_Text_String, GetWindowTextLengthW(hEdit) + 1);
//
//            int key = (int)_wtoi(g_Text_String);
//            Node* nodeToDelete = g_Tree.search(key);
//
//            if (nodeToDelete != g_Tree.nil)
//            {
//                g_Tree.deleteNode(key);
//            }
//
//            InvalidateRect(hWnd, NULL, FALSE);
//        }
//        break;
//        case 102:  // 자동 삽입/삭제 시작
//            SetTimer(hWnd, IDT_TIMER1, 1000, NULL);
//            break;
//        case 103:  // 자동 삽입/삭제 중지
//            KillTimer(hWnd, IDT_TIMER1);
//            break;
//        case IDM_ABOUT:
//            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
//            break;
//        case IDM_EXIT:
//            DestroyWindow(hWnd);
//            break;
//        default:
//            return DefWindowProc(hWnd, message, wParam, lParam);
//        }
//    }
//    break;
//    case WM_TIMER:
//        if (wParam == IDT_TIMER1)
//        {
//            g_CurrentKey++;
//            g_Tree.insertNode(g_CurrentKey);
//
//            // 일정 키 값 이후 삭제도 수행
//            if (g_CurrentKey > 10)
//            {
//                g_Tree.deleteNode(g_CurrentKey - 10);
//            }
//
//            InvalidateRect(hWnd, NULL, FALSE); // 화면 갱신
//        }
//        break;
//    case WM_PAINT:
//    {
//        PAINTSTRUCT ps;
//        HDC hdc = BeginPaint(hWnd, &ps);
//        RECT ClientRect;
//        GetClientRect(hWnd, &ClientRect);
//
//        PatBlt(g_MemDc, 0, 0, g_MemDcRect.right, g_MemDcRect.bottom, WHITENESS);
//
//        g_Tree.Render(g_MemDc, hWnd, g_Tree.root, g_MemDcRect.left, g_MemDcRect.right, 1);
//
//        BitBlt(hdc, 0, 0, g_MemDcRect.right, g_MemDcRect.bottom, g_MemDc, 0, 0, SRCCOPY);
//
//        EndPaint(hWnd, &ps);
//    }
//    break;
//    case WM_DESTROY:
//    {
//        DeleteObject(g_Brush);
//        DeleteObject(g_GridPen);
//        PostQuitMessage(0);
//    }
//    break;
//    case WM_SIZE:
//    {
//        SelectObject(g_MemDc, g_MemDcBitmap_Old);
//        DeleteObject(g_MemDc);
//        DeleteObject(g_MemDcBitmap);
//
//        HDC hdc = GetDC(hWnd);
//
//        GetClientRect(hWnd, &g_MemDcRect);
//        g_MemDcBitmap = CreateCompatibleBitmap(hdc, g_MemDcRect.right, g_MemDcRect.bottom);
//        g_MemDc = CreateCompatibleDC(hdc);
//        ReleaseDC(hWnd, hdc);
//
//        g_MemDcBitmap_Old = (HBITMAP)SelectObject(g_MemDc, g_MemDcBitmap);
//    }
//    break;
//    default:
//        return DefWindowProc(hWnd, message, wParam, lParam);
//    }
//    return 0;
//}
//
//// 정보 대화 상자의 메시지 처리기입니다.
//INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
//{
//    UNREFERENCED_PARAMETER(lParam);
//    switch (message)
//    {
//    case WM_INITDIALOG:
//        return (INT_PTR)TRUE;
//    case WM_COMMAND:
//        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
//        {
//            EndDialog(hDlg, LOWORD(wParam));
//            return (INT_PTR)TRUE;
//        }
//        break;
//    }
//    return (INT_PTR)FALSE;
//}
//
//void RenderGrid(HDC hdc)
//{
//    int ix = 0;
//    int iy = 0;
//
//    HPEN OldPen = (HPEN)SelectObject(hdc, g_GridPen);
//
//    for (int w = 0; w <= GRID_WIDTH; w++)
//    {
//        MoveToEx(hdc, ix, 0, NULL);
//        LineTo(hdc, ix, GRID_HEIGHT * GRID_SIZE);
//        ix += GRID_SIZE;
//    }
//
//    for (int h = 0; h <= GRID_HEIGHT; h++)
//    {
//        MoveToEx(hdc, 0, iy, NULL);
//        LineTo(hdc, GRID_WIDTH * GRID_SIZE, iy);
//        iy += GRID_SIZE;
//    }
//
//    SelectObject(hdc, OldPen);
//}
//
//void RenderObstacle(HDC hdc)
//{
//    int iX = 0;
//    int iY = 0;
//
//    HBRUSH Old = (HBRUSH)SelectObject(hdc, g_Brush);
//    SelectObject(hdc, GetStockObject(NULL_PEN));
//
//    for (int w = 0; w < GRID_WIDTH; w++)
//    {
//        for (int h = 0; h < GRID_HEIGHT; h++)
//        {
//            if (g_Tile[h][w])
//            {
//                iX = w * GRID_SIZE;
//                iY = h * GRID_SIZE;
//
//                Rectangle(hdc, iX, iY, iX * GRID_SIZE + 2, iY * GRID_SIZE + 2);
//            }
//        }
//    }
//
//    SelectObject(hdc, Old);
//}

#include "framework.h"
#include "RedBlackTreeGraphic.h"
#include "RedBlackTreeClass.h"
#include <cstdlib> // for rand, srand
#include <ctime>   // for time

#define MAX_LOADSTRING 100
#define GRID_SIZE 16

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////
// 전역 변수:
HINSTANCE hInst;
WCHAR szTitle[MAX_LOADSTRING];
WCHAR szWindowClass[MAX_LOADSTRING];

int GRID_HEIGHT = 100;
int GRID_WIDTH = 110;

char g_Tile[100][110];
wchar_t g_Text_String[1024];

RedBlackTree g_Tree;

// 전역 윈도우:
HWND hButtonInsert;
HWND hButtonDelete;

// 함수 전방 선언
void RenderGrid(HDC hdc);
void RenderObstacle(HDC hdc);

// 전역 GDI Object / 변수
HPEN g_GridPen;
HBRUSH g_Brush;

float g_Scale = 1.0f;
const float g_ScaleStep = 0.1f;
const float g_MinScale = 0.1f;
const float g_MaxScale = 3.0f;

HBITMAP g_MemDcBitmap;
HBITMAP g_MemDcBitmap_Old;
HDC g_MemDc;
RECT g_MemDcRect;

/////////////////////////////////////////////////////////////////////////////////////////////////////////////////

// 이 코드 모듈에 포함된 함수의 선언을 전달합니다:
ATOM MyRegisterClass(HINSTANCE hInstance);
BOOL InitInstance(HINSTANCE, int);
LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK About(HWND, UINT, WPARAM, LPARAM);

int APIENTRY wWinMain(_In_ HINSTANCE hInstance,
    _In_opt_ HINSTANCE hPrevInstance,
    _In_ LPWSTR lpCmdLine,
    _In_ int nCmdShow)
{
    UNREFERENCED_PARAMETER(hPrevInstance);
    UNREFERENCED_PARAMETER(lpCmdLine);

    // 전역 문자열을 초기화합니다.
    LoadStringW(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
    LoadStringW(hInstance, IDC_REDBLACKTREEGRAPHIC, szWindowClass, MAX_LOADSTRING);
    MyRegisterClass(hInstance);

    if (!InitInstance(hInstance, nCmdShow))
    {
        return FALSE;
    }

    HACCEL hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_REDBLACKTREEGRAPHIC));

    MSG msg;

    // 기본 메시지 루프입니다:
    while (GetMessage(&msg, nullptr, 0, 0))
    {
        if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
        {
            TranslateMessage(&msg);
            DispatchMessage(&msg);
        }
    }

    return (int)msg.wParam;
}

ATOM MyRegisterClass(HINSTANCE hInstance)
{
    WNDCLASSEXW wcex;

    wcex.cbSize = sizeof(WNDCLASSEX);
    wcex.style = CS_HREDRAW | CS_VREDRAW;
    wcex.lpfnWndProc = WndProc;
    wcex.cbClsExtra = 0;
    wcex.cbWndExtra = 0;
    wcex.hInstance = hInstance;
    wcex.hIcon = LoadIcon(hInstance, MAKEINTRESOURCE(IDI_REDBLACKTREEGRAPHIC));
    wcex.hCursor = LoadCursor(nullptr, IDC_ARROW);
    wcex.hbrBackground = (HBRUSH)(COLOR_WINDOW + 1);
    wcex.lpszMenuName = MAKEINTRESOURCEW(IDC_REDBLACKTREEGRAPHIC);
    wcex.lpszClassName = szWindowClass;
    wcex.hIconSm = LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

    return RegisterClassExW(&wcex);
}

BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
    hInst = hInstance;

    HWND hWnd = CreateWindowW(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
        CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, nullptr, nullptr, hInstance, nullptr);

    if (!hWnd)
    {
        return FALSE;
    }

    ShowWindow(hWnd, nCmdShow);
    UpdateWindow(hWnd);

    return TRUE;
}

LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
    switch (message)
    {
    case WM_CREATE:
    {
        HDC hdc = GetDC(hWnd);
        GetClientRect(hWnd, &g_MemDcRect);
        g_MemDcBitmap = CreateCompatibleBitmap(hdc, g_MemDcRect.right, g_MemDcRect.bottom);
        g_MemDc = CreateCompatibleDC(hdc);
        ReleaseDC(hWnd, hdc);
        g_MemDcBitmap_Old = (HBITMAP)SelectObject(g_MemDc, g_MemDcBitmap);

        // 랜덤 값 생성을 위한 시드 설정
        srand(static_cast<unsigned int>(time(0)));

        // 노드 삽입 버튼
        hButtonInsert = CreateWindowW(
            L"button",
            L"Random Insert",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            20, 20, 150, 25,
            hWnd,
            (HMENU)100,
            hInst,
            NULL);

        // 노드 삭제 버튼
        hButtonDelete = CreateWindowW(
            L"button",
            L"Delete Head",
            WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
            20, 50, 150, 25,
            hWnd,
            (HMENU)101,
            hInst,
            NULL);

        g_GridPen = CreatePen(PS_SOLID, 1, RGB(200, 200, 200));
        g_Brush = CreateSolidBrush(RGB(100, 100, 100));
        break;
    }
    case WM_COMMAND:
    {
        int wmId = LOWORD(wParam);
        switch (wmId)
        {
        case 100:  // 랜덤 값 트리에 삽입
        {
            int randomValue = rand() % 100000 + 1;  // 1에서 100000 사이의 랜덤 값 생성
            g_Tree.insertNode(randomValue);         // 랜덤 값을 트리에 삽입

            InvalidateRect(hWnd, NULL, FALSE);      // 화면을 다시 그리도록 요청
        }
        break;
        case 101:  // 루트 노드 삭제
        {
            if (g_Tree.root != g_Tree.nil)  // 트리가 비어있지 않다면
            {
                g_Tree.deleteNode(g_Tree.root->_Key);  // 루트 노드를 삭제
            }

            InvalidateRect(hWnd, NULL, FALSE);         // 화면을 다시 그리도록 요청
        }
        break;
        case IDM_ABOUT:
            DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
            break;
        case IDM_EXIT:
            DestroyWindow(hWnd);
            break;
        default:
            return DefWindowProc(hWnd, message, wParam, lParam);
        }
    }
    break;
    case WM_PAINT:
    {
        PAINTSTRUCT ps;
        HDC hdc = BeginPaint(hWnd, &ps);
        RECT ClientRect;
        GetClientRect(hWnd, &ClientRect);

        PatBlt(g_MemDc, 0, 0, g_MemDcRect.right, g_MemDcRect.bottom, WHITENESS);

        // 트리 그리기
        g_Tree.Render(g_MemDc, hWnd, g_Tree.root, g_MemDcRect.left, g_MemDcRect.right, 1);

        BitBlt(hdc, 0, 0, g_MemDcRect.right, g_MemDcRect.bottom, g_MemDc, 0, 0, SRCCOPY);

        EndPaint(hWnd, &ps);
    }
    break;
    case WM_DESTROY:
    {
        DeleteObject(g_Brush);
        DeleteObject(g_GridPen);
        PostQuitMessage(0);
    }
    break;
    case WM_SIZE:
    {
        SelectObject(g_MemDc, g_MemDcBitmap_Old);
        DeleteObject(g_MemDc);
        DeleteObject(g_MemDcBitmap);

        HDC hdc = GetDC(hWnd);

        GetClientRect(hWnd, &g_MemDcRect);
        g_MemDcBitmap = CreateCompatibleBitmap(hdc, g_MemDcRect.right, g_MemDcRect.bottom);
        g_MemDc = CreateCompatibleDC(hdc);
        ReleaseDC(hWnd, hdc);

        g_MemDcBitmap_Old = (HBITMAP)SelectObject(g_MemDc, g_MemDcBitmap);
    }
    break;
    default:
        return DefWindowProc(hWnd, message, wParam, lParam);
    }
    return 0;
}

// 정보 대화 상자의 메시지 처리기입니다.
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
    UNREFERENCED_PARAMETER(lParam);
    switch (message)
    {
    case WM_INITDIALOG:
        return (INT_PTR)TRUE;
    case WM_COMMAND:
        if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
        {
            EndDialog(hDlg, LOWORD(wParam));
            return (INT_PTR)TRUE;
        }
        break;
    }
    return (INT_PTR)FALSE;
}

void RenderGrid(HDC hdc)
{
    int ix = 0;
    int iy = 0;

    HPEN OldPen = (HPEN)SelectObject(hdc, g_GridPen);

    for (int w = 0; w <= GRID_WIDTH; w++)
    {
        MoveToEx(hdc, ix, 0, NULL);
        LineTo(hdc, ix, GRID_HEIGHT * GRID_SIZE);
        ix += GRID_SIZE;
    }

    for (int h = 0; h <= GRID_HEIGHT; h++)
    {
        MoveToEx(hdc, 0, iy, NULL);
        LineTo(hdc, GRID_WIDTH * GRID_SIZE, iy);
        iy += GRID_SIZE;
    }

    SelectObject(hdc, OldPen);
}

void RenderObstacle(HDC hdc)
{
    int iX = 0;
    int iY = 0;

    HBRUSH Old = (HBRUSH)SelectObject(hdc, g_Brush);
    SelectObject(hdc, GetStockObject(NULL_PEN));

    for (int w = 0; w < GRID_WIDTH; w++)
    {
        for (int h = 0; h < GRID_HEIGHT; h++)
        {
            if (g_Tile[h][w])
            {
                iX = w * GRID_SIZE;
                iY = h * GRID_SIZE;

                Rectangle(hdc, iX, iY, iX * GRID_SIZE + 2, iY * GRID_SIZE + 2);
            }
        }
    }

    SelectObject(hdc, Old);
}
