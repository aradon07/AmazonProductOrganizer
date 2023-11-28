/******************************************************************************************************/
//
//		Project3
//		AMZ_product.h
//
// Group Members: , COP3530 Group 14
//		Aravind Donthamsetti, David Hochman, Yueming FANG
//		
//		
//
// Started: 11-24(F)-23, 11-27(M)-23
//
// Due: 12-5(T)-23
/*******************************************************************************************************/

#include "AMZ_product.h"
#include <iostream>
#include <string>

using namespace std;

// Class-Constructor
AMZ_product::AMZ_product(string  _asin, string _title, string _imgUrl, string _productURL,
	double _stars, int _reviews, double _price, double _listPrice,
	int _CategoryID, bool _isbestseller, int NumBought_lastMonth)
{
	asin = _asin;

	title = _title;
	imgUrl = _imgUrl;
	productURL = _productURL;

	stars = _stars;
	reviews = _reviews;
	price = _price;
	listPrice = _listPrice;

	category_id = _CategoryID;
	isBestSeller = _isbestseller;
	boughtInLastMonth = NumBought_lastMonth;

}

//********************* Accessors ***********************************//

string AMZ_product::Get_asin()
{
	return asin;
}

string AMZ_product::Get_title()
{
	return title;
}
string AMZ_product::Get_imgUrl()
{
	return imgUrl;
}
string AMZ_product::Get_productURL()
{
	return productURL;
}

double AMZ_product::Get_stars()
{
	return stars;
}
int AMZ_product::Get_reviews()
{
	return reviews;
}
double AMZ_product::Get_price()
{
	return price;
}
double AMZ_product::Get_listPrice()
{
	return listPrice;
}

int AMZ_product::Get_category_id()
{
	return category_id;
}
bool AMZ_product::Get_isBestSeller()
{
	return isBestSeller;
}
int AMZ_product::Get_boughtInLasMonth()
{
	return boughtInLastMonth;
}

/*****************************************************************


*******************************************************************/
// Print Amazon_Product_Object
//
void AMZ_product::print_AmazonProduct()
{
	// Rearranged (11)-variable outputs
	// Right now(12/24), cannot output the two images of given product (ie, the two url-addresses!)
	//
	cout << "----------------------------------------------------------------" << endl;
	cout << "Title: " << Get_title() << endl;

	cout << "Ratings: " << Get_stars() << "     ";
	cout << "Number of Reviews: " << Get_reviews() << endl << endl;

	cout << "Price: " << Get_price() << "     ";
	cout << "List_Price: " << Get_listPrice() << endl;

	cout << "Best Seller (Y/N): " << Get_isBestSeller() << endl;
	cout << "Number Bought in Last Month: " << Get_boughtInLasMonth() << endl << endl;

	// Currently (12/24), We Don't know what Asin and Category_ID mean.
	//
	cout << "Asin: " << Get_asin() << "    " << endl;
	cout << "Category_ID: " << Get_category_id() << endl;
	cout << "Image_Url: " << Get_imgUrl() << endl;
	cout << "Product_Url: " << Get_productURL() << endl;
	cout << "----------------------------------------------------------------" << endl;

}

void AMZ_product::Print_Some_Products(vector<AMZ_product>& products_amz)
{
	// Print every 100th Amazon-Product-object.
	unsigned int i;
	cout << "\n--------------------------------------------" << endl << endl;
	for (i = 0; i < products_amz.size(); i += 100)
	{
		cout << "i: " << i << endl;
		products_amz[i].print_AmazonProduct();
	}
	cout << "\n--------------------------------------------" << endl << endl;

}





