#include <iostream>
template<typename T>
class TStack {
private:
	int mem;
	int n;
	T* stack;
public:
	TStack() {
		n = 0;
		mem = 1;
		stack = new T[1];
	};

	TStack(const TStack<T>& s1) {
		n = s1.n;
		mem = s1.mem;
		stack = new T[mem];
		for (int i = 0; i < n; i++) {
			stack[i] = s1.stack[i];
		}
	};
	~TStack() {
		n = 0;
		mem = 0;
		delete[] stack;
	};
	void push(T e) {
		if (n >= mem) {
			mem = 2 * mem;
			T* temp = stack;
			stack = new T[mem];
			for (int i = 0; i < n; i++) {
				stack[i] = temp[i];
			}
			delete[] temp;
			stack[n] = e;
			n++;
		}
		else {
			stack[n] = e;
			n++;
		}	
	};
	void pop() {
		n--;
	};
	T top() const{
		return (stack[n - 1]);
	};
	int size() const {
		return n;
	};
	bool empty() const{
		return n == 0;
	};
	bool operator==(const TStack& t) const {
		bool res = true;
		if (n != t.n) {
			return false;
		}
		for (int i = 0; i < n; i++) {
			if (stack[i] != t.stack[i]) {
				res = false;
			}
		}
		return res;
	}
};