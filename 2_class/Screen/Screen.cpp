#include "Screen.h"
int main(){

	class Screen myScreen(10,10,'c');
	cout<<myScreen<<endl;

	const class Screen &ms = myScreen;
	cout<<ms<<endl;
	
	myScreen.move(4,0).set('#');
	cout<<myScreen<<endl;
	cout<<ms<<endl;

	myScreen.some_member();
	ms.some_member();

	myScreen.display().set('#');
	ms.diplay().set('^');	

	return 0;
}
