#include <iostream>
#include <string>
#include "User.h"
#include "Book.h"
#include "UserList.h"
#include "BookList.h"

using namespace std;

int main()
{
    int choose1;
    int numofusers;
    int userchoose1;
    int usersearchChoose;
    int userchoose2;
    int numofbooks;
    int bookchoose1;
    int bookchoose2;
    int booksearchChoose;
    int bookchoose3;
    //int bookchoose4;

    UserList *userlist=NULL;
    while (true)
    {
        cout<< "Select one of the following choice "<<endl<<"1-Books Menu"
        <<endl<< "2-Users Menu"<<endl<<"3-Exit"<<endl;
        cin>>choose1;
        if (choose1==1)
        {
            cout<<"How Many Books will be added ?"<<endl;
            cin>>numofbooks;
            BookList booklist(numofbooks);

            while(true )
            {    cout <<"BOOK MENU"<<endl<< "1-Create a BOOK and add it to the list"<<
                 endl<<"2-Search for a BOOK "<<
                 endl<<"3-Display all BOOKS  (with book rating)"<<endl<<"4-Get The Highest Book Rate" <<
                 endl<<"5-Get All Books Of A User  "<<endl<<"6-Copy The Current Book List To A New Book List "<<
                 endl<<"7-Back To The Main Menu"<<endl;

                 cin>>bookchoose1;

                 if (bookchoose1==1)
                 {
                    Book book;
                    cin>>book;
                    while(true){
                        cout <<"1-Assign author"<<endl<< "2-continue"<<endl;
                        cin>>bookchoose2;
                        if(bookchoose2==1)
                        {
                            int id;
                            cout<<"Please Enter User ID "<<endl;
                            cin >>id;
                            if(userlist==NULL || userlist->searchUser(id)==NULL)
                            {
                                cout<<" No Author Found with Id = "<<id<<endl;
                                //booklist.addBook(book);
                            }


                            else
                            {
                                book.setAuthor(*(userlist->searchUser(id)));
                                booklist.addBook(book);
                                cout <<" Assign Author successfully "<<endl;
                                break;
                            }
                        }

                        else if (bookchoose2==2)
                        {
                            booklist.addBook(book);
                            break;

                        }
                        else{
                            cout<<"Enter valid choose"<<endl;
                        }



                     }

                 }

                 else if (bookchoose1==2)
                 {
                     while(true)
                    {
                       cout<<"SEARCH FOR A BOOK"<<endl<<"1-Search by name"<<endl<<"2-Search by id "<<
                        endl<<"3-Return to Users Menu"<<endl;
                        cin>>booksearchChoose;
                        if( booksearchChoose == 1)
                        {
                            string Name;
                            cout<<"Enter Name"<<endl;
                            cin>>Name;
                            if(booklist.searchBook(Name)==NULL)
                            {
                                cout<<"Not Found"<<endl;
                            }
                            else
                            {
                                cout<<*(booklist.searchBook(Name))<<endl;
                                Book *book2;
                                book2=(booklist.searchBook(Name));
                                while(true)
                                {
                                    cout<<"1-Update Author "<<endl<<"2-Update Name  "<<endl<<"3-Update Category  "<<endl<<"4-Delete Book"
                                    <<endl<<"5-Rate Book  "<<endl<<"6-Get backs to Book Menu  "<<endl;
                                    cin>>bookchoose3;
                                    if (bookchoose3==1)

                                    {
                                        User user;
                                        cout <<" Enter New Author ";
                                        cin>>user;
                                        book2->setAuthor(user);
//

                                    }
                                    else if (bookchoose3==2)

                                    {   string newname;
                                        cout <<" Enter New Name ";
                                        cin>>newname;
                                        book2->setTitle(newname);


                                    }

                                    else if (bookchoose3==3)
                                    {
                                        string newcatecory;
                                        cout <<" Enter New Category ";
                                        cin>>newcatecory;
                                        book2->setCategory(newcatecory);
                                    }

                                    else if (bookchoose3==4)
                                    {
                                        booklist.deleteBook(book2->getId());
                                    }

                                    else if (bookchoose3==5)
                                    {
                                        int rate;
                                        cout <<" Enter Book Rate ";
                                        cin>>rate;
                                        book2->rateBook(rate);
                                        cout <<" Rate Book successfully "<<endl;

                                    }

                                    else if (bookchoose3==6)
                                    {
                                        break;
                                    }

                                    else
                                    {
                                       cout<<"Please Enter Valid Number" <<endl;
                                    }


                                } break;


                            }
                        }


                        else if ( booksearchChoose == 2 )
                        {
                            int id;
                            cout<<"Enter ID"<<endl;
                            cin>>id;
                             if(booklist.searchBook(id)==NULL)
                            {
                                cout<<"Not Found"<<endl;
                            }
                            else
                            {
                                cout<<*(booklist.searchBook(id))<<endl;
                                Book *book3;
                                book3=(booklist.searchBook(id));
                                while(true)
                                {
                                    cout<<"1-Update Author "<<endl<<"2-Update Name  "<<endl<<"3-Update Category  "<<endl<<"4-Delete Book"
                                    <<endl<<"5-Rate Book  "<<endl<<"6-Get backs to Book Menu  "<<endl;
                                    cin>>bookchoose3;
                                    if (bookchoose3==1)

                                    {
                                        User user;
                                        cout <<" Enter New Author ";
                                        cin>>user;
                                        book3->setAuthor(user);
//

                                    }
                                    else if (bookchoose3==2)

                                    {   string newname;
                                        cout <<" Enter New Name ";
                                        cin>>newname;
                                        book3->setTitle(newname);


                                    }

                                    else if (bookchoose3==3)
                                    {
                                        string newcatecory;
                                        cout <<" Enter New Category ";
                                        cin>>newcatecory;
                                        book3->setCategory(newcatecory);
                                    }

                                    else if (bookchoose3==4)
                                    {
                                        booklist.deleteBook(id);
                                    }

                                    else if (bookchoose3==5)
                                    {
                                        int rate;
                                        cout <<" Enter Book Rate ";
                                        cin>>rate;
                                        book3->rateBook(rate);
                                        cout <<" Rate Book successfully "<<endl;

                                    }

                                    else if (bookchoose3==6)
                                    {
                                        break;
                                    }

                                    else
                                    {
                                       cout<<"Please Enter Valid Number" <<endl;
                                    }


                                } break;

                            }



                        }

                        else if( usersearchChoose == 3)
                        {
                            break;
                        }
                        else
                        {
                           cout<<"Please Enter Valid Number" <<endl;
                        }

                    }


                 }

                  else if (bookchoose1==3)
                 {
                    cout<<booklist;
                 }
                  else if (bookchoose1==4)
                 {
                     Book book;
                     book=booklist.getTheHighestRatedBook();
                     cout<<book;
                 }
                  else if (bookchoose1==5)
                 {
                     cout << "Enter ID" << endl;
                     int id;
                     cin >> id;
                     booklist.getBooksForUser(*(userlist->searchUser(id)));

                 }
                  else if (bookchoose1==6)
                 {
                     BookList booklist2(booklist);
                     cout<<booklist2;

                 }
                    else if (bookchoose1==7)
                 {
                     break;
                 }
                 else
                 {
                      cout<<"Please Enter Valid Number" <<endl;
                 }

            }












        }
        else if(choose1==2)
        {
            cout<<"How Many Users will be added ?"<<endl;
            cin>>numofusers;
            userlist=new UserList (numofusers);
           while(true)
           {
               cout <<"USERS MENU"<<endl<< "1-Create a USER and add it to the list"<<endl<<"2-Search for a USER "<<
               endl<<"3-Display all USERS "<<endl<<"4-Back to the main menu"<<endl;
//               <<endl<<"4-Delete User"
               cin>>userchoose1;
                if (userchoose1 == 1)
                {
                    User user;
                    cin>>user;
                    userlist->addUser(user);

                }
                else if (userchoose1 == 2)
                {
                    while(true)
                    {
                       cout<<"SEARCH FOR A USER"<<endl<<"1-Search by name"<<endl<<"2-Search by id "<<
                        endl<<"3-Return to Users Menu"<<endl;
                        cin>>usersearchChoose;
                        if( usersearchChoose == 1)
                        {
                            string Name;
                            cout<<"Enter Name"<<endl;
                            cin>>Name;
                            if(userlist->searchUser(Name)==NULL)
                            {
                                cout<<"Not Found"<<endl;
                            }
                            else
                            {
                                cout<<*(userlist->searchUser(Name))<<endl;
                                while(true)
                                {
                                    cout<<"1-Delete User "<<endl<<"2-Return to Users Menu "<<endl;
                                    cin>>userchoose2;
                                    if (userchoose2==1)

                                    {   User deleteName=*(userlist->searchUser(Name));
                                        userlist->deleteUser(deleteName.getId());
                                        break;
                                    }
                                    else if (userchoose2==2)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                       cout<<"Please Enter Valid Number" <<endl;
                                    }


                                }


                            }
                        }


                        else if ( usersearchChoose == 2 )
                        {
                            int id;
                            cout<<"Enter ID"<<endl;
                            cin>>id;
                             if(userlist->searchUser(id)==NULL)
                            {
                                cout<<"Not Found"<<endl;
                            }
                            else
                            {
                                cout<<*(userlist->searchUser(id))<<endl;
                                 while(true)
                                {
                                    cout<<"1-Delete User "<<endl<<"2-Return to Users Menu "<<endl;
                                    cin>>userchoose2;
                                    if (userchoose2==1)

                                    {
                                        userlist->deleteUser(id);
                                        break;
                                    }
                                    else if (userchoose2==2)
                                    {
                                        break;
                                    }
                                    else
                                    {
                                       cout<<"Please Enter Valid Number" <<endl;
                                    }

                                }


                            }



                        }

                        else if( usersearchChoose == 3)
                        {
                            break;
                        }
                        else
                        {
                           cout<<"Please Enter Valid Number" <<endl;
                        }

                    }


                }
                else if (userchoose1 == 3)
                {
//                      if(userlist=nullptr)
//                    {
//                        cout<<" Not Found Any User  ";
//
//                    }
//                    else
//                    {
                        cout<<*(userlist)<<endl;
//                    }

                }
//

                else if (userchoose1 == 4)
                {
                    break;
                }
                else
                {
                    cout<<"Please Enter Valid Number" <<endl;
                }
           }


        }
        else if(choose1==3)
        {
            break;
        }
        else
        {
           cout<<"Please Enter Valid Number" <<endl;
        }

    }

    return 0;
}



