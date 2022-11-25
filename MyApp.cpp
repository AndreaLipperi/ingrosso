
#include"MyApp.h"
#include "SelectFrame.h"
#include "Menu.h"
#include "Enter.h"
#include "RegisterFrame.h"


bool MyApp::OnInit()
{
    // Create an instance of our frame, or window

    SelectFrame *MainWin = new SelectFrame(_T("Ingrosso"), wxPoint(50, 20), wxSize(500, 300));
    MainWin->Show(TRUE); // show the window
    SetTopWindow(MainWin); // and finally, set it as the main window

    return TRUE;
}//
// Created by dario on 16/11/2022.
//
