#ifndef _MY_FUNCTIONAL_INCLUDED
#define _MY_FUNCTIONAL_INCLUDED

#include<algorithm>
using namespace std;


/* _seq is a custom data structure used for filtering the list
 T is the type of list passed and n is the size of the list
 size n is used to determine the new size of the list after 
applying filter operation
*/

template <class T>
struct _seq {
	T* list;
	int n;
	_seq() {list = NULL; n=0;}
	_seq(T* _list, int _n) : list(_list), n(_n) {}
	void del() {free(list);}
};

/*
Map function, it accepts the list of arbitray type, size of list and func
@list : list passed to function
@n    : size of the list
@func : function passed to map function
*/

template<class L, class F>
L * map (L* list,int n ,F func ) {

	L* mappedlist=new L[n]; //A new list created which will be returned after applying map function
    for(int i=0;i<n;i++)
      mappedlist[i]=func(list[i]);
    return mappedlist;

}
/*
forEach function similar to map function
applies function passed to forEach on each item of the list
*/

template<class L, class F>
void foreach (L*list, int n, F func) {
	for(int i=0;i<n;i++)
		func(list[i]);
}

/*
Filter function takes list as input, and predicate function.
It then removes the item from lists which are false for predicate
Returns new list with entries containing only the desired items
@list:list passed
@n   :size of the list
@pred: predicate function passed
@flag:boolean array which maps the corresponding entries of list either 
true or false
*/

template<class L , class P>
_seq<L> filter(L* list, int n, P pred) {
	int compact=0; //size of the compact list
	int counter=0; //to fill the entries in new list
	bool* flag=new bool[n];
	for(int i=0;i<n;i++) {
		flag[i]=(bool)pred(list[i]);
		if(flag[i])
			compact++;
	}
	L* filteredList=new L[compact];
	for(int i=0;i<n;i++) {
		if(flag[i]) {
			filteredList[counter]=list[i];
			counter++;
		}
	}
	free (flag); //Removing the helper boolean list
	return _seq<L>(filteredList,compact);
}

/*
Fold left function,technically this is called LEFT reduction/accumulation 
because the operators are applied left to right, for example:
reduce(lambda x,y:x-y,[1,2,3]) will return -4-->(1-2)-3
*/

template<class L, class F>
L foldl(L* list, int n,F func ) {
	L r=list[0];

	for(int i=1;i<n;i++)
		r=func(r,list[i]);
	return r;
}

/*
Fold right functioin is right associative for example:
reduce(lambda x,y:x-y,[1,2,3]) will return 2-->1-(2-3)=2
	

*/

template<class L, class F>
L foldr(L* list, int n,F func ) {
	L r=list[n-1];

	for(int i=1;i<n;i++)
		r=func(list[n-1-i],r);
	return r;
}

/*
Zip operation is performed on two lists, which concatenates the
items of two lists into pairs.
The resuslt of merged lists is stored in pair type, which can store
items in its first and second data members.
*/

template<class L1, class L2>
pair<L1,L2> * zip(L1* firstlist, L2* secondlist,int n) {
	pair<L1,L2> * merged= new pair<L1,L2> [n];
	for(int i=0;i<n;i++) {
		merged[i].first=firstlist[i];
		merged[i].second=secondlist[i];
	}
		
	return merged;

}

/*
This is the same zip operation, this variant is used in the case
if the size of two list differ, for this function , size of each list
is required in the arguments.

*/

template<class L1, class L2>
pair<L1,L2> * zip(L1* firstlist, int a, L2* secondlist,int b) {

	int list_size=min(a,b);
	pair<L1,L2> * merged= new pair<L1,L2> [list_size];
	for(int i=0;i<list_size;i++) {
		merged[i].first=firstlist[i];
		merged[i].second=secondlist[i];
	}
		
	return merged;

}





#endif //_MY_FUNCTIONAL_INCLUDED