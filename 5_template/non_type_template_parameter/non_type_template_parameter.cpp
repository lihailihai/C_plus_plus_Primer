#include<iostream>
#include<stdexcept>
#include<functional>
using namespace std;
template<typename T=int, int MAXSIZE=10>
class Stack{
	public:
		T elems[MAXSIZE];
		int size = MAXSIZE;
		int numElems=0;
	public:
		Stack();
		void push(T const &);
		void pop();
		T top() const;
		bool empty() const{
			return numElems == 0;
		}

		bool full() const{
			return numElems == MAXSIZE;
		}
};

template<typename T, int MAXSIZE>
 Stack<T,MAXSIZE>::Stack():numElems(0){}

template<typename T, int MAXSIZE>
void Stack<T,MAXSIZE>::push(T const & elem){
	if(numElems == MAXSIZE){
		throw out_of_range("Stack<>::push(): stack is full");
	}

	elems[numElems] = elem;
	++numElems;
}

template<typename T,int MAXSIZE>
void Stack<T,MAXSIZE>::pop(){
	if(numElems <= 0){
		throw out_of_range("Stack<>::pop(): stack is empty");
	}
	--numElems;
}
template<typename T,int MAXSIZE>
T Stack<T,MAXSIZE>::top() const{
	if(numElems <= 0){
		throw out_of_range("Stack<>::top(): stack is empty");
	}
	return elems[numElems -1];
}

int main(){
	try{
//		Stack<int,0> int0stack;
		Stack<> defaultstack;
		defaultstack.push(10);
		cout<<defaultstack.size<<endl;
		cout<<defaultstack.top()<<endl;

		Stack<int,10> int10stack;
		int10stack.push(10);
		cout<<int10stack.top()<<endl;

		Stack<> * item = new Stack<>();
		item->push(10);
		cout<<item->top()<<endl;

	}catch(exception  const & ex){
		cout<<"Exception:"<<ex.what()<<endl;
	}
	return 0;
}
