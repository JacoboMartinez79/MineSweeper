#include "MineSweeper.h"

wxIMPLEMENT_APP(MineSweeper);

	MineSweeper::MineSweeper()
	{


	}
	MineSweeper::~MineSweeper() 
	{


	}
	bool MineSweeper::OnInit() 
	{
		m_form1 = new TheMainMineSweeper();
		m_form1->Show();
		return true;
	}


