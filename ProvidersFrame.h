//
// Created by dario on 30/11/2022.
//


#ifndef INGROSSO_ONLINE_STOCKISTFRAME_H
#define INGROSSO_ONLINE_STOCKISTFRAME_H
#include "wx/wxhtml.h"
#include "wx/wx.h"
#include "NewProductsFrame.h"

class ProvidersFrame:public wxFrame {
public:
    ProvidersFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    static const long IdButtonRequests;
    static const long IdButtonProfile;
    static const long IdButtonStore;
    static const long IdButtonInsProd;

DECLARE_EVENT_TABLE()

private:
    void OpenRequests(wxCommandEvent& event);
    void OpenProfile(wxCommandEvent& event);
    void OpenStore(wxCommandEvent& event);
    void OpenInsProd(wxCommandEvent& event);
    wxButton *Requests;
    wxButton *Profile;
    wxButton *Store;
    wxButton *InsProd;

};


#endif //INGROSSO_ONLINE_STOCKISTFRAME_H