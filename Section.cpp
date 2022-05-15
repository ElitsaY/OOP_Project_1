#include"Section.h"

const int& Section::getNumberOfShelves() const
{
	return numberOfShelves;
}
const int& Section::getNumberOfWidth() const
{
	return shelfWidth;
}
const int& Section::getNumberOfLength() const
{
	return shelfLength;
}
const int& Section::getNumberOfHeight() const
{
	return shelfHeight;
}
//-------------------------------

size_t Section::findPosition(size_t& height, size_t& length, size_t& width) const
{
	if (length > shelfLength || width > shelfLength || height > shelfLength)
		return -1;
	//едно измерение е по-голямо от 100
	if (length > shelfHeight)
	{
		//не може да има две измерения по-големи от 100
		if (width > shelfHeight || height > shelfHeight)
			return -1;
		//задължително отива при дължита
		return length;
	}
	else if (width > shelfHeight)
	{
		if (length > shelfHeight || height > shelfHeight)
			return -1;
		return width;
	}
	else if (height > shelfHeight)
	{
		if (width > shelfHeight || length > shelfHeight)
			return -1;
		return height;
	}
	//трите измерения са по-малки от 100 =>намирам най-малкото
	size_t minDimention = length;
	if (minDimention > width)
		minDimention = width;
	else if (minDimention > height)
		minDimention = height;
	return minDimention;
}

bool Section::insertProductOnShelf(Product& newElement)
{
	//първо търся свободно място на рафт
	size_t pHeight = newElement.getHeight();
	size_t pLength = newElement.getLength();
	size_t pWidth = newElement.getWidth();

	size_t productRotation = findPosition(pHeight, pLength, pWidth);

	if (productRotation == -1)
		return false;

	for (size_t i = 0; i < numberOfShelves; i++)
	{
		size_t productsOnShelf = shelf[i].getSize();
		if (productsOnShelf == 0)
		{
			//ако рафта е празен, слагам продукта и обновявам края
			newElement.setLength(productRotation);
			newElement.setShelf(i);
			newElement.setId(0);
			shelf[i].push_back(newElement);
			return true;
		}
		else
		{
			//пробвам да сложа елемента на рафта 
			size_t lastElementLength = shelf[i][productsOnShelf - 1].getLength();
			if (shelfLength - lastElementLength >= productRotation) // има място
			{
				newElement.setLength(lastElementLength + productRotation);
				newElement.setId(productsOnShelf);
				newElement.setShelf(i);
				shelf[i].push_back(newElement);
				return true;
			}
		}
	}
	return false;
}

void Section::removeProductFromShelf(const Product& removeElement, size_t shelfIndex)
{
	size_t productId = removeElement.getId();
	size_t productsOnShelf = shelf[shelfIndex].getSize();
	size_t substractLength;
	if (productId == 0) // махам първи елемент
	{
		substractLength = shelf[shelfIndex][0].getLength();
	}
	else if (productId == productsOnShelf - 1) //махам последен елемент
	{
		shelf[shelfIndex].pop_back(removeElement);
	}
	else
	{
		substractLength = shelf[shelfIndex][productId + 1].getLength() - shelf[shelfIndex][productId - 1].getLength();
		//вземам точната дължина 
	}

	for (int i = productId + 1; i < productsOnShelf; i++)
	{
		shelf[shelfIndex][i].setId(i - 1);
		size_t newLength = shelf[shelfIndex][i].getLength() - substractLength;
		shelf[shelfIndex][i].setLength(newLength);
	}
	shelf[shelfIndex].pop_back(shelf[shelfIndex][productsOnShelf-1]);
	
}

void Section::eraseProducts(const Date& validDate)
{
	for (int i = 0; i < numberOfShelves; i++)
	{
		size_t numberOfProducts = shelf[i].getSize();
		for (int j = 0; j < numberOfProducts; j++)
		{
			if (validDate < shelf[i][j].getValidityDate())
			{
				//изтекъл е срока на годност;
				removeProductFromShelf(shelf[i][j], i);
			}
		}
	}
}