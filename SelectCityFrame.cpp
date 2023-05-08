//
// Created by Andrea Lipperi on 08/05/23.
//

#include "SelectCityFrame.h"
#include "cityMethods.h"
#include "ViewDataUsersFrame.h"
#include "subcategoriesMethods.h"
#include "categoriesMethods.h"
#include "ProdListFrame.h"
#include <string>
#include <vector>

using namespace std;


const long SelectCityFrame::IdButtonInsert =::wxNewId();
const long SelectCityFrame::IdButtonComeBack =::wxNewId();

BEGIN_EVENT_TABLE (SelectCityFrame, wxFrame)

                EVT_BUTTON(IdButtonInsert, SelectCityFrame::InsertCity)
                EVT_BUTTON(IdButtonComeBack, SelectCityFrame::ComeBack)

END_EVENT_TABLE()

SelectCityFrame::SelectCityFrame( const wxString &title) :
        wxFrame(NULL, -1, title, wxPoint(-1, -1), wxSize(500, 350)){


    wxPanel *Mainpanel = new wxPanel(this, -1);

    wxBoxSizer *hbox = new wxBoxSizer(wxHORIZONTAL);


    wxFlexGridSizer *fgs=new wxFlexGridSizer(6,2,20,5);

    TableCity *table;

    std::vector<std::string> cities;

    cities=table->select();
    wxVector<string> choices;
    for (int k=0; k<table->number_of_city(); k++){
        choices.push_back(cities[k]);
    }
    wxString myString[table->number_of_city()];
    for (int i=0;i<table->number_of_city();i++) {
        myString[i].Append(choices[i]);
    }

    cities.clear();
    choices.clear();

    wxStaticText *City = new wxStaticText(Mainpanel, -1, wxT("Category"));

    Insert=new wxButton (Mainpanel,IdButtonInsert,_T ("Insert"),wxDefaultPosition,wxDefaultSize,0);
    Back=new wxButton(Mainpanel,IdButtonComeBack,_T ("Back"),wxDefaultPosition,wxDefaultSize,0);

    choiceC=new wxChoice(Mainpanel, wxID_ANY,wxDefaultPosition, wxDefaultSize);
    choiceC->Append("Select");
    choiceC->Append("All");
    choiceC->Append(table->number_of_city(),myString);


    fgs->Add(City,0);
    fgs->Add(choiceC,1, wxEXPAND);

    fgs->Add(Insert,0);
    fgs->Add(Back,0);



    fgs->AddGrowableRow(1, 1);
    fgs->AddGrowableCol(1, 1);




    hbox->Add(fgs, 1, wxALL, 10);



    Mainpanel->SetSizer(hbox);
    //this->SetSizer(MainBox);

    Centre();

}

void SelectCityFrame::InsertCity(wxCommandEvent &event) {
    if (choiceC->GetSelection() == wxNOT_FOUND)
    {
        wxMessageBox("Choose an option", "Error", wxICON_ERROR);
    } else {
        int Id_city = choiceC->GetSelection();
        string city = choiceC->GetString(Id_city).ToStdString();
        Close();
        ViewDataUsersFrame *view= new ViewDataUsersFrame(_T("USERS"), city);
        view->Show(TRUE);
    }
}

void SelectCityFrame::ComeBack(wxCommandEvent &event) {

    Close();

}
