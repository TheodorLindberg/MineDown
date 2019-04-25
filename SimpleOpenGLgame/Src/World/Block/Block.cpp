#include "Block.h"
/*Block id definition
|-------------|------------|--------------------|
|Starting bit | Bit length | Definition			|
|-------------|------------|--------------------|
|      0      |     3      |Block type			|
|-------------|------------|--------------------|
|      3      |     3      | Facing direction   |
|-------------|------------|--------------------|
|	   6      |     1      | Use collision      |
|-------------|------------|--------------------|
|      7      |     1      | Per frame update   |
|-------------|------------|--------------------|
|      8      |    12      | unique id for block|
|-------------|------------|--------------------|
|      20     |    12      |  Block specific    |
|-------------|------------|--------------------|
*/



Block::Block()
	:data(DEFAULT_BLOCK_ID)
{}

Block::Block(Data data)
	: data(data)
{}

bool Block::isCube()
{
	return getBlockType() == BlockType::Cube;
}

bool Block::isHalfBlock()
{
	return getBlockType() == BlockType::HalfBlock;
}

bool Block::isStair()
{
	return getBlockType() == BlockType::Stair;
}

bool Block::isLiquid()
{
	return getBlockType() == BlockType::Liquid;
}

bool Block::isOther()
{
	return getBlockType() == BlockType::Other;
}

#define blockTypeMask 0xF
Block::BlockType Block::getBlockType()
{
	return static_cast<BlockType>(id & blockTypeMask);
}

bool Block::faceNorth()
{
	return getFacingDirection() == Facing::North;
}

bool Block::faceSouth()
{
	return getFacingDirection() == Facing::South;
}

bool Block::faceEast()
{
	return getFacingDirection() == Facing::East;
}

bool Block::faceWest()
{
	return getFacingDirection() == Facing::West;
}

bool Block::faceUpwards()
{
	return getFacingDirection() == Facing::Upwards;
}

bool Block::faceDownwards()
{
	return getFacingDirection() == Facing::Downwards;
}

#define facingDirectionMask 0x7
Block::Facing Block::getFacingDirection()
{
	return static_cast<Facing>(blockFlags1 & facingDirectionMask);
}

#define hasCollisionMask 1 << 4
bool Block::hasCollision()
{
	return blockFlags1 & hasCollisionMask;
}

#define hasPerFramUpdateMask 1 << 5
bool Block::perFrameUpdate()
{
	return blockFlags1 & hasPerFramUpdateMask;
}

#define hasPlayerNearbyUpdateMask 1 << 6
bool Block::playerNearbyUpdate()
{
	return blockFlags1 & hasPlayerNearbyUpdateMask;
}

#define hasTransparencyMask 1 << 7
bool Block::hasTransparency()
{
	return blockFlags1 & hasTransparencyMask;
}


Block::Data Block::getData()
{
	return data;
}

unsigned short Block::getId()
{
	return id;
}

unsigned short Block::getFlags()
{
	return blockFlags;
}

unsigned short Block::getSecondFlag()
{
	return blockFlags2;
}

unsigned int Block::getMetaData()
{
	return metaData;
}

bool Block::blockIsValid()
{
	return data != BLOCK_INVALIDE_ID; ///@todo make this instead check if the block id exists
}

bool Block::blockIsAir()
{
	return data == BLOCK_AIR_ID;
}


