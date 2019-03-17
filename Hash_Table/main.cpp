#include  <iostream>
#include "Hash_Tableh.h"
#include <string>

void automated_testing();

int main()
{
	automated_testing();
	Hash_Table<std::string, std::string> hash;
	std::string key, value;
	int choice;
	bool exit = false;
	while (1)
	{
		std::cout << "\n----------------------" << std::endl;
		std::cout << "Hash Phone Directory" << std::endl;
		std::cout << "\n----------------------" << std::endl;
		std::cout << "1.Insert Phone Book Entry into the table" << std::endl;
		std::cout << "2.Search Phone Book from the key" << std::endl;
		std::cout << "3.Delete Phone Book Entry using Name" << std::endl;
		std::cout << "4.Exit" << std::endl;
		std::cout << "Enter your choice: ";
		std::cin >> choice;
		switch (choice)
		{
		case 1:
			std::cout << "Enter Phone Number to be inserted: ";
			std::cin >> value;
			std::cout << "Enter Last Name to be inserted: ";
			std::cin >> key;
			hash.insert(key, value);
			break;
		case 2:
			std::cout << "Enter Last Name to be searched: ";
			std::cin >> key;
			std::cout << "/nLast Name found: " << key << std::endl;
			if (hash.find(key) == false)
			{
				std::cout << "No Last Name found: " << key << std::endl;
				continue;
			}
			break;
		case 3:
			std::cout << "Enter Last Name to be deleted: ";
			std::cin >> key;
			hash.Remove(key);
			break;
		case 4:
			return 0;
		default:
			std::cout << "\nEnter correct option\n";
		}
	}



	return 0;
}




void automated_testing()
{
	Hash_Table<int, int> Hash_Table;

	Hash_Table.insert(1, 1);
	if (Hash_Table.find(1) == false)
	{
		std::cout << "Insert Test Failed!" << std::endl;
	}
	else
	{
		std::cout << "Insert Value Test Successful!" << std::endl;
	}

	Hash_Table.insert(2, 2);
	if (Hash_Table.find(2) == false)
	{
		std::cout << "Insert Test Failed!" << std::endl;
	}
	else
	{
		std::cout << "Insert Value Test Successful!" << std::endl;
	}

	Hash_Table.insert(3, 3);
	if (Hash_Table.find(3) == false)
	{
		std::cout << "Insert Test Failed!" << std::endl;
	}
	else
	{
		std::cout << "Insert Value Test Successful!" << std::endl;
	}
	Hash_Table.insert(4, 4);
	if (Hash_Table.find(4) == false)
	{
		std::cout << "Insert Test Failed!" << std::endl;
	}
	else
	{
		std::cout << "Insert Value Test Successful!" << std::endl;
	}
	Hash_Table.insert(5, 5);
	if (Hash_Table.find(5) == false)
	{
		std::cout << "Insert Test Failed!" << std::endl;
	}
	else
	{
		std::cout << "Insert Value Test Successful!" << std::endl;
	}
	Hash_Table.insert(6, 2);
	if (Hash_Table.find(6) == false)
	{
		std::cout << "Insert Test Failed!" << std::endl;
	}
	else
	{
		std::cout << "Insert Value Test Successful!" << std::endl;
	}
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
	Hash_Table.Remove(2);
	if (Hash_Table.find(2) == true)
	{
		std::cout << "Remove Value Test Failed!" << std::endl;
	}
	else
	{
		std::cout << "Remove Value Test Successful!" << std::endl;
	}
	Hash_Table.Remove(4);
	if (Hash_Table.find(4) == true)
	{
		std::cout << "Remove Value Test Failed!" << std::endl;
	}
	else
	{
		std::cout << "Remove Value Test Successful!" << std::endl;
	}
	Hash_Table.Remove(1);
	if (Hash_Table.find(1) == true)
	{
		std::cout << "Remove Value Test Failed!" << std::endl;
	}
	else
	{
		std::cout << "Remove Value Test Successful!" << std::endl;
	}
	Hash_Table.Remove(5);
	if (Hash_Table.find(5) == true)
	{
		std::cout << "Remove Value Test Failed!" << std::endl;
	}
	else
	{
		std::cout << "Remove Value Test Successful!" << std::endl;
	}
	Hash_Table.display();
	std::cin.get();
}



