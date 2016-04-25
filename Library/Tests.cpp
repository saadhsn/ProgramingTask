#include <iostream>
#include <string>
#include <algorithm>
#include "Functional.h" //Custom library which implements the functional programming features in C++
using namespace std;

 


int main() {

	/*
	Below are the anonymous functions in C++, these works in the same way as 
	funtion object(aka functor) is created and passed to function argument, 
	anonymous functions works with standard C++11.
	*/

	auto _subtract 	= [](int a, int b) {return a-b;};
	auto _sum      	= [](int a, int b) {return a+b;};
	auto _addOne   	= [](int a) {return a+1;};
	auto _concatCopy= [](string a) {return a+ " " + a ;}; //concatenates the string when applied to map function
	auto _square    = [](int a) {return a*a;};
	auto _echoWord  = [](string a) {cout<<a<<endl;};
	auto _echoNum   = [](int a) {cout<<a<<endl;};
	auto _isEven    = [](int a) {

		if(a%2==0)
			return true;
		else 
			return false;
	};
	//Function filters the words starting from a alphabetic only case insensitive
	auto _startsWithS =[](string s) {   
		if(s=="a" || s=="A")
			return true;
		else
			return false;
	};

	int myIntList1 [10]= {1,2,3,4,5,6,7,8,9,10};
	int myIntList2 [10]= {10,9,8,7,6,5,4,3,2,1};
	string myStringList [10]={"a","b","a","d","e","f","a","h","i","j"};

	int* Rlist=new int[10];
	string* Slist=new string [10];

	Rlist=map(myIntList1,10,_square);

	foreach(Rlist,10,_echoNum);
	int sum=foldl(myIntList1,10,_sum);
	cout<<"Sum reduction : "<<sum<<endl;
	cout<<"running filter operation to remove odd numbers"<<endl<<endl;
	_seq<int> FilteredList=filter(myIntList1,10,_isEven);
	foreach(FilteredList.list,FilteredList.size,_echoNum);
	_seq<string> FilteredListS=filter(myStringList,10,_startsWithS);
	cout<<"running filter operation to remove words starting with any alphabet other then a"<<endl;
	foreach(FilteredListS.list,FilteredListS.size,_echoWord);

	pair<int,int>* mergedlist=zip(myIntList1,myIntList2,10);
	cout<<"Merged List Items"<<endl;
    for(int i=0;i<10;i++) {
		cout<<mergedlist[i].first<<","<<mergedlist[i].second<<endl;
    }

	return 0;

}