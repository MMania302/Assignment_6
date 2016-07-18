#include "HashTable.h"
#include <iostream>
HashTable::HashTable(){
    for(int i = 0;i<10;i++){
        hashTable[i] = NULL;
    }
}
int HashTable::hashSum(std::string name,int hashSize){
    int newSum = 0;
    for(int i = 0;i<name.length();i++){
        newSum = newSum + name[0];
    }
    return newSum%hashSize;
}
void HashTable::insertMovie(std::string name,int year){
    int index = hashSum(name,10);
    //std::cout << index << ":" << name << std::endl;
    if(hashTable[index]==NULL){
        //std::cout << "index empty" << std::endl;
        HashElem* tmp = new HashElem(name,year);
        hashTable[index] = tmp;
        //std::cout << hashTable[index]->title << std::endl;
    }
    else if(hashTable[index]!=NULL){
        HashElem* newMovie = new HashElem(name,year);
        HashElem* tmp = hashTable[index];
        while(tmp->next!=NULL){
            tmp = tmp->next;
        }
        tmp->next = newMovie;
        newMovie->previous = tmp;
    }
}
void HashTable::deleteMovie(std::string name){
    int index = hashSum(name,10);
    if(hashTable[index]->next==NULL){
        hashTable[index]=NULL;
    }
    else if(hashTable[index]->title==name&&hashTable[index]->next!=NULL){
        HashElem* tmp = hashTable[index];
        hashTable[index] = hashTable[index]->next;
        hashTable[index]->previous = NULL;
        delete tmp;
    }
    else if(hashTable[index]->title!=name&&hashTable[index]->next!=NULL){
        HashElem* tmp = hashTable[index];
        while(tmp->title!=name&&tmp!=NULL){
            tmp = tmp->next;
        }
        if(tmp==NULL){
            std::cout << "Movie not found" << std::endl;
        }
        else if(tmp!=NULL&&tmp->next!=NULL){
            HashElem* movieDel = tmp;
            tmp = tmp->next;
            tmp->previous = movieDel->previous;
            movieDel->previous->next = tmp;
            delete movieDel;
        }
        else if(tmp!=NULL&&tmp->next==NULL){
            tmp->previous->next = NULL;
            delete tmp;
        }
    }
}
void HashTable::findMovie(std::string name){
    int index = hashSum(name,10);
    if(hashTable[index]->title==name){
        std::cout << index << ":" << hashTable[index]->title << ":" << hashTable[index]->year << std::endl;
    }
    else{
        HashElem* tmp = hashTable[index];
        while(tmp!=NULL&&tmp->title==name){
            tmp = tmp->next;
        }
        if(tmp==NULL){
            std::cout << "Movie not found" << std::endl;
        }
        else{
            std::cout << index << ":" << tmp->title << ":" << tmp->year << std::endl;
        }
    }
}
void HashTable::printTableContents(){
    bool isEmpty = true;
    int i = 0;
    while(i<10&&isEmpty){
        if(hashTable[i]!=NULL){
            isEmpty = false;
        }
        i++;
    }
    if(isEmpty){
        std::cout << "empty" << std::endl;
    }
    else{
        for(int j = 0;j<10;j++){
            if(hashTable[j]!=NULL){
                std::cout << hashTable[j]->title << ":" << hashTable[j]->year << std::endl;
                if(hashTable[j]->next!=NULL){
                    HashElem* tmp = hashTable[j]->next;
                    while(tmp!=NULL){
                        std::cout << tmp->title << ":" << tmp->year << std::endl;
                        tmp = tmp->next;
                    }
                }
            }
        }
    }
}
HashTable::~HashTable(){

}
