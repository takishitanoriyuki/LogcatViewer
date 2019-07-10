#include "Widget.h"

GtkWidget* Widget::mpMainWindow = nullptr;
GtkWidget* Widget::mpListView = nullptr;

Widget::Widget() {
    
}

Widget::~Widget() {
    
}

GtkWidget* Widget::getMainWindow() {
    if(!Widget::mpMainWindow) {
        Widget::mpMainWindow = gtk_window_new(GTK_WINDOW_TOPLEVEL);
    }
    return Widget::mpMainWindow;
}

GtkWidget* Widget::getListView() {
    if(!Widget::mpListView) {
        Widget::mpListView = gtk_tree_view_new();
    }
    return Widget::mpListView;
}
