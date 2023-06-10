#include "User.h"
#include "UserList.h"

UserList::UserList(int capacity)
{
    userscount=0;
    this->capacity=capacity;
    users=new User[capacity];

}
void UserList::addUser(User user)
{
    users[userscount]=user;
    userscount++;
}
User* UserList::searchUser(int id )
{
    for(int i=0; i<userscount ;i++)
    {
        if (users[i].getId()==id){

            return &(users[i]);
        }
    }
    return NULL ;
}
User* UserList::searchUser(string name )
{
    for(int i=0; i<userscount ;i++)
    {
        if (users[i].getName()==name){

            return &(users[i]);
        }
    }
    return NULL ;
}

void UserList::deleteUser(int id)
{
    if(id<capacity &&id >=0)
    {
        for(int i=0; i<userscount ;i++)
        {
            if (users[i].getId()==id){
                userscount--;
                for(int j=i ; j<userscount ; j++)
                {
                    users[j]=users[j+1];

                }

                break;
            }
        }
    }



}
ostream &operator <<(ostream &output ,UserList &userlist )
{

    for(int i=0; i<userlist.userscount ;i++)
    {
        output<<userlist.users[i];
    }
    return output;
}


UserList::~UserList()
{
   delete[]users;
}
