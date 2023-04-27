//
// Created by Andrea Lipperi on 20/04/23.
//

#include "CartFrame.h"
#include "ordersMethods.h"
#include "UsernameGlobal.h"
#include "orders.h"
#include "cartMethods.h"
#include "wx/grid.h"

#include <wx/spinctrl.h>

const long CartFrame::IdButtonRemove =::wxNewId();
const long CartFrame::IdButtonOrder =::wxNewId();
const long CartFrame::IdButtonComeBack =::wxNewId();

BEGIN_EVENT_TABLE (CartFrame, wxFrame)
                EVT_BUTTON(IdButtonRemove, CartFrame::IsRemove)
                EVT_BUTTON(IdButtonOrder, CartFrame::IsOrder)
                EVT_BUTTON(IdButtonComeBack, CartFrame::ComeBack)
END_EVENT_TABLE()

CartFrame::CartFrame(const wxString &title):
        wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)) {

    username=UsernameGlobal::GetInstance().GetValueUsername();
    TableCart cart;
    int row = cart.select_count(username);
    mat_cart=new string *[row];
    for (int k = 0; k < row; k++) {
        mat_cart[k] = new string[6];
    }
    grid = new wxGrid(this, wxID_ANY);
    grid->CreateGrid(row, 4);
    grid->SetColLabelValue(0, "Name Product");
    grid->SetColLabelValue(1, "Price");
    grid->SetColLabelValue(2, "Provider Name");
    grid->SetColLabelValue(3, "Quantity to Order");
    mat_cart=cart.select(username);

    for (int i = 0; i < cart.select_count(username); i++) {

        for (int col = 0; col < 4; col++) {
            grid->SetReadOnly(i, col, true);
            grid->SetCellValue(i, col,  mat_cart[i][col]);
        }
    }
    grid->SetSelectionMode(wxGrid::wxGridSelectRows);
    grid->AutoSize();

    Remove=new wxButton(this,IdButtonRemove,_T ("Remove"),wxDefaultPosition,wxDefaultSize,0);
    Order=new wxButton(this,IdButtonOrder,_T ("Do Order"),wxDefaultPosition,wxDefaultSize,0);
    Back=new wxButton(this,IdButtonComeBack,_T ("Back"),wxDefaultPosition,wxDefaultSize,0);


    sizer = new wxBoxSizer(wxVERTICAL);

    sizer->Add(grid, 1, wxEXPAND | wxALL, 5);
    sizer->Add(Remove, 1, wxEXPAND | wxALL, 5);
    sizer->Add(Order, 1, wxEXPAND | wxALL, 5);
    sizer->Add(Back, 1, wxEXPAND | wxALL, 5);
    SetSizer(sizer);


    Centre();


}

void CartFrame::IsRemove(wxCommandEvent &event) {
    if (grid->GetSelectedRows() == 0) {
        wxMessageBox("Choose a product", "Error", wxICON_ERROR);
    } else {
        wxArrayInt selectedRows = grid->GetSelectedRows();
        int row;
        for (size_t i = 0; i < selectedRows.GetCount(); i++) {
            row = selectedRows[i];
        }
        TableCart table;
        int id = stoi(mat_cart[row][5]);
        table.remove_prod(id);
        grid->DeleteRows(row);
    }
}

void CartFrame::IsOrder(wxCommandEvent &event) {
    TableCart cart;
    int row = cart.select_count(username);
    TableOrders table;
    std::time_t t = std::time(nullptr); // ottiene il numero di secondi trascorsi dal 1 gennaio 1970
    std::tm* now = std::localtime(&t); // converte in una struttura tm con informazioni sulla data e sull'ora attuali
    int year = now->tm_year + 1900; // anno attuale (tm_year contiene l'anno dal 1900)
    int month = now->tm_mon + 1; // mese attuale (tm_mon contiene il mese da 0 a 11)
    int day = now->tm_mday; // giorno attuale del mese
    string data = ""+to_string(year)+"/"+ to_string(month)+"/"+ to_string(day)+"";
    int i=0;
    int j=0;
    int id_order[row];
    while (j<row) {
        id_order[j]=table.select_id(mat_cart[j][2])+1;
        j++;
    }
    while (i<row){
        Orders *order = new Orders(stoi(mat_cart[i][3]),stoi(mat_cart[i][4]),"S",data,username,mat_cart[i][2],id_order[i]);
        table.add(*order);
        i++;
    }
    cart.remove_all(username);
    grid->ClearGrid();
}

void CartFrame::ComeBack(wxCommandEvent &event) {
    Close();
}