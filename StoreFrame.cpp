//
// Created by dario on 28/04/2023.
//

#include "StoreFrame.h"
const long StoreFrame::IdButtonDelete =::wxNewId();
const long StoreFrame::IdButtonBack =::wxNewId();

BEGIN_EVENT_TABLE (StoreFrame, wxDialog)
                EVT_BUTTON(IdButtonDelete, StoreFrame::DeleteProduct)
                EVT_BUTTON(IdButtonBack, StoreFrame::ComeBack)

END_EVENT_TABLE()

StoreFrame::StoreFrame(const wxString &title, const std::string id_providers):
        wxDialog(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)) {


    /* wxStaticText *order = new wxStaticText(this, -1, wxT("Order By"));
     wxString myString[]={"Name Product", "Price", "Provider Name"};
     choiceOrder=new wxChoice(this, wxID_ANY,wxDefaultPosition, wxDefaultSize);
     choiceOrder->Append("Select");
     choiceOrder->Append(3,myString);
     choiceOrder->Bind(wxEVT_CHOICE, &ProdListFrame::OnChoice, this);*/


    TableStore store;
    int row = store.select_count(sub, disponibility);
    mat_store=new std::string *[row];
    for (int k = 0; k < row; k++) {
        mat_store[k] = new std::string[5];
    }
    grid = new wxGrid(this, wxID_ANY);
    grid->CreateGrid(row, 3);
    grid->SetColLabelValue(0, "Name product");
    grid->SetColLabelValue(1, "Quantity");
    grid->SetColLabelValue(2, "Price");

    mat_store=store.select(sub_name,disponibility);

    //selection=new wxRadioButton(grid, wxID_ANY, wxT(""));
    for (int i = 0; i < store.select_count(sub_name, disponibility); i++) {

        for (int col = 0; col < 3; col++) {
            grid->SetReadOnly(i, col, true);
            grid->SetCellValue(i, col,  mat_store[i][col]);
        }
    }
    grid->SetSelectionMode(wxGrid::wxGridSelectRows);
    grid->AutoSize();


    Delete=new wxButton (this,IdButtonDelete,_T ("Remove"),wxDefaultPosition,wxDefaultSize,0);
    Back=new wxButton (this,IdButtonBack,_T ("Back"),wxDefaultPosition,wxDefaultSize,0);

    sizer = new wxBoxSizer(wxVERTICAL);

    sizer->Add(store, 0, wxALL, 5);
    sizer->Add(choiceOrder, 0, wxALL, 5);
    sizer->Add(grid, 1, wxEXPAND | wxALL, 5);
    sizer->Add(Delete, 1, wxEXPAND | wxALL, 5);
    sizer->Add(Back, 1, wxEXPAND | wxALL, 5);
    SetSizer(sizer);

    Centre();


}
void StoreFrame::ComeBack(wxCommandEvent &event) {

    Close();

}

void StoreFrame::DeleteProduct(wxCommandEvent &event) {
    if (grid->GetSelectedRows() == 0) {
        wxMessageBox("Choose a product", "Error", wxICON_ERROR);
    } else
        TableStore obj;
        obj.remove(grid->GetSelectedRows());
}
