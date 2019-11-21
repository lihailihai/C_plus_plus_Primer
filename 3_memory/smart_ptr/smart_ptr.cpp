#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

int main(){

	shared_ptr<float> fl = make_shared<float>();

	auto p = make_shared<int>(10);
	cout<<"*p:"<<*p<<endl;

	shared_ptr<string> s = make_shared<string>(10,'l');
	cout<<"s->"<<*s<<endl;

	auto ss(s);
	cout<<"ss->"<<*ss<<endl;

//	shared_ptr<double> p1 = new double(1024); //error

	shared_ptr<double> p2(new double(1024));
	cout<<"*p2"<<*p2<<endl;	
	
	s.reset(new string(10,'h'));
	cout<<"s->"<<*s<<endl;
//*******************************************************
	string sss = "using unique_ptr";
	unique_ptr<string> p3(new string("Test unique ptr"));
	unique_ptr<string> p4(p3.release());
	cout<<*p4<<endl;

	unique_ptr<string> p5(new string("haili"));
	p5.reset(p4.release());
	cout<<*p5<<endl;
	//p3.reset(p4.release());
	//cout<<*p3<<endl;
//******************************************************
	allocator<string> alloc;
	int n = 10;
	auto const pp = alloc.allocate(n);
	auto q = pp;
	for(int i=0; i<n; ++i){
		alloc.construct(q++,10,'i');
	}
	cout<<*pp<<endl;

	while(pp != q){
		alloc.destroy(--q);
	}

	alloc.deallocate(pp,n);


	vector<int> vi ={1,2,3,4,5,6};
	allocator<int> alloc2;
	auto ppp = alloc2.allocate(vi.size()*2);

	auto qq = uninitialized_copy(vi.begin(),vi.end(),ppp);
	cout<<*ppp<<*(ppp+1)<<endl;
	cout<<*qq<<*(qq-1)<<endl;
	auto qqq = uninitialized_fill_n(qq,vi.size(),42);
// uninitiallized_full(qq.begin(), qq.end(),78);   
	cout<<*(qqq-1)<<endl;
	return 0;

}
