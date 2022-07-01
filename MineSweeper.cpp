#include "MineSweeper.h"

wxIMPLEMENT_APP(MineSweeper);
//frame
	MineSweeper::MineSweeper()
	{


	}
	MineSweeper::~MineSweeper() 
	{


	}
//this shows the window
	bool MineSweeper::OnInit() 
	{
		m_form1 = new TheMainMineSweeper();
		m_form1->Show();
		return true;
	}


