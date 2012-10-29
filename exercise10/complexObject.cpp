#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "threedObject.h"
#include "complexObject.h"


/**
 *    A cubeObject is a threedObject...
 */
 
cubeObject::cubeObject(const char* sName, int m, float d)
:   threedObject(sName, m, d)
{
    // ctor
    add_point( -10, -10, -10 ); // 0
    add_point( -10,  10, -10 ); // 1
    add_point(  10,  10, -10 ); // 2
    add_point(  10, -10, -10 ); // 3

    add_point( -10, -10,  10 ); // 4
    add_point( -10,  10,  10 ); // 5
    add_point(  10,  10,  10 ); // 6
    add_point(  10, -10,  10 ); // 7
    
    add_line( 0, 1 );
    add_line( 1, 2 );
    add_line( 2, 3 );
    add_line( 3, 0 );
    
    add_line( 4, 5 );
    add_line( 5, 6 );
    add_line( 6, 7 );
    add_line( 7, 4 );
    
    add_line( 0 , 4 );
    add_line( 1 , 5 );
    add_line( 2 , 6 );
    add_line( 3 , 7 );
} 

cubeObject::cubeObject(const char* sName, int x, int y, int z, int m, float d)
:   threedObject(sName, m, d)
{
    // ctor
    add_point( -10, -10, -10 );
    add_point( -10,  10, -10 );
    add_point(  10,  10, -10 );
    add_point(  10, -10, -10 );

    add_point( -10, -10,  10 );
    add_point( -10,  10,  10 );
    add_point(  10,  10,  10 );
    add_point(  10, -10,  10 ); 

    add_line( 0, 1 );
    add_line( 1, 2 );
    add_line( 2, 3 );
    add_line( 3, 0 );
    
    add_line( 4, 5 );
    add_line( 5, 6 );
    add_line( 6, 7 );
    add_line( 7, 4 );

    add_line( 0 , 4 );
    add_line( 1 , 5 );
    add_line( 2 , 6 );
    add_line( 3 , 7 );
    
    translate( x, y, z );   
} 

cubeObject::~cubeObject()
{
    // dtor
}

/**
 *    Display threedObjects information along with mass & density
 */
 
void cubeObject::display_info(FILE* ofp, const char* sMsg) const 
{
    printf("==CUBE==\n");
    threedObject::display_info(ofp, sMsg);    // call parent class display_info
    fprintf(ofp, "Mass = %d lbs Density = %f\n", m_mass, m_density);
}
/**
 *    Display threedObjects information along with mass & density
 */
 
void cubeObject::display_info(FILE* ofp) const 
{
    printf("==CUBE==\n");
    threedObject::display_info(ofp);    // call parent class display_info
    fprintf(ofp, "Mass = %d lbs Density = %f\n", m_mass, m_density);
}


/**
 *    A triObject is a threedObject with mass & density...
 */
 
triObject::triObject(const char* sName, int m, float d)
:   threedObject(sName, m, d)
{
    // ctor
    add_point(   0, 50, 0 );
    add_point( -10,  0, 10 );
    add_point( -10,  0, -10 );
    add_point(  10,  0, -10 );
    add_point(  10,  0, 10 );
    
    add_line( 0, 1 );
    add_line( 0, 2 );
    add_line( 0, 3 );
    add_line( 0, 4 );
    add_line( 1, 2 );
    add_line( 2, 3 );
    add_line( 3, 4 );
    add_line( 4, 1 );
} 

triObject::triObject(const char* sName, int x, int y, int z, int m, float d)
:   threedObject(sName, m, d)
{
    // ctor
    add_point(   0, 50, 0 );
    add_point( -10,  0, 10 );
    add_point( -10,  0, -10 );
    add_point(  10,  0, -10 );
    add_point(  10,  0, 10 );
    
    add_line( 0, 1 );
    add_line( 0, 2 );
    add_line( 0, 3 );
    add_line( 0, 4 );
    add_line( 1, 2 );
    add_line( 2, 3 );
    add_line( 3, 4 );
    add_line( 4, 1 );
        
    translate( x, y, z );   
} 

triObject::~triObject()
{
    // dtor
}

/**
 *    Display threedObjects information along with mass & density
 */
 
void triObject::display_info(FILE* ofp, const char* sMsg) const 
{
    printf("==TRI==\n");
    threedObject::display_info(ofp, sMsg);    // call parent class display_info
    fprintf(ofp, "Mass = %d lbs Density = %f\n", m_mass, m_density);
}
/**
 *    Display threedObjects information along with mass & density
 */
 
void triObject::display_info(FILE* ofp) const 
{
    printf("==TRI==\n");
    threedObject::display_info(ofp);    // call parent class display_info
    fprintf(ofp, "Mass = %d lbs Density = %f\n", m_mass, m_density);
}


