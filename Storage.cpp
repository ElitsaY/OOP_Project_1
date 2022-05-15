#include"Storage.h"

bool Storage::executeCommand(const MyString& command) const
{
	if (command == "exit") return false;
	return true;
}

void Storage::findSection(Product& newProduct)
{
	for (int i = 0; i < numberOfSections; i++)
	{
		if (sections[i].insertProductOnShelf(newProduct) == true)
		{
			newProduct.setSection(i);
			return;
		}
	}
}

void Storage::storeInfo(Product& newProduct)
{
	listOfValidProducts.push_back(newProduct);
	
	Pair<Product, bool> temp(newProduct, false);
	actionsMade.push_back(temp);
	
	int productsQ = quantityOfProduct.getSize();
	bool added = false;
	for (int i = 0; i < productsQ; i++)
	{
		MyString listName = quantityOfProduct[i].getFirst();
		if (listName == newProduct.getName())
		{
			size_t newQuantity = quantityOfProduct[i].getSecond() + newProduct.getQuantityInstock();
			quantityOfProduct[i].setSecond(newQuantity);
			bool added = true;
		}		
	}
	
	if (added == false)
	{
		Pair<MyString, int> tempVar(newProduct.getName(),newProduct.getQuantityInstock());
		quantityOfProduct.push_back(tempVar);
	}
	
}

void Storage::insertProduct()
{
	MyString command;
	std::cout << ">";
	std::cin >> command;
	std::cout << std::endl;

	Product newProduct;

	while (executeCommand(command))
	{
		std::cin >> newProduct;
		if (!newProduct.validProductDates())
		{
			std::cout << "Wrong information about the product"<<std::endl;
			std::cout << "The product can not be accepted" << std::endl;
		}
		else
		{
			findSection(newProduct);
			storeInfo(newProduct);
			
		}
		std::cout << ">";
		std::cin >> command;
		std::cout << std::endl;
	}
}

void Storage::cleanUp(const Date& validyDate)
{
	for (int i = 0; i < numberOfSections; i++)
	{
		sections[i].eraseProducts(validyDate);
	}
	size_t validProducts = listOfValidProducts.getSize();
	for (int i = 0; i < validProducts; i++)
	{
		if (listOfValidProducts[i].getValidityDate() < validyDate)
		{
			listOfValidProducts.pop_back(listOfValidProducts[i]);
		}
	}
}

void Storage::printStocks() 
{
	size_t productsInStock = quantityOfProduct.getSize();
	for (int i = 0; i < productsInStock; i++)
	{
		std::cout << quantityOfProduct[i].getFirst() << " ";
		std::cout << quantityOfProduct[i].getSecond() << std::endl;
	}
	//quantityOfProduct.print();
}

void Storage::productsAvailable(const Date& startDate, const Date& finishDate)
{
	size_t totalActions = actionsMade.getSize();
	for (int i = 0; i < totalActions; i++)
	{
		Date currentActionDate = actionsMade[i].getFirst().getEnterDate();
		if (startDate < currentActionDate && currentActionDate < finishDate)
		{
			std::cout << actionsMade[i].getFirst();
			if (actionsMade[i].getSecond() == true)
			{
				std::cout << "removed" << std::endl;
			}
			else
			{
				std::cout << "inserted" << std::endl;
			}
		}

	}
}

void Storage::removeFromTotalQuantity(const MyString& productName, size_t quantity)
{
	size_t size = quantityOfProduct.getSize();
	for (int i = 0; i < size; i++)
	{
		if (productName == quantityOfProduct[i].getFirst())
		{
			size_t currentQuantity = quantityOfProduct[i].getSecond();
			if (currentQuantity - quantity <= 0) quantityOfProduct.pop_back(quantityOfProduct[i]);
			else quantityOfProduct[i].setSecond(currentQuantity - quantity);
			return;
		}
	}
}

void Storage::removeQuantity(const MyString& productName, size_t neededQuantity)
{
	size_t validProducts = listOfValidProducts.getSize();

	for (int i = 0; i < validProducts; i++)
	{
		if (productName == listOfValidProducts[i].getName())
		{
			size_t availableQ = listOfValidProducts[i].getQuantityInstock();
			if (availableQ >= neededQuantity)
			{
				listOfValidProducts[i].setQuantityInStock(availableQ - neededQuantity);

				if (availableQ == neededQuantity)
				{
					listOfValidProducts.pop_back(listOfValidProducts[i]);

					size_t productSection = listOfValidProducts[i].getSection();
					size_t productShelf = listOfValidProducts[i].getShelf();
					sections[productShelf].removeProductFromShelf(listOfValidProducts[i], productShelf);
				}

				Pair<Product, bool> temp;
				temp.setFirst(listOfValidProducts[i]);
				temp.setSecond(true);
				actionsMade.push_back(temp);
				removeFromTotalQuantity(productName, neededQuantity);

				return;
			}
			else
			{
				neededQuantity -= availableQ;
				bool answer;
				std::cout << "Do you want to get another stock" << std::endl;
				std::cin >> answer;
				if (answer == 0)
					return;
			}
		}
	}
	std::cout << "The product does not exist" << std::endl;
}

void Storage::getProduct()
{
	size_t validProducts = listOfValidProducts.getSize();

	MyString command;
	std::cout << ">";
	std::cin >> command; 
	std::cout << std::endl;

	MyString nameOfProduct;
	size_t neededQuantity;

	while (executeCommand(command))
	{
		listOfValidProducts.sort();
		std::cin >> nameOfProduct >> neededQuantity;
		removeQuantity(nameOfProduct, neededQuantity);
		std::cout << ">";
		std::cin >> command;
		std::cout << std::endl;
	}
}