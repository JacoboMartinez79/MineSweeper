#pragma once
#include <wx/wx.h>

class TheMainMineSweeper : public wxFrame
{
public:
	TheMainMineSweeper();
	~TheMainMineSweeper();

public:
	int nFieldWidth = 10;
	int nFieldHeight = 10;
	wxButton** btn;
	int* nField = nullptr;
	bool mFirstClick = true;

void OnButtonClicked(wxCommandEvent& evt);

   wxDECLARE_EVENT_TABLE();
};

