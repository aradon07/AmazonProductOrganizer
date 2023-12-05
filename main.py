import csv

def Shellsorttitle(vec):
    val = len(vec) // 2

    while val > 0:
        j = val
        # Check the array in from left to right
        # Till the last possible index of j
        while j < len(vec):
            i = j - val  # This will keep help in maintain gap value

            while i >= 0:
                # If value on right side is already greater than left side value
                # We don't do swap else we swap
                if vec[i + val].title > vec[i].title:

                    break
                else:
                    vec[i + val], vec[i] = vec[i], vec[i + val]

                i = i - val  # To check left side also
                # If the element present is greater than current element
            j += 1
        val = val // 2

def Quicksorttitle(vec):
    print("z")

def Shellsortrating(vec):
    val = len(vec) // 2

    while val > 0:
        j = val
        # Check the array in from left to right
        # Till the last possible index of j
        while j < len(vec):
            i = j - val  # This will keep help in maintain gap value

            while i >= 0:
                # If value on right side is already greater than left side value
                # We don't do swap else we swap
                if vec[i + val].rating > vec[i].rating:

                    break
                else:
                    vec[i + val], vec[i] = vec[i], vec[i + val]

                i = i - val  # To check left side also
                # If the element present is greater than current element
            j += 1
        val = val // 2

def Quicksortrating(vec):
    print("z")

def Shellsortprice(vec):
    val = len(vec) // 2

    while val > 0:
        j = val
        # Check the array in from left to right
        # Till the last possible index of j
        while j < len(vec):
            i = j - val  # This will keep help in maintain gap value

            while i >= 0:
                # If value on right side is already greater than left side value
                # We don't do swap else we swap
                if vec[i + val].price > vec[i].price:

                    break
                else:
                    vec[i + val], vec[i] = vec[i], vec[i + val]

                i = i - val  # To check left side also
                # If the element present is greater than current element
            j += 1
        val = val // 2

def Quicksortprice(vec):
    print("z")


class Product:
    def __init__(self, title, stars, price, category):
        self.title = title  # string title
        self.stars = stars  # float stars
        self.price = price  # float price
        self.category = category  # int category


if __name__ == "__main__":
    while True:
        cat = ""

        with open('amazon_categories.csv', newline='', encoding="utf8") as csvfile2:
            # Create a CSV reader
            reader2 = csv.reader(csvfile2)

            for i in reader2:
                row = next(reader2, None)  # Read the next line
                x = 0
                if row is None:
                    break  # If the end of file is reached, break the loop
                # print(row)
                for i in row:
                    if x == 0:
                        print(i + ". ")
                        x = 1
                    else:
                        print(i)
                        print()
                        x = 0
        #cat = input("Enter the desired category to search")

        #char_list = [chr(i) for i in range(49, 271)]

        #while cat not in char_list:
         #   cat = input("Please enter a valid category")
        valid_input = False
        while not valid_input:
            cat = input("Enter the desired category to search: ")

            try:
                cat_int = int(cat)
                if 1 <= cat_int <= 270:
                    valid_input = True
                else:
                    print("Please enter a valid category between 1 and 270.")
            except ValueError:
                print("Please enter a valid integer.")

        products0 = []
        products1 = []
        with open('amazon_products.csv', newline='', encoding="utf8") as csvfile:
            # Create a CSV reader
            reader = csv.reader(csvfile)

            for i in reader:
                row = next(reader, None)  # Read the next line
                if row is None:
                    break  # If the end of file is reached, break the loop
                # print(row)
                x = 0
                title = ""
                stars = 0.00
                price = 0.00
                category = 0

                for j in row:

                    if x == 1:
                        title = j
                        # print("x")
                    if x == 4:
                        stars = j
                        # print(j)
                    if x == 6:
                        price = j
                        # print(j)
                    if x == 8:
                        category = j
                        # print(j)

                    x += 1

                temp0 = Product(title, stars, price, category)
                temp1 = Product(title, stars, price, category)

                if temp0.category == cat:
                    products0.append(temp0)
                if temp1.category == cat:
                    products1.append(temp1)

        print("\nOptions:")
        print("1. Sort by Title")
        print("2. Sort by Rating")
        print("3. Sort by Price")
        print("4. Exit")

        choice = input("Enter your choice (1-4): ")

        if choice == '1':

            Quicksorttitle(products0)
            Shellsorttitle(products1)

        elif choice == '2':
            Quicksortrating(products0)
            Shellsortrating(products1)

        elif choice == '3':
            Quicksortprice(products0)
            Shellsortprice(products1)

        elif choice == '4':

            print("Exiting the program. Goodbye!")
            break
        else:
            print("Invalid choice. Please enter a valid option (1-4).")







