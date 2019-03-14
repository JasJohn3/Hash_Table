#pragma once
#ifndef HASH_H
#define HASH_H
#include <iostream>
#include <thread>
#include <string>
#include<cstdlib>
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
	void setTable_Size()
	{
		int user_input;
		std::cout << "What size of Table would you like to create?" << std::endl;
		std::cout << "Enter Size: " << std::flush;
		std::cin >> user_input;
		Table_Size = user_input;
		Table = new Hash_Node<K, V>*[Table_Size];
		for (int i = 0; i < Table_Size; ++i)
		{
			Table[i] = NULL;
		}
	}
	void insert(K  key, V value)
	{

		//apply hash function to the index of the inserting key and value pair
		/*	temporary test function for collision testing
			int hash_index = key % Table_Size;				*/

		
		/*	This is the real hash function for the table.
			std::hash<K> hash_function;
			int hash_index = hash_function(key);
			hash_index = hash_index % Table_Size;			*/
		


		std::hash<K> hash_function;
		int hash_index = hash_function(key);
		//added absolute value.  Hash function can return negative values.
		hash_index = std::abs(hash_index % Table_Size);
		Hash_Node<K, V>* current = Table[hash_index];
		if (current == nullptr)
		{
			Table[hash_index] = new Hash_Node<K, V>(key, value);
		}
		else {

			while (current != nullptr)
			{
				if (current->key == key)
				{
					current->value = value;
					break;
				}
				else if (current->next == nullptr)
				{
					current->next = new Hash_Node<K, V>(key, value);
				}
				current = current->next;

			}
		}






		
	}

		


	V find(K key)
	{

		/*int hash_index = key % Table_Size;*/
		
		std::hash<K> hash_function;
		int hash_index = hash_function(key);
		hash_index = std::abs(hash_index % Table_Size);
		Hash_Node<K,V>* current = Table[hash_index];
		
		while (current != nullptr)
		{
			if (current->key == key)
			{
				std::cout << "Found:" << std::endl;
				std::cout<< "Key: " << current->key << " " << "Value: " << current->value <<std::endl;
			}
			current = current->next;	
		}
		return NULL;
			
	}
	void display()
	{
		for (int i = 0; i < Table_Size; ++i)
		{
			Hash_Node<K, V>* current = Table[i];
			if (Table[i]==NULL)
			{
				continue;
			}
			while (current!=nullptr)
			{
				std::cout << "Index: " << i << " Key: " << current->key << " Value:" << current->value << std::endl;
				current = current->next;
			}
			//std::cout<<"Index: "<<i<<" Key: "<<Table[i]->key<<" Value:"<<Table[i]->value<<std::endl;
		}
	}
	

	~Hash_Table()
	{
		
	}
};

//reference
//https://medium.com/@aozturk/simple-hash-map-hash-table-implementation-in-c-931965904250
#endif

		/*


				if (Table[hash_index] == NULL)
		{
			return Table[hash_index] = temp;
		}
					while (current != NULL)
			{
				previous = current;
				current = current->next;
				if (temp->key == current->key)
				{
					current->value = temp->value;
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
		*/
		/*void Display()
		{


				if (Table[i] == NULL) continue;
				Hash_Node<K, V>* temp = Table[i];

				std::cout <<"Index: "<<i<<" Key: "<< temp->key <<" Value: "<< temp->value << std::endl;

			/*
			do
			{
				std::cout << "Index: " << i << " Key: " << temp->key << " Value: " << temp->value << std::endl;
			} while (Table[i]->next != nullptr);
		}
		*/