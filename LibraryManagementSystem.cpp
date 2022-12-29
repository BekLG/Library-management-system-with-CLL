#include<iostream>
using namespace std;

struct book
{
    char title[100];
   /* char author[100]
    int publicationYear;
    char genre[20];
    int numberOfPages;
    float price;
    int shelfNumber;
    int availableCopies; */

    book * next;
};

book *head,*tail,*temp,*current,*q;

void registerBook()
{
     cout<<"register book page"<<endl;
}

void displayAllBooks()
{
    cout<<"display book page"<<endl;
}


void displayByGenre()
{
    string genre;
    cout<<"enter the genre you want to display"<<endl;
    cin>>genre;
    cout<<"display book page  "<<genre;
}


void searchByTitle()
{
    string title;
    cout<<"enter the book title you want to search"<<endl;
    cin>>title;

    cout<<"search book page  "<<title;
}

void searchByAuthor()
{
    string author;
    cout<<"enter the author name you want to search"<<endl;
    cin>>author;

    cout<<"search book page  "<<author;
}

void lendBook()
{
    cout<<"lend book page"<<endl;
}

void returnBook()
{
    cout<<"return book page"<<endl;
}

void displayMenu()
{
    int choice;
    cout<<"welcome to library management System"<<endl<<endl;
    cout<<"enter 1 to register new book"<<endl;
    cout<<"enter 2 to display book list"<<endl;
    cout<<"enter 3 to search book"<<endl;
    cout<<"enter 4 to register lend book"<<endl;
    cout<<"enter 5 to return  book"<<endl;
    cout<<"enter 6 to close application"<<endl;

    cin>>choice;

    switch (choice){
        case 1:
        registerBook();
        break;
        case 2:
        cout<<"book display page"<<endl<<endl;
        cout<<"enter 1 to display all books"<<endl;
        cout<<"enter 2 to display books by genre"<<endl;
        cout<<"enter 3 to  return to main menu"<<endl;

        cin>> choice;
        if(choice==1)
        {
            displayAllBooks();
        }
        else if(choice==2)
        {
            displayByGenre();
        }
        else if(choice==3)
        {
            displayMenu();
        }
        else
        {
            cout<<"invalid choice!";
        }
        break;

        case 3:
        cout<<"book search page"<<endl<<endl;
        cout<<"enter 1 to search book by title"<<endl;
        cout<<"enter 2 to search book by author name"<<endl;
        cout<<"enter 3 to  return to main menu"<<endl;
        cin>> choice;
        if(choice==1)
        {
            searchByTitle();
        }
        else if(choice==2)
        {
            searchByAuthor();
        }
        else if(choice==3)
        {
            displayMenu();
        }
        else
        {
            cout<<"invalid choice!";
        }
        break;

        case 4:
        lendBook();
        break;

        case 5:
        returnBook();
        break;

        case 6:
        exit(0);
        break;

        default:
        cout<<"invalid choice!";
        break;

    }

}


int main()
{


    displayMenu();


}
