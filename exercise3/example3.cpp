/**
 *	NAME		:	example1.cpp
 *	PURPOSE		:	Sample C++ project to demonstrate simple class.
 *	DATE		:	October 25, 2012
 *	AUTHOR 		:	Michael Uman
 *
 *	NOTE		:	This example shows the use of an externally defined class.
 *
 *					Instantiate 2 objects of class simpleObject, use const, ref
 *					passing, and static member function.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simpleObject.h"

/**
 *	Print out information about object.
 */
 
void display_object_info(const char* objName, const simpleObject& thisObject)
{
	int				width = 0, 
					height = 0;
	int				x,y,z;

	thisObject.get_position( x, y, z );
	thisObject.get_dimensions( width, height );
	
	printf("%s @ %d, %d, %d with dimensions %d X %d\n",
		objName, x,y,z, width, height);

	return;
}

/**
 *	Main entry point.
 */

int main()
{
	simpleObject	object1(100,100,100);
	simpleObject	object2(50, 50, 50);

	display_object_info( "object1", object1 );
	display_object_info( "object2", object2 );

	/* check if these objects occupy the same location */
	printf("object1 & object2 %s occupy the same place...\n",
		simpleObject::is_equal( object1, object2 )?"DO":"DO NOT");
		
	printf("moving object2 by 50,50,50...\n");
	object2.translate( 50, 50, 50 );

	display_object_info( "object2", object2 );
	/* check if these objects occupy the same location */
	printf("object1 & object2 %s occupy the same place...\n",
		simpleObject::is_equal( object1, object2 )?"DO":"DO NOT");
		
	return 0;		
}

