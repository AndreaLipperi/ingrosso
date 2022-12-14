//
// Created by dario on 09/12/2022.
//




#ifndef INGROSSO_ONLINE_CLIENTFRAME_H
#define INGROSSO_ONLINE_CLIENTFRAME_H
#include "wx/wx.h"
#include "wx/wxhtml.h"
#include "SelectFrame.h"
class ClientFrame:public wxFrame {
public:
    ClientFrame(const wxString& title, const wxPoint& pos, const wxSize& size);

    static const long IdButtonProducts;
    static const long IdButtonFavorites;
    static const long IdButtonOrders;
    static const long IdButtonCart;
    static const long IdButtonProfile;
    static const long IdButtonComeBack;

DECLARE_EVENT_TABLE()

private:
    void OpenProductsList(wxCommandEvent& event);
    void OpenProfile(wxCommandEvent& event);
    void OpenCart(wxCommandEvent& event);
    void OpenFavoritesList(wxCommandEvent& event);
    void OpenOrdersList(wxCommandEvent& event);
    void ComeBack(wxCommandEvent& event);
    wxButton *Cart;
    wxButton *Profile;
    wxButton *Favorites;
    wxButton *Products;
    wxButton *Orders;
    wxButton *Back;



};


#endif //INGROSSO_ONLINE_CLIENTFRAME_H


