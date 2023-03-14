# Library Management System
 C++ Project
This is a C++ project for a library management system that allows users to perform various functions such as registering new books, displaying book lists sorted alphabetically or categorized by genre, searching for books by title and author name, lending and returning books, and deleting books. The project is implemented using circular linked list data structure. 


# Functionality
This library management system allows users to perform the following functions:

Register a new book with details such as book title, author name, genre, and publication date.

Display a list of all books sorted alphabetically or categorized by genre.

Search for a book by title or author name.
Lend a book to a user by updating the book's status.

Return a book by updating the book's status.
Delete a book from the library.

The system also provides error handling for invalid inputs and displays appropriate messages to the user.




# Data Structure

The project uses circular linked list data structure to manage the books in the library. A circular linked list is a type of linked list where the last node points to the first node, creating a loop. This allows for efficient traversal of the list in both directions.

Each node in the circular linked list represents a book in the library and contains information such as book title, author name, genre, publication date, and book status (lent or available).