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

    GtkWidget* pListView = Widget::getListView();
    create_model(pListView);
    MainWindow::appendColumn2Listview(pListView, "Time", 0);
    MainWindow::appendColumn2Listview(pListView, "PID", 1);
    MainWindow::appendColumn2Listview(pListView, "TID", 2);
    MainWindow::appendColumn2Listview(pListView, "Level", 3);
    MainWindow::appendColumn2Listview(pListView, "AppName", 4);
    MainWindow::appendColumn2Listview(pListView, "Body", 5);

    gtk_container_add(GTK_CONTAINER(pMainWindow), pListView);
    gtk_widget_show_all(pMainWindow);
}

void MainWindow::appendColumn2Listview(GtkWidget *pListView, const char *pTitle, const int order)
{
    GtkCellRenderer* pRenderer = gtk_cell_renderer_text_new();
    GtkTreeViewColumn* pColumn = gtk_tree_view_column_new_with_attributes(pTitle, pRenderer, "text", order, NULL);
    gtk_tree_view_append_column(GTK_TREE_VIEW(pListView), pColumn);
}

void MainWindow::set_data(GtkWidget *pListView)
{
    GtkTreeIter iter;
    GtkListStore* pStore = GTK_LIST_STORE(gtk_tree_view_get_model(GTK_TREE_VIEW(pListView)));
    gtk_list_store_clear(pStore);

    //新しいレコード（３つ）を生成する
    gtk_list_store_append(pStore, &iter);
    gtk_list_store_set(pStore, &iter, 0, "", 1, "", 2, "", 3, "", 4, "", 5, "", -1);
}

void MainWindow::create_model(GtkWidget *treeview)
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

    gtk_tree_view_set_model(GTK_TREE_VIEW(treeview), GTK_TREE_MODEL(store));

    g_object_unref(store);
}