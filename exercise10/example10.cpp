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
#include "threedObject.h"
#include "complexObject.h"
#include "geometry.h"
#include "sprite.h"

/* global variables */
int user_x_translate = 5,
    user_y_translate = 5,
    user_z_translate = 5;

/**
 *    Main entry point.
 */

int main(int argc, const char* argv[])
{
    /* Get x translation from commandline */
    if (argc == 4) {
        user_x_translate = atoi( argv[1] );
        user_y_translate = atoi( argv[2] );
        user_z_translate = atoi( argv[3] );
    }

    threedObject*           pNewObject = 0L;
    THREED_OBJECT_VEC       objVec;
    THREED_OBJECT_VEC_ITER  oIter;
    int                     count = 0;
    
    /* Test the new cubeObject class */
    pNewObject = new cubeObject( "cube_1", 5, 0.95 );
    objVec.push_back(pNewObject);
    pNewObject = new cubeObject( "cube_2", 40, 0, 0 );
    objVec.push_back(pNewObject);
    pNewObject = new triObject( "tri_1", 2, 0.67 );
    objVec.push_back(pNewObject);
    
    printf("dumping objects!\n");
    
    for (oIter = objVec.begin() ; oIter != objVec.end() ; oIter++) {
        std::stringstream sMsg;
        
        sMsg << "==object " << count++ << " ==";
        
        printf("%s\n", sMsg.str().c_str());
        
        (*oIter)->display_info( stdout );
    }    

#if 0
    /* test new sprite class */
    
    sprite      mySprite( objVec[2], 
                          user_x_translate, 
                          user_y_translate, 
                          user_z_translate );

    printf("\n\nStarting sprite movement with velocity %d, %d, %d...\n",
           user_x_translate, user_y_translate, user_z_translate);
    
    for (int x = 0 ; x < 10 ; x++) {
        mySprite.move();
        (*mySprite)->display_info(stdout);
    }

    /* free all dynamically allocated objects in vector */
    for (oIter = objVec.begin() ; oIter != objVec.end() ; oIter++) {
        delete (*oIter);
    }
#endif

    return 0;        
}
