#include "BookList.h"
#include "Book.h"


BookList::BookList(int capacity)
{
    bookscount=0;
    this->capacity=capacity;
    books=new Book[capacity];

}
BookList:: BookList(const BookList& anotherList)
{
    capacity=anotherList.capacity;
    books=new Book[capacity];
    bookscount=anotherList.bookscount;

    for (int i=0 ; i<bookscount ; i++)
    {
        books[i]=anotherList.books[i];

    }
}

void BookList::addBook(Book book)
{
    books[bookscount]=book;
    bookscount++;
}

Book* BookList::searchBook(string name )
{   for(int i=0; i<bookscount ;i++)
    {
        if (books[i].getTitle()==name){

            return &(books[i]);
        }
    }
    return NULL ;

}
Book* BookList::searchBook(int id )
{   for(int i=0; i<bookscount ;i++)
    {
        if (books[i].getId()==id){

            return &(books[i]);
        }
    }
    return NULL ;

}

void BookList::deleteBook(int id)
{
    if(id<capacity &&id >=0)
    {
        for(int i=0; i<bookscount ;i++)
        {
            if (books[i].getId()==id){
                bookscount--;
                for(int j=i ; j<bookscount ; j++)
                {
                    books[j]=books[j+1];

                }

                break;
            }
        }
    }



}

Book BookList ::getTheHighestRatedBook()
{
    double theMax=books[0].getRateBook();
    cout<<"inside book rate   "<<bookscount<<endl;
    int maxBookIndex=0;
    for(int i=1; i<bookscount ;i++)
    {
        if(books[i].getRateBook()>theMax)
        {
            theMax=books[i].getRateBook();
            maxBookIndex = i;
        }
    }
    return books[maxBookIndex];
}

Book* BookList::getBooksForUser(User user)
{
    Book* bookArrTemp=new Book[bookscount];
    int counter=0;
    string authorname;
   for(int i=0; i<bookscount ;i++)
   {
        if(user==books[i].getAuthor())
        {

            bookArrTemp[counter]=books[i];
            cout<<"============= Book "<<books[i].getId()<<" Info =================="<<endl;
            cout<<"Title: " <<books[i].getTitle()<<endl;
            cout<<"ISBN: " <<books[i].getISBN()<<endl;
            cout<<"ID: "<<books[i].getId()<<endl;
            cout<<"Category: " <<books[i].getCategory()<<endl;
            cout<<"Avg Rating: "<<books[i].getRateBook()<<endl;
            authorname=books[i].getAuthor().getName();
            counter++;
        }
   }cout<<"Author : "<<authorname<<endl;
    Book* bookArr = new Book[counter];
    for(int i =0 ; i<counter ;i++)
    {
        bookArr[i]=bookArrTemp[i];
    }
   return bookArr;
}

Book & BookList::operator[ ](int position)
{
    return books[position];
}


ostream& operator << (ostream &output, BookList &booklist)
{
    for(int i=0; i<(booklist.bookscount) ;i++)
    {
        output<<booklist.books[i];
    }
    return output;
}


BookList::~BookList()
{
   delete[]books;
}
