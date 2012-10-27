#ifndef __COMPLEXOBJECT_H__
#define __COMPLEXOBJECT_H__

#include "simpleObject.h"


/**
 *    A cubeObject is a simpleObject with mass & density...
 */
 
class cubeObject : public simpleObject {
public:
    cubeObject(const char* sName, int mass = DEFAULT_WEIGHT, 
               float density = DEFAULT_DENSITY);
    cubeObject(const char* sName, int x, int y, int z,
               int mass = DEFAULT_WEIGHT, float density = DEFAULT_DENSITY);               
    ~cubeObject();

    /* override simpleObjects display_info() function */
    void display_info(FILE* ofp, const char* sMsg) const;
    /* override the overloaded function */
    void display_info(FILE* ofp) const;    
};

/**
 *
 */

class triObject : public simpleObject {
public:
    triObject(const char* sName, int mass = DEFAULT_WEIGHT, 
              float density = DEFAULT_DENSITY);
    triObject(const char* sName, int x, int y, int z,
               int mass = DEFAULT_WEIGHT, float density = DEFAULT_DENSITY);      
    ~triObject();
    
    /* override simpleObjects display_info() function */
    void display_info(FILE* ofp, const char* sMsg) const;
    /* override the overloaded function */
    void display_info(FILE* ofp) const;
    
};


#endif

