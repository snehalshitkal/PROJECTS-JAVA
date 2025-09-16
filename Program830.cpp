/////////////////////////////////////////////////////////////////////////////////////
//
//      Project Name : Generalized Data Structure Library
//      Author       : Snehal Rohit Shitkal
//      Description  : In this project combined functions of Data Structure.
//
/////////////////////////////////////////////////////////////////////////////////////


#include<iostream>
using namespace std;

////////////////////////////////////////////////////////////////////////////////////
//
//  Class:          QueueX
//  Description:    Generic Implementation of Queue
//  Author:         snehal shitkal
//
/////////////////////////////////////////////////////////////////////////////////////

template<class T>
struct Queuenode
{
    T data;
    struct Queuenode<T> *next;
};

template<class T>
class QueueX
{
    private:
        struct Queuenode<T> *first;
        int iCount;

    public:
        QueueX();
        void Enqueue(T);
        int Dequeue();
        void Display();
        int Count();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	QueueX  
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   NONE
//	Description:            :   This is constructor of class Singly_linkedList
//	Returns					:    NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
QueueX<T> :: QueueX()
{
    first = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Enqueue  
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no Holds the Entry which is to be added.
//	Description:            :   This is Insert last of  Element
//	Returns					:    NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void QueueX<T>:: Enqueue(T no)           //InsertLast
{
    struct Queuenode<T>* temp = NULL;
    struct Queuenode<T>* newn = NULL;

    newn = new struct Queuenode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
    }

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Dequeue  
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   NONE
//	Description:            :   This is Delete First of  Element
//	Returns					:   NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int QueueX<T> :: Dequeue()         //DeleteFirst
{
    struct Queuenode<T> * temp = NULL;
    T iValue = 0;

    if(first == NULL)
    {
        cout<<"Unable to pop element Queue empty:"<<"\n";
        return -1;
    }
    else
    {
        temp = first;

        iValue = first->data;

        first = first->next;

        delete temp;
        iCount--;

        return iValue;

    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display  
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   NONE
//	Description:            :   This function displays elements in queue
//	Returns					:    None
//
///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void QueueX<T> :: Display()
{
    struct Queuenode<T>* temp = NULL;
    temp = first;

    while(temp != NULL)
    {
        cout<<" "<<temp->data<<"-";
        temp = temp->next;
    }
    cout<<"\n";
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count  
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   NONE
//	Description:            :   This function count the elements
//	Returns					:   return number of elements
//
///////////////////////////////////////////////////////////////////////////////////////////


template<class T>
int QueueX<T>:: Count()
{
    return iCount;
} 


////////////////////////////////////////////////////////////////////////////////
//
//  Class:          StackX
//  Description:    Generic Implementation of Stack
//  Author:         snehal shitkal
//
////////////////////////////////////////////////////////////////////////////////


template<class T>
struct Stacknode
{
    T data;
    struct Stacknode<T> *next;

};

template<class T>
class StackX
{
    private:
        struct Stacknode<T> *first;
        int iCount;

    public:
        StackX();
        void Push(T);
        T Pop();
        void Display();
        int Count();
};


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	StackX  
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   NONE
//	Description:            :   This is constructor of class StackX
//	Returns					:   NONE
//
///////////////////////////////////////////////////////////////////////////////////////////

template<class T>
StackX<T>:: StackX()
{
    first = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Push  
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no hold the element that we insert.
//	Description:            :   This function insert the elements in first in stack
//	Returns					:   NONE
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void StackX<T>::Push(T no)           //InsertFirst
{
    struct Stacknode<T>* newn = NULL;

    newn = new Stacknode<T>;

    newn->data = no;
    newn->next = NULL;

    newn->next = first;
    first = newn;

    iCount++;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Pop  
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   NONE
//	Description:            :   This function Delete the elements of first in stack
//	Returns					:   Return the deleted element
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
T StackX<T>:: Pop()                             //Deletefirst
{
    struct Stacknode<T>* temp = NULL;
    T iValue = 0;

    if(first == NULL)
    {
        cout<<"Unable to pop element stack is empty:"<<"\n";
        return -1;
    }
    else
    {
        temp = first;
        iValue = first->data;

        first = first->next;
        delete temp;

        iCount--;
        return iValue;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display  
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   NONE
//	Description:            :   This function Display the stack
//	Returns					:   None
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void StackX<T>:: Display()
{
    struct Stacknode<T> *temp = NULL;

    temp = first;

    while(temp != NULL )
    {
        cout<<"|"<<temp->data<<"|"<<"\n";
        temp = temp->next;
    } 
    cout<<"\n";
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count  
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   NONE
//	Description:            :   This function Count the number of elements in stack
//	Returns					:   Return the total number of elements
//
/////////////////////////////////////////////////////////////////////////////////////////////
template<class T>
int StackX<T>::Count()
{
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Class:          SinglyCLL
//  Description:    Generic Implementation of SinglyCLL
//  Author:         snehal shitkal
//
//
////////////////////////////////////////////////////////////////////////////////

template<class T>
struct SinglyCLLnode
{
    T data;
    struct SinglyCLLnode<T> *next;
};


template<class T>
class SinglyCLL
{
    private:
        struct SinglyCLLnode<T> * first;
        struct SinglyCLLnode<T> * last;
        int iCount;

    public:
        SinglyCLL();
        void Display();
        int Count();

        void InsertFirst(T no);
        void InsertLast(T no);
        void InsertAtPos(T no ,int pos);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int pos);
       
};


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SinglyCLL  
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   NONE
//	Description:            :   This is Constructor of class SinglyCLL
//	Returns					:   None
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
SinglyCLL<T> :: SinglyCLL()
{
   
    this->first = NULL;
    this->last = NULL;
    this->iCount = 0;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertFirst  
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no Holds the entry which is to be added.
//	Description:            :   This function adds first node to Singly Circular Linked List.
//	Returns					:   None
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertFirst(T no)
{
    struct SinglyCLLnode<T> *newn = NULL;

    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if (first == NULL && last == NULL)
    {
        first = newn;
        last = newn;

        last->next = first;
    }
    else
    {
        newn->next = first;
        first = newn;

        last->next = first;
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertLast  
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no Holds the entry which is to be added.
//	Description:            :   This function adds last node to Singly Circular Linked List.
//	Returns					:   None
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertLast(T no)
{
    struct SinglyCLLnode<T> * newn = NULL;
    newn = new struct SinglyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last =newn;

        last->next = newn;
    }
    else
    {
        last->next = newn;
        last = newn;
        newn->next = first;
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display  
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None
//	Description:            :   This function Display all node to Singly Circular Linked List.
//	Returns					:   None
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: Display()
{
    struct SinglyCLLnode<T> * temp = NULL;
    temp = first;
    
    if(first == NULL && last == NULL)
    {
        cout<<"Node not Inserted:";
        return;
    }
    do
    {
        cout<<"| "<<temp->data<<" |->";
        temp = temp->next;

    }while(temp != last->next);
    cout<<"\n";
    
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count  
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None
//	Description:            :   This function Count all node to Singly Circular Linked List.
//	Returns					:   Return total number of nodes in SLL
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int SinglyCLL<T>:: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteFirst  
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None
//	Description:            :   This function Delete first node to Singly Circular Linked List.
//	Returns					:   None
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T>::DeleteFirst()
{
    if(first == NULL && last == NULL)
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
        first = first->next;
        delete last->next;
        last->next = first;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteLast 
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None
//	Description:            :   This function Delete Last node to Singly Circular Linked List.
//	Returns					:   None
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> ::DeleteLast()
{
    struct SinglyCLLnode<T>* temp = NULL;

    if(first == NULL && last == NULL)
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
       temp = first;

       while(temp->next != last)
       {
            temp = temp->next;
       }

       delete last;
       last = temp;

       last->next = first;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertAtPos 
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no Holds the node which is to be added.
//                              int pos Holds the position of added node 
//	Description:            :   This function Insert node to Singly Circular Linked List to specifific position.
//	Returns					:   None
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: InsertAtPos(T no,int pos)
{
    int icnt = 0;

    struct SinglyCLLnode<T> * newn = NULL;
    struct SinglyCLLnode<T> * temp = NULL;

    if(pos < 1 || pos > iCount+1)
    {
        cout<<"Invalid Position:"<<"\n";
        return;
    }
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        newn = new struct SinglyCLLnode<T>;

        newn->data = no;
        newn->next = NULL;

        temp = first;

        for(icnt = 1;icnt < pos - 1; icnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
    iCount++;

}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteAtPos 
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T pos Holds the position of node
//	Description:            :   This function delete node to given position in Singly Circular Linked List to specifific position.
//	Returns					:   None
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void SinglyCLL<T> :: DeleteAtPos(int pos)
{
    struct SinglyCLLnode<T> * temp = NULL;
    struct SinglyCLLnode<T> * target = NULL;
    int icnt = 0;
    if(pos<1 || pos >iCount)
    {
        cout<<"Invalid position:"<<"\n";
        return;
    }
    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;
        for(icnt = 1; icnt<pos - 1;icnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;
        delete target;
    }
    iCount--;
}


////////////////////////////////////////////////////////////////////////////////
//
//  Class:          DoublyCLL
//  Description:    Generic Implementation of DoublyCLL
//  Author:         snehal shitkal
//
////////////////////////////////////////////////////////////////////////////////


template<class T>
struct DoublyCLLnode
{
    T data;
    struct DoublyCLLnode<T> *next;
    struct DoublyCLLnode<T> *prev;
};


template<class T>
class DoublyCLL
{
    private:
        struct DoublyCLLnode<T> * first;
        struct DoublyCLLnode<T> * last;
        int iCount;
    public:
        DoublyCLL();
        void Display();
        int Count();

        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);

        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DoublyCLL 
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None
//	Description:            :   This constructor of Doubly Circular Linked List .
//	Returns					:   None
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
DoublyCLL<T> :: DoublyCLL()
{
  
    first = NULL;
    last = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertFirst 
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no which hold the element that we added
//	Description:            :   This function insert the node in first.
//	Returns					:   None
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertFirst(T no)
{
    struct DoublyCLLnode<T> * newn = NULL;

    newn = new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last == NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
       newn->next = first;
       first->prev = newn; 

       first = newn;
    }
    last->next = first;
    first->prev = last;

    iCount++;
} 

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertLast
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no which hold the element that we added
//	Description:            :   This function insert the node in Last of DoublyLL.
//	Returns					:   None
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertLast(T no)
{
    struct DoublyCLLnode<T> *newn = NULL;

    newn =  new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL && last==NULL)
    {
        first = newn;
        last = newn;
    }
    else
    {
        last->next = newn;
        newn->prev = last;

        last = newn;
    }

    last->next = first;
    first->prev = last;

    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None
//	Description:            :   This function Display the all nodes in DoublyLL.
//	Returns					:   None
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: Display()
{
    struct DoublyCLLnode<T> * temp = NULL;
    cout<<"Element of Linked List:"<<"\n";

    temp = first;

    if(first == NULL && last == NULL)
    {
        cout<<"Linked list Empty:";
        return;
    }
    do
    {
        cout<<" | "<<temp->data<<"|<=>";
        temp = temp->next;
    }while(temp != first);
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None
//	Description:            :   This function Count the all elements in DoublyLL.
//	Returns					:   Return total number of nodes.
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
int DoublyCLL<T> :: Count()
{
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteFirst
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None
//	Description:            :   This function Delete the first  node in DoublyLL.
//	Returns					:   None.
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteFirst()
{
    
    if(first == NULL && last == NULL)
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
        
        first = first->next;
        delete first->prev;

        last->next = first;
        first->prev = last;
    }
    iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteLast
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None
//	Description:            :   This function Delete the Last node in DoublyLL.
//	Returns					:   None.
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T>:: DeleteLast()
{
    if(first == NULL && last == NULL)
    {
        return;
    }
    else if(first == last)
    {
        delete last;
        first = NULL;
        last = NULL;
    }
    else
    {
        last = last->prev;
        delete last->next;

       
        last->next = first;
        first->prev = last;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertAtPos
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no holds the node that we added
//	Description:            :   This function Insert the  node  at given position in DoublyLL.
//	Returns					:   None.
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: InsertAtPos(T no,int pos)
{
    int icnt = 0;
    struct DoublyCLLnode<T> * newn = NULL;
    struct DoublyCLLnode<T> * temp =NULL;

    newn = new struct DoublyCLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    if(pos < 1 || pos > iCount + 1)
    {
        cout<<"Invalid position:"<<"\n";
        return;
    }
    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        temp = first;
        for(icnt = 1; icnt < pos -1; icnt++)
        {
            temp = temp->next;

        }
        newn->next = temp->next;
        temp->next->prev = newn;
        
        temp->next=newn;
        newn->prev=temp;   
    }
    iCount++;

}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteAtPos
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T pos holds the position of node 
//	Description:            :   This function Delete the  node  at given position in DoublyLL.
//	Returns					:   None.
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T>
void DoublyCLL<T> :: DeleteAtPos(int pos)
{
    struct DoublyCLLnode<T> * temp = NULL;
    int icnt = 0;
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position:"<<"\n";
        return;
    }
    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;
        for(icnt =1; icnt < pos - 1;icnt++)
        {
            temp = temp->next;
        }
        temp->next = temp->next->next;
        delete temp->next->prev;

        temp->next->prev = temp;
        
    }
    iCount--;
}


////////////////////////////////////////////////////////////////////////////////
//
//  Class:          SinglyLL
//  Description:    Generic Implementation of Singly Linera
//  Author:         snehal shitkal
//
////////////////////////////////////////////////////////////////////////////////

template<class T> 
struct SinglyLLnode
{
    T data;
    struct SinglyLLnode<T> *next;
};


template<class T> 
class SinglyLL
{
    private:
        struct SinglyLLnode<T>* first;
        int iCount;

    public:
        SinglyLL();
        void InsertFirst(T no);
        void InsertLast(T no);
        void Display();
        int Count();
        void DeleteFirst();
        void DeleteLast();
        void InsertAtPos(T no,int pos);
        void DeleteAtPos(int pos);
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SinglyLL
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None 
//	Description:            :   This constructor of class SinglyLL.
//	Returns					:   None.
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T> 
SinglyLL<T> :: SinglyLL()
{
    first = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertFirst
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no holds the node that we added 
//	Description:            :   This function insert first the element in SinglyLL.
//	Returns					:   None.
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T> 
void SinglyLL<T> :: InsertFirst(T no)
{
    struct SinglyLLnode<T>* newn = NULL;
    newn = new struct SinglyLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)               //Empty
    {
        first = newn;
    }
    else                            //multiple
    {
        newn->next = first;
        first = newn; 
    }
        iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertLast
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no holds the node that we added 
//	Description:            :   This function insert last the element in SinglyLL.
//	Returns					:   None.
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T> 
void SinglyLL<T> :: InsertLast(T no)
{
    struct SinglyLLnode<T>* newn = NULL;
    struct SinglyLLnode<T>* temp = NULL;

    newn = new struct SinglyLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;
        while(temp->next != NULL)
        {
                temp = temp->next;
        }

        newn->next = temp->next;
        temp->next = newn;
    }
        iCount++;  
    }

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None 
//	Description:            :   This function Display the nodes in SinglyLL.
//	Returns					:   None.
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T> 
void SinglyLL<T> :: Display()
{
    struct SinglyLLnode<T>* temp = NULL;
    temp = first;
    while(temp != NULL)
    {
        cout<<"| "<<temp->data<<"|->";
        temp = temp->next;
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None 
//	Description:            :   This function count the nodes in SinglyLL.
//	Returns					:   Return total nodes in SinglyLL.
//
/////////////////////////////////////////////////////////////////////////////////////////////

template<class T> 
int SinglyLL<T> :: Count()
{
    return iCount;
}
 

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteFirst
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None 
//	Description:            :   This function Delete first the node in SinglyLL.
//	Returns					:   None.
//
/////////////////////////////////////////////////////////////////////////////////////////////
 
template<class T> 
void SinglyLL<T> :: DeleteFirst()
{
    struct SinglyLLnode<T>* temp = NULL;

    if(first == NULL)           //empty
    {
        return;
    }
    else if(first->next == NULL)        //only 1 node
    {
        delete(first);
        first = NULL;
    }
    else                //multiple node 
    {
        temp = first;
        first = first->next;
        delete temp;
    }
        
    iCount--;  
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteLast
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None 
//	Description:            :   This function Delete Last the node in SinglyLL.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////

template<class T> 
void SinglyLL<T> :: DeleteLast()
{
    struct SinglyLLnode<T>* temp = NULL;
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
    }
    else
    {
        temp = first;

        while(temp->next->next != NULL)
        {
            temp = temp->next;
        }
            
        delete(temp->next);
        temp->next = NULL;
    }
        iCount--;
        
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertAtPos
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no Holds the added node. 
//                              int pos Holds the position of added node 
//	Description:            :   This function Insert the node at given position in SinglyLL.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////
 
template<class T>     
void SinglyLL<T> :: InsertAtPos(T no,int pos)
{
    struct SinglyLLnode<T>* temp = NULL;
    struct SinglyLLnode<T>* newn = NULL;

    if(pos<1 || pos>iCount+1)
    {
        cout<<"Invalid Position:\n";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
    newn = new struct SinglyLLnode<T>;

    newn->data = no;
    newn->next = NULL;

    struct SinglyLLnode<T>* temp = NULL;
    
    temp = first;
    int icnt = 0;
    for (icnt = 1; icnt<pos-2; icnt++)
    {
        temp = temp->next;
    }
        
    newn->next = temp->next;
    temp->next = newn;
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteAtPos
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no Holds the added node. 
//                              int pos Holds the position of deleted node 
//	Description:            :   This function Delete the node at given position in SinglyLL.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////
 
template<class T> 
void SinglyLL<T> :: DeleteAtPos(int pos)
{
    struct SinglyLLnode<T>* temp = NULL;
    struct SinglyLLnode<T>* target = NULL;

    int icnt = 0;
    if(pos < 1 || pos > iCount)
    {
        cout<<"Invalid Position:";
            
    }
    if(pos == 1)
    {
        DeleteFirst();
    }
    else if(pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;
        for(icnt = 1; icnt<pos-2; icnt++)
        {
            temp = temp->next;
        }
        target = temp->next;
        temp->next = target->next;

        delete(target);
    }
        iCount--;
        
}


////////////////////////////////////////////////////////////////////////////////
//
//  Class:          DoublyLL
//  Description:    Generic Implementation of Doubly Linear
//  Author:         snehal shitkal
////////////////////////////////////////////////////////////////////////////////

template <class T>
struct DoublyLLnode
{
    int data;
    struct DoublyLLnode<T> * next;
    struct DoublyLLnode<T> * prev;
};

template <class T>
class DoublyLL
{
    private:
        struct DoublyLLnode<T>* first;
        int iCount;

    public:
        DoublyLL();
        void InsertFirst(T);
        void InsertLast(T);
        void InsertAtPos(T,int);
        void DeleteFirst();
        void DeleteLast();
        void DeleteAtPos(int);
        void Display();
        int Count();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DoublyLL
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None. 
//	Description:            :   This Constructor of class DoublyLL.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////
 
template <class T>
DoublyLL<T> :: DoublyLL()
{
   
    first = NULL;
    iCount = 0;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertFirst
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no Holds the node that we added. 
//	Description:            :   This function insert the first node in DoublyLL.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////
 
   
template <class T>
void DoublyLL<T> :: InsertFirst(T no)
{
    struct DoublyLLnode<T> * newn = NULL;
    newn = new struct DoublyLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev = NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        newn->next = first;
        first->prev = newn;
        first = newn;
    }
        iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertLast
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no Holds the node that we added. 
//	Description:            :   This function insert the Last node in DoublyLL.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: InsertLast(T no)
{
    struct DoublyLLnode<T> * temp = NULL;
    struct DoublyLLnode<T> * newn = NULL;

    newn= new struct DoublyLLnode<T>;

    newn->data = no;
    newn->next = NULL;
    newn->prev= NULL;

    if(first == NULL)
    {
        first = newn;
    }
    else
    {
        temp = first;

        while(temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newn;
        newn->prev = temp;
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteFirst
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None. 
//	Description:            :   This function Delete the first node in DoublyLL.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: DeleteFirst()
{
    struct DoublyLLnode<T> * temp = NULL;
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        temp = first;
        first = first->next;
        delete temp;
    }
    iCount--;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteLast
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None. 
//	Description:            :   This function Delete the last node in DoublyLL.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: DeleteLast()
{
    struct DoublyLLnode<T> * temp = NULL;
       
    if(first == NULL)
    {
        return;
    }
    else if(first->next == NULL)
    {
        delete first;
        first = NULL;
    }
    else
    {
        temp = first;
        while(temp->next != NULL)
        {
            temp = temp->next;
        }
           temp->next->prev = NULL;
           delete temp;
            
    }
        iCount--;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None. 
//	Description:            :   This function Display the node in DoublyLL.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: Display()
{
    struct DoublyLLnode<T> * temp = NULL;

    temp = first;
    while(temp != NULL)
    {
        cout<<"<=| "<<temp->data<<" |=>";
        temp = temp->next;
    }
        cout<<" NULL=>"<<"\n";

}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None. 
//	Description:            :   This function count the total node in DoublyLL.
//	Returns					:   Return the total count.
//
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int DoublyLL<T> :: Count()
{
    return iCount;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertAtPos
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no Holds the node. 
//                              int pos Holds the position of added node 
//	Description:            :   This function count the total node in DoublyLL.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: InsertAtPos(T no,int pos)
{
    struct DoublyLLnode<T> * newn = NULL;
    struct DoublyLLnode<T> * temp = NULL;

    int icnt = 0;
        
    if(pos< 1 || pos>iCount+1)
    {
        cout<<"Invalid Position:";
        return;
    }

    if(pos == 1)
    {
        InsertFirst(no);
    }
    else if(pos == iCount+1)
    {
        InsertLast(no);
    }
    else
    {
        temp = first;
        newn = new struct DoublyLLnode<T>;
        
        newn->data = no;
        newn->next = NULL;
        newn->prev = NULL;

        for(icnt = 1; icnt < pos-1; icnt++)
        {
            temp = temp->next;
        }

        newn->next = temp->next;
        temp->next->prev = newn;

        temp->next = newn;
        newn->prev = temp;
    }
        iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	DeleteAtPos
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   int pos Holds the position of deleted node 
//	Description:            :   This function Delete the node at given position in DoublyLL.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void DoublyLL<T> :: DeleteAtPos(int pos)
{
    struct DoublyLLnode<T> * temp = NULL;
    struct DoublyLLnode<T> * target = NULL;

    int icnt = 0;

    if(pos<1 || pos>iCount)
    {
        cout<<"Invalid Position:";
        return;
    }

    if(pos == 1)
    {
        DeleteFirst();
    }

    else if (pos == iCount)
    {
        DeleteLast();
    }
    else
    {
        temp = first;
        for(icnt = 1; icnt<pos - 1;icnt++)
        {
                temp = temp->next;
        }
        
        target = temp->next;

        temp->next = target->next;
        target->next->prev = temp;
        delete target;

    }
        iCount--;
        
}

////////////////////////////////////////////////////////////////////////////////
//
//  Class:          BST
//  Description:    Generic Implementation of Binary search tree
//  Author:         snehal shitkal
////////////////////////////////////////////////////////////////////////////////

template <class T>
struct BSTnode
{
    int data;
    struct BSTnode<T> *lchild;
    struct BSTnode<T> *rchild;
};


template <class T>
class BST
{
    private:
        struct BSTnode<T> *first;
        int iCount;

        void InorderHelper(BSTnode<T>* first);
        void PreorderHelper(BSTnode<T>* first);
        void PostorderHelper(BSTnode<T>* first);
        
    public:
        BST();
        void Insert(T);
        void Inorder();
        void Preorder();
        void Postorder();
        bool search(T);
        int Count();
        int CountLeafNode();
        int CountParentNodes();
};

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BST
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None 
//	Description:            :   This is Constructor of class BST.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
BST<T> :: BST()
{
    cout<<"Inside constructor of SinglyCLL\n";

    first = NULL;
    iCount = 0;
}


////////////////////////////////////////////////////////////////////////////////////
template <class T>
void BST<T>::InorderHelper(BSTnode<T>* first)
{
    if (first == nullptr) 
    {
        return;
    }
    InorderHelper(first->lchild);
    cout << first->data << "\t";
    InorderHelper(first->rchild);
}

////////////////////////////////////////////////////////////////////////////////////

template <class T> 
void BST<T>:: PreorderHelper(BSTnode<T> *first)
 {
    if (first == nullptr) 
    {
        return;
    }
    
    cout << first->data << "\t";
    PreorderHelper(first->lchild);
    PreorderHelper(first->rchild);
}
////////////////////////////////////////////////////////////////////////////////////
 
template <class T>
void BST<T>:: PostorderHelper(BSTnode<T>* first)
 {
    if (first == nullptr) 
    {
        return;
    }
    
    PostorderHelper(first->lchild);
    PostorderHelper(first->rchild);
    cout<<first->data<< "\t";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Insert
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no Holds the element 
//	Description:            :   This function insert the element in BST.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void BST<T> :: Insert(T no)
{
    struct BSTnode<T> * newn = NULL;
    struct BSTnode<T> * temp = NULL;

    newn = new struct BSTnode<T>;

    newn->data = no;

    newn->lchild = NULL;
    newn->rchild = NULL;

    if(first == NULL)          
    {
        first = newn;
    }
    else                    
    {
        temp = first;
        while(1)
        {
            if(no == temp->data)
            {
                cout<<"Duplicate elements: unable to insert element"<<"\n";
                delete newn;
                break;
            }
            else if(no > temp->data)      //rchild
            {
                if(temp->rchild == NULL)
                {
                    temp->rchild = newn;
                    break;
                }
                temp = temp->rchild;
            }
            else if(no < temp->data)     //lchild
            {
                if(temp->lchild == NULL)
                {
                    temp->lchild = newn;
                    break;
                }
                temp = temp->lchild;
            }
        }
    }
    iCount++;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Inorder
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None 
//	Description:            :   This function Dissplay the element in BST.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void BST<T>::Inorder()
{
    InorderHelper(first);   // or "first" if you use that name
    cout << "\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Preorder
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None 
//	Description:            :   This function Display the node in BST.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void BST<T> :: Preorder()
{
       PreorderHelper(first);   
        cout << "\n";

    
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Postorder
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None 
//	Description:            :   This function Display the node in BST.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
void BST<T> :: Postorder()
{
   
        PostorderHelper(first);   
        cout << "\n";
 
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	search
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T  no Holds the node added. 
//	Description:            :   This function search the node in BST.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
bool BST<T> :: search(T no)
{
    bool bFlag = false;
    BSTnode<T>* temp = first;
    while(temp != NULL)
    {
        if(no == temp->data)
        {
            bFlag = true;
            break;
        }
        else if(no > temp->data)
        {
            temp = temp->rchild;
        }
        else if(no < temp->data)
        {
            temp = temp->lchild;
        }
    }
    return bFlag;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Count
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None. 
//	Description:            :   This function count the node in BST.
//	Returns					:   Return total nodes.
//
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int BST<T> :: Count()
{
    return iCount;
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	CountLeafNode
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None. 
//	Description:            :   This function count the total leaf node in BST.
//	Returns					:   Return total leaf node.
//
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int BST<T>:: CountLeafNode()
{
    static int iCount = 0;
    if(first != NULL)
    {
        if(first->lchild == NULL && first->rchild == NULL)
        {
            iCount++;
        }
        
        CountLeafNode(first->rchild);       
        CountLeafNode(first->lchild);
    }
    return iCount;
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	CountParentNode
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None. 
//	Description:            :   This function count the total Parent node in BST.
//	Returns					:   Return total parent node.
//
//////////////////////////////////////////////////////////////////////////////////////////

template <class T>
int BST<T> :: CountParentNodes()
{
    static int iCount = 0;
    if(first != NULL)
    {
        if(first->lchild != NULL || first->rchild != NULL)
        {
            iCount++;
        }

        CountParentNodes(first->rchild);       
        CountParentNodes(first->lchild);
    }
    return iCount;
}

////////////////////////////////////////////////////////////////////////////////
//
//  Class:          SortingArrayX
//  Description:    Generic Implementation of Sorting Algorithm
//  Author:         snehal shitkal
////////////////////////////////////////////////////////////////////////////////


template<class T>
class SortingArrayX          
{
    public:
        T *Arr;
        int iSize;
        bool sorted;

        SortingArrayX( T no)
        {
            iSize = no;
            Arr = new int[iSize];
            sorted = true;
        }

        ~SortingArrayX()
        {
            delete []Arr;
        }

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Accept
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None. 
//	Description:            :   This function Accept the elements.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////

       
    void Accept()
    {
        cout<<"Enter the elements : \n";
            
        int i = 0;              

        for(i = 0; i < iSize;i++)
        {
            cout<<"Enter Elements of the array: \n";
            cin>>Arr[i];

            if((i > 0) && (sorted == true))         
            {
                if(Arr[i]  < Arr[i - 1])
                {
                    sorted = false;
                }
            }
                
         }
    }

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None. 
//	Description:            :   This function Display the elements.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////

void Display()
{
    cout<<"Elements of the array are : \n";
            
    int i = 0;

    for(i = 0; i < iSize; i++)
    {
        cout<<Arr[i]<<"\t";
    }
    cout<<"\n";
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BubbleSort
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None. 
//	Description:            :   This function sorting the elements.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////

       
void BubbleSort()
{
    int i = 0, j = 0, temp = 0;

    if(sorted == true)              
    {
        return;
    }

    for(i = 0; i<iSize; i++)        
    {
        for(j = 0; j < iSize - 1; j++)        
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp; 
            }
        }

            cout<<"Data after pass:"<<i+1<<"\n";
            Display();
    }
}


///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BubbleSortEffiecient
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None. 
//	Description:            :   This function Display the elements.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////

void BubbleSortEffiecient()
{
    int i = 0, j = 0, temp = 0;

    bool bFlag = true;

    if(sorted == true)              
    {
        return;
    }

    for(i = 0; i < iSize && bFlag == true; i++)      
    {
        bFlag = false;

        for(j = 0; j < iSize - 1 - i; j++)        
        {
            if(Arr[j] > Arr[j + 1])
            {
                temp = Arr[j];
                Arr[j] = Arr[j + 1];
                Arr[j + 1] = temp; 

                bFlag = true;
            }
        }

        cout<<"Data after pass:"<<i+1<<"\n";
        Display();
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	SelectionSort
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None. 
//	Description:            :   This function use to selection sorting  the elements.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////
  
void SelectionSort()
{
    int i = 0, j = 0,min_index = 0, temp = 0;
 
    for(i = 0; i < iSize - 1; i++)
    {
        min_index = i;

        for(j = i+1; j < iSize; j++)
        {
            if(Arr[j] < Arr[min_index])
            { 
                min_index = j;
            }
        }

        if(i != min_index)
        {
            temp = Arr[i];

            Arr[i] = Arr[min_index];
                
            Arr[min_index] = temp;
        }
            
    }
}

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	InsertionSort
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None. 
//	Description:            :   This function use to Insertion sorting  the elements.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////
    
void InsertionSort()
{
    int i = 0,j = 0, selected = 0;

    for(i = 0;i<iSize;i++)
    {
        for(j = i-1,selected = Arr[i];(j >= 0)&&(Arr[j]>selected);j--)
        {
            Arr[j + 1] = Arr[j];
        }

        Arr[j + 1] = selected;
    }
}
};


////////////////////////////////////////////////////////////////////////////////
//
//  Class:          Searching
//  Description:    Generic Implementation of Sorting Algorithm
//  Author:         snehal shitkal
////////////////////////////////////////////////////////////////////////////////


template<class T>
class SearchingArrayX        
{
    public:
        T *Arr;
        int iSize;
        bool Sorted;

        SearchingArrayX(T no)
        {
            iSize = no;
            Arr = new int[iSize];
            Sorted = true;
        }

        ~SearchingArrayX()
        {
            delete []Arr;
        }

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Accept
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None. 
//	Description:            :   This function use to Accept tthe elements.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////
 
        void Accept()
        {
            cout<<"Enter "<<iSize<<" elements : \n";
            
            int i =0;                   // 11       

            for(i = 0; i < iSize;i++)
            {
                cout<<"Enter the element no : "<<i+1<<"\n";
                cin>>Arr[i];

                if((i > 0) && (Sorted == true))     // IMP
                {
                    if(Arr[i] < Arr[i-1])
                    {
                        Sorted = false;
                    }
                }
            }
        }

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	Display
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None. 
//	Description:            :   This function use to Display the elements.
//	Returns					:   None.
//
//////////////////////////////////////////////////////////////////////////////////////////
 
        void Display()
        {
            cout<<"Elements of the array are : \n";
            
            int i = 0;

            for(i = 0; i < iSize; i++)
            {
                cout<<Arr[i]<<"\t";
            }
            cout<<"\n";
        }

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	LinearSearch
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no Holds the search elemnts. 
//	Description:            :   This function use to LinearSearch the elements.
//	Returns					:   Return the Bool value.
//
//////////////////////////////////////////////////////////////////////////////////////////
 
        bool LinearSearch(T no)       
        {
            int i = 0;
            bool bFlag = false;

            if(Sorted == true)                  
            {
                cout<<"Data is sorted\n";

                return BinarySearchEfficientInc(no);
            }

            for(i = 0; i < iSize; i++)
            {
                if(Arr[i] == no)
                {
                    bFlag = true;
                    break;
                }
            }

            return bFlag;
        }

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BiDirectionalSearch
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no Holds the search elemnts. 
//	Description:            :   This function use to BiDirectionalSearch the elements.
//	Returns					:   Return the Bool value.
//
//////////////////////////////////////////////////////////////////////////////////////////
 
        bool BiDirectionalSearch(T no)    
        {
            int iStrat = 0;
            int iEnd = 0;

            bool bFlag = false;

            for(iStrat = 0, iEnd = iSize-1 ; iStrat <= iEnd; iStrat++, iEnd--)
            {
                if(Arr[iStrat] == no || Arr[iEnd] == no)
                {
                    bFlag = true;
                    break;
                }
            }

            return bFlag;
        }

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BinarySearchInc
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no Holds the search elemnts. 
//	Description:            :   This function use to BiDirectionalSearch the elements.
//	Returns					:   Return the Bool value.
//
//////////////////////////////////////////////////////////////////////////////////////////
 
        bool BinarySearchInc(T no)
        {
            int iStart = 0, iEnd = 0, iMid = 0;
            bool bFlag = false;

            iStart = 0;
            iEnd = iSize - 1;

            while(iStart <= iEnd)
            {
                iMid = iStart + ((iEnd - iStart) / 2);

                if(Arr[iMid] == no)
                {
                    bFlag = true;
                    break;
                }
                else if(no < Arr[iMid])     // First half (Left window)
                {
                    iEnd = iMid - 1;
                }
                else if(no > Arr[iMid])     // Second half (Right window)
                {
                    iStart = iMid + 1;
                }
            }   // End of while

            return bFlag;
        }

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BinarySearchDec
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no Holds the search elemnts. 
//	Description:            :   This function use to BinarySearchDec the elements.
//	Returns					:   Return the Bool value.
//
//////////////////////////////////////////////////////////////////////////////////////////
 
        bool BinarySearchDec(T no)
        {
            int iStart = 0, iEnd = 0, iMid = 0;
            bool bFlag = false;


            iStart = 0;
            iEnd = iSize - 1;

            while(iStart <= iEnd)
            {
                iMid = iStart + ((iEnd - iStart) / 2);

                if(Arr[iMid] == no)
                {
                    bFlag = true;
                    break;
                }
                else if(no > Arr[iMid])     
                {
                    iEnd = iMid - 1;
                }
                else if(no < Arr[iMid])    
                {
                    iStart = iMid + 1;
                }
            }   

            return bFlag;
        }

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BinarySearchEfficientInc
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no Holds the search elemnts. 
//	Description:            :   This function use to Binary Search Efficiently Increasing the elements.
//	Returns					:   Return the Bool value.
//
//////////////////////////////////////////////////////////////////////////////////////////
 
        bool BinarySearchEfficientInc(T no)
        {
            int iStart = 0, iEnd = 0, iMid = 0;
            bool bFlag = false;

            if(Sorted == false)       // New
            {
                cout<<"Data is not sorted\n";
                
                return LinearSearch(no);    // Important
            }

            iStart = 0;
            iEnd = iSize - 1;

            while(iStart <= iEnd)
            {
                iMid = iStart + ((iEnd - iStart) / 2);

                if((Arr[iMid] == no) || (Arr[iStart] == no) || (Arr[iEnd] == no))    //Change
                {
                    bFlag = true;
                    break;
                }
                else if(no < Arr[iMid])     
                {
                    iEnd = iMid - 1;
                }
                else if(no > Arr[iMid])     
                {
                    iStart = iMid + 1;
                }
            }   // End of while

            return bFlag;
        }

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	BinarySearchEfficientDec
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   T no Holds the search elemnts. 
//	Description:            :   This function use to Binary Search Efficiently Decreasing the elements.
//	Returns					:   Return the Bool value.
//
//////////////////////////////////////////////////////////////////////////////////////////
 

        bool BinarySearchEfficientDec(T no)
        {
            int iStart = 0, iEnd = 0, iMid = 0;
            bool bFlag = false;


            iStart = 0;
            iEnd = iSize - 1;

            while(iStart <= iEnd)
            {
                iMid = iStart + ((iEnd - iStart) / 2);

                if((Arr[iMid] == no) || (Arr[iStart] == no) || (Arr[iEnd] == no))    //Change
                {
                    bFlag = true;
                    break;
                }
                else if(no > Arr[iMid])     // First half (Left window)
                {
                    iEnd = iMid - 1;
                }
                else if(no < Arr[iMid])     // Second half (Right window)
                {
                    iStart = iMid + 1;
                }
            }   // End of while

            return bFlag;
        }

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	CheckSortedInc
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None. 
//	Description:            :   This function use to search increasing order sorted the elements.
//	Returns					:   Return the Bool value.
//
//////////////////////////////////////////////////////////////////////////////////////////
         

        bool CheckSortedInc()
        {
            bool bFlag = true;
            int i = 0;

            for(i = 0; i < iSize - 1; i++)
            {
                if(Arr[i] > Arr[i+1])   // Change kela ahe
                {
                    bFlag = false;
                    break;
                }
            }

            return bFlag;
        }

///////////////////////////////////////////////////////////////////////////////////////////
//
//	Function Name			:	CheckSortedDec
//	Function Date			:	15/9/2025
//	Function Author			:	snehal shitkal
//	Parameters:				:   None. 
//	Description:            :   This function use to search Decreasing order sorted the elements.
//	Returns					:   Return the Bool value.
//
//////////////////////////////////////////////////////////////////////////////////////////
          
        bool CheckSortedDec()
        {
            bool bFlag = true;
            int i = 0;

            for(i = 0; i < iSize - 1; i++)
            {
                if(Arr[i] < Arr[i+1])   // Change kela ahe
                {
                    bFlag = false;
                    break;
                }
            }

            return bFlag;
        }
};


////////////////////////////////////////////////////////////////////////////////
//   assignment 34,35,36 fun c++- generic-
//write all fun logic in all type LL


// prog 830 reffer code in drive
////////////////////////////////////////////////////////////////////////////////

int main()
{
    SinglyLL<int> slobj;
    DoublyLL<int> dlobj;
    SinglyCLL<int> scobj;
    DoublyCLL<int> dcobj;

    StackX<int>* stobj = new StackX<int>();
    QueueX<int>* quobj = new QueueX<int>();

    BST<int>* btobj = new BST<int>();
    
   
    int iRet = 0,iValue = 0,iChoice1 = 0,iChoice2 = 0,iPos = 0;
    bool bRet = true;
    
    while(1)
    {
    cout<<"------------------------------------------------------"<<"\n";
    cout<<"---------Generic Linked List Application---------------"<<"\n";
    cout<<"------------------------------------------"<<"\n";
    cout<<"1: Singly Linked List "<<"\n";
    cout<<"2: Doubly Linked List:"<<"\n";
    cout<<"3: Singly Circular Linked List "<<"\n";
    cout<<"4: Doubly Circular Linked List "<<"\n";
    cout<<"5: Stack Operations "<<"\n";
    cout<<"6: Queue Operation "<<"\n";
    cout<<"7: Binary Search Tree "<<"\n";
    cout<<"-------------==============-----------------------------"<<"\n";
    cin>>iChoice1;

    
     if(iChoice1 == 1)
     {
        while(true)
        {

            cout<<"------------------Singly Linked List------------------------"<<"\n";
            cout<<"1: Insert First node in Singly Linked List "<<"\n";
            cout<<"2: Insert Last node in Singly Linked List:"<<"\n";
            cout<<"3: Insert at Position  of Node "<<"\n";
            cout<<"4: Delete First node in Singly Linked List "<<"\n";
            cout<<"5: Delete Last node in Singly Linked List:"<<"\n";
            cout<<"6: Delete at Position  of Node "<<"\n";
            cout<<"7: Display All Nodes"<<"\n";
            cout<<"8: Count All Node in Singly Linked List"<<"\n";
            cout<<"--------------------Thank you----------------------"<<"\n";
            cin>>iChoice2;

            if(iChoice2 == 1)
            {
            cout<<"Enter the Node that you want to insert:"<<"\n";
            cin>>iValue;
            slobj.InsertFirst(iValue);
            }
            else if(iChoice2 == 2)
            {
            cout<<"Enter the Node that you want to insert:"<<"\n";
            cin>>iValue;
            slobj.InsertLast(iValue);
            }
            else if(iChoice2 == 3)
            { 
            cout<<"Enter the Node that you want to insert:"<<"\n";
            cin>>iValue;

            cout<<"Enter the position:"<<"\n";
            cin>>iPos;

            slobj.InsertAtPos(iValue,iPos);

            }

            else if(iChoice2 == 4)
            {
            cout<<"Deleting the first node in Linked List:"<<"\n";
            slobj.DeleteFirst();
            }
        
            else if(iChoice2 == 5)
            {
            cout<<"Deleting the Last node in Linked List:"<<"\n";
            slobj.DeleteLast();
            }

            else if(iChoice2 == 6)
            {
            cout<<"Enter the position that you want to delete node:"<<"\n";
            cin>>iPos;
            slobj.DeleteAtPos(iPos);
            }
            else if(iChoice2 == 7)
            {
            cout<<"Nodes of Linked List:"<<"\n";
            slobj.Display();
            }

            else if(iChoice2 == 8)
            {
            cout<<"Count All Nodes Nodes of Linked List:"<<"\n";
            iRet = slobj.Count();
            cout<<"Total numbers of node in Linked List:"<<iRet<<"\n";
            }
            else if(iChoice2 == 0 )
            {
            cout<<"Thank yoy for using Application:"<<"\n";
            break;
            }
            else
            {
            cout<<"Invalid Choice"<<"\n";
            }

        }
    }

    else if(iChoice1 == 2)
    {
         while(true)
        {
            cout<<"--------------------Doubly Linked List--------------------"<<"\n";
            cout<<"1: Insert First node in Doubly Linked List "<<"\n";
            cout<<"2: Insert Last node in Doubly Linked List:"<<"\n";
            cout<<"3: Insert at Position  of Node "<<"\n";
            cout<<"4: Delete First node in Doubly Linked List "<<"\n";
            cout<<"5: Delete Last node in Doubly Linked List:"<<"\n";
            cout<<"6: Delete at Position  of Node "<<"\n";
            cout<<"7: Display All Nodes"<<"\n";
            cout<<"8: Count All Node in Doubly Linked List"<<"\n";
            cout<<"------------------------------------------"<<"\n";
            cin>>iChoice2;

            if(iChoice2 == 1)
            {
            cout<<"Enter the Node that you want to insert:"<<"\n";
            cin>>iValue;
            dlobj.InsertFirst(iValue);
            }
            else if(iChoice2 == 2)
            {
            cout<<"Enter the Node that you want to insert:"<<"\n";
            cin>>iValue;
            dlobj.InsertLast(iValue);
            }
            else if(iChoice2 == 3)
            { 
            cout<<"Enter the Node that you want to insert:"<<"\n";
            cin>>iValue;

            cout<<"Enter the position:"<<"\n";
            cin>>iPos;

            dlobj.InsertAtPos(iValue,iPos);

            }

            else if(iChoice2 == 4)
            {
            cout<<"Deleting the first node in Doubly Linked List:"<<"\n";
            dlobj.DeleteFirst();
            }
        
            else if(iChoice2 == 5)
            {
            cout<<"Deleting the Last node in Doubly Linked List:"<<"\n";
            dlobj.DeleteLast();
            }

            else if(iChoice2 == 6)
            {
            cout<<"Enter the position that you want to delete node:"<<"\n";
            cin>>iPos;
            dlobj.DeleteAtPos(iPos);
            }
            else if(iChoice2 == 7)
            {
            cout<<"Nodes of Doubly Linked List:"<<"\n";
            dlobj.Display();
            }

            else if(iChoice2 == 8)
            {
            cout<<"Count All Nodes Nodes of Doubly Linked List:"<<"\n";
            iRet = dlobj.Count();
            cout<<"Total numbers of node in Doubly Linked List:"<<iRet<<"\n";
            }
            else if(iChoice2 == 0 )
            {
            cout<<"Thank yoy for using Application:"<<"\n";
            break;
            }
            else
            {
            cout<<"Invalid Choice"<<"\n";
            }

        }  
    }

    else if(iChoice1 == 3)
    {
         while(true)
        {
            cout<<"------------------Singly Circular Linked List------------------------"<<"\n";
            cout<<"1: Insert First node in Singly Circular Linked List "<<"\n";
            cout<<"2: Insert Last node in Singly Circular Linked List:"<<"\n";
            cout<<"3: Insert at Position  of Node "<<"\n";
            cout<<"4: Delete First node in Singly Circular Linked List "<<"\n";
            cout<<"5: Delete Last node in Singly Circular Linked Listt:"<<"\n";
            cout<<"6: Delete at Position  of Node "<<"\n";
            cout<<"7: Display All Nodes"<<"\n";
            cout<<"8: Count All Node in Singly Circular Linked List"<<"\n";
            cout<<"------------------------------------------"<<"\n";
            cin>>iChoice2;

            if(iChoice2 == 1)
            {
            cout<<"Enter the Node that you want to insert:"<<"\n";
            cin>>iValue;
            dlobj.InsertFirst(iValue);
            }
            else if(iChoice2 == 2)
            {
            cout<<"Enter the Node that you want to insert:"<<"\n";
            cin>>iValue;
            dlobj.InsertLast(iValue);
            }
            else if(iChoice2 == 3)
            { 
            cout<<"Enter the Node that you want to insert:"<<"\n";
            cin>>iValue;

            cout<<"Enter the position:"<<"\n";
            cin>>iPos;

            dlobj.InsertAtPos(iValue,iPos);

            }

            else if(iChoice2 == 4)
            {
            cout<<"Deleting the first node in Singly Circular Linked List:"<<"\n";
            dlobj.DeleteFirst();
            }
        
            else if(iChoice2 == 5)
            {
            cout<<"Deleting the Last node in Singly Circular Linked List:"<<"\n";
            dlobj.DeleteLast();
            }

            else if(iChoice2 == 6)
            {
            cout<<"Enter the position that you want to delete node:"<<"\n";
            cin>>iPos;
            dlobj.DeleteAtPos(iPos);
            }
            else if(iChoice2 == 7)
            {
            cout<<"Nodes of Singly Circular Linked List:"<<"\n";
            dlobj.Display();
            }

            else if(iChoice2 == 8)
            {
            cout<<"Count All Nodes Nodes of Singly Circular Linked List:"<<"\n";
            iRet = dlobj.Count();
            cout<<"Total numbers of node in Singly Circular Linked List:"<<iRet<<"\n";
            }
            else if(iChoice2 == 0 )
            {
            cout<<"Thank yoy for using Application:"<<"\n";
            break;
            }
            else
            {
            cout<<"Invalid Choice"<<"\n";
            }

        }  
    }

    else if(iChoice1 == 4)
    {
         while(true)
        {
            cout<<"------------------Doubly Circular Linked List------------------------"<<"\n";
            cout<<"1: Insert First node in Doubly Circular Linked List "<<"\n";
            cout<<"2: Insert Last node in Doubly Circular Linked List:"<<"\n";
            cout<<"3: Insert at Position  of Node "<<"\n";
            cout<<"4: Delete First node in Doubly Circular Linked List "<<"\n";
            cout<<"5: Delete Last node in Doubly Circular Linked Listt:"<<"\n";
            cout<<"6: Delete at Position  of Node "<<"\n";
            cout<<"7: Display All Nodes"<<"\n";
            cout<<"8: Count All Node in Doubly Circular Linked List"<<"\n";
            cout<<"------------------------------------------"<<"\n";
            cin>>iChoice2;

            if(iChoice2 == 1)
            {
            cout<<"Enter the Node that you want to insert:"<<"\n";
            cin>>iValue;
            dlobj.InsertFirst(iValue);
            }
            else if(iChoice2 == 2)
            {
            cout<<"Enter the Node that you want to insert:"<<"\n";
            cin>>iValue;
            dlobj.InsertLast(iValue);
            }
            else if(iChoice2 == 3)
            { 
            cout<<"Enter the Node that you want to insert:"<<"\n";
            cin>>iValue;

            cout<<"Enter the position:"<<"\n";
            cin>>iPos;

            dlobj.InsertAtPos(iValue,iPos);

            }

            else if(iChoice2 == 4)
            {
            cout<<"Deleting the first node in Doubly Circular Linked List:"<<"\n";
            dlobj.DeleteFirst();
            }
        
            else if(iChoice2 == 5)
            {
            cout<<"Deleting the Last node in Doubly Circular Linked List:"<<"\n";
            dlobj.DeleteLast();
            }

            else if(iChoice2 == 6)
            {
            cout<<"Enter the position that you want to delete node:"<<"\n";
            cin>>iPos;
            dlobj.DeleteAtPos(iPos);
            }
            else if(iChoice2 == 7)
            {
            cout<<"Nodes of Doubly Circular Linked List:"<<"\n";
            dlobj.Display();
            }

            else if(iChoice2 == 8)
            {
            cout<<"Count All Nodes Nodes of Doubly Circular Linked List:"<<"\n";
            iRet = dlobj.Count();
            cout<<"Total numbers of node in Doubly Circular Linked List:"<<iRet<<"\n";
            }
            else if(iChoice2 == 0 )
            {
            cout<<"Thank yoy for using Application:"<<"\n";
            break;
            }
            else
            {
            cout<<"Invalid Choice"<<"\n";
            }

        }  
    }

    else if(iChoice1 == 5)
    {
         while(true)
        {
            cout<<"------------------Stack Operations------------------------"<<"\n";
            cout<<"1: Push Elements in stack "<<"\n";
            cout<<"2: Pop out Elements:"<<"\n";
            cout<<"3: Display Stack elements "<<"\n";
            cout<<"4: Count all elements in stack "<<"\n";
            cout<<"------------------------------------------"<<"\n";
            cin>>iChoice2;

            if(iChoice2 == 1)
            {
            cout<<"Enter the elements that you want to insert:"<<"\n";
            cin>>iValue;
            stobj->Push(iValue);
            }
            else if(iChoice2 == 2)
            {
            cout<<"Poped out element in stack:"<<"\n";
            iRet = stobj->Pop();
            cout<<"Deleted element in stack:"<<iRet<<"\n";
            }
            else if(iChoice2 == 3)
            { 
            cout<<"Display elements in stack:"<<"\n";
            stobj->Display();

            }

            else if(iChoice2 == 4)
            {
            cout<<"Count of elements:"<<"\n";
            iRet =stobj->Count();
            cout<<"Total number of elements in stack:"<<"\n";
            }
            else if(iChoice2 == 0 )
            {
            cout<<"Thank yoy for using Application:"<<"\n";
            break;
            }
            else
            {
            cout<<"Invalid Choice"<<"\n";
            }

        }  
    }

    else if(iChoice1 == 6)
    {
         while(true)
        {
            cout<<"------------------Queue Operations------------------------"<<"\n";
            cout<<"1: Insert Elements in Queue "<<"\n";
            cout<<"2: Delete Elements in Queue:"<<"\n";
            cout<<"3: Display the Queue elements "<<"\n";
            cout<<"4: Count all elements in Queue "<<"\n";
            cout<<"------------------------------------------"<<"\n";
            cin>>iChoice2;

            if(iChoice2 == 1)
            {
            cout<<"Enter the elements that you want to insert:"<<"\n";
            cin>>iValue;
            quobj->Enqueue(iValue);
            }
            else if(iChoice2 == 2)
            {
            cout<<"Delete the element in Queue:"<<"\n";
            iRet = quobj->Dequeue();
            cout<<"Deleted element in Queue:"<<iRet<<"\n";
            }
            else if(iChoice2 == 3)
            { 
            cout<<"Display elements in Queue:"<<"\n";
            quobj->Display();
            }
            else if(iChoice2 == 4)
            {
            cout<<"Count of elements:"<<"\n";
            iRet =quobj->Count();
            cout<<"Total number of elements in stack:"<<"\n";
            }
            else if(iChoice2 == 0 )
            {
            cout<<"Thank yoy for using Application:"<<"\n";
            break;
            }
            else
            {
            cout<<"Invalid Choice"<<"\n";
            }

        }  
    }

      else if(iChoice1 == 7)
    {
         while(true)
        {
            cout<<"------------------Binary Search Tree Operations------------------------"<<"\n";
            cout<<"1: Insert Elements in BST "<<"\n";
            cout<<"2: Display Elements Inorder:"<<"\n";
            cout<<"3: Display Elements Preorder "<<"\n";
            cout<<"4: Display Elements Postorder "<<"\n";
            cout<<"5: Search Elements in BST "<<"\n";
            cout<<"6: Count Total Nodes "<<"\n";
            cout<<"------------------------------------------"<<"\n";
            cin>>iChoice2;

            if(iChoice2 == 1)
            {
            cout<<"Enter the Elements that you want to Insert:"<<"\n";
            cin>>iValue;
            btobj->Insert(iValue);
            }
            else if(iChoice2 == 2)
            {
            cout<<"Inorder Elements Display:"<<"\n";
            btobj->Inorder();
            
            }
            
            else if(iChoice2 == 3)
            { 
            cout<<"Preorder elements Display:"<<"\n";
            btobj->Preorder();
            }
            else if(iChoice2 == 4)
            {
            cout<<"Count of elements:"<<"\n";
            btobj->Postorder();
            }
            
            else if(iChoice2 == 5)
            {
            cout<<"Enter the Search elements:"<<"\n";
            cin>>iValue;
            bRet = btobj->search(iValue);

            if(bRet == true)
            {
                cout<<" Element are present:"<<"\n";
            }
            else
            {
                cout<<" Element are not present:"<<"\n";
            }
            }

            else if(iChoice2 == 6)
            {
           
            iRet = btobj->Count();
            cout<<"Total Nodes in BST:"<<iRet<<"\n";

            }
            else if(iChoice2 == 0 )
            {
            cout<<"Thank yoy for using Application:"<<"\n";
            break;
            }
            else
            {
            cout<<"Invalid Choice"<<"\n";
            }
            
        }  
    }
}
    return 0 ;
}