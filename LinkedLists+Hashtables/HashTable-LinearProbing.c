/* Mingye Chen 2020-09-07
 * Hashtable with linear probing (less memory than linkedlist)
 * Functions:
 * - Insert Item
 * - Delete Item
 * - Search Item
 *- Hash Function
 */
#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>

#define HASHTABLESIZE 10

//data in the hash table
typedef struct Person{
    char name[50];
    int age;
}Person;

//array of pointers
//this is the hashtable, it uses pointers so when it is NULL, it is empty
Person* hashtable[HASHTABLESIZE];

//creates empty table by populating NULL
void init_hash_table(){
    for(int i = 0; i < HASHTABLESIZE; i++)
        hashtable[i] = NULL;
}

//frees the memory in the table
void erase_table(){
    puts("ERASING DATA");
    for(int i = 0; i < HASHTABLESIZE; i++){
        if(hashtable[i] != NULL){
            fputs("Deleting : ", stdout);
            printf("%s \n",hashtable[i]->name);
            free(hashtable[i]);
        }
        else{
            puts("--Empty cell--");
        }
        
    }
}

//prints the hash table
void print_table(){
    puts("PRINTING HASHTABLE");
    for(int i = 0; i < HASHTABLESIZE; i++){
        if(hashtable[i] == NULL)
            puts("--Empty cell--");
        else
            printf("%s : %d \n", hashtable[i]->name, hashtable[i]->age);
    }
}

//hash function to create the hash key
unsigned int hash_function(char *name){
    unsigned int hashkey = 0;
    unsigned int nameSize = strlen(name);
    //add up ascii values the name
    for (unsigned int i = 0; i < nameSize; i++){
        hashkey += name[i];
        hashkey = hashkey * name[0];
    }
    hashkey = hashkey % HASHTABLESIZE;
    return hashkey;
}

Person* search(char* name){
    unsigned int hashkey = hash_function(name);
    //puts("starting search");
    for(unsigned int i = hashkey; i < HASHTABLESIZE; i++){
        //ALWAYS CHECK FOR NULL!!!!!!!!!!!!
        //if NULL that means nothing is there
        if(hashtable[i] == NULL){
            puts("No results");
            return NULL;
        }
        if(strcmp(hashtable[i]->name,name)==0)
            return hashtable[i];
           
    }
    //Table is FULL
    puts("TABLE IS FULL");
    return NULL;
}

/*
returns true if insert was successful
uses the hashkey, hashTable size is know as it is DEFINED HASHEDTABLESIZE
uses linear probing
it will print no results as it uses search()
*/
bool insertData(unsigned int hashkey, char* name, int age){
    //checks for dupicates
    if(search(name)!=NULL){
        puts("Entry already in hash table");
        return false;
    }
    //start searching for free spot (linear probing)
    for(unsigned int i = hashkey; i < HASHTABLESIZE; i++){
        if(hashtable[i]==NULL){
            Person* newPerson = (Person*)malloc(sizeof(Person));
            newPerson->age = age;
            memcpy(newPerson->name, name, strlen(name)+1);
            hashtable[i] = newPerson;
            return true;
        }
    }
    //table full
    puts("TABLE IS FULL");
    return false;
}

int main(){
    init_hash_table();
    insertData(hash_function("Joe"), "Joe", 69);
    insertData(hash_function("Bob"), "Bob", 6);
    insertData(hash_function("Angela"), "Angela", 32);
    insertData(hash_function("Michelle"), "Michelle", 42);
    insertData(hash_function("Sam"), "Sam", 9);
    insertData(hash_function("Penny"), "Penny", 9);
    insertData(hash_function("Sasha"), "Sasha", 9);

    insertData(hash_function("Sasha"), "Sasha", 9);

    print_table();

    Person* temp = search("bill");
    if(temp!=NULL)
        printf("%s is %d years old \n",temp->name, temp->age);

    erase_table();
    puts("done");
    return 0;
}
