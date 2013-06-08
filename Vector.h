/*******************************************************************
 * Copyright (C) Leaguenew-USTC, 2012                                
 *                                                                  
 * FILE NAME             :  Vector.h                                
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

#ifndef VECTOR_H
#define VECTOR_H

#include<vector>
using namespace std;

class Vector
{
public:
	Vector();
    Vector(int n) ;
    int getSize() ;
    void fill(double value)    ;     
    double get(int i)          ;     
	double get( vector<double>::iterator it) const;
    void set(int i,double value) ;
    void add(const Vector &v)    ;
    void sub(const Vector &v)    ;
    void mul(double k) ;
    void inc_mul(const Vector &v,double k);
    double  dot(const Vector &v);
    double square_norm();
    double norm();
    double sum();
    double min();
    double max();
	void Show();
	~Vector();

private:
    int size;
	vector<double> myvector;
	vector<double>::iterator it;
};

#endif