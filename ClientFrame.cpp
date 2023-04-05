//
// Created by dario on 09/12/2022.
//
#include <wx/wx.h>
#include "ClientFrame.h"
//
// Created by dario on 30/11/2022.
//
#include "SelectSubFrame.h"
#include "ManageProFrame.h"
#include "FavouritesFrame.h"
#include "UsernameGlobal.h"


const long ClientFrame::IdButtonCart =::wxNewId();
const long ClientFrame::IdButtonProfile =::wxNewId();
const long ClientFrame::IdButtonFavorites =::wxNewId();
const long ClientFrame::IdButtonOrders =::wxNewId();
const long ClientFrame::IdButtonProducts =::wxNewId();
const long ClientFrame::IdButtonComeBack =::wxNewId();




BEGIN_EVENT_TABLE (ClientFrame, wxFrame)

           EVT_BUTTON(IdButtonCart, ClientFrame::OpenCart)
           EVT_BUTTON(IdButtonProfile, ClientFrame::OpenProfile)
           EVT_BUTTON(IdButtonProducts, ClientFrame::OpenProductsList)
           EVT_BUTTON(IdButtonOrders, ClientFrame::OpenOrdersList)
           EVT_BUTTON(IdButtonFavorites, ClientFrame::OpenFavoritesList)
           EVT_BUTTON(IdButtonComeBack, ClientFrame::ComeBack)

END_EVENT_TABLE()


ClientFrame::ClientFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size){



    wxPanel *panelHome = new wxPanel(this, -1);



    wxBoxSizer *box = new wxBoxSizer(wxHORIZONTAL);
    wxFlexGridSizer *MainGrid = new wxFlexGridSizer(3, 2, 25, -60);


    Orders=new wxButton (panelHome,IdButtonOrders,_T ("Orders' list"),wxDefaultPosition,wxSize(180,40),0);
    Profile=new wxButton(panelHome,IdButtonProfile, _T("Manage profile"), wxDefaultPosition,wxSize(180,40),0 );
    Products=new wxButton(panelHome, IdButtonProducts, _T("Products' list"), wxDefaultPosition, wxSize(180,40), 0);
    Cart=new wxButton(panelHome, IdButtonCart, _T("Cart"),wxDefaultPosition, wxSize(180,40),0);
    Favorites=new wxButton(panelHome, IdButtonFavorites, _T("Favorites"),wxDefaultPosition, wxSize(180,40),0);
    Back=new wxButton(panelHome,IdButtonComeBack,_T ("Logout"),wxDefaultPosition,wxDefaultSize,0);




    MainGrid->Add(Products,0);
    MainGrid->Add(Favorites,0,wxLEFT, 10);
    MainGrid->Add(Orders,0);
    MainGrid->Add(Cart,0,wxLEFT, 10);
    MainGrid->Add(Profile,0,wxLEFT,130);
    MainGrid->Add(Back,0,wxLEFT, 90);

    MainGrid->AddGrowableRow(1, 1);
    MainGrid->AddGrowableCol(1, 1);


    box->Add(MainGrid, 1, wxALL, 60);



    panelHome->SetSizer(box);
    //this->SetSizer(MainBox);

    Centre();

}

void ClientFrame::OpenProductsList(wxCommandEvent &event) {
    SelectSubFrame *List = new SelectSubFrame (_T("LISTA"));
    List->Show(TRUE);
}

void ClientFrame::OpenProfile(wxCommandEvent &event) {
    ManageProFrame *manage = new ManageProFrame (_T("LISTA"));
    manage->Show(TRUE);
}

void ClientFrame::OpenCart(wxCommandEvent &event) {

}

void ClientFrame::OpenFavoritesList(wxCommandEvent &event) {
    FavouritesFrame *fav=new FavouritesFrame(_T("Favoutites"));
    fav->Show(TRUE);
}

void ClientFrame::OpenOrdersList(wxCommandEvent &event) {

}

void ClientFrame::ComeBack(wxCommandEvent &event) {
    UsernameGlobal::GetInstance().SetValueUsername("");
    UsernameGlobal::GetInstance().SetValueType("");
    Hide();

}