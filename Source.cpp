/*1. Սահմանել աբստրակտ պարամետրիզացված հերթ հետևյալ գործողություններով.
bool empty() const=0;  		//դատարկ է, թե ոչ 
T& 	front()const=0;  		//հղում հերթի առաջին տարրի վրա. 
							//ենթադրվում է, որ հերթը դատարկ չէ
void pop()=0;				//հերթի առաջին տարրի հեռացում. 
							//ենթադրվում է, որ հերթը դատարկ չէ
void push(const T& elem)=0;	// տարրի ավելացում հերթին.
//ենթադրվում է, որ հիշողության //պակաս չի կարող առաջանալ
2. Իրականացնել այս աբստրակտ հերթը հաջորդական և կապակցված պարամետրիզացված հերթերի միջոցով: 
3. Բերել կառուցված դասերը տեստավորող օրինակ:
*/
#include <iostream>
using namespace std;

/*class Queue*/
template<class T>
class Queue {
public:
	Queue() {}
	virtual ~Queue() {}
	virtual bool empty()const = 0;
	virtual T& front()const = 0;
	virtual void pop() = 0;
	virtual void push(const T& elem) = 0;
};

/* continuous Queue */
template <class T, int MAX_SIZE = 100>
class cQueue : public Queue<T> {
private:
	T* array;
	int start;
public:
	cQueue() :array(new T[MAX_SIZE]), start(-1) {}
	~cQueue() { delete array; }

	bool empty() const {
		if (start == -1)
		
		return true
			;
		else
			return false;
	}

	T& front()const {
		if (!empty())
		return array[start];
		else
		cout << "queue is empty" << endl;
	}

	void pop() {
		if (empty())
		{
			cout << "queue is empty" << endl;
			return;
		}
		array[start--] = NULL;
	}

	void push(const T& elem) {
		for (int i = start + 1; i > 0; --i)
		{
			array[i] = array[i - 1];
		}
		array[0] = elem;
		++start;
	}
};



/* linked Queue */
template<class T>
class lQueue : public Queue<T> {
private:
	struct Node {
		T info;
		Node* link;
		Node(const T& elem, Node* addr_) : info(elem), link(addr_) {}
	};
	Node* start;
public:
	lQueue() :start(0) {}
	~lQueue() {
		Node* p;
		while (start) {
			p = start;
			start = start->link;
			delete p;
		}
	}
	bool empty() const {
		if (start == 0)
			return true;
		else
			return false;
	}
	T& front() const {
		if (!empty())
		return start->info;
		else
		cout << "queue is empty" << endl;
	}

	void pop() 
	{
		if (start == NULL)
		{
			cout << "queue is empty" << endl;
			return;
		}
		Node* ptr = start;
		Node* first = start->link;
		delete start;
		while (ptr->link != NULL) {
			ptr = ptr->link;
		}
		start = ptr;
		start->link = first;
	}

	void push(const T& elem) {
		if (empty())
		{
			start = new Node(elem, start);
			return;
		}
		Node* ptr = start->link;
		start->link = new Node(elem, ptr);
	}
};


/* testing */
int main()
{
	char type;
	Queue<char>* s;
	cout << "queue type?(c/l):";
	cin >> type;
	if (type == 'c')
		s = new cQueue<char, 10>;
	else
		s = new lQueue<char>;
	s->push('g');
	s->push('i');
	cout << s->front() << endl;
	s->pop();
	cout << s->front() << endl;
	s->pop();
	cout << s->empty() << endl;
	delete s;
	return 0;
}
