//
// Created by Matilde Tarchi on 20/03/23.
//
#include "prodListFrame.h"

std::string sub;
std::string cat;
std::string name;
std::string cost;
std::string quant;


const long prodListFrame::IdButtonConfirm =::wxNewId();
const long prodListFrame::IdButtonComeBack =::wxNewId();

BEGIN_EVENT_TABLE (prodListFrame, wxFrame)
                EVT_BUTTON(IdButtonConfirm, prodListFrame::IsConfirm)
                EVT_BUTTON(IdButtonComeBack, prodListFrame::ComeBack)
END_EVENT_TABLE()

prodListFrame::prodListFrame(const wxString &title):
        wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)) {


    wxPanel *panel = new wxPanel(this, -1);

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);

    wxFlexGridSizer *fgs = new wxFlexGridSizer(8, 2, 12, -5);

    wxGrid *grid = new wxGrid(this, wxID_ANY);
    grid->CreateGrid(5, 6);
    grid->SetColLabelValue(0, "Sottocategoria");
    grid->SetColLabelValue(1, "Categoria");
    grid->SetColLabelValue(2, "Nome");
    grid->SetColLabelValue(3, "Costo");
    grid->SetColLabelValue(4, "Disponibilità");
    grid->SetColLabelValue(5, "Favorito");

    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 4; col++) {
            grid->SetCellValue(row, col, wxString::Format("(%d, %d)", row, col));
        }
        wxGridCellBoolRenderer *renderer = new wxGridCellBoolRenderer();
        grid->SetCellRenderer(row, 5, renderer);
        grid->SetCellEditor(row, 5, new wxGridCellBoolEditor());
    }
    grid->AutoSize();

    Confirm=new wxButton (panel,IdButtonConfirm,_T ("Ok"),wxDefaultPosition,wxDefaultSize,0);
    Back=new wxButton(panel,IdButtonComeBack,_T ("Back"),wxDefaultPosition,wxDefaultSize,0);

    /*hbox2->Add(fgs, 1, wxDOWN, 10);
    hbox2->AddStretchSpacer(1); // Aggiunge uno spazio vuoto espandibile
    hbox2->Add(Confirm, 0, wxRIGHT, 10);
    hbox2->Add(Back, 0);

    hbox->Add(grid, 1, wxEXPAND | wxALL, 20);
    hbox->Add(hbox2, 0, wxALIGN_RIGHT | wxALL, 20);

    panel->SetSizer(hbox);*/
    fgs->Add(Confirm,0);
    fgs->Add(Back,0);


    fgs->AddGrowableRow(1, 1);
    fgs->AddGrowableCol(1, 1);


    hbox2->Add(fgs, 1, wxDOWN, 10);

    panel->SetSizer(hbox);

    //this->SetSizer(MainBox);

    Centre();


}


void prodListFrame::IsConfirm(wxCommandEvent &event) {

}

void prodListFrame::ComeBack(wxCommandEvent &event) {
    Close();
}

