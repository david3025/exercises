#include <iostream>
#include <typeinfo>
#include "linked_list.h"
using namespace std;


/*
float *func1(float n) {
    float *a = &n;
    (*a) = n + 5;
     do{
         (*a)--;
     }while (a > 0);
     
    return a;
}
*/
float *func1(float &n) {
    float *a = &n;
    (*a) = n + 5;
     do{
         (*a)--;
     }while (*a > 0);
     
    return a;
}

/*
char *IntToString(int number) {
    char str1[32] = {0};
    while (number != 0) {
        str1[i++] = '0' +number % 10;
        number /= 10;
    }
    return str1;
}
*/

void reverse(char str[], int length)
{
    int start = 0;
    int end = length -1;
    while (start < end)
    {
        swap(*(str+start), *(str+end));
        start++;
        end--;
    }
}

void IntToString(int number, char *string_input) {
    int i = 0;
    while (number != 0) {
        string_input[i++] = '0' + number % 10;
        number /= 10;
    }
    string_input[i] = '\0';
    reverse(string_input, i);
}
/*Solutions with more errors*/
int *AllocateAndZeroMemory(int nSize) {
    int* pRet = new int[nSize * sizeof(int)];
    if (pRet) {
        while (nSize != 0) {
            pRet[nSize--] = 0;
        }
        
    }
    return pRet;
}

int PrintInRowsAndGetLength(char* pStr)
{
    int i = 0, length = 0;
    while (pStr[i] != '\0')
    {
        printf("%c \n", pStr[i++]);
        length = length + 1;
    }
    return length;
}



Node* Linked_List_Questions(Node* m_pHead)
{
    Node* n1 = m_pHead;
    Node* n2 = m_pHead;

    while (n2->next != nullptr)
    {
        n1 = n1->next;
        n2 = n2->next->next;
        if (n1 == n2)
        {
            break;
        }
    }
    n1 = m_pHead; 

    while (n1 != n2)
    {
    n1 = n1->next;
    n2 = n2->next;
    }
    return n2;
}





int main() {
    /*float num = -6;
    std::cout << *func1(num);
    char result[30];
    int number = 12345;
    IntToString(number, result);
    cout << typeid(number).name() << endl; 
    cout << typeid(result).name() << endl; 
    int* x = AllocateAndZeroMemory(4);
    cout<<PrintInRowsAndGetLength("hello");*/

    //linked-list
    Node* head = NULL;
    Node* n1 = NULL;
    Node* n2 = NULL;
    Node* n3  = NULL;
    Node* n4  = NULL;
 
    // allocate 3 nodes in the heap
    head = new Node();
    n1 = new Node();
    n2 = new Node();
    n3 = new Node();
    n4 = new Node();

    head->data = 0; 
    head->next = n1;

    n1->data = 1; 
    n1->next = n2;

    n2->data = 2; 
    n2->next = n3;

    n3->data = 3; 
    n3->next = n4;

    n4->data = 4; 
    n4->next = n2;




    cout <<Linked_List_Questions(head)->data;

    


    return 0;
}