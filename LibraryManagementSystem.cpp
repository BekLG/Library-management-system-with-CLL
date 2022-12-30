#include<iostream>
using namespace std;

struct book
{
    string title;
    string author;
    int numberOfPages;
  //  string id;
    int publicationYear;
    string genre;
  //  float price;
    int shelfNumber;
    int availableCopies;

    book * next;
};

book *head,*tail,*temp,*current,*q,*p;  //declaration of necessary pointers
string titleGV,authorGV,genreGV;        //declaration of global variables
int numberOfPagesGV,publicationYearGV,shelfNumberGV,availableCopiesGV;  // GV means Global Variable


void displayMenu();   //declaration of functions
void registerBook();
void displayAllBooks();
void displayByGenre();
void searchByTitle();
void searchByAuthor();
void lendBook();
void returnBook();


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

	  // cin>>book_name;

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
    do
    {
        cout<<current->title<<" "<<current->author<<" "<<current->genre<<" "<<current->numberOfPages<<" "<<current->publicationYear<<" "<<current->availableCopies<<" "<<current->shelfNumber<<endl;
        current=current->next;
    }
    while(current!=tail->next);

    displayMenu();
}


void displayByGenre()
{

    cout<<"enter the genre you want to display"<<endl;
    cin>>genreGV;
    cout<<"display book page  "<<genreGV;
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
    system("clear");
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
        exit(0);
        break;

        default:
        cout<<"invalid choice!";
        break;

    }

}



