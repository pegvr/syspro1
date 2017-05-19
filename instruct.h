/* 
 * File:   instruct.h
 * Author: peggyvourou
 *
 * Created on 19 Μάρτιος 2017, 4:14 μμ
 */

#ifndef INSTRUCT_H
#define	INSTRUCT_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include "time.h"

class instruct {
public:
    instruct();
    instruct(char* str, int count_lines);
    instruct(const instruct& orig);
    virtual ~instruct();
private:
    char* del_caller;
    char* find_caller_num;
    char *find_caller_date;
    char *find_caller_time;
    char *caller_id;
    char *num;
    

};

#endif	/* INSTRUCT_H */

