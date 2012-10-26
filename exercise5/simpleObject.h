/**
 *    This file contains the definition of the simpleObject class
 */
 
#ifndef    __SIMPLEOBJECT_H__
#define __SIMPLEOBJECT_H__

#include <string>

/*    Min/Max for 3d space */
#define        MIN_X    -200
#define        MAX_X    200
#define        MIN_Y    -200
#define        MAX_Y    200
#define        MIN_Z    -200
#define        MAX_Z    200

#define     DEFAULT_WIDTH    20
#define        DEFAULT_HEIGHT    20

/* Basic object representing a point in space */

class simpleObject {
public:
    simpleObject(const char* sName, int x, int y, int z, 
                 int w = DEFAULT_WIDTH, int h = DEFAULT_HEIGHT);
    simpleObject(int x, int y, int z);
    simpleObject(int x, int y, int z, int w, int h);    // overloaded constructor
    ~simpleObject();
    
    /* Display object info to file ofp with message sMsg */
    void     display_info(FILE* oFp, const char* sMsg) const;
    void     display_info(FILE* oFp) const;                // overloaded display_info
    
    bool     translate(int x_offset, int y_offset, int z_offset);
    bool     translate_x(int offset);
    bool     translate_y(int offset);
    bool     translate_z(int offset);

    bool     move_to(int x, int y, int z);

    void     get_position(int& x, int& y, int& z) const;
    void     get_dimensions(int& w, int& h) const;
    
    static   bool is_equal(simpleObject& a, simpleObject& b);
    
    std::string get_name() const;
    
    /* Operator overloading demonstrated by this function */
    bool operator == (const simpleObject& compare);
    
protected:
    std::string    m_name;
    int            m_x;
    int            m_y;
    int            m_z;
    int            m_width;
    int            m_height;
};

#endif

