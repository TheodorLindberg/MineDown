#pragma once
#include "Block/Block.h"
#include "Chunk/Chunk.h"
#include "Map.h"

class World
{
public:
	Block& getBlock(int x, int y, int z);
	Block& getBlock(Block::Position position);

	void setBlock(int x, int y, int z);
	void setBlock(Block::Position position);

	Map& getMap();

	void render();
	void update(float dt);
private:
	Chunk* getChunk(int chunkX, int chunkY);
	Chunk::Location coordsToChunkLocation(int x, int y);
	Block::Position coordsToBlockPosition(int x, int y, int z);
private:
	Map m_map;
	
	
};
