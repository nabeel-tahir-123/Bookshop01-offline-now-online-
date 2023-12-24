#include <iostream>
#include <fstream>
#include <iomanip>
#include <limits>

using namespace std;

class book_data
{
    char books_number[30];
    char Book_Name[50];
    char Author_Name[20];
    int No_Copies;

public:
    void Get_BookDetails()
    {
        cout << "\nENTER DETAILS OF YOUR DESIRED BOOK WHICH YOU WANT TO PURCHASE\n";
        cout << "\nEnter The Book's Number: ";
        cin >> books_number;
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        cout << "\nEnter Book's Name: ";
        cin.getline(Book_Name, 50);
        cout << "\nEnter The Author's Name: ";
        cin.getline(Author_Name, 20);
        cout << "\nEnter No. Of Copies of the desired book: ";
        cin >> No_Copies;
    }

    void Show_Book_Data()
    {
        cout << "\nBook Number: " << books_number;
        cout << "\nBook Name: " << Book_Name;
        cout << "\nAuthor's Name: " << Author_Name;
        cout << "\nCOPIES: " << No_Copies;
    }

    void Modify_Book_Data()
    {
        cout << "\nBook number: " << books_number;
        cout << "\nModify Book Name: ";
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
        cin.getline(Book_Name, 50);
        cout << "\nModify Author's Name: ";
        cin.getline(Author_Name, 20);
        cout << "\nEnter No. Of Copies: ";
        cin >> No_Copies;
    }

    char* get_book_number()
    {
        return books_number;
    }

    void Report()
    {
        cout << books_number << setw(30) << Book_Name << setw(30) << Author_Name << setw(30) << No_Copies << endl;
    }
};

fstream fp;
book_data bk;

void clearInputBuffer()
{
    cin.clear();
    cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void write_book_data()
{
    // Clear screen
    cout << "\033[2J\033[1;1H";

    int moremain;
    fp.open("book.dat", ios::out | ios::app);
    if (!fp)
    {
        cout << "Error opening file for writing!";
        return;
    }

    do
    {
        bk.Get_BookDetails();
        fp.write((char*)&bk, sizeof(book_data));
        cout << "\nPress 1 to add some more books to the system";
        cout << "\nPress 2 to go back to the main menu\n";
        cout << "Enter your choice: ";
        cin >> moremain;
        clearInputBuffer();
    } while (moremain == 1);

    fp.close();
}

void Display_books(char n[])
{
    // Clear screen
    cout << "\033[2J\033;1H";

    cout << "\nBOOK DETAILS\n";
    int check = 0;
    fp.open("book.dat", ios::in);
    if (!fp)
    {
        cout << "Error opening file for reading!";
        return;
    }

    while (fp.read((char*)&bk, sizeof(book_data)))
    {
        if (strcmp(bk.get_book_number(), n) == 0)
        {
            bk.Show_Book_Data();
            check = 1;
        }
    }

    fp.close();
    if (check == 0)
        cout << "\n\nBook does not exist";

    // Wait for user input
    cout << "\nPress Enter to continue...";
    clearInputBuffer();
}

void Modify_Book_Data()
{
    // Clear screen
    cout << "\033[2J\033[1;1H";

    char n[20];
    int found = 0;
    cout << "\n\n\tMODIFY BOOK";
    cout << "\n\n\tEnter The book number: ";
    cin >> n;
    clearInputBuffer();

    fp.open("book.dat", ios::in | ios::out);
    if (!fp)
    {
        cout << "Error opening file for reading and writing!";
        return;
    }

    while (fp.read((char*)&bk, sizeof(book_data)) && found == 0)
    {
        if (strcmp(bk.get_book_number(), n) == 0)
        {
            bk.Show_Book_Data();
            cout << "\nEnter The New Details of book" << endl;
            bk.Modify_Book_Data();
            int pos = -1 * sizeof(bk);
            fp.seekp(pos, ios::cur);
            fp.write((char*)&bk, sizeof(book_data));
            cout << "\n\n\t Record Updated Successfully...";
            found = 1;
        }
    }

    fp.close();
    if (found == 0)
        cout << "\n\n Record Not Found ";

    // Wait for user input
    cout << "\nPress Enter to continue...";
    clearInputBuffer();
}

void delete_book_data()
{
    // Clear screen
    cout << "\033[2J\033[1;1H";

    char n[20];
    int flag = 0;
    cout << "\n\n\n\tDELETE BOOK";
    cout << "\n\nEnter The Book's number You Want To Delete: ";
    cin >> n;
    clearInputBuffer();

    fp.open("book.dat", ios::in | ios::out);
    if (!fp)
    {
        cout << "Error opening file for reading and writing!";
        return;
    }

    fstream fp2;
    fp2.open("Temp.dat", ios::out);
    if (!fp2)
    {
        cout << "Error opening temporary file for writing!";
        fp.close();
        return;
    }

    fp.seekg(0, ios::beg);
    while (fp.read((char*)&bk, sizeof(book_data)))
    {
        if (strcmp(bk.get_book_number(), n) != 0)
        {
            fp2.write((char*)&bk, sizeof(book_data));
        }
        else
            flag = 1;
    }

    fp2.close();
    fp.close();
    remove("book.dat");
    rename("Temp.dat", "book.dat");

    if (flag == 1)
        cout << "\n\n\tRecord Deleted ..";
    else
        cout << "\n\nRecord not found";

    // Wait for user input
    cout << "\nPress Enter to continue...";
    clearInputBuffer();
}

void display_all_books()
{
    // Clear screen
    cout << "\033[2J\033[1;1H";

    fp.open("book.dat", ios::in);
    if (!fp)
    {
        cout << "Error opening file for reading!";
        return;
    }

    cout << "\n\n\t\t------Book LIST-------\n\n";
    cout << "============================================================================================\n";
    cout << "Book Number" << setw(20) << "Book Name" << setw(25) << "Author" << setw(25) << "Copies" << endl;
    cout << "============================================================================================\n";

    while (fp.read((char*)&bk, sizeof(book_data)))
    {
        bk.Report();
    }

    fp.close();

    // Wait for user input
    cout << "\nPress Enter to continue...";
    clearInputBuffer();
}

void intro()
{
    // Clear screen
    cout << "\033[2J\033[1;1H";

    cout << "\t\t\t\t**\t**";
    // ... (unchanged code)
}

int main()
{
    int option = 0;
    for (;;)
    {
        intro();
        cout << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
        cout << "\n\t\tPress 1 to PURCHASE A BOOK";
        cout << "\n\t\tPress 2 to DISPLAY ALL BOOKS";
        cout << "\n\t\tPress 3 to CHECK AVAILABILITY OF THE BOOK IN STORE";
        cout << "\n\t\tPress 4 to MODIFY BOOK RECORDS";
        cout << "\n\t\tPress 5 to DELETE BOOK RECORDS";
        cout << "\n\t\tPress 6 to Exit ";
        cout << "\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
        cout << "\n\t\tOption: ";
        cin >> option;
        clearInputBuffer();

        switch (option)
        {
        case 1:
            write_book_data();
            break;
        case 2:
            display_all_books();
            break;
        case 3:
            char num[20];
            cout << "\n\n\tPlease Enter The book No. ";
            cin >> num;
            clearInputBuffer();
            Display_books(num);
            break;
        case 4:
            Modify_Book_Data();
            break;
        case 5:
            delete_book_data();
            break;
        case 6:
            exit(0);
            break;
        default:
            cout << "\a";
        }
    }
    return 0;
}
