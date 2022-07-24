#include <grrlib.h>

#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#include <wiiuse/wpad.h>

#include "../../gfx/guiassets/credits/Mad_duck.h"
#include "../../gfx/font/Font1.h"





int RenderCredits(GRRLIB_texImg *font){
    time_t start, current;
    double elapsed;
    
    start = time(NULL);

    u32 wpaddown;
    s8 page = 0;
    // Render The Credits
    while(1){
    current = time(NULL);

    elapsed = difftime(current, start);
        
    WPAD_ScanPads();
    wpaddown = WPAD_ButtonsDown(0);

    GRRLIB_FillScreen(0x0);
    

    if (elapsed > 1 && elapsed < 4) {
    
    GRRLIB_Printf(100, 250, font, 0xFFFFFF, 1, "Ninjamuffin Presents");
    }

    if (elapsed > 4 && elapsed < 6)
    {
        GRRLIB_Printf(50, 250, font, 0xFFFFFF, 1, "Ported by Hunterrules0_0");
    }
    if (elapsed > 6 && elapsed < 8){
        GRRLIB_Printf(50, 250, font, 0xFFFFFF, 1, "Friday Night Funkin Wii");
        
    }
    if (elapsed > 8){
        return 0;
    }
    GRRLIB_Render(); 
    
    
    }
}
