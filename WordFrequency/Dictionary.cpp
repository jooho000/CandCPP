/***
* Jooho Lee
* jlee897
* 2024 Winter CSE101 PA8
* Dictionary.cpp
* Dictionary ADT
***/ 
#include "Dictionary.h"

Dictionary::Dictionary() {
    Node* dummyNode = new Node("dummy", 0);
    dummyNode->parent = dummyNode;
    dummyNode->left = dummyNode;
    dummyNode->right = dummyNode;
    nil = dummyNode;
    root = dummyNode;
    current = dummyNode;
    dummyNode->color = COLOR_BLACK;
    num_pairs = 0;
}

Dictionary::Node::Node(keyType k, valType v) {
    key = k;
    val = v;
    parent = nullptr;
    left = nullptr;
    right = nullptr;
}

Dictionary::Dictionary(const Dictionary& D) {
    Node* dummyNode = new Node("dummy", 0);
    dummyNode->parent = dummyNode;
    dummyNode->left = dummyNode;
    dummyNode->right = dummyNode;
    dummyNode->color = COLOR_BLACK;
    nil = dummyNode;
    root = dummyNode;
    current = dummyNode;
    num_pairs = D.num_pairs;

    if (D.root != nil) {
        preOrderCopy(D.root, D.nil);
    }
}

Dictionary::~Dictionary() {
    clear();
    delete nil;
}

int Dictionary::size() const {
    return num_pairs;
}

bool Dictionary::contains(keyType k) const {
    Node* temp = search(root,k);
    if (temp == nil) {
        return false;
    }
    return true;
}

valType& Dictionary::getValue(keyType k) const {
    if (contains(k) == true) {
        Node* temp = search(root, k);
        return temp->val;
    } else {
        throw std::domain_error("contains(k) != true in getValue() //Dictionary.cpp");
    }
}

bool Dictionary::hasCurrent() const {
    if (current != nil) {
        return true;
    } else {
        return false;
    }
}

keyType Dictionary::currentKey() const {
    if (hasCurrent() == true) {
        return current->key;
    } else {
        throw std::domain_error("hasCurrent() != true in currentKey() //Dictionary.cpp");
    }
}

valType& Dictionary::currentVal() const {
    if (hasCurrent() == true) {
        return current->val;
    } else {
        throw std::domain_error("hasCurrent() != true in currentVal() //Dictionary.cpp");
    }
}

void Dictionary::clear() {
    postOrderDelete(root);
    current = nil;
    root = nil;
    current = nil;
    num_pairs = 0;
    nil->color = COLOR_BLACK;
}

void Dictionary::setValue(keyType k, valType v) {
    Node* curr = search(root, k);
    if (curr == nil) {
        if (k != "") {
            insert(k,v);
        }
    } else {
        curr->val = v;
    }
}

void Dictionary::remove(keyType k) {
    Node* temp = search(root, k);
    if (temp == current) {
        current = nil;
    }
    if (temp != nil) {
        RB_Delete(temp);
    } else {
        throw std::domain_error("search(k) == nil in remove() //Dictionary.cpp");
    }
    num_pairs--;
}

void Dictionary::next() {
    if (hasCurrent() == true) {
        current = findNext(current);
    } else {
        throw std::domain_error("hasCurrent() == false in next() //Dictionary.cpp");
    }
}

void Dictionary::prev() {
    if (hasCurrent() == true) {
        current = findPrev(current);
    } else {
        throw std::domain_error("hasCurrent() == false in prev() //Dictionary.cpp");
    }
}

void Dictionary::begin() {
    current = findMin(root);
}

void Dictionary::end() {
    current = findMax(root);
}

std::string Dictionary::to_string() const {
    std::string finalString = "";
    inOrderString(finalString, root);
    return finalString;
}

std::string Dictionary::pre_string() const {
    std::string finalString = "";
    preOrderString(finalString, root);
    return finalString;
}

bool Dictionary::equals(const Dictionary& D) const {
    return to_string() == D.to_string();
}

std::ostream& operator<<( std::ostream& stream, Dictionary& D ) {
    return stream << D.to_string();
}

bool operator==( const Dictionary& A, const Dictionary& B ) {
    return A.equals(B);
}

Dictionary& Dictionary::operator=( const Dictionary& D ) {
    if (this != &D) {
        Dictionary temp = Dictionary(D);
        std::swap(nil,temp.nil);
        std::swap(root,temp.root);
        std::swap(current, temp.current);
        std::swap(num_pairs, temp.num_pairs);
    }
    return *this;
}



