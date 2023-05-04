//
// Created by Andrea Lipperi on 04/05/23.
//

#include "OrderListClient.h"
#include "UsernameGlobal.h"
#include "ViewOrderClient.h"


const long OrderListClient::IdButtonCancel =::wxNewId();
const long OrderListClient::IdButtonView =::wxNewId();

BEGIN_EVENT_TABLE (OrderListClient, wxDialog)
                EVT_BUTTON(IdButtonCancel, OrderListClient::CancelOrder)
                EVT_BUTTON(IdButtonView, OrderListClient::ViewOrder)

END_EVENT_TABLE()

OrderListClient::OrderListClient(const wxString &title, int control):
        wxDialog(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)) {
    ctrl=control;
    username=UsernameGlobal::GetInstance().GetValueUsername();
    wxStaticText *order_txt = new wxStaticText(this, -1, wxT("Order By"));
    wxString myString[]={"Code Order", "Provider Name", "Date Order"};
    choiceOrder=new wxChoice(this, wxID_ANY,wxDefaultPosition, wxDefaultSize);
    choiceOrder->Append("Select");
    choiceOrder->Append(3,myString);
    choiceOrder->Bind(wxEVT_CHOICE, &OrderListClient::OnChoice, this);

    TableOrders order;
    int row = order.select_count_for_client(username, ctrl);
    mat_order=new std::string *[row];
    for (int k = 0; k < row; k++) {
        if (ctrl==0) {
            mat_order[k] = new std::string[3];
        }else {
            mat_order[k] = new std::string[4];
        }
    }
    grid = new wxGrid(this, wxID_ANY);
    if (ctrl==0) {
        grid->CreateGrid(row, 3);
        grid->SetColLabelValue(0, "Code order");
        grid->SetColLabelValue(1, "Provider");
        grid->SetColLabelValue(2, "Date");
    } else {

        grid->CreateGrid(row, 4);
        grid->SetColLabelValue(0, "Code order");
        grid->SetColLabelValue(1, "Provider");
        grid->SetColLabelValue(2, "Date");
        grid->SetColLabelValue(3, "Status");

    }
    mat_order=order.select_for_client(username,ctrl);

    for (int i = 0; i < order.select_count_for_client(username,ctrl); i++) {
        if (ctrl==0) {
            for (int col = 0; col < 3; col++) {
                grid->SetReadOnly(i, col, true);
                grid->SetCellValue(i, col, mat_order[i][col]);
            }
        } else {
            for (int col = 0; col < 4; col++) {
                grid->SetReadOnly(i, col, true);
                grid->SetCellValue(i, col, mat_order[i][col]);
            }
        }
    }
    grid->SetSelectionMode(wxGrid::wxGridSelectRows);
    grid->AutoSize();


    Cancel=new wxButton (this,IdButtonCancel,_T ("Cancel Order"),wxDefaultPosition,wxDefaultSize,0);
    View=new wxButton (this,IdButtonView,_T ("View"),wxDefaultPosition,wxDefaultSize,0);

    sizer = new wxBoxSizer(wxVERTICAL);

    sizer->Add(order_txt, 0, wxALL, 5);
    sizer->Add(choiceOrder, 0, wxALL, 5);
    sizer->Add(grid, 1, wxEXPAND | wxALL, 5);
    sizer->Add(Cancel, 1, wxEXPAND | wxALL, 5);
    sizer->Add(View, 1, wxEXPAND | wxALL, 5);
    SetSizer(sizer);

    Centre();


}

void OrderListClient::CancelOrder(wxCommandEvent &event) {
    wxArrayInt selectedRows = grid->GetSelectedRows();
    int row;
    for (size_t i = 0; i < selectedRows.GetCount(); i++) {
        row = selectedRows[i];
    }
    if (grid->GetSelectedRows() == 0) {
        wxMessageBox("Choose a order", "Error", wxICON_ERROR);
    } else if (ctrl==1 && mat_order[row][3]!="Pending") {
        wxMessageBox("The one you choosed it's already confirmed or denied, you can't cancel it", "Error", wxICON_ERROR);
    } else {
        TableOrders table;
        table.cancel_order(username,mat_order[row][0],mat_order[row][1]);
        grid->DeleteRows(row);
    }
}
void OrderListClient::ViewOrder(wxCommandEvent &event) {
    if (grid->GetSelectedRows() == 0) {
        wxMessageBox("Choose a order", "Error", wxICON_ERROR);
    } else {
        std::string code;
        wxArrayInt selectedRows = grid->GetSelectedRows();
        int row;
        for (size_t i = 0; i < selectedRows.GetCount(); i++) {
            row = selectedRows[i];
        }
        code = mat_order[row][0];
        ViewOrderClient *view = new ViewOrderClient(_T("ORDER LIST"), code, mat_order[row][1]);
        view->Show(TRUE);
    }

}

void OrderListClient::OnChoice(wxCommandEvent& event) {
    TableOrders table;
    string order_choice=event.GetString().ToStdString();
    mat_order=table.select_for_client(username,ctrl,order_choice);
    for (int i = 0; i < table.select_count_for_client(username,ctrl); i++) {
        if (ctrl==0) {
            for (int col = 0; col < 3; col++) {
                grid->SetReadOnly(i, col, true);
                grid->SetCellValue(i, col, mat_order[i][col]);
            }
        } else {
            for (int col = 0; col < 4; col++) {
                grid->SetReadOnly(i, col, true);
                grid->SetCellValue(i, col, mat_order[i][col]);
            }
        }
    }
    grid->SetSelectionMode(wxGrid::wxGridSelectRows);
    grid->AutoSize();
}