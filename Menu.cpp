//
// Created by dario on 16/11/2022.
//

#include"Menu.h"
#include "wx/wx.h"
#include "MyApp.h"




enum{
    ID_I= 2
};

enum
{
    ID_Hello = 1
};


wxBEGIN_EVENT_TABLE(Menu, wxFrame)
     EVT_MENU(ID_Hello, Menu::OnHello)
     EVT_MENU(wxID_EXIT, Menu::OnExit)
     EVT_MENU(wxID_ABOUT, Menu::OnAbout)
     EVT_MENU(ID_I, Menu::OnI)

wxEND_EVENT_TABLE()



Menu::Menu(const wxString& title, const wxPoint& pos, const wxSize& size)
        : wxFrame(NULL, wxID_ANY, title, pos, size)
{

    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
                     "Help string shown in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);
    menuFile->AppendSeparator();
    menuFile->Append(ID_I, "&I...\tCtrl-S","Help string shown in status bar for this menu item");
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append( menuFile, "&File" );
    menuBar->Append( menuHelp, "&Help" );
    SetMenuBar( menuBar );
    CreateStatusBar();
    SetStatusText( "Welcome to wxWidgets!" );

}


void Menu::OnExit(wxCommandEvent& event)
{
    Close( true );
}
void Menu::OnAbout(wxCommandEvent& event)
{
    wxMessageBox( "This is a wxWidgets' Hello world sample",
                  "About Hello World", wxOK | wxICON_INFORMATION );
}
void Menu::OnHello(wxCommandEvent& event)
{
    wxLogMessage("Hello world from wxWidgets!");
}

void Menu::OnI(wxCommandEvent& event){
    wxLogMessage("I'm here");
}
