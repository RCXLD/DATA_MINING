/*******************************************************************
 * Copyright (C) Leaguenew-USTC, 2012                                
 *                                                                  
 * FILE NAME             :  functions.cpp                                
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

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "functions.h"
#include "Vector.h"
#include "KahanSum.h"
#include "median.h"
using namespace std;

void write_data( string filename ,vector<Vector> myvector,vector<int> vp)
{
	ofstream fout;
	vector<Vector>::iterator it;
	vector<int>::iterator ip;
	fout.open( filename.c_str(),ios::out );

	for( it = myvector.begin(),ip = vp.begin(); it != myvector.end()-1;it++,ip++)
	{
		int i;
		for( i=0; i<(*it).getSize();i++)
		{
			fout<<setprecision(15)<<setiosflags(ios::scientific)<<(*it).get(i)<<" ";
		}
		fout<<(*ip)<<endl;    /* print the cluster id */
	}
	fout<<endl;
	fout.close();
}

vector<Vector> read_data(string filename)
{
	vector<Vector> mylist;
	ifstream fin( filename.c_str(),ios::in );
	int i ,size;

	/* get the dimension of the vector; */
	size = 1;
	string temp;
	char num[100];
	getline( fin ,temp ,'\n');
	for( i = 0 ; i < temp.length() ; i++)
		if( temp[i]==' ')  size++;

	fin.seekg ( 0, ios::beg);    //  ?
	while( !fin.eof() )
	{
		Vector myvec(size);
		for( i = 0 ;i < size ;i++)
		{
			fin>>num;
			myvec.set( i,atof(num) );
		}
		mylist.push_back( myvec);
	}
	return mylist;
}

vector<double> vector_mean ( vector<Vector> mylist)
{
	int i , size;
	vector<Vector>::iterator it;
	vector<double> vec_mean;
	KahanSum ks;
	
	size = mylist.size();   /* obtain the number of vectors */
	for( i=0;i<mylist[0].getSize();i++)
	{
		ks.reset();
		for( it = mylist.begin(); it != mylist.end(); it++ )
		{
			ks.add( (*it).get(i) );
		}
		vec_mean.push_back( ks.get_sum()/(size*1.0) );
	}
	return vec_mean;
}

vector<double> vector_median (vector<Vector> mylist)
{
	vector<Vector>::iterator it;
	int i ;
	vector<double> vec_median;
	Median md;

	for( i=0;i<mylist[0].getSize();i++ )
	{
		md.reset();
		for( it = mylist.begin();it!=mylist.end();it++ )
		{
			md.add( (*it).get(i) );
		}
		vec_median.push_back( md.get_median() );
	}
	return vec_median;
}


