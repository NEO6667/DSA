class Car:
    # class variable
    total_car = 0

    def __init__(self, brand, model):
        # encapsulation(2underscore in front)
        self.__brand=brand
        self.model=model
        Car.total_car += 1
        
    def get_brand(self):
        return self.__brand + " !"
        
    def fullname(self):
        return f"{self.__brand} {self.model}"
    
    # polymorphism
    def fuel_type(self):
        return "Petrol or diesel"

# inheritance
class ElectricCar(Car):
    def __init__(self, brand, model, battery_size):
        super().__init__(brand, model)
        self.battery_size=battery_size
        
    def fuel_type(self):
        return "Electric Charge"
    
my_car = Car("range", "rover")
print(my_car.get_brand())
print(my_car.fullname())

e_car = ElectricCar("tata","punch","55kWh")

print(e_car.fullname())
print(e_car.battery_size)

print(Car.total_car)


"""
Question 1 — Basic OOP
Create a Python class called BankAccount with:
An attribute owner
An attribute balance
A method deposit(amount) that adds money
A method withdraw(amount) that subtracts money only if sufficient balance exists
A method display_balance() that prints the current balance

Example:
account = BankAccount("Alice", 1000)
account.deposit(500)
account.withdraw(300)
account.display_balance()

Expected output:
Balance: 120
"""
class BankAccount:
    def __init__(self, owner, balance):
        self.owner = owner
        self.balance = balance
        
    def deposit(self, amount):
        self.balance += amount
    
    def withdraw(self, amount):
        if amount <= self.balance:
            # self.amount = amount
            self.balance -= amount
    
    def display_balance(self):
        print(self.balance)
        
account = BankAccount("Alice", 1000)
account.deposit(500)
account.withdraw(300)
account.display_balance()

print("Q2"+"-"*25)


"""
Question 2 — Basic → Intermediate
Create a class called Student.
It should have:
name
marks — a list of marks
calculate_average() — returns the average marks
get_grade() — returns:
"A" if average ≥ 80
"B" if average ≥ 60
"C" if average ≥ 40
"F" if average < 40

Example:
student = Student("John", [85, 72, 90, 78])

print(student.calculate_average())
print(student.get_grade())

Expected:
81.25
A
"""

class Student:
    def __init__(self, name, marks:list):
        self.name = name
        self.marks = marks

    def calculate_average(self):
        total = sum(self.marks)
        cnt = len(self.marks)
        return total/cnt

    def get_grade(self):
        avg = self.calculate_average()
        if avg >= 80:
            return "A"
        elif avg >= 60:
            return "B"
        elif avg >= 40:
            return "C"
        else: 
            return "F"

student = Student("John", [85, 72, 90, 78])

print(student.calculate_average())
print(student.get_grade())

print("Q3"+"-"*25)

"""
Question 3 — Intermediate
Now let's test inheritance + method overriding.

Create an Employee class with:

name

salary

give_raise(percent) → increases salary by that percentage

display_salary() → returns salary

Then create a Manager class that inherits from Employee.

Manager should additionally have:

bonus

Override display_salary() so it returns:

salary + bonus

Example:

emp = Employee("Alice", 50000)
emp.give_raise(10)
print(emp.display_salary())

Expected:

55000

And:

manager = Manager("Bob", 80000, 10000)
print(manager.display_salary())

Expected:

90000
"""

class Employee:
    def __init__(self, name:str, salary:int):
        self.name = name
        self.salary = salary
    
    def give_raise(self, percent):
        new_salary = self.salary + self.salary*(percent/100)
        self.salary = new_salary
        return new_salary

    def display_salary(self):
        return self.salary

class Manager(Employee):
    def __init__(self, name, salary, bonus):
        super().__init__(name, salary)
        self.bonus = bonus

    def display_salary(self):
        return self.salary+self.bonus
    

emp = Employee("Alice", 50000)
emp.give_raise(10)
print(emp.display_salary())

manager = Manager("Bob", 80000, 10000)
print(manager.display_salary())


print("Q4"+"-"*25)


"""
Question 4 — Advanced
Now let's test polymorphism + abstraction.
Create an abstract base class called Shape with an abstract method:
area()

Then create these subclasses:
Circle(radius)
Rectangle(width, height)
Triangle(base, height)

Each class should implement its own area() method.

Use Python's abc module:

from abc import ABC, abstractmethod

Expected behavior:

shapes = [
    Circle(5),
    Rectangle(10, 4),
    Triangle(6, 3)
]

for shape in shapes:
    print(shape.area())

Expected output:
78.5
40
9.0

Important requirements
Shape must inherit from ABC
area() must use @abstractmethod
Each subclass must override area()
Use one loop to calculate the areas — don't check if Circle, if Rectangle, etc.
"""

from abc import ABC, abstractmethod

class Shape(ABC):
    @abstractmethod
    def area(self):
        pass

class Circle(Shape):
    def __init__(self, radius):
        self.radius = radius
    
    def area(self):
        return 3.14*self.radius*self.radius
    
class Rectangle(Shape):
    def __init__(self, width, height):
        self.width = width
        self.height = height
    
    def area(self):
        return self.height*self.width

class Triangle(Shape):
    def __init__(self, base, height):
        self.base = base
        self.height = height
    
    def area(self):
        return 0.5*self.base*self.height

shapes = [
    Circle(5),
    Rectangle(10, 4),
    Triangle(6, 3)
]

for shape in shapes:
    print(shape.area())


print("Q5"+"-"*25)


"""
Question 5 — Advanced 🚀
This is your final and hardest question.

Build a small Library Management System using OOP.

You need three classes:

1. Book
Attributes:

title

author

is_available — initially True

Methods:

display_info() → displays/returns the book's title and author

borrow() → makes the book unavailable

return_book() → makes the book available again

A book should not be borrowed if it is already borrowed.

2. Library
Attributes:

name

books — a list of Book objects

Methods:

add_book(book) → adds a book

show_books() → displays all books and their availability

find_book(title) → finds and returns a book by title

borrow_book(title) → borrows a book

return_book(title) → returns a book

3. Member
Attributes:

name

borrowed_books — initially an empty list

Methods:

borrow_book(library, title)

return_book(library, title)

show_borrowed_books()

Rules
A member:

Can borrow a book only if it exists and is available.

When borrowed, the book should be added to borrowed_books.

When returned, it should be removed from borrowed_books.

Should not be able to return a book they haven't borrowed.

Example usage
Your code should support something like:

book1 = Book("Python Basics", "John Smith")
book2 = Book("OOP in Python", "Jane Doe")

library = Library("Central Library")

library.add_book(book1)
library.add_book(book2)

member = Member("Alice")

member.borrow_book(library, "Python Basics")
member.show_borrowed_books()

member.return_book(library, "Python Basics")
member.show_borrowed_books()

"""
class Book:
    def __init__(self, title, author):
        self.title = title
        self.author = author
        self.is_available = True

    def display_info(self):
        return f"{self.title} by {self.author}"

    def borrow(self):
        if self.is_available:
            self.is_available = False
            return True
        return False

    def return_book(self):
        self.is_available = True


class Library:
    def __init__(self, name):
        self.name = name
        self.books = []

    def add_book(self, book):
        self.books.append(book)

    def find_book(self, title):
        for book in self.books:
            if book.title == title:
                return book
        return None

    def show_books(self):
        for book in self.books:
            status = "Available" if book.is_available else "Borrowed"
            print(f"{book.display_info()} - {status}")

    def borrow_book(self, title):
        book = self.find_book(title)

        if book is None:
            return False

        return book.borrow()

    def return_book(self, title):
        book = self.find_book(title)

        if book is None:
            return False

        book.return_book()
        return True


class Member:
    def __init__(self, name):
        self.name = name
        self.borrowed_books = []

    def borrow_book(self, library, title):
        book = library.find_book(title)

        if book is None:
            print("Book not found.")
            return

        if book.borrow():
            self.borrowed_books.append(book)
            print(f"{self.name} borrowed '{book.title}'.")
        else:
            print(f"'{book.title}' is not available.")

    def return_book(self, library, title):
        book = library.find_book(title)

        if book is None:
            print("Book not found.")
            return

        if book in self.borrowed_books:
            book.return_book()
            self.borrowed_books.remove(book)
            print(f"{self.name} returned '{book.title}'.")
        else:
            print(f"{self.name} did not borrow '{book.title}'.")

    def show_borrowed_books(self):
        if not self.borrowed_books:
            print("No borrowed books.")
            return

        print(f"{self.name}'s borrowed books:")

        for book in self.borrowed_books:
            print(f"- {book.display_info()}")


# Creating books
book1 = Book("Python Basics", "John Smith")
book2 = Book("OOP in Python", "Jane Doe")

# Creating library
library = Library("Central Library")

# Adding books
library.add_book(book1)
library.add_book(book2)

# Creating member
member = Member("Alice")

# Show library
library.show_books()

# Borrow
member.borrow_book(library, "Python Basics")

# Show member's books
member.show_borrowed_books()

# Show library again
library.show_books()

# Return
member.return_book(library, "Python Basics")

# Show member's books again
member.show_borrowed_books()

# Show library again
library.show_books()
