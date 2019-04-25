#pragma once
#include <vector>

template<typename T, std::size_t width, std::size_t height = width, std::size_t depth = width>
class Vector3D
{
public:
	Vector3D() 
		:
		m_data(m_VOLUME)
	{}
	T & at(int xPos, int yPos, int zPos)
	{
		return m_data[yPos *
			m_AREA + zPos *
			m_SIZE + xPos];
	}

	const T& at(int xPos, int yPos, int zPos) const
	{
		return m_data[yPos *
			m_AREA + zPos *
			m_SIZE + xPos];
	}

	template<typename Vector>
	T& at(const Vector& pos)
	{
		return at(pos.x, pos.y, pos.z);
	}

	template<typename Vector>
	const T& at(const Vector& pos) const
	{
		return at(pos.x, pos.y, pos.z);
	}

	template<typename Vector>
	int getIndex(const Vector& pos)
	{
		return  pos.y *
			m_AREA + pos.z *
			m_SIZE + pos.z;
	}

	std::vector<T>& getRaw()
	{
		return m_data;
	}
private:
	int m_SIZE = width;
	int m_AREA = width * depth;
	int m_VOLUME = m_AREA * height;
	std::vector<T> m_data;
};