/*!
    \file array3D.h
    \brief Contains the definition of a resizable 3D array.
    \author Wojciech Jarosz
    
    CS 73/273 Computational Aspects of Digital Photography C++ basecode.
*/

/* Replace this file with the one that includes your implementations in assignment 1 */

#pragma once

#include <vector>
#include "exceptions.h"

//! Generic, resizable, 3D array class.
template<typename T>
class Array3D
{
public:
	//@{ \name Constructors and destructors
	Array3D();
	Array3D(int sizeX, int sizeY, int sizeZ);
	//@}

	//@{ \name Element access
	T &operator()(int x, int y, int z = 0);
	const T &operator()(int x, int y, int z = 0) const;
	T &operator()(int i);
	const T &operator()(int i) const;
	//@}

	//@{ \name Dimension sizes
	int width() const  { return m_sizeX; }
	int height() const { return m_sizeY; }
	int depth() const  { return m_sizeZ; }

	int size() const  { return m_sizeX * m_sizeY * m_sizeZ; }
	int sizeX() const { return m_sizeX; }
	int sizeY() const { return m_sizeY; }
	int sizeZ() const { return m_sizeZ; }
	//@}

	void resize(int sizeX, int sizeY, int sizeZ, const T &value = T(0));
	void reset(const T &value = T(0));
	void operator=(const T &);

protected:
	std::vector<T> m_data;
	int m_sizeX, m_sizeY, m_sizeZ;
	int m_strideZ;

private:
	Array3D(const Array3D &);              // Copying and assignment
	Array3D &operator=(const Array3D &); // are not implemented
};

template<typename T>
inline Array3D<T>::Array3D():
	m_data(), m_sizeX(0), m_sizeY(0), m_sizeZ(0), m_strideZ(0)
{
	// empty
}

template<typename T>
inline Array3D<T>::Array3D(int sizeX, int sizeY, int sizeZ) :
	m_data(sizeX * sizeY * sizeZ),
	m_sizeX(sizeX), m_sizeY(sizeY), m_sizeZ(sizeZ),
	m_strideZ(sizeX * sizeY)
{
	// empty
}

// ********************************************************//
//               IMPLEMENT THESE FUNCTIONS                 //
// ********************************************************//

template <typename T>
inline T & Array3D<T>::operator()(int i)
{
	return m_data[0]; /*Remove this line*/
	// return the element at location i, where i spans all X, Y, and Z dimensions of the array
	// throw OutOfBoundsException if i is negative or larger than the max index in the array
}

template <typename T>
inline T & Array3D<T>::operator()(int x, int y, int z)
{
	return m_data[0]; /*Remove this line*/
	// Return the value in x,y,z and throw out of bounds if the input is invalid
}

// The next two functions should have the same implementation as the previous two
template <typename T>
inline const T & Array3D<T>::operator()(int i) const
{
	return m_data[0]; /*Remove this line*/
	// Implement me!
}

template <typename T>
inline const T & Array3D<T>::operator()(int x, int y, int z) const
{
	return m_data[0]; /*Remove this line*/
	// Implement me!
}

// ********************************************************//
//               DON'T EDIT BELOW THIS LINE                //
// ********************************************************//

template <typename T>
inline void Array3D<T>::resize(int sizeX, int sizeY, int sizeZ, const T & value)
{
	if (sizeX == m_sizeX && sizeY == m_sizeY && sizeZ == m_sizeZ)
		return;

	m_data.resize(sizeX * sizeY * sizeZ, value);
	m_sizeX = sizeX;
	m_sizeY = sizeY;
	m_sizeZ = sizeZ;
	m_strideZ = m_sizeX*m_sizeY;
}

template <typename T>
inline void Array3D<T>::reset(const T& value)
{
	int sz = size();
	for (int i = 0; i < sz; i++)
		m_data[i] = value;
}

template <typename T>
inline void Array3D<T>::operator=(const T& value)
{
	reset(value);
}