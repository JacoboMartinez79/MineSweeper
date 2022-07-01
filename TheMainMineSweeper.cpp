#include "TheMainMineSweeper.h"

wxBEGIN_EVENT_TABLE(TheMainMineSweeper, wxFrame)
     EVT_BUTTON(10001, OnButtonClicked)
wxEND_EVENT_TABLE()

TheMainMineSweeper::TheMainMineSweeper() : wxFrame(nullptr, wxID_ANY, "MineSweeper", wxPoint(400, 200), wxSize(500, 500))
{
	btn = new wxButton* [nFieldWidth * nFieldHeight];
	wxGridSizer* grid = new wxGridSizer(nFieldWidth, nFieldHeight, 0, 0);

	nField = new int[nFieldWidth * nFieldHeight];

	wxFont font(24, wxFONTFAMILY_DEFAULT, wxFONTSTYLE_NORMAL, wxFONTWEIGHT_BOLD, false);

	for (int x = 0;  x < nFieldWidth;  x++)
	{
		for (int y = 0; y < nFieldHeight; y++)
		{
			btn[y * nFieldWidth + x] = new wxButton(this, 10000 + (y * nFieldWidth + x));
			btn[y * nFieldWidth + x]->SetFont(font);
			grid->Add(btn[y * nFieldWidth + x], 1, wxEXPAND | wxALL);

			btn[y * nFieldWidth + x]->Bind(wxEVT_COMMAND_BUTTON_CLICKED, &TheMainMineSweeper::OnButtonClicked, this);
			nField[y * nFieldWidth + x] = 0;
		} 
	}
	this->SetSizer(grid);
	grid->Layout();

}

TheMainMineSweeper::~TheMainMineSweeper()
{
	delete[]btn;

}

void TheMainMineSweeper::OnButtonClicked(wxCommandEvent &evt)
{
	//get cordinates
	int x = (evt.GetId() - 10000) % nFieldWidth;
	int y = (evt.GetId() - 10000) / nFieldWidth;
	/// <summary>
	if (mFirstClick)
	{
		//decreasing mines
		int mines = 30;
		while (mines) {
			int rx = rand() % nFieldWidth;
			int ry = rand() % nFieldHeight;
			if (nField[ry * nFieldWidth + rx] == 0 && rx != x && ry != y) 
			{

				nField[ry * nFieldWidth + rx] = -1;
				mines--;
			}
		}
		mFirstClick = false;
	}
	//disabling the button.
	btn[y * nFieldWidth + x]->Enable(false);
	if (nField[y * nFieldWidth + x] == -1)
	{
		wxMessageBox("BOOM !! - GAME OVER :(");
		//reset game 
		for (int x = 0; x < nFieldWidth; x++)
		{
			for (int y = 0; y < nFieldHeight; y++)
			{
				nField[y * nFieldWidth + x] = 0;
				btn[y * nFieldWidth + x]->SetLabel("");
				btn[y * nFieldWidth + x]->Enable(true);
			}
		}
	}
	else 
	{
		//counting the mines now
		int mineCounter = 0;
		for (int i = 0; i < 2; i++)
		{
			for (int j = -1; j < 2; j++)
			{
				if (x + i >= 0 && x + i < nFieldWidth && y + j >= 0 && y + j < nFieldHeight)
				{
					if (nField[(y + j) * nFieldWidth + (x + i)] == -1)
					{
						mineCounter++;
					}

				}
			}
		}
		if (mineCounter > 0) 
		{
			btn[y * nFieldWidth + x]->SetLabel(std::to_string(mineCounter));
		}
	}
	evt.Skip();
}