//
// Created by Matilde Tarchi on 20/04/23.
//

#include "cartFrame.h"
#include "ordersMethods.h"
#include "UsernameGlobal.h"
#include "orders.h"
#include "cartMethods.h"
#include "wx/grid.h"

#include <wx/spinctrl.h>

const long cartFrame::IdButtonRemove =::wxNewId();
const long cartFrame::IdButtonOrder =::wxNewId();
const long cartFrame::IdButtonComeBack =::wxNewId();

BEGIN_EVENT_TABLE (cartFrame, wxFrame)
                EVT_BUTTON(IdButtonRemove, cartFrame::IsRemove)
                EVT_BUTTON(IdButtonOrder, cartFrame::IsOrder)
                EVT_BUTTON(IdButtonComeBack, cartFrame::ComeBack)
END_EVENT_TABLE()

cartFrame::cartFrame(const wxString &title):
        wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)) {

    username=UsernameGlobal::GetInstance().GetValueUsername();
    TableCart cart;
    int row = cart.select_count(username);
    mat_cart=new string *[row];
    for (int k = 0; k < row; k++) {
        mat_cart[k] = new string[4];
    }
    grid = new wxGrid(this, wxID_ANY);
    grid->CreateGrid(row, 4);
    grid->SetColLabelValue(0, "Name Product");
    grid->SetColLabelValue(1, "Price");
    grid->SetColLabelValue(2, "Provider Name");
    grid->SetColLabelValue(3, "Quantity to Order");
    mat_cart=cart.select(username);

    //selection=new wxRadioButton(grid, wxID_ANY, wxT(""));
    for (int i = 0; i < cart.select_count(username); i++) {

        for (int col = 0; col < 3; col++) {
            grid->SetReadOnly(i, col, true);
            grid->SetCellValue(i, col,  mat_cart[i][col]);
        }
        grid->SetColFormatNumber(3);
        grid->SetCellValue(i, 3, "0");
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

void cartFrame::IsRemove(wxCommandEvent &event) {
    if (grid->GetSelectedRows() == 0) {
        wxMessageBox("Choose a product", "Error", wxICON_ERROR);
    } else {
        wxArrayInt selectedRows = grid->GetSelectedRows();
        int row;
        for (size_t i = 0; i < selectedRows.GetCount(); i++) {
            row = selectedRows[i];
        }
        TableCart table;
        int id = stoi(mat_cart[row][3]);
        table.remove_prod(id);
        grid->DeleteRows(row);
    }
}

void cartFrame::IsOrder(wxCommandEvent &event) {
    TableCart cart;
    int row = cart.select_count(username);
    int k=0;
    int control=1;
    string quantity;
    while (k<row && control==1) {
        quantity = grid->GetCellValue(k, 3).ToStdString();
        if (stoi(quantity) == 0) {
            control=0;
        }
        k++;
    }
    if (control==1) {
        TableOrders table;
        std::time_t t = std::time(nullptr); // ottiene il numero di secondi trascorsi dal 1 gennaio 1970
        std::tm* now = std::localtime(&t); // converte in una struttura tm con informazioni sulla data e sull'ora attuali
        int year = now->tm_year + 1900; // anno attuale (tm_year contiene l'anno dal 1900)
        int month = now->tm_mon + 1; // mese attuale (tm_mon contiene il mese da 0 a 11)
        int day = now->tm_mday; // giorno attuale del mese
        string data = ""+to_string(year)+"/"+ to_string(month)+"/"+ to_string(day)+"";
        int i=0;
        while (i<row){
            quantity = grid->GetCellValue(i, 3).ToStdString();
            Orders *order = new Orders(stoi(quantity),stoi(mat_cart[i][3]), "S",data,username,mat_cart[i][2]);
            table.add(*order);
            i++;
        }
    } else {
        wxMessageBox("Insert a valid quantity value in every row", "Error", wxICON_ERROR);
    }
}

void cartFrame::ComeBack(wxCommandEvent &event) {
    Close();
}
