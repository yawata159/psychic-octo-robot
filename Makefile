all: windowing tagreader mixer

windowing: windowing.c
	gcc `ncurses5-config --cflags` -o windowing windowing.c `ncurses5-config --libs`

tagreader: tagreader.c
	gcc `taglib-config --cflags` -o tagreader tagreader.c `taglib-config --libs` -ltag_c

mixer: mixer.c
	gcc `sdl2-config --cflags` -o mixer mixer.c `sdl2-config --libs` -lSDL2_mixer
