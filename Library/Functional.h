#ifndef _MY_FUNCTIONAL_INCLUDED
#define _MY_FUNCTIONAL_INCLUDED


// _seq is a custom data structure used for filtering the list
// T is the type of list passed and n is the size of the list
// size n is used to determine the new size of the list after applying filter operation

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
	for(int i=0;i<n;i++)
		list[i]=func(list[i]);
	return list;
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







#endif //_MY_FUNCTIONAL_INCLUDED