/******************************************************************************************************/
//
//		Project3
//		AMZ_product.h
//
// Group Members: Fall 2023, COP3530
//		Aravind Donthamsetti
//		
//		
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


void GetDataFromCSVFile(string filePath, vector<AMZ_product>& amazonProducts);

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

			// this is working (11
			cout << lineFromFile << endl;
			cout << "Count-Data-pieces: " << endl;

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
			getline(stream, _asin, ',');

			int f2_begin = lineFromFile.find('"');
			int f3_colon = lineFromFile.find(':');
			//int f_end = lineFromFile.find('"', f_colon - 7);
			if (f2_begin != -1)
			{
				cout << "f2_begin: " << f2_begin << "    f3_colon: " << f3_colon << endl;
				_title = lineFromFile.substr(f2_begin, f3_colon - 17);
			}
			else
			{
				getline(stream, _title, ',');
			}
			//cout << "f_begin: " << f_begin << "    f_colon: " << f_colon << endl;
			//_title = lineFromFile.substr(f_begin, f_colon-17);

			cout << "Title: " << _title << endl;


			//getline(stream, _imgUrl, ',');
			int f3_begin = f3_colon - 5;
			int f3_end = lineFromFile.find(',', f3_begin + 1);
			_imgUrl = lineFromFile.substr(f3_begin, f3_end);

			//getline(stream, _productURL, ',');
			int f4_colon = lineFromFile.find(':', f3_colon + 1);
			int f4_begin = f3_colon - 5;
			int f4_end = lineFromFile.find(',', f4_begin + 1);
			_productURL = lineFromFile.substr(f4_begin, f4_end);

			//Debug:
			cout << "===============================" << endl;
			cout << _asin << endl;
			cout << _title << endl;
			cout << "===============================" << endl;
			cout << _imgUrl << endl;
			cout << _productURL << endl;
			cout << "===============================" << endl;

			//idNum = stoi(tempNum);

			// Convert some strings to double-type
			//getline(stream, _stars, ',');
			int f5_begin = f4_end + 1;
			int f5_end = lineFromFile.find(',', f5_begin + 1);
			_stars = lineFromFile.substr(f5_begin, f5_end);
			//_Stars = stod(_stars);

			// Convert some strings to integer-type
			getline(stream, _reviews, ',');
			int f6_begin = f5_end + 1;
			int f6_end = lineFromFile.find(',', f6_begin + 1);
			_reviews = lineFromFile.substr(f6_begin, f6_end);
			//_Reviews = stoi(_reviews);

			getline(stream, _price, ',');
			//_Price = stod(_price);

			getline(stream, _listPrice, ',');
			//_ListPrice = stod(_listPrice);

			getline(stream, _categoryID, ',');
			//_Category_ID = stoi(_categoryID);


			//Debug:
			cout << "===============================" << endl;
			cout << "star-rating: " << _stars << endl;
			cout << "Reviews: " << _reviews << endl;
			cout << "Price: " << _price << endl;
			cout << "List_Price: " << _listPrice << endl;
			cout << "Category(ID): " << _categoryID << endl;
			cout << "===============================" << endl;

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
			getline(stream, _isbestseller, ',');
			if (_isbestseller == "FALSE")
			{
				//see Cateory 104, 110, 
				_IsBestSeller = false;
			}
			else if (_isbestseller == "TRUE")
			{
				//see Category 110
				_IsBestSeller = true;
				// Debugger statement (11-24-23) 11:19 PM.
				//cout << _Category_ID << endl;
			}
			else
			{
				_IsBestSeller = false;
			}

			//remove the delimiter for the last token, 
			getline(stream, numBought_lastMonth);
			//	_Number_boughtInLastMonth = stoi(numBought_lastMonth);

			cout << "IsBestSeller(Y/N): " << _IsBestSeller << endl;
			cout << "N_BoughtLastMonth: " << numBought_lastMonth << endl;
			//cout << _Number_boughtInLastMonth << endl;
			cout << "Last: Enter 1 to go ==============================" << endl;
			int test = 0;
			cin >> test;		//Note: Could comment out this line to see 100s of data-objests!


			loopcount++;
			if (loopcount % 10 == 0)
			{
				//cin >> test;
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

