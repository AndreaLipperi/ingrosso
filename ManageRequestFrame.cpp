//
// Created by dario on 20/04/2023.
//

#include "ManageRequestFrame.h"


const long ManageRequestFrame::IdButtonConfirm =::wxNewId();
const long ManageRequestFrame::IdButtonView =::wxNewId();

BEGIN_EVENT_TABLE (ManageRequestFrame, wxDialog)
         EVT_BUTTON(IdButtonConfirm, ManageRequestFrame::OnConfirm)
         EVT_BUTTON(IdButtonView, ManageRequestFrame::ViewOrder)

END_EVENT_TABLE()

ManageRequestFrame::ManageRequestFrame(const wxString &title):
        wxDialog(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)) {
    sub_name=sub;
    disponibility=disp;

   /* wxStaticText *order = new wxStaticText(this, -1, wxT("Order By"));
    wxString myString[]={"Name Product", "Price", "Provider Name"};
    choiceOrder=new wxChoice(this, wxID_ANY,wxDefaultPosition, wxDefaultSize);
    choiceOrder->Append("Select");
    choiceOrder->Append(3,myString);
    choiceOrder->Bind(wxEVT_CHOICE, &ProdListFrame::OnChoice, this);*/


    TableOrders order;
    int row = order.select_count(sub, disponibility);
    mat_store=new std::string *[row];
    for (int k = 0; k < row; k++) {
        mat_store[k] = new std::string[5];
    }
    grid = new wxGrid(this, wxID_ANY);
    grid->CreateGrid(row, 4);
    grid->SetColLabelValue(0, "Code order");
    grid->SetColLabelValue(1, "Date");
    grid->SetColLabelValue(2, "Customers");
    grid->SetColLabelValue(3, "Disponibility");
    mat_store=order.select(sub_name,disponibility);

    //selection=new wxRadioButton(grid, wxID_ANY, wxT(""));
    for (int i = 0; i < order.select_count(sub_name, disponibility); i++) {

        for (int col = 0; col < 4; col++) {
            grid->SetReadOnly(i, col, true);
            grid->SetCellValue(i, col,  mat_store[i][col]);
        }
    }
    grid->SetSelectionMode(wxGrid::wxGridSelectRows);
    grid->AutoSize();


    Confirm=new wxButton (this,IdButtonConfirm,_T ("Confirm"),wxDefaultPosition,wxDefaultSize,0);
    View=new wxButton (this,IdButtonView,_T ("View"),wxDefaultPosition,wxDefaultSize,0);

    sizer = new wxBoxSizer(wxVERTICAL);

    sizer->Add(order, 0, wxALL, 5);
    sizer->Add(choiceOrder, 0, wxALL, 5);
    sizer->Add(grid, 1, wxEXPAND | wxALL, 5);
    sizer->Add(Confirm, 1, wxEXPAND | wxALL, 5);
    sizer->Add(View, 1, wxEXPAND | wxALL, 5);
    SetSizer(sizer);

    Centre();


}


/*void ProdListFrame::OnChoice(wxCommandEvent& event) {
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
}*/
void ManageRequestFrame::OnConfirm(wxCommandEvent &event) {
    if (grid->GetSelectedRows() == 0) {
        wxMessageBox("Choose a product", "Error", wxICON_ERROR);
    } else
        wxArrayInt selectedRows = grid->GetSelectedRows();
    int row;
    for (size_t i = 0; i < selectedRows.GetCount(); i++) {
        row = selectedRows[i];
    }
    std::string username_cust=UsernameGlobal::GetInstance().GetValueUsername();
    TableOrders table;
    int quantity = spinCtrl->GetValue();
    Orders *order = new Orders(quantity,mat_store[row][4], username_cust, mat_store[row][2]);
    table.add(*order);
}

void ManageRequestFrame::ViewOrder(wxCommandEvent &event) {
    if (grid->GetSelectedRows() == 0) {
        wxMessageBox("Choose a product", "Error", wxICON_ERROR);
    } else
        std::string code;
        //TODO prendere valore di codeOrder
        ViewOrderFrame *view = new ViewOrderFrame(_T("ORDER LIST"),code);
         view->Show(TRUE);
}