/*******************************************************************
 * Copyright (C) Leaguenew-USTC, 2012                                
 *                                                                  
 * FILE NAME             :  Test.cpp                                
 * PRINCIPAL AUTHOR      :  leaguenew                               
 * MODULE NAME           :  TEST                           
 * LANGUAGE              :  C++                                      
 * TARGET ENVIRONMENT    :  windows                                   
 * DATE OF FIRST RELEASE :  2012/12/20                              
 * DESCRIPTION           :  test all the functions whether to work 
							correctly
 ******************************************************************/

/*
 * Revision log:
 *
 * Created by leaguenew,2012/12/20
 * Modified by leaguenew,2013/1/3
 *
 */

#include "stdafx.h"
#include "KahanSum.h"
#include "Median.h"
#include "Vector.h"
#include "kmeans.h"
#include "functions.h"

#include<iostream>
#include<cmath>
#include<cstdlib>
#include<algorithm>
#include<string>
#include<iomanip>

using namespace std;

/*Test for KahanSum*/
/*
int main()
{
    KahanSum KS;
    KS.reset();
    int n;
	cout<<"please input the number n:"<<endl;
    cin>>n;
    for( double i = 1.0;i<= n ;i++)    
	{ 
   		KS.add( i );
	}
    cout<<KS.get_sum()<<endl;
    return 0;
}
*/


/*Test for Median*/
/*
int main()
{
    Median md;
    while(1){
    	md.reset();
    	int n,i;
		cout<<"please input the dimension of vector:"<<endl;
    	cin>>n;
    	for( i = 0;i < n ;i++)    
      		md.add( (double)rand());
		cout<<"The original list is :"<<endl;
    	md.showall();
		cout<<endl<<"The median is:"<<md.get_median()<<endl;
		cout<<endl<<"The ordered list is :"<<endl;
    	md.showall();
    }
    return 0;
}
*/



/*Test for Vector*/

/*
int main()
{
    int n;
	cout<<"please input the size of the vector:"<<endl;
    cin>>n;
    Vector A(n),V(n);
    
	A.fill(2.2);
	cout<<"show all the values in the vector A:"<<endl;
	A.Show();

    V.fill(1.1);
	cout<<"show all the values in the vector V:"<<endl;
	V.Show();
	

    A.add(V);
	cout<<"A=A+V:"<<endl;
	A.Show();

	A.sub(V);
	cout<<"A=A-V:"<<endl;
	A.Show();

	A.mul(2);
	cout<<"A=2*A"<<endl;
	A.Show();

	A.inc_mul(V,2);
	cout<<"A=A+2*V"<<endl;
	A.Show();
	
	cout<<"A.V:"<<A.dot(V)<<endl;

	cout<<"The square_norm of the vector:"<<A.square_norm()<<endl<<endl;

	cout<<"The norm of the vector:"<<A.norm()<<endl<<endl;

	cout<<"The sum of all the values of the vector:"<<A.sum()<<endl<<endl;

	cout<<"The minimum of all the values is :"<<A.min()<<endl<<endl;

	cout<<"The maximum of all the values is :"<<A.max()<<endl<<endl;

	return 0;	
}
*/

/* Test for write_data & read_data */
/*
int main()
{
	vector<Vector> vlist;
	vector<int> pid(4000,1);
	string filename ;
	string a;
	cout<<"please input the filename to be process:"<<endl;
	cin>>filename;

	vlist = read_data( filename );

	write_data( "myout" ,vlist,pid);
	return 0;
}
*/

/*Test for vector_mean*/
/*
int main()
{
	===============================================================================
	vector<Vector>	 vlist;
	vector<double> vec_mean;
	string filename;
	cout<<"please input the filename to be process:"<<endl;
	cin>>filename;
	vlist = read_data(filename);
	vec_mean = vector_mean( vlist );
	
	for( int i = 0; i<vec_mean.size();i++ )
		cout<<setprecision(15)<<setiosflags(ios::scientific)<<vec_mean[i]<<endl;
	return 0;
	===============================================================================
	===============================================================================
	vector<Vector> vlist;
	vector<double> temp;

	vlist = read_data("read_data.txt");
	temp = vector_mean( vlist );

	Vector vec_mean( temp.size() );
	for( int i = 0 ; i<temp.size() ; i++ )
		vec_mean.set(i,temp[i]);

	for( int i = 0 ; i<vec_mean.getSize() ; i++ )
	{
		cout<<"enter2"<<endl;
		cout<<vec_mean.get(i)<<endl;
	}
	return 0;
	===============================================================================
}
*/

/*Test for vector_median*/
/*
int main()
{
	vector<Vector>	 vlist;
	vector<double> vec_median;
	string filename;
	cout<<"please input the filename to be process:"<<endl;
	cin>>filename;
	vlist = read_data(filename);
	vec_median = vector_median( vlist );
	
	for( int i = 0; i<vec_median.size();i++ )
		cout<<setprecision(15)<<setiosflags(ios::scientific)<<vec_median[i]<<endl;
	return 0;
}
*/


/*Test for KMeans*/


int main()
{
	vector<Vector>  veclist;
	vector<int>		pids	;
	
	
	string filename;
	cout<<"please input the filename to process:"<<endl;
	cin>>filename;
	
	veclist = read_data( filename );/* dataset-1/dataset-2/dataset-3/dataset-4 */
	
	int k; /* (k)means */
	cout<<"please input the number of clusters K:"<<endl;
	cin>>k;
	
	KMeans kmeans( k );

	double convergence = veclist.size() * 0.10; /* obtain the convergence */
	
	kmeans.init_cluster_centers( veclist );

	while( kmeans.clusterize( veclist ) > (int)convergence )
		continue;

	for( int i = 0 ; i < veclist.size(); i++ )
		pids.push_back( kmeans.get_point_id( i ) );

	write_data( "myout" ,veclist , pids);
	system("pause");
	return 0;
}

