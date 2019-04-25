#pragma once

static constexpr int CHUNK_GRID_WIDTH = 32;
static constexpr int CHUNK_GRID_HEIGHT= 32;
static constexpr int CHUNK_GRID_DEPTH = 10;

static constexpr int CHUNK_BLOCK_COUNT = CHUNK_GRID_WIDTH * CHUNK_GRID_HEIGHT * CHUNK_GRID_DEPTH;

static constexpr float GRID_BLOCK_SIZE = 0.1;
static constexpr float GRID_BLOCK_OFFSET = GRID_BLOCK_SIZE;

static constexpr float CHUNK_WIDTH = GRID_BLOCK_SIZE * CHUNK_GRID_WIDTH;
static constexpr float CHUNK_HEIGHT = GRID_BLOCK_SIZE * CHUNK_GRID_HEIGHT;
static constexpr float CHUNK_DEPTH = GRID_BLOCK_SIZE * CHUNK_GRID_DEPTH;



