#include "Hashtable.h"


Hashtable::Hashtable(char* temp, int k, int tablesize) //Hashtable Constructor
{
    name = temp;
    length = k;   //Length for Hamming,Cosine and DistanceMatrix         //Length for Euclidean
    array = new LinkedList[ length ];
}

Hashtable::Hashtable(const Hashtable& orig) {
}

Hashtable::~Hashtable() 
{
    delete [] array;
}

int Hashtable::hash( char *str )
{
    int value = 0;
    for ( int i = 0; i < strlen(str); i++ )
    {
       // cout << "bla" <<str[i] << endl ;
        if(str[i]=='-')
        {
            value = value;
        }
        else
        {
            value += str[i];
        } 
   }
    return (value * strlen(str) ) % length;
}  

/*insert points depending on caller number*/
void Hashtable::InsertIntoHashtable(char* temp, CDRS *cdrspoint )
{    

    int index ;
    index = hash(cdrspoint->getOrNum());
   array[index].insertPoint(cdrspoint, cdrspoint->getDesNum() , cdrspoint->getOrNum());
}


/*insert points depending on destination number*/
void Hashtable::InsertIntoHashtableDes(char* temp, CDRS *cdrspoint ) 
{    

    int index ;
    index = hash(temp);
   array[index].insertPointDes(cdrspoint, temp , cdrspoint->getDate());
}

void Hashtable ::DeleteItem(char * NumOr , char * Id)
{
    int index;
    index = hash(NumOr);
    array[index].DeleteCaller( NumOr ,Id);
    
}


void Hashtable ::Search(char* NumOr, char* year1, char* year2, char* time1, char* time2, int flag)
{
    int index;
    index = hash(NumOr);
    if(flag ==0 )
    {
        array[index].Searchlist(NumOr,year1,year2,time1,time2, flag); //if we want the caller
    }
    else if(flag ==1)
    {
        array[index].SearchlistB(NumOr,year1,year2,time1,time2, flag); //if we want the callee
    }
    
}




void Hashtable::printTable()
{
   // cout << length;
    cout << "\nHash Table:\n";   
    for (int i = 0; i < length; i++)
    {
        cout << "\nBucket " << i << ": ";
        array[i].printList(); //go and print the list inside the bucket
    }
}

int Hashtable::getLength()
{
    return length;
}

