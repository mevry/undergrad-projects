// Stacks.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include "Stack.h"
#include "StringStack.h"
#include "Person.h"
#include <vector>
using namespace std;
using std::cout;
using std::endl;
void poppedMessage(std::string popped) {
	std::cout << "\tString: " << popped << std::endl;
}

int main()
{
	/*StringStack* ss = new StringStack("This is the base.");
	ss->push("Next Node");
	ss->push("Another Node");
	ss->pop();
	ss->push("Top Node");
	ss->pop();
	ss->pop();
	ss->pop();
	ss->pop();
	ss->getStats();

	std::cout << "Program Exited Successfully" << std::endl;*/
	

	/*cout << "Stack of STRING" << endl;
	cout << "---------------" << endl;
	Stack<string> *str_stack = new Stack<string>(new string("Base Node"));
	str_stack->push(new string("Second Node"));
	str_stack->push(new string("Third Node"));
	str_stack->pop();
	str_stack->push(new string("Top Node"));
	str_stack->enumerate();

	cout << endl;
	cout << "Stack of BOOL" << endl;
	cout << "-------------" << endl;
	bool bool1 = true;
	bool bool2 = false;
	bool bool3 = true;
	bool bool4 = false;
	Stack<bool> *bool_stack = new Stack<bool>(&bool1);
	bool_stack->push(&bool2);
	bool_stack->push(&bool3);
	bool_stack->pop();
	bool_stack->push(&bool4);
	bool_stack->enumerate();*/

	vector<Person*> peopleList = vector<Person*>{
		new Person("Miller", "Derek", 33),
		new Person("Smith", "John", 24),
		new Person("Jackson", "Bethany", 44),
		new Person("Parker", "Trey", 50),
	};

	Stack<Person> *people = new Stack<Person>();

	for (auto person : peopleList) {
		people->push(person);
	}


	cout << endl;
	cout << "Stack of PERSON" << endl;
	cout << "---------------" << endl;

	people->enumerate();

	cout << endl;
	cout << "Popping First 2 People" << endl;
	cout << "----------------------" << endl;

	for (int i = 0; i < 2; i++) {
		cout << *people->pop() << endl;
	}

	cout << endl;
	cout << "Remaining in Stack" << endl;
	cout << "------------------" << endl;
	people->enumerate();
	cout << endl;

    return 0;
}


