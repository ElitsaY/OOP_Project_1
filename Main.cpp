#include"Product.h"
#include"Vector.hpp"
#include"Pair.hpp"
#include"Storage.h"

int main()
{
	Storage ellie;
	ellie.insertProduct();
	Date s(20, 8, 2022);
	Date f(13, 12, 2022);
	ellie.productsAvailable(s, f);
	std::cout << "_____________________________________" << std::endl;
	ellie.printStocks();
	std::cout << "_____________________________________" << std::endl;
	ellie.getProduct();
	std::cout << "_____________________________________" << std::endl;
	ellie.printStocks();
	std::cout << "_____________________________________" << std::endl;
	ellie.productsAvailable(s,f);
	std::cout << "_____________________________________" << std::endl;

}

/*
aspirin bayer
22 8 2022
12 12 2022
20
10 10 10

trahizan Engelhard 
22 10 2022
12 12 2022
10
20 20 20

mig400 berlinChemi
20 10 2022
14 12 2022
15
15 15 15

mig400 berlinChemi
23 10 2022
13 12 2022
10
15 15 15
*/