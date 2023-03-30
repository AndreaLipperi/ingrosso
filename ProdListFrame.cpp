//
// Created by Andrea Lipperi on 22/03/23.
//

#include "ProdListFrame.h"
#include "SelectSubFrame.h"
#include <wx/grid.h>
#include <wx/app.h>
#include <wx/radiobut.h>

const long ProdListFrame::IdButtonSelection =::wxNewId();
const long ProdListFrame::IdButtonConfirm =::wxNewId();
const long ProdListFrame::IdButtonComeBack =::wxNewId();

BEGIN_EVENT_TABLE (ProdListFrame, wxFrame)
                EVT_BUTTON(IdButtonConfirm, ProdListFrame::IsConfirm)
                EVT_RADIOBUTTON(IdButtonSelection, ProdListFrame::selection_data)
                EVT_BUTTON(IdButtonComeBack, ProdListFrame::ComeBack)
END_EVENT_TABLE()

ProdListFrame::ProdListFrame(const wxString &title, const std::string &sub, const std::string &disp):
        wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)) {
    sub_name=sub;
    disponibility=disp;


    wxStaticText *order = new wxStaticText(this, -1, wxT("Order"));
    wxString myString[]={"prodotto", "prezzo", "fornitore"};
    choiceOrder=new wxChoice(this, wxID_ANY,wxDefaultPosition, wxDefaultSize);
    choiceOrder->Append("Seleziona");
    choiceOrder->Append(3,myString);
    choiceOrder->Bind(wxEVT_CHOICE, &ProdListFrame::OnChoice, this);


    TableStore store;
    int row = store.select_count(sub, disponibility);
    mat_store=new string *[row];
    for (int k = 0; k < row; k++) {
        mat_store[k] = new string[5];
    }
    grid = new wxGrid(this, wxID_ANY);
    grid->CreateGrid(row, 4);
    grid->SetColLabelValue(0, "Prodotto");
    grid->SetColLabelValue(1, "Prezzo");
    grid->SetColLabelValue(2, "Fornitore");
    grid->SetColLabelValue(3, "Disponibilità");
    mat_store=store.select(sub_name,disponibility);

    //selection=new wxRadioButton(grid, wxID_ANY, wxT(""));
    for (int i = 0; i < store.select_count(sub_name, disponibility); i++) {

        for (int col = 0; col < 4; col++) {
                grid->SetReadOnly(i, col, true);
                grid->SetCellValue(i, col,  mat_store[i][col]);
        }
    }
    grid->SetSelectionMode(wxGrid::wxGridSelectRows);
    grid->AutoSize();


    Confirm=new wxButton (this,IdButtonConfirm,_T ("Ok"),wxDefaultPosition,wxDefaultSize,0);
    /*Back=new wxButton(panel,IdButtonComeBack,_T ("Back"),wxDefaultPosition,wxDefaultSize,0);


    hbox2->AddStretchSpacer(1); // Aggiunge uno spazio vuoto espandibile
    hbox2->Add(Confirm, 0, wxRIGHT, 10);
    hbox2->Add(Back, 0);
    hbox->Add(grid, 1, wxEXPAND | wxALL, 20);
    hbox->Add(hbox2, 0, wxALIGN_RIGHT | wxALL, 20);
    panel->SetSizer(hbox);
    fgs->Add(order,0);
    fgs->Add(choiceOrder,1, wxEXPAND);



    fgs->AddGrowableRow(1, 1);
    fgs->AddGrowableCol(1, 1);



    hbox2->Add(fgs, 1, wxALL, 10);
    panel->SetSizer(hbox2);*/
    wxBoxSizer* sizer = new wxBoxSizer(wxVERTICAL);

    sizer->Add(order, 0, wxALL, 5);
    sizer->Add(choiceOrder, 0, wxALL, 5);
    sizer->Add(grid, 1, wxEXPAND | wxALL, 5);
    sizer->Add(Confirm, 1, wxEXPAND | wxALL, 5);
    SetSizer(sizer);

    //this->SetSizer(MainBox);

    Centre();


}

void ProdListFrame::OnChoice(wxCommandEvent& event) {
    TableStore store;
    string order=event.GetString().ToStdString();
    mat_store=store.select(sub_name, disponibility,order);
    for (int i = 0; i < store.select_count(sub_name, disponibility); i++) {
        for (int col = 0; col < 4; col++) {
            grid->SetReadOnly(i, col, true);
            grid->SetCellValue(i, col,  mat_store[i][col]);
        }

    }
    grid->SetSelectionMode(wxGrid::wxGridSelectRows);
    grid->AutoSize();
}
void ProdListFrame::IsConfirm(wxCommandEvent &event) {
    wxArrayInt selectedRows = grid->GetSelectedRows();
    int row;
    for (size_t i = 0; i < selectedRows.GetCount(); i++) {
        row = selectedRows[i];
        cout << mat_store[row][2] << mat_store[row][4];
    }
}

void ProdListFrame::ComeBack(wxCommandEvent &event) {
    Close();
}

void ProdListFrame::selection_data(wxCommandEvent &event) {

}
