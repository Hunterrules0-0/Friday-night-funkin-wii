/*===========================================
        FNF WII
    If you like this project dont thank me. thank the people who made the game and donate to them at
    https://www.kickstarter.com/projects/funkin/friday-night-funkin-the-full-ass-game/
    
    I JUST REWRITTEN THE GAME I DID NOT MAKE IT
============================================*/
#include <grrlib.h>

#include <stdlib.h>
#include <wiiuse/wpad.h>
#include <asndlib.h>

#include <stdio.h>

#include "sample_ogg.h"
#include "gfx/guiassets/credits/Mad_duck.h"
#include "gfx/font/Font1.h"
#include "GUI/Credits/Credits.c"
#include "GUI/Menu/main_menu.c"
#include "GUI/Menu/select_screen.c"

#include "Audio/oggplayer.h"
#include "Audio/oggplayer.c"
int main() {
    GRRLIB_Init();
    WPAD_Init();
    ASND_Init();
 	

    // Font texture
    GRRLIB_texImg *text_font1 = GRRLIB_LoadTexture(Font1);
    

    
    GRRLIB_InitTileSet(text_font1, 22, 27, 32);
    
    //GRRLIB_texImg *tex_Duck   = GRRLIB_LoadTexture(Mad_duck);
    PlayOgg(sample_ogg, sample_ogg_size, 1, OGG_INFINITE_TIME);
    // Load the credits
    RenderCredits(text_font1);
    
    //load the menu
    GotoMenu(text_font1);

    select_screen(text_font1);        
}
