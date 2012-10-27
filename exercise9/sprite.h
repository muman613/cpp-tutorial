#ifndef __SPRITE_H__
#define __SPRITE_H__

#include "simpleObject.h"

class sprite {
public:
    sprite( simpleObject* pObj, int xvel, int yvel, int zvel )
    : m_object(pObj), 
      m_xvel(xvel), m_yvel(yvel), m_zvel(zvel)
    {
        // ctor
    }
    ~sprite()
    {
        // dtor
    }
    
    void            change_vel(int xvel, int yvel, int zvel) 
    {
        m_xvel = xvel;
        m_yvel = yvel;
        m_zvel = zvel;
    }
    
    void            move() 
    {
        m_object->translate( m_xvel, m_yvel, m_zvel );
    }
    
    simpleObject*   operator *() const 
    {
        return m_object;
    }
    
protected:
    simpleObject*   m_object;
    int             m_xvel;
    int             m_yvel;
    int             m_zvel;    
};

#endif // __SPRITE_H__

