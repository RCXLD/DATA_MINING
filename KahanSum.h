/*******************************************************************
 * Copyright (C) Leaguenew-USTC, 2012                                
 *                                                                  
 * FILE NAME             :  KahanSum.h                                
 * PRINCIPAL AUTHOR      :  leaguenew                               
 * MODULE NAME           :  KAHANSUM                           
 * LANGUAGE              :  C++                                      
 * TARGET ENVIRONMENT    :  windows                                   
 * DATE OF FIRST RELEASE :  2012/12/20                              
 * DESCRIPTION           :  use kahanSum algorithm to calculate the 
							sum of some data precisely
 ******************************************************************/

/*
 * Revision log:
 *
 * Created by leaguenew,2012/12/20
 * Modified by leaguenew,2013/1/3
 *
 */

#ifndef KAHANSUM_H
#define KAHANSUM_H

class KahanSum
{
public:
       void reset() ;
       void add(double value) ;   //KahanSum algorithm
       double get_sum() ;
private:      
       double sum;
	   bool flag ;
	   double c,y,t;
};

#endif