#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "threedObject.h"

/* Class implementation */

threedObject::threedObject(const char* sName, int m, float d)
:   m_name(sName),
    m_mass(m),
    m_density(d)
{
    // ctor
}

threedObject::threedObject(const char* sName, DPOINT_VECTOR& points)
:   m_name(sName),
    m_points(points)
{
    // ctor
}    

threedObject::threedObject(const threedObject& copy)
:   m_name(copy.m_name),
    m_points(copy.m_points),
    m_lines(copy.m_lines)
{
    // copy contructor
}

threedObject::~threedObject()
{
    // dtor
}

void threedObject::add_point(int x, int y, int z) {
    m_points.push_back(dpoint(x,y,z));
}

void threedObject::add_point(dpoint& point) {
    m_points.push_back(point);
}

/**
 *  Add a line to the object.
 */
 
bool threedObject::add_line(size_t start, size_t end) {
    bool        bRes      = false;
    size_t      lastPoint = m_points.size();

    if (lastPoint > 0) {
        if ((start < lastPoint) && (end < lastPoint)) {
            m_lines.push_back( dline<size_t>( start, end ) );
            bRes = true;
        }
    }    
    
    return bRes;
}

/**
 *    Perform translation if the object will be within range.
 *
 *    Returns true if the object is translated, false if the object would move
 *    out of range.
*/

bool threedObject::translate(int x_offset, int y_offset, int z_offset)
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

bool threedObject::translate_x(int offset)
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

bool threedObject::translate_y(int offset)
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


bool threedObject::translate_z(int offset)
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

std::string threedObject::get_name() const {
    return m_name;
}

/*  Return # of points in vector */
size_t threedObject::get_point_count() const {
    return m_points.size();
}

const dpoint& threedObject::point(size_t index) const {
    return m_points[index];
}

const dline<size_t> threedObject::line(size_t index) const {
    return m_lines[index];
}

/* Return # of lines in vector */
size_t threedObject::get_line_count() const {
    return m_lines.size();
}

/* return the objects mass */
int threedObject::get_mass() const
{
    return m_mass;
}

/* return the objects density */
float threedObject::get_density() const 
{
    return m_density;
}

/**
 *  Display objects parameters...
 */

void threedObject::display_info(FILE* ofp, const char* sMsg) const
{
    CONST_DPOINT_VECTOR_ITER    dIter;
    CONST_DLINE_VECTOR_ITER     lIter;
    int                         pIndex = 0,
                                lIndex = 0;
    
    fprintf(ofp, "%s : %s\n", m_name.c_str(), sMsg);
    fprintf(ofp, "%s : has %d points\n", m_name.c_str(), (int)m_points.size());
    for (dIter = m_points.begin() ; dIter != m_points.end() ; dIter++) {
        fprintf(ofp,
                "%3d     %+2d, %+2d, %+2d\n",
                pIndex++,
                (*dIter).m_x,
                (*dIter).m_y,
                (*dIter).m_z);
    }
    fprintf(ofp, "%s : has %d lines\n", m_name.c_str(), (int)m_lines.size());
    
    for (lIter = m_lines.begin() ; lIter != m_lines.end() ; lIter++) {
        fprintf(ofp,
                "%3d     %d -> %d\n", 
                lIndex++,
                (int)(*lIter).m_start, 
                (int)(*lIter).m_end);
    }
}

/**
 *  Display objects parameters...
 */
 
void threedObject::display_info(FILE* ofp) const
{
    CONST_DPOINT_VECTOR_ITER    dIter;
    CONST_DLINE_VECTOR_ITER     lIter;
    int                         pIndex = 0,
                                lIndex = 0;
    
    fprintf(ofp, "%s : has %d points\n", m_name.c_str(), (int)m_points.size());

    for (dIter = m_points.begin() ; dIter != m_points.end() ; dIter++) {
        fprintf(ofp,
                "%3d     %+2d, %+2d, %+2d\n",
                pIndex++,
                (*dIter).m_x,
                (*dIter).m_y,
                (*dIter).m_z);
    }
    fprintf(ofp, "%s : has %d lines\n", m_name.c_str(), (int)m_lines.size());
    
    for (lIter = m_lines.begin() ; lIter != m_lines.end() ; lIter++) {
        fprintf(ofp,
                "%3d     %d -> %d\n", 
                lIndex++,
                (int)(*lIter).m_start, 
                (int)(*lIter).m_end);
    }
}

/* static function used to compare two objects */
bool threedObject::is_equal(threedObject& a, threedObject& b) {
    return (a == b);    // Use overloaded operator ==
}

/* operator == overload */

bool threedObject::operator ==(const threedObject& compare) {
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

bool threedObject::scale(float pct) {
    DPOINT_VECTOR_ITER  dIter;
    DPOINT_VECTOR       newVector;
    
    /* 1st make sure that the translate will not move object out of range */
    for (dIter = m_points.begin() ; dIter != m_points.end() ; dIter++) {
        int        tmpX, tmpY, tmpZ;

        
        tmpX = (*dIter).m_x * pct;
        tmpY = (*dIter).m_y * pct;
        tmpZ = (*dIter).m_z * pct;

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

