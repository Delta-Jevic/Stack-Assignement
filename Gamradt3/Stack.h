/********************************************************************
*** NAME	    : Jevic Tshilumba                                 ***
*** CLASS	    : CSC 300                                         ***
*** ASSIGNMENT	: 3                                               ***
*** DUE DATE	: 10-05-2022                                      ***
*** INSTRUCTOR	: Ken Gamradt	                                  ***
*********************************************************************/

#ifndef STACK_H                                   // Guard-start
#define STACK_H
#include <string>

typedef std::string SElement;                     // typedef<existing type> <new type> // basic from of generic programming

class Stack
{
public:                                            // exportable
// General description of each of the ADT operations/methods/functions -exportable operations only
    Stack();
    Stack( Stack &);                               // reuse pop & push
    ~Stack();
    void push( const SElement);
    void pop(SElement &);                          
    void peek(SElement &);                         // reuse pop & push
    void view();                                   // reuse pop & push
private:                                           // non-exportable
// No private member documentation - implementation details are hidden/abstracted away
    struct SNode;
    typedef SNode* SNodePtr;
    struct SNode{
           SElement element;
           SNodePtr next;
        };
        SNodePtr top;
};
#endif
                                        
