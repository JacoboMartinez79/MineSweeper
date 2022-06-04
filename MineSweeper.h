#pragma once
#include <wx/wx.h>
#include "TheMainMineSweeper.h"

class MineSweeper : public wxApp
{
	public:
		MineSweeper();
		~MineSweeper();
	private:
		TheMainMineSweeper* m_form1 = nullptr;

	public:
		virtual bool OnInit();
	};
