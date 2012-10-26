#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simpleObject.h"

/* Class implementation */

simpleObject::simpleObject(int x, int y, int z)
:	m_x(x), m_y(y), m_z(z),
	m_width(20), m_height(20)
{
	// ctor
}

simpleObject::~simpleObject()
{
	// dtor
}

/**
 *	Perform translation if the object will be within range.
 *
 *	Returns true if the object is translated, false if the object would move
 *	out of range.
*/

bool simpleObject::translate(int x_offset, int y_offset, int z_offset)
{
	int		tmpX, tmpY, tmpZ;
	
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

/* static function used to compare two objects */
bool simpleObject::is_equal(simpleObject& a, simpleObject& b) {

	if ((a.m_x == b.m_x) &&
	    (a.m_y == b.m_y) &&
	    (a.m_z == b.m_z))
    	return true;

	return false;
}


