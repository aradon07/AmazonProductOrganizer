//ARAVID DONTHAMSETTI 
//12/4/23    ATTEMPT to read CSV file better......... without a class and object ---- just from main driver

#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

// Function to clean up a CSV line and tokenize it
vector<string> tokenizeCSVLine(const string& line) 
{
    vector<string> tokens;
    istringstream ss(line);
    string token;

    while (getline(ss, token, ',')) 
    {
        // Remove quotes from token if present
        size_t start = token.find_first_of('"');
        size_t end = token.find_last_of('"');

        if (start != string::npos && end != string::npos) 
        {
            token = token.substr(start + 1, end - start - 1);
        }

        tokens.push_back(token);
    }

    return tokens;
}

int main() 
{
    ifstream inputFile("amazon_products.csv");  

    if (!inputFile.is_open()) 
    {
		 
        cout << "Error opening the file." << endl;
	        return 1;
    }

    // Read and print header
    string header;
    getline(inputFile, header);
    cout << "Header: " << header << endl;

    while (!inputFile.eof()) 
    {
        string line;
        getline(inputFile, line);

        if (line.empty()) 
        {
            break;    // Stop if we reached the end of the file
        }

        // Tokenize and process each line
        vector<string> tokens = tokenizeCSVLine(line);

        // Ensure that there are 11 tokens in each line     /////////////////////////
        if (tokens.size() != 11) 
        {
            //Ignore the errors by only printing what works..........---if we comment out the error -- problem persists.
            // 
            cout<< "Error: Invalid number of tokens in the line." << endl;   //- debug line shows token errors from extra commas are in file
            continue; // Skip this line and move to the next one
        }

        // Access and print specific tokens of interest
        cout << "Title: " << tokens[1] << endl;          // Token 2: title
        cout << "Stars: " << tokens[4] << endl;          // Token 5: stars
        cout << "Price: " << tokens[6] << endl;          // Token 7: price
        cout << "Category ID: " << tokens[8] << endl;    // Token 9: category ID
        cout << "Is Best Seller: " << tokens[9] << endl; // Token 10: isBestSeller 
        cout << "Bought in Last Month: " << tokens[10] << endl; // Token 11: boughtinLastMonth

        //Access other parameters we may not care for
        cout << "\n5 Data Tokens We may Not Need below............." << endl << endl;
        cout << "Asin: " << tokens[0] << endl;          // Token 1: ASIN
        cout << "img URL: " << tokens[2] << endl;          // Token 3: title
        cout << "product URL: " << tokens[3] << endl;          // Token 4: title
        cout << "reviews: " << tokens[5] << endl;          // Token 6: title
        cout << "list price: " << tokens[7] << endl;          // Token 8: title
        
         
     // TO DO:   further processing for Quick sorting  and Shell Sort needed next.....

        cout << endl; // Add a newline for better readability
    }

    inputFile.close();


    // Interactive menu                 TO DO : -----------I GOT SOMETHING STARTED for a possible interface menu-----But not working yet...
   
    
    int choice;
    do {
        cout << "\n-------------------------" << endl;
        cout << "1. Search for items by category id number" << endl;
        cout << "2. Search by title" << endl;
        cout << "3. List top 25 items by highest price" << endl;
        cout << "4. List top 25 items by lowest price" << endl;
        cout << "5. List top 25 items by highest star rating" << endl;
        cout << "6. List top 25 items by lowest star rating" << endl;
        cout << "7. Check if an item is a bestseller" << endl;
        cout << "8. Exit" << endl;
        cout << "-------------------------" << endl;

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1: {
            // Search for items by category id number
            int categoryId;
            cout << "Enter category id: ";
            cin >> categoryId;

            //////////////////////////////////////////////////////NEED CODE HERE
			
            break;
        }
        case 2: {
            // Search by title
            string title;
            cout << "Enter title: ";
            cin.ignore();  // Consume the newline character left in the buffer
            getline(cin, title);

            
            break;
        }
        case 3: {
            // List top 25 items by highest price
            // Implement sort and print the top 25 items by highest price  ///////NEED CODE HERE
            break;
        }
        case 4: {
            // List top 25 items by lowest price
            // Implement  sort and print the top 25 items by lowest price  ///////NEED CODE HERE
            break;
        }
        case 5: {
            // List top 25 items by highest star rating
            // Implement  sort and print the top 25 items by highest star rating  ///////NEED CODE HERE
            break;
        }
        case 6: {
            // List top 25 items by lowest star rating
            // Implement  sort and print the top 25 items by lowest star rating   ///////NEED CODE HERE
            break;
        }
        case 7: {
            // Check if an item is a bestseller
            string asin;
            cout << "Enter ASIN: ";
            cin >> asin;

            //////////////////////////////////////////////////////////////////////NEED CODE HERE
            
            break;
        }
        case 8: {
            // Exit the program
            cout << "Exiting program." << endl;
            break;
        }
        default:
            cout << "Invalid choice. Please enter a number between 1 and 8." << endl;
        }
    } while (choice != 8);

    return 0;
}

