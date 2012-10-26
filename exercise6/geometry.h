#ifndef __GEOMETRY_H__
#define __GEOMETRY_H__

/**
 *  This is the d point class.
 */
 
class dpoint {
public:
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

/*
 *  This is the d line class.
 */
 
class dline {
    dline(dpoint start, dpoint end) : m_start(start), m_end(end) {}
    dline(const dline& copy) : m_start(copy.m_start), m_end(copy.m_end) {}
    
    dpoint m_start;
    dpoint m_end;
};

#endif	// __GEOMETRY_H__
