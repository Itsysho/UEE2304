#include <iostream>
#include <fstream>
using namespace std;

class Stack {
public:
	struct Node {
		Node *next;
		int elem;
		Node(int elem) {
			this->elem = elem;
			this->next = nullptr;
		}
	};
	Node *top;
	int _size;
	Stack() {
		top = nullptr;
		_size = 0;
	}
	
	void push(int e) {
		Node *u = new Node(e);
		u->next = top;
		top = u;
		_size++;
	}

	int pop() {
		int data;
		if (top == nullptr) {
			data = 0;
		} else {
			Node *temp = top;
			top = temp->next;
			data = temp->elem;
			delete temp;
			_size--;
		}
		return data; 
	}
	
	int size() {
		return _size;
	}
};

int main() {
	int x;
	ifstream fin("input.txt");
	ofstream fout("answer.txt"); 
	Stack stk;
	while (fin >> x) {
		if (x > 0) {
			stk.push(x);
		} else {
			if (stk.size() < 5) {
				fout << "ERROR ";
				return 0;
			}
			for (int i = 0; i < 5; i++) {
				int e = stk.pop();
				fout << e << " ";
			}
		}
	}
	return 0;
}
