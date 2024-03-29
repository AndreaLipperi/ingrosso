//
// Created by dario on 09/12/2022.
//


#include <wx/wx.h>

#ifndef INGROSSO_ONLINE_CLIENTFRAME_H
#define INGROSSO_ONLINE_CLIENTFRAME_H
#include "SelectFrame.h"
class ClientFrame:public wxFrame {
public:
    ClientFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    static const long IdButtonProducts;
    static const long IdButtonFavorites;
    static const long IdButtonOrders;
    static const long IdButtonCart;
    static const long IdButtonProfile;
    static const long IdButtonProviders;
    static const long IdButtonRemove;
    static const long IdButtonComeBack;

DECLARE_EVENT_TABLE()

private:
    void OpenProductsList(wxCommandEvent& event);
    void OpenProfile(wxCommandEvent& event);
    void OpenCart(wxCommandEvent& event);
    void OpenFavoritesList(wxCommandEvent& event);
    void OpenOrdersList(wxCommandEvent& event);
    void ViewProviders(wxCommandEvent& event);
    void RemoveUser(wxCommandEvent& event);
    void ComeBack(wxCommandEvent& event);
    wxButton *Cart;
    wxButton *Profile;
    wxButton *Favorites;
    wxButton *Products;
    wxButton *Providers;
    wxButton *Orders;
    wxButton *Remove;
    wxButton *Back;
    std::string username;
    std::string type;



};


#endif //INGROSSO_ONLINE_CLIENTFRAME_H


