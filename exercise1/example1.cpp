/**
 *	NAME		:	example1.cpp
 *	PURPOSE		:	Sample C++ project to demonstrate simple class.
 *	DATE		:	October 25, 2012
 *	AUTHOR 		:	Michael Uman
 *
 *	NOTE		:	This example shows a single class defined and implemented
 *					in a single file.
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <string.h>


/*	Min/Max for 3d space */
#define		MIN_X	-200
#define		MAX_X	200
#define		MIN_Y	-200
#define		MAX_Y	200
#define 	MIN_Z	-200
#define		MAX_Z	200

/* Basic object representing a point in space */

class simpleObject {
public:
	simpleObject(int x, int y, int z);
	~simpleObject();
	
	bool 	translate(int x_offset, int y_offset, int z_offset);
	bool 	translate_x(int offset);
	bool 	translate_y(int offset);
	bool 	translate_z(int offset);

	bool 	move_to(int x, int y, int z);

	void	get_position(int& x, int& y, int& z);
	void	get_dimensions(int& w, int& h);
	
protected:
	int			m_x;
	int			m_y;
	int			m_z;
	int			m_width;
	int			m_height;
};

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

void simpleObject::get_position(int& x, int& y, int& z)
{
	x = m_x;
	y = m_y;
	z = m_z;
}

void simpleObject::get_dimensions(int& w, int& h)
{
	w = m_width;
	h = m_height;
}

/**
 *	Main entry point.
 */

int main()
{
	int				width = 0, 
					height = 0;
	int				x,y,z;
	simpleObject	thisObject(100,100,100);
	

	thisObject.get_position( x, y, z );
	thisObject.get_dimensions( width, height );
	
	printf("thisObject @ %d, %d, %d with dimensions %d X %d\n",
		x,y,z, width, height);

	return 0;		
}
