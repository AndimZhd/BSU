#pragma once
#include "Deque.h"
#include "MyWindow.h"
#include <string>

#include <windows.h>
#include <windowsx.h>
#include <commctrl.h>

#define UPDATE_LISTS WM_USER + 1



class Model : public Deque {
public:
	Model(const Deque& deque): Deque(deque){}
};

class View {
private:
	HWND hwnd;
	Model* model;
	int id_;
public:
	View(HWND wnd, Model* mdl, int id) : hwnd(wnd), model(mdl), id_(id) {}
	void Update() {
		SendDlgItemMessage(hwnd, id_, LB_RESETCONTENT, NULL, NULL);
		if (model->size() > 0) {
			auto it = model->createIterator();
			for (it->first(); !it->isDone(); it->next())
			{
				std::string str_elem = std::to_string(it->element());
				SendDlgItemMessage(hwnd, id_, LB_INSERTSTRING, -1, (LPARAM)str_elem.data());
			}
		}
	}

	HWND getHWND() {
		return hwnd;
	}
};

class Controller {
	Model* model;
	View* view;
public:
	Controller(Model* mdl, View* v) : model(mdl), view(v) {}

	void updateView() {
		SendMessage(view->getHWND(), UPDATE_LISTS, NULL, NULL);
	}

	void pushBack(int el) {
		model->pushBack(el);
	}

	void pushFront(int el) {
		model->pushFront(el);
	}

	void popBack() {
		model->popBack();
	}

	void popFront() {
		model->popFront();
	}

	void clear() {
		model->clear();
	}
	
	friend Controller& operator +=(Controller& self, const Controller& controller) {
		*self.model += *controller.model;
		return self;
	}

	void accept(Visitor& visitor) {
		model->accept(visitor);
	}

	 void swap(Controller& c1) {
		 model->swap(*c1.model);
	}
};
