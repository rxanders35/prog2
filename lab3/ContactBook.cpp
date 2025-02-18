#include "ContactBook.h"
#include <algorithm>

Contact::Contact(string n, string num) : name(n), number(num) {}

string Contact::getName()
{
    return name;
}

string Contact::getNumber()
{
    return number;
}


void Contact::Display()
{
    cout << name << ", " << number;
}

ContactBook::ContactBook() : curr_size(0) {}

ContactBook::~ContactBook()
{
    for (int i = 0; i < curr_size; i++)
    {
        delete contacts[i];
    }
}

ContactBook::ContactBook(const ContactBook &other) : curr_size(0)
{
    for (int i = 0; i < other.curr_size; i++)
    {
        contacts[curr_size] = new Contact(other.contacts[i]->getName(), other.contacts[i]->getNumber());
        curr_size++;
    }
}

ContactBook &ContactBook::operator=(const ContactBook &other)
{
    if (this == &other)
    {

        for (int i = 0; i < other.curr_size; i++)
        {
            delete contacts[i];
        }
        curr_size = 0;
        for (int i = 0; i < other.curr_size; i++)
        {
            contacts[curr_size] = new Contact(other.contacts[i]->getName(), other.contacts[i]->getNumber());
            curr_size++;
        }
    }
    return *this;
}

Contact *ContactBook::Find(const string &query)
{
    for (int i = 0; i < curr_size; i++)
    {
        if (contacts[i]->getName() == query || contacts[i]->getNumber() == query)
        {
            return contacts[i];
        }
    }
    return nullptr;
}

void ContactBook::Add(Contact &c)
{
    if (curr_size < MAX_SIZE)
    {
        contacts[curr_size] = new Contact(c);
        curr_size++;
    }
}

void ContactBook::AddContacts(vector<Contact *> &contacts)
{
    for (Contact *contact : contacts)
    {
        if (contact != nullptr && curr_size < MAX_SIZE)
        {
            Add(*contact);
        }
    }
}

void ContactBook::Remove(Contact &c)
{
    for (int i = 0; i < curr_size; i++)
    {
        if (*contacts[i] == c)
        {
            delete contacts[i];
            for (int j = i; j < curr_size - 1; j++)
            {
                contacts[j] = contacts[j + 1];
            }
            curr_size--;
            return;
        }
    }
}

void ContactBook::Display()
{
    for (int i = 0; i < curr_size; i++)
    {
        if (contacts[i] != nullptr)
        {
            cout << contacts[i]->getName() << ", " << contacts[i]->getNumber() << endl;
        }
    }
}

void ContactBook::Alphabetize()
{
    sort(contacts, contacts + curr_size,
         [](Contact *a, Contact *b)
         {
             return a->getName() < b->getName();
         });
}

ContactBook &ContactBook::operator+=(Contact &contact)
{
    Add(contact);
    return *this;
}

ContactBook &ContactBook::operator+=(const ContactBook &other)
{
    for (int i = 0; i < other.curr_size && curr_size < MAX_SIZE; i++)
    {
        Add(*other.contacts[i]);
    }
    return *this;
}

ContactBook ContactBook::operator+(const ContactBook other) const
{
    ContactBook res(*this);
    for (int i = 0; i < other.curr_size; i++)
    {
        res.Add(*other.contacts[i]);
    }
    return res;
}

ContactBook &ContactBook::operator-=(Contact &contact)
{
    Remove(contact);
    return *this;
}

ContactBook &ContactBook::operator-=(const ContactBook &other)
{
    for (int i = 0; i < other.curr_size; i++)
    {
        Remove(*(other.contacts[i]));
    }
    return *this;
}

ContactBook ContactBook::operator-(const ContactBook &other) const
{
    ContactBook res = *this;
    for (int i = 0; i < other.curr_size; i++)
    {
        if (other.contacts[i] != nullptr)
        {
            res.Remove(*other.contacts[i]);
        }
    }
    return res;
}

bool ContactBook::operator==(const ContactBook &other) const
{
    if (curr_size != other.curr_size)
    {
        return false;
    }

    for (int i = 0; i < curr_size; i++)
    {
        bool check = false;
        for (int j = 0; j < other.curr_size; j++)
        {
            if (contacts[i]->getName() == other.contacts[j]->getName() &&
                contacts[i]->getNumber() == other.contacts[j]->getNumber())
            {
                check = true;
                break;
            }
        }
        if (!check)
        {
            return false;
        }
    }
    return true;
}

bool Contact::operator==(const Contact &other) const
{
    return (name == other.name && number == other.number);
}
