# Makefile
# Credits to IanFinlayson
# https://github.com/IanFinlayson
rgb2gba: raw2gba.c
        g++ rgb2gba.c -lX11 -lpthread -o rgb2gba

clean:
	rm -f rgb2gba
