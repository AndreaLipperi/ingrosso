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


    wxFlexGridSizer *fgs=new wxFlexGridSizer(6,2,20,5);

    TableCategories table_cat;
    TableProducts table_sub;

   // std::vector<std::string> categories;
    //std::vector<std::string> subcategories;

   // categories=table_cat.select();
    wxString choices[]={};
   // for (int i=0; i<categories.size(); i++){
      //  choices[i]=categories[i];
   // }
 //   int Id_cat = choiceC->GetSelection();
  //  std::string Cat=choiceC->GetString(Id_cat).ToStdString();

    wxString choices2[]={};
   // subcategories=table_sub.select(Cat);
   // for (int i=0; i<subcategories.size(); i++){
   //     choices2[i]=subcategories[i];
   // };

    wxStaticText *Category = new wxStaticText(Mainpanel, -1, wxT("Category"));
    wxStaticText *SubCategory = new wxStaticText(Mainpanel, -1, wxT("Subcategory"));
    wxStaticText *Name = new wxStaticText(Mainpanel, -1, wxT("Product's name"));
    wxStaticText *Qty_avb= new wxStaticText(Mainpanel, -1, wxT("Quantity available"));
    wxStaticText *Cost= new wxStaticText(Mainpanel, -1, wxT("$"));

    Insert=new wxButton (Mainpanel,IdButtonInsert,_T ("Insert"),wxDefaultPosition,wxDefaultSize,0);
    Back=new wxButton(Mainpanel,IdButtonComeBack,_T ("Back"),wxDefaultPosition,wxDefaultSize,0);


    choiceC=new wxChoice(Mainpanel, wxID_ANY,wxDefaultPosition, wxDefaultSize,3,choices);
    choiceSubC=new wxChoice(Mainpanel, wxID_ANY,wxDefaultPosition, wxDefaultSize,3,choices2);
    tcName = new wxTextCtrl(Mainpanel, -1);
    tcCost = new wxTextCtrl(Mainpanel, -1);
    tcQ_a= new wxTextCtrl(Mainpanel, -1);


    fgs->Add(Category,0);
    fgs->Add(choiceC,1, wxEXPAND);
    fgs->Add(SubCategory,0);
    fgs->Add(choiceC,1, wxEXPAND);

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
    int Id_subcategory= choiceSubC->GetSelection();
    std::string Sub_category=choiceSubC->GetString(Id_subcategory).ToStdString();
    int Id_category = choiceC->GetSelection();
    std::string Category=choiceC->GetString(Id_category).ToStdString();
    std::string Name = tcName->GetValue().ToStdString();
    std::string  Quantity = tcQ_a->GetValue().ToStdString();
    std::string Price = tcCost->GetValue().ToStdString();

}

void NewProductsFrame::ComeBack(wxCommandEvent &event) {

   Close();

}