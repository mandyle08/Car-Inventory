#ifndef LINKEDLIST_H
#define LINKEDLIST_H

template <class T>
class LinkedList{

  template<class V>
    friend std::ostream& operator<<(std::ostream&, LinkedList<V>&);


  template <class U>
    class Node{
      friend class LinkedList;
      private:
      U*          data;
      Node<U>*    prev;
      Node<U>*    next;
    };

  public:
  LinkedList();
  ~LinkedList();
  LinkedList<T>& operator+=(T*);
  LinkedList<T>& operator-=(T*);
  int getSize() const;
  T* operator[](int); 

  private:
  Node<T>*    head;
  Node<T>*    tail;
  int         size;
};

/*
Function: LinkedList template-Constructor
Purpose:initilizes the size
input/output:none
return: none
*/
template <class T>
LinkedList<T>::LinkedList() : head(0){}

/*
Function: deconstructor LinkedList template
Purpose:frees memory
input/output:none
return: none
*/
template <class T>
LinkedList<T>::~LinkedList(){
  Node<T> *currNode, *nextNode;

  currNode = head;

  while (currNode != 0) {
    nextNode = currNode->next;
    delete currNode->data;
    delete currNode;
    currNode = nextNode;
  }

  head = tail = 0;
}

/*
Function: += operator
Purpose:adds any object to linkedlist
input/output:none
return: customer in list
*/
template <class T>
LinkedList<T>& LinkedList<T>::operator+=(T* newCust)
{
  Node<T> *currNode, *prevNode;
  Node<T>* newNode = new Node<T>();
  newNode->data = newCust;
  newNode->next = 0;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (*(newNode->data) < *(currNode->data))
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (prevNode == 0) {
    head = newNode;
  }
  else {
    prevNode->next = newNode;
  }

  newNode->next = currNode;
  size++;
  return *this;
}

/*
Function: -= operator
Purpose:removes any object in linkedlist
input/output:none
return: none
*/
template <class T>
LinkedList<T>& LinkedList<T>::operator-=(T* cust)
{
  Node<T> *currNode, *prevNode;

  currNode = head;
  prevNode = 0;

  while (currNode != 0) {
    if (currNode->data == cust)
      break;
    prevNode = currNode;
    currNode = currNode->next;
  }

  if (currNode == 0) 
    return *this;

  if (prevNode == 0) {
    head = currNode->next;
  }
  else {
    prevNode->next = currNode->next;
  }

  delete currNode;
  size--;
  return *this;
}

/*
Function: getSize()
Purpose: Gets size of the linked list
input:none
output:size of list
return: none
*/
template <class T>
int LinkedList<T>::getSize() const {
  Node<T> *currNode = head;
  int size = 0;

  while (currNode != 0) {
    currNode = currNode->next;
    size++;
  }
  
  return size;
}

/*
Function: [] operator
Purpose:takes an integer subscript as a parameter and returns 
a pointer to the Customer object at that position in the list.
input: x
output:none
return: none
*/
template <class T>
T* LinkedList<T>::operator[](int i) {
    if(i < 0 || i > (getSize()-1)) {
        return 0;
    } else {

        Node<T> *currNode = head;

        for (int j = 0; j < i; j++) {
            currNode = currNode->next;
        }

        return currNode->data;
    }
}


/*
Function: << operator
Purpose:prints the contents of the LinkedList
input/output:none
return: list
*/
template <class V>
std::ostream& operator<<(std::ostream& output, LinkedList<V>& cl)
{
  
  for (int i = 0; i < cl.getSize(); i++)  {
    output << (*(cl[i]));
  }
    
  return output;

}

#endif

