
//
// Created by dario on 23/11/2022.
//
#include "wx/wxhtml.h"
#include "wx/wx.h"
#include <string>

#ifndef BUTTON_WXWIDGETS_REGISTERFRAME_H
#define BUTTON_WXWIDGETS_REGISTERFRAME_H


class RegisterFrame : public wxFrame{
public:
    RegisterFrame(const wxString& title);
    static const long IdButtonConfirm;

    DECLARE_EVENT_TABLE()


private:
    void Register(wxCommandEvent& event);
    wxButton *Confirm;

};


#endif //BUTTON_WXWIDGETS_REGISTERFRAME_H
