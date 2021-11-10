#include "Deque.h"
#include "MVc.h"

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>

#include <ios>
#include <string>
#include <sstream>

#include "MyWindow.h"

#define UPDATE_LISTS WM_USER + 1

HINSTANCE instance_handle;

Deque deque1;
Deque deque2;

Model* model1 = new Model(deque1);
Model* model2 = new Model(deque2);


LRESULT CALLBACK WndProc(HWND hWnd, UINT msg, WPARAM wParam, LPARAM lParam)
{
	View* view1 = new View(hWnd, model1, 105);
	View* view2 = new View(hWnd, model2, 106);

	Controller firstController(model1, view1);
	Controller secondController(model2, view2);

	static HWND firstTextField;
	static HWND firstPushFrontButton;
	static HWND firstPushBackButton;
	static HWND firstPopBackButton;
	static HWND firstPopFrontButton;
	static HWND firstClearButton;
	static HWND firstMergeButton;

	static HWND secondTextField;
	static HWND secondPushBackButton;
	static HWND secondPushFrontButton;
	static HWND secondPopBackButton;
	static HWND secondPopFrontButton;
	static HWND secondClearButton;
	static HWND secondMergeButton;

	static HWND swapButton;

	static HWND edit_to_push;

	static HWND averageText;
	static HWND firstAverageButton;
	static HWND secondAverageButton;

	char edit_value[256];
	std::stringstream ss;

	switch (msg)
	{
	case WM_CREATE:
		firstTextField = CreateWindowEx(WS_EX_CLIENTEDGE, "listbox", "", WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_AUTOVSCROLL, 20, 20, 190, 100, hWnd, (HMENU)105, NULL, nullptr);
		firstPushFrontButton = CreateWindow("button", "PushFront", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 20, 130, 90, 30, hWnd, nullptr, instance_handle, nullptr);
		firstPushBackButton = CreateWindow("button", "PushBack", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 120, 130, 90, 30, hWnd, nullptr, instance_handle, nullptr);
		firstPopFrontButton = CreateWindow("button", "PopFront", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 20, 170, 90, 30, hWnd, nullptr, instance_handle, nullptr);
		firstPopBackButton = CreateWindow("button", "PopBack", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 120, 170, 90, 30, hWnd, nullptr, instance_handle, nullptr);
		firstClearButton = CreateWindow("button", "Clear", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 20, 210, 190, 30, hWnd, nullptr, instance_handle, nullptr);
		firstMergeButton = CreateWindow("button", "<--", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 230, 40, 40, 40, hWnd, nullptr, instance_handle, nullptr);
		firstAverageButton = CreateWindow("button", "Average", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 20, 250, 190, 30, hWnd, nullptr, instance_handle, nullptr);

		secondTextField = CreateWindowEx(WS_EX_CLIENTEDGE, "listbox", "", WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_AUTOVSCROLL, 390, 20, 190, 100, hWnd, (HMENU)106, NULL, nullptr);
		secondPushFrontButton = CreateWindow("button", "PushFront", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 390, 130, 90, 30, hWnd, nullptr, instance_handle, nullptr);
		secondPushBackButton = CreateWindow("button", "PushBack", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 490, 130, 90, 30, hWnd, nullptr, instance_handle, nullptr);
		secondPopFrontButton = CreateWindow("button", "PopFront", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 390, 170, 90, 30, hWnd, nullptr, instance_handle, nullptr);
		secondPopBackButton = CreateWindow("button", "PopBack", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 490, 170, 90, 30, hWnd, nullptr, instance_handle, nullptr);
		secondClearButton = CreateWindow("button", "Clear", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 390, 210, 190, 30, hWnd, nullptr, instance_handle, nullptr);
		secondMergeButton = CreateWindow("button", "-->", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 330, 40, 40, 40, hWnd, nullptr, instance_handle, nullptr);
		secondAverageButton = CreateWindow("button", "Average", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 390, 250, 190, 30, hWnd, nullptr, instance_handle, nullptr);

		swapButton = CreateWindow("button", "-->\n<--", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_LEFT, 280, 40, 40, 40, hWnd, nullptr, instance_handle, nullptr);

		edit_to_push = CreateWindow("edit", "0", WS_CHILD | WS_VISIBLE | WS_BORDER | ES_RIGHT, 230, 130, 140, 50, hWnd, 0, instance_handle, nullptr);

		averageText = CreateWindowEx(WS_EX_CLIENTEDGE, "listbox", "", WS_CHILD | WS_VISIBLE | WS_VSCROLL | ES_AUTOVSCROLL, 250, 250, 100, 40, hWnd, (HMENU)107, NULL, nullptr);
		return 0;

	case WM_COMMAND:
		if (reinterpret_cast<HWND>(lParam) == firstPushFrontButton)
		{
			GetWindowText(edit_to_push, edit_value, 20);
			int a = atoi(edit_value);
			firstController.pushFront(a);
		}
		else if (reinterpret_cast<HWND>(lParam) == firstPushBackButton)
		{
			GetWindowText(edit_to_push, edit_value, 20);
			int a = atoi(edit_value);
			firstController.pushBack(a);
		}
		else if (reinterpret_cast<HWND>(lParam) == firstPopBackButton)
		{
			firstController.popBack();
		}
		else if (reinterpret_cast<HWND>(lParam) == firstPopFrontButton)
		{
			firstController.popFront();
		}
		else if (reinterpret_cast<HWND>(lParam) == firstClearButton)
		{
			firstController.clear();
		}
		else if (reinterpret_cast<HWND>(lParam) == firstMergeButton)
		{
			firstController += secondController;
		}
		else if (reinterpret_cast<HWND>(lParam) == firstAverageButton)
		{
			DequeVisitor visitor;
			firstController.accept(visitor);
			std::string text = std::to_string(visitor.getAverage());
			SendDlgItemMessage(hWnd, 107, LB_RESETCONTENT, NULL, NULL);
			SendDlgItemMessage(hWnd, 107, LB_INSERTSTRING, -1, (LPARAM)text.data());
		}
		else if (reinterpret_cast<HWND>(lParam) == secondPushBackButton)
		{
			GetWindowText(edit_to_push, edit_value, 20);
			int a = atoi(edit_value);
			secondController.pushBack(a);
		}
		else if (reinterpret_cast<HWND>(lParam) == secondPushFrontButton)
		{
			GetWindowText(edit_to_push, edit_value, 20);
			int a = atoi(edit_value);
			secondController.pushFront(a);
		}
		else if (reinterpret_cast<HWND>(lParam) == secondPopBackButton)
		{
			secondController.popBack();
		}
		else if (reinterpret_cast<HWND>(lParam) == secondPopFrontButton)
		{
			secondController.popFront();
		}
		else if (reinterpret_cast<HWND>(lParam) == secondClearButton)
		{
			secondController.clear();
		}
		else if (reinterpret_cast<HWND>(lParam) == secondMergeButton)
		{
			secondController += firstController;
		}
		else if (reinterpret_cast<HWND>(lParam) == secondAverageButton)
		{
			DequeVisitor visitor;
			secondController.accept(visitor);

			std::string text = std::to_string(visitor.getAverage());
			SendDlgItemMessage(hWnd, 107, LB_RESETCONTENT, NULL, NULL);
			SendDlgItemMessage(hWnd, 107, LB_INSERTSTRING, -1, (LPARAM)text.data());
		}
		else if (reinterpret_cast<HWND>(lParam) == swapButton)
		{
			secondController.swap(firstController);
		}
		else
		{
			return DefWindowProc(hWnd, msg, wParam, lParam);
		}
		firstController.updateView();
		secondController.updateView();
		return 0;

	case UPDATE_LISTS:
		/*SendDlgItemMessage(hWnd, 105, LB_RESETCONTENT, NULL, NULL);
		SendDlgItemMessage(hWnd, 106, LB_RESETCONTENT, NULL, NULL);
		if (first.size() > 0) {
			for (iterator_first->first(); !iterator_first->isDone(); iterator_first->next())
			{
				std::string str_elem = std::to_string(iterator_first->element());
				SendDlgItemMessage(hWnd, 105, LB_INSERTSTRING, -1, (LPARAM)str_elem.data());
			}
		}
		if (second.size() > 0) {
			for (iterator_second->first(); !iterator_second->isDone(); iterator_second->next())
			{
				std::string str_elem = std::to_string(iterator_second->element());
				SendDlgItemMessage(hWnd, 106, LB_INSERTSTRING, -1, (LPARAM)str_elem.data());
			}
		}
		return 0;*/
		view1->Update();
		view2->Update();
		return 0;

	case WM_DESTROY:
		PostQuitMessage(0);
		return 0;

	default:
		return DefWindowProc(hWnd, msg, wParam, lParam);
	}
	delete view1;
	delete view2;
}

int WINAPI WinMain(HINSTANCE hInst, HINSTANCE, LPSTR, int cmdShow)
{
	instance_handle = hInst;
	MyWindow mywin("Deque", hInst, cmdShow, WndProc, NULL, 300, 0, 610, 350);
	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);
	}
	return (msg.wParam);
}