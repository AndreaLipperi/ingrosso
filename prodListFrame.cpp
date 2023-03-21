//
// Created by Matilde Tarchi on 20/03/23.
//
#include "prodListFrame.h"

std::string sub;
std::string cat;
std::string name;
std::string cost;
std::string quant;


const long prodListFrame::IdButtonConfirm =::wxNewId();
const long prodListFrame::IdButtonComeBack =::wxNewId();

BEGIN_EVENT_TABLE (prodListFrame, wxFrame)
                EVT_BUTTON(IdButtonConfirm, prodListFrame::IsConfirm)
                EVT_BUTTON(IdButtonComeBack, prodListFrame::ComeBack)
END_EVENT_TABLE()

prodListFrame::prodListFrame(const wxString &title):
        wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)) {


    wxPanel *panel = new wxPanel(this, -1);

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);
    wxGrid *grid = new wxGrid(this, wxID_ANY);
    grid->CreateGrid(5, 6);
    grid->SetColLabelValue(0, "Sottocategoria");
    grid->SetColLabelValue(1, "Categoria");
    grid->SetColLabelValue(2, "Nome");
    grid->SetColLabelValue(3, "Costo");
    grid->SetColLabelValue(4, "Quantità Disponibile");
    grid->SetColLabelValue(4, "Favorito");

    for (int row = 0; row < 5; row++) {
        for (int col = 0; col < 5; col++) {
            grid->SetCellValue(row, col, wxString::Format("(%d, %d)", row, col));
        }
    }
    grid->AutoSize();
}


void prodListFrame::IsConfirm(wxCommandEvent &event) {

}

void prodListFrame::ComeBack(wxCommandEvent &event) {

}




/*wxFlexGridSizer *fgs = new wxFlexGridSizer(8, 2, 12, -5);

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


}


void prodListFrame::Register(wxCommandEvent &event) {
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