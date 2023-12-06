import csv
from timeit import default_timer as timer

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



def PartitionTitle(vec, startIndex, endIndex):

    x = vec[endIndex]

    y = startIndex - 1

    for i in range(startIndex, endIndex):
        if vec[i].title <= x.title:
            y += 1
            (vec[y], vec[i]) = (vec[i], vec[y])

    (vec[y+1], vec[endIndex]) = (vec[endIndex], vec[y+1])
    return y+1

def PartitionRating(vec, startIndex, endIndex):
    x = vec[endIndex]
    y = startIndex - 1

    for i in range(startIndex, endIndex):
        if vec[i].stars < x.stars or (vec[i].stars == x.stars and vec[i].title < x.title):
            y += 1
            vec[y], vec[i] = vec[i], vec[y]

    vec[y + 1], vec[endIndex] = vec[endIndex], vec[y + 1]
    return y + 1
def PartitionPrice(vec, startIndex, endIndex):

    x = vec[endIndex]

    y = startIndex - 1

    for i in range(startIndex, endIndex):
        if vec[i].price <= x.price:
            y += 1
            (vec[y], vec[i]) = (vec[i], vec[y])

    (vec[y+1], vec[endIndex]) = (vec[endIndex], vec[y+1])
    return y+1

def Quicksorttitle(vec, startIndex, endIndex):

    if startIndex < endIndex:
        x = PartitionTitle(vec, startIndex, endIndex)

        Quicksorttitle(vec, startIndex, x-1)

        Quicksorttitle(vec, x+1, endIndex)



def Shellsortrating(vec):

    val = len(vec) // 2

    while val > 0:
        for i in range(val, len(vec)):
            temp = vec[i]
            j = i
            while j >= val and (vec[j - val].stars > temp.stars or (vec[j - val].stars == temp.stars and vec[j - val].title > temp.title)):
                vec[j] = vec[j - val]
                j -= val
            vec[j] = temp
        val //= 2

def Quicksortrating(vec, startIndex, endIndex):
    if startIndex < endIndex:
        x = PartitionRating(vec, startIndex, endIndex)
        Quicksortrating(vec, startIndex, x - 1)
        Quicksortrating(vec, x + 1, endIndex)


def Shellsortprice(vec):

    val = len(vec) // 2

    while val > 0:
        for i in range(val, len(vec)):
            temp = vec[i]
            j = i
            while j >= val and vec[j - val].price > temp.price:
                if vec[j - val].price == temp.price and vec[j - val].title > temp.title:
                    break  # Maintain stability by checking title
                vec[j] = vec[j - val]
                j -= val
            vec[j] = temp
        val //= 2


def Quicksortprice(vec, startIndex, endIndex):

    if startIndex < endIndex:
        x = PartitionPrice(vec, startIndex, endIndex)

        Quicksortprice(vec, startIndex, x-1)

        Quicksortprice(vec, x+1, endIndex)

def Print10(vec):
    print("The top 10 results of this search are:")
    print()
    for i in range(10):
        print(vec[len(vec)-i-1].title)
        print()


class Product:
    def __init__(self, title, stars, price, category):
        self.title = title  # string title
        self.stars = stars  # float stars
        self.price = price  # float price
        self.category = category  # int category


if __name__ == "__main__":
    while True:
        ex = input("Welcome to Amazon Product Sorter! Input x to exit and any other character to continue ")
        print()
        cat = ""

        if ex == 'x':
            exit()

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
                        stars = float(j)
                        # print(j)
                    if x == 6:
                        price = float(j)
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
            qstart = timer()
            Quicksorttitle(products0, 0, len(products0)-1)
            qend = timer()
            qsort_time = qend-qstart

            print(f"Quicksort time: {qsort_time}")
            Print10(products0)

            sstart = timer()
            Shellsorttitle(products1)
            send = timer()
            ssort_time = send-sstart

            print(f"Shellsort time: {ssort_time}")
            Print10(products1)

        elif choice == '2':
            qstart = timer()
            Quicksortrating(products0, 0, len(products0)-1)
            qend = timer()
            qsort_time = qend-qstart

            print(f"Quicksort time: {qsort_time}")
            Print10(products0)

            sstart = timer()
            Shellsortrating(products1)
            send = timer()
            ssort_time = send-sstart

            print(f"Shellsort time: {ssort_time}")
            Print10(products1)

        elif choice == '3':
            qstart = timer()
            Quicksortprice(products0, 0, len(products0)-1)
            qend = timer()
            qsort_time = qend-qstart

            print(f"Quicksort time: {qsort_time}")
            Print10(products0)

            sstart = timer()
            Shellsortprice(products1)
            send = timer()
            ssort_time = send-sstart

            print(f"Shellsort time: {ssort_time}")
            Print10(products1)

        elif choice == '4':

            print("Exiting the program. Goodbye!")
            break
        else:
            print("Invalid choice. Please enter a valid option (1-4).")

