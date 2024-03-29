//
// Created by Andrea Lipperi on 22/03/23.
//

#include "ProdListFrame.h"
#include "SelectSubFrame.h"
#include "GlobalVariables.h"
#include "favourites.h"
#include "favouritesMethods.h"
#include "cartMethods.h"
#include "cart.h"
#include <wx/grid.h>
#include <wx/app.h>
#include <wx/spinctrl.h>

const long ProdListFrame::IdButtonFav =::wxNewId();
const long ProdListFrame::IdButtonCart =::wxNewId();
const long ProdListFrame::IdButtonInsert =::wxNewId();

BEGIN_EVENT_TABLE (ProdListFrame, wxFrame)
                EVT_BUTTON(IdButtonFav, ProdListFrame::IsFavourites)
                EVT_BUTTON(IdButtonCart, ProdListFrame::IsCart)
                EVT_BUTTON(IdButtonInsert, ProdListFrame::IsInsert)
END_EVENT_TABLE()

ProdListFrame::ProdListFrame(const wxString &title, const std::string &sub, const std::string &disp):
        wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)) {
    sub_name=sub;
    disponibility=disp;
    username=GlobalVariables::GetInstance().GetValueUsername();

    wxStaticText *order = new wxStaticText(this, -1, wxT("Order By"));
    wxString myString[]={"Name Product", "Price", "Provider Name"};
    choiceOrder=new wxChoice(this, wxID_ANY,wxDefaultPosition, wxDefaultSize);
    choiceOrder->Append("Select");
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
    grid->SetColLabelValue(0, "Name Product");
    grid->SetColLabelValue(1, "Price");
    grid->SetColLabelValue(2, "Provider Name");
    grid->SetColLabelValue(3, "Disponibility");
    mat_store=store.select(sub_name,disponibility);

    for (int i = 0; i < store.select_count(sub_name, disponibility); i++) {

        for (int col = 0; col < 4; col++) {
                grid->SetReadOnly(i, col, true);
                grid->SetCellValue(i, col,  mat_store[i][col]);
        }
    }
    grid->SetSelectionMode(wxGrid::wxGridSelectRows);
    grid->AutoSize();


    FavButton=new wxButton (this,IdButtonFav,_T ("Add to favourites"),wxDefaultPosition,wxDefaultSize,0);
    CartButton=new wxButton (this,IdButtonCart,_T ("Add to cart"),wxDefaultPosition,wxDefaultSize,0);

    sizer = new wxBoxSizer(wxVERTICAL);

    sizer->Add(order, 0, wxALL, 5);
    sizer->Add(choiceOrder, 0, wxALL, 5);
    sizer->Add(grid, 1, wxEXPAND | wxALL, 5);
    sizer->Add(FavButton, 1, wxEXPAND | wxALL, 5);
    sizer->Add(CartButton, 1, wxEXPAND | wxALL, 5);
    SetSizer(sizer);

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
void ProdListFrame::IsFavourites(wxCommandEvent &event) {
    if (grid->GetSelectedRows() == 0) {
        wxMessageBox("Choose a product", "Error", wxICON_ERROR);
    } else {
        wxArrayInt selectedRows = grid->GetSelectedRows();
        int row;
        for (size_t i = 0; i < selectedRows.GetCount(); i++) {
            row = selectedRows[i];
        }

        Favourites *fav = new Favourites(mat_store[row][4], username, mat_store[row][2]);
        TableFavourites table;
        table.add(*fav);
    }
}

void ProdListFrame::IsCart(wxCommandEvent &event)  {
    if (grid->GetSelectedRows() == 0) {
        wxMessageBox("Choose a product", "Error", wxICON_ERROR);
    } else {
        sizer->Hide(FavButton);
        sizer->Hide(CartButton);
        wxStaticText *q = new wxStaticText(this, -1, wxT("Insert Quantity"));
        sizer->Add(q, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
        spinCtrl = new wxSpinCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, 0);
        sizer->Add(spinCtrl, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
        wxButton *insert=new wxButton(this,IdButtonInsert,_T ("Add to cart"),wxDefaultPosition,wxDefaultSize,0);
        sizer->Add(insert, 0, wxALIGN_CENTER_VERTICAL | wxALL, 5);
        wxSize currentSize = GetSize();
        int newWidth = currentSize.GetWidth() +1;
        int newHeight = currentSize.GetHeight() +1;
        SetSize(newWidth, newHeight);
    }
}
void ProdListFrame::IsInsert(wxCommandEvent &event) {
    if (spinCtrl->GetValue()<1){
        wxMessageBox("Insert a valid quantity", "Error", wxICON_ERROR);
    } else {
        wxArrayInt selectedRows = grid->GetSelectedRows();
        int row;
        for (size_t i = 0; i < selectedRows.GetCount(); i++) {
            row = selectedRows[i];
        }
        std::string username_cust=GlobalVariables::GetInstance().GetValueUsername();
        TableCart table;
        int quantity = spinCtrl->GetValue();
        Cart *cart = new Cart(quantity,mat_store[row][4], username_cust, mat_store[row][2]);
        table.add(*cart);
    }
}
