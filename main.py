import csv

products0 = []
products1 = []

class Product:
    def __init__(self, title, stars, price, category):
        self.title = title  # string title
        self.stars = stars  # float stars
        self.price = price  # float price
        self.category = category  # int category

# Open the CSV file
with open('amazon_products.csv', newline='', encoding="utf8") as csvfile:
    # Create a CSV reader
    reader = csv.reader(csvfile)

    # Read and print 10 lines from the CSV file
    for i in reader:
        row = next(reader, None)  # Read the next line
        if row is None:
            break  # If the end of file is reached, break the loop
        #print(row)
        x = 0
        title = ""
        stars = 0.00
        price = 0.00
        category = 0

        for j in row:

            if x == 1:
                title = j
                #print(j)
            if x == 4:
                stars = j
                #print(j)
            if x == 6:
                price = j
                #print(j)
            if x == 8:
                category = j
                #print(j)



            x += 1

        temp0 = Product(title, stars, price, category)
        temp1 = Product(title, stars, price, category)

        products0.append(temp0)
        products1.append(temp1)