#ifndef BOOKLIST_H
#define BOOKLIST_H
#include "Book.h"



class BookList
{
    private:
        Book *books;    //array of objects of books.
        int capacity;   // size of the array
        int bookscount; //count how many books in array
    public:
        BookList(const BookList& anotherList);  //copy constructor to copy the bookList to another list
        BookList(int capacity); //Parametrize constructor  take capacity and send it to array to store users in it
        void addBook(Book book);    //fun to add one book to th array of books
        Book* searchBook(string name ); //to search for book by name
        Book* searchBook(int id);   //to search for book by id
        void deleteBook(int id);    //to delete book from the list of books
        Book getTheHighestRatedBook();  // display the book which has the highest rate
        Book* getBooksForUser(User);  // get all books of this author
        Book & operator[ ](int position);   //Operator overloading to display the array by its index
        friend ostream &operator << (ostream &output, BookList &booklist);  ////friend fun to display all users at book list

        ~BookList();    //destructor to free memory by delete books pointer




};

#endif // BOOKLIST_H
