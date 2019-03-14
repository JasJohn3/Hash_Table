#include  <iostream>
#include "Hash_Tableh.h"
#include <string>


int main()
{
	Hash_Table<int, int> Hash_Table;
	Hash_Table.setTable_Size();
	Hash_Table.insert(1, 1);
	Hash_Table.display();
	std::cout << std::endl;
	Hash_Table.insert(2, 2);
	Hash_Table.display();
	std::cout << std::endl;
	Hash_Table.insert(3, 3);
	Hash_Table.display();
	std::cout << std::endl;
	Hash_Table.insert(4, 4);
	Hash_Table.display();
	std::cout << std::endl;
	Hash_Table.insert(5, 5);
	Hash_Table.display();
	std::cout << std::endl;
	Hash_Table.insert(6, 2);
	Hash_Table.display();
	std::cout << std::endl;
	Hash_Table.insert(1, 3);
	Hash_Table.display();
	std::cout << std::endl;
	Hash_Table.find(6);
	Hash_Table.find(5);
	Hash_Table.find(4);
	Hash_Table.find(3);
	Hash_Table.find(2);
	Hash_Table.find(1);
	system("pause");
 	std::cin.get();
	return 0;
}