#include  <iostream>
#include "Hash_Tableh.h"
#include <string>


int main()
{
	Hash_Table<int, int> Hash_Table;

	Hash_Table.insert(1, 1);
	Hash_Table.insert(2, 1);
	Hash_Table.insert(3, 1);
	Hash_Table.insert(4, 1);
	Hash_Table.insert(5, 1);
	Hash_Table.Search(5);
	Hash_Table.Search(4);
	Hash_Table.Search(3);
	Hash_Table.Search(2);
	Hash_Table.Search(1);
	std::cin.get();
	return 0;
}