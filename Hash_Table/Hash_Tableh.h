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
		std::hash<K> hash_function;
		int hash_index = hash_function(key);
		hash_index = hash_index % Table_Size;


		if (Table[hash_index] == NULL)
		{
			return Table[hash_index] = temp;
		}
		Hash_Node<K, V>* current = Table[hash_index];
		while (current != NULL)
		{
			if (temp->key == current->key)
			{
				return current->value= temp->value;
			}
			else
			{
				if (current->next == nullptr)
				{
					current->next = temp;
				}
				else
				{
					current = current->next;
				}
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

