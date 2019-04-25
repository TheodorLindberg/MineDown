#include "Chunk.h"
#include <iostream>

Chunk::Chunk(Chunk::Location worldPosition)
	: m_worldPosition(worldPosition)
{
}

void Chunk::setBlock(Block::Position position, Block value)
{
	setBlock(position.x, position.y, position.z, value);
}

void Chunk::setBlock(int x, int y, int z, Block value)
{
	assert(x > 0 || x < CHUNK_GRID_WIDTH);
	assert(y > 0 || y < CHUNK_GRID_HEIGHT);
	assert(z > 0 || z < CHUNK_GRID_DEPTH);

	m_blockData.at(x,y,z) = value;

}

Block& Chunk::getBlock(Block::Position position)
{
	return getBlock(position.x, position.y, position.z);
}

Block& Chunk::getBlock(int x, int y, int z)
{
	assert(x > 0 || x < CHUNK_GRID_WIDTH);
	assert(y > 0 || y < CHUNK_GRID_HEIGHT);
	assert(z > 0 || z < CHUNK_GRID_DEPTH);

	return m_blockData.at(x,y,z);
}


