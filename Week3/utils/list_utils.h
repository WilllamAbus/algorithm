#pragma once
#include <vector>
#include <iostream>

using namespace std;

struct ListNode {
    int val;
    ListNode* next;
    ListNode(int x) : val(x), next(nullptr) {}
};

// API
ListNode* buildList(const vector<int>& vals);
void printList(ListNode* head);
void freeList(ListNode* head);