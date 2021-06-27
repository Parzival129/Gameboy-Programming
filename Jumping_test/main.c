#include <gb/gb.h> 
#include <stdio.h> 

INT8 playerlocation[2]; // stores two INT8 x & y postition of player
BYTE jumping; // Is player jumping or not?
UINT8 gravity = -2; // gravity
UINT8 currentspeedY; // current speed of player
UINT8 floorYposition = 100; // where the floor is

unsigned char bloke[] = // player sprite
{
  0x7C,0x7C,0xFF,0xFF,0xF6,0xE8,0xFF,0xA4,
  0x7E,0x0E,0x54,0x28,0xAA,0x7C,0x00,0x6C
};

void performantdelay(UINT8 numloops){ // more performace enhancing version of delay() function
    UINT8 i;
    for (i = 0; i < numloops; i++){
        wait_vbl_done();
    }
}

INT8 wouldhitsurface(UINT8 projectedYposition){ // so the player hits the ground
    if (projectedYposition >= floorYposition){
        return floorYposition;
    }
    return -1;
}

void jump(UINT8 spriteid, UINT8 spritelocation[2]){ // function for having player jump
    INT8 possiblesurfaceY;

    if (jumping == 0){
        jumping = 1;
        currentspeedY = 10;
    }
    // work out current speed - effect if gravitation going down
    currentspeedY = currentspeedY + gravity;

    playerlocation[1] = playerlocation[1] - currentspeedY;

    possiblesurfaceY = wouldhitsurface(playerlocation[1]);

    if (possiblesurfaceY > -1){
        jumping = 0; // if the player has hit the surface, stop jumping
        move_sprite(spriteid, playerlocation[0], playerlocation[1]);

    }
    else{
        move_sprite(spriteid, playerlocation[0], spritelocation[1]);
    }

}

void main(){
    set_sprite_data(0, 8, bloke); // define sprite sata

    set_sprite_tile(0,0); // defines the tiles numbers

    playerlocation[0] = 10; // defines player location
    playerlocation[1] = floorYposition;
    jumping = 0;

    move_sprite(0, playerlocation[0], playerlocation[1]);

    DISPLAY_ON; // turns on display
    SHOW_SPRITES;

    while (1){

        if ((joypad() & J_A) || jumping == 1){
            jump(0,playerlocation); // calls jump function
        }

        if (joypad() & J_LEFT){
            playerlocation[0] = playerlocation[0] - 2; // updates play location variable
            move_sprite(0, playerlocation[0], playerlocation[1]); // applies location
        }
        if (joypad() & J_RIGHT){
            playerlocation[0] = playerlocation[0] + 2; // updates play location variable
            move_sprite(0, playerlocation[0], playerlocation[1]); // applies location
        }
        performantdelay(5); // use of wait function
    }
}