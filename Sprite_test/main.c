#include <gb/gb.h> 
#include <stdio.h>
#include "Export.c"

void main(){
    UINT8 currentspriteindex = 0; // variable that says what tile ur on
    set_sprite_data(0, 2, Smile); // load smiler into memory (we put 2 since we made 2 tiles)
    set_sprite_tile(0, 0);  // Set it to the first tile
    move_sprite(0, 88, 78); // move th sprite to the middle

    SHOW_SPRITES; // show all sprites

    while(1){ // infinite loop to cycle through sprite tiles
        if (currentspriteindex==0){
            currentspriteindex = 1;
        }
        else{
            currentspriteindex = 0;
        }
        set_sprite_tile(0, currentspriteindex); // Sets to next sprite tile
        delay(1000); // pause so you can see the animation 
        scroll_sprite(0, 10, 0); // moves sprite horizontally each time
    }
}