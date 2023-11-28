//
//		Project3
//		AMZ_product.h

/************************************************************************
*
1  asin
2  title
3  imgUrl
4  productURL
5  stars
6  reviews
7  price
8  listPrice
9  category_id
10 isBestSeller
11 boughtInLastMonth
*
* 4 strings, 3 double, 3 int, 1 bool: 11
* *************************************************************************/

#pragma once

#include <string>
#include <vector>

using namespace std;


class AMZ_product
{
private:
	string  asin;

	string  title;
	string  imgUrl;
	string productURL;

	double  stars;
	int  reviews;
	double  price;
	double  listPrice;

	int  category_id;
	bool isBestSeller;
	int boughtInLastMonth;

	vector<AMZ_product> amazon_Products;

public:
	// class-Constructor
	AMZ_product(string  _asin, string _title, string _imgUrl, string _productURL,
		double _stars, int _reviews, double _price, double _listPrice,
		int _CategoryID, bool _isbestseller, int NumBought_lastMonth);

	// Default class constructor
	AMZ_product()
	{
		asin = "";	title = "";
		imgUrl = "";	productURL = "";

		stars = 0.0;
		reviews = 0;
		price = 0.0;
		listPrice = 0.0;

		category_id = 0;
		isBestSeller = false;
		boughtInLastMonth = 0;

	};

	//****************** Behaviours - 9/X-Functions*************************//


	void print_AmazonProduct();		//(1)
	void Print_Some_Products(vector<AMZ_product>& products_amz);
	//void Print_ALL_products(vector<AMZ_product> &products_amz);

	//********************* Accessors ***********************************//

	string Get_asin();
	string Get_title();
	string Get_imgUrl();
	string Get_productURL();

	double Get_stars();
	int Get_reviews();
	double Get_price();
	double Get_listPrice();

	int Get_category_id();
	bool Get_isBestSeller();
	int Get_boughtInLasMonth();

};

