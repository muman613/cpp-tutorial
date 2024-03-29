/**
 *	NAME		:	example1.cpp
 *	PURPOSE		:	Sample C++ project to demonstrate simple class.
 *	DATE		:	October 25, 2012
 *	AUTHOR 		:	Michael Uman
 *
 *	NOTE		:	This example shows the use of an externally defined class.
 *
 *					Instantiate 2 objects of class simpleObject, use const, ref
 *					passing, and static member function, sub-classing objects.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simpleObject.h"
#include "complexObject.h"
/**
 *	Main entry point.
 */

int user_x_translate = 50;

int main(int argc, const char* argv[])
{
	/* Get x translation from commandline */
	if (argc == 2) {
		user_x_translate = atoi( argv[1] );
	}
	
	simpleObject	object1(100,100,100);
	simpleObject	object2(50, 50, 50);

	/* Use the new function display_info() to output object information */
	object1.display_info( stdout, "object1" );
	object2.display_info( stdout, "object2" );

	/* check if these objects occupy the same location */
	printf("object1 & object2 %s occupy the same place...\n",
		simpleObject::is_equal( object1, object2)?"DO":"DO NOT");
		
	printf("moving object2 by 50,50,50...\n");
	object2.translate( 50, 50, 50 );

	object2.display_info( stdout, "object2" );
	/* check if these objects occupy the same location */
	printf("object1 & object2 %s occupy the same place...\n",
		simpleObject::is_equal( object1, object2)?"DO":"DO NOT");
	
	printf("\n");
	
	/* Test the new complexObject class */
	complexObject	object3( 20, -10, 30, 15, 15, 8, 0.5 );
	object3.display_info( stdout, "object3" );
	
	/* Attempt to move it out of range!!! */
	
	printf("Translating object3 by %d, 0, 0...\n", user_x_translate);
	if (!object3.translate( user_x_translate, 0, 0 )) {
		printf("Unable to move object3 by 190, 0, 0!\n");
	}
	
	object3.display_info( stdout, "object3" );
	return 0;		
}
