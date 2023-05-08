//
// Created by dario on 30/11/2022.
//

#include "ProvidersFrame.h"
#include "ChooseStatusFrame.h"
#include "StoreFrame.h"
#include "UsernameGlobal.h"
#include "ManageProFrame.h"
#include "SelectFrame.h"

const long ProvidersFrame::IdButtonStore =::wxNewId();
const long ProvidersFrame::IdButtonProfile =::wxNewId();
const long ProvidersFrame::IdButtonInsProd =::wxNewId();
const long ProvidersFrame::IdButtonRequests =::wxNewId();
const long ProvidersFrame::IdButtonRemove =::wxNewId();
const long ProvidersFrame::IdButtonBack =::wxNewId();


BEGIN_EVENT_TABLE (ProvidersFrame, wxFrame)
EVT_BUTTON(IdButtonStore, ProvidersFrame::OpenStore)
EVT_BUTTON(IdButtonProfile, ProvidersFrame::OpenProfile)
EVT_BUTTON(IdButtonInsProd, ProvidersFrame::OpenInsProd)
EVT_BUTTON(IdButtonRequests, ProvidersFrame::OpenRequests)
EVT_BUTTON(IdButtonRemove, ProvidersFrame::RemoveUser)
EVT_BUTTON(IdButtonBack, ProvidersFrame::ComeBack)
END_EVENT_TABLE()


ProvidersFrame::ProvidersFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size){

    wxPanel *panelHome = new wxPanel(this, -1);

    username=UsernameGlobal::GetInstance().GetValueUsername();
    type=UsernameGlobal::GetInstance().GetValueType();

    wxBoxSizer *box = new wxBoxSizer(wxHORIZONTAL);
    wxFlexGridSizer *MainGrid = new wxFlexGridSizer(2, 2, 25, -5);

    Requests=new wxButton (panelHome,IdButtonRequests,_T ("Manage requests"),wxDefaultPosition,wxSize(180,40),0);
    Profile=new wxButton(panelHome,IdButtonProfile, _T("Manage profile"), wxDefaultPosition,wxSize(180,40),0 );
    InsProd=new wxButton(panelHome, IdButtonInsProd, _T("Insert products"), wxDefaultPosition, wxSize(180,40), 0);
    Store=new wxButton(panelHome, IdButtonStore, _T("Store"),wxDefaultPosition, wxSize(180,40),0);
    Remove=new wxButton(panelHome, IdButtonRemove, _T("Delete Account"),wxDefaultPosition, wxSize(180,40),0);
    Back=new wxButton(panelHome,IdButtonBack,_T ("Logout"),wxDefaultPosition,wxDefaultSize,0);


    MainGrid->Add(InsProd,0);
    MainGrid->Add(Profile,0,wxLEFT, 50);
    MainGrid->Add(Store,0);
    MainGrid->Add(Requests,0,wxLEFT, 50);
    MainGrid->Add(Remove,0,wxLEFT, 50);
    MainGrid->Add(Back,0,wxLEFT, 50);


    MainGrid->AddGrowableRow(1, 1);
    MainGrid->AddGrowableCol(1, 1);


    box->Add(MainGrid, 1, wxALL, 60);



    panelHome->SetSizer(box);

    Centre();

}

void ProvidersFrame::OpenRequests(wxCommandEvent &event) {
    ChooseStatusFrame *EnterWin = new ChooseStatusFrame (_T("REQUESTS"));
    EnterWin->Show(TRUE);
}

void ProvidersFrame::OpenProfile(wxCommandEvent &event) {
    ManageProFrame *manage = new ManageProFrame (_T("MANAGE PROFILE"));
    manage->Show(TRUE);
}

void ProvidersFrame::OpenStore(wxCommandEvent &event) {
    StoreFrame *store = new StoreFrame(_T("STORE"));
    store->Show(TRUE);
}

void ProvidersFrame::OpenInsProd(wxCommandEvent &event) {
    NewProductsFrame *EnterWin = new NewProductsFrame (_T("NEW PRODUCT"));
    EnterWin->Show(TRUE);
}
void ProvidersFrame::ComeBack(wxCommandEvent &event) {
    UsernameGlobal::GetInstance().SetValueUsername("");
    UsernameGlobal::GetInstance().SetValueType("");
    Close();
    SelectFrame *home = new SelectFrame(_T("YOUR MARKET"), wxPoint(50, 20), wxSize(500, 300));
    home->Show(TRUE);
}
void ProvidersFrame::RemoveUser(wxCommandEvent &event)  {
    TableUsers table;
    if (table.remove(username, type)==0){
        wxMessageBox("You can't delete your account because you have orders not accepted/denied or some of your product are in someone's favourites or cart", "Error", wxICON_ERROR);
    } else {
        wxMessageBox("Account removed, you'll be sent to registracion page", "Error", wxICON_ERROR);
        UsernameGlobal::GetInstance().SetValueUsername("");
        UsernameGlobal::GetInstance().SetValueType("");
        Close();
        SelectFrame *home = new SelectFrame(_T("YOUR MARKET RIGHT HERE"), wxPoint(50, 20), wxSize(500, 300));
        home->Show(TRUE);
    }
}