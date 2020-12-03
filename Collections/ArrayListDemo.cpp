#include <string>
#include <vector>
#include <iostream>

int main()
{
	std::vector<int> al;

	al.push_back(1);
	al.push_back(2);
	al.push_back(3);
	al.push_back(4);
	std::cout << "Contents of Array: ";
	for (auto  i = al.begin();i != al.end(); i++)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;

	al.push_back(8);
	al.push_back(9);
	std::cout << "Contents of Array:" ;

	for (auto  i = al.begin();i != al.end(); ++i)
	{
		std::cout << *i << " ";
	}
	std::cout << std::endl;
	std::cout << "Array Size: " << al.size() << std::endl;

	std::cout << "Array IsEmpty: "<< al.empty() << std::endl;

	al.pop_back();

	std::cout << "Array Size: " << al.size() << std::endl;
	al.clear();

	std::cout << "Array IsEmpty: " << al.empty() << std::endl;
	return 0;
}
