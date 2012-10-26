#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simpleObject.h"

/* Class implementation */

simpleObject::simpleObject(const char* sName, int x, int y, int z, int w, int h)
:   m_name(sName),
    m_x(x), m_y(y), m_z(z),
    m_width(w), m_height(h)
{
    // ctor
}    

/* default constructor assumes object has dimensions of 20x20 */
simpleObject::simpleObject(int x, int y, int z)
:   m_name("unknown"),    
    m_x(x), m_y(y), m_z(z),
    m_width(DEFAULT_WIDTH), m_height(DEFAULT_HEIGHT)
{
    // ctor
}

/* overloaded constructor takes width and height as parameters */
simpleObject::simpleObject(int x, int y, int z, int w, int h)
:   m_name("unknown"),
    m_x(x), m_y(y), m_z(z),
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
    
    tmpX = m_x + x_offset;
    tmpY = m_y + y_offset;
    tmpZ = m_z + z_offset;
    
    /* Make sure the object is within range */
    
    if ((tmpX < MIN_X) || (tmpX > MAX_X))
        return false;
    if ((tmpY < MIN_Y) || (tmpY > MAX_Y))
        return false;
    if ((tmpZ < MIN_Z) || (tmpZ > MAX_Z))
        return false;
        
    m_x = tmpX;
    m_y = tmpY;
    m_z = tmpZ;
    
    return true;
}

bool simpleObject::translate_x(int offset)
{
    int tmpX = m_x + offset;
    
    if ((tmpX < MIN_X) || (tmpX > MAX_X))
        return false;
    m_x = tmpX;
    
    return true;    
}

bool simpleObject::translate_y(int offset)
{
    int tmpY = m_y + offset;
    
    if ((tmpY < MIN_Y) || (tmpY > MAX_Y))
        return false;
    m_y = tmpY;
    
    return true;
}


bool simpleObject::translate_z(int offset)
{
    int tmpZ = m_z + offset;
    
    if ((tmpZ < MIN_Z) || (tmpZ > MAX_Z))
        return false;
    m_z = tmpZ;
    
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

    m_x = x;
    m_y = y;
    m_z = z;
    
    return true;
}

void simpleObject::get_position(int& x, int& y, int& z) const
{
    x = m_x;
    y = m_y;
    z = m_z;
}

void simpleObject::get_dimensions(int& w, int& h) const
{
    w = m_width;
    h = m_height;
}


std::string simpleObject::get_name() const {
    return m_name;
}

void simpleObject::display_info(FILE* ofp, const char* sMsg) const
{
    fprintf(ofp, "%s @ %d, %d, %d with dimensions %d X %d\n",
            sMsg, m_x,m_y,m_z, m_width, m_height);
}

void simpleObject::display_info(FILE* ofp) const
{
    fprintf(ofp, "%s @ %d, %d, %d with dimensions %d X %d\n",
            m_name.c_str(), m_x,m_y,m_z, m_width, m_height);
}

/* static function used to compare two objects */
bool simpleObject::is_equal(simpleObject& a, simpleObject& b) {

    if ((a.m_x == b.m_x) &&
        (a.m_y == b.m_y) &&
        (a.m_z == b.m_z))
        return true;

    return false;
}

/* operator == overload */

bool simpleObject::operator ==(const simpleObject& compare) {
    if ((m_x == compare.m_x) &&
        (m_y == compare.m_y) &&
        (m_z == compare.m_z))
        return true;

    return false;
}

