/* 
 * File:   LinkedList.h
 * Author: peggyvourou
 *
 * Created on 8 Μάρτιος 2017, 11:03 μμ
 */

#ifndef LINKEDLIST_H
#define	LINKEDLIST_H


#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <math.h>
#include "CDRs.h"
#include"CrsdLinkedList.h"




struct Point
{
    
    CDRSLinkedList *cdrs_point;
    CDRS *cdrs_key;
    char * item;
    char *ornum;
    char *ide;
    char *time;
    char *date;
    Point * next;
    Point()
    {
        cdrs_key = NULL;
        item = NULL;
        next = NULL; 
        ornum = NULL;
        ide = NULL;
    }; 
    Point(CDRS* cdrspoint, char* numb, char* d, char *id, char *da, char *ti)
    {
       cdrs_point = new CDRSLinkedList(); 
       cdrs_key = cdrspoint;  
        ornum = d;
        item = numb;
        next = NULL; 
        ide = id;
        date = da;
        time = ti;
        
        
        
    };
    
    /*getters*/
    char * get_item()
    {
        return item;
    }
    void PrintItem()
    {
        cout << "item :" << item << endl; 
    }
    char * get_Id()
    {
        return ide;
    }
    char * get_Caller()
    {
        return ornum;
    }
    
    char *get_Time()
    {
        return time;
    }
    char *get_Date()
    {
        return date;
    }
};

class LinkedList {
public:
    LinkedList();
    LinkedList(const LinkedList& orig);
    virtual ~LinkedList();
    void DeleteCaller(char * NumOr, char * Id);
    // Inserts an item at the end of the list.
    void insertPoint(CDRS *cdrspoint, char* num, char* date);
    void insertPointDes(CDRS *cdrspoint, char * num, char * date);
    void printList();
    int getLength();
    void Searchlist(char* NumOr, char* year1, char* year2, char* time1, char* time2,int flag);
    void SearchlistB(char* NumOr, char* year1, char* year2, char* time1, char* time2,int flag);
    
private:
    Point * head;
    int length;
};

#endif	/* LINKEDLIST_H */


