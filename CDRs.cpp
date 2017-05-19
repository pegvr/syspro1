#include "CDRs.h"

CDRS::CDRS(char* temp,int count) 
{   
    char line[strlen(temp)], * ps , *ps0, *ps2, *ps3, *ps4, *ps5, *ps6, *ps7, *ps8;
    strcpy(line,temp);
    char *line1; 
   
    
    ps = strtok(temp, ";");
    cdr_uniq_id = ps;
    ps0= strtok(NULL, ";");
    originator_number = ps0;
   ps2 = strtok(NULL, ";");
   destination_number = ps2;
    ps3 = strtok(NULL, ";");
    date = ps3;
    ps5 = strtok(NULL, ";");
    init_time = ps5;
    ps6 = strtok(NULL, ";");
    duration = ps6;
    ps7 = strtok(NULL, ";");
    type = ps7;
    ps8 = strtok(NULL, ";");
    tarrif = ps8 ; 
    ps4 = strtok(NULL, ";");
    fault_condition = ps4; 
    counter = count;
 
   
    
}

CDRS::CDRS(const CDRS& orig) {
}


CDRS::CDRS() 
{
    
}

CDRS::~CDRS() 
{
   
}




 char * CDRS:: getId() 
{
     
     char *p = new char[strlen(cdr_uniq_id)+1];

     return cdr_uniq_id;
}


char* CDRS:: getOrNum()
{
    
    char *c = new char[strlen(originator_number)+1];
     strcpy (c, originator_number);
    return c;
}

char* CDRS:: getDesNum()
{
    char *d = new char[strlen(destination_number)+1];
     strcpy (d, destination_number);
    return d;
}

char* CDRS:: getDate()
{
    return date;
}

char* CDRS:: getTime()
{
    return init_time;
}

char* CDRS:: getType()
{
    return type;
}

char* CDRS:: getTarr()
{
    return tarrif;
}

char* CDRS:: getFcon()
{
    return fault_condition;
}


