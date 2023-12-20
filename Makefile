FILES =
FILES_TEST = ./test/test.cpp ./core/xmlfile.cpp
HEADER_FILE = ./version.h ./core/Notebook.h 

default:
	make test.exe

test.exe: $(FILES_TEST) $(HEADER_FILE)
	g++ -O3 -Wall -Wextra $(FILES_TEST) -o test.exe

clean:
	del arc_note.exe

clean_test:
	del test.exe
