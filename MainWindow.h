#ifndef _MAINWINDOW_H_
#define _MAINWINDOW_H_

#include "common.h"
#include "Widget.h"

class MainWindow {
public:
    MainWindow();
    ~MainWindow();
private:
    void createWindow();
    void appendColumn2Listview(GtkWidget *treeview, const char *title, const int order);
    void set_data(GtkWidget *pListView);
    void create_model(GtkWidget *treeview);
};

#endif
