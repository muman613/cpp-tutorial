/**
 *    NAME      :    example1.cpp
 *    PURPOSE   :    Sample C++ project to demonstrate simple class.
 *    DATE      :    October 25, 2012
 *    AUTHOR    :    Michael Uman
 *
 *    NOTE      :    This example shows the use of an externally defined class.
 *
 *                   Instantiate 2 objects of class threedObject, use const, ref
 *                   passing, and static member function, function overloading,
 *                   sub-classing objects, operator overloading, rtti.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <sstream>
#include <typeinfo>
#include <SDL.h>
#include <SDL_gfxPrimitives.h>
#include <SDL_ttf.h>
#include "threedObject.h"
#include "complexObject.h"
#include "geometry.h"
#include "sprite.h"

/* global variables */
int user_x_translate = 5,
    user_y_translate = 5,
    user_z_translate = 5;


THREED_OBJECT_VEC       objVec;
SDL_Surface*            gSDLSurf = 0L;
TTF_Font*               gTtfFont = 0L;

sprite*                 sprite1 = 0L;
SDL_TimerID             tid = 0;

rect                    vp1(10, 10, 410, 410);
rect                    vp2(420, 10, 820, 410);
rect                    vp3(10, 420, 410, 820);

/* func prototypes */
bool init_graphics();
bool release_graphics();


Uint32 move_callback(Uint32 interval, void* param) {   
    if (sprite1 != 0L) {
        sprite1->move();
    }
    
    return interval;
}

bool init_graphics() {
    if (SDL_Init(SDL_INIT_EVERYTHING) < 0) {
        fprintf(stderr, "ERROR: Unable to initialize SDL library!\n");
        return false;
    }
    
    if ((gSDLSurf = SDL_SetVideoMode(860, 860, 32, SDL_HWSURFACE|SDL_DOUBLEBUF)) == NULL) {
        fprintf(stderr, "ERROR: Unable to allocate a surface!\n");
        return false;
    }
    
    SDL_WM_SetCaption( "exercise10", "exercise10" );
    
    if (TTF_Init() != 0) {
        fprintf(stderr, "ERROR: Unable to initialize TTF library!\n");
        return false;
    }
    
    gTtfFont = TTF_OpenFont("Arial_Bold.ttf", 14);
    if (gTtfFont == NULL) {
        fprintf(stderr, "ERROR: Unable to load text font!\n");
        TTF_Quit();
        return false;
    }
    
    tid = SDL_AddTimer( 1000, move_callback, 0L);
    
    return true;
}

bool release_graphics() {

    if (tid != 0) {
        SDL_RemoveTimer( tid );
    }

    SDL_Quit();
    gSDLSurf = 0L;
}

/**
 *  Draw text at specified location.
 */
 
void render_text(int x, int y, const char* szText) {
    SDL_Surface* text = 0L;
    SDL_Color text_color = { 255, 255, 255 };
    SDL_Rect dst;
    
    dst.x = x; dst.y = y;
    
    text = TTF_RenderText_Solid( gTtfFont, szText, text_color );
    if (text != NULL) {
        SDL_BlitSurface( text, NULL, gSDLSurf, &dst );
    }
    
    return;
}

/**
 *
 */
 
bool draw_rectangle(rect& thisRect, int r, int g, int b) {
    lineRGBA( gSDLSurf, thisRect.m_x1, thisRect.m_y1, thisRect.m_x2, thisRect.m_y1,
        r,g,b, 255);
    lineRGBA( gSDLSurf, thisRect.m_x1, thisRect.m_y2, thisRect.m_x2, thisRect.m_y2,
        r,g,b, 255);
    lineRGBA( gSDLSurf, thisRect.m_x1, thisRect.m_y1, thisRect.m_x1, thisRect.m_y2,
        r,g,b, 255);
    lineRGBA( gSDLSurf, thisRect.m_x2, thisRect.m_y1, thisRect.m_x2, thisRect.m_y2,
        r,g,b, 255);

    lineRGBA( gSDLSurf, (thisRect.m_x1 + (thisRect.m_x2 - thisRect.m_x1) / 2), thisRect.m_y1 + 20,
                        (thisRect.m_x1 + (thisRect.m_x2 - thisRect.m_x1) / 2), thisRect.m_y2 - 20,
                        0, 180, 255, 255); 

    lineRGBA( gSDLSurf, thisRect.m_x1 + 20, (thisRect.m_y1 + (thisRect.m_y2 - thisRect.m_y1) / 2),
                        thisRect.m_x2 - 20, (thisRect.m_y1 + (thisRect.m_y2 - thisRect.m_y1) / 2), 
                        0, 180, 255, 255);                 
    return true;
}

void draw_panes() {

    SDL_FillRect( gSDLSurf, NULL, SDL_MapRGB( gSDLSurf->format, 0, 128, 200) );
    
    draw_rectangle( vp1, 255 ,255, 255 );
    draw_rectangle( vp2, 255 ,255, 255 );
    draw_rectangle( vp3, 255 ,255, 255 );
    
    
    render_text( 12,  12,  "Top"    );
    render_text( 422, 12,  "Front"  );
    render_text( 12,  422, "Left"   );
}


void add_objects_to_vector() {
    threedObject*           pNewObject = 0L;

    pNewObject = new cubeObject( "cube_1", 5, 0.95 );
    objVec.push_back(pNewObject);
    pNewObject = new cubeObject( "cube_2", 40, 30, -10 );
    pNewObject->scale( 1.4 );
    objVec.push_back(pNewObject);
    pNewObject = new triObject( "tri_1", 50, -10, 25, 2, 0.67 );
    objVec.push_back(pNewObject);

    sprite1 = new sprite( objVec[1], 2, 4, -4 );

    return;
}

void dumpObjects() {
    THREED_OBJECT_VEC_ITER  oIter;
    int count = 1;
    
    printf("dumping objects!\n");
    
    for (oIter = objVec.begin() ; oIter != objVec.end() ; oIter++) {
        std::stringstream sMsg;
        
        sMsg << "==object " << count++ << " ==";
        
        printf("%s\n", sMsg.str().c_str());
        
        (*oIter)->display_info( stdout );
    }    

}

void drawObjects() {
    THREED_OBJECT_VEC_ITER  oIter;

    for (oIter = objVec.begin() ; oIter != objVec.end() ; oIter++) {
        threedObject*   pThisObject = *oIter;
        size_t          lCount          = 0,
                        pCount          = 0;
        dpoint          pointA, pointB;
        dline<size_t>   line;
        
        lCount = pThisObject->get_line_count();
        pCount = pThisObject->get_point_count();
        
        for (size_t lIndex = 0 ; lIndex < lCount ; lIndex++) {
            line = pThisObject->line( lIndex );
            pointA = pThisObject->point( line.m_start );
            pointB = pThisObject->point( line.m_end );
            
            /* draw top view */
            
            lineRGBA( gSDLSurf, 
                     vp1.m_x1 + 200 + pointA.m_x, vp1.m_y1 + 200 - pointA.m_z, 
                     vp1.m_x1 + 200 + pointB.m_x, vp1.m_y1 + 200 - pointB.m_z,
                     255, 0, 0, 255 );
           
            /* draw front view */

            lineRGBA( gSDLSurf, 
                     vp2.m_x1 + 200 + pointA.m_x, vp2.m_y1 + 200 - pointA.m_y, 
                     vp2.m_x1 + 200 + pointB.m_x, vp2.m_y1 + 200 - pointB.m_y,
                     255, 0, 0, 255 );
            
            /* draw left view */  

            lineRGBA( gSDLSurf, 
                     vp3.m_x1 + 200 + pointA.m_z, vp3.m_y1 + 200 - pointA.m_y, 
                     vp3.m_x1 + 200 + pointB.m_z, vp3.m_y1 + 200 - pointB.m_y,
                     255, 0, 0, 255 );            
        }
        
        
    }
    
    return;
}

/**
 *    Main entry point.
 */
 
int main(int argc, const char* argv[])
{
    bool                    bDone = false;
    THREED_OBJECT_VEC_ITER  oIter;
    
    if (!init_graphics()) {
        return -10;
    }
    
    add_objects_to_vector();
        
    printf("Hit 'ESC' to exit!\n");
      
    SDL_Event Event;
    
    while (!bDone) {
        draw_panes();
        drawObjects();
        
        while (SDL_PollEvent(&Event)) {
            if (Event.type == SDL_QUIT) {
                bDone = true;
            } else if (Event.type == SDL_KEYUP) {
                char ch = Event.key.keysym.sym;

                switch (ch) {
                case SDLK_ESCAPE:
                    bDone = true;
                    break;
                case SDLK_d:
                    dumpObjects();
                    break;
                }                
            }
        }
        SDL_Flip(gSDLSurf);
    }
    
    release_graphics();

    return 0;        
}
