#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "simpleObject.h"

/* Class implementation */

simpleObject::simpleObject(const char* sName)
:   m_name(sName)
{
    // ctor
}

simpleObject::simpleObject(const char* sName, DPOINT_VECTOR& points)
:   m_name(sName),
    m_points(points)
{
    // ctor
}    

simpleObject::simpleObject(const simpleObject& copy)
:   m_name(copy.m_name),
    m_points(copy.m_points)
{
    // copy contructor
}

simpleObject::~simpleObject()
{
    // dtor
}

void simpleObject::add_point(int x, int y, int z) {
    m_points.push_back(dpoint(x,y,z));
}

void simpleObject::add_point(dpoint& point) {
    m_points.push_back(point);
}

/**
 *    Perform translation if the object will be within range.
 *
 *    Returns true if the object is translated, false if the object would move
 *    out of range.
*/

bool simpleObject::translate(int x_offset, int y_offset, int z_offset)
{
    DPOINT_VECTOR_ITER  dIter;
    DPOINT_VECTOR       newVector;
    
    /* 1st make sure that the translate will not move object out of range */
    for (dIter = m_points.begin() ; dIter != m_points.end() ; dIter++) {
        int        tmpX, tmpY, tmpZ;

        
        tmpX = (*dIter).m_x + x_offset;
        tmpY = (*dIter).m_y + y_offset;
        tmpZ = (*dIter).m_z + z_offset;

        if ((tmpX < MIN_X) || (tmpX > MAX_X))
            return false;
        if ((tmpY < MIN_Y) || (tmpY > MAX_Y))
            return false;
        if ((tmpZ < MIN_Z) || (tmpZ > MAX_Z))
            return false;    

        newVector.push_back(dpoint( tmpX, tmpY, tmpZ ));
    }

    /* Now copy newVector to m_points */
    m_points = newVector;

    return true;
}

bool simpleObject::translate_x(int offset)
{
    DPOINT_VECTOR_ITER  dIter;
    DPOINT_VECTOR       newVector;
    
    /* 1st make sure that the translate will not move object out of range */
    for (dIter = m_points.begin() ; dIter != m_points.end() ; dIter++) {
        int        tmpX, tmpY, tmpZ;

        
        tmpX = (*dIter).m_x + offset;
        tmpY = (*dIter).m_y;
        tmpZ = (*dIter).m_z;

        if ((tmpX < MIN_X) || (tmpX > MAX_X))
            return false;

        newVector.push_back(dpoint( tmpX, tmpY, tmpZ ));
    }

    /* Now copy newVector to m_points */
    m_points = newVector;
    
    return true;    
}

bool simpleObject::translate_y(int offset)
{
    DPOINT_VECTOR_ITER  dIter;
    DPOINT_VECTOR       newVector;
    
    /* 1st make sure that the translate will not move object out of range */
    for (dIter = m_points.begin() ; dIter != m_points.end() ; dIter++) {
        int        tmpX, tmpY, tmpZ;

        
        tmpX = (*dIter).m_x;
        tmpY = (*dIter).m_y + offset;
        tmpZ = (*dIter).m_z;

        if ((tmpY < MIN_Y) || (tmpY > MAX_Y))
            return false;

        newVector.push_back(dpoint( tmpX, tmpY, tmpZ ));
    }

    /* Now copy newVector to m_points */
    m_points = newVector;
    
    return true;
}


bool simpleObject::translate_z(int offset)
{
    DPOINT_VECTOR_ITER  dIter;
    DPOINT_VECTOR       newVector;
    
    /* 1st make sure that the translate will not move object out of range */
    for (dIter = m_points.begin() ; dIter != m_points.end() ; dIter++) {
        int        tmpX, tmpY, tmpZ;

        
        tmpX = (*dIter).m_x;
        tmpY = (*dIter).m_y;
        tmpZ = (*dIter).m_z + offset;

        if ((tmpZ < MIN_Z) || (tmpZ > MAX_Z))
            return false;

        newVector.push_back(dpoint( tmpX, tmpY, tmpZ ));
    }

    /* Now copy newVector to m_points */
    m_points = newVector;
    
    return true;    
}


//bool simpleObject::move_to(int x, int y, int z)
//{
//    if ((x < MIN_X) || ( x > MAX_X))
//        return false;
//    if ((y < MIN_Y) || (y > MAX_Y))
//        return false;
//    if ((z < MIN_Z) || (z > MAX_Z))
//        return false;

//    m_point.m_x = x;
//    m_point.m_y = y;
//    m_point.m_z = z;
//    
//    return true;
//}

std::string simpleObject::get_name() const {
    return m_name;
}

/*  Return # of points in vector */
size_t simpleObject::get_point_count() const {
    return m_points.size();
}

/**
 *  Display objects parameters...
 */

void simpleObject::display_info(FILE* ofp, const char* sMsg) const
{
    CONST_DPOINT_VECTOR_ITER dIter;
    
    fprintf(ofp, "%s : %s\n", m_name.c_str(), sMsg);
    fprintf(ofp, "%s : has %d points\n", m_name.c_str(), (int)m_points.size());

    for (dIter = m_points.begin() ; dIter != m_points.end() ; dIter++) {
        fprintf(ofp,
                "    %+2d, %+2d, %+2d\n",
                (*dIter).m_x,
                (*dIter).m_y,
                (*dIter).m_z);
    }
}

/**
 *  Display objects parameters...
 */
 
void simpleObject::display_info(FILE* ofp) const
{
    CONST_DPOINT_VECTOR_ITER dIter;
    
    fprintf(ofp, "%s : has %d points\n", m_name.c_str(), (int)m_points.size());

    for (dIter = m_points.begin() ; dIter != m_points.end() ; dIter++) {
        fprintf(ofp,
                "    %+2d, %+2d, %+2d\n",
                (*dIter).m_x,
                (*dIter).m_y,
                (*dIter).m_z);
    }
}

/* static function used to compare two objects */
bool simpleObject::is_equal(simpleObject& a, simpleObject& b) {
    return (a == b);    // Use overloaded operator ==
}

/* operator == overload */

bool simpleObject::operator ==(const simpleObject& compare) {
    size_t      myCount = get_point_count(),
                hisCount = compare.get_point_count();
                   
    /* make sure objects have the same # of points */
    if (myCount != hisCount) {
        return false;
    }
    
    for (size_t index = 0 ; index < myCount ; index++) {
        if ((m_points[index].m_x != compare.m_points[index].m_x) ||
            (m_points[index].m_y != compare.m_points[index].m_y) ||
            (m_points[index].m_z != compare.m_points[index].m_z))
            return false;
    }

    return true;
}

