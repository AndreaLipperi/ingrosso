//
// Created by dario on 16/11/2022.
//

#include <wx/wx.h>
#include "wx/wxhtml.h"
#ifndef BUTTON_WXWIDGETS_NEWFRAME_H
#define BUTTON_WXWIDGETS_NEWFRAME_H


class Enter : public wxDialog{
public:
    Enter(const wxString& title);
    static const long IdButtonConfirm;
    static const long IdButtonBack;

DECLARE_EVENT_TABLE()

private:
    void Access(wxCommandEvent& event);
    void ComeBack(wxCommandEvent& event);
    wxButton *Confirm;
    wxButton *Back;
    wxTextCtrl *m_passwordText;
    wxTextCtrl *tc1;
};



#endif //BUTTON_WXWIDGETS_NEWFRAME_H