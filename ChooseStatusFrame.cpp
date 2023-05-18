//
// Created by Andrea Lipperi on 04/05/23.
//

#include "ChooseStatusFrame.h"
#include "OrderListClient.h"
#include "ManageRequestFrame.h"
#include "subcategoriesMethods.h"
#include "GlobalVariables.h"
#include "categoriesMethods.h"
#include "ProdListFrame.h"
#include <string>
#include <vector>

using namespace std;


const long ChooseStatusFrame::IdButtonInsert =::wxNewId();
const long ChooseStatusFrame::IdButtonComeBack =::wxNewId();

BEGIN_EVENT_TABLE (ChooseStatusFrame, wxFrame)

                EVT_BUTTON(IdButtonInsert, ChooseStatusFrame::InsertProduct)
                EVT_BUTTON(IdButtonComeBack, ChooseStatusFrame::ComeBack)

END_EVENT_TABLE()

ChooseStatusFrame::ChooseStatusFrame( const wxString &title) :
        wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)){
    type=GlobalVariables::GetInstance().GetValueType();

    wxStaticText *txt = new wxStaticText(this, -1, wxT("CHOOSE STATUS OF THE ORDERS YOU WANT TO SEE"));

    Insert=new wxButton (this,IdButtonInsert,_T ("Insert"),wxDefaultPosition,wxDefaultSize,0);
    Back=new wxButton(this,IdButtonComeBack,_T ("Back"),wxDefaultPosition,wxDefaultSize,0);

    choice=new wxChoice(this, wxID_ANY,wxDefaultPosition, wxDefaultSize);
    wxString myChoice[]={"Only Pending", "All"};
    choice->Append("Select");
    choice->Append(2,myChoice);

    sizer = new wxBoxSizer(wxVERTICAL);

    sizer->Add(txt, 0);
    sizer->Add(choice, 1, wxEXPAND | wxALL, 5);
    sizer->Add(Insert, 1, wxEXPAND | wxALL, 5);
    sizer->Add(Back, 1, wxEXPAND | wxALL, 5);
    SetSizer(sizer);


    Centre();

}
void ChooseStatusFrame::InsertProduct(wxCommandEvent &event) {
    if (choice->GetSelection() == wxNOT_FOUND)
    {
        wxMessageBox("Choose an option", "Error", wxICON_ERROR);
    } else {
        int Id_choice = choice->GetSelection()-1;
        if (type=="F") {
            ManageRequestFrame *req = new ManageRequestFrame(_T("YOUR REQUESTS"), Id_choice);
            // Passa la stringa alla classe wxFrame di destinazione.
            req->Show(TRUE);
        } else {
            OrderListClient *ord = new OrderListClient(_T("YOUR ORDERS"), Id_choice);
            // Passa la stringa alla classe wxFrame di destinazione.
            ord->Show(TRUE);
        }

    }
}

void ChooseStatusFrame::ComeBack(wxCommandEvent &event) {

    Close();

}