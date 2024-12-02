# Favourite Unique Personal Library

This project is a **book collection management program** designed to help avid readers efficiently organize their personal libraries. Written in C, the program provides a variety of features to manage up to 30 books, ensuring a seamless and structured approach to handling literary collections.

## Features

- Add books with unique titles, authors, and subjects.
- Delete specific books or all books by an author.
- Search for books by title or author.
- List books by specific authors, subjects, or in original order.

## Input and Output

- **Input:** Operations are read from `library.txt`, with commands to add, delete, search, or list books.
- **Output:** Results are displayed on the screen and saved in `output.txt`, ensuring all operations are logged.

## Implementation Highlights

- Implements a structured design using `struct` for book and library management.
- Adheres to Standard C11 for compatibility and efficient memory usage.
- Uses linked lists for flexible and dynamic data management.

## Requirements

- A compatible C compiler (e.g., GCC or CodeBlocks).
- Input file `library.txt` with commands and book details.

## Getting Started

1. Clone this repository.
2. Prepare the `library.txt` file with the desired operations.
3. Compile the program using your preferred C11-compatible compiler.
4. Run the executable and review the results in the output file.

## Example Input
12
1 TOM_SAWYER TWAIN FICTION
1 Intro_to_C_Programming King Computer_Science
4 Huckleberry_Finn
1 Huckleberry_Finn TWAIN FICTION
1 Guns,Germs,Steel Diamond Anthropology
1 Java5.0 Cohoon Computer_Science
6 Twain
7 computer_science
7 Computr_Science
2 Intro_to_C_Programming
6 king
8

##Example Output
The book TOM_SAWYER author TWAIN subject FICTION has been added to the library.

The book Intro_to_C_Programming author King subject Computer_Science has been added to the library.

The Book Huckleberry_Finn is currently not in the library.

The book Huckleberry_Finn author TWAIN subject FICTION has been added to the library.

The book Guns,Germs,Steel author Diamond subject Anthropology has been added to the library.

The book Java5.0 author Cohoon subject Computer_Science has been added to the library.

List of all books by TWAIN
Huckleberry_Finn
TOM_SAWYER

List of all books on COMPUTER_SCIENCE
Java5.0
Intro_to_C_Programming

List of all books on COMPUTR_SCIENCE
No related book for COMPUTR_SCIENCE is found in the library.

The book Intro_to_C_Programming has been removed from the library.

List of all books on KING
No related book for KING is found in the library.

List all the books in original order.
TOM_SAWYER TWAIN FICTION
Guns,Germs,Steel Diamond Anthropology
Huckleberry_Finn TWAIN FICTION
Java5.0 Cohoon Computer_Science

The book TOM_SAWYER author TWAIN subject FICTION has been added to the library.

The book Intro_to_C_Programming author King subject Computer_Science has been added to the library.

The Book Huckleberry_Finn is currently not in the library.

The book Huckleberry_Finn author TWAIN subject FICTION has been added to the library.

The book Guns,Germs,Steel author Diamond subject Anthropology has been added to the library.

The book Java5.0 author Cohoon subject Computer_Science has been added to the library.

List of all books by TWAIN
Huckleberry_Finn
TOM_SAWYER

List of all books on COMPUTER_SCIENCE
Java5.0
Intro_to_C_Programming

List of all books on COMPUTR_SCIENCE
No related book for COMPUTR_SCIENCE is found in the library.

The book Intro_to_C_Programming has been removed from the library.

List of all books on KING
No related book for KING is found in the library.

List all the books in original order.
TOM_SAWYER TWAIN FICTION
Guns,Germs,Steel Diamond Anthropology
Huckleberry_Finn TWAIN FICTION
Java5.0 Cohoon Computer_Science


