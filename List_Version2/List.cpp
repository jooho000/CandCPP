/***
* Jooho Lee
* jlee897
* 2024 Winter CSE101 PA5
* List.cpp
* List ADT
***/ 
#include<iostream>
#include<string>
#include<stdexcept>
#include"List.h"

List::Node::Node(ListElement x) {
    data = x;
    next = nullptr;
    prev = nullptr;
}

List::List() {
    frontDummy = new Node(0);
    backDummy = new Node(0);
    frontDummy->next = backDummy;
    backDummy->prev = frontDummy;
    beforeCursor = frontDummy;
    afterCursor = backDummy;
    pos_cursor = 0;
    num_elements = 0;
}

List::List(const List& L) {
    frontDummy = new Node(0);
    backDummy = new Node(0);
    frontDummy->next = backDummy;
    backDummy->prev = frontDummy;
    beforeCursor = frontDummy;
    afterCursor = backDummy;
    pos_cursor = 0;
    num_elements = 0;
    Node* curr = L.frontDummy->next;
    moveFront();
    for (int i = 0; i < L.length(); i++) {
        insertAfter(curr->data);
        moveNext();
        curr = curr->next;
    }
    num_elements = L.num_elements;
}

List::~List() {
    clear();
    delete frontDummy;
    delete backDummy;
}

void List::clear() {
    if (length() == 0) {
        return;
    }
    for (int i = 0; i < length(); i++) {
        Node *temp = frontDummy->next;
        frontDummy->next = frontDummy->next->next;
        delete temp;
    }
    frontDummy->next = backDummy;
    backDummy->prev = frontDummy;
    beforeCursor = frontDummy;
    afterCursor = backDummy;
    pos_cursor = 0;
    num_elements = 0;
}

int List::length() const{
    return num_elements;
}

ListElement List::front() const {
    if (length() <= 0) {
        throw std::length_error("List: front(): empty List\n");
    }
    return(frontDummy->next->data);
}

ListElement List::back() const {
    if (length() <= 0) {
        throw std::length_error("List: back(): empty List\n");
    }
    return(backDummy->prev->data);
}

int List::position() const {
    if (pos_cursor < 0 || pos_cursor > length()) {
        throw std::length_error("List: position(): position is less than 0 or greater than length\n");
    }
    return pos_cursor;
}

ListElement List::peekNext() const {
    if (position() >= length()) {
        throw std::logic_error("Lsit: peekNext(): position() >= length()\n");
    }
    return afterCursor->data;
}

ListElement List::peekPrev() const {
    if (position() <= 0) {
        throw std::logic_error("List: peekPrev(): position() <= 0\n");
    }
    return beforeCursor->data;
}

void List::moveFront() {
    beforeCursor = frontDummy;
    afterCursor = frontDummy->next;
    pos_cursor = 0;
}

void List::moveBack() {
    beforeCursor = backDummy->prev;
    afterCursor = backDummy;
    pos_cursor = length();
}

ListElement List::moveNext() {
    if (position() >= length()) {
        throw std::logic_error("List: moveNext(): no next valie to go to\n");
    }
    ListElement valToReturn = peekNext();
    pos_cursor++;
    beforeCursor = beforeCursor->next;
    afterCursor = afterCursor->next;
    return valToReturn;
}

ListElement List::movePrev() {
    if (position() <= 0) {
        throw std::logic_error("List: movePrev(): no prev value to go to\n");
    }
    ListElement valToReturn = peekPrev();
    pos_cursor--;
    beforeCursor = beforeCursor->prev;
    afterCursor = afterCursor->prev;
    return valToReturn;
}

void List::insertAfter(ListElement x) {
    Node *N = new Node(x);
    beforeCursor->next = N;
    N->prev = beforeCursor;
    N->next = afterCursor;
    afterCursor->prev = N;
    num_elements++;
    afterCursor = N;
}

void List::insertBefore(ListElement x) {
    Node *N = new Node(x);
    afterCursor->prev = N;
    N->next = afterCursor;
    beforeCursor->next = N;
    N->prev = beforeCursor;
    beforeCursor = N;
    num_elements++;
    pos_cursor++;
}

void List::setAfter(ListElement x) {
    if (position() >= length()) {
        throw std::logic_error("List: setAfter(): no after value to go to\n");
    }
    afterCursor->data = x;
}

  void List::setBefore(ListElement x) {
    if (position() <= 0) {
        throw std::logic_error("List: setBefore(): no before value to go to\n");
    }
    beforeCursor->data = x;
  }

  void List::eraseAfter() {
    if (position() >= length()) {
        throw std::logic_error("List: earaseAfter(): no after value to go to\n");
    }
    Node *temp = afterCursor;
    beforeCursor->next = afterCursor->next;
    afterCursor->next->prev = beforeCursor;
    afterCursor = beforeCursor->next;
    delete temp;
    num_elements--;
  }

  void List::eraseBefore() {
    if (position() <= 0) {
        throw std::logic_error("List: eraseBefore(): no before value to go to\n");
    }
    Node *temp = beforeCursor;
    beforeCursor->prev->next = afterCursor;
    afterCursor->prev = beforeCursor->prev;
    beforeCursor = afterCursor->prev;
    delete temp;
    num_elements--;
    pos_cursor--;
  }

  int List::findNext(ListElement x) {
    while (position() < length()) {
        ListElement temp = peekNext();
        moveNext();
        if (temp == x) {
            return position();
        }
    }
    return -1;
  }

  int List::findPrev(ListElement x) {
    while (position() > 0) {
        ListElement temp = peekPrev();
        movePrev();
        if (temp == x) {
            return position();
        }
    }
    return -1;
  }

  void List::cleanup() {
    Node *checkNode;
    Node *curr = frontDummy->next;
    for (int i = 0; i < length(); i++) {
        checkNode = curr->next;
        while (checkNode != backDummy) {
            if (checkNode->data == curr->data) {
                Node *temp = checkNode;
                checkNode->prev->next = checkNode->next;
                checkNode->next->prev = checkNode->prev;
                checkNode = checkNode->next;
                if (temp == beforeCursor) {
                    beforeCursor = beforeCursor->prev;
                }
                delete temp;
                num_elements--;
            } else {
                checkNode = checkNode->next;
            }
        }
        curr = curr->next;
    }
    if (beforeCursor == frontDummy) {
        afterCursor = beforeCursor->next;
        pos_cursor = 0;
    } else {
        ListElement myNum = beforeCursor->data;
        moveFront();
        findNext(myNum);
    }
  }

List List::concat(const List& L) const {
    List sum(*this);
    Node* curr = L.frontDummy->next;
    sum.moveBack();
    for (int i = 0; i < L.length(); i++) {
        sum.insertAfter(curr->data);
        sum.moveNext();
        curr = curr->next;
    }
    sum.moveFront();
    return sum;
}

std::string List::to_string() const {
    Node* curr = frontDummy->next;
    std::string s = "";
    for (int i = 0; i < length(); i++) {
        s += std::to_string(curr->data) + " ";
        curr = curr->next;
    }
    return s;
}

bool List::equals(const List& R) const {
    bool isEqual = false;
    Node* curr = frontDummy->next;
    Node* comparee = R.frontDummy->next;
    if (length() != R.length()) {
        return isEqual;
    }
    for (int i = 0; i < length(); i++) {
        if (curr->data != comparee->data) {
            return isEqual;
        }
        curr = curr->next;
        comparee = comparee->next;
    }
    isEqual = true;
    return isEqual;
}

std::ostream& operator<<( std::ostream& stream, const List& L ) {
    return stream << L.to_string();
}

bool operator==( const List& A, const List& B ) {
    return A.equals(B);
}

List& List::operator=( const List& L ) {
    if (this != &L) {
        List temp = L;

        std::swap(frontDummy,temp.frontDummy);
        std::swap(backDummy,temp.backDummy);
        std::swap(afterCursor,temp.afterCursor);
        std::swap(beforeCursor,temp.beforeCursor);
        std::swap(pos_cursor,temp.pos_cursor);
        std::swap(num_elements,temp.num_elements);
    }
    return *this;
}





