#ifndef LIST_H
#define LIST_H
#include <string>

const int SIZE = 10;

using namespace std;

typedef int storageType; // storageType is the same thing as an int


class List
{
private:
	storageType theList[SIZE];
	storageType count;
public:
	List();
	void addToList(storageType data);
	storageType findData(storageType dataToFind) const;
	storageType removeData(storageType dataToRemove);
	void displayList(ostream &out);


};


#endif