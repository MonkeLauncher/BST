#include <iostream>

using namespace std;


template <class T>
class BST {
	BST *right = nullptr, *left = nullptr;
	T container;
	long long level;
	
public:
	BST (T var, int lev = 1) 
	: container(var), level(lev) {}
	
	void add (T var) {
		if (var <= container) {
			if (left != nullptr) {
				left -> add (var);
				return;
			}
			
			left = new BST <T> (var, level + 1);
		}
		
		else {
			if (right != nullptr) {
				right -> add (var);
				return;
			}
			
			right = new BST <T> (var, level + 1);
		}
	}
	
	long long find (T var) {
		if (var == container) return level;
		if (var < container) return left -> find (var);
		return right -> find (var);
	}
	
	void printList () {
		if (left != nullptr) left -> printList ();
		cout << container << " ";
		if (right != nullptr) right -> printList ();
	}
	
	long long maxLevel () {
		long long a = level, leftlevel = 0, rightlevel = 0;
		
		if (left != nullptr) leftlevel = left -> maxLevel();
		if (right != nullptr) rightlevel = right -> maxLevel();
		
		a = (a > leftlevel ? a : leftlevel);
		a = (a > rightlevel ? a : rightlevel);
		
		return a;
	}
};



int main () {
	int lista[6] = {4, 2, 3, 1, 6, 5};
	BST <int> tree (0);
	
	for (int i = 0; i < 6; i++) {
		tree.add (lista[i]); 
	}
	
	cout << tree.find(3) << endl;
	tree.printList(); cout << endl;
	cout << tree.maxLevel();
}
