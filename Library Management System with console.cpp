#include<iostream>
#include<fstream>
#include<string>
#include<climits>
#include<iomanip>
int BOOK_COUNT = 100;
using namespace std;
struct Book
{
	string bname;
	string aname;
	string category;
	string isbn;
	int id;
};
//Function to add a book
void add_a_book(Book books[], int& numBooks, string bname, string aname, string category, string isbn, int id)
{

	if(numBooks < BOOK_COUNT)
	{
		books[numBooks].bname = bname;
		books[numBooks].aname = aname;
		books[numBooks].category = category;
		books[numBooks].isbn = isbn;
		books[numBooks].id = id;
		numBooks++;
		cout << "Book added successfully.\n";
	}
	else
	{
		cout << "Error! Maximum number of books reached.\n";
	}
}

//Function to delete the books
void delete_a_book(Book books[], int& numBooks, int Id)
{
	int index = -1;
	for(int i = 0; i < numBooks; i++)
	{
		if(books[i].id == Id)
		{
			index = i;
			break;
		}
	}
	if(index != -1)
	{
		for(int i = index; i < numBooks -1; i++)
	{
		books[i] = books[i +1];
	}	
	numBooks--;
	cout << "Book Deleted Successfully\n";
	}
	else
	{
		cout << "Book with Id " << Id << " does not found!\n";	
	}
}

//Function to update a book
void update_a_book(Book books[], int& numBooks, int Id)
{
	int index = -1;
	for(int i = 0; i < numBooks; i++)
	{
		if(books[i].id == Id)
		{
			index = i;
			break;
		}
	}
	if(index != -1)
	{
		string input;
		
		cout << "Enter new Book Name: ";
		cin.ignore();
		getline(cin, input);
		if(!input.empty())
		{
			books[index].bname = input;
		}
		
		cout << "Enter new Author Name: ";
		getline(cin, input);
		if(!input.empty())
		{
			books[index].aname = input;
		}
		
		cout << "Enter the new Category: ";
		getline(cin, input);
		if(!input.empty())
		{
			books[index].category = input;
		}
		
		cout << "Enter new ISBN NO: ";
		getline(cin, input);
		if(!input.empty())
		{
			books[index].isbn = input;
		}
		
		cout << "Book details updated successfully.\n";
	}
	else
	{
		cout << "Book with Id " << Id << " does not found.\n";
	}
	
}

//Function to print all the books
void print_all_books(Book books[], int numBooks)
{
	if(numBooks == 0)
	{
		cout << "No books available.\n";
	}
	else
	{
		int field_width = 15;
		cout << "All Books:\n";
		cout << "------------------------------------------------------" << endl;
		cout << "------------------------------------------------------" << endl;
		cout << left << setw(field_width) << "Book Name";
		cout << setw(field_width) << "Author Name";
		cout << setw(field_width) << "Category";
		cout << setw(field_width) << "ISBN NO";
		cout << setw(field_width) << "Id" << endl;
		for(int i = 0; i < numBooks; i++) // Changed loop condition to < numBooks
		{	
			cout << setw(field_width) << books[i].bname;
			cout << setw(field_width) << books[i].aname;
			cout << setw(field_width) << books[i].category;
			cout << setw(field_width) << books[i].isbn;
			cout << setw(field_width) << books[i].id << endl;
		}
	}
}

//Function to Search a book
void search_a_books(Book books[], int& numBooks, int id)
{
	int index = -1;
	for(int i = 0; i < numBooks; i++)
	{
		if(books[i].id == id)
		{
			index = i;	
			break;
		}
	}
	if(index != -1)
	{
		cout << "Book Found.\n";
		int field_width = 15;
		cout << left << setw(field_width) << "Book Name";
		cout << setw(field_width) << "Author Name";
		cout << setw(field_width) << "Category";
		cout << setw(field_width) << "ISBN NO";
		cout << setw(field_width) << "Id" << endl;
		cout << setw(field_width) << books[index].bname;
		cout << setw(field_width) << books[index].aname;
		cout << setw(field_width) << books[index].category;
		cout << setw(field_width) << books[index].isbn;
		cout << setw(field_width) << books[index].id << endl;	
	}
	else
	{
		cout << "Book with id " << id << " does not found.\n";
		
	}
}

//Main Function of Project
int main() 
{
	const string filename = "Books.txt";
	Book books[BOOK_COUNT];
	int numBooks = 0;
    cout << "               " << "Library Management System" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "1. Add a book" << endl;
    cout << "2. Delete a book" << endl;
    cout << "3. Update a book" << endl;
    cout << "4. Get all the books" << endl;
    cout << "5. Search a book" << endl;
    cout << "------------------------------------------------------" << endl;
    cout << "------------------------------------------------------" << endl;
    char choice,  ch;
    do 
	{
        cout << "Enter your choice: ";
        cin >> choice;
        cout << "------------------------------------------------------" << endl;
        cout << "------------------------------------------------------" << endl;
        switch(choice)
		{
            case '1': 
			{
                string bname, aname, isbn, category;
				int id;
                cout << "Enter the Book Name: ";
                cin.ignore();
                getline(cin, bname);
                cout << "Enter the Author Name: ";
                getline(cin, aname);
                cout << "Enter the category of Book: ";
                getline(cin, category);
                cout << "Enter the ISBN No: ";
                getline(cin, isbn);
                cout << "Enter the Id of Book: ";
                cin >> id;
                add_a_book(books, numBooks, bname, aname, category, isbn, id);
                break;
            }
            case '2': 
			{
                int Id;
                cout << "Enter id to delete Book: ";
                cin >> Id;
                cin.ignore();
                delete_a_book(books, numBooks, Id);
				break;
			}
			case '3':
			{
				int Id;
				cout << "Enter id to update a book: ";
				cin >> Id;
				update_a_book(books, numBooks, Id);
				break;	
			}
			case '4':
				{
				 print_all_books(books, numBooks);
				 break;	
				}
			case '5':
				{
					int id;
					cout << "Enter Id to seach a Book: ";
					cin >> id;
					search_a_books(books, numBooks, id);
					break;
				}
            default:
                cout << "Invalid choice" << endl;
				break; // Added break statement for default case
		} 	
		cout << "------------------------------------------------------" << endl;
		cout << "------------------------------------------------------" << endl;    
		cout << "Do you want to continue (y/n): ";
		cin >> ch;
		cout << "------------------------------------------------------" << endl;
		cout << "------------------------------------------------------" << endl;
		 
	} while(ch == 'y'); // Moved while condition outside the switch statement

	return 0;
}
