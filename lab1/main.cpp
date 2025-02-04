#include <iostream>
#include <string>
#include <vector>
#include <iomanip>
using namespace std;

int process(const string &s)
{
        int count = 0;
        for (char c : s)
        {
                if (c == ',')
                {
                        ++count;
                }
        }
        return count;
}

int print_data(string title, string col1, string col2, vector<string> names, vector<int> numbers)
{
        cout << setw(33) << right << title << endl;
        cout << left << setw(20) << col1 << "|" << setw(23) << right << col2 << endl;
        cout << "--------------------------------------------" << endl;

        for (int i = 0; i < names.size(); ++i)
        {
                cout << left << setw(20) << names[i] << "|"
                     << right << setw(23) << numbers[i] << endl;
        }
        cout << endl;

        for (int i = 0; i < names.size(); ++i)
        {
                cout << right << setw(20) << names[i] << " ";
                for (int j = 0; j < numbers[i]; ++j)
                {
                        cout << "*";
                }
                cout << endl;
        }
        return 0;
}
int main()
{
        string title;
        cout << "Enter a title for the data:\n";
        getline(cin, title);
        cout << "You entered: " << title << "\n";

        string col1;
        cout << "Enter the column 1 header:\n";
        getline(cin, col1);
        cout << "You entered: " << col1 << "\n";

        string col2;
        cout << "Enter the column 2 header:\n";
        getline(cin, col2);
        cout << "You entered: " << col2 << "\n";

        vector<int> numbers;
        vector<string> names;

        while (1)
        {
                string data_point;
                cout << "Enter a data point (-1 to stop input):\n";
                getline(cin, data_point);
                if (data_point == "-1")
                {
                        cout << endl;
                        break;
                }

                int commas = process(data_point);
                if (commas > 1)
                {
                        cout << "Error: Too many commas in input.\n";
                }
                if (commas == 0)
                {
                        cout << "Error: No comma in string.\n";
                }
                else if (commas == 1)
                {
                        size_t comma_find = data_point.find(',');
                        string name = data_point.substr(0, comma_find);
                        string number_as_string = data_point.substr(comma_find + 1);

                        try
                        {
                                int number = stoi(number_as_string);
                                names.push_back(name);
                                numbers.push_back(number);
                                cout << "Data string: " << name << "\n";
                                cout << "Data integer: " << number << "\n";
                        }
                        catch (const invalid_argument &e)
                        {
                                cout << "Error: Comma not followed by an integer.\n";
                                continue;
                        }
                        catch (const out_of_range &e)
                        {
                                cout << "Error: Out of Range\n";
                                continue;
                        }
                }
        }
        print_data(title, col1, col2, names, numbers);

        return 0;
}

/*
   Until the user types "-1":
   Get input for a string
   Validate input
   If valid...
      Split
      Validate second half of input
      If also valid...
         Store separate pieces
*/

//   Print out data in table format

//   Print out data in chart format