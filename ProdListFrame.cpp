//
// Created by Andrea Lipperi on 22/03/23.
//

#include "ProdListFrame.h"
#include "SelectSubFrame.h"

std::string sub;
std::string cat;
std::string name;
std::string cost;
std::string quant;


const long ProdListFrame::IdButtonConfirm =::wxNewId();
const long ProdListFrame::IdButtonComeBack =::wxNewId();

BEGIN_EVENT_TABLE (ProdListFrame, wxFrame)
                EVT_BUTTON(IdButtonConfirm, ProdListFrame::IsConfirm)
                EVT_BUTTON(IdButtonComeBack, ProdListFrame::ComeBack)
END_EVENT_TABLE()

ProdListFrame::ProdListFrame(const wxString &title):
        wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)) {

    SelectSubFrame* select_sub_name = (SelectSubFrame*)wxTheApp->GetTopWindow();
    string sub=select_sub_name->sub_name;
    wxPanel *panel = new wxPanel(this, -1);

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);

    wxFlexGridSizer *fgs = new wxFlexGridSizer(8, 2, 12, -5);

    wxGrid *grid = new wxGrid(this, wxID_ANY);

    TableStore store;
    int row = store.select_count(sub);
    string** mat_store=new string *[row];
    for (int k = 0; k < row; k++) {
        mat_store[k] = new string[4];
    }
    mat_store=store.select(sub);
    grid->CreateGrid(row, 4);
    grid->SetColLabelValue(0, "Prodotto");
    grid->SetColLabelValue(1, "Prezzo");
    grid->SetColLabelValue(2, "Fornitore");
    grid->SetColLabelValue(3, "Disponibilità");

    for (int i = 0; i < row; i++) {
        for (int col = 0; col < 4; col++) {
            grid->SetCellValue(i, col,  mat_store[i][col]);
        }
        wxGridCellBoolRenderer *renderer = new wxGridCellBoolRenderer();
        grid->SetCellRenderer(i, 4, renderer);
        grid->SetCellEditor(i, 4, new wxGridCellBoolEditor());
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

void ProdListFrame::IsConfirm(wxCommandEvent &event) {

}

void ProdListFrame::ComeBack(wxCommandEvent &event) {
    Close();
}

void ProdListFrame::SetGrid(wxCommandEvent &event) {

}
