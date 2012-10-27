#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "simpleObject.h"
#include "complexObject.h"


/**
 *    A cubeObject is a simpleObject with mass & density...
 */
 
cubeObject::cubeObject(const char* sName, int m, float d)
:   simpleObject(sName, m, d)
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
} 

cubeObject::cubeObject(const char* sName, int x, int y, int z, int m, float d)
:   simpleObject(sName, m, d)
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
    
    translate( x, y, z );   
} 

cubeObject::~cubeObject()
{
    // dtor
}

/**
 *    Display simpleObjects information along with mass & density
 */
 
void cubeObject::display_info(FILE* ofp, const char* sMsg) const 
{
    printf("==CUBE==\n");
    simpleObject::display_info(ofp, sMsg);    // call parent class display_info
    fprintf(ofp, "Mass = %d lbs Density = %f\n", m_mass, m_density);
}
/**
 *    Display simpleObjects information along with mass & density
 */
 
void cubeObject::display_info(FILE* ofp) const 
{
    printf("==CUBE==\n");
    simpleObject::display_info(ofp);    // call parent class display_info
    fprintf(ofp, "Mass = %d lbs Density = %f\n", m_mass, m_density);
}


/**
 *    A triObject is a simpleObject with mass & density...
 */
 
triObject::triObject(const char* sName, int m, float d)
:   simpleObject(sName, m, d)
{
    // ctor
    add_point(   0, 10, 0 );
    add_point( -10,  0, 10 );
    add_point( -10,  0, -10 );
    add_point(  10,  0, -10 );
    add_point(  10,  0, 10 );
} 

triObject::triObject(const char* sName, int x, int y, int z, int m, float d)
:   simpleObject(sName, m, d)
{
    // ctor
    add_point(   0, 10, 0 );
    add_point( -10,  0, 10 );
    add_point( -10,  0, -10 );
    add_point(  10,  0, -10 );
    add_point(  10,  0, 10 );
    
    translate( x, y, z );   
} 

triObject::~triObject()
{
    // dtor
}

/**
 *    Display simpleObjects information along with mass & density
 */
 
void triObject::display_info(FILE* ofp, const char* sMsg) const 
{
    printf("==TRI==\n");
    simpleObject::display_info(ofp, sMsg);    // call parent class display_info
    fprintf(ofp, "Mass = %d lbs Density = %f\n", m_mass, m_density);
}
/**
 *    Display simpleObjects information along with mass & density
 */
 
void triObject::display_info(FILE* ofp) const 
{
    printf("==TRI==\n");
    simpleObject::display_info(ofp);    // call parent class display_info
    fprintf(ofp, "Mass = %d lbs Density = %f\n", m_mass, m_density);
}


