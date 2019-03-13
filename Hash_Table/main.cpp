#include  <iostream>
#include "Hash_Tableh.h"
#include <string>


int main()
{
	Hash_Table<std::string, char> Hash_Table;
	Hash_Table.insert("Alpha",'A');
	Hash_Table.insert("Beta",'B');
	Hash_Table.insert("Charlie", 'C');
	Hash_Table.Display();
	std::cout<<std::endl;
	Hash_Table.insert("Beta", 'C');
	Hash_Table.Display();
	std::cout << std::endl;
	Hash_Table.insert("Bravo", 'B');
	Hash_Table.insert("Delta", 'D');
	Hash_Table.insert("Echo", 'E');
	Hash_Table.Display();
	system("pause");

	return 0;
}