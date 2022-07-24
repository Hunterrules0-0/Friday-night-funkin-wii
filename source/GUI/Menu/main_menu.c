/*#############################################
 Friday night funkin wii menu

 written by hunterrules0_0
###############################################*/

#include "../../gfx/guiassets/credits/Mad_duck.h"

#include  "../../gfx/guiassets/Menu/Dancing_gf/gfdancesprites.h"
#include  "../../gfx/guiassets/Menu/Logo/menu.h" //sorry this one dosent include the bumping I could not get it to work
#include "../../Common_stuff/colors.h"
#include  "../../gfx/guiassets/Menu/Background/menuBG.h"
#include <unistd.h>
#include "../../Audio/oggplayer.h"

#include "confirmMenu_ogg.h"






int GotoMenu(GRRLIB_texImg *font){

    GRRLIB_texImg *dancegf1 = GRRLIB_LoadTexture(gfdance1);
    GRRLIB_texImg *dancegf2 = GRRLIB_LoadTexture(gfdance2);
    GRRLIB_texImg *dancegf3 = GRRLIB_LoadTexture(gfdance3);
    GRRLIB_texImg *dancegf4 = GRRLIB_LoadTexture(gfdance4);
    GRRLIB_texImg *dancegf5 = GRRLIB_LoadTexture(gfdance5);
    GRRLIB_texImg *dancegf6 = GRRLIB_LoadTexture(gfdance6);
    GRRLIB_texImg *dancegf7 = GRRLIB_LoadTexture(gfdance7);
    GRRLIB_texImg *dancegf8 = GRRLIB_LoadTexture(gfdance8);
    GRRLIB_texImg *dancegf9 = GRRLIB_LoadTexture(gfdance9);
    GRRLIB_texImg *dancegf10 = GRRLIB_LoadTexture(gfdance10);
    GRRLIB_texImg *dancegf11 = GRRLIB_LoadTexture(gfdance11);
    GRRLIB_texImg *dancegf12 = GRRLIB_LoadTexture(gfdance12);
    GRRLIB_texImg *dancegf13 = GRRLIB_LoadTexture(gfdance13);
    GRRLIB_texImg *dancegf14 = GRRLIB_LoadTexture(gfdance14);
    GRRLIB_texImg *dancegf15 = GRRLIB_LoadTexture(gfdance15);
    GRRLIB_texImg *dancegf16 = GRRLIB_LoadTexture(gfdance16);
    GRRLIB_texImg *dancegf17 = GRRLIB_LoadTexture(gfdance17);
    GRRLIB_texImg *dancegf18 = GRRLIB_LoadTexture(gfdance18);
    GRRLIB_texImg *dancegf19 = GRRLIB_LoadTexture(gfdance19);
    GRRLIB_texImg *dancegf20 = GRRLIB_LoadTexture(gfdance20);

    //logo bump animation
    GRRLIB_texImg *logo_bump = GRRLIB_LoadTexture(menu);
    unsigned char black = 0x0;
    
    int gfdancearray[] = {dancegf1, dancegf2, dancegf3, dancegf4, dancegf5, dancegf6, dancegf7, dancegf8, dancegf9, dancegf9, dancegf10, dancegf11, dancegf12, dancegf13, dancegf14, dancegf15, dancegf16, dancegf17, dancegf18, dancegf19, dancegf20};

    // I know That the header files we included have alot of images here and all the stuff we have to load
    // I cant use a spritesheet for some assets as wiibuilder(the program I use to convert images to headers)
    // will only convert it if its not larger than 1024px. So for some we have to do it image by image. Im sure theres an easier
    // way that I dont know but im not the best programmer and it dosent really matter as the wii can surely handle a few images
    
    int i = 1;
    int a;
    int next_screen = 0;
    int bordery = 800;
    int soundplayed = 0;
    while(1){





            WPAD_ScanPads();
		    u32 held = WPAD_ButtonsHeld(0);
		    
            if(held & WPAD_BUTTON_A){
                next_screen = 1; // start the moving sequence
                switch(soundplayed){
                    case 0 :
                    PlayOgg(confirmMenu_ogg, confirmMenu_ogg_size, 0, OGG_ONE_TIME);
                    soundplayed = 1;

                    break;
                
                }

            }
		    if(held & WPAD_BUTTON_HOME){
                GRRLIB_FreeTexture(font);

                for( a = 10; a < 20; a = a + 1 ){
                    GRRLIB_FreeTexture(gfdancearray[a]);

                }
                GRRLIB_FreeTexture(logo_bump);

            GRRLIB_Exit(); // Be a good boy, clear the memory allocated by GRRLIB
			exit(0);

		    }                
            
            switch(next_screen) { //If the player presses A move the screen and load into the selection screen
                case 1 :
                        if(bordery < 1 ){ bordery = 0; sleep(1); return 0;}else{
                            
                            GRRLIB_FillScreen(black);
                            
                            bordery = bordery - 10;    
                         
                        }      
                    break; 
                case 0 :
                    GRRLIB_FillScreen(black);
                   
                    i = i + 1; // act as a pointer to the next frame.

                    //usleep is like sleep but for numbers below 0.1. because it counts in microseconds
                    usleep(80000);

                    break;
                
            }
            
            
        
            GRRLIB_DrawImg(150, 100, gfdancearray[i], 0, 1, 1, 0xFFFFFFFF);
            
            GRRLIB_DrawImg(-10, 30, logo_bump, 0, 0.45, 0.45, 0xFFFFFFFF);

            GRRLIB_Rectangle(0, bordery, 800, 600, BLACK, 1);


            if (i > 20 || i == 20){i = 0;} // reset after all frames complete.
            GRRLIB_Render(); ///render
            
    }
    
   

}