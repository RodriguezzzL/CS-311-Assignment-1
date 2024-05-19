//Name: Luis Rodriguez
//Date: 02/02/2023
//Class: CS311
#include <iostream>
using namespace std;

struct Node
{
int value;
Node *next;
};

Node *createLinkedList(int a[],int len);
Node *mergeLinkedLists(Node **LL,int len);
Node *reversedLinkedList(Node *L);
Node *removeDuplicates(Node *L);
void display(Node* l);


int main() {
  Node *head;
  Node *rev_head;
  int a[] = {1,2,3,4,5};
  int b[] = {6,7,8,9,10};
  int c[] = {11,2,13,14,15};
  int len = 5;
 
  
  
  Node **Dptr = new Node *[len];
  Dptr[0] = createLinkedList(a,len);
  Dptr[1] = createLinkedList(b,len);
  Dptr[2] = createLinkedList(c,len);
  head = mergeLinkedLists(Dptr,len);
  
  cout << "The merged list is: " << endl;
  display(head);

  head = removeDuplicates(head);
  display(head);

    
  cout << "The reversed list is: " << endl;
  head = reversedLinkedList(head);
  display(head);
  
  
    
  
    
  }
Node *createLinkedList(int a[],int len){
  Node *temp;
  Node *temp_prev;
  Node* head = nullptr;

  
  
  for (int i = 0; i < len; i++)
    {
      if(i == 0)
      {
          head = new Node;
          cout << "Loading to Node :" << a[0] << endl;
          head->value = a[0];
          head->next = nullptr;
          temp_prev = head;
      }
      else
      { 
        temp = new Node;
        temp->value = a[i];
        cout <<"Loading to Node :" << a[i] << endl;
        temp->next = nullptr;
        temp_prev->next = temp; 
        temp_prev = temp;
      }
  
 
    }
  return head;
  }
Node *mergeLinkedLists(Node **LL,int len){
  Node* originalHead = *LL;
  Node* original_listtemp;

  Node *temp;
  Node *new_head;
  if (originalHead == nullptr)
  {
    cout << "List is empty!" << endl;
    return nullptr;
  }
  for (int i = 0; i < len; i++)
    {
      original_listtemp = LL[i];
      if(i == 0)
      {
        new_head = new Node;
        new_head->value = original_listtemp->value;
        new_head->next = nullptr;
        temp = new_head;
        original_listtemp = original_listtemp->next;
        cout << "Copied element value is :" << temp->value << endl;
        
        while(original_listtemp!= nullptr){
          
          temp->next = new Node;
          temp = temp->next;
          temp->value = original_listtemp->value;
          temp->next = nullptr;
          original_listtemp = original_listtemp->next;
          cout << "Copied element value is :" << temp->value << endl;
        }
      }
      else
      {
      while(original_listtemp != nullptr)
        {
          temp->next = new Node;
          temp = temp->next;
          temp->value = original_listtemp->value;
          temp->next = nullptr;
          original_listtemp = original_listtemp->next;
          cout << "Copied element value is :" << temp->value << endl;
        }  
    }
  
   }
  return new_head;
  }
Node *reversedLinkedList(Node *L){
  Node *Head = L;
  Node *current = Head;
  Node *previous = nullptr;
  Node *next = nullptr;
  while (current!= nullptr)
  {
    next = current->next;
    current->next = previous;
    previous = current;
    current = next;
  }
  Head = previous;
  return Head;
  }
Node *removeDuplicates(Node *L){
  Node *current = L;
  Node *next = nullptr;
  Node *previous = L;
  Node *head = L;
  Node *temp = nullptr;
  
  if (head == nullptr)
  {
  cout<<"List was empty."<<endl;
  return nullptr;
  }
  
  while (current->next != nullptr)
    {
      next = current->next; 
      while(next != nullptr) // next != nullptr to check last element
      {
        
        if (current->value == next->value)
        {
          cout << "Duplicate value found!" << endl;
          while(previous->next != next)
            {
              previous = previous->next;
            }
    
           cout<< "Removing element " << current->value << endl;
            previous->next = next->next;
            temp = next;
            delete temp;
            next = previous->next;
          
        }
        else
        {
            next = next->next;
        }
      }
      current = current->next; // moving to next element to check.
     
  }
  return head;}
void display(Node* l)
{
   
  if(l == nullptr)
  {
    cout << "List is empty" << endl;
    return;
  }
  cout << "Now displaying Linked List " << endl;
  while(l!= nullptr) 
  {
    cout << l->value << " ";
    l = l->next;
  }
  cout << endl;
}