//
// Created by Matilde Tarchi on 30/03/23.
//

#include "favouritesFrame.h"
std::string sub;
std::string cat;
std::string name;
std::string cost;


const long favouritesFrame::IdButtonRemove =::wxNewId();
const long favouritesFrame::IdButtonOrder =::wxNewId();
const long favouritesFrame::IdButtonComeBack =::wxNewId();

BEGIN_EVENT_TABLE (favouritesFrame, wxFrame)
                EVT_BUTTON(IdButtonRemove, favouritesFrame::ComeBack)
                EVT_BUTTON(IdButtonOrder, favouritesFrame::ComeBack)
                EVT_BUTTON(IdButtonComeBack, favouritesFrame::ComeBack)
END_EVENT_TABLE()

favouritesFrame::favouritesFrame(const wxString &title):
        wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)) {


    wxPanel *panel = new wxPanel(this, -1);

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *hbox2 = new wxBoxSizer(wxHORIZONTAL);

    wxFlexGridSizer *fgs = new wxFlexGridSizer(8, 2, 12, -5);

    wxGrid *grid = new wxGrid(this, wxID_ANY);
    grid->CreateGrid(5, 4);
    grid->SetColLabelValue(0, "Sottocategoria");
    grid->SetColLabelValue(1, "Categoria");
    grid->SetColLabelValue(2, "Nome");
    grid->SetColLabelValue(3, "Costo");

    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 4; col++) {
            grid->SetCellValue(row, col, wxString::Format("(%d, %d)", row, col));
            //METTERE VALORI DA DATABASE

        }
        wxGridCellBoolRenderer *renderer = new wxGridCellBoolRenderer();
        grid->SetCellRenderer(row, 5, renderer);
        grid->SetCellEditor(row, 5, new wxGridCellBoolEditor());
    }
    grid->AutoSize();

    Remove=new wxButton(panel,IdButtonRemove,_T ("Rimuovi"),wxDefaultPosition,wxDefaultSize,0);
    Order=new wxButton(panel,IdButtonOrder,_T ("Ordina"),wxDefaultPosition,wxDefaultSize,0);
    Back=new wxButton(panel,IdButtonComeBack,_T ("Back"),wxDefaultPosition,wxDefaultSize,0);



    fgs->Add(Remove,0);
    fgs->Add(Order,0);
    fgs->Add(Back,0);

    fgs->AddGrowableRow(1, 1);
    fgs->AddGrowableCol(1, 1);
    hbox2->Add(fgs, 1, wxDOWN, 10);

    panel->SetSizer(hbox);


    Centre();


}

void favouritesFrame::IsRemove(wxCommandEvent &event) {

}

void favouritesFrame::IsOrder(wxCommandEvent &event) {

}

void favouritesFrame::ComeBack(wxCommandEvent &event) {
    Close();
}

