#include<iostream>
#include <iomanip>
using namespace std;

struct book
{
    string title;
    string author;
    int numberOfPages;
    int publicationYear;
    string genre;
    int shelfNumber;
    int availableCopies;

    book * next;
};

book *head,*tail,*temp,*current,*q,*p;  //declaration of necessary pointers
string titleGV,authorGV,genreGV;        //declaration of global variables
bool found= false;
int numberOfPagesGV,publicationYearGV,shelfNumberGV,availableCopiesGV;  // GV means Global Variable

void displayMenu();   //declaration of functions
void registerBook();
void displayAllBooks();
void displayByGenre();
void searchByTitle();
void searchByAuthor();
void lendBook();
void returnBook();
void waitAndDisplayMenu();
void deleteBook();

int main()
{
    displayMenu();
}

void registerBook()
{
     temp= new book;

    cin.ignore();
        cout<<"Enter Title Of The Book: ";
	    getline(cin,titleGV);
	    cout<<"Enter author Of The Book: ";
	    getline(cin,authorGV);
	    cout<<"Enter genre Of The Book: ";
	    getline(cin,genreGV);

	    cout<<"Enter page Of The Book: ";
	    cin>>numberOfPagesGV;
	    cout<<"Enter publication year Of The Book: ";
	    cin>>publicationYearGV;
	    cout<<"Enter available copies Of The Book: ";
	    cin>>availableCopiesGV;
	    cout<<"Enter location/ shelf number Of The Book: ";
	    cin>>shelfNumberGV;

        cin.ignore();

	    temp->title=titleGV;
	    temp->author=authorGV;
	    temp->genre=genreGV;
	    temp->numberOfPages=numberOfPagesGV;
	    temp->publicationYear=publicationYearGV;
	    temp->availableCopies=availableCopiesGV;
	    temp->shelfNumber=shelfNumberGV;


    if(tail==NULL){//if the list is empty linked list will instantiated.
               tail=temp;
               head=temp;
               tail->next=head;
            }
            else{//if the node is already instantiated, the new node will be inserted at a given position.
                    current=tail;
                 do{
                        int res=titleGV.compare(current->title);//compare book name string in the new node with the list to get the position, to make the list is sorted by book name.
                        q=current->next;
                    if(res < 0 && current == head){//at the begining.
                          p=head;
                          head=temp;
                          temp->next=p;
                          p=temp;
                          tail->next=temp;

                        }

                       else if(res >0){

                               if(current==tail){//At the end.
                                    temp->next=head;
                                    tail->next=temp;
                                    tail=temp;
                               }
                               if(q->title >= titleGV && res >0){//N_th position
                                    temp->next=q;
                                    current->next=temp;
                               }
                       }
                       current=current->next;//traverse to all nodes to compare the string.

		           }while(current!=tail);//till the end of the linked list.
}
            displayMenu();
}

void displayAllBooks()
{
    cout<<"display book page"<<endl;

      current=tail->next;
      cout<<"====================================================================================================================================================+"<<endl;
      cout<<setw(5)<<"* "<<setw(25)<<"TITLE"<<" |"<<setw(25)<<"AUTHOR"<<" |"<<setw(20)<<"GENRE"<<" |"<<setw(15)<<"No OF PAGES"<<" |"<<setw(15)<<"PUB-YEAR"<<" |"<<setw(15)<<"AV-COPIES"<<" |"<<setw(15)<<"SHELF-No"<<" |" <<endl;
    do
    {
             cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl;
             cout<<setw(5)<<"* "<<setw(25)<<current->title<<" |"<<setw(25)<<current->author<<" |"<<setw(20)<<current->genre<<" |"<<setw(15)<<current->numberOfPages<<" |"<<setw(15)<<current->publicationYear<<" |"<<setw(15)<<current->availableCopies<<" |"<<setw(15)<<current->shelfNumber<<" |" <<endl;

        //cout<<current->title<<" "<<current->author<<" "<<current->genre<<" "<<current->numberOfPages<<" "<<current->publicationYear<<" "<<current->availableCopies<<" "<<current->shelfNumber<<endl;
        current=current->next;
    }
    while(current!=tail->next);
      cout<<"====================================================================================================================================================+"<<endl;

    waitAndDisplayMenu();
}
void displayByGenre()
{

    cout<<"enter the genre you want to display"<<endl;
    cin>>genreGV;

      current=tail->next;
             cout<<"====================================================================================================================================================+"<<endl;
             cout<<setw(5)<<"* "<<setw(25)<<"TITLE"<<" |"<<setw(25)<<"AUTHOR"<<" |"<<setw(20)<<"GENRE"<<" |"<<setw(15)<<"No OF PAGES"<<" |"<<setw(15)<<"PUB-YEAR"<<" |"<<setw(15)<<"AV-COPIES"<<" |"<<setw(15)<<"SHELF-No"<<" |" <<endl;
    do
    {
        if(genreGV.compare(current->genre) ==0)
        {
             cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl;
             cout<<setw(5)<<"* "<<setw(25)<<current->title<<" |"<<setw(25)<<current->author<<" |"<<setw(20)<<current->genre<<" |"<<setw(15)<<current->numberOfPages<<" |"<<setw(15)<<current->publicationYear<<" |"<<setw(15)<<current->availableCopies<<" |"<<setw(15)<<current->shelfNumber<<" |" <<endl;
        }

        current=current->next;
    }
    while(current!=tail->next);
            cout<<"====================================================================================================================================================+"<<endl;


    waitAndDisplayMenu();
}

void searchByTitle()
{

    cout<<"enter the book title you want to search"<<endl;
    cin>>titleGV;

     current=tail->next;
    do
    {
        if(titleGV.compare(current->title) ==0)
        {
            found= true;
             cout<<"found..."<<endl;
             cout<<"====================================================================================================================================================+"<<endl;
             cout<<setw(5)<<"* "<<setw(25)<<"TITLE"<<" |"<<setw(25)<<"AUTHOR"<<" |"<<setw(20)<<"GENRE"<<" |"<<setw(15)<<"No OF PAGES"<<" |"<<setw(15)<<"PUB-YEAR"<<" |"<<setw(15)<<"AV-COPIES"<<" |"<<setw(15)<<"SHELF-No"<<" |" <<endl;
             cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl;
             cout<<setw(5)<<"* "<<setw(25)<<current->title<<" |"<<setw(25)<<current->author<<" |"<<setw(20)<<current->genre<<" |"<<setw(15)<<current->numberOfPages<<" |"<<setw(15)<<current->publicationYear<<" |"<<setw(15)<<current->availableCopies<<" |"<<setw(15)<<current->shelfNumber<<" |" <<endl;

             cout<<"====================================================================================================================================================+"<<endl;

        }

        current=current->next;
    }
    while(current!=tail->next);

    if(found==false)
    {
         cout<<"Sorry, no matches found! check your spelling and try again"<<endl;
    }

    waitAndDisplayMenu();
}

void searchByAuthor()
{

    cout<<"enter the author name you want to search"<<endl;
    cin>>authorGV;

      current=tail->next;
    do
    {
        if(authorGV.compare(current->author) ==0)
        {
            found= true;
             cout<<"====================================================================================================================================================+"<<endl;
             cout<<setw(5)<<"* "<<setw(25)<<"TITLE"<<" |"<<setw(25)<<"AUTHOR"<<" |"<<setw(20)<<"GENRE"<<" |"<<setw(15)<<"No OF PAGES"<<" |"<<setw(15)<<"PUB-YEAR"<<" |"<<setw(15)<<"AV-COPIES"<<" |"<<setw(15)<<"SHELF-No"<<" |" <<endl;
             cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------+"<<endl;
             cout<<setw(5)<<"* "<<setw(25)<<current->title<<" |"<<setw(25)<<current->author<<" |"<<setw(20)<<current->genre<<" |"<<setw(15)<<current->numberOfPages<<" |"<<setw(15)<<current->publicationYear<<" |"<<setw(15)<<current->availableCopies<<" |"<<setw(15)<<current->shelfNumber<<" |" <<endl;

             cout<<"====================================================================================================================================================+"<<endl;
        }

        current=current->next;
    }
    while(current!=tail->next);

    if(found==false)
    {
         cout<<"Sorry, no matches found! check your spelling and try again"<<endl;
    }

    waitAndDisplayMenu();
}

void lendBook()
{
    cout<<"lend book page"<<endl<<endl;


    cout<<"enter the book title you want to lend"<<endl;
    cin>>titleGV;

      current=tail->next;
    do
    {
        if(titleGV.compare(current->title) ==0) //check if the wanted book is in the list
        {
            found= true;
            if(current->availableCopies > 0)    //if the book is available on the shelf/ if no of copies is greater than zero
            {
                current->availableCopies --;
                cout<<"success, "<<current->availableCopies<<" copies of "<<current->title <<" book are left on the shelf" ;
            }
            else
            {
                cout<<"sorry, this book is not available";
            }

        }
        current=current->next;
    }
    while(current!=tail->next);

    if(found==false)
    {
         cout<<"Sorry, no matches found! check your spelling and try again"<<endl;
    }

   waitAndDisplayMenu();

}

void returnBook()
{
    cout<<"return book page"<<endl<<endl;


    cout<<"enter the book title you want to return"<<endl;
    cin>>titleGV;

     current=tail->next;
    do
    {
        if(titleGV.compare(current->title) ==0)
        {
            found= true;

            current->availableCopies = current->availableCopies + 1;
            cout<<"success, "<<current->availableCopies<<" copies of "<<current->title << " book are left on the shelf"<<endl;
            current=current->next;
        }
    }

    while(current!=tail->next);

    if(found==false)
    {
         cout<<"Sorry, no matches found! check your spelling and try again"<<endl;
    }

    waitAndDisplayMenu();
}

void deleteBook()
{
    cout<<"enter the book title you want to delete"<<endl;
    cin>>titleGV;

    if(head == tail && titleGV.compare(head->title) ==0) // there is only one node
    {
        delete head;
        cout<<"book deleted sucessfully"<<endl;
    }
    else    //there are more than 1 nodes, so we have to search and delete
    {
        current=tail->next;
        q=tail;
        do
        {
            if(titleGV.compare(current->title) ==0)
            {
                found= true;
                q->next= current->next;
                delete current;
                cout<<"book deleted sucessfully"<<endl;

            }
        current=current->next;
        q=q->next;
    }
    while(current!=tail->next);

    if(found==false)
    {
         cout<<"Sorry, no matches found! check your spelling and try again"<<endl;
    }
    }


    waitAndDisplayMenu();

}

void displayMenu()
{
    system("clear");
    int choice;
    cout<<"welcome to library management System"<<endl<<endl;
    cout<<"enter 1 to register new book"<<endl;
    cout<<"enter 2 to display book list"<<endl;
    cout<<"enter 3 to search book"<<endl;
    cout<<"enter 4 to lend book"<<endl;
    cout<<"enter 5 to return  book"<<endl;
    cout<<"enter 6 to delete  book"<<endl;
    cout<<"enter 7 to close application"<<endl;

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
            system("clear");
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
            system("clear");
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
        deleteBook();
        break;

        case 7:
        exit(0);
        break;

        default:
        cout<<"invalid choice!";
        break;

    }
}

void waitAndDisplayMenu()
{
    int choice;
    cout<<"press 1 to continue, other keys to exit"<<endl;
    while (1)
    {
      cin>>choice;
      if (choice == 1)
      {
        displayMenu();
        break;
      }
      else
      {
        exit(0);
      }
    }
}
