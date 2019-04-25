#pragma once
#include "Block/Block.h"
#include "Chunk/Chunk.h"
#include <Util/STD_Util.h>
#include <unordered_map>
#include <memory>

class Map
{
public:
	typedef std::unordered_map<Chunk::Location, Chunk::Ptr> ChunksMap;
private:
	ChunksMap m_chunksMap;
public:
	Map() = default;
	void addChunk(Chunk::Position position, Chunk::Ptr chunk);
	void addChunk(Chunk::Position position, bool overrideExisting = false);
	void deleteChunk(Chunk::Position position);

	bool existsAt(Chunk::Position position);
	void update(float dt);

	Chunk* getChunk(int x, int y, int z);
	Chunk* getChunk(Chunk::Position position);

	ChunksMap& getChunksMap();
};