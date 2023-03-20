//
// Created by Matilde Tarchi on 20/03/23.
//
#include "prodList.h"

std::string sub;
std::string cat;
std::string name;
std::string cost;
std::string quant;


const long prodList::IdButtonConfirm =::wxNewId();
const long prodList::IdButtonComeBack =::wxNewId();

BEGIN_EVENT_TABLE (prodList, wxDialog)
                EVT_BUTTON(IdButtonConfirm, prodList::IsConfirm)
                EVT_BUTTON(IdButtonComeBack, prodList::ComeBack)
END_EVENT_TABLE()

prodList::prodList(const wxString &title):
        wxDialog(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)) {


    wxPanel *panel = new wxPanel(this, -1);

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
    wxFlexGridSizer *fgs1=new wxFlexGridSizer(1,2, 12,-5);



    wxFlexGridSizer *fgs = new wxFlexGridSizer(8, 2, 12, -5);

    //wxBoxSizer *MainBox=new wxBoxSizer(wxHORIZONTAL);

    Confirm=new wxButton (panel,IdButtonConfirm,_T ("Ok"),wxDefaultPosition,wxDefaultSize,0);
    Back=new wxButton(panel,IdButtonComeBack,_T ("Back"),wxDefaultPosition,wxDefaultSize,0);




    fgs->Add(Confirm,0);
    fgs->Add(Back,0);

    fgs->AddGrowableRow(1, 1);
    fgs->AddGrowableCol(1, 1);


    hbox->Add(fgs, 1, wxALL, 10);



    panel->SetSizer(hbox);
    //this->SetSizer(MainBox);

    Centre();
}
/*
#include <wx/wx.h>
#include <wx/grid.h>

class MyFrame : public wxFrame {
public:
    MyFrame() : wxFrame(nullptr, wxID_ANY, "Tabella") {
        wxGrid* grid = new wxGrid(this, wxID_ANY);
        grid->CreateGrid(3, 3);
    }
};

class MyApp : public wxApp {
public:
    bool OnInit() override {
        MyFrame* frame = new MyFrame();
        frame->Show();
        return true;
    }
};*/



/*void prodList::Register(wxCommandEvent &event) {
    Close();

    b_n = tcB_n->GetValue().ToStdString();
    a = tcA->GetValue().ToStdString();
    c = tcC->GetValue().ToStdString();
    u = tcU->GetValue().ToStdString();
    em = tcEm->GetValue().ToStdString();
    psw = m_passwordText->GetValue().ToStdString();
    TableUsers table;
    int numResult;
    numResult = table.access_reg(em, psw, 1);
    Users *user;

    if (numResult == 0) {
        user = new Users(t, b_n, c, a, em, psw, u);
        table.add(*user);
        cout << table.select_type(em);
    } else {
        wxLogMessage("There is already an account with this email");
    }

}*/