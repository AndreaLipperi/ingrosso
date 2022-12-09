//
// Created by dario on 05/12/2022.
//

#include "NewProductsFrame.h"

const long NewProductsFrame::IdButtonInsert =::wxNewId();
const long NewProductsFrame::IdButtonComeBack =::wxNewId();


BEGIN_EVENT_TABLE (NewProductsFrame, wxFrame)
EVT_BUTTON(IdButtonInsert, NewProductsFrame::InsertProduct)
EVT_BUTTON(IdButtonComeBack, NewProductsFrame::ComeBack)

END_EVENT_TABLE()

NewProductsFrame::NewProductsFrame( const wxString &title) :
        wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)){


    wxPanel *Mainpanel = new wxPanel(this, -1);

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);


    wxFlexGridSizer *fgs=new wxFlexGridSizer(2,2, 20,5);


    //wxBoxSizer *MainBox=new wxBoxSizer(wxHORIZONTAL);

    wxStaticText *Category = new wxStaticText(Mainpanel, -1, wxT("Type"));
    wxStaticText *Name = new wxStaticText(Mainpanel, -1, wxT("Product's name"));
    wxStaticText *Qty_avb= new wxStaticText(Mainpanel, -1, wxT("Quantity available"));
    wxStaticText *Cost= new wxStaticText(Mainpanel, -1, wxT("$"));

    Insert=new wxButton (Mainpanel,IdButtonInsert,_T ("Insert"),wxDefaultPosition,wxDefaultSize,0);
    Back=new wxButton(Mainpanel,IdButtonComeBack,_T ("Back"),wxDefaultPosition,wxDefaultSize,0);



    tcCategory = new wxTextCtrl(Mainpanel, -1);
    tcName = new wxTextCtrl(Mainpanel, -1);
    tcCost = new wxTextCtrl(Mainpanel, -1);
    tcQ_a= new wxTextCtrl(Mainpanel, -1);


    fgs->Add(Category,0);
    fgs->Add(tcCategory,1, wxEXPAND);
    fgs->Add(Name,0);
    fgs->Add(tcName,1, wxEXPAND);

    fgs->Add(Qty_avb,0);
    fgs->Add(tcQ_a,1);
    fgs->Add(Cost,0);
    fgs->Add(tcCost, 1);
    fgs->Add(Insert,0);
    fgs->Add(Back,0);



    fgs->AddGrowableRow(1, 1);
    fgs->AddGrowableCol(1, 1);




    hbox->Add(fgs, 1, wxALL, 10);



    Mainpanel->SetSizer(hbox);
    //this->SetSizer(MainBox);

    Centre();

}

void NewProductsFrame::InsertProduct(wxCommandEvent &event) {

}

void NewProductsFrame::ComeBack(wxCommandEvent &event) {

    Close(TRUE);
    ProvidersFrame *MainWin = new ProvidersFrame(_T("HOME"),wxPoint(50, 20), wxSize(600, 300));
    MainWin->Show(TRUE);
}