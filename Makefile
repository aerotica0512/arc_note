FILES = ./main/winmain.cpp ./core/xmlfile.cpp ./main/init_ui.cpp ./main/wndproc.cpp ./main/ui.cpp
FILES_TEST = ./test/test.cpp ./core/xmlfile.cpp
HEADER_FILE = ./version.h ./core/Notebook.h ./main/init_ui.h ./main/wndproc.h ./main/ui.h

default:
	make arc_note.exe

arc_note.exe: $(FILES) $(HEADER_FILE) ./res/resources.rc Makefile
	windres -i ./res/resources.rc -o ./res/resources.o -r
	g++ -O3 -mwindows -Wall -static $(FILES) ./res/resources.o -o arc_note.exe

test.exe: $(FILES_TEST) $(HEADER_FILE) Makefile
	g++ -O3 -Wall $(FILES_TEST) -o test.exe

clean: arc_note.exe Makefile
	del arc_note.exe

clean_test: test.exe Makefile
	del test.exe
