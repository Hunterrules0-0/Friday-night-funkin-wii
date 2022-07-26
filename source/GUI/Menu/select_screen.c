
#include <stdio.h>
#include "../../Common_stuff/colors.h"
#include "../../gfx/guiassets/Selection_Screen/Weeks/Tutorial.h"

int select_screen(GRRLIB_texImg *font){
    //vars
    int bordery;
    GRRLIB_texImg *week0 = GRRLIB_LoadTexture(Tutorial);

    while(1){
        WPAD_ScanPads();
		u32 held = WPAD_ButtonsHeld(0);
        
        //  controls
        if(held & WPAD_BUTTON_HOME){
            GRRLIB_Exit();
			exit(0);

        }

        
        
        //  move black bar
        if(bordery > 799){
        
            printf("black bar is out of viewpoint");
                    usleep(80000);

        }
        else {
        bordery = bordery + 10;  
        GRRLIB_Rectangle(0, bordery, 800, 480, BLACK, 1);
        usleep(80000);

        }
        
        
        //  stuff to render 
        GRRLIB_FillScreen(TAN);


        GRRLIB_Rectangle(0, 297, 800, 190, BLACK, 1);
        GRRLIB_DrawImg(350, 328, week0, 0, 0.45, 0.45, 0xFFFFFFFF);
        
        GRRLIB_Render(); ///render

        

    }

    
}