#include "User.h"

int User::count = 0;

User::User() {
   // count++;
    name = "";
    age = 0;
   // id = count;
    password = "";
    email = "";
}
User::User(string name, int age, string email, string password) {
    //count++;
    this->name = name;
    this->age = age;
    this->email = email;
    password = password;
    //id = count;
}
User::User(const User &user) {
    //count++;
    this->name = user.name;
    this->age = user.age;
    this->email = user.email;
    this->password = user.password;
    this->id = user.id;
}

bool User::operator == (const User &user) {
    bool isEqual;  //true if user1 = user2
    if ((this->name == user.name) &&
        (this->age == user.age) &&
        (this->email == user.email) &&
        (this->id == user.id)){
            isEqual = true;
        }
    else {
        isEqual = false;
    }
    return isEqual;
}
void User::setName(string name) {
    this->name = name;
}

string User::getName()const {
    return name;
}

void User::setPassword(string password) {
    this->password = password;
}

string User::getPassword() {
    return password;
}

void User::setEmail(string email) {
    this->email = email;
}
string User::getEmail() {
    return email;
}

void User::setAge(int age) {
    this->age = age;
}
int User::getAge() {
    return age;
}

void User::setId(int id) {
    this->id=id;
}
int User::getId() {
    return id;
}

ostream& operator << (ostream &output,  User &user ) {
    output << "================ User " << user.id << "  info =================" << endl
    << "Name: " << user.name << "| Age: " << user.age << "| ID: " << user.id <<
    "| Email: " << user.email << endl
    << "===============================================" << endl;
    return output ;
}

istream& operator >> (istream &input, User &user) {
    string name;
    int age;
    string password;
    string email;
    user.count++;
   // id=count;
    cout << "Enter the user information in this order" << endl
         << "Name Age Email Password (space separated)" << endl;

    input >> name >> age >> email >> password;
    user.setName(name);
    user.setAge(age);
    user.setEmail(email);
    user.setPassword(password);
    user.setId(user.count);

}
