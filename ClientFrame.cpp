//
// Created by dario on 09/12/2022.
//
#include <wx/wx.h>
#include "ClientFrame.h"
//
// Created by dario on 30/11/2022.
//
#include "SelectSubFrame.h"
#include "SelectFrame.h"
#include "ChooseStatusFrame.h"
#include "SelectCityFrame.h"
#include "ManageProFrame.h"
#include "FavouritesFrame.h"
#include "UsernameGlobal.h"
#include "CartFrame.h"


const long ClientFrame::IdButtonCart =::wxNewId();
const long ClientFrame::IdButtonProfile =::wxNewId();
const long ClientFrame::IdButtonFavorites =::wxNewId();
const long ClientFrame::IdButtonOrders =::wxNewId();
const long ClientFrame::IdButtonProducts =::wxNewId();
const long ClientFrame::IdButtonProviders =::wxNewId();
const long ClientFrame::IdButtonRemove =::wxNewId();
const long ClientFrame::IdButtonComeBack =::wxNewId();




BEGIN_EVENT_TABLE (ClientFrame, wxFrame)

           EVT_BUTTON(IdButtonCart, ClientFrame::OpenCart)
           EVT_BUTTON(IdButtonProfile, ClientFrame::OpenProfile)
           EVT_BUTTON(IdButtonProducts, ClientFrame::OpenProductsList)
           EVT_BUTTON(IdButtonProviders, ClientFrame::ViewProviders)
           EVT_BUTTON(IdButtonOrders, ClientFrame::OpenOrdersList)
           EVT_BUTTON(IdButtonFavorites, ClientFrame::OpenFavoritesList)
           EVT_BUTTON(IdButtonRemove, ClientFrame::RemoveUser)
           EVT_BUTTON(IdButtonComeBack, ClientFrame::ComeBack)

END_EVENT_TABLE()


ClientFrame::ClientFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size){
    username=UsernameGlobal::GetInstance().GetValueUsername();
    type=UsernameGlobal::GetInstance().GetValueType();


    wxPanel *panelHome = new wxPanel(this, -1);



    wxBoxSizer *box = new wxBoxSizer(wxHORIZONTAL);
    wxFlexGridSizer *MainGrid = new wxFlexGridSizer(3, 2, 25, -60);


    Orders=new wxButton (panelHome,IdButtonOrders,_T ("Orders' list"),wxDefaultPosition,wxSize(140,40),0);
    Profile=new wxButton(panelHome,IdButtonProfile, _T("Manage profile"), wxDefaultPosition,wxSize(140,40),0 );
    Products=new wxButton(panelHome, IdButtonProducts, _T("Products' list"), wxDefaultPosition, wxSize(140,40), 0);
    Providers=new wxButton(panelHome, IdButtonProviders, _T("View Providers"), wxDefaultPosition, wxSize(140,40), 0);
    Cart=new wxButton(panelHome, IdButtonCart, _T("Cart"),wxDefaultPosition, wxSize(140,40),0);
    Favorites=new wxButton(panelHome, IdButtonFavorites, _T("Favorites"),wxDefaultPosition, wxSize(140,40),0);
    Remove=new wxButton(panelHome, IdButtonRemove, _T("Delete Account"),wxDefaultPosition, wxDefaultSize,0);
    Back=new wxButton(panelHome,IdButtonComeBack,_T ("Logout"),wxDefaultPosition,wxDefaultSize,0);




    MainGrid->Add(Products,0,wxLEFT, 50);
    MainGrid->Add(Favorites,0,wxLEFT, 50);
    MainGrid->Add(Orders,0,wxLEFT, 50);
    MainGrid->Add(Cart,0,wxLEFT, 50);
    MainGrid->Add(Profile,0,wxLEFT,50);
    MainGrid->Add(Providers,0,wxLEFT,50);
    MainGrid->Add(Remove,0,wxLEFT,90);
    MainGrid->Add(Back,0,wxLEFT, 90);

    MainGrid->AddGrowableRow(1, 1);
    MainGrid->AddGrowableCol(1, 1);


    box->Add(MainGrid, 1, wxALL, 60);



    panelHome->SetSizer(box);
    //this->SetSizer(MainBox);

    Centre();

}

void ClientFrame::OpenProductsList(wxCommandEvent &event) {
    SelectSubFrame *List = new SelectSubFrame (_T("SELECT SUBCATEGORY"));
    List->Show(TRUE);
}

void ClientFrame::OpenProfile(wxCommandEvent &event) {
    ManageProFrame *manage = new ManageProFrame (_T("MANAGE YOUR PROFILE"));
    manage->Show(TRUE);
}

void ClientFrame::OpenCart(wxCommandEvent &event) {
    CartFrame *cart=new CartFrame(_T("CART"));
    cart->Show(TRUE);
}

void ClientFrame::OpenFavoritesList(wxCommandEvent &event) {
    FavouritesFrame *fav=new FavouritesFrame(_T("FAVOURITES LIST"));
    fav->Show(TRUE);
}

void ClientFrame::OpenOrdersList(wxCommandEvent &event) {
    ChooseStatusFrame *ord= new ChooseStatusFrame(_T("ORDERS"));
    ord->Show(TRUE);
}

void ClientFrame::ComeBack(wxCommandEvent &event) {
    UsernameGlobal::GetInstance().SetValueUsername("");
    UsernameGlobal::GetInstance().SetValueType("");
    Close();
    SelectFrame *home = new SelectFrame(_T("YOUR MARKET RIGHT HERE"), wxPoint(50, 20), wxSize(500, 300));
    home->Show(TRUE);
}

void ClientFrame::RemoveUser(wxCommandEvent &event) {
    TableUsers table;
    if (table.remove(username, type)==0){
        wxMessageBox("You can't delete your account because you have orders not accepted/denied", "Error", wxICON_ERROR);
    } else {
        wxMessageBox("Account removed, you'll be sent to registracion page", "Error", wxICON_ERROR);
        UsernameGlobal::GetInstance().SetValueUsername("");
        UsernameGlobal::GetInstance().SetValueType("");
        Close();
        SelectFrame *home = new SelectFrame(_T("YOUR MARKET RIGHT HERE"), wxPoint(50, 20), wxSize(500, 300));
        home->Show(TRUE);
    }
}

void ClientFrame::ViewProviders(wxCommandEvent &event) {
    SelectCityFrame *sel_c = new SelectCityFrame(_T("SELECT CITY"));
    sel_c->Show(TRUE);
}
