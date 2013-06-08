/*******************************************************************
 * Copyright (C) Leaguenew-USTC, 2012                                
 *                                                                  
 * FILE NAME             :  KahanSum.cpp                                
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


#include"KahanSum.h"
#include<iostream>
using namespace std;

void KahanSum::reset() 
{
	sum = 0.0;
	c = 0.0;
}
       
void KahanSum::add(double value)   /*KahanSum algorithm*/
{
	y = value - c;
	t = sum + y;
	c = (t - sum) - y;
	sum = t;
}
       
double KahanSum::get_sum()        
{ 
	return sum;
}
