//
// Created by Andrea Lipperi on 02/05/23.
//


#include "StoreFrame.h"
#include "UsernameGlobal.h"
#include "ModifyProductFrame.h"
#define colonne 4
const long StoreFrame::IdButtonDelete =::wxNewId();
const long StoreFrame::IdButtonBack =::wxNewId();
const long StoreFrame::IdButtonModify =::wxNewId();

BEGIN_EVENT_TABLE (StoreFrame, wxDialog)
                EVT_BUTTON(IdButtonDelete, StoreFrame::DeleteProduct)
                EVT_BUTTON(IdButtonModify, StoreFrame::ModifyProduct)
                EVT_BUTTON(IdButtonBack, StoreFrame::ComeBack)

END_EVENT_TABLE()

StoreFrame::StoreFrame(const wxString &title):
        wxDialog(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)) {

    username=UsernameGlobal::GetInstance().GetValueUsername();

    wxStaticText *order = new wxStaticText(this, -1, wxT("Order By"));
    wxString myString[]={"Name Product", "Price", "Quantity Available"};
    choiceOrder=new wxChoice(this, wxID_ANY,wxDefaultPosition, wxDefaultSize);
    choiceOrder->Append("Select");
    choiceOrder->Append(3,myString);
    choiceOrder->Bind(wxEVT_CHOICE, &StoreFrame::OnChoice, this);

    TableStore store;
    int row = store.select_count_for_prov(username);
    mat_store=new std::string *[row];
    for (int k = 0; k < row; k++) {
        mat_store[k] = new std::string[colonne];
    }
    grid = new wxGrid(this, wxID_ANY);
    grid->CreateGrid(row, 3);
    grid->SetColLabelValue(0, "Name Product");
    grid->SetColLabelValue(1, "Price");
    grid->SetColLabelValue(2, "Quantity Available");

    mat_store=store.select_for_prov(username);

    for (int i = 0; i < store.select_count_for_prov(username); i++) {
        for (int col = 0; col < 3; col++) {
            grid->SetReadOnly(i, col, true);
            grid->SetCellValue(i, col,  mat_store[i][col]);
        }
    }
    grid->SetSelectionMode(wxGrid::wxGridSelectRows);
    grid->AutoSize();


    Delete=new wxButton (this,IdButtonDelete,_T ("Remove"),wxDefaultPosition,wxDefaultSize,0);
    Modify=new wxButton (this,IdButtonModify,_T ("Modify"),wxDefaultPosition,wxDefaultSize,0);
    Back=new wxButton (this,IdButtonBack,_T ("Back"),wxDefaultPosition,wxDefaultSize,0);

    sizer = new wxBoxSizer(wxVERTICAL);

    sizer->Add(order);
    sizer->Add(choiceOrder, 0, wxALL, 5);
    sizer->Add(grid, 1, wxEXPAND | wxALL, 5);
    sizer->Add(Delete, 1, wxEXPAND | wxALL, 5);
    sizer->Add(Modify, 1, wxEXPAND | wxALL, 5);
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
    } else {
        TableStore obj;
        wxArrayInt selectedRows = grid->GetSelectedRows();
        int row;
        for (size_t i = 0; i < selectedRows.GetCount(); i++) {
            row = selectedRows[i];
        }
        if (obj.remove(stoi(mat_store[row][3]))==0) {
            wxMessageBox("You can't remove this product from your store because is in someone's cart or favourites list or not accepted/denied order", "Error", wxICON_ERROR);
        } else {
            grid->DeleteRows(row);
        }
    }
}
void StoreFrame::ModifyProduct(wxCommandEvent &event) {
    if (grid->GetSelectedRows() == 0) {
        wxMessageBox("Choose a product", "Error", wxICON_ERROR);
    } else {
        TableStore obj;
        wxArrayInt selectedRows = grid->GetSelectedRows();
        int row;
        for (size_t i = 0; i < selectedRows.GetCount(); i++) {
            row = selectedRows[i];
        }
        ModifyProductFrame *mod = new ModifyProductFrame(_T("MODIFY PRODUCT"), stoi(mat_store[row][3]));
        mod->Show(TRUE);
    }
}

void StoreFrame::OnChoice(wxCommandEvent& event) {
    TableStore store;

    string order=event.GetString().ToStdString();

    mat_store=store.select_for_prov(username, order);

    for (int i = 0; i < store.select_count_for_prov(username); i++) {
        for (int col = 0; col < 3; col++) {
            grid->SetReadOnly(i, col, true);
            grid->SetCellValue(i, col,  mat_store[i][col]);
        }
    }
    grid->SetSelectionMode(wxGrid::wxGridSelectRows);
    grid->AutoSize();
}