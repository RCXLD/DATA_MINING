/*******************************************************************
 * Copyright (C) Leaguenew-USTC, 2012                                
 *                                                                  
 * FILE NAME             :  Median.cpp                                
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

#include"Median.h"
#include<iostream>
#include<algorithm>
#include<cstdlib>
using namespace std;

Median::Median()
{
	
}

void Median:: reset()    
{
	myvector.clear();	
}


void Median::add(double value) 
{ 
	myvector.push_back(value);
}
       
double Median::get_median() 
{ 
	int n;
	sort( myvector.begin(),myvector.end() );
	n = myvector.size();
	if( n%2!=0 )return myvector[n/2]; 
    else return ( myvector[n/2-1] + myvector[n/2] )/2;
}

void Median::showall()
{
	for( int i=0;i<myvector.size();i++)
		cout<<"myvector["<<i<<"]--->"<<myvector[i]<<endl;
	cout<<endl;
}

Median::~Median()
{
	myvector.clear();
}

