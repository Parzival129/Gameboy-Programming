#include <gb/gb.h>  //Angle brackets check the compiler's include folders
#include "Meta-Sprite.c" //double quotes check the folder of the code that's being compiled

// https://gbdev.gg8.se/wiki/articles/GBDK_Sprite_Tutorial

void main(){
	SPRITES_8x16; // Tells GBDK to load two 8x8 sprites at once, making one 8x16 tile
	set_sprite_data(0, 8, smile); // Starting at 0, push eight 8x8 tiles from the 'smile' array into running sprite data
	set_sprite_tile(0, 0); // Set tile 0 to whatever sprite number 0 in sprite data
	move_sprite(0, 75, 75); // move sprite 0 to these coordinates

    set_sprite_tile(1, 2); // also shows other side of face
    move_sprite(1, 75 + 8, 75); // puts other side of face next to the first
	SHOW_SPRITES; // show sprites

    // ANIMATION

    while (1){
        set_sprite_tile(1, 6); // switches sprite 1 (aka other side of face) from 6 to 2 causing animation
		delay(500);
		set_sprite_tile(1,2);
		delay(500);
    }
    

}