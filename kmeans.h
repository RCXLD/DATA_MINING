/*******************************************************************
 * Copyright (C) Leaguenew-USTC, 2012                                
 *                                                                  
 * FILE NAME             :  kmeans.h                                
 * PRINCIPAL AUTHOR      :  leaguenew                               
 * MODULE NAME           :  KMEAN                           
 * LANGUAGE              :  C++                                      
 * TARGET ENVIRONMENT    :  windows                                   
 * DATE OF FIRST RELEASE :  2012/12/20                              
 * DESCRIPTION           :  classify the data using kmeans algorithm
 ******************************************************************/

/*
 * Revision log:
 *
 * Created by leaguenew,2012/12/20
 * Modified by leaguenew,2013/1/3
 *
 */

#ifndef  KEAMS_H
#define KEAMS_H

#include <iostream>
#include <vector>
#include "Vector.h"
#include "KahanSum.h"
#include "Median.h"

class KMeans
{
public:
	KMeans() ;
	KMeans(int n) ;
	void init_cluster_centers( vector<Vector> mylist );
	int clusterize(vector<Vector> mylist);
	Vector get_cluster_center(int i);
	int get_point_id(int i);
private:
	int k ; 
	vector<Vector> cluster_centers;
	vector<int> point_ids;
	int get_closest_center_id( const Vector &X);
	void  init_point_indexes( vector<int> &pids);
};

#endif