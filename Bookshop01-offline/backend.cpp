//#include <iostream>
//#include <fstream>
//#include <iomanip>
//#include <limits>
//#include <cstring>
//
//
////using namespace std;
////
//class book_data
//{
   /* char books_number[30];
    char Book_Name[50];
    char Author_Name[20];
    int No_Copies;*/
//
//public:
//    void Get_BookDetails()
//    {
//        cout << "\nENTER DETAILS OF YOUR DESIRED BOOK WHICH YOU WANT TO PURCHASE\n";
//        cout << "\nEnter The Book's Number: ";
//        cin >> books_number;
//        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
//        cout << "\nEnter Book's Name: ";
//        cin.getline(Book_Name, 50);
//        cout << "\nEnter The Author's Name: ";
//        cin.getline(Author_Name, 20);
//        cout << "\nEnter No. Of Copies of the desired book: ";
//        cin >> No_Copies;
//    }
//
//    void Show_Book_Data()
//    {
//        cout << "\nBook Number: " << books_number;
//        cout << "\nBook Name: " << Book_Name;
//        cout << "\nAuthor's Name: " << Author_Name;
//        cout << "\nCOPIES: " << No_Copies;
//    }
//
//    void Modify_Book_Data()
//    {
//        cout << "\nBook number: " << books_number;
//        cout << "\nModify Book Name: ";
//        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // Clear input buffer
//        cin.getline(Book_Name, 50);
//        cout << "\nModify Author's Name: ";
//        cin.getline(Author_Name, 20);
//        cout << "\nEnter No. Of Copies: ";
//        cin >> No_Copies;
//    }
//
//    char* get_book_number()
//    {
//        return books_number;
//    }
//
//    void Report()
//    {
//        cout << books_number << setw(30) << Book_Name << setw(30) << Author_Name << setw(30) << No_Copies << endl;
//    }
//};
//
//fstream fp;
//book_data bk;
//
//void clearInputBuffer()
//{
//    cin.clear();
//    cin.ignore(numeric_limits<streamsize>::max(), '\n');
//}
//
//void write_book_data()
//{
//    // Clear screen
//    cout << "\033[2J\033[1;1H";
//
//    int moremain;
//    fp.open("book.dat", ios::out | ios::app);
//    if (!fp)
//    {
//        cout << "Error opening file for writing!";
//        return;
//    }
//
//    do
//    {
//        bk.Get_BookDetails();
//        fp.write((char*)&bk, sizeof(book_data));
//        cout << "\nPress 1 to add some more books to the system";
//        cout << "\nPress 2 to go back to the main menu\n";
//        cout << "Enter your choice: ";
//        cin >> moremain;
//        clearInputBuffer();
//    } while (moremain == 1);
//
//    fp.close();
//}
//
//void Display_books(char n[])
//{
//    // Clear screen
//    cout << "\033[2J\033;1H";
//
//    cout << "\nBOOK DETAILS\n";
//    int check = 0;
//    fp.open("book.dat", ios::in);
//    if (!fp)
//    {
//        cout << "Error opening file for reading!";
//        return;
//    }
//
//    while (fp.read((char*)&bk, sizeof(book_data)))
//    {
//        if (strcmp(bk.get_book_number(), n) == 0)
//        {
//            bk.Show_Book_Data();
//            check = 1;
//        }
//    }
//
//    fp.close();
//    if (check == 0)
//        cout << "\n\nBook does not exist";
//
//    // Wait for user input
//    cout << "\nPress Enter to continue...";
//    clearInputBuffer();
//}
//
//void Modify_Book_Data()
//{
//    // Clear screen
//    cout << "\033[2J\033[1;1H";
//
//    char n[20];
//    int found = 0;
//    cout << "\n\n\tMODIFY BOOK";
//    cout << "\n\n\tEnter The book number: ";
//    cin >> n;
//    clearInputBuffer();
//
//    fp.open("book.dat", ios::in | ios::out);
//    if (!fp)
//    {
//        cout << "Error opening file for reading and writing!";
//        return;
//    }
//
//    while (fp.read((char*)&bk, sizeof(book_data)) && found == 0)
//    {
//        if (strcmp(bk.get_book_number(), n) == 0)
//        {
//            bk.Show_Book_Data();
//            cout << "\nEnter The New Details of book" << endl;
//            bk.Modify_Book_Data();
//            int pos = -1 * sizeof(bk);
//            fp.seekp(pos, ios::cur);
//            fp.write((char*)&bk, sizeof(book_data));
//            cout << "\n\n\t Record Updated Successfully...";
//            found = 1;
//        }
//    }
//
//    fp.close();
//    if (found == 0)
//        cout << "\n\n Record Not Found ";
//
//    // Wait for user input
//    cout << "\nPress Enter to continue...";
//    clearInputBuffer();
//}
//
//void delete_book_data()
//{
//    // Clear screen
//    cout << "\033[2J\033[1;1H";
//
//    char n[20];
//    int flag = 0;
//    cout << "\n\n\n\tDELETE BOOK";
//    cout << "\n\nEnter The Book's number You Want To Delete: ";
//    cin >> n;
//    clearInputBuffer();
//
//    fp.open("book.dat", ios::in | ios::out);
//    if (!fp)
//    {
//        cout << "Error opening file for reading and writing!";
//        return;
//    }
//
//    fstream fp2;
//    fp2.open("Temp.dat", ios::out);
//    if (!fp2)
//    {
//        cout << "Error opening temporary file for writing!";
//        fp.close();
//        return;
//    }
//
//    fp.seekg(0, ios::beg);
//    while (fp.read((char*)&bk, sizeof(book_data)))
//    {
//        if (strcmp(bk.get_book_number(), n) != 0)
//        {
//            fp2.write((char*)&bk, sizeof(book_data));
//        }
//        else
//            flag = 1;
//    }
//
//    fp2.close();
//    fp.close();
//
//    if (flag == 1)
//    {
//        if (rename("Temp.dat", "book.dat") != 0)
//        {
//            perror("Error renaming file");
//        }
//        else
//        {
//            cout << "\n\n\tRecord Deleted ..";
//        }
//    }
//    else
//        cout << "\n\nRecord not found";
//
//    // Wait for user input
//    cout << "\nPress Enter to continue...";
//    clearInputBuffer();
//}
//
//void display_all_books()
//{
//    // Clear screen
//    cout << "\033[2J\033[1;1H";
//
//    fp.open("book.dat", ios::in);
//    if (!fp)
//    {
//        cout << "Error opening file for reading!";
//        return;
//    }
//
//    cout << "\n\n\t\t------Book LIST-------\n\n";
//    cout << "============================================================================================\n";
//    cout << "Book Number" << setw(20) << "Book Name" << setw(25) << "Author" << setw(25) << "Copies" << endl;
//    cout << "============================================================================================\n";
//
//    while (fp.read((char*)&bk, sizeof(book_data)))
//    {
//        bk.Report();
//    }
//
//    fp.close();
//
//    // Wait for user input
//    cout << "\nPress Enter to continue...";
//    clearInputBuffer();
//}

//void intro()
//{
//    // Clear screen
//    cout << "\033[2J\033[1;1H";
//
//    cout << "\t\t\t\t**\t**";
//    // ... (unchanged code)
//}
//
//int main()
//{
//    int option = 0;
//    for (;;)
//    {
//        intro();
//        cout << "\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@";
//        cout << "\n\t\tPress 1 to PURCHASE A BOOK";
//        cout << "\n\t\tPress 2 to DISPLAY ALL BOOKS";
//        cout << "\n\t\tPress 3 to CHECK AVAILABILITY OF THE BOOK IN STORE";
//        cout << "\n\t\tPress 4 to MODIFY BOOK RECORDS";
//        cout << "\n\t\tPress 5 to DELETE BOOK RECORDS";
//        cout << "\n\t\tPress 6 to Exit ";
//        cout << "\n\t\t@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@\n";
//        cout << "\n\t\tOption: ";
//        cin >> option;
//        clearInputBuffer();
//
//        switch (option)
//        {
//        case 1:
//            write_book_data();
//            break;
//        case 2:
//            display_all_books();
//            break;
//        case 3:
//            char num[20];
//            cout << "\n\n\tPlease Enter The book No. ";
//            cin >> num;
//            clearInputBuffer();
//            Display_books(num);
//            break;
//        case 4:
//            Modify_Book_Data();
//            break;
//        case 5:
//            delete_book_data();
//            break;
//        case 6:
//            exit(0);
//            break;
//        default:
//            cout << "\a";
//        }
//    }
//    return 0;
//}


 // add book is working in below code
//#include <fstream>
//#include <iomanip>
//#include <iostream>
//#include <limits>
//#include <sstream>
//#include "httplib.h"
//#include <string>
//
//using namespace std;
//using namespace httplib;
//
//class book_data {
//public:
//  char books_number[30];
//  char Book_Name[50];
//  char Author_Name[20];
//  int No_Copies;
//
//  void Report(ostream &os) const {
//    os << books_number << setw(30) << Book_Name << setw(30) << Author_Name
//       << setw(30) << No_Copies << endl;
//  }
//};
//
//fstream fp;
//book_data bk;
//
//void clearInputBuffer() {
//  cin.clear();
//  cin.ignore(numeric_limits<streamsize>::max(), '\n');
//}
//
//
//  void write_book_data(const Request &req, Response &res) {
//    // Extract data from the request
//    string bookNumber = req.get_param_value("bookNumber");
//    string bookName = req.get_param_value("bookName");
//    string authorName = req.get_param_value("authorName");
//    int copies = stoi(req.get_param_value("copies"));
//
//    // Open file for writing
//    fp.open("book.dat", ios::out | ios::app);
//    if (!fp) {
//      res.set_content("Error opening file for writing!", "text/plain");
//      return;
//    }
//
//    // Write book data
//    strcpy_s(bk.books_number, bookNumber.c_str());
//    strcpy_s(bk.Book_Name, bookName.c_str());
//    strcpy_s(bk.Author_Name, authorName.c_str());
//    bk.No_Copies = copies;
//
//    fp.write((char *)&bk, sizeof(book_data));
//
//    // Close file
//    fp.close();
//
//    // Set response content
//    res.set_content("Book added successfully!", "text/plain");
//  }
//
//  void display_all_books(const Request &req, Response &res) {
//  // Open file for reading
//  fp.open("book.dat", ios::in);
//  if (!fp) {
//    res.set_content("Error opening file for reading!", "text/plain");
//    return;
//  }
//
//  // Create a string to hold book list
//  string bookList;
//
//  // Read book data
//  while (fp.read((char *)&bk, sizeof(book_data))) {
//    stringstream ss;
//    bk.Report(ss);
//    bookList += ss.str();
//  }
//
//  // Close file
//  fp.close();
//
//  // Set response content
//  res.set_content(bookList, "text/plain");
//}
//
//int main() {
//  Server svr;
//
//  // Purchase a book
//  svr.Post("/purchase", write_book_data);
//
//  // Display all books
//  svr.Get("/display", display_all_books);
//
//  // Start the server on port 8080
//  svr.listen("localhost", 8080);
//
//  return 0;
//}













#include <fstream>
#include <iomanip>
#include <iostream>
#include <limits>
#include <sstream>
#include "httplib.h"
#include <string>

using namespace std;
using namespace httplib;

class book_data {
public:
  char books_number[30];
  char Book_Name[50];
  char Author_Name[20];
  int No_Copies;

  void Report(ostream &os) const {
    os << books_number << setw(30) << Book_Name << setw(30) << Author_Name
       << setw(30) << No_Copies << endl;
  }
};

fstream fp;
book_data bk;

void clearInputBuffer() {
  cin.clear();
  cin.ignore(numeric_limits<streamsize>::max(), '\n');
}

void write_book_data(const Request &req, Response &res) {
  // Extract data from the request
  string bookNumber = req.get_param_value("bookNumber");
  string bookName = req.get_param_value("bookName");
  string authorName = req.get_param_value("authorName");
  int copies = stoi(req.get_param_value("copies"));

  // Open file for writing
  fp.open("book.dat", ios::out | ios::app);
  if (!fp) {
    res.set_content("Error opening file for writing!", "text/plain");
    return;
  }

  // Write book data
  strcpy_s(bk.books_number, bookNumber.c_str());
  strcpy_s(bk.Book_Name, bookName.c_str());
  strcpy_s(bk.Author_Name, authorName.c_str());
  bk.No_Copies = copies;

  fp.write((char *)&bk, sizeof(book_data));

  // Close file
  fp.close();

  // Set response content
  res.set_content("Book added successfully!", "text/plain");
}


void display_all_books(const Request &req, Response &res) {
  // Open file for reading
  fp.open("book.dat", ios::in);
  if (!fp) {
    res.set_content("Error opening file for reading!", "text/plain");
    return;
  }

  // Create a string to hold book list
  string bookList;

  // Read book data
  while (fp.read((char *)&bk, sizeof(book_data))) {
    stringstream ss;
    bk.Report(ss);
    bookList += ss.str();
  }

  // Close file
  fp.close();

  // Set response content
  res.set_content(bookList, "text/plain");
}


void search_book(const Request &req, Response &res) {
  // Extract data from the request
  string bookNumber = req.get_param_value("bookNumber");

  // Open file for reading
  fp.open("book.dat", ios::in);
  if (!fp) {
    res.set_content("Error opening file for reading!", "text/plain");
    return;
  }

  // Search for the book
  bool found = false;
  string bookList;

  while (fp.read((char *)&bk, sizeof(book_data))) {
    if (strcmp(bk.books_number, bookNumber.c_str()) == 0) {
      found = true;
      stringstream ss;
      bk.Report(ss);
      bookList += ss.str();
      break;
    }
  }

  // Close file
  fp.close();

  // Set response content
  if (found) {
    res.set_content(bookList, "text/plain");
  } else {
    res.set_content("Book not found!", "text/plain");
  }
}

void update_book(const Request &req, Response &res) {
  // Extract data from the request
  string bookNumber = req.get_param_value("bookNumber");
  string bookName = req.get_param_value("bookName");
  string authorName = req.get_param_value("authorName");
  int copies = stoi(req.get_param_value("copies"));

  // Open file for reading and writing
  fp.open("book.dat", ios::in | ios::out);
  if (!fp) {
    res.set_content("Error opening file for reading and writing!",
                    "text/plain");
    return;
  }

  // Search for the book and update if found
  bool found = false;

  while (fp.read((char *)&bk, sizeof(book_data))) {
    if (strcmp(bk.books_number, bookNumber.c_str()) == 0) {
      found = true;
      strcpy_s(bk.Book_Name, bookName.c_str());
      strcpy_s(bk.Author_Name, authorName.c_str());
      bk.No_Copies = copies;

      // Move the file pointer to update the record
      fp.seekp(sizeof(book_data), ios::cur);
      fp.write((char *)&bk, sizeof(book_data));
      break;
    }
  }

  // Close file
  fp.close();

  // Set response content
  if (found) {
    res.set_content("Book updated successfully!", "text/plain");
  } else {
    res.set_content("Book not found!", "text/plain");
  }
}

void delete_book(const Request &req, Response &res) {
  // Extract data from the request
  string bookNumber = req.get_param_value("bookNumber");

  // Open input file in binary mode
  ifstream inFile("book.dat", ios::binary);
  if (!inFile) {
    res.set_content("Error opening file for reading!", "text/plain");
    return;
  }

  // Open output file in binary mode
  ofstream outFile("temp.dat", ios::binary);
  if (!outFile) {
    res.set_content("Error opening temporary file for writing!", "text/plain");
    inFile.close();
    return;
  }

  // Search for the book and copy records to a temporary file
  bool found = false;

  while (inFile.read((char *)&bk, sizeof(book_data))) {
    if (strcmp(bk.books_number, bookNumber.c_str()) != 0) {
      outFile.write((char *)&bk, sizeof(book_data));
    } else {
      found = true;
    }
  }

  // Close files
  inFile.close();
  outFile.close();

  // Remove the original file
  remove("book.dat");

  // Rename the temporary file to the original file
  rename("temp.dat", "book.dat");

  // Set response content
  if (found) {
    res.set_content("Book deleted successfully!", "text/plain");
  } else {
    res.set_content("Book not found!", "text/plain");
  }
}

int main() {
  Server svr;

  // Purchase a book
  svr.Post("/purchase", write_book_data);

  // Display all books
  svr.Get("/display", display_all_books);

  // Search book
  svr.Get("/search", search_book);

  // Update book
  svr.Put("/update", update_book);

  // Delete book
  svr.Delete("/delete", delete_book);

  // Start the server on port 8080
  svr.listen("localhost", 8080);

  return 0;
}
