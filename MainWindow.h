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
    void appendColumn2Listview(GtkWidget *pListview, const char *pTitle, const int order);
    void createModel(GtkWidget *pListview);
    GtkUIManager* create_menu(GtkWidget *parent);
    void cb_quit(GtkAction *action, gpointer user_data);
    void cb_open(GtkAction *action, gpointer user_data);

private:
    GtkActionEntry *entries;
};

#endif
