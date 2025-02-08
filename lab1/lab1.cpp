#include <iostream>
using namespace std;

struct list{
//    list* pred;
    list* next;
    int d;
};

void add(list*& head, int data){
    list* elem = new list;
    elem -> d = data;
    elem -> next = head;
    head = elem;
}

void print(list* head){
    list* current = head;
    while (current){
        cout << current->d << " <-> ";
        current = current->next;
    }
    std::cout << '\n';
}

int main(){
    list* head = nullptr;
    int n = 0; 
    cin >> n;
    for(int i = 0; i < n; i++){
           add(head,i);
    }
    print(head);
}