#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simpleObject.h"

/* Class implementation */

simpleObject::simpleObject(const char* sName, int x, int y, int z, int w, int h)
:   m_name(sName),
    m_point(x, y, z),
    m_width(w), m_height(h)
{
    // ctor
}

simpleObject::simpleObject(const char* sName, dpoint point, int w, int h)
:   m_name(sName),
    m_point(point),
    m_width(w), m_height(h)
{
    // ctor
}    

/* default constructor assumes object has dimensions of 20x20 */
simpleObject::simpleObject(int x, int y, int z)
:   m_name(DEFAULT_NAME),    
    m_point(x, y, z),
    m_width(DEFAULT_WIDTH), m_height(DEFAULT_HEIGHT)
{
    // ctor
}

/* overloaded constructor takes width and height as parameters */
simpleObject::simpleObject(int x, int y, int z, int w, int h)
:   m_name(DEFAULT_NAME),
    m_point(x, y, z),
    m_width(w), m_height(h)
{
    // ctor
}

simpleObject::~simpleObject()
{
    // dtor
}

/**
 *    Perform translation if the object will be within range.
 *
 *    Returns true if the object is translated, false if the object would move
 *    out of range.
*/

bool simpleObject::translate(int x_offset, int y_offset, int z_offset)
{
    int        tmpX, tmpY, tmpZ;
    
    tmpX = m_point.m_x + x_offset;
    tmpY = m_point.m_y + y_offset;
    tmpZ = m_point.m_z + z_offset;
    
    /* Make sure the object is within range */
    
    if ((tmpX < MIN_X) || (tmpX > MAX_X))
        return false;
    if ((tmpY < MIN_Y) || (tmpY > MAX_Y))
        return false;
    if ((tmpZ < MIN_Z) || (tmpZ > MAX_Z))
        return false;
        
    m_point.m_x = tmpX;     // Access public member data...
    m_point.m_y = tmpY;
    m_point.m_z = tmpZ;
    
    return true;
}

bool simpleObject::translate_x(int offset)
{
    int tmpX = m_point.m_x + offset;
    
    if ((tmpX < MIN_X) || (tmpX > MAX_X))
        return false;
    m_point.m_x = tmpX;
    
    return true;    
}

bool simpleObject::translate_y(int offset)
{
    int tmpY = m_point.m_y + offset;

    if ((tmpY < MIN_Y) || (tmpY > MAX_Y))
        return false;
    m_point.m_y = tmpY;
    
    return true;
}


bool simpleObject::translate_z(int offset)
{
    int tmpZ = m_point.m_z + offset;
    
    if ((tmpZ < MIN_Z) || (tmpZ > MAX_Z))
        return false;
    m_point.m_z = tmpZ;
    
    return true;    
}


bool simpleObject::move_to(int x, int y, int z)
{
    if ((x < MIN_X) || ( x > MAX_X))
        return false;
    if ((y < MIN_Y) || (y > MAX_Y))
        return false;
    if ((z < MIN_Z) || (z > MAX_Z))
        return false;

    m_point.m_x = x;
    m_point.m_y = y;
    m_point.m_z = z;
    
    return true;
}

void simpleObject::get_position(int& x, int& y, int& z) const
{
    x = m_point.m_x;
    y = m_point.m_y;
    z = m_point.m_z;
}

void simpleObject::get_dimensions(int& w, int& h) const
{
    w = m_width;
    h = m_height;
}


std::string simpleObject::get_name() const {
    return m_name;
}

/**
 *  Display objects parameters...
 */

void simpleObject::display_info(FILE* ofp, const char* sMsg) const
{
    fprintf(ofp, "%s @ %d, %d, %d with dimensions %d X %d\n",
            sMsg, 
            m_point.m_x,
            m_point.m_y,
            m_point.m_z, 
            m_width, m_height);
}

/**
 *  Display objects parameters...
 */
 
void simpleObject::display_info(FILE* ofp) const
{
    fprintf(ofp, "%s @ %d, %d, %d with dimensions %d X %d\n",
            m_name.c_str(), 
            m_point.m_x,
            m_point.m_y,
            m_point.m_z, 
            m_width, m_height);
}

/* static function used to compare two objects */
bool simpleObject::is_equal(simpleObject& a, simpleObject& b) {

    if ((a.m_point.m_x == b.m_point.m_x) &&
        (a.m_point.m_y == b.m_point.m_y) &&
        (a.m_point.m_z == b.m_point.m_z))
        return true;

    return false;
}

/* operator == overload */

bool simpleObject::operator ==(const simpleObject& compare) {
    if ((m_point.m_x == compare.m_point.m_x) &&
        (m_point.m_y == compare.m_point.m_y) &&
        (m_point.m_z == compare.m_point.m_z))
        return true;

    return false;
}

