ACLOCAL_AMFLAGS = -I m4
SUBDIRS = libltdl src

win32:
	make
	mkdir -p win/win32
	cp ./src/.libs/amoroso.dll ./win/win32
	cp ./src/.libs/amoroso.dll.a ./win/win32
	cp ./src/.libs/amoroso.la ./win/win32

win64:
	make
	mkdir -p win/win64
	cp ./src/.libs/amoroso.dll ./win/win64
	cp ./src/.libs/amoroso.dll.a ./win/win64
	cp ./src/.libs/amoroso.la ./win/win64
