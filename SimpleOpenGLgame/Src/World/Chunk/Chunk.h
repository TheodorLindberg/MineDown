#pragma once
#include <glm/glm.hpp>
#include <memory>
#include <cassert>

#include "ChunkConfig.h"
#include "World/Block/Block.h"
#include "Util/Vector3D.h"
class Chunk
{
public:
	typedef glm::vec<2, int> Location;
	typedef std::unique_ptr<Chunk> Ptr;
	typedef Vector3D<Block, CHUNK_GRID_WIDTH, CHUNK_GRID_HEIGHT, CHUNK_GRID_DEPTH> Blocks;

	Chunk(Location worldPosition);
	
	void update(float dt);
	
	void setBlock(Block::Position position, Block block);
	void setBlock(int x, int y, int z, Block block);

	Block& getBlock(Block::Position position);
	Block& getBlock(int x, int y, int z);

	
private:
	Location m_worldPosition;
	Blocks m_blockData;
};