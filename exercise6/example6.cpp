/**
 *    NAME      :    example1.cpp
 *    PURPOSE   :    Sample C++ project to demonstrate simple class.
 *    DATE      :    October 25, 2012
 *    AUTHOR    :    Michael Uman
 *
 *    NOTE      :    This example shows the use of an externally defined class.
 *
 *                   Instantiate 2 objects of class simpleObject, use const, ref
 *                   passing, and static member function, function overloading,
 *                   sub-classing objects, operator overloading.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simpleObject.h"
#include "complexObject.h"
#include "geometry.h"

/* global variables */
int user_x_translate = 50;

/**
 *    Main entry point.
 */

int main(int argc, const char* argv[])
{
    /* Get x translation from commandline */
    if (argc == 2) {
        user_x_translate = atoi( argv[1] );
    }

    dpoint          point1(100, 100, 100);
    dpoint          point2(50, 50, 50);
    simpleObject    object1("object_1", point1);
    simpleObject    object2("object_2", point2, 10, 10);

    /* Use the new function display_info() to output object information */
    object1.display_info( stdout );
    object2.display_info( stdout );

    printf("\nChecking if objects are equal...\n");

    /* check if these objects occupy the same location */
    printf("object1 & object2 %s occupy the same place...\n",
        (object1 == object2)?"DO":"DO NOT");
        
    printf("moving object2 by 50,50,50...\n");
    object2.translate( 50, 50, 50 );

    object2.display_info( stdout, "object2" );
    /* check if these objects occupy the same location */
    printf("object1 & object2 %s occupy the same place...\n",
        (object1 == object2)?"DO":"DO NOT");
    
    printf("\n");
    
    /* Test the new complexObject class */
    complexObject    object3( "object_3", 20, -10, 30, 15, 15, 8, 0.5 );
    object3.display_info( stdout );
    
    /* Attempt to move it out of range!!! */
    
    printf("Translating object3 by %d, 0, 0...\n", user_x_translate);
    if (!object3.translate( user_x_translate, 0, 0 )) {
        printf("Unable to move object3 by %d, 0, 0!\n", user_x_translate);
    }
    
    object3.display_info( stdout );
    
    return 0;        
}
