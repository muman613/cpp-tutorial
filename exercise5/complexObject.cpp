#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "simpleObject.h"
#include "complexObject.h"


/**
 *	A complexObject is a simpleObject with mass & density...
 */
 
complexObject::complexObject(const char* sName, int x, int y, int z, int w, int h, int m, float d)
:	simpleObject(sName, x, y, z, w, h),
	m_mass(m),
	m_density(d)
{
	// ctor
} 
complexObject::complexObject(int x, int y, int z, int w, int h, int m, float d)
:	simpleObject(x, y, z, w, h),
	m_mass(m),
	m_density(d)
{
	// ctor
}

complexObject::~complexObject()
{
	// dtor
}

/**
 *	Display simpleObjects information along with mass & density
 */
 
void complexObject::display_info(FILE* ofp, const char* sMsg) const 
{
	simpleObject::display_info(ofp, sMsg);	// call parent class display_info
	fprintf(ofp, "Mass = %d lbs Density = %f\n", m_mass, m_density);
}
/**
 *	Display simpleObjects information along with mass & density
 */
 
void complexObject::display_info(FILE* ofp) const 
{
	simpleObject::display_info(ofp);	// call parent class display_info
	fprintf(ofp, "Mass = %d lbs Density = %f\n", m_mass, m_density);
}

/* return the objects mass */
int complexObject::get_mass() const
{
	return m_mass;
}

/* return the objects density */
float complexObject::get_density() const 
{
	return m_density;
}


