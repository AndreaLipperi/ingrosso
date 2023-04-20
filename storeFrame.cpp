//
// Created by Matilde Tarchi on 20/04/23.
//

#include "storeFrame.h"
#include "SelectSubFrame.h"
#include "storeMethods.h"
#include "UsernameGlobal.h"
#include <wx/grid.h>
#include <wx/app.h>
#include <wx/spinctrl.h>

const long storeFrame::IdButtonRemove =::wxNewId();
const long storeFrame::IdButtonBack =::wxNewId();

BEGIN_EVENT_TABLE (storeFrame, wxFrame)
                EVT_BUTTON(IdButtonRemove, storeFrame::IsRemove)
                EVT_BUTTON(IdButtonBack, storeFrame::IsComeBack)
END_EVENT_TABLE()

storeFrame::storeFrame(const wxString &title, const std::string &sub, const std::string &disp):
        wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)) {
    sub_name=sub;
    disponibility=disp;

    wxStaticText *order = new wxStaticText(this, -1, wxT("Order By"));
    wxString myString[]={"Name Product", "Price", "Provider Name"};
    choiceOrder=new wxChoice(this, wxID_ANY,wxDefaultPosition, wxDefaultSize);
    choiceOrder->Append("Select");
    choiceOrder->Append(3,myString);
    choiceOrder->Bind(wxEVT_CHOICE, &storeFrame::OnChoice, this);


    TableStore store;
    int row = store.select_count(sub, disponibility);
    mat_store=new string *[row];
    for (int k = 0; k < row; k++) {
        mat_store[k] = new string[5];
    }
    grid = new wxGrid(this, wxID_ANY);
    grid->CreateGrid(row, 4);
    grid->SetColLabelValue(0, "Name Product");
    grid->SetColLabelValue(1, "Price");
    grid->SetColLabelValue(2, "Provider Name");
    grid->SetColLabelValue(3, "Disponibility");
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


    RemoveButton=new wxButton (this,IdButtonRemove,_T ("Remove "),wxDefaultPosition,wxDefaultSize,0);
    BackButton=new wxButton (this,IdButtonBack,_T ("Back"),wxDefaultPosition,wxDefaultSize,0);

    sizer = new wxBoxSizer(wxVERTICAL);

    sizer->Add(order, 0, wxALL, 5);
    sizer->Add(choiceOrder, 0, wxALL, 5);
    sizer->Add(grid, 1, wxEXPAND | wxALL, 5);
    sizer->Add(RemoveButton, 1, wxEXPAND | wxALL, 5);
    sizer->Add(BackButton, 1, wxEXPAND | wxALL, 5);
    SetSizer(sizer);

    Centre();


}
void storeFrame::OnChoice(wxCommandEvent& event) {
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
void storeFrame::IsComeBack(wxCommandEvent &event) {
    Close();
}
void storeFrame::IsRemove(wxCommandEvent &event) {
    if (grid->GetSelectedRows() == 0) {
        wxMessageBox("Choose a product", "Error", wxICON_ERROR);
    } else {
        wxArrayInt selectedRows = grid->GetSelectedRows();
        int row;
        for (size_t i = 0; i < selectedRows.GetCount(); i++) {
            row = selectedRows[i];
        }
        TableStore table;
        int id = stoi(mat_store[row][3]);
        table.remove_prod(id);
        grid->DeleteRows(row);
    }
}
