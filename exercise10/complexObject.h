#ifndef __COMPLEXOBJECT_H__
#define __COMPLEXOBJECT_H__

#include "threedObject.h"


/**
 *    A cubeObject is a threedObject with mass & density...
 */
 
class cubeObject : public threedObject {
public:
    cubeObject(const char* sName, int mass = DEFAULT_WEIGHT, 
               float density = DEFAULT_DENSITY);
    cubeObject(const char* sName, int x, int y, int z,
               int mass = DEFAULT_WEIGHT, float density = DEFAULT_DENSITY);               
    virtual ~cubeObject();

    /* override threedObjects display_info() function */
    void display_info(FILE* ofp, const char* sMsg) const;
    /* override the overloaded function */
    void display_info(FILE* ofp) const;    
};

/**
 *
 */

class triObject : public threedObject {
public:
    triObject(const char* sName, int mass = DEFAULT_WEIGHT, 
              float density = DEFAULT_DENSITY);
    triObject(const char* sName, int x, int y, int z,
               int mass = DEFAULT_WEIGHT, float density = DEFAULT_DENSITY);      
    virtual ~triObject();
    
    /* override threedObjects display_info() function */
    void display_info(FILE* ofp, const char* sMsg) const;
    /* override the overloaded function */
    void display_info(FILE* ofp) const;
    
};


#endif

