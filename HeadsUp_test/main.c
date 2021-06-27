#include <gb/gb.h> 
#include "backgroundtileset.c"
#include "backgroundmap.c"
#include <gb/font.h> // loads gbdk font library
#include "windowmap.c"

void main(){
	font_t min_font; // variable to store font
	font_init(); // initializes fonts
	min_font = font_load(font_min); // font_min is the font we are loading from the library, it has 36 tiles
	font_set(min_font); // sets font to font that is in variable min_font that we made earlier

    set_bkg_data(37, 7, Backgroundtileset); // 37 because the min_font is using the first 36 and you don't want the memory to clash, 7 because you have 7 tiles
    set_bkg_tiles(0, 0, 40, 18, backgroundmap); // uses tile set to draw background 20 & 18 because that was the dimensions of our background

	set_win_tiles(0,0,5,1,windowmap); //create a window for the heads up display with the window map
	move_win(7,120); // moves the window so it doesn't cover the whole screen

    SHOW_BKG; //Flags to show stuff
	SHOW_WIN;
    DISPLAY_ON;

	while (1){ // scrolls background
		scroll_bkg(1, 0);
		delay(100);
	}

}