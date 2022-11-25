//
// Created by dario on 16/11/2022.
//
#include <wx/wx.h>
#include "wx/wxhtml.h"
#ifndef BUTTON_WXWIDGETS_NEWFRAME_H
#define BUTTON_WXWIDGETS_NEWFRAME_H


class Enter : public wxFrame{
    public:
        Enter(const wxString& title);
        static const long IdButtonConfirm;

        DECLARE_EVENT_TABLE()

    private:
     void Access(wxCommandEvent& event);
      wxButton *Confirm;
};



#endif //BUTTON_WXWIDGETS_NEWFRAME_H
