#include <string>
#include <vector>
#include <iostream>
#include <string>

using namespace std;

class Contact
{
public:
    Contact(string name, string number);
    bool operator==(const Contact &other) const;
    string getName();
    string getNumber();
    void Display();

private:
    string name;
    string number;
};

class ContactBook
{
public:
    ContactBook();
    ~ContactBook();
    ContactBook(const ContactBook &other);
    ContactBook &operator=(const ContactBook &other);

    Contact *Find(const string &query);
    void Add(Contact &c);
    void AddContacts(vector<Contact *> &contacts);
    void Remove(Contact &c);
    void Display();
    void Alphabetize();

    ContactBook &operator+=(Contact &contact);
    ContactBook &operator+=(const ContactBook &other);
    ContactBook operator+(const ContactBook other) const;
    ContactBook &operator-=(Contact &contact);
    ContactBook &operator-=(const ContactBook &other);
    ContactBook operator-(const ContactBook &other) const;
    bool operator==(const ContactBook &other) const;
    bool operator!=(const ContactBook &other) const;

private:
    static const int MAX_SIZE = 100;
    Contact *contacts[MAX_SIZE];
    uint curr_size = 0;
};