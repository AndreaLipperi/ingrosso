//
// Created by dario on 30/11/2022.
//

#include "ProvidersFrame.h"





const long ProvidersFrame::IdButtonStore =::wxNewId();
const long ProvidersFrame::IdButtonProfile =::wxNewId();
const long ProvidersFrame::IdButtonInsProd =::wxNewId();
const long ProvidersFrame::IdButtonRequests =::wxNewId();


BEGIN_EVENT_TABLE (ProvidersFrame, wxFrame)
EVT_BUTTON(IdButtonStore, ProvidersFrame::OpenStore)
EVT_BUTTON(IdButtonProfile, ProvidersFrame::OpenProfile)
EVT_BUTTON(IdButtonInsProd, ProvidersFrame::OpenInsProd)
EVT_BUTTON(IdButtonRequests, ProvidersFrame::OpenRequests)
END_EVENT_TABLE()


ProvidersFrame::ProvidersFrame(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size){

    wxPanel *panelHome = new wxPanel(this, -1);



    wxBoxSizer *box = new wxBoxSizer(wxHORIZONTAL);
    wxFlexGridSizer *MainGrid = new wxFlexGridSizer(2, 2, 25, -5);
    //wxFlexGridSizer *Grid1 = new wxFlexGridSizer(1, 2, 12, -5);
    // wxFlexGridSizer *Grid2 = new wxFlexGridSizer(1, 2, 12, -5);

    Requests=new wxButton (panelHome,IdButtonRequests,_T ("Manage requests"),wxDefaultPosition,wxSize(180,40),0);
    Profile=new wxButton(panelHome,IdButtonProfile, _T("Manage profile"), wxDefaultPosition,wxSize(180,40),0 );
    InsProd=new wxButton(panelHome, IdButtonInsProd, _T("Insert products"), wxDefaultPosition, wxSize(180,40), 0);
    Store=new wxButton(panelHome, IdButtonStore, _T("Store"),wxDefaultPosition, wxSize(180,40),0);


    MainGrid->Add(InsProd,0, wxLEFT, -15);
    MainGrid->Add(Profile,0,wxLEFT, 50);
    MainGrid->Add(Store,0, wxLEFT, -15);
    MainGrid->Add(Requests,0,wxLEFT, 50);

    MainGrid->AddGrowableRow(1, 1);
    MainGrid->AddGrowableCol(1, 1);


    box->Add(MainGrid, 1, wxALL, 60);



    panelHome->SetSizer(box);
    //this->SetSizer(MainBox);

    Centre();

}

void ProvidersFrame::OpenRequests(wxCommandEvent &event) {

}

void ProvidersFrame::OpenProfile(wxCommandEvent &event) {
 ManageProFrame *profile = new ManageProFrame (_T("PROFILE"));
 profile->Show(TRUE);
}

void ProvidersFrame::OpenStore(wxCommandEvent &event) {

}

void ProvidersFrame::OpenInsProd(wxCommandEvent &event) {
    NewProductsFrame *EnterWin = new NewProductsFrame (_T("NEW PRODUCT"));
    EnterWin->Show(TRUE);
}