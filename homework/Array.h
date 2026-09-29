#pragma once

#include <cassert>
#include <iostream>

using namespace std;

template<class T>
class Array
{
	T* arr = nullptr;
	int size = 0;
	int capacity = 0;

public:

	Array();

	explicit Array(int s);

	Array(const Array& obj);

	Array& operator=(const Array& obj);

	~Array();


	int getSize() const;
	int getSize();

	void setSize(int newS, int grow = 1);

	int getUpperBound() const;

	bool isEmpty() const;

	void freeExtra();

	void removeAll();

	T* getAt(int index) const;

	void setAt(int index, const T& value);

	void add(const T& value);

	void append(const Array<T>& oth);

	T* getdata();

	const T* getdata() const;

	void insertAt(int index, const T& value);

	void removeAt(int index);


	void setRand() const;

	void show() const;

	void remove(int index);

	void insert(int index, const T& value);

	void sort() const;

	void reverse();

	void clear();

	void resize(int newSize);

	void fill(const T& value) const;

	int countValue(const T& value) const;

	int findValue(const T& value) const;

	int get(int index) const;

	void set(int index, const T& value) const;

	bool contains(const T& value) const;

	T& operator[](int idx);


	friend ostream& operator<<(ostream& out, const Array& obj)
	{
		for (int i = 0; i < obj.size; i++)
		{
			out << obj.arr[i] << " ";
		}

		return out;
	}


	friend istream& operator>>(istream& in, Array& obj)
	{
		for (int i = 0; i < obj.size; i++)
		{
			in >> obj.arr[i];
		}

		return in;
	}


	Array operator-() const
	{
		Array result(size);

		for (int i = 0; i < size; i++)
		{
			result.arr[i] = -arr[i];
		}

		return result;
	}


	Array operator/(int n) const
	{
		if (n == 0)
		{
			return *this;
		}

		Array result(size);

		for (int i = 0; i < size; i++)
		{
			result.arr[i] = arr[i] / n;
		}

		return result;
	}


	Array& operator++()
	{
		for (int i = 0; i < size; i++)
		{
			arr[i]++;
		}

		return *this;
	}


	bool operator!() const
	{
		return size == 0 || arr == nullptr;
	}
};



template<class T>
Array<T>::Array() : arr(nullptr), size(0)
{
}


template<class T>
Array<T>::Array(int s)
{
	if (s < 0)
	{
		s = 0;
	}

	size = s;

	if (size > 0)
	{
		arr = new T[size];
	}
	else
	{
		arr = nullptr;
	}
}


template<class T>
Array<T>::Array(const Array& obj)
{
	cout << "copyconstr array\n";

	size = obj.size;

	if (size > 0)
	{
		arr = new T[size];

		for (int i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}
	else
	{
		arr = nullptr;
	}
}



template<class T>
Array<T>& Array<T>::operator=(const Array& obj)
{
	if (this == &obj)
	{
		return *this;
	}

	delete[] arr;

	size = obj.size;

	if (size > 0)
	{
		arr = new T[size];

		for (int i = 0; i < size; i++)
		{
			arr[i] = obj.arr[i];
		}
	}
	else
	{
		arr = nullptr;
	}

	return *this;
}


template<class T>
Array<T>::~Array()
{
	delete[] arr;
}


template<class T>
int Array<T>::getSize() const
{
	return size;
}


template<class T>
int Array<T>::getSize()
{
	return size;
}



template<class T>
void Array<T>::setSize(int newS, int grow)
{
	if (newS < 0)
	{
		newS = 0;
	}

	T* temp = nullptr;

	if (newS > 0)
	{
		temp = new T[newS];

		int minSize = size;

		if (newS < minSize)
		{
			minSize = newS;
		}

		for (int i = 0; i < minSize; i++)
		{
			temp[i] = arr[i];
		}
	}

	delete[] arr;

	arr = temp;
	size = newS;
}



template<class T>
int Array<T>::getUpperBound() const
{
	if (size == 0)
	{
		return -1;
	}

	return size - 1;
}


template<class T>
bool Array<T>::isEmpty() const
{
	return size == 0 || arr == nullptr;
}



template<class T>
void Array<T>::freeExtra()
{
	if (capacity > size)
	{
		if (size > 0)
		{
			T* temp = new T[size];
			for (int i = 0; i < size; i++)
			{
				temp[i] = arr[i];
			}
			delete[] arr;
			arr = temp;
			capacity = size;
		}
		else
		{
			delete[] arr;
			arr = nullptr;
			capacity = 0;
		}
	}
}



template<class T>
void Array<T>::removeAll()
{
	delete[] arr;

	arr = nullptr;
	size = 0;
}

template<class T>
T* Array<T>::getAt(int index) const
{
	assert(index >= 0 && index < size);

	return &arr[index];
}



template<class T>
void Array<T>::setAt(int index, const T& value)
{
	assert(index >= 0 && index < size);

	arr[index] = value;
}



template<class T>
void Array<T>::add(const T& value)
{
	T* temp = new T[size + 1];

	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}

	temp[size] = value;

	delete[] arr;

	arr = temp;

	size++;
}


template<class T>
void Array<T>::append(const Array<T>& oth)
{
	int oldSize = size;

	T* temp = new T[size + oth.size];

	for (int i = 0; i < size; i++)
	{
		temp[i] = arr[i];
	}

	for (int i = 0; i < oth.size; i++)
	{
		temp[oldSize + i] = oth.arr[i];
	}

	delete[] arr;

	arr = temp;

	size += oth.size;
}


template<class T>
T* Array<T>::getdata()
{
	return arr;
}


template<class T>
const T* Array<T>::getdata() const
{
	return arr;
}


template<class T>
void Array<T>::insertAt(int index, const T& value)
{
	assert(index >= 0 && index <= size);

	T* temp = new T[size + 1];

	for (int i = 0; i < index; i++)
	{
		temp[i] = arr[i];
	}

	temp[index] = value;

	for (int i = index; i < size; i++)
	{
		temp[i + 1] = arr[i];
	}

	delete[] arr;

	arr = temp;

	size++;
}

template<class T>
void Array<T>::removeAt(int index)
{
	assert(index >= 0 && index < size);

	T* temp = nullptr;

	if (size - 1 > 0)
	{
		temp = new T[size - 1];

		int j = 0;

		for (int i = 0; i < size; i++)
		{
			if (i != index)
			{
				temp[j] = arr[i];
				j++;
			}
		}
	}

	delete[] arr;

	arr = temp;

	size--;
}



template<class T>
void Array<T>::setRand() const
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = T();
	}
}



template<>
void Array<int>::setRand() const
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = (i * 7 + 3) % 10;
	}
}


template<class T>
void Array<T>::show() const
{
	for (int i = 0; i < size; i++)
	{
		cout << arr[i] << " ";
	}

	cout << endl;
}


template<class T>
void Array<T>::remove(int index)
{
	removeAt(index);
}



template<class T>
void Array<T>::insert(int index, const T& value)
{
	insertAt(index, value);
}



template<class T>
void Array<T>::sort() const
{
	for (int i = 0; i < size - 1; i++)
	{
		for (int j = 0; j < size - i - 1; j++)
		{
			if (arr[j] > arr[j + 1])
			{
				T temp = arr[j];

				arr[j] = arr[j + 1];

				arr[j + 1] = temp;
			}
		}
	}
}



template<class T>
void Array<T>::reverse()
{
	for (int i = 0; i < size / 2; i++)
	{
		T temp = arr[i];

		arr[i] = arr[size - i - 1];

		arr[size - i - 1] = temp;
	}
}



template<class T>
void Array<T>::clear()
{
	removeAll();
}


template<class T>
void Array<T>::resize(int newSize)
{
	setSize(newSize);
}


template<class T>
void Array<T>::fill(const T& value) const
{
	for (int i = 0; i < size; i++)
	{
		arr[i] = value;
	}
}


template<class T>
int Array<T>::countValue(const T& value) const
{
	int count = 0;

	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			count++;
		}
	}

	return count;
}


template<class T>
int Array<T>::findValue(const T& value) const
{
	for (int i = 0; i < size; i++)
	{
		if (arr[i] == value)
		{
			return i;
		}
	}

	return -1;
}



template<class T>
int Array<T>::get(int index) const
{
	assert(index >= 0 && index < size);

	return arr[index];
}



template<class T>
void Array<T>::set(int index, const T& value) const
{
	assert(index >= 0 && index < size);

	arr[index] = value;
}


template<class T>
bool Array<T>::contains(const T& value) const
{
	return findValue(value) != -1;
}


template<class T>
T& Array<T>::operator[](int index)
{
	assert(index >= 0 && index < size);

	return arr[index];
}