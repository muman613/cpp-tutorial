/**
 *    This file contains the definition of the simpleObject class
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
#define         DEFAULT_WIDTH       20
#define         DEFAULT_HEIGHT      20
#define         DEFAULT_NAME        "nameless_object"

typedef std::vector<dpoint>                     DPOINT_VECTOR;
typedef std::vector<dpoint>::iterator           DPOINT_VECTOR_ITER;
typedef std::vector<dpoint>::const_iterator     CONST_DPOINT_VECTOR_ITER;

/* Basic object representing a series of points in space */

class simpleObject {
public:
    simpleObject(const char* sName);
    simpleObject(const char* sName, DPOINT_VECTOR& points);
    simpleObject(const simpleObject& copy);
    ~simpleObject();
    
    /* functions to add points to object */
    void    add_point(int x, int y, int z);
    void    add_point(dpoint& point);
    
    /* Display object info to file ofp with message sMsg */
    void    display_info(FILE* oFp, const char* sMsg) const;
    void    display_info(FILE* oFp) const;          // overloaded display_info
    
    bool    translate(int x_offset, int y_offset, int z_offset);
    bool    translate_x(int offset);
    bool    translate_y(int offset);
    bool    translate_z(int offset);

    bool    move_to(int x, int y, int z);

    static bool is_equal(simpleObject& a, simpleObject& b);
    
    std::string get_name() const;
    size_t      get_point_count() const;
    
    /* Operator overloading demonstrated by this function */
    bool operator == (const simpleObject& compare);
    
protected:
    std::string     m_name;     ///< Objects name
    DPOINT_VECTOR   m_points;   ///< Vector of dpoints
  //  dpoint          m_point;    ///< Objects location in 3d space
};

#endif

