//
// Created by Andrea Lipperi on 31/03/23.
//

#include "ModifyProductFrame.h"
#include "UsernameGlobal.h"
#include "storeMethods.h"


const long ModifyProductFrame::IdButtonConfirm =::wxNewId();

BEGIN_EVENT_TABLE (ModifyProductFrame, wxDialog)
                EVT_BUTTON(IdButtonConfirm, ModifyProductFrame::OnConfirm)
END_EVENT_TABLE()

ModifyProductFrame::ModifyProductFrame(const wxString &title, int id_store):
        wxDialog(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)) {
    id=id_store;

    wxStaticText *desc = new wxStaticText(this, -1, wxT("Name Product"));
    wxStaticText *price = new wxStaticText(this, -1, wxT("Price"));
    wxStaticText *quant = new wxStaticText(this, -1, wxT("Available Quantity"));

    Confirm=new wxButton (this,IdButtonConfirm,_T ("Confirm"),wxDefaultPosition,wxDefaultSize,0);
    TableStore table;
    data_store=new string *[1];
    for (int k = 0; k < 1; k++) {
        data_store[k] = new string[3];
    }
    data_store=table.select_to_modify(id);
    tcD = new wxTextCtrl(this, wxID_ANY,data_store[0][0]);

    sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(desc);
    sizer->Add(tcD, 0, wxALL, 5);
    sizer->Add(price);
    tcP = new wxSpinCtrlDouble(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, stod(data_store[0][1]), 0.01);
    sizer->Add(tcP, 0, wxALL, 5);
    sizer->Add(quant);
    tcQ = new wxSpinCtrl(this, wxID_ANY, "", wxDefaultPosition, wxDefaultSize, wxSP_ARROW_KEYS, 0, 100, stoi(data_store[0][2]));
    sizer->Add(tcQ, 0, wxALL, 5);
    sizer->Add(Confirm,0);


    SetSizer(sizer);

    Centre();
}


void ModifyProductFrame::OnConfirm(wxCommandEvent &event) {
    Close();

    std::string new_desc=tcD->GetValue().ToStdString();
    std::string new_price = to_string(tcP->GetValue());
    std::string new_quant= to_string(tcQ->GetValue());
    TableStore table;
    table.changeData(id,new_desc,new_price,stoi(new_quant));

}
