#include <iostream>
#include <string>
using namespace std;

class MyString {
  string buf;
public:
  MyString(string s = NULL);
  void print() const;
};

MyString::MyString(string s) : buf(s) {}

void MyString::print() const {
  cout << buf << endl;
}

class StringStack {
  static const int size = 100;
  const MyString* stack[size];
  int index;
public:
  StringStack();
  void push(const MyString*);
  const MyString* pop();
};

StringStack::StringStack() : index(0) {
  memset(stack, 0, size * sizeof(MyString*));
}

void StringStack::push(const MyString* s) {
  if (index < size)
    stack[index++] = s;
}

const MyString* StringStack::pop() {
  if (index > 0) {
	const MyString* rv = stack[--index];
	stack[index] = 0;
	return rv;
  }
  return 0;
}

MyString iceCream[] = {
  "bakaliowo-śmietankowe",
  "karmelowe",
  "czekoladowe",
  "migdalowe",
  "czarna porzeczka",
  "cytrynowe",
  "migdalowe",
  "karmelowe w gorzkiej czekoladzie"
};

const int iCsz =
  sizeof iceCream / sizeof *iceCream;

int main() {
  StringStack ss;
  for (int i = 0; i < iCsz; i++) {
	ss.push(&iceCream[i]);
  }
  const MyString* cp;
  while ((cp = ss.pop()) != 0) {
	cp->print();
  }
  char a; cin.get(a);
}
