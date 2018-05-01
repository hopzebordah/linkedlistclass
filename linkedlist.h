/*
Alexander Peters
linked list class definition file
*/

#ifndef LINKEDLIST_H
#define LINKEDLIST_H

using namespace std;

template <typename T>
struct node
{
    T data; 
    node<T> *link;
};

template <typename T> class linkedlist 
{
private:
    node<T> *head, *last;
public:
    // constructors
    linkedlist();
    linkedlist(const linkedlist &);

    // methods
    void append(T data);
    T get(int pos);
    int length();
    void print();
    void reverse();
    int search(T data);
    void insertByPos(T data, int pos);
    void removeByPos(int pos);
};

template <typename T> linkedlist<T>::linkedlist()
{
    head = NULL;
    last = NULL;
}

template <typename T> linkedlist<T>::linkedlist(const linkedlist &other)
{
    head = other.head;
    last = other.last;
}

template <typename T> void linkedlist<T>::append(T data)
{
    // declare new node and set
    // data to par and link to null (because it's the last)
    node<T> *temp = new node<T>;
    temp->data = data;
    temp->link = NULL;

    // if no elements exist in the linked-list
    if (head == NULL)
    {
        // then the new node is the first and last element
        head = temp;
        last = temp;
    }
    else
    {
        // set last link to new node,
        // then set last to new node
        last->link = temp;
        last = last->link;
    }
}

template <typename T> T linkedlist<T>::get(int pos)
{
    int i = 0; 
    for (node<T> *ptr=head; head!=NULL; ptr=ptr->link)
    {
        if (i == pos)
            return ptr->data;
        i++;
    }
    return -1;
}

template <typename T> void linkedlist<T>::print()
{
    // loop var is ptr to first node.
    // while ptr is != null, then
    // assign ptr to the current node's link to next node
    for (node<T> *ptr=head; ptr!=NULL; ptr=ptr->link)
    {
        cout << ptr << ": " << ptr->data << endl;
    }
}

template <typename T> int linkedlist<T>::length()
{
    int i = 0;
    for (node<T> *ptr=head; ptr!=NULL; ptr=ptr->link)
    {
        i++;
    }
    return i;
}

template <typename T> void linkedlist<T>::reverse()
{
    node<T> *prev = NULL;
    node<T> *curr = head;
    node<T> *next = NULL;

    last = head;    

    // while curr is not null
    // set next to next via curr->link
    // curr->link to prev (first time is null)
    // prev to curr
    // and curr to next a.k.a interate to next node
    while (curr != NULL)
    {
        next = curr->link;
        curr->link = prev;
        prev = curr;
        curr = next;
    }
    // set head to final node ptr
    head = prev;
}

template <typename T> int linkedlist<T>::search(T tofind)
{
    int i = 0;
    for (node<T> *ptr=head; ptr!=NULL; ptr=ptr->link)
    {
        if (ptr->data == tofind)
            return i; 
        i++;
    }
    return -1;
}

template <typename T> void linkedlist<T>::insertByPos(T data, int pos)
{
    node<T> *prev = NULL;
    int i = 0;
    for (node<T> *ptr=head; ptr!=NULL; ptr=ptr->link)
    {
        if (i == pos)
        {
            node<T> *temp = new node<T>;
            temp->data = data;
            if (ptr == head)
            {
                temp->link = head;
                head = temp;
            }
            else if (ptr == last)
            {
                temp->link = NULL;
                last->link = temp;
                last = temp;
            }
            else
            {
                prev->link = temp;
                temp->link = ptr; 
            }
            return;
        }
        i++;
        prev = ptr;
    }
}

template <typename T> void linkedlist<T>::removeByPos(int pos)
{
    node<T> *prev = NULL;
    int i = 0;
    for (node<T> *ptr=head; ptr!=NULL; ptr=ptr->link)
    {
        if (i == pos)
        {
            if (ptr == head)
            {
                head = ptr->link;
                delete ptr;
            }
            else if (ptr == last)
            {
                last = prev;
                last->link = NULL;
                delete ptr;
            }
            else 
            {
                prev->link = ptr->link;
                delete ptr;
            }
            return;
        }
        i++;
        prev = ptr;
    }
}

#endif
