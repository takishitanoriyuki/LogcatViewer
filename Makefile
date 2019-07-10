CC = gcc
INCLUDE := 	-I/usr/include/gtk-3.0 \
		   	-I/usr/include/at-spi2-atk/2.0 \
			-I/usr/include/at-spi-2.0 \
			-I/usr/include/dbus-1.0 \
			-I/usr/lib/x86_64-linux-gnu/dbus-1.0/include \
			-I/usr/include/gtk-3.0 -I/usr/include/gio-unix-2.0/ \
			-I/usr/include/cairo \
			-I/usr/include/pango-1.0 \
			-I/usr/include/harfbuzz \
			-I/usr/include/pango-1.0 \
			-I/usr/include/atk-1.0 \
			-I/usr/include/cairo \
			-I/usr/include/pixman-1 \
			-I/usr/include/freetype2 \
			-I/usr/include/libpng16 \
			-I/usr/include/freetype2 \
			-I/usr/include/libpng16 \
			-I/usr/include/gdk-pixbuf-2.0 \
			-I/usr/include/libpng16 \
			-I/usr/include/glib-2.0 \
			-I/usr/lib/x86_64-linux-gnu/glib-2.0/include
LIBS :=		-lgtk-3 \
			-lgdk-3 \
			-lpangocairo-1.0 \
			-lpango-1.0 \
			-latk-1.0 \
			-lcairo-gobject \
			-lcairo \
			-lgdk_pixbuf-2.0 \
			-lgio-2.0 \
			-lgobject-2.0 \
			-lglib-2.0 \
			-lstdc++
OPTION :=	-pthread
SRCS := 	main.cpp \
			MainWindow.cpp \
			Widget.cpp
OBJS := 	$(SRCS:.cpp=.o)

LogcatViewer: $(OBJS)
	$(CC) -o $@ $(OBJS) $(LIBS)

main.o: main.cpp \
	common.h \
	MainWindow.h
	$(CC) -o $@ -c main.cpp $(OPTION) $(INCLUDE)

Widget.o: Widget.cpp \
	common.h \
	Widget.h
	$(CC) -o $@ -c Widget.cpp $(OPTION) $(INCLUDE)

MainWindow.o: MainWindow.cpp \
			  common.h \
			  MainWindow.h
	$(CC) -o $@ -c MainWindow.cpp $(OPTION) $(INCLUDE)

clean:
	rm LogcatViewer *.o
