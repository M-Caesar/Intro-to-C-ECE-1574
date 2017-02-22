#include "list.h"

List::List()
{
};

void List::addToList(storageType data)
{
	if (count < SIZE)
	{
		theList[count] = data;
		count++;
	}
}

storageType List::findData(storageType dataToFind) const
{
	storageType=toReturn;
	bool found = false;
	for (int i = 0; i < count; i++)
	{
		if (dataToFind== theList[i])
		{
			toReturn = theList[i];
			found = true;


		}
	}

	return toReturn;
}

storageType List::removeData(storageType dataToRemove)
{
	storageType=toReturn;
	bool found = false;
	for (int i = 0; i < count; i++)
	{
		if (dataToRemove== theList[i])
		{
			toReturn = theList[i];
			found = true;

			
		}
	}

	return toReturn;
}


void List:: displayList(ostream &out)
{
	for (int i = 0; i < count; i++)
		out << theList[i] << endl;
}