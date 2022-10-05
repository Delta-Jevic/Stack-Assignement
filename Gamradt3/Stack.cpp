/********************************************************************
*** NAME	    : Jevic Tshilumba                                 ***
*** CLASS	    : CSC 300                                         ***
*** ASSIGNMENT	: 3                                               ***
*** DUE DATE	: 10-05-2022                                      ***
*** INSTRUCTOR	: Ken Gamradt	                                  ***
*********************************************************************/

#include <iostream>
#include "Stack.h"

using namespace std;

Stack::Stack():top(nullptr)                                                 // default constructor function to create an initialized emplty stack
{

}

Stack::Stack(Stack & objects): top(nullptr)                                 // copy constructor function to create a duplicate
{
    SElement record;
    Stack recordStack;

    while(objects.top != NULL)
    {
        objects.pop(record);
    }
    recordStack.view();
    while (recordStack.top != NULL)
    {
       recordStack.pop(record);
       push(record);
    }
    
}

Stack::~Stack()                                                            // destructor function to remove all elements from the Stack
{
    SNodePtr nodePtr;   // To traverse the Stack
    SNodePtr nextNode;  // To point to the next node

    // Position nodePtr at the head of the Stack.
    nodePtr = top;

    // While nodePtr is not at the end of the Stack...
    while (nodePtr != nullptr){
        // Save a pointer to the next node.
        nextNode = nodePtr->next;
        // Delete the current node.
        delete nodePtr;

        // Position nodePtr at the next node.
        nodePtr = nextNode;
    }
}

void Stack::push (const SElement value )
{
    SNodePtr  newNode = new SNode;
    

    newNode->element = value;

    newNode->next = nullptr;

    if ( top == nullptr)
    {
        top = newNode;
    }else{
        newNode->next = top;
        top = newNode;
    }

}

void Stack::pop(SElement & value)
{
    if(top == nullptr)
    {
       cout<< "The stack is empty.\n";
    }
    else
    {
        value = top->element;
        delete top;
        top = top->next;
    }
}

void Stack::peek( SElement & string )
{
    pop(string);
    push(string);  
}

void Stack::view()                                       // view function to display the contents of the list from the first element to the last element
{

    Stack tempStack;

    SElement temp = "";

    tempStack.top = nullptr;

    cout<<"top -> ";

    while (top)
    {
        pop(temp);

        cout << temp << "-> ";

        tempStack.push(temp);
    }
    cout << "bottom" << endl;

    while(tempStack.top)
    {
        tempStack.pop(temp);
        push(temp);
    }
}