#ifndef NODE_H
#define NODE_H

#include <iostream>
#include <string>

template <class Pokemon>
class Node
{
private:
	Pokemon data;
	Node<Pokemon>* ptrFront;
	Node<Pokemon>* ptrRear;
public:
	//Constructors
	Node()
	{
		ptrFront = nullptr;
		ptrRear = nullptr;
	}
	Node(Pokemon &D)
	{
		data = D;
		ptrFront = nullptr;
		ptrRear = nullptr;
	}
	Node(Pokemon &D, Node<Pokemon>* ptrN)
	{
		data = D;
		ptrFront = ptrN;
		ptrRear = nullptr;
	}
	Node(Pokemon &D, Node<Pokemon>* ptrN, Node<Pokemon>* ptrR)
	{
		data = D;
		ptrFront = ptrN;
		ptrRear = ptrR;
	}

	//Setters
	void setData(Pokemon &d)
	{
		data = d;
	}
	void setPtrFront(Node<Pokemon>* pF)
	{
		ptrFront = pF;
	}
	void setPtrRear(Node<Pokemon>* pR)
	{
		ptrRear = pR;
	}


	//Getters
	Pokemon getData() const
	{
		return data;
	}
	Node<Pokemon>* getPtrFront() const
	{
		return ptrFront;
	}
	Node<Pokemon>* getPtrRear() const
	{
		return ptrRear;
	}

};
#endif // !NODE_H

//
//#ifndef NODE_H
//#define NODE_H
//
//#include <iostream>
//#include <string>
//
//template <class T>
//class Node
//{
//public:
//	T data;
//	Node<T> *leftBranch;
//	Node<T> *rightBranch;
//
//	// defualt constructor
//	Node()
//	{
//		leftBranch = nullptr;
//		rightBranch = nullptr;
//	}
//
//	// constructor
//	Node(T value)
//	{
//		data = value;
//		leftBranch = nullptr;
//		rightBranch = nullptr;
//	}
//};
//
//#endif // !NODE_H