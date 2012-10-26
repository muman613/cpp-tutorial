#ifndef	__COMPLEXOBJECT_H__
#define __COMPLEXOBJECT_H__

#include "simpleObject.h"


/**
 *	A complexObject is a simpleObject with mass & density...
 */
 
class complexObject : public simpleObject {
public:
	complexObject(const char* sName, int x, int y, int z, int width, int height, 
				  int mass, float density);
	complexObject(int x, int y, int z, int width, int height, 
				  int mass, float density);
	~complexObject();

	/* override simpleObjects display_info() function */
	void display_info(FILE* ofp, const char* sMsg) const;
	/* override the overloaded function */
	void display_info(FILE* ofp) const;
	
	int		get_mass() const;
	float	get_density() const;
	
protected:

	int		m_mass;		// Objects mass in lbs
	float	m_density;	// Objects density
};


#endif

