/*******************************************************************
 * Copyright (C) Leaguenew-USTC, 2012                                
 *                                                                  
 * FILE NAME             :  Vector.cpp                                
 * PRINCIPAL AUTHOR      :  leaguenew                               
 * MODULE NAME           :  Vector                           
 * LANGUAGE              :  C++                                      
 * TARGET ENVIRONMENT    :  windows                                   
 * DATE OF FIRST RELEASE :  2012/12/20                              
 * DESCRIPTION           :  use the Vector to store the data and do
							some operation
 ******************************************************************/

/*
 * Revision log:
 *
 * Created by leaguenew,2012/12/20
 * Modified by leaguenew,2013/1/3
 *
 */

#include"Vector.h"
#include"KahanSum.h"
#include<iostream>
#include<algorithm>
#include<cstdlib>
#include<cmath>
using namespace std;

Vector::Vector()
{
// do nothing
}

Vector::Vector(int n)
{
	myvector.resize(n);
	size = n;
}

int Vector::getSize()
{
	return size;
}

void Vector::fill(double value) 
{
	for( int i = 0 ;i< size ;i++)
		myvector[ i ] = value ;
}

double Vector::get( int i )
{
	if( i >= 0 && i < myvector.size() )
	{
		return myvector[i];
	}
	return 0;
}

double Vector::get(vector<double>::iterator it) const
{
	if( it < myvector.end() )
	{
		return *it;
	}
	return 0;
}

void Vector::set(int i,double value) 
{ 
	if( i>=0 && i < myvector.size() )
	{
		myvector[i]=value;
	}
	else
		myvector.push_back(value);
}

void Vector::add(const Vector &v)    
{
	Vector temp = v ;
	for(int i=0;i < this->myvector.size();i++)
		myvector[i] += temp.get(i);
}

void Vector::sub(const Vector &v)
{
	Vector temp = v;
	for(int i = 0;i<this->myvector.size();i++)
		myvector[i] -= temp.get(i);
}

void Vector:: mul(double k)           
{	
	for(int i=0 ;i<myvector.size();i++)
		myvector[i]*=k;
}

void Vector::inc_mul(const Vector &v,double k) 
{
	Vector temp = v;
	for( int i = 0; i < this->myvector.size(); i++ )
		this->myvector[i] = this->myvector[i] + k * temp.get(i) ;
}

double Vector::dot(const Vector &v)// {A.V;}
{
	KahanSum ks;
	ks.reset();		/* pay attention to the reset() funciton */
	Vector temp = v;
	for( int i = 0;i < this->myvector.size();i++)
	{
		ks.add( myvector[i] * temp.get(i) );
	}
	return ks.get_sum();
}

double Vector::square_norm()   
{
	vector<double>::iterator it;
	KahanSum ks;
	ks.reset();

	for( int i = 0 ;i < myvector.size(); i++ )
	{
		ks.add( myvector[i]*myvector[i] );
	}
	
	return ks.get_sum();
}

double Vector:: norm()  
{
	return sqrt( this -> square_norm() );
}

double Vector:: sum()     
{
	vector<double>::iterator it;
	KahanSum ks;
	ks.reset();
	for( it = myvector.begin();it!=myvector.end();++it )
		ks.add( *it );
	return ks.get_sum();
}

double Vector:: min()
{
	return *min_element( myvector.begin(),myvector.end() );
}

double Vector:: max()
{
	return *max_element( myvector.begin(),myvector.end() );
}

void  Vector::Show()
{
	vector<double>::iterator it;
	int i=0;
	for( it = myvector.begin(); it != myvector.end(); ++it)
	{
		cout<<"Array["<<i<<"]----->"<<*it<<endl;
		i++;
	}
}

Vector::~Vector()
{
	myvector.clear();
}

