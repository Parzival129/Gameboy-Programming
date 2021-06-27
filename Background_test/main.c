#include <gb/gb.h> 
#include "backgroundtileset.c"
#include "backgroundmap.c"

void main(){
    set_bkg_data(0, 7, Backgroundtileset); // 7 because you have 7 tiles
    set_bkg_tiles(0, 0, 40, 18, backgroundmap); // uses tile set to draw background 20 & 18 because that was the dimensions of our background

    SHOW_BKG; //Flags to show stuff
    DISPLAY_ON;

    
	while(1){
		if(joypad()==J_RIGHT) // If RIGHT is pressed
		{
			scroll_bkg(3, 0);
			delay(100);
		}
		
		if(joypad()==J_LEFT)  // If LEFT is pressed
		{
			scroll_bkg(-3, 0);
			delay(100);
		}
		
		if(joypad()==J_UP)  // If UP is pressed
		{ 
			scroll_bkg(0, -3);
			delay(100);
		}
		
		if(joypad()==J_DOWN)  // If DOWN is pressed
		{ 
			scroll_bkg(0, 3);
			delay(100);
		}
	}
}