#include "common.h"
#include "MainWindow.h"

int main(int argc, char** argv) {
    gtk_init(&argc, &argv);
    MainWindow* main = new MainWindow();
    gtk_main();
    delete main;
    return 0;
}
