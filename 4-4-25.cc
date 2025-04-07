#include "/public/read.h" // IWYU pragma: keep
#include <stdexcept> // IWYU pragma: keep
#include <vector> // IWYU pragma: keep
#include <algorithm> // IWYU pragma: keep
#include <numeric> // IWYU pragma: keep
#include <cassert> // IWYU pragma: keep
using namespace std;

template <class T>
class BST {
	//A class within a class
	struct Kernel {
		T data{}; //Call the default cstor
		Kernel *left{}, *right{};
		int count = 1; //Allow duplicates
	};
	Kernel *root = nullptr;
	int size = 0;
	Kernel* ptr_search(T key) const {
		return nullptr;
	}
	void print_recursive(Kernel *ptr) const {
		if (ptr == nullptr) return;
		print_recursive(ptr->left);
		cout << ptr->data << endl;
		print_recursive(ptr->right);
	}
	public:
	BST(){}
	~BST(){} //TBD
	auto get_size() const { return size; }
	void insert(T key) {
		Kernel *old_guy = ptr_search(key);
		//Special multitree thingy
		if (old_guy) {
			old_guy->count++;
			size++;
			return;
		}
		//Normal BST insert
		Kernel *new_guy = new Kernel{key};
		//Special cases for insert?
		//Special #1: Empty
		if (root == nullptr) {
			root = new_guy;
			size++;
			return;
		}
		Kernel *temp = root;
		while (true) {
			if (key < temp->data) { //Go left
				if (temp->left) { //We have a left child
					temp = temp->left;
					continue;
				}
				temp->left = new_guy;
				size++;
				return;
			}
			else { //New guy is larger than us
				if (temp->right) { //If we have a right child
					temp = temp->right;
					continue;
				}
				temp->right = new_guy;
				size++;
				return;
			}
		}
	}
	//Stub function is a dummy function that just returns something plausible
	bool search(T key) const {
		return false; //SUS 🪬
	}
	void destroy(T key) {} 
	void print() const {
		print_recursive(root);
	} 
};

//Driver
//A driver is a simple main function that calls your code and tests it for correctness
int main() {
	static_assert(sizeof(int) == 4,"Ints must be four bytes for this code to work.");
	BST<string> tree;
	tree.insert("Stef");
	tree.insert("Justis");
	tree.insert("Zebra");
	tree.insert("Abumaali");
	tree.insert("Xanadu");
	tree.insert("Bruno");
	assert(tree.get_size() == 6 && "Your insert is broken bruh");
	cout << "Test #1 Passed\n";
	tree.print();
}










