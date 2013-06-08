/*******************************************************************
 * Copyright (C) Leaguenew-USTC, 2012                                
 *                                                                  
 * FILE NAME             :  functions.h                                
 * PRINCIPAL AUTHOR      :  leaguenew                               
 * MODULE NAME           :  FUNCTION                           
 * LANGUAGE              :  C++                                      
 * TARGET ENVIRONMENT    :  windows                                   
 * DATE OF FIRST RELEASE :  2012/12/20                              
 * DESCRIPTION           :  read_data()/write_data()/vector_mean()
							vector_median() are included in the file
 ******************************************************************/

/*
 * Revision log:
 *
 * Created by leaguenew,2012/12/20
 * Modified by leaguenew,2013/1/3
 *
 */

#ifndef FUNCTIONS_H
#define FUNCTIONS_H  

#include<fstream>
#include"Vector.h"
using namespace std;

void write_data(string fileName,vector<Vector> myvector,vector<int> vp );

vector<Vector> read_data( string fileName );

vector<double> vector_mean ( vector<Vector> mylist);

vector<double> vector_median( vector<Vector> mylist) ;

#endif

