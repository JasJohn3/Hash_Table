#pragma once
#ifndef HASH_H
#define HASH_H
#include <iostream>

template <typename K, typename V>
struct Hash_Node
{
	V value;
	K key;

	Hash_Node(K key, V value)
	{
		this->key = key;
		this->value = value;
	}
};
template <typename K, typename V>
class Hash_Table
{
private:
	Hash_Node<K, V> **Table;
	//sets the initial size of the Hash Map
	int Table_Size;
	//stores the current size
	int size;

	Hash_Node<K, V> *dummy;
public:
	Hash_Table()
	{
		Table = new Hash_Node<K, V>*[Table_Size];
	}
	void insert(const K & key, const V & value)
	{
		Hash_Node<K, V> * temp = new Hash_Node<K, V>(key, value);

		//apply hash function to the index of the inserting key and value pair
		int hash_index = hash_code(key);

	}
	~Hash_Table()
	{
		
	}
};

//reference
//https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250
#endif

