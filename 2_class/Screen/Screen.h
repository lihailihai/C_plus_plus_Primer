#include <iostream>
#include <string>
#include <vector>
using namespace std;
class Window_mgr;
class Screen{
	public:
		typedef string::size_type pos;
		// using pos = string::size_type;
		Screen() = default;
	        Screen(pos ht, pos wd, char c): cursor(ht), height(ht), width(wd),
		contents(ht*wd,c){}
		char get() const{
			return contents[cursor];
		}
		
		void some_member() const;
		inline char get(pos ht, pos wd) const;
		Screen& move(pos r, pos c);
		Screen &set(char);
		Screen &set(pos,pos,char);
		friend ostream &operator<<(ostream& os, const Screen& screen){
			os<<"height: "<<screen.height<<" "<<"width:"<<screen.width
				<<" "<<"cursor:"<<screen.cursor<<
				" "<<"contents:"<<screen.contents<<endl;
			return os;
		}
		
		Screen &display(){
			cout<<*this<<endl;
			return *this;
		}
		
const Screen &display() const{
			cout<<*this<<endl;
			return *this;
		}
// defination the class Window before class Screeen,then declare and define the class Screen and friend-function.
//friend Window_mgr::addScreen(int a);  
//friend Window_mgr::ScreenIndex Window_mgr::addScreen(const Screen& screen);
	private:
		pos cursor = 0;
		pos height = 0, width = 0;
		string contents;
		mutable size_t access_ctr;
};

inline Screen &Screen::move(pos r,pos c){
	pos row = r * width;
	cursor = row + c;
	return *this;
}

inline char  Screen::get(pos r, pos c) const{
	pos row = r * width;
	return contents[row + c];
}

void Screen::some_member() const {
	++access_ctr;
}

Screen &Screen::set(char c){
	contents[cursor]  = c;
	return *this;
}

Screen &Screen::set(pos r, pos col, char ch){
	contents[r*width + col];
	return *this;

}
class Window_mgr{
	using ScreenIndex=Screen::pos;
	public:
		void addScreen(int a){
			cout<<"Inside class Window_mgr addsome"<<endl;
		};
		ScreenIndex addScreen(const Screen& screen);
	private:
		vector<Screen> screens{Screen(24,80,' ')};

	size_t	ScreeenIndex;
};

Window_mgr::ScreenIndex Window_mgr:: addScreen(const Screen& screen){
	return 1;
}




