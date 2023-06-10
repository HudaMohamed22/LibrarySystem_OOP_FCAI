#ifndef USERLIST_H
#define USERLIST_H
#include<cstring>
#include<iostream>
#include "User.h"


class UserList
{
    private:
        User *users;   //array of objects
        int capacity;   // size of the array
        int userscount; //count how many users in array

    public:
        UserList(int capacity);     //Parametrize constructor  take capacity and send it to array to store users in it
        void addUser(User user);    //fun to add one user to th array of users
        User *searchUser(int id );  //to search for users by name
        User *searchUser(string name);  //to search for a user by id
        void deleteUser(int id);    //to delete user from the list of users
        friend ostream &operator <<(ostream &output ,UserList &userlist );  //friend fun to display all users at userlist
        ~UserList();   //destructor to free memory by delete users pointer





};

#endif // USERLIST_H
