#pragma once
#include <unordered_map>

template <typename Key, typename Value>
bool existsInMap(const std::unordered_map<Key, Value>& m, const Key& toFind)
{
	return m.find(toFind) != m.end();
}
