//
// Created by dario on 20/04/2023.
//

#include "ViewOrderFrame.h"

const long ViewOrderFrame::IdButtonBack =::wxNewId();


BEGIN_EVENT_TABLE (ViewOrderFrame, wxDialog)
    EVT_BUTTON(IdButtonBack, ViewOrderFrame::ComeBack)


END_EVENT_TABLE()

ViewOrderFrame::ViewOrderFrame(const wxString &title,const std::string &code_order):
        wxDialog(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)) {
    sub_name = sub;
    disponibility = disp;

    /* wxStaticText *order = new wxStaticText(this, -1, wxT("Order By"));
     wxString myString[]={"Name Product", "Price", "Provider Name"};
     choiceOrder=new wxChoice(this, wxID_ANY,wxDefaultPosition, wxDefaultSize);
     choiceOrder->Append("Select");
     choiceOrder->Append(3,myString);
     choiceOrder->Bind(wxEVT_CHOICE, &ProdListFrame::OnChoice, this);*/


    TableOrders orders;
    int row = orders.select_count(sub, disponibility);
    mat_store = new std::string *[row];
    for (int k = 0; k < row; k++) {
        mat_store[k] = new std::string[5];
    }
    grid = new wxGrid(this, wxID_ANY);
    grid->CreateGrid(row, 3);
    grid->SetColLabelValue(0, "Name order");
    grid->SetColLabelValue(1, "Quantity");
    grid->SetColLabelValue(2, "Price");

    mat_store = orders.select(sub_name, disponibility);

    //selection=new wxRadioButton(grid, wxID_ANY, wxT(""));
    for (int i = 0; i < orders.select_count(sub_name, disponibility); i++) {

        for (int col = 0; col < 4; col++) {
            grid->SetReadOnly(i, col, true);
            grid->SetCellValue(i, col, mat_store[i][col]);
        }
    }
    grid->SetSelectionMode(wxGrid::wxGridSelectRows);
    grid->AutoSize();


    Back = new wxButton(this, IdButtonBack, _T ("Back"), wxDefaultPosition, wxDefaultSize, 0);

    sizer = new wxBoxSizer(wxVERTICAL);

    sizer->Add(orders, 0, wxALL, 5);
    sizer->Add(choiceOrder, 0, wxALL, 5);
    sizer->Add(grid, 1, wxEXPAND | wxALL, 5);

    sizer->Add(Back, 1, wxEXPAND | wxALL, 5);
    SetSizer(sizer);

    Centre();
}

void ViewOrderFrame::ComeBack(wxCommandEvent &event) {

    Close();

}