#include "Map.h"


void Map::addChunk(Chunk::Position position, Chunk::Ptr chunk)
{
	m_chunksMap[position] = std::move(chunk);
}

void Map::addChunk(Chunk::Position position, bool overrideExisting)
{
	auto it = m_chunksMap.find(position);
	if (it == m_chunksMap.end()) {
		m_chunksMap.emplace(position, std::make_unique<Chunk>());
	}
	else if (overrideExisting) {
		it->second = std::make_unique<Chunk>();
	}
}

void Map::deleteChunk(Chunk::Position position)
{
	if (existsInMap(m_chunksMap, position)) {
		m_chunksMap.erase(position);
	}
}

bool Map::existsAt(Chunk::Position position)
{
	return existsInMap(m_chunksMap, position);
}

void Map::update(float dt)
{
	for (auto& chunk : m_chunksMap) {
		chunk.second->update(dt);
	}
}

Chunk* Map::getChunk(int x, int y, int z)
{
	return m_chunksMap.find(Chunk::Position(x, y, z))->second.get();
}

Chunk* Map::getChunk(Chunk::Position position)
{
	return m_chunksMap.find(position)->second.get();
}

Map::ChunksMap& Map::getChunksMap()
{

}
