# include "linked_list.h"
# include <iostream>
# include <string>

using std::cout, std::endl, std::string, std::ostream;

//adds a single node to the end of the linked list. 
//The parameters will be used to create a node object 
//that will be added to the linked list.

void MyList::add(const std::string& name, int score) {
    // TODO
    MyNode * newNode = new MyNode(name, score);
    newNode -> name = name;
    newNode -> score = score;
    //say this is the last node in the network
    newNode -> next = nullptr;
    //say the previous node is the tail node ()
    newNode->prev = _tail;

    if (_tail != nullptr){
        _tail-> next = newNode;
    }
    _tail = newNode;
    if (_head == nullptr){
        _head = newNode;
    }
    ++_size;

}

//removes all the nodes from the linked list.
void MyList::clear() {
    // TODO
    MyNode * temp = _head;
    MyNode * next = nullptr;
    while (temp != nullptr){
        next = temp->next;
        delete temp;
        --_size;
        temp = next;
    }
    _head = nullptr;
    _tail = nullptr;
    
}

bool MyList::remove(const std::string& name) {
    // TODO

    return false;
}

bool MyList::insert(const std::string& name, int score, size_t index) {
    // TODO

    return false;
}

MyList::MyList() : _size(0), _head(nullptr), _tail(nullptr) {}

MyList::~MyList() {
    clear();
}

size_t MyList::size() const {
    return _size;
}

bool MyList::empty() const {
    return _head == nullptr;
}

MyNode* MyList::head() const {
    return _head;
}

ostream& operator<<(ostream& os, const MyList& myList) {
    MyNode* _current = myList.head();
    if (_current == nullptr) {
        os << "<empty>" << endl;
        return os;
    }

    os << "[ " << _current->name << ", " << _current->score << " ]";
    _current = _current->next;
    while (_current != nullptr) {
        os << " --> [ " << _current->name << ", " << _current->score << " ]";
        _current = _current->next;
    }
    
    return os;
}

MyNode::MyNode(const std::string& name, int score) : name{name}, score{score}, next{nullptr}, prev{nullptr} {}

/*
int main(){

    MyList myList;
    myList.add("hello", 5);
    myList.add("idk", 5);
    myList.add("whatcha harry", 5);
    std::cout<<"size "<<myList.size()<<std::endl;
    std::cout<<myList<<std::endl;
    std::cout<<"YESSSSSSSSSS"<<std::endl;
    return 0;
}
*/