/*******************************************************************
 * Copyright (C) Leaguenew-USTC, 2012                                
 *                                                                  
 * FILE NAME             :  Median.h                                
 * PRINCIPAL AUTHOR      :  leaguenew                               
 * MODULE NAME           :  Median                           
 * LANGUAGE              :  C++                                      
 * TARGET ENVIRONMENT    :  windows                                   
 * DATE OF FIRST RELEASE :  2012/12/20                              
 * DESCRIPTION           :  use median function to calculate the 
							median of a list of data
 ******************************************************************/

/*
 * Revision log:
 *
 * Created by leaguenew,2012/12/20
 * Modified by leaguenew,2013/1/3
 *
 */

#ifndef MEDIAN_H
#define MEDIAN_H

#include<vector>
using namespace std;

class Median
{
public:
	   Median();
       void reset();
       void add(double value) ;
       double get_median(); 
	   void showall();
	   ~Median();
private:
	   vector<double> myvector;
};

#endif