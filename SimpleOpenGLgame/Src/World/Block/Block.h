#pragma once

#include <vector>
#include <iostream>
#include <glm/glm.hpp>
/*Block id definition
|--------|---------------------|--------------------|
|  Bits  | Definition          | More               |
|--------|---------------------|--------------------|
|  0-3   | Block type          |                    |  //Id
|--------|---------------------|--------------------|
|  4-15  | Unique id           |                    |  // Id
|--------|---------------------|--------------------|
| 16-18  | Facing direction    |                    |  // Block flags
|--------|---------------------|--------------------|
| 19     | Use collision       |                    |  // Block flags
|--------|---------------------|--------------------|
| 20     | Updates per frame   |                    |  // Block flags
|--------|---------------------|--------------------|
|   21   | Updates when player | is close by        |  //Block flags
|--------|---------------------|--------------------|
| 22     | Has transparency    |                    |  //Block flags
|--------|---------------------|--------------------|
|  23    | nothing             |                    | //Block flags
|--------|---------------------|--------------------|
|  24-31 | Block specific      |                    |  //Block flags
|--------|---------------------|--------------------|
| 32-63  | Metadata for block  |Different for blocks| //Metadata
|--------|---------------------|--------------------|

*/
#define BLOCK_INVALIDE_ID 0x000000
#define BLOCK_AIR_ID 0xE001
#define DEFAULT_BLOCK_ID BLOCK_AIR_ID

class Block
{
public:
	typedef glm::vec<3, int> Position;
	typedef std::uint64_t Data;

	enum class BlockType : unsigned char//4 bits max
	{
		Cube,
		HalfBlock,
		Stair,
		Liquid,

		Air = 14, //Don't render
		Other = 15, //Use block specific renderer/model to render
	};
	enum class Facing : unsigned char//3 bits max
	{
		North = 0,
		South,
		East,
		West,
		Upwards,
		Downwards,
	};
private:
	union 
	{
		struct {
			Data data;
		};
		struct {
			unsigned short id;
			unsigned char blockFlags1;
			unsigned char blockFlags2;

			unsigned char metaData1;
			unsigned char metaData2;
			unsigned char metaData3;
			unsigned char metaData4;

		};
		struct {
			unsigned short id;
			unsigned short blockFlags;
			unsigned int metaData;

		};
	};
public:
	Block();
	Block(Data data);

	//Block type
	bool isCube();
	bool isHalfBlock();
	bool isStair();
	bool isOther();
	bool isLiquid();
	BlockType getBlockType();

	//Facing direction
	bool faceNorth();
	bool faceSouth();
	bool faceEast();
	bool faceWest();
	bool faceUpwards();
	bool faceDownwards();
	Facing getFacingDirection();

	//Other info
	bool hasCollision();
	bool perFrameUpdate();
	bool playerNearbyUpdate();
	bool hasTransparency();
	//One more can be added

	//Getters for data
	Data getData();
	unsigned short getId();
	unsigned short getFlags();
	unsigned short getSecondFlag();
	unsigned int getMetaData();
	

	bool blockIsValid();
	bool blockIsAir();

};
//additional 
