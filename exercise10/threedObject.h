/**
 *    This file contains the definition of the threedObject class
 */
 
#ifndef __SIMPLEOBJECT_H__
#define __SIMPLEOBJECT_H__

#include <string>
#include <vector>					// Pull in the STL vector template
#include "geometry.h"               // Get the 3d geometry classes

/*    Min/Max for 3d space */
#define         MIN_X    -200
#define         MAX_X    200
#define         MIN_Y    -200
#define         MAX_Y    200
#define         MIN_Z    -200
#define         MAX_Z    200

/* default parameters */
#define         DEFAULT_NAME        "nameless_object"
#define         DEFAULT_WEIGHT      1
#define         DEFAULT_DENSITY     0.8

class cubeObject;
class triObject;

/* Basic object representing a series of points in space */

class threedObject {
public:
    threedObject(const char* sName, 
                 int mass = DEFAULT_WEIGHT, 
                 float density = DEFAULT_DENSITY);
    threedObject(const char* sName, DPOINT_VECTOR& points);
    threedObject(const threedObject& copy);
    virtual ~threedObject();
        
    /* Display object info to file ofp with message sMsg */
    virtual void    display_info(FILE* oFp, const char* sMsg) const;
    virtual void    display_info(FILE* oFp) const;          // overloaded display_info
    
    bool    translate(int x_offset, int y_offset, int z_offset);
    bool    translate_x(int offset);
    bool    translate_y(int offset);
    bool    translate_z(int offset);

    bool    scale(float pct);
    
    static bool is_equal(threedObject& a, threedObject& b);
    
    std::string get_name()          const;
    size_t      get_point_count()   const;
    size_t      get_line_count()    const;
    int         get_mass()          const;
    float       get_density()       const;

    /* Operator overloading demonstrated by this function */
    bool operator == (const threedObject& compare);
    
    
    const dpoint&       point(size_t index) const;
    const dline<size_t> line(size_t index) const;
    
protected:
    friend class cubeObject;
    friend class triObject;
    
    /* functions to add points to object */
    void    add_point(int x, int y, int z);
    void    add_point(dpoint& point);
    
    bool    add_line(size_t start, size_t end);
    
    std::string     m_name;     ///< Objects name
    DPOINT_VECTOR   m_points;   ///< Vector of dpoints
    DLINE_VECTOR    m_lines;    ///< Vector of lines
    
    int             m_mass;     ///< Objects mass in lbs
    float           m_density;  ///< Objects density        
    
};

typedef std::vector<threedObject*>           THREED_OBJECT_VEC;
typedef std::vector<threedObject*>::iterator THREED_OBJECT_VEC_ITER;


#endif

