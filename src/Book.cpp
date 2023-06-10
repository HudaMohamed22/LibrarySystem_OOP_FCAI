#include "Book.h"
int Book::count = 0;

Book::Book() {
    //count++;
    title = "";
    isbn = "";
    category = "";
    averageRating = 0;
    //id = count;
    total = 0;
    num = 0;
    author.setId(0);
//    author.count --;
}
Book::Book(string title, string isbn, string category) {
    //count++;
    this->title = title;
    this->isbn = isbn;
    this->category = category;
    averageRating = 0;
    //id = count;
    total = 0;
    num = 0;
    author.setId(0);
//    author.count --;
}
Book::Book(const Book &book) {
    this->title = book.title;
    this->isbn = book.isbn;
    this->id = book.id;
    this->category = book.category;
    this->averageRating = book.averageRating;
    this->author = book.author;
    this->total = book.total;
    this->num = book.num;
//    author.count --;

}

void Book::setTitle(string title) {
     this->title = title;
}

string Book::getTitle() {
    return title;
}

void Book::setISBN(string isbn) {
    this->isbn = isbn;
}

string Book::getISBN() {
    return isbn;
}

void Book::setId(int id) {
    this->id = id;
}
int Book::getId() {
    return id;
}

void Book::setCategory(string category) {
    this->category = category;
}
string Book::getCategory() {
    return category;
}
void Book::setAuthor(User user) {
    this->author = user;
}
User Book::getAuthor() {
    return author;
}
void Book::rateBook(int rating) {
    total = total + rating;
    num++;
    averageRating = total / num;

}
double Book::getRateBook(){
    return averageRating;
}


bool Book::operator == (const Book &book) {
    bool isEqual;  //true if user1 = user2
    if  ((this->title == book.title) &&
        (this->isbn == book.isbn) &&
        (this->id == book.id) &&
        (this->category == book.category)&&
        (this->author == book.author)) {
            isEqual = true;
        }
    else {
        isEqual = false;
    }
    return isEqual;

}


//
//ostream& operator<<(ostream &output,  Book &book ){
//     if(book.author.getId() != 0){
//        User ob=book.getAuthor();
//        output<<"================ Book "<< book.getId()<<"  info ================="<<endl
//        <<"Title: "<<book.getTitle()<<"| ISBN: "<<book.getISBN()<<"| ID: "<<book.getId()<<
//        "| Category: "<<book.getCategory()<<"| Avg Rating: "<<book.getRate()<<endl
//        <<"===============================================  "<<endl<<ob<<endl;
//        return output ;
//        }
//    else{
//        cout<<"Please Enter Author Info"<<endl;
//    }
//
//}

ostream & operator << (ostream &output,  Book &book ) {
        User ob = book.getAuthor();
        output << "================ Book " << book.id << "  info =================" << endl
        << "Title: " << book.title << "| ISBN: " << book.isbn << "| ID: " << book.id <<
        "| Category: " << book.category<<"| Avg Rating: "<<book.averageRating<<endl
        <<"===============================================  "<<endl;
        if(book.author.getId() != 0){
        output<<"================ Author " << ob.getId() << "  info =================" << endl

        << "Name: " << ob.getName() << "| Age: " << ob.getAge() << "| ID: " << ob.getId() <<
        "| Email: " << ob.getEmail() << endl
        << "===============================================" << endl;

        }
        return output ;
        }

istream & operator >> (istream &input , Book &book) {

    string title;
    string isbn;
    string category;
    book.count++;

    cout<<"Enter the book information in this order"<<endl
        <<"Title ISBN Category (space separated)"<<endl;

    input>>title>>isbn>>category;
    book.setTitle(title);
    book.setISBN(isbn);
    book.setCategory(category);
    book.id=book.count;


}















