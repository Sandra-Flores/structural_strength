//  Name: Daniel Calderon
//  Name: Angel Gonzalez
//  Name: Sandra Flores
//  Name: Miguel Fletes
//  Nov 1 ,2015
// structural strength code
/* Question answered: Going by the data, neither of the items will be able to hold the amount of force required. If you go to three standard deviations the value will be below 16000 and as a result the bridge will succumb to the weight.*/

#include <vector>
#include <iostream>
#include <fstream>
#include <cstdlib>
#include <cmath>

using namespace std;

double mean(ifstream& fin);
void maxMin(int ary[], int n,ofstream& fout);
double stdDev(ifstream& fin);
double var(ifstream& fin);
 
 int main()
 {
    ifstream fin,finB;
    ofstream fout;
    
    fin.open("data1.txt");
    finB.open("data2.txt");
    fout.open("results.txt");
    
    double val =0,valDeviation = 0,valDeviationB = 0,valVariance = 0,valVarianceB = 0;
    const int SIZE = 10;
	string string1;
	int value, value1;
	int numbers[SIZE] = {0};
	int numbers1[SIZE] = {0};
	string word;
	
	val = mean(fin);
	fout << "The mean is: " << val << endl;
	fout << " " << endl;
//******************************************************************************** 	
	fin.clear();
	finB.clear();
	fin.seekg(0);
	finB.seekg(0);
	
	valDeviation = stdDev(fin);

	valDeviationB = stdDev(finB);

	fout << "The standard devaition for steel is: " << valDeviation << endl;
	fout << " " << endl;
	fout << "The standard deviation for graphite is: " << valDeviationB << endl;
	fout << " " << endl;
//******************************************************************************** 	

	for(int ix = 0; ix < 1; ix++)
	{
    	fin >> string1;   
	}   
	for(int ix = 0; ix < SIZE; ix++)
	{
    	fin >> value;
    	
    	numbers[ix] = value;
	}
	
	fin.clear();
	finB.clear();
	fin.seekg(0);
	finB.seekg(0);
	

	for(int ix = 0; ix < 1; ix++)
	{
    	finB >> string1;   
	}   
	for(int ix = 0; ix < SIZE; ix++)
	{
    	finB >> value1;
    	
    	numbers1[ix] = value1;
	}
    fout << "The max and min for steel are: " << endl;
	maxMin(numbers, SIZE,fout);
	fout << "The max and min for graphite are: "<< endl;
	maxMin(numbers1, SIZE,fout);
//******************************************************************************** 
	fin.clear();
	finB.clear();
	fin.seekg(0);
	finB.seekg(0);
	valVariance = var(fin);
	valVarianceB = var(finB);
	
	fout << "The variance for steel is: " << valVariance << endl;
	fout << " " << endl;
	fout << "The variance for graphite is: " << valVarianceB << endl;
//******************************************************************************** 	
    fin.close();
    finB.close();
    fout.close();
 
 return 0;
 }
//******************************************************************************** 
double mean(ifstream& fin)
{
    int ary[20];
    string word;
    int val,size = 0;
    int ix=0;
    int sum = 0;
    int i = 0;
    for(i; i < 1; i++) 
    {
        fin >> word;
    }
        while(fin >> val)
    {
        ary[ix] = val;
        
        ix++;
        size++;
    }
    
    for(i =0; i < size;i++)
    {
        sum += ary[i];
    }
   
    return sum/size ;
}
//******************************************************************************** 
void maxMin(int ary[], int n,ofstream& fout)
{
  
	int min = ary[0];
	for(int ix = 0; ix < n; ix++)
	{
    	if(ary[ix] < min)
    	{
       	min = ary[ix];
    	}
	}
	fout << "min: " << min << endl;
	fout << endl;
    
	int max = ary[0];
	for(int ix = 0; ix < n; ix++)
	{
    	if(ary[ix] > max)
    	{
       	max = ary[ix];
    	}
	}
	fout << "max: " << max << endl;
	fout << endl;
	
    
}
//******************************************************************************** 
double var(ifstream& fin)
{

    double ary[5000];
    int sizeAry = 0;
    double temp, sum = 0, average, variance;
    double squareSum = 0; //holds the square root sum of average - actual number in the array
    int ix = 0;
    string word;
    for(int i =0; i < 1; i++) 
    {
        fin >> word;
    }
    while (fin >> temp)
    {
        sizeAry++;
        ary[ix] = temp;
        ix++;
    }
    for(int i = 0; i < sizeAry ; i++)
    {
        sum += ary[i];
    }
    average = sum/sizeAry;
    for(int i = 0; i < sizeAry ; i++)
    {
        squareSum += (ary[i] - average) * (ary[i] - average);
    }
    variance = squareSum/sizeAry;
    
    fin.clear();
    fin.seekg(0);  
    
    return variance; 
}
//******************************************************************************** 
double stdDev(ifstream& fin)
{
    double ary[5000];
    int sizeAry = 0, ix = 0;; //need the size of the array :~
    double variance = var(fin);//need the variance
    double temp;
    string word;
    for(int i = 0; i < 1; i++) 
    {
        fin >> word;
    }
    while (fin >> temp)//eats values to find out the # of things
    {
        sizeAry++;
        ary[ix] = temp;
        ix++;
    }
    
    fin.clear();
    fin.seekg(0);  
    
    return sqrt(variance/sizeAry); //all stdDev does is return the square root of the variance divided by the number of values

}









