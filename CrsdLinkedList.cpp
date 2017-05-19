#include "CrsdLinkedList.h"



CDRSLinkedList::CDRSLinkedList()            //Linked List Constructor
{
    head1 = new PointCD;
    head1 -> next1 = NULL; //head is null
    length = 0;
}

CDRSLinkedList::CDRSLinkedList(const CDRSLinkedList& orig) {
}
 

CDRSLinkedList::~CDRSLinkedList()       //Linked List Destructor
{
    PointCD * p = head1;
    PointCD * q = head1;
    while (q != NULL)
    {
        p = q;
        q = p -> next1;
        if (q != NULL) delete p;
    }
}

// Inserts an item at the head of the list.
void CDRSLinkedList::insertCDRSpoint( CDRS *cdrspoint, char * num, char * date)
{
  
    PointCD *temp1 = new PointCD(cdrspoint,num,date);
   if ( !head1->next1) 
    {
        head1->next1 = temp1;
        length++;
        return;
    }
    temp1->next1 = head1->next1;
    head1->next1 = temp1;
    length++;
   
}



void CDRSLinkedList::printList()      //Print whole bucket
{

   
    if (length == 0)
    {
        cout << "\n{ }\n";
        return;
    }
    PointCD * p = head1->next1;
    cout << "\n{ ";
    while (p)
    {
 
        p->PrintItem();
               
        if (p -> next1) cout << ", ";
        else break;
        p = p->next1;
    }
    cout << "}\n";
}






