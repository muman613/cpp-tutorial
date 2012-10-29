#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

#include <vector>

/**
 *  This is the d point class.
 */
 
class dpoint {
public:
    dpoint() : m_x(0), m_y(0), m_z(0) {}
    dpoint(int x, int y, int z) : m_x(x), m_y(y), m_z(z) {}
    // overloaded constructor, copy constructor...
    dpoint(const dpoint& copy) : m_x(copy.m_x), m_y(copy.m_y), m_z(copy.m_z) {}

    dpoint& operator = (const dpoint& copy) {
        m_x = copy.m_x;
        m_y = copy.m_y;
        m_z = copy.m_z;

        return *this;   // return a reference pointer to self.
    }
    
    int m_x;
    int m_y;
    int m_z;
};

/*  Define some containers for dpoint */

typedef std::vector<dpoint>                     DPOINT_VECTOR;
typedef std::vector<dpoint>::iterator           DPOINT_VECTOR_ITER;
typedef std::vector<dpoint>::const_iterator     CONST_DPOINT_VECTOR_ITER;

/*  
    Create a line class which can be based on any numerical representation 

    For instance dline<dpoint> or dline<int> or dline<float> ...    
*/

template <class T>
class dline {
public:
    dline() : m_start(-1), m_end(-1) {}
    dline(T start, T end) : m_start(start), m_end(end) {}
    dline(const dline& copy) : m_start(copy.m_start), m_end(copy.m_end) {}

    T m_start;
    T m_end;
};

/*  Line vector of point indexes */
typedef std::vector< dline<size_t> >                    DLINE_VECTOR;
typedef std::vector< dline<size_t> >::iterator          DLINE_VECTOR_ITER;
typedef std::vector< dline<size_t> >::const_iterator    CONST_DLINE_VECTOR_ITER;

#endif	// __GEOMETRY_H__
