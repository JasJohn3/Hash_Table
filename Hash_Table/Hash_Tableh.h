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
	Hash_Node<K, V>*previous;

	Hash_Node(K key, V value)
	{
		this->key = key;
		this->value = value;
		this->next = nullptr;
		this->previous = nullptr;
	}
};
template <typename K, typename V>
class Hash_Table
{
private:
	Hash_Node<K, V> **Table;
	//sets the initial size of the Hash Map
	int Table_Size = 5;


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

		std::hash<K> hash_function;
		int hash_index = hash_function(key);
		//added absolute value.  Hash function can return negative values.
		hash_index = std::abs(hash_index % Table_Size);
		//set a temporary node to our table value
		Hash_Node<K, V>* current = Table[hash_index];
		if (current == nullptr)
		{
			//if the node stored at the tables index value is null, we insert a new node with the key and value pair
			Table[hash_index] = new Hash_Node<K, V>(key, value);
			std::cout << "Insert new head Successful Key: " << key << " Value: " << value << std::endl;
		}
		else {
			//if a node exists in our table, we iterate through the linked list comparing key values
			while (current != nullptr)
			{
				//if the current nodes key value is the same as the key value inserted into our function, we overwrite the value stored in that node
				if (current->key == key)
				{
					
					current->value = value;
					std::cout << "Insert Value Successful Key: " << current->key << " Value: " << current->value << std::endl;
					break;
				}
				//if the current nodes next value is a null pointer, we create a new node at our current->next pointer to a new Node with the key value pair inserted into our function
				else if (current->next == nullptr)
				{
					
					current->next = new Hash_Node<K, V>(key, value);
					Hash_Node<K, V>* temp = current->next;
					temp->previous = current;
					std::cout << "Insert Value Successful Key: " << current->key << " Value: " << current->value << std::endl;
				}
				//iterate to the next node in the list.
				current = current->next;
			}
		}
	}
	void Remove(K key)
	{
		std::hash<K> hash_function;
		//declaring an integer value to store the hash value
		int hash_index = hash_function(key);
		//Modding the hash value by the table size to get a remainder for our index value
		hash_index = std::abs(hash_index % Table_Size);
		//creating a temporary NODE to be able to iterate through our linked list values
		Hash_Node<K,V> * Delete_Node = Table[hash_index];
		
		while (Delete_Node!= NULL)
		{
			//case 1 Top of list
			if (Delete_Node->key==key && Delete_Node->previous == nullptr && Delete_Node->next != nullptr)
			{
				
				Table[hash_index] = Delete_Node->next;
				Delete_Node->next->previous = nullptr;
				delete Delete_Node;
				break;
			}
			//case 2 A Node in the middle of the list
			else if (Delete_Node->key == key && Delete_Node->next!= nullptr && Delete_Node->previous!= nullptr)
			{
				//This reassigns our pointer values to reconnect our List and remove the Current Node found.
				Delete_Node->next->previous = Delete_Node->previous;
				Delete_Node->previous->next = Delete_Node->next;
				delete Delete_Node;
				break;
			}
			//Case 3 the end of the list
			else if (Delete_Node->key == key && Delete_Node->next == nullptr && Delete_Node->previous != nullptr)
			{
				Delete_Node->previous->next = nullptr;
				Delete_Node->previous = nullptr;
				delete Delete_Node;
				break;
			}
			//only one element in the list
			else if (Delete_Node->key == key && Delete_Node->next == nullptr && Delete_Node->previous == nullptr)
			{
				delete Delete_Node;
				Table[hash_index] = NULL;
				break;
			}
			Delete_Node = Delete_Node->next;
		}
	}
		


	bool find(K key)
	{
		bool flag = false;
		/*int hash_index = key % Table_Size;*/
		//implementing the stl library hash function with K type value
		std::hash<K> hash_function;
		//declaring an integer value to store the hash value
		int hash_index = hash_function(key);
		//Modding the hash value by the table size to get a remainder for our index value
		hash_index = std::abs(hash_index % Table_Size);
		//creating a temporary NODE to be able to iterate through our linked list values
		Hash_Node<K,V>* current = Table[hash_index];
		//If the index of the hass is not NULL, begin loop
		while (current != nullptr)
		{
			//compare the value of the current->key to the key value from our find function
			if (current->key == key)
			{
				//standard print function to reveal the values of our list
				std::cout << "Found:" << std::endl;
				std::cout<< "Key: " << current->key << " " << "Value: " << current->value <<std::endl;
				flag = true;
			}
			//this steps to the next value in our linked list
			current = current->next;	
		}
		if (flag == false)
		{
			std::cout << "Key Value Not Found In Table!" << std::endl;
		}
		//had to modify to a bool function because strings cannot be NULL values.
		return flag;
			
	}
	void display()
	{
		//creating a display function to iterate through our list and test structural integrity
		for (int i = 0; i < Table_Size; ++i)
		{
			//create a temporary node value that will allow our function to iterate through our linked list values
			Hash_Node<K, V>* current = Table[i];
			if (Table[i]==NULL)
			{
				//this prevents our function from crashing if there are index values with no elements stored in the list
				continue;
			}
			//this allows our function to iterate through our linked list values stored in our hash table
			while (current!=nullptr)
			{
				std::cout << "Index: " << i << " Key: " << current->key << " Value:" << current->value <<std::endl;
				if (current->previous!=nullptr)
				{
					std::cout << "Previous Key:" << current->previous->key << std::endl;
				}
				current = current->next;
			}
			//std::cout<<"Index: "<<i<<" Key: "<<Table[i]->key<<" Value:"<<Table[i]->value<<std::endl;
		}
	}
	

	~Hash_Table()
	{
		delete [] Table;
	}
};

#endif