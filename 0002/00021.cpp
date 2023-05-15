#include <iostream>


struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    explicit ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};


int getVal(ListNode *ln) {
    if (ln == nullptr) {
        return 0;
    }
    return ln->val;
}


ListNode* getNext(ListNode* ln) {
    if (ln == nullptr) {
        return nullptr;
    }
    return ln->next;
}


int calcSum(ListNode* ln1, ListNode* ln2, int carry=0) {
    return getVal(ln1) + getVal(ln2) + carry;
}


int calcVal(int sum) {
    return sum % 10;
}


int calcCarry(int sum) {
    return sum / 10;
}


class Solution {
public:
    static ListNode* addTwoNumbers(ListNode* l1, ListNode* l2);
};
ListNode* Solution::addTwoNumbers(ListNode* l1, ListNode* l2) {
    int sum, val, carry = 0;
    ListNode* res = new ListNode();
    ListNode* curr = res;
    while ((l1 != nullptr) || (l2 != nullptr)) {
        sum = calcSum(l1, l2, carry);
        val = calcVal(sum);
        carry = calcCarry(sum);
        curr->next = new ListNode(val);
        curr = curr->next;
        l1 = getNext(l1);
        l2 = getNext(l2);
    }
    if (carry > 0) {
        curr->next = new ListNode(carry);
    }
    return res->next;
}


bool listNodeEqual(ListNode* ln1, ListNode* ln2) {
    while ((ln1 != nullptr) || (ln2 != nullptr)) {
        if (getVal(ln1) != getVal(ln2)) {
            return false;
        }
        ln1 = getNext(ln1);
        ln2 = getNext(ln2);
    }
    return true;
}


void example1() {
    ListNode ln11(3);
    ListNode ln12(4, &ln11);
    ListNode ln13(2, &ln12);

    ListNode ln21(4);
    ListNode ln22(6, &ln21);
    ListNode ln23(5, &ln22);

    ListNode expected1(8);
    ListNode expected2(0, &expected1);
    ListNode expected3(7, &expected2);

    ListNode* ans = Solution::addTwoNumbers(&ln13, &ln23);
    assert(listNodeEqual(ans, &expected3));
}


void example2() {
    ListNode ln11(0);
    ListNode ln21(0);
    ListNode expected(0);

    ListNode* ans = Solution::addTwoNumbers(&ln11, &ln21);
    assert(listNodeEqual(ans, &expected));
}


void example3() {
    ListNode ln11(9);
    ListNode ln12(9, &ln11);
    ListNode ln13(9, &ln12);
    ListNode ln14(9, &ln13);
    ListNode ln15(9, &ln14);
    ListNode ln16(9, &ln15);
    ListNode ln17(9, &ln16);

    ListNode ln21(9);
    ListNode ln22(9, &ln21);
    ListNode ln23(9, &ln22);
    ListNode ln24(9, &ln23);

    ListNode expected1(1);
    ListNode expected2(0, &expected1);
    ListNode expected3(0, &expected2);
    ListNode expected4(0, &expected3);
    ListNode expected5(9, &expected4);
    ListNode expected6(9, &expected5);
    ListNode expected7(9, &expected6);
    ListNode expected8(8, &expected7);

    ListNode* ans = Solution::addTwoNumbers(&ln17, &ln24);
    assert(listNodeEqual(ans, &expected8));
}


int main() {
    example1();
    example2();
    example3();
    return 0;
}