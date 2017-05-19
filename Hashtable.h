/* 
 * File:   Hashtable.h
 * Author: peggyvourou
 *
 * Created on 8 Μάρτιος 2017, 10:56 μμ
 */

#ifndef HASHTABLE_H
#define	HASHTABLE_H

#include "LinkedList.h"
#include <math.h>

class Hashtable {
public:
    Hashtable(char* temp, int k, int tablesize);
    Hashtable(const Hashtable& orig);
    virtual ~Hashtable();
    
    // Adds an item to the Hash Table.
    void insertPoint( Point * newPoint );
       
    // Display the contents of the Hash Table to console window.
    void printTable();
     int  hash( char *str);
    void Search(char* NumOr, char* year1, char* year2, char* time1, char* time2,int flag);
    // Returns the number of locations in the Hash Table.
    int getLength();
    
    // Returns the number of Points in the Hash Table.
    int getNumberOfPoints();
    void InsertIntoHashtable(char* temp, CDRS *cdrspoint);
    void InsertIntoHashtableDes(char* temp, CDRS *cdrspoint );
    void DeleteItem(char *NumOr, char * Id);
    
   // int SearchBucket(int L, char* temp, char* temp1, string item, int counter, int *Row, int fi, string method, int radius, ofstream& file, int func, string &neighbour,int columns,  Cluster ** centroid, int cluster);
private:
    // Array is a reference to an array of Linked Lists.
    char* name;
    LinkedList * array;
    // Length is the size of the Hash Table array.
    int length;
    
    
};

#endif	/* HASHTABLE_H */

