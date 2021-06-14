#ifndef PROJECT_LINKED_LIST_H
#define PROJECT_LINKED_LIST_H


#include <bits/stdc++.h>
using namespace std;

template<class T>
class Node {
private:
    T val;
    Node<T> *nxt;
public:
    Node() : nxt(NULL) {}
    T getVal() {
        return val;
    }
    void setVal(T _val) {
        val = _val;
    }
    Node<T> *getCur() {
        return this;
    }
    void setNxt(Node<T> *_nxt) {
        nxt = _nxt;
    }
    Node<T> *getNxt() {
        return nxt;
    }
};

template <class T>
class LinkedList {
private:
    Node<T> *head, *tail;
    int sz;
public:
    LinkedList() : head(NULL), tail(NULL), sz(0) {

    }

    ~LinkedList() {
        while (sz)
            deletePos(0);
        cout << sz << endl;
    }

    Node<T> *getHead() {
        return head;
    }

    int getSz() {
        return sz;
    }

    void setSz(int szz) {
        sz = szz;
    }

    void insert(T d) {
        Node<T> *data = new Node<T>();
        data->setVal(d);
        if (head == NULL) {
            head = data;
            tail = data;
            ++sz;
            return;
        }
        Node<T> *it = head;
        for (; it->getNxt() != NULL; it = it->getNxt());
        it->setNxt(data);
        tail = data;
        ++sz;
    }

    void insertPos(T d, int idx) {
        if (idx < 0 || idx >= sz) {
            cout << "Insertion out of Bounds\n";
            return;
        }
        if (idx == sz - 1) {
            insert(d);
            return;
        }
        Node<T> *data = new Node<T>;
        data->setVal(d);
        Node<T> *it = head;
        if (idx == 0) {
            data->setNxt(head);
            head = data;
            sz++;
            return;
        }
        for (int i = 1; i < idx; i++, it = it->getNxt());
        data->setNxt(it->getNxt());
        it->setNxt(data);
        ++sz;
    }

    void deletePos(int idx) {
        if (idx < 0 || idx >= sz) {
            cout << "Deletion out of Bound\n";
            return;
        }
        Node<T> *it = head, *prv;
        if (idx == 0) {
            Node<T> *t = head->getNxt();
            delete head;
            head = t;
            --sz;
            return;
        }
        if (idx == sz) {
            for (int i = 1; i < idx; i++, it = it->getNxt());
            delete tail;
            tail = it;
            --sz;
            return;
        }
        for (int i = 1; i < idx; i++, it = it->getNxt());
        prv = it->getNxt();
        it->setNxt(it->getNxt()->getNxt());
        delete prv;
        --sz;
    }

    void deleteVal(T val) {
        Node<T> *it = head;
        for (int i = 0; i < sz; i++, it = it->getNxt())
            if (it->getVal() == val) {
                deletePos(i + 1);
                return;
            }
        cout << "Element is not Found\n";
    }

    static void concatenate(Node<T> *a, Node<T> *b) {
        Node<T> *t1 = a, *t2 = b;
        while (t1->getNxt() != NULL)
            t1 = t1->getNxt();
        t1->setNxt(b);
    }

    static void printLL(Node<T> *Head) {
        Node<T> *it = Head;
        while (it != NULL) {
            cout << it->getVal() << " ";
            it = it->getNxt();
        }
        cout << "\n";
    }

    Node<T> *search(T val) {
        Node<T> *t = head;
        for (int i = 0; i < sz; i++, t = t->getNxt())
            if (t->getVal() == val)
                return t;
        cout << "Element Not Found\n";
        return nullptr;
    }

    void Modify(T oldVal, T newVal) {
        Node<T> *t = search(oldVal);
        if (t == NULL)
            return;
        t->setVal(newVal);
    }
};

#endif //PROJECT_LINKED_LIST_H
