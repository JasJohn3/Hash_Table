#include  <iostream>
#include "Hash_Tableh.h"
#include <string>


int main()
{
	Hash_Table<int, int> Hash_Table;

	Hash_Table.insert(1, 1);
	Hash_Table.insert(2, 2);
	Hash_Table.insert(3, 3);
	Hash_Table.insert(4, 4);
	Hash_Table.insert(5, 5);
	Hash_Table.insert(6, 2);
	Hash_Table.Search(6);
	Hash_Table.Search(5);
	Hash_Table.Search(4);
	Hash_Table.Search(3);
	Hash_Table.Search(2);
	Hash_Table.Search(1);
	std::cin.get();
	return 0;
}