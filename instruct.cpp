/* 
 * File:   instruct.cpp
 * Author: peggyvourou
 * 
 * Created on 19 Μάρτιος 2017, 4:14 μμ
 */

#include "instruct.h"

instruct::instruct(char *str, int count_lines) {
    char *temp,*call_id,*caller;    
    temp = strtok(str," ");
    if(strcmp(temp,"insert")==0)
    {
        return;
    }
    else if(strcmp(temp,"delete")==0)
    {
        call_id = strtok(NULL," ");
        caller_id = call_id;
        caller = strok(NULL, " ");
        num = caller;
    }
    else
    {
        return;
    }
}
instruct ::instruct(){
    
}
instruct::instruct(const instruct& orig) {
}

instruct::~instruct() {
}

