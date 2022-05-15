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
	Date clean(24, 8, 2022);
	ellie.cleanUp(clean);
	ellie.productsAvailable(s, f);
	ellie.printStocks();
	ellie.getProduct();
	ellie.printStocks();
	ellie.productsAvailable(s,f);
}

/*
aspirin boaron
22 8 2022
12 12 2022
20
10 10 10

trahizan ellie
22 10 2022
12 12 2022
10
20 20 20

mig400 fmi
20 10 2022
14 12 2022
15
15 15 15

analgin fmi
20 12 2021
13 10 2022
30
15 15 10

mig400 fmi
23 10 2022
13 12 2022
10
15 15 15
*/