#ifndef _WIDGET_H_
#define _WIDGET_H_

#include <gtk/gtk.h>

class Widget {
public:
    Widget();
    ~Widget();
    static GtkWidget* getMainWindow();
    static GtkWidget* getListView();
private:
    static GtkWidget* mpMainWindow;
    static GtkWidget* mpListView;
};
#endif