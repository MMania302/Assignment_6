#include "HashTable.h"
#include <iostream>
#include <sstream>
#include <fstream>
using namespace std;
int displayMenu(){
    cout << "======Main Menu======" << endl;
    cout << "1. Insert movie" << endl;
    cout << "2. Delete movie" << endl;
    cout << "3. Find movie" << endl;
    cout << "4. Print table contents" << endl;
    cout << "5. Quit" << endl;
    int menuOpt;
    string stringMenuOpt;
    getline(cin,stringMenuOpt);
    stringstream streamMenuOpt(stringMenuOpt);
    streamMenuOpt>>menuOpt;
    return menuOpt;
}
int main(int argc, char *argv[]){
    if(argc==1){
        HashTable movies;
        int menu = displayMenu();
        while(menu!=5){
            if(menu==1){
                cout << "Enter title:" << endl;
                int movieYear;
                string stringMovieYear;
                string movieName;
                getline(cin,movieName);
                cout << "Enter year:" << endl;
                getline(cin,stringMovieYear);
                stringstream streamMovieYear(stringMovieYear);
                streamMovieYear>>movieYear;
                movies.insertMovie(movieName,movieYear);
            }
            else if(menu==2){
                cout << "Enter title:" << endl;
                string movieToDelete;
                getline(cin,movieToDelete);
                movies.deleteMovie(movieToDelete);
            }
            else if(menu==3){
                cout << "Enter title:" << endl;
                string movieFind;
                getline(cin,movieFind);
                movies.findMovie(movieFind);
            }
            else if(menu==4){
                movies.printTableContents();
            }
            menu = displayMenu();
        }
        cout << "Goodbye!" << endl;
    }

    return 0;
}
