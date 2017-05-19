/* 
 * File:   CDRs.h
 * Author: peggyvourou
 *
 * Created on 10 Μάρτιος 2017, 8:58 μμ
 */

#ifndef CDRS_H
#define	CDRS_H

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <sstream>
#include <string.h>
#include "time.h"

using namespace std;

class CDRS {
public:
    CDRS(char *temp, int count);
    CDRS(const CDRS& orig);
    virtual ~CDRS();
    CDRS();
     char *getId() ;
    char *getOrNum();
    char *getDesNum();
    char *getDate();
    char  *getTime();
    char *getType();
    char  *getTarr();
    char *getFcon();
    char *constructGfunction(int k);
    void insertintoCDRS(char *temp,int count);
    int  counter;
    
    
private:
    char *cdr_uniq_id ;
    char *originator_number;
    char *destination_number;
    char *date;
    char *init_time;
    char *duration;
    char *type;
    char *tarrif;
    char *fault_condition;
    int length;
};





#endif	/* CDRS_H */

