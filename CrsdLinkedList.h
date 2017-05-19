/* 
 * File:   CrsdLinkedList.h
 * Author: peggyvourou
 *
 * Created on 17 Μάρτιος 2017, 12:26 πμ
 */

#ifndef CRSDLINKEDLIST_H
#define	CRSDLINKEDLIST_H

#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
#include "CDRs.h"


struct PointCD
{
    
    CDRS *cdrs_key;
    char * item;
    PointCD * next1;
    PointCD()
    {
        cdrs_key = NULL;
        item = NULL;
        next1 = NULL; 
    }; 
    PointCD(CDRS *cdrspoint, char* numb, char* d)
    {
        cdrs_key = cdrspoint;  
        item = numb;
        next1 = NULL; 
    };
    
    void PrintItem()
    {
        cout << "item : " << item << endl; 
    }
};

class CDRSLinkedList {
public:
    CDRSLinkedList();
    CDRSLinkedList(const CDRSLinkedList& orig);
    virtual ~CDRSLinkedList();
    // Inserts an item at the end of the list.
    void insertCDRSpoint(CDRS *cdrspoint, char* num, char* date);
    //void Search(int radius, string temp,string item, int counter, int * Row, string method, ofstream& file,int columns, Cluster ** cluster, int k);
    void printList();
    //int getLength();
    
private:
    PointCD * head1;
    int length;
};

#endif	/* CRSDLINKEDLIST_H */

