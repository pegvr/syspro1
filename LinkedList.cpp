
#include "LinkedList.h"

LinkedList::LinkedList()            //Linked List Constructor
{
    
    head = new Point;
    head -> next = NULL; //head is null
    length = 0;
    
    
}

LinkedList::LinkedList(const LinkedList& orig) {
}
 

LinkedList::~LinkedList()       //Linked List Destructor
{
    Point * p = head;
    Point * q = head;
    while (q != NULL)
    {
        p = q;
        q = p -> next;
        if (q != NULL) delete p;
    }
}

// Inserts an item at the head of the list.
void LinkedList::insertPoint(CDRS *cdrspoint, char * num, char * date)
{ 
    Point *temp = head;
    Point *new_point = new Point(cdrspoint, num, date,cdrspoint->getId(),cdrspoint->getDate(),cdrspoint->getTime() );
    while (temp->next != NULL) {
        temp = temp->next;
         int i; 
         i= strcmp(temp->item,num);
         if ( i == 0) {
             temp->cdrs_point->insertCDRSpoint(cdrspoint,cdrspoint->getDesNum(),date);     
           length++;
           return;
         }      
    }
 
    if (!head -> next)              //If list is empty insert here
    {
         head->next = new_point;
        length++; 
        return;
    }
    else 
    {
        temp->next = new_point;
        length++;
        return; 
    }
    
   
}

/*insert points depending on destination number*/
void LinkedList::insertPointDes(CDRS *cdrspoint, char * num, char * date)
{ 
    Point *temp = head; 
    Point *new_point = new Point(cdrspoint, num, date,cdrspoint->getId(),cdrspoint->getDate(),cdrspoint->getTime()); 
    while (temp->next != NULL) { 
        temp = temp->next;
        
         int i; 
          temp->PrintItem();
         i= strcmp(temp->item,num);
         if ( i == 0) {
            temp->cdrs_point->insertCDRSpoint(cdrspoint,cdrspoint->getOrNum(),date);      
           length++;
           return;
       }
    }
 
    if (!head -> next)              //If list is empty insert here
    {
        head->next = new_point;
        length++;
        return;
    }
    else
    {
        temp->next = new_point;
        length++;
        return; 
    }
    
 
}


void LinkedList :: DeleteCaller(char * NumOr, char * Id)
{
    
    
    if(!head)
    {
        cout << "Sorry error" << endl; 
        return;
    }

    
    Point *tmp = head;
    tmp = tmp->next;
    Point *prev = NULL;
    
    int i = strcmp(Id,tmp->get_Id());
    int j = strcmp(NumOr,tmp->get_Caller());
    
    while ((j!=0 && i!=0 && tmp->next!=NULL))
    {
        prev = tmp ;
        tmp = tmp->next;
        i = strcmp(Id,tmp->get_Id());
        j = strcmp(NumOr,tmp->get_Caller());
    }
    
    if(i==0 && j==0)
    {
        free(tmp);
        if (prev)
        {
            
            prev->next = tmp->next;
        }
        else
        {
            
            tmp = tmp->next;
            while(tmp)
            {
                free(tmp);
                tmp = tmp->next;
            }
            
        }
        length -- ;
        cout << "DELETE DONE" << endl;
    }
    
    
    
}

/*search for callee*/
void LinkedList :: Searchlist(char* NumOr, char* year1, char* year2, char* time1, char* time2,int flag)
{
    int day_a,day_b,month_a,month_b,year_a, year_b, time_ah,time_am,time_bh,time_bm;
    char *timeah,*timebh,*timeam,*timebm;
    if(year1!=NULL ) // years to integers
    {
        year_a = atoi(year1);        
        year_b = atoi(year2);
    }
    if(time1 != NULL ) // hours and minutes to integers
    {
       
        timeah = strtok(time1,":");
        timeam = strtok(NULL," ");
        timebh = strtok(time2,":");
        timebm = strtok(time2," ");
        time_ah = atoi(timeah);
        time_am = atoi(timeam);
        time_bh = atoi(timebh);
        time_bm= atoi(timebm);
    }
    

    if(time1==NULL && year1 == NULL)
    {
       
        if(!head)
        {
            cout << "Sorry error" << endl; 
            return;
        }
        
        Point *tmp = head->next;
        Point *prev = NULL;
        int i = strcmp(NumOr,tmp->get_Caller()); //compare aur items
        while ((i!=0 && tmp->next!=NULL))
        {

            prev = tmp ;
            tmp = tmp->next;
            i = strcmp(NumOr,tmp->get_Caller());
        }
        
        if(i==0)
        {
            
            cout << "Caller: " << tmp->get_Caller() << "has CDRS with ids: " <<  endl; 
            cout << tmp->cdrs_key->getId() << endl; 
            tmp = tmp->next;
            while(tmp!=NULL)
            {
                cout << tmp->get_Id() << endl;
                tmp =tmp->next;
             
            }
        }
    
    }
    else 
    {
        if(!head)
        {
            cout << "Sorry error" << endl; 
            return;
        }
        
        Point *tmp = head->next;
        Point *prev = NULL;
        int i = strcmp(NumOr,tmp->get_Caller());
        while ((i!=0 && tmp->next!=NULL))
        {

            prev = tmp ;
            tmp = tmp->next;
            i = strcmp(NumOr,tmp->get_Caller());
        }
        if(i==0 && (time1!=NULL) && (year1==NULL))
        {
            
            char * time, *hours, *min;
            int ti_me, hou_rs, mi_n;
            time = tmp->get_Time();
            hours = strtok(time,":");
            min = strtok(NULL," ");
            hou_rs = atoi(hours);
            mi_n = atoi(min);
            cout << "We found Caller: " << tmp->get_Caller() << "has CDRS with ids:" <<  endl;
            while(tmp!=NULL)
            {
                if((((hou_rs == time_ah && mi_n >= time_am) || (hou_rs > time_ah ))&&((hou_rs==time_bh && mi_n <= time_bm)|| (hou_rs < time_bh)))&& tmp!=NULL )
                {
                    cout << tmp->cdrs_key->getId() << endl; 
                    tmp = tmp->next;
                     
                    while(tmp!=NULL)
                    {
                        char * var, *hours, *min, *time;
                        int ti_me, hou_rs, mi_n;
                        var = tmp->get_Time();
                        hours = strtok(var,":");
                        min = strtok(NULL," ");
                        hou_rs = atoi(hours);
                        mi_n = atoi(min);
                        if((((hou_rs == time_ah && mi_n >= time_am) || (hou_rs > time_ah ))&&((hou_rs==time_bh && mi_n <= time_bm)|| (hou_rs < time_bh)))&& tmp!=NULL )
                        {
                            cout << tmp->cdrs_key->getId() << endl; 
                        }
                        tmp = tmp->next;
                    }
                
                }
                
                
            
                
            }
        }
//        else if(i==0 && (time1!=NULL) && (year1!=NULL))
//        {
//            cout << year_a <<endl; 
//            i = year_a;
//            year_a = year_a%10000;
//            cout << year_a << endl;
//            i = i - year_a;
//            cout << i << endl; 
//            i = i/10000;
//            cout << i << endl;
//            month_a = i%100;
//            cout << month_a << endl;
//            day_a = i - month_a;
//            day_a = day_a/100;
//            cout << day_a << endl;
//            
//            
//            cout << year_b << endl; 
//            year_a = year_b;
//            year_b = year_b%10000;
//            cout << year_b << endl;
//            year_a = year_a - year_b;
//             
//            year_a = year_a/10000;
//            cout << year_a << endl;
//            month_b = year_a%100;
//            cout << month_b << endl;
//            day_b = year_a - month_b;
//            day_b = day_b/100;
//            cout << day_b << endl;
//            
//            
//        }
        else
        {
           
          cout << "We don't have CDRS in this hour for caller" << tmp->get_Caller() << endl; 
                
        }
        
    }
    
}


/*search for callee*/
void LinkedList :: SearchlistB(char* NumOr, char* year1, char* year2, char* time1, char* time2,int flag)
{
    
    int day_a,day_b,month_a,month_b,year_a, year_b, time_ah,time_am,time_bh,time_bm;
    char *timeah,*timebh,*timeam,*timebm;
    if(year1!=NULL )
    {
        year_a = atoi(year1);        
        year_b = atoi(year2);
    }
    if(time1 != NULL )
    {
       
        timeah = strtok(time1,":");
        timeam = strtok(NULL," ");
        timebh = strtok(time2,":");
        timebm = strtok(time2," ");
        time_ah = atoi(timeah);
        time_am = atoi(timeam);
        time_bh = atoi(timebh);
        time_bm= atoi(timebm);
    }

    if(time1==NULL && year1 == NULL)
    {
        if(!head)
        {
            
            return;
        }
        
        Point *tmp = head->next;
        Point *prev = NULL;
        int i = strcmp(NumOr,tmp->get_item());

        while ((i!=0 && tmp->next!=NULL))
        {; 
            prev = tmp ;
            tmp = tmp->next;
            i = strcmp(NumOr,tmp->get_item());
        }
        
        if(i==0)
        {
            cout << " We found Callee: " << tmp->get_item() << "has CDRS with ids:" <<  endl; 
            cout << tmp->cdrs_key->getId() << endl; 
            tmp=tmp->next;
            while(tmp!=NULL)
            {
                cout << tmp->cdrs_key->getId() << endl;
                tmp =tmp->next;
                
             
            }
        }
    
    }
    else 
    {
        if(!head)
        {
            cout << "Sorry error" << endl; 
            return;
        }
        
        Point *tmp = head->next;
        Point *prev = NULL;
        int i = strcmp(NumOr,tmp->get_item());
        while ((i!=0 && tmp->next!=NULL))
        {

            prev = tmp ;
            tmp = tmp->next;
            i = strcmp(NumOr,tmp->get_item());
        }
        if(i==0 && (time1!=NULL) && (year1==NULL))
        {
            
           
            cout << "We found Callee: " << tmp->get_item() << "has CDRS with ids:" <<  endl;
            while(tmp!=NULL)
            {
                 char * time, *hours, *min;
                int ti_me, hou_rs, mi_n;
                time = tmp->get_Time();
                hours = strtok(time,":");
                min = strtok(NULL," ");
                hou_rs = atoi(hours);
                mi_n = atoi(min);
                if((((hou_rs == time_ah && mi_n >= time_am) || (hou_rs > time_ah ))&&((hou_rs==time_bh && mi_n <= time_bm)|| (hou_rs < time_bh)))&& tmp!=NULL )
                {
                    cout << tmp->cdrs_key->getId() << endl; 
                    tmp = tmp->next;
                     
                    while(tmp!=NULL)
                    {
                        char * var, *hours, *min, *time;
                        int ti_me, hou_rs, mi_n;
                        var = tmp->get_Time();
                        hours = strtok(var,":");
                        min = strtok(NULL," ");
                        hou_rs = atoi(hours);
                        mi_n = atoi(min);
                        if((((hou_rs == time_ah && mi_n >= time_am) || (hou_rs > time_ah ))&&((hou_rs==time_bh && mi_n <= time_bm)|| (hou_rs < time_bh)))&& tmp!=NULL )
                        {
                            cout << tmp->cdrs_key->getId() << endl; 
                        }
                        tmp = tmp->next;
                    }
                
                }
                tmp = tmp->next;
                
                
            
                
            }
        }
        
        else
        {
           
          cout << "We don't have CDRS in this hour for caller" << tmp->get_Caller() << endl; 
                
        }
        
    }
    
}






void LinkedList::printList()      //Print whole bucket
{

    //cout << "bhka" << endl ; 
    if (length == 0)
    {
        cout << "\n{ }\n";
        return;
    }
    cout << "bhka" << endl ;
    Point * p = head->next;
    cout << "bhka" << endl ;
    cout << "\n{ ";
    while (p)
    {
       
        cout << "caller: " << p->get_Caller() << "has CDRS: " << p->get_Id() << endl; ;
        cout << "------******* ----- "<< endl;
        p->cdrs_point->printList();
        cout << "number: ";
        p->PrintItem();
        cout << p->cdrs_key->getOrNum() << endl ; 
               
        if (p -> next) cout << ", ";
        else break;
        
        p = p->next;
    }
    cout << "}\n";
}

// Returns the length of the list.
int LinkedList::getLength()
{
    return length;
}

