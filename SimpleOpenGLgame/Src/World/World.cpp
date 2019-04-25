#include "World.h"

Block& World::getBlock(int x, int y, int z)
{

}

Block& World::getBlock(Block::Position position)
{

}

void World::setBlock(int x, int y, int z)
{
	Chunk::Location chunkLocation = coordsToChunkLocation(x, y);
	Block::Position blockPosition = coordsToBlockPosition(x, y, z);

}

void World::setBlock(Block::Position position)
{
	return setBlock(position.x, position.y,position.z);
}

Map& World::getMap()
{

}

void World::render()
{

}

void World::update(float dt)
{

}

Chunk * World::getChunk(int chunkX, int chunkY)
{
	return nullptr;
}

Chunk::Location World::coordsToChunkLocation(int x, int y)
{
	return Chunk::Location(x / CHUNK_GRID_WIDTH/*INT*/, y  / CHUNK_GRID_HEIGHT/*INT*/);
}

Block::Position World::coordsToBlockPosition(int x, int y, int z)
{
	return Block::Position(x % CHUNK_GRID_WIDTH/*INT*/, y % CHUNK_GRID_HEIGHT/*INT*/ , z);
}
