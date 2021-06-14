#ifndef PROJECT_COPIES_H
#define PROJECT_COPIES_H
#include <bits/stdc++.h>
#include <ostream>

using namespace std;

class Copies {
private:
    string CopyDate;
    bool Available;
    string Borrower;
    string BorrowDate;
    int ReturnDays;
public:
    Copies():CopyDate(""),Available(true),Borrower(""),BorrowDate(""),ReturnDays(0){}

    const string &getCopyDate() const {
        return CopyDate;
    }

    void setCopyDate(const string &copyDate) {
        CopyDate = copyDate;
    }

    bool isAvailable() const {
        return Available;
    }

    void setAvailable(bool available) {
        Available = available;
    }

    const string &getBorrower() const {
        return Borrower;
    }

    void setBorrower(const string &borrower) {
        Borrower = borrower;
    }

    const string &getBorrowDate() const {
        return BorrowDate;
    }

    void setBorrowDate(const string &borrowDate) {
        BorrowDate = borrowDate;
    }

    int getReturnDays() const {
        return ReturnDays;
    }

    void setReturnDays(int returnDays) {
        ReturnDays = returnDays;
    }

    friend ostream &operator<<(ostream &os, const Copies &copies) {
        os << "CopyDate: " << copies.CopyDate << "\nAvailable: " << copies.Available << "\nBorrower: " << copies.Borrower
           << "\nBorrowDate: " << copies.BorrowDate << "\nReturnDays: " << copies.ReturnDays<<"\n";
        return os;
    }
    friend istream &operator>>(istream &in,Copies &copy){
        cout<<"Date: "; in>>copy.CopyDate;
        return in;
    }

};


#endif //PROJECT_COPIES_H
