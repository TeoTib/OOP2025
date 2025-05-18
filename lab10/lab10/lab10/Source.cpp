#include <iostream>
using namespace std;

class myexception : public exception
{
	virtual const char* what() const throw()
	{
		return "Indexul dat ca parametru e mai mare decat size-ul array-ului";
	}
} myex;
class myexception2 : public exception
{
	virtual const char* what() const throw()
	{
		return "Nu poti imparti prin zero";
	}
} myex2;
class myexception3 : public exception
{
	virtual const char* what() const throw()
	{
		return "Nu am gasit elementul in array";
	}
} myex3;

template <typename A>
class Array
{
private:
	A* array;
	int size;
	int sizeactual;
public:
	Array(int size)
	{
		array = new A[size];
		this->size = size;
		sizeactual = 0;
	}
	~Array()
	{
		delete[] array;
		size = 0;
	}
	void operator +=(A parametru)
	{
		array[sizeactual] = parametru;
		sizeactual++;
	}
	void afisare()
	{
		for (int i = 0; i < sizeactual; i++)
			cout << array[i] << " ";
		cout << endl;
	}
	Array(const Array& n) {
		array = new A[n.size];
		size = n.size;
		sizeactual = n.sizeactual;
		for (int i = 0; i < n.sizeactual; i++)
			array[i] = n.array[i];
	}
	Array(Array&& n) {
		size = n.size;
		sizeactual = n.sizeactual;
		array = n.array;
		n.array = nullptr;
		n.size = 0;
		n.sizeactual = 0;
	}
	void operator + (Array& n)
	{
		//deci la this adaug n prin conc
		int sizefinal = sizeactual + n.sizeactual;
		A* newArray = new A[sizefinal];
		for (int i = 0; i < sizeactual; i++)
			newArray[i] = array[i];
		int j = sizeactual;
		for (int i = 0; i < n.sizeactual; i++)
			newArray[j++] = n.array[i];
		delete[] array;
		array = newArray;
		size = sizefinal;
		sizeactual = sizefinal;
	}
	void operator - (Array& n)
	{
		//scad din this orice aparitie a oricarui element din n
		A* newArray = new A[size];
		int sizeFinal = 0;
		for (int j = 0; j < sizeactual; j++)
		{
			int ok = 1;
			for (int i = 0; i < n.sizeactual; i++)
			{
				if (n.array[i] == array[j])
				{
					ok = 0;
					break;
				}
			}
			if (ok == 1)
				newArray[sizeFinal++] = array[j];
		}
		delete[] array;
		array = newArray;
		sizeactual = sizeFinal;
	}
	void operator *= (int scalar)
	{
		for (int i = 0; i < sizeactual; i++)
			array[i] = array[i] * scalar;
	}
	void operator /= (int scalar)
	{
		if (scalar == 0)
		{
			try
			{
				throw myex2;
			}
			catch (exception& e)
			{
				cout << e.what() << '\n';
			}
		}
		else
		{
			for (int i = 0; i < sizeactual; i++)
				array[i] = array[i] / scalar;
		}

	}
	A& operator[](int key)
	{
		if (key >= sizeactual)
		{
			try
			{
				throw myex;
			}
			catch (exception& e)
			{
				cout << e.what() << '\n';
			}
		}
		else
		{
			return array[key];
		}
	}

	class iterator {
		A* ptr;
	public:
		iterator(A* p) : ptr(p) {}
		A& operator*() { return *ptr; }
		iterator& operator++() { ++ptr; return *this; }
		bool operator!=(const iterator& other) { return ptr != other.ptr; }
	};

	iterator begin() { return iterator(array); }
	iterator end() { return iterator(array + size); }

	iterator gaseste(bool (*callback)(A, int), int value) {
		for (auto it = begin(); it != end(); ++it) {
			if (callback(*it, value)) return it;
		}
		try
		{
			throw myex3;
		}
		catch (exception& e)
		{
			cout << e.what() << '\n';
		}
		return end();
	}

	void sortare()
	{
		for (int i = 0; i < sizeactual - 1; i++)
			for (int j = i + 1; j < sizeactual; j++)
				if (array[i] > array[j])
					swap(array[i], array[j]);
	}


};

bool esteElementulCautat(int x, int value) {
	return x == value;
}




int main()
{
	Array<int> a(10);
	a += 3;
	a += 5;
	a += 10;
	Array<int> b = a;
	b.afisare();
	Array<int> c = move(a);
	c.afisare();
	b + c;
	b.afisare();
	Array<int> d(10);
	d += 5;
	d += 10;
	b - d;
	b.afisare();
	b *= 3;
	b.afisare();
	b /= 3;
	b.afisare();
	b[1] = 1;
	b.afisare();
	int elementCautat = 1;
	auto it = b.gaseste(esteElementulCautat, elementCautat);
	if (it != b.end())
		cout << "s-a gasit elementul" << endl;
	b.sortare();
	b.afisare();


	return 0;
}