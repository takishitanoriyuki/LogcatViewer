#include "MainWindow.h"

MainWindow::MainWindow() {
    createWindow();
}

MainWindow::~MainWindow() {

}

void MainWindow::createWindow() {
    GtkWidget* pMainWindow = Widget::getMainWindow();
    gtk_window_set_title(GTK_WINDOW(pMainWindow), "Logcat Viewer");
    gtk_widget_set_size_request(pMainWindow, 300, 200);
    g_signal_connect(pMainWindow, "destroy", G_CALLBACK(gtk_main_quit), NULL);

    GtkWidget* vbox=gtk_vbox_new(GTK_ORIENTATION_HORIZONTAL,2);
    gtk_container_add(GTK_CONTAINER(pMainWindow),vbox);
    GtkWidget* menubar=gtk_menu_bar_new();
    gtk_box_pack_start(GTK_BOX(vbox),menubar,FALSE,TRUE,0);
    GtkWidget* file_menu=gtk_menu_new();
    GtkWidget* File_Item=gtk_menu_item_new_with_label("File");
    GtkWidget* Load_item=gtk_menu_item_new_with_label("Open");
    gtk_menu_shell_append (GTK_MENU_SHELL (file_menu), Load_item);
    gtk_menu_item_set_submenu (GTK_MENU_ITEM (File_Item), file_menu);
    gtk_menu_shell_append (GTK_MENU_SHELL (menubar), File_Item);

    GtkWidget* pListView = Widget::getListView();
    createModel(pListView);
    MainWindow::appendColumn2Listview(pListView, "Time", 0);
    MainWindow::appendColumn2Listview(pListView, "PID", 1);
    MainWindow::appendColumn2Listview(pListView, "TID", 2);
    MainWindow::appendColumn2Listview(pListView, "Level", 3);
    MainWindow::appendColumn2Listview(pListView, "AppName", 4);
    MainWindow::appendColumn2Listview(pListView, "Body", 5);

    gtk_container_add(GTK_CONTAINER(vbox), pListView);
    gtk_widget_show_all(pMainWindow);
}

void MainWindow::appendColumn2Listview(GtkWidget *pListview, const char *pTitle, const int order)
{
    GtkCellRenderer* pRenderer = gtk_cell_renderer_text_new();
    GtkTreeViewColumn* pColumn = gtk_tree_view_column_new_with_attributes(pTitle, pRenderer, "text", order, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(pListview), pColumn);
}

void MainWindow::createModel(GtkWidget *pListview)
{
    GtkListStore* store = gtk_list_store_new(
        6,
        G_TYPE_STRING,
        G_TYPE_STRING,
        G_TYPE_STRING,
        G_TYPE_STRING,
        G_TYPE_STRING,
        G_TYPE_STRING
    );

    gtk_tree_view_set_model(GTK_TREE_VIEW(pListview), GTK_TREE_MODEL(store));

    g_object_unref(store);
}
