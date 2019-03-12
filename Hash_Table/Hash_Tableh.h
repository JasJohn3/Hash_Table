#pragma once
#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <thread>
#include <string>
template <typename K, typename V>
struct Hash_Node
{
	V value;
	K key;
	Hash_Node<K, V>*next;

	Hash_Node(K key, V value)
	{
		this->key = key;
		this->value = value;
		this->next = nullptr;
	}
};
template <typename K, typename V>
class Hash_Table
{
private:
	Hash_Node<K, V> **Table;
	//sets the initial size of the Hash Map
	int Table_Size = 5;
	//stores the current size
	int size;

	Hash_Node<K, V> *dummy;
public:
	Hash_Table()
	{
		Table = new Hash_Node<K, V>*[Table_Size];
		for (int i = 0; i < Table_Size; ++i)
		{
			Table[i] = NULL;
		}

	}
	void insert(const K & key, const V & value)
	{
		Hash_Node<K, V> * temp = new Hash_Node<K, V>(key, value);

		//apply hash function to the index of the inserting key and value pair
		std::hash<K> string_hash;
		int hash_index = string_hash(key);
		hash_index = hash_index % Table_Size;


		if (Table[hash_index] == NULL)
		{
			Table[hash_index] = temp;
		}
		else { Table[hash_index] = temp->next; }


		current_node = Table[hash_index]
			while (current_node != NULL)
			{
				// if matches overwrite
				// if doesn't match then iterate and not null
				// if at end then store it.
				if (current_node->key )
				{
					Table[hash_index] = temp;
				}
				else
				{
					current_node = temp->next;
				}
			}

	}
	~Hash_Table()
	{
		
	}
};

//reference
//https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250
#endif

