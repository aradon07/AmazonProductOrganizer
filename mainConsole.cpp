/******************************************************************************************************/
//
//		Project3
//		AMZ_product.h
//
// Group Members: Fall 2023, COP3530
//		Aravind Donthamsetti
//		
//		
// More Progress Reading CSV: 12/3 and 12/4. But CSV data is required to be cleaned and you will need the new file.
// Currently read every 1000 lines by pressing "1 and enter" every 1000 listings.
// 
// Started: 11-24(Fri)-23 ThanksGiving Weekend, 11-27(M)-23
//
// Due: 12-5(T)-23
/*******************************************************************************************************/



#include <iostream>
#include <string>
#include <vector>

#include "AMZ_product.h"

#include <iomanip>		//Zyb Main() formating
#include<sstream>	//Zyb 12.2 Input string-stream
#include <fstream>	//Zyb 12.4 File input

using namespace std;


void GetDataFromCSVFile(string filePath, vector<AMZ_product> &amazonProducts);

int main()
{
    //std::cout << "Hello World!\n";
	AMZ_product amazonStuff;

	//Vector lego-containers here for easy access.
	vector<AMZ_product> amzPRODUCTS;

	//int option = 0;  //Initialize variable
	unsigned int option;				// 11-24-23, F23, COP3530 Project3_Amazon_DataSets

	//Menu
	cout << std::fixed << setprecision(2);
	cout << "Amazon file(s) to open?\n";
	cout << "0. To Quit!" << endl;
	cout << "1. amazon_products.csv" << endl;
	cout << "Menu doesn't work yet!! \n\n" << endl;
	
	//unsigned int option;
	//cin >> option;

	// Read data from file and store each data-object
			// in a vector-class-container.
	GetDataFromCSVFile("amazon_products.csv", amzPRODUCTS);
	//cout << "Total number of amz-Products: " << amzPRODUCTS.size() << endl;
	cin >> option;

	//amazonStuff.Print_Some_Products(amzPRODUCTS);

	//TestPrint(LEGOsets);


    return 0;
}



void GetDataFromCSVFile(string filePath, vector<AMZ_product>& amz_products)
{
	ifstream inFile(filePath);
	int loopcount = 0;

	if (inFile.is_open())
	{
		//0. Read the heading data from the file
		string lineFromFile;
		getline(inFile, lineFromFile);

		// Reading the Header (of file amazon_products.csv)
		// 
		cout << "--------------------------------------------------------------------------------" << endl;
		cout << "HEADER_CSV-file: \n" << endl;

		cout << lineFromFile << endl << endl;
		cout << "--------------------------------------------------------------------------------" << endl;
		// 
		// asin	 title	imgUrl	productURL	stars	reviews	  price	 listPrice	
		// category_id	isBestSeller	boughtInLastMonth
		//
		// 4 strings, 3 double, 3 int, 1 bool: 11

		//Get ALL the line entries/records from the file, one line at a time (below header)
		while (getline(inFile, lineFromFile))
		{
			//Create a stream from the line of data from the file
			istringstream stream(lineFromFile);  // A stream of data, coming from a string

			int go;
			// this is working (11
			cout << lineFromFile << endl;
			//cout << "\nCount-Data-pieces (11 Tokens): " << endl;
			//cin >> go;

			//getline only works with strings so use temporary string variables (11 attributes):
			string  _asin, _title, _imgUrl, _productURL;
			string _stars, _reviews;
			string _price, _listPrice;
			string _categoryID;
			string _isbestseller;
			string numBought_lastMonth;

			// 3:3:1 => 3 doubles, 3 integers, 1 boolean
			double _Stars;
			int _Reviews;
			double _Price, _ListPrice;
			int _Category_ID;
			bool _IsBestSeller;
			int _Number_boughtInLastMonth;

			// Getline codes to access each of the 11 tokens from each CSV line of data 
			// one token at a time in the order below with delimiter 
			//
			//getline(stream, _asin, ',');
			int f1_begin = 0;
			int f1_end = lineFromFile.find(',');
			_asin = lineFromFile.substr(f1_begin, f1_end);
			cout << "\n===========================================" << endl;
			cout << "\nAsin: " << _asin << endl;
			//cin >> go;

			//int f_end = lineFromFile.find('"', f_colon - 7);

			int f2_begin = f1_end + 1;
			int f3_colon = lineFromFile.find(':');
			int f2_end = f3_colon - 6;

			_title = lineFromFile.substr(f2_begin, (f2_end - f2_begin));

			//_title = lineFromFile.substr(f2_begin, f3_colon - 17);
			cout << "\nTitle: " << _title << endl;
			//cin >> go;

			//cout << "f_begin: " << f_begin << "    f_colon: " << f_colon << endl;
			//_title = lineFromFile.substr(f_begin, f_colon-17);

			//cout << "Title: " << _title << endl;
			
			
			//getline(stream, _imgUrl, ',');
			int f3_begin = f3_colon - 5;
			int f3_end = lineFromFile.find(',', f3_begin + 1);
			//cout << "f3_begin: " << f3_begin << "    f3_end: " << f3_end << endl;
			_imgUrl = lineFromFile.substr(f3_begin, (f3_end - f3_begin));

			cout << "\nimg_Url: " << _imgUrl << endl;
			//cin >> go;

			//getline(stream, _productURL, ',');
			int f4_colon = lineFromFile.find(':', f3_end + 1);
			int f4_begin = f4_colon -5;
			int f4_end = lineFromFile.find(',', f4_begin + 1);
			_productURL = lineFromFile.substr(f4_begin, (f4_end - f4_begin));

			cout << "\nproduct_Url: " << _productURL << endl;
			//cin >> go;

			/******************************************************
			//Debug:
			cout << "===============================" << endl;
			cout << _asin << endl;
			cout << _title << endl;
			cout << "===============================" << endl;
			cout << _imgUrl << endl;
			cout << _productURL << endl;
			cout << "===============================" << endl;
			**********************************************************/

			//idNum = stoi(tempNum);

			// Convert some strings to double-type
			//getline(stream, _stars, ',');
			int f5_begin = f4_end + 1;
			int f5_end = lineFromFile.find(',', f5_begin + 1);
			_stars = lineFromFile.substr(f5_begin, (f5_end - f5_begin));
			//_Stars = stod(_stars);

			cout << "\nStars: " << _stars << endl;
			//cin >> go;

			// Convert some strings to integer-type
			//getline(stream, _reviews, ',');
			int f6_begin = f5_end + 1;
			int f6_end = lineFromFile.find(',', f6_begin + 1);
			_reviews = lineFromFile.substr(f6_begin, (f6_end - f6_begin));
			//_Reviews = stoi(_reviews);

			cout << "\nReviews: " << _reviews << endl;
			//cin >> go;

			getline(stream, _price, ',');
			int f7_begin = f6_end + 1;
			int f7_end = lineFromFile.find(',', f7_begin + 1);
			_price = lineFromFile.substr(f7_begin, (f7_end - f7_begin));
			//_Price = stod(_price);

			cout << "\nPrice: " << _price << endl;
			//cin >> go;

			//getline(stream, _listPrice, ',');
			//_ListPrice = stod(_listPrice);

			int f8_begin = f7_end + 1;
			int f8_end = lineFromFile.find(',', f8_begin + 1);
			_listPrice = lineFromFile.substr(f8_begin, (f8_end - f8_begin));
			cout << "\nList_Price: " << _listPrice << endl;
			//cin >> go;
			
			//getline(stream, _categoryID, ',');
			//_Category_ID = stoi(_categoryID);

			int f9_begin = f8_end + 1;
			int f9_end = lineFromFile.find(',', f9_begin + 1);
			_listPrice = lineFromFile.substr(f9_begin, (f9_end - f9_begin));
			cout << "\nCategory_ID: " << _listPrice << endl;
			//cin >> go;

			/********************************************************
			//Debug:
			cout << "===============================" << endl;
			cout << "star-rating: " <<_stars << endl;
			cout << "Reviews: " << _reviews << endl;
			cout << "Price: " << _price << endl;
			cout << "List_Price: " << _listPrice << endl;
			cout << "Category(ID): " <<_categoryID << endl;
			cout << "===============================" << endl;
			**********************************************************/
			
			/********************************************************************
			cout << "===============================" << endl;
			cout << _Stars << endl;
			cout << _Reviews << endl;
			cout << _Price << endl;
			cout << _ListPrice << endl;
			cout << _Category_ID << endl;
			cout << "===============================" << endl;
			****************************************************************/

			// Convert some strings to ?boolean-type
			//getline(stream, _isbestseller, ',');
			int f10_begin = f9_end + 1;
			int f10_end = lineFromFile.find(',', f10_begin + 1);
			_isbestseller = lineFromFile.substr(f10_begin, (f10_end - f10_begin));
			cout << "\nIsBestSeller: " << _isbestseller << endl;
			//cin >> go;
			//bool _IsBestSeller = lineFromFile.substr(f10_begin,(f10_end - f10_begin));

			int f11_begin = f10_end + 1;
			int f11_end = lineFromFile.find(',', f11_begin + 1);
			numBought_lastMonth = lineFromFile.substr(f11_begin, (f11_end - f11_begin));
			cout << "\nNumber_Bought_lastMonth: " << numBought_lastMonth << endl;
			//cin >> go;

					
			//remove the delimiter for the last token, 
			//getline(stream, numBought_lastMonth);
		//	_Number_boughtInLastMonth = stoi(numBought_lastMonth);



			//cout << "IsBestSeller(Y/N): " << _IsBestSeller << endl;
			//cout << "N_BoughtLastMonth: " << numBought_lastMonth << endl;
			//cout << _Number_boughtInLastMonth << endl;
			//cout << "Last: Enter 1 to go ==============================" << endl;
			int test = 0;
			//cin >> test;		//Note: Could comment out this line to see 100s of data-objests!


			loopcount++;
			if (loopcount % 1000 == 0)
			{
				cout << "LoopCount: " << loopcount << endl;
				cin >> test;
				
			}
			
			
			//Create an Amazon_Product Data-object(11 atributes)
			//LegoData legoOBJ(idNum, theme, name, minifigs, pieces, price);

			/************************
			AMZ_product productOBJ(_asin, _title, _imgUrl, _productURL,
				_Stars, _Reviews, _Price, _ListPrice, 
				_Category_ID, _IsBestSeller, _Number_boughtInLastMonth);
				*******************************/

			// Store Amazon_Product-Object(data) into 
			// vector(class AMZ_product)-container
			//amz_products.push_back(productOBJ);
		}              							
	}
	else
	{
		cout << "Error: File could not be opened!!" << endl;
	}

	cout << "Total Amazon Products: " << loopcount << endl;

} //End function GetDataFromCSVFile()

