//
// Created by dario on 28/04/2023.
//


#ifndef INGROSSO_ONLINE_MANAGEREQUESTFRAME_H
#define INGROSSO_ONLINE_MANAGEREQUESTFRAME_H
#include "wx/wx.h"
#include "wx/wxhtml.h"
#include "wx/grid.h"
#include "storeMethods.h"

class StoreFrame: public wxDialog{
public:
   StoreFrame(const wxString& title, const std::string id_providers);

    static const long IdButtonDelete;
    static const long IdButtonBack;

DECLARE_EVENT_TABLE()


private:
    void DeleteProduct(wxCommandEvent& event);
    void ComeBack(wxCommandEvent& event);

    wxButton *Delete;
    wxButton *Back;

    wxBoxSizer *sizer;

    wxGrid *grid;
    std::string sub_name;

    wxChoice* choiceOrder;

    std::string** mat_store;
};



#endif //INGROSSO_ONLINE_MANAGEREQUESTFRAME_H
