class Library_item :
    def __init__(self, title, author, __id_number):
        self.title = title
        self.author = author
        self.__id_number = int(__id_number)

    def display_info(self):
        print("Book / Magzine details :")
        print("Title :",self.title)
        print("Author :",self.author)
        print("ID Number :",self.get_id_number())

    def get_id_number(self):
        return self.__id_number

class Book(Library_item) :

    def __init__(self, title, author, __id_number, genre, is_checked_out):
        super().__init__(title, author, __id_number)
        self.genre = genre
        self.is_checked_out = False

    def checkout_book(self) :
        self.is_checked_out = True

    def display_info(self):
        super().display_info()
        print("Genre :",self.genre)
        print("Availability :",self.is_checked_out)
        return 
    
class Magazine(Library_item) :
    def __init__(self, title, author, __id_number, issue_number, publication_date,is_checked_out):
        super().__init__(title, author, __id_number)
        self.issue_number = int(issue_number)
        self.publication_date = publication_date
        self.is_checked_out = False

    def display_info(self):
        super().display_info()
        print("Issue number :",self.issue_number)
        print("Publication date :",self.publication_date)
        print("Availability :",self.is_checked_out)

    def checkout_Magzine(self) :
        self.is_checked_out = True

print("\n\n\n... WELCOME TO LIBRARY MANAGEMENT SYSTEM ...\n")
print("+--------+-------------------+")
print(f"| {"Number":6} | {"Action to Perform":18}|")
print("+--------+-------------------+")
print(f"| {" 1.":6} | {"Entry for Book":18}|")
print("+--------+-------------------+")
print(f"| {" 2.":6} | {"Entry for Magzine":18}|")
print("+--------+-------------------+")
print(f"| {" 3.":6} | {"Exit SYSTEM":18}|")
print("+--------+-------------------+")

while True :
    choice = int(input("\nPlease enter your choice : "))
    if choice<1 or choice>3 :
        print("... Invalid input ... ")
        print("... Re-enter your input ... ")
        choice = int(input("Please enter your choice as per above : "))        
    else:
        break

if choice == 1:
    print("\n... WELCOME TO BOOK ENTRY ...\n")
    title = input("Enter Book title : ")
    author = input("Enter Book author : ")
    id = int(input("Enter Book ID Number : "))
    genre = input("Enter book genre : ")
    book_obj = Book(title,author,id,genre,True)
    book_obj.checkout_book()
    print("\n...\n")
    book_obj.display_info()

if choice == 2:
    print("\n... WELCOME TO Magzine ENTRY ...\n")
    title = input("Enter Magzine title : ")
    author = input("Enter Magzine author : ")
    id = int(input("Enter Magzine ID Number : "))
    issue_number = input("Enter Magzine ISSUE Number : ")
    date = input("Enter publication date {Y-M-D} : ")
    mag_obj = Magazine(title,author,id,issue_number,date,False)
    mag_obj.checkout_Magzine()
    print("\n...\n")
    mag_obj.display_info()

if choice == 3:
    print("\n... THANK YOU USER ...")
    print("... BYE BYE ...\n")
    exit()

print("\n")





