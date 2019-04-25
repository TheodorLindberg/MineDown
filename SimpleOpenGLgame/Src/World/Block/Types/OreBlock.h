#pragma once
#include "../Block.h"

#define packRarity(lower, higher) (higher-lower) << 8 | lower //byte 1 lower procent, byte 2 range
#define oreBitSize 6
#define oreMaxSize 64.f

class OreBlock : public Block
{
public:
	//We only have 6 bits to store information about certain ore amount, but we need much more precision. 
	//since we know the range of each rarity we can compress the 6 bits to a much lower range and therefor get much more precision
	//For example with just 6 bits on the legendary rarity we get steps with just 0.03 procent 
	enum class Rarity : unsigned short
	{
		//Raritys
		SuperCommon = packRarity(50,100), //50% - 100%
		Common      = packRarity(30,70),  //30% - 70%
		Uncommon    = packRarity(10,40),  //10% - 40%
		Rare        = packRarity(5,10),   //5% - 20%
		SuperRare   = packRarity(2, 10),  //2% - 10%
		Epic        = packRarity(0,5),    //0% - 5%
		Legendary   = packRarity(0,2),    //0% - 2% 
		//Other
		Above       = packRarity(50,100), //50% - 100%,
		Under       = packRarity(0,50),   //0% - 50%,
		Middle      = packRarity(25, 75), //25% - 75%
		All         = packRarity(0, 100), //0% - 50%,
		None        = packRarity(0,0),    //0% - 0%
	};
public:
	float convertValueToProcent(unsigned char value, Rarity rarity = Rarity::All) {
		unsigned char lower = static_cast<unsigned char>(rarity); //We just need the first 8 bits
		unsigned char range = static_cast<unsigned short>(rarity) >> 8;    //Convert to 16bits and then move to shift to 8 bits
		return (value / 64.f) * range + lower; //Do the calculation
	}								  

};
