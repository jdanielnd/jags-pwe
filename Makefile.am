ACLOCAL_AMFLAGS = -I m4
SUBDIRS = libltdl src

win32:
	make
	mkdir -p win/win32
	cp ./src/.libs/pwexponential.dll ./win/win32
	cp ./src/.libs/pwexponential.dll.a ./win/win32
	cp ./src/.libs/pwexponential.la ./win/win32

win64:
	make
	mkdir -p win/win64
	cp ./src/.libs/pwexponential.dll ./win/win64
	cp ./src/.libs/pwexponential.dll.a ./win/win64
	cp ./src/.libs/pwexponential.la ./win/win64
