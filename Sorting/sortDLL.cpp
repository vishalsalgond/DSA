#include <bits/stdc++.h>
using namespace std;

//DLL Node definition
struct Node {

    int data;
    Node *next, *prev;

    Node (int d, Node *next = NULL, Node *prev = NULL) {
        this -> data = d;
        this -> next = next;
        this -> prev = prev;
    }
};

//split DLL starting from head to [head ... mid] & [mid + 1 ...]
Node *split(Node *head) {

    Node *slow = head, *fast = head;

    //slow will stop at middle node
    while(fast -> next && fast -> next -> next) {
        slow = slow -> next;
        fast = fast -> next -> next;
    }

    //break the list
    Node *temp = slow -> next;
    slow -> next -> prev = NULL;
    slow -> next = NULL;

    //return next node of mid
    return temp;
}

Node* merge(Node *head1, Node *head2) {

    //if one list is empty, simply return the second list
    if(!head1) return head2;
    if(!head2) return head1;

    //if head1 is smaller than head2 then move one position ahead
    //and attach head1 to result ontained from merging of remaining lists
    if(head1 -> data < head2 -> data) {
        head1 -> next = merge(head1 -> next, head2);
        head1 -> next -> prev = head1;
        head1 -> prev = NULL;
        return head1;
    }
    else {
        head2 -> next = merge(head1, head2 -> next);
        head2 -> next -> prev = head2;
        head2 -> prev = NULL;
        return head2;
    }
    
}

Node* mergeSort(Node *head) {

    //if there's only one node left then just return it
    if(!head || !head -> next) return head;

    //get next node to middle
    Node *mid = split(head);

    head = mergeSort(head);
    mid = mergeSort(mid);

    //merge two lists i. e. [head ... mid] & [mid + 1 ...]
    return merge(head, mid);
}



int main() {
    
    int n; cin >> n;
    Node *head = NULL, *prev = NULL;

    //create a DLL
    for(int i = 0; i < n; i++) {
        int num; cin >> num;
        Node *curr = new Node(num);
        if(i > 0) {
            curr -> prev = prev;
            prev -> next = curr;
        }
        else head = curr;
        prev = curr;
    }

    Node *temp = mergeSort(head);
    while(temp) {
        cout << temp -> data << " ";
        temp = temp -> next;
    }
}
