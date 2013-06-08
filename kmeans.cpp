/*******************************************************************
 * Copyright (C) Leaguenew-USTC, 2012                                
 *                                                                  
 * FILE NAME             :  kmeans.cpp                               
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

#include <fstream>
#include <iostream>
#include <iomanip>
#include <string>
#include <vector>

#include "functions.h"
#include "Vector.h"
#include "KahanSum.h"
#include "median.h"
#include "kmeans.h"
using namespace std;

KMeans::KMeans()
{
	 init_point_indexes( point_ids );
}

KMeans::KMeans( int n )
{
	k = n;
}

void KMeans::init_cluster_centers( vector<Vector> mylist )
{
	point_ids.resize( mylist.size()+10 );
	init_point_indexes( point_ids );
}

int KMeans::clusterize(vector<Vector> mylist)//use the "&"
{
	int convergence = 0;
	cluster_centers.clear();/* pay attention to this. */
	for( int i = 0 ; i < k; i++ )   /* compute the cluster_centers */
	{
		vector<Vector> vec_mean;
		vec_mean.clear();
		vector<double> temp;
		temp.clear();

		for( int j = 0; j < mylist.size(); j++ )
		{
			if( i == point_ids[j] )		vec_mean.push_back( mylist[ j ] );
		}

		temp = vector_mean( vec_mean );//if the vector_mean return the type "Vector"  will be much better
		
		Vector temp1( temp.size() );//convert from vector<double> temp to Vector temp1;

		for( int k = 0 ;k < temp.size(); k++ )
		{
			temp1.set( k ,temp[k] );
		}
		cluster_centers.push_back( temp1 );
	}

	for( int i = 0;i<mylist.size();i++ )
	{
		int pid = get_closest_center_id( mylist[i] );

		if( point_ids[ i ] != pid )	
		{	
			point_ids[i] = pid ; 
			convergence++;
		}
	}

	return convergence;
}

Vector KMeans::get_cluster_center(int i)
{
	return cluster_centers[i];
}

int KMeans::get_point_id(int i)
{
	return point_ids[ i ];
}

int KMeans:: get_closest_center_id( const Vector &X)
{
	double dis = 10000000.0;  //
	int pid ;
	for(  int j = 0 ; j < k ; j++ )
	{
		Vector temp = X;//
		temp.sub( cluster_centers[ j ] );
		if( temp.norm()< dis )
		{
			dis = temp.norm() ;	
			pid = j;
		}
	}
	return pid;
}

void KMeans:: init_point_indexes(vector<int> &pids)
{
	srand(100);
	for( int i =0 ;i<pids.size();i++)
	{
		pids[i] =  rand()  % k ;
	}
	
	/* another method the initialize the point_ids */
	/*
	for( int i = 0 ; i < k ; i++ )
		pids[ i ] = i;
	for( int i = k ; i < pids.size(); i++ )
		pids[ i ]  = 0;
	*/
}


