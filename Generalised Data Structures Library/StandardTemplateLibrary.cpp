
//Descreiption: Research oriented project 


#include<iostream>

using namespace std;

template<typename T>
struct node
{
	T data;
	struct node *next;
};

template<typename T>
struct Dnode
{
    T data;
    struct Dnode *next;
    struct Dnode *prev;
};
///////////////////////////////// Singly Linked List /////////////////////////////////////////////
template<class T>
class SinglyLL
{
private:
	node<T>* first;
	int size;
	
public:
    SinglyLL();
    void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Count();
};
///////////////////////////////// Doubly Linear Linked List /////////////////////////////////////////////////

template <class T>
class DoublyLinearLL
{
private:
    int size;
    Dnode <T>* first;

public:
    DoublyLinearLL();
    void Display();
    int Count();
    void InsertFirst(T);
    void InsertLast(T);
    void InsertAtPos(T, int);
    void DeleteFirst();
    void DeleteLast();
    void DeleteAtPos(int);
};
//////////////////////////////////// Singly Circular List /////////////////////////////////////////////

template<class T>
class SinglyCL
{
private:
    node<T>* first;
	node<T>* last;
	int size;
	
public:
    SinglyCL();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
	void Display();
	int Count();
    
};

///////////////////////////////// Doubly Circular List ////////////////////////////////////////////////

template<class T>
class DoublyCL
{
private:
	Dnode<T>* first;
	Dnode<T>* last;
	int size;
	
public:

    DoublyCL();
	void Display();
	int Count();
	void InsertFirst(T);
	void InsertLast(T);
	void InsertAtPos(T,int);
	void DeleteFirst();
	void DeleteLast();
	void DeleteAtPos(int);
};
/////////////////////////////////// Stack //////////////////////////////////////////////

template<class T>
class Stack     // Singly Linear Linked List
{
private:
    node<T>* first;
    int size;
    
public:
    Stack();
	void push(T);
	int pop();
	void Display();
	int Count();
};

/////////////////////////////////// Queue ///////////////////////////////////////////////

template<class T>
class Queue     // Singly Linear Linked List
{
private:
    node<T>* first;
    int size;
    
public:
    Queue();
	void Enqueue(T);
	int Dequeue();
	void Display();
	int Count();
};

/////////////////////////////////////////////////////////////////////////////////////

///////////////////////////////////////// CLASS DEFINATION //////////////////////////

/////////////////////////////// Singly Linked List ////////////////////////////////

template<class T>
SinglyLL<T> :: SinglyLL() // Constructor
	{
		first=NULL;
		size=0;
	}
	
	template<class T>
	void SinglyLL<T> :: InsertFirst(T no)
	{
		node<T>* newn=new node<T>;  // Memory allocation in CPP
		
		newn->data=no;
		newn->next=NULL;
		
		if(first == NULL)
		{
			first = newn;
		}
		else
		{
			newn->next=first;
			first = newn;
		}
		size++;
	}
	
	template<class T>
	void SinglyLL<T> :: InsertLast(T no)
	{
		node<T>* newn=new node<T>;		// Memory allocation in CPP
		node<T>* temp=first;

		newn->data=no;
		newn->next=NULL;
		
		if(first == NULL)
		{
			first = newn;
		}
		else
		{
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next=newn;
		}
		size++;
	}
	
	template<class T>
	void SinglyLL<T> :: InsertAtPos(T no, int ipos)
	{
		if((ipos < 1) || (ipos > size+1)) //Filter
		{
			cout<<"Tnvalid Position...!"<<"\n";
			return;
		}
		
		if(ipos == 1) //Insert First
		{
			InsertFirst(ipos);
		}
		else if(ipos == size+1)  //Insert Last
		{
			InsertLast(ipos);
		}
		else                    // Insert in Between
		{
			node<T>* newn = new node<T>;
			node<T>* temp=first;
			
			newn->data=no;
			newn->next=NULL;
			
			for(int i=1; i < ipos-1; i++)
			{
				temp=temp->next;
			}
			newn->next=temp->next;
			temp->next=newn;
		}
		size++;
	}
	
	template<class T>
	void SinglyLL<T> :: DeleteFirst()
	{
		node<T>* temp = first;
		if(first != NULL)
		{
			first= first->next;
			delete temp;
		}
		size--;
	}
	
	template<class T>
	void SinglyLL<T> :: DeleteLast()
	{
		node<T>* temp = first;
		
		if(first == NULL)
		{
			return;
		}
		else if(first->next == NULL)
		{
			delete first;
			first=NULL;
			size--;
		}
		else
		{
			while(temp->next->next != NULL)
			{
				temp=temp->next;
			}
			delete temp->next;
			temp->next=NULL;
			size--;
		}
	}
	
	template<class T>
	void SinglyLL<T> :: DeleteAtPos(int ipos)
	{
		if((ipos < 1) || (ipos > size))  //Filter
		{
			cout<<"Invalid Position...!";
			return;
		}
		
		if(ipos == 1)
		{
			DeleteFirst();
		}
		else if(ipos == size)
		{
			DeleteLast();
		}
		else
		{
			node<T>* temp=first;
			
			for(int i=1; i < ipos-1; i++)
			{
				temp=temp->next;
			}
			
            node<T>* targeted=temp->next;
			
			temp->next=targeted->next;
			delete targeted;
			size--;
		}
	}
	
	template<class T>
	void SinglyLL<T> :: Display()
	{
		node<T>* temp = first;
		
		while(temp != NULL)
		{
			cout<<"|"<<temp->data<<"|->";
			temp= temp->next;
		}
		cout<<"NULL\n";
	}
	
	template<class T>
	int SinglyLL<T> :: Count()
	{
		return size;
	}

/////////////////////////////// Doubly Linear Linked List ////////////////////////////////

template <class T>
DoublyLinearLL<T>::DoublyLinearLL()
{
    size = 0;
    first = NULL;
}

template <class T>
void DoublyLinearLL<T>::Display()
{
    Dnode <T>* temp = first;
    while (temp != NULL)
    {
        cout << "|" << temp->data << "| -> ";
        temp = temp->next;
    }
    cout << "NULL\n";
}

template <class T>
int DoublyLinearLL<T>::Count()
{
    return size;
}

template <class T>
void DoublyLinearLL<T>::InsertFirst(T no)
{
    Dnode<T>* newn = new Dnode<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        newn->next->prev = newn;
        first = newn;
    }
    size++;
}

template <class T>
void DoublyLinearLL<T>::InsertLast(T no)
{
    Dnode<T>* temp = first;
    Dnode<T>* newn = new Dnode<T>;
    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if (first == NULL)
    {
        first = newn;
    }
    else
    {
        while (temp->next != NULL)
        {
            temp = temp->next;
        }
        temp->next = newn;
        newn->prev = temp;
    }
    size++;
}

template <class T>
void DoublyLinearLL<T>::InsertAtPos(T no, int ipos)
{
    Dnode<T>* temp = first;
    if ((ipos < 1) || (ipos > size + 1))
    {
        return;
    }

    if (ipos == 1)
    {
        InsertFirst(no);
    }
    else if (ipos == size + 1)
    {
        InsertLast(no);
    }
    else
    {
        Dnode<T>* newn = new Dnode<T>;
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for (int i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }
        newn->next = temp->next;
        newn->next->prev = newn;
        temp->next = newn;
        newn->prev = temp;
        size++;
    }
}

template <class T>
void DoublyLinearLL<T>::DeleteFirst()
{
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        first = first->next;
        delete first->prev;
        first->prev = NULL;
    }
    size--;
}

template <class T>
void DoublyLinearLL<T>::DeleteLast()
{
    Dnode<T>* temp = first;
    if (first == NULL)
    {
        return;
    }
    else if (first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        while (temp->next->next != NULL)
        {
            temp = temp->next;
        }
        delete temp->next;
        temp->next = NULL;
    }
    size--;
}

template <class T>
void DoublyLinearLL<T>::DeleteAtPos(int ipos)
{
    Dnode<T>* temp = first;
    if ((ipos < 1) || (ipos > size))
    {
        return;
    }

    if (ipos == 1)
    {
        DeleteFirst();
    }
    else if (ipos == size)
    {
        DeleteLast();
    }
    else
    {
        for (int i = 1; i < ipos - 1; i++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;
        temp->next->prev = temp;
        size--;
    }
}

/////////////////////////////// Singly Circular List ////////////////////////////////

template<class T>
    SinglyCL<T> :: SinglyCL()
	{
		first=NULL;
		last=NULL;
		size=0;
	}
	
	template<class T>
	void SinglyCL<T> :: InsertFirst(T no)
	{
		node<T>* newn = new node<T>;
		
		newn->data=no;
		newn->next=NULL;
		
		if((first == NULL) && (last == NULL))
		{
			first = newn;
			last = newn;
		}
		else
		{
			newn->next=first;
			first=newn;
		}
		last->next=first;
		size++;
	}
	
	template<class T>
	void SinglyCL<T> :: InsertLast(T no)
	{
		node<T>* newn = new node<T>;
		
		newn->data=no;
		newn->next=NULL;
		
		if((first == NULL) && (last == NULL))
		{
			first = newn;
			last = newn;
		}
		else
		{
			last->next=newn;
		    last=newn;
		}
		last->next=first;
		size++;
	}
	
	template<class T>
	void SinglyCL<T> :: InsertAtPos(T no, int ipos)
	{
		if((ipos < 1) || (ipos > (size+1)))
		{
			return;
		}
		if(ipos == 0)
		{
			InsertFirst(no);
		}
		if(ipos == size+1)
		{
			InsertLast(no);
		}
		else
		{
            node<T>* newn = new node<T>;
            
			newn->data=no;
			newn->next=NULL;
			
			node<T>* temp=first;
			
			for(int i=1; i < ipos-1; i++)
			{
				temp=temp->next;
			}
			
			newn->next=temp->next;
			temp->next=newn;
			
			size++;
		}
	}
	
	template<class T>
	void SinglyCL<T> :: DeleteFirst()
	{
		if(size == 0)
		{
			return;
		}
		else if(first == last)
		{
			delete first;
			first = NULL;
			last = NULL;
		}
		else
		{
			first=first->next;
			delete last->next;
			last->next=first;
		}
		size--;
	}
	
	template<class T>
	void SinglyCL<T> :: DeleteLast()
	{
		node<T>* temp=first;
		
		if(size == 0)
		{
			return;
		}
		else if(first == last)
		{
			delete first;
			first = NULL;
			last = NULL;
		}
		else
		{
			while(temp->next != last)
			{
				temp=temp->next;
			}
			delete last;
			last=temp;
			last->next=first;
		}
		size--;
	}
	
	template<class T>
	void SinglyCL<T> :: DeleteAtPos(int ipos)
	{
		if((ipos < 1) || (ipos > size))
		{
			return;
		}
		
		if(ipos == 1)
		{
			DeleteFirst();
		}
		else if(ipos == size)
	    {
			DeleteLast();
		}
		else
		{
			node<T>* temp=first;
			
			for(int i=1; i < ipos-1; i++)
			{
				temp=temp->next;
			}
			
			node<T>* targeted = temp->next;
			
			temp->next=targeted->next;
			delete targeted;
			
			size--;
		}
	}
	
	template<class T>
	void SinglyCL<T> :: Display()
	{
		node<T>* temp=first;
		
		if((first == NULL) && (last == NULL))
		{
			return;
		}
		
		do
		{
			cout<<"|"<<temp->data<<"| ->";
			temp=temp->next;
		}while(temp != last->next);
		
		cout<<"NULL"<<"\n";
	}
	
	template<class T>
	int SinglyCL<T> :: Count()
	{
		
		return size;
	}

/////////////////////////////// Doubly Circular List ////////////////////////////////

template<class T>
 DoublyCL<T> :: DoublyCL()
	{
		first = NULL;
		last = NULL;
		size = 0;
	}

template<class T>
void DoublyCL<T> :: InsertFirst(T no)
{
	Dnode<T>* newn = new Dnode<T>;
	
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
	if((first == NULL) && (last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		newn->next=first;
		first->prev=newn;
		first=newn;
	}
	last->next=first;
	first->prev=last;
	size++;
}

template<class T>
void DoublyCL<T> :: InsertLast(T no)
{
	Dnode<T>* newn = new Dnode<T>;
	
	newn->data=no;
	newn->next=NULL;
	newn->prev=NULL;
	
	if((first == NULL) && (last == NULL))
	{
		first = newn;
		last = newn;
	}
	else
	{
		last->next=newn;
		newn->prev=last;
		last=newn;
	}
	last->next=first;
	first->prev=last;
	size++;
}

template<class T>
void DoublyCL<T> :: Display()
{
	Dnode<T>* temp=first;
	
	for(int i=1; i <= size; i++)
	{
		cout<<"|"<<temp->data<<"|-> ";
		temp=temp->next;
	}
	cout<<"NULL"<<"\n";
}

template<class T>
int DoublyCL<T> :: Count()
{
	return size;
}

template<class T>
void DoublyCL<T> :: DeleteFirst()
{
	if((first == NULL) && (last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
		
		return;
	}
	else
	{
		first=first->next;
		delete last->next;
		
		first->prev=last;
	    last->next=first;
	}
	size--;
}

template<class T>
void DoublyCL<T> :: DeleteLast()
{
	if((first == NULL) && (last == NULL))
	{
		return;
	}
	else if(first == last)
	{
		delete first;
		first = NULL;
		last = NULL;
		
		return;
	}
	else
	{
		last=last->prev;
		delete last->next;
		
		first->prev=last;
	    last->next=first;
	}
	size--;
}

template<class T>
void DoublyCL<T> :: InsertAtPos(T no, int ipos)
{
	if((ipos < 1) || (ipos > size+1))
	{
		return;
	}
	
	if(ipos == 1)
	{
		InsertFirst(no);
	}
	else if(ipos == size)
	{
		InsertLast(no);
	}
	else
	{
		Dnode<T>* newn = new Dnode<T>;
		
		newn->data=no;
		newn->next=NULL;
		newn->prev=NULL;
		
		Dnode<T>* temp =first;
		
		for(int i=1; i < ipos-1; i++)
		{
			temp=temp->next;
		}
		
		newn->next=temp->next;
		temp->next->prev=newn;
		newn->prev=temp;
		temp->next=newn;
		
		size++;
	}
}

template<class T>
void DoublyCL<T> :: DeleteAtPos(int ipos)
{
	if((ipos < 1) || (ipos > size))
	{
		return;
	}
	
	if(ipos == 1)
	{
		DeleteFirst();
	}
	else if(ipos == size)
	{
		DeleteLast();
	}
	else
	{
		Dnode<T>* temp = first;
		
		for(int i=1; i < ipos-1; i++)
		{
			temp=temp->next;
		}
		
		temp->next=temp->next->next;
		delete temp->next->prev;
		temp->next->prev=temp;
		
		size--;
	}
}

////////////////////////////////  Stack  //////////////////////////////////////////////

template<class T>
Stack<T> :: Stack()
    {
        first = NULL;
        size = 0;
    }
    
	template<class T>
    void Stack<T> :: push(T no)   // InsertFirst()
    {
        node<T>* newn = new node<T>;
		node<T>* temp=first;
		
		newn->data=no;
		newn->next=NULL;
		
		if(first == NULL)
		{
			first = newn;
		}
		else
		{
			newn->next=first;
			first=newn;
		}
		size++;
    }
    
	template<class T>
    int Stack<T> :: pop()   // DeleteFirst()
    {
       node<T>* temp=first;
		T iValue=0;
		if(temp == NULL)
		{
			cout<<"Stack is empty..!"<<endl;
			return -1;
		}
		
		if(size == 1)
		{
			iValue=temp->data;
			delete temp;
			first=NULL;
		}
		else
		{
			first=temp->next;
			iValue=temp->data;
			delete temp;
		}
		size--;
		return iValue;
    }
    
	template<class T>
    void Stack<T> :: Display()
    {
		node<T>* temp=first;
		
		for(int i=1; i <= size; i++)
		{
			cout<<"|"<<temp->data<<"| "<<"\n";
			temp=temp->next;
		}
		cout<<"\n";
	}
    
	template<class T>
    int Stack<T> :: Count()
    {
        return size;
    }
////////////////////////////////  Queue  //////////////////////////////////////////////

template<class T>
Queue<T> :: Queue()
    {
        first = NULL;
        size = 0;
    }
    
	template<class T>
    void Queue<T> :: Enqueue(T no)   // InsertLast()
    {
       node<T>* newn=new node<T>;		
	   node<T>* temp=first;

		newn->data=no;
		newn->next=NULL;
		
		if(first == NULL)
		{
			first = newn;
		}
		else
		{
			while(temp->next != NULL)
			{
				temp = temp->next;
			}
			temp->next=newn;
		}
		size++;
    }
    
	template<class T>
    int Queue<T> :: Dequeue()   // DeleteFirst()
    {
        node<T>* temp=first;
		T iValue=0;
		if(temp == NULL)
		{
			cout<<"Queue is empty..!"<<endl;
			return -1;
		}
		
		if(size == 1)
		{
			iValue=temp->data;
			delete temp;
			first=NULL;
		}
		else
		{
			first=temp->next;
			iValue=temp->data;
			delete temp;
		}
		size--;
		return iValue;
    }
    
	template<class T>
    void Queue<T> :: Display()
    {
		node<T>* temp=first;
		
		for(int i=1; i <= size; i++)
		{
			cout<<"|"<<temp->data<<"|-> ";
			temp=temp->next;
		}
		cout<<"NULL"<<"\n";
	}
    
	template<class T>
    int Queue<T> :: Count()
    {
        return size;
    }

//////////////////////////////////////// END DEFINATION //////////////////////////////


////////////////////////////////////////// MAIN FUNCTION /////////////////////////////
int main()
{
	int iDCLRet=0;
	
   	DoublyCL<int> DCLobj;
	
	DCLobj.InsertFirst(21);
	DCLobj.InsertFirst(11);
	
	DCLobj.InsertLast(51);
	DCLobj.InsertLast(101);
	
	DCLobj.InsertAtPos(75,3);
	
	DCLobj.Display();
	
    iDCLRet=DCLobj.Count();
	cout<<"Number of elements:"<<iDCLRet<<"\n";
	
	DCLobj.DeleteAtPos(3);
	
	DCLobj.DeleteFirst();
	DCLobj.DeleteLast();

	DCLobj.Display();
	
    iDCLRet=DCLobj.Count();
	cout<<"Number of elements:"<<iDCLRet<<"\n\n";
	
///////////////////////////////////////////////////////////////////////////////////////

int iSLLRet=0;
	
   	SinglyLL<int> SLLobj;
	
	SLLobj.InsertFirst(21);
	SLLobj.InsertFirst(11);
	
	SLLobj.InsertLast(51);
	SLLobj.InsertLast(101);
	
	SLLobj.InsertAtPos(75,3);
	
	SLLobj.Display();
	
    iSLLRet=SLLobj.Count();
	cout<<"Number of elements:"<<iSLLRet<<"\n";
	
	SLLobj.DeleteAtPos(3);
	
	SLLobj.DeleteFirst();
	SLLobj.DeleteLast();

	SLLobj.Display();
	
    iSLLRet=SLLobj.Count();
	cout<<"Number of elements:"<<iSLLRet<<"\n\n";

//////////////////////////////////////////////////////////////////////////////////////////

SinglyCL<int> SCLobj;
	int iSClRet=0;
	
	SCLobj.InsertFirst(51);
	SCLobj.InsertFirst(21);
	SCLobj.InsertFirst(11);
	
	SCLobj.InsertLast(101);
	
	SCLobj.InsertAtPos(55,4);
	
	SCLobj.Display();
	
	iSClRet=SCLobj.Count();
	cout<<"Number of elements are:"<<iSClRet<<"\n";
	
	SCLobj.DeleteAtPos(4);
	
	SCLobj.DeleteFirst();
	SCLobj.DeleteLast();
	
	SCLobj.Display();
	
	iSClRet=SCLobj.Count();
	cout<<"Number of elements are:"<<iSClRet<<"\n\n";

/////////////////////////////////////////////////////////////////////////////////////////////

DoublyLinearLL<int> DLLobj;
	int iDLLRet=0;
	
	DLLobj.InsertFirst(51);
	DLLobj.InsertFirst(21);
	DLLobj.InsertFirst(11);
	
	DLLobj.InsertLast(101);
	
	DLLobj.InsertAtPos(55,4);
	
	DLLobj.Display();
	
	iDLLRet=DLLobj.Count();
	cout<<"Number of elements are:"<<iDLLRet<<"\n";
	
	DLLobj.DeleteAtPos(4);
	
	DLLobj.DeleteFirst();
	DLLobj.DeleteLast();
	
	DLLobj.Display();
	
	iDLLRet=DLLobj.Count();
	cout<<"Number of elements are:"<<iDLLRet<<"\n\n";

///////////////////////////////////////////////////////////////////////////////////////////////
 Stack<int> Sobj;
	int iStackret=0;
    
    Sobj.push(11);
    Sobj.push(21);
    Sobj.push(51);
    Sobj.push(101);
    
	cout<<"Elements of Stack :"<<"\n";
    Sobj.Display();
	iStackret=Sobj.Count();
	cout<<"Size of Stack is: "<<iStackret<<"\n\n";
    
    iStackret = Sobj.pop();       
    cout<<"Poped Element: "<<"|"<<iStackret<<"|"<<"\n\n";                    
    
    cout<<"Elements of Stack :"<<"\n";
	Sobj.Display();          
    iStackret = Sobj.Count();     
    
    cout<<"Size of Stack is : "<<iStackret<<"\n\n"; 

/////////////////////////////////////////////////////////////////////////////////////////

Queue<int> Qobj;
	int iQueueRet=0;
    
    Qobj.Enqueue(11);
    Qobj.Enqueue(21);
    Qobj.Enqueue(51);
    Qobj.Enqueue(101);
	
	Qobj.Display();
	iQueueRet=Qobj.Count();
	cout<<"Size of queue is: "<<iQueueRet<<"\n\n";
    
    iQueueRet = Qobj.Dequeue();       
    cout<<"Removed Element: "<<"|"<<iQueueRet<<"|"<<"\n\n";                     
    
    Qobj.Display();          
    iQueueRet = Qobj.Count();     
    
    cout<<"Size of queue is : "<<iQueueRet<<"\n"; 	
    
	
	return 0;
}
