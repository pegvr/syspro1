/* 
 * File:   main.cpp
 * Author: peggyvourou
 *
 * Created on 8 Μάρτιος 2017, 7:03 μμ
 */

#include <cstdlib>
#include <fstream>
#include <iostream>
#include <string.h>
#include "CDRs.h"
#include "Hashtable.h"
#include "LinkedList.h"
#include <math.h>
using namespace std;

/*
 * 
 */
void File(Hashtable ** PointersToHashtable,Hashtable ** PointersToHashtable2, CDRS **Cdrs, int l, int count_lines, int max, FILE *inputfile,int arr[], int line);
Hashtable ** CreateHash(int L, int k, int tablesize);


int main(int argc, char** argv) {
    
    
    
    int l = 0;
    int count_lines = 0, num_of_ch = 1;
    int h1 = pow(2.0,5); // number of buckets for hashtable1
    int h2 = pow(2.0,5); //number of buckets for hashtable2
    char ch , *cdr;
    ifstream myfile(argv[1]); 
    if (argv[3] != NULL && argv[5] != NULL) //number of for hashtables
    {
        h1 = atoi(argv[3]);
        h2 = atoi(argv[5]);
    }
//    
    
    
    FILE *inputfile;
    inputfile = fopen(argv[1], "r");
    ch = getc(inputfile);
    
    int i; 
    while (ch != EOF )
    {
       
        if (ch == '\n')
        {
            count_lines = count_lines + 1;
            
        }
        ch = getc(inputfile);
        
    }
    fclose(inputfile); 
    
    
    inputfile = fopen(argv[1], "r");
    ch = getc(inputfile);
  
    int num_of_chars[count_lines];
    while (ch != EOF )
    {
        num_of_ch = num_of_ch +1;
        if (ch == '\n')
        {
           num_of_chars[i] = num_of_ch; 
           num_of_ch = 0;
           i++ ;
            
        }
        ch = getc(inputfile);
        
    }
    
    
    
    fclose(inputfile); //close file.
    int max = num_of_chars[0];
    for(int i = 0; i < count_lines; i++)
    {
        if(num_of_chars[i] > max)
        {
            max = num_of_chars[i]; 
        }
        
    }
    
    char *line; 
    int pos, posid;
    char * token;
    
    Hashtable **PointersToHashtable = CreateHash(1, h1, count_lines);   //Construct L HashTables
    Hashtable **PointersToHashtable2 = CreateHash(1, h2, count_lines);   //Construct L HashTables
    CDRS **Cdrs =  new CDRS*[count_lines]; //Construct Cdrs points
 
    inputfile = fopen(argv[1], "r"); //open file again
    
    File(PointersToHashtable,PointersToHashtable2,Cdrs,0,count_lines,max,inputfile,num_of_chars,0);
    
    fclose(inputfile); //close file.

    return 0;
}


Hashtable ** CreateHash(int L, int k, int tablesize)
{
    Hashtable **PointersToHashtable = new Hashtable*[L];  //Table which points to g1,g2,...,gl hashtables
    char temp1[10];
    char * temp = "g0";

        temp = 'g' + temp1;
        PointersToHashtable[L] = new Hashtable (temp, k, tablesize);
    return PointersToHashtable;
}


void File(Hashtable ** PointersToHashtable,Hashtable ** PointersToHashtable2, CDRS **Cdrs, int l, int count_lines, int max, FILE *inputfile,int arr[], int lines)
{
    
    
    int pos;
    char *cdr, *token, *temp;
    int number;
    number = arr[lines];
    char line[number];
    char lineh[number];
     while (fgets(line, sizeof(line), inputfile)) {
        /* note that fgets don't strip the terminating \n, checking its
           presence would allow to handle lines longer that sizeof(line) */
        for(int i=0; i<number; i++)
        {
            lineh[i]=line[i]; //store the line
      
        }
        token = strtok(lineh," ");
  
        bool equal;
        int poss; 
        int counter; 

        if(strcmp(token, "insert") == 0 )
        {
            int len = strlen(token);
            counter = counter + 1; 
            poss = len;
            char cdrs[max-(len+1)];
            for (int i =0; i < max; i++)
            {
                cdrs[i] = line[poss+1];
                poss = poss + 1;
                
            }
            cdr = cdrs;
            
            Cdrs[l] = new CDRS(cdrs,count_lines); //new CDRS record
            
            PointersToHashtable[1]->InsertIntoHashtable(Cdrs[l]->getOrNum(),Cdrs[l]);     
            PointersToHashtable2[1]->InsertIntoHashtableDes(Cdrs[l]->getDesNum(),Cdrs[l]);

            l = l+1;
            lines = lines+1; // for next line characters
            File(PointersToHashtable,PointersToHashtable2,Cdrs,l,count_lines,max,inputfile,arr,lines);
            
        }
        else if(strcmp(token,"topdest")==0)
        {
            lines = lines+1;// for next line characters
            File(PointersToHashtable,PointersToHashtable2,Cdrs,l,count_lines,max,inputfile,arr,lines);
        }
        else if(strcmp(token,"top")==0)
        {
            lines = lines+1;// for next line characters
            File(PointersToHashtable,PointersToHashtable2,Cdrs,l,count_lines,max,inputfile,arr,lines);
        }
        else if(strcmp(token,"indist")==0)
        {
            lines = lines+1;// for next line characters
            File(PointersToHashtable,PointersToHashtable2,Cdrs,l,count_lines,max,inputfile,arr,lines);  
        }
        else if(strcmp(token,"dump")==0)
        {
          lines = lines+1;// for next line characters
          File(PointersToHashtable,PointersToHashtable2,Cdrs,l,count_lines,max,inputfile,arr,lines);  
        }
        else if(strcmp(token, "delete") == 0)
        {
            char *del, *id , *num0r; 
            del = strtok(line," ");
            del = strtok(NULL," ");
            num0r = strtok(NULL,"\0"); //find our caller
            int len = strlen(num0r);
             
            PointersToHashtable[1]->DeleteItem(num0r,del); //delete him from hash
            lines = lines +1; // for next line characters 
            File(PointersToHashtable,PointersToHashtable2,Cdrs,l,count_lines,max,inputfile,arr,lines);
        }
        else if(strcmp(token,"find")==0)
        {   
            char *del, *id , *num0r,*time1, *year1, *time2, *year2, *token;
            int len_of_line,len1,len2,len3,len4,len5,lend1,lend2;
            len_of_line = strlen(line);
            del = strtok(line," ");
            lend1 = strlen(del);
            del = strtok(NULL," ");
            lend2 = strlen(del);
            num0r = strtok(NULL," ");
            len1 = strlen(num0r);
            if(len_of_line ==(lend1+lend2+len1+2)) //if we have only the caller 
            {
                lines =lines+1;
                PointersToHashtable[1]->Search(num0r,NULL,NULL,NULL,NULL,0); 
                File(PointersToHashtable,PointersToHashtable2,Cdrs,l,count_lines,max,inputfile,arr,lines);
                continue;
            }
            else if(len_of_line  > (lend1+lend2+len1+2)) //if we dont have only the caller 
            {
                
                time1 = strtok(NULL," ");
                len2 = strlen(time1);
                time2 = strtok(NULL," ");
                len3 = strlen(time2);
                if(len_of_line == (lend1+lend2+len1+len2+len3+4) && (len2==5)) //if we dont have only the caller , but we have time too
                {
                    lines =lines+1;
                    PointersToHashtable[1]->Search(num0r,NULL,NULL,time1,time2,0); 
                    File(PointersToHashtable,PointersToHashtable2,Cdrs,l,count_lines,max,inputfile,arr,lines);
                continue;
                }
                else if(len_of_line == (lend1+lend2+len1+len2+len3+4) && (len2 == 8)) //if we dont have only the caller , but we have year too
                {
                    lines = lines+1;
                    File(PointersToHashtable,PointersToHashtable2,Cdrs,l,count_lines,max,inputfile,arr,lines);
                   
                }
                else if(len_of_line > (lend1+lend2+len1+len2+len3+4) ) //if we dont have only the caller , but we have time and year  too
                {
                    year1= strtok(NULL," ");
                    len4 = strlen(year1);
                    year2 = strtok(NULL," ");
                    len5 = strlen(year2);
                    if(len_of_line == (lend1+lend2+len1+len2+len3+len4+len5 +6 ))
                    {
                        
                        PointersToHashtable[1]->Search(num0r,time2,year2,time1,year1,0); 
                        lines = lines+1;
                        File(PointersToHashtable,PointersToHashtable2,Cdrs,l,count_lines,max,inputfile,arr,lines);
                    }
                }
            }
            
        }
        else if(strcmp(token,"lookup")==0)
        {   
            char *del, *id , *num0r,*time1, *year1, *time2, *year2;
            int len_of_line,len1,len2,len3,len4,len5,lend1,lend2;
            len_of_line = strlen(line);
            del = strtok(line," ");
            lend1=strlen(del);
            num0r = strtok(NULL," ");
            lend2 = strlen(num0r);
            if(len_of_line ==(lend1+lend2+1))
            {
                lines =lines+1;
                PointersToHashtable2[1]->Search(num0r,NULL,NULL,NULL,NULL,1); 
                File(PointersToHashtable,PointersToHashtable2,Cdrs,l,count_lines,max,inputfile,arr,lines);
                continue;
            }
            else if(len_of_line  > (lend1+lend2+1)) //if we have only the callee
            {
                time1 = strtok(NULL," ");
                len2 = strlen(time1);
                time2 = strtok(NULL," ");
                len3 = strlen(time2);
                if(len_of_line == (lend1+lend2+len2+len3+3) && (len2==5))
                {
                    lines =lines+1;
                    PointersToHashtable2[1]->Search(num0r,NULL,NULL,time1,time2,1); 
                    File(PointersToHashtable,PointersToHashtable2,Cdrs,l,count_lines,max,inputfile,arr,lines);
                continue;
                }
                else if(len_of_line == (lend1+lend2+len1+len2+len3+4) && (len2 == 8)) //if we dont have only the callee
                {
                    lines = lines+1;
                    File(PointersToHashtable,PointersToHashtable2,Cdrs,l,count_lines,max,inputfile,arr,lines);
                }
                else if(len_of_line > (lend1+lend2+len1+len2+len3+4) ) //if we dont have only the callee
                {
                    year1= strtok(NULL," ");
                    len4 = strlen(year1);
                    year2 = strtok(NULL," ");
                    len5 = strlen(year2);
                    if(len_of_line == (lend1+lend2+len1+len2+len3+len4+len5 +6 )) //if we dont have only the callee
                    {
                        
                        //PointersToHashtable[1]->Search(num0r,time2,year2,time1,year1,1); 
                        lines = lines+1;
                        File(PointersToHashtable,PointersToHashtable2,Cdrs,l,count_lines,max,inputfile,arr,lines);
                    }
                    lines = lines+1;
                    File(PointersToHashtable,PointersToHashtable2,Cdrs,l,count_lines,max,inputfile,arr,lines);
                }
            }
            
        }
        else if(strcmp(token,"bye")==0)
        {
            
            delete PointersToHashtable;
            delete PointersToHashtable2;
            for(int i; i<count_lines; i++)
            {
                delete Cdrs[i];
            }
            lines =lines+1;
            cout << "Everything is free now!" << endl; 
            File(PointersToHashtable,PointersToHashtable2,Cdrs,l,count_lines,max,inputfile,arr,lines);
            
        }
        else if(strcmp(token,"print")==0) // if the first word of line is print
        {
            char *del, *id , *num0r; 
            id = strtok(line," ");
            id = strtok(NULL," "); 
            if(strcmp(id,"hashtable1")==0) // if the second word of line is hashtable1
            {
                cout << "print hashtable 1: " << endl; 
                PointersToHashtable[1]->printTable();
                lines =lines+1;
                File(PointersToHashtable,PointersToHashtable2,Cdrs,l,count_lines,max,inputfile,arr,lines);
            }
            else
            {
                cout << "print hashtable 2: " << endl; // if the second word of line is hashtable2
                PointersToHashtable2[1]->printTable();
                lines =lines+1;
                File(PointersToHashtable,PointersToHashtable2,Cdrs,l,count_lines,max,inputfile,arr,lines);
            }
        }
        
  }
}

