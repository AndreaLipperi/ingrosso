//
// Created by dario on 16/11/2022.
//

#include "SelectFrame.h"
#include "wx/wx.h"
#include "Enter.h"
#include "MyApp.h"
#include "SelectSubFrame.h"
#include "RegisterFrame.h"



const long SelectFrame::IdButtonRegister=::wxNewId();
const long SelectFrame::IdButtonAccess =::wxNewId();
BEGIN_EVENT_TABLE (SelectFrame, wxFrame)
//EVT_BUTTON ( BUTTON_Hello, SelectFrame::OnExit )
                EVT_BUTTON(IdButtonAccess, SelectFrame::OnAccess)
                EVT_BUTTON(IdButtonRegister, SelectFrame::OnRegister)
// Tell the OS to run MainFrame::OnExit when
END_EVENT_TABLE() // The button is pressed


std::string SelectFrame::username_actual_user="";
SelectFrame::SelectFrame(const wxString &title, const wxPoint &pos, const wxSize
&size): wxFrame(NULL,  - 1, title, pos, size)

{

    this->SetSizeHints(wxDefaultSize, wxDefaultSize);
    wxBoxSizer *MainBox= new wxBoxSizer(wxHORIZONTAL);
    wxBoxSizer *MainBox1=new wxBoxSizer(wxHORIZONTAL);
    Register=new wxButton (this,IdButtonRegister,_T ("Register"),wxDefaultPosition,wxSize(180,40),0);
    HelloWorld=new wxButton(this,IdButtonAccess,_T ("Enter"), wxDefaultPosition,wxSize(180,40),0);
    MainBox1->Add(Register,0,wxALL,0);
    this->SetSizer(MainBox1);
    MainBox->Add(HelloWorld,0,wxLEFT,210);
    this->SetSizer(MainBox);
    this->Layout();
//HelloWorld = new wxButton(this, BUTTON_Hello, _T("Enter"),
// shows a button on this window
//wxDefaultPosition, wxDefaultSize,0); // with the text "hello World"
}


void SelectFrame::OnAccess(wxCommandEvent& event )
{

    Enter *MainWin2 = new Enter(_T("Enter!"));
    MainWin2->ShowModal(); // show the window
    // and finally, set it as the main window
    // Tells the OS to quit running this process
}
void SelectFrame::OnRegister(wxCommandEvent& event){

    RegisterFrame *MainWin3 = new RegisterFrame(_T("Register!"));
    MainWin3->ShowModal();
}
