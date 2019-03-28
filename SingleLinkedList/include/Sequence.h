#ifndef SEQUENCE_H
#define SEQUENCE_H

#include<iostream>
using namespace std;

template<typename Key, typename Info>
class Sequence
{

    private:
        struct Node{
            Node *next;
            Info info;
            Key key;

            Node():next(nullptr){}
            Node(Key newKey,Info newInfo, Node *newNode): next(newNode), info(newInfo), key(newKey){}

        };

    protected:

    private:
        Node *head;
        int length;

    public:

        // constructors
        Sequence(): head(nullptr), length(0){}
        Sequence(const Sequence<Key, Info> &seq): head(nullptr){*this = seq;}  // to short body to create under the class

        // destructor
        ~Sequence(){ clear();}

        // operators
        bool operator>=(const Sequence<Key, Info> & seq) const{if(this->length >= seq.length) return true; return false;}
        bool operator>(const Sequence<Key, Info> & seq) const{if(this->length > seq.length) return true; return false;}
        bool operator<(const Sequence<Key, Info> & seq) const{if(this->length < seq.length) return true; return false;}
        bool operator<=(const Sequence<Key, Info> & seq) const{if(this->length <= seq.length) return true; return false;}
        bool operator==(const Sequence<Key, Info> & seq) const noexcept;
        bool operator!=(const Sequence<Key, Info>& seq)const noexcept{return !(*this == seq);}  // to short body to create under the class
        Sequence<Key, Info> & operator=(const Sequence<Key, Info> &seq);
        template<typename Keyy, typename Infoo>
        friend ostream& operator<<(ostream& os, const Sequence<Keyy, Infoo>& seq);
        Sequence<Key, Info> operator+(const Sequence<Key, Info> & seq){return this->merge(seq);}   // to short body to create under the class
        Sequence<Key, Info> &operator+=(const Sequence<Key, Info> seq){*this = *this + seq;return *this;} // to short body to create under the class

        //capacity
        bool isEmpty() const;
        int size() const;
        int contain(const Key &key);

        //modifiers
        void pushFront(const Key &key, const Info &info);
        void pushBack(const Key &key, const Info &info);
        void popFront();
        void popBack();
        void insertAfter(const Key& newKey, const Info& newInfo, const Key& loc,int which = 1);
        void clear();
        bool remove(const Key &key, int which = 1);

        void printx(Node *temp){

            if(temp == nullptr){
                cout << endl;
                return;
            }

            if(temp->next == nullptr){
                cout << temp->info << " ";
                cout << endl;
                return;
            }


            if(temp->key %2 == 0){
                cout << temp->key << " ";
                printx(temp->next);
            }else{
            printx(temp->next);
            }

            if(temp->key %2 != 0)
                cout << temp->key << endl;




        }

        void printClever(){
            this->printx(head);
        }


        // access to elements
        Info & front();
        Info & back();
        Info & getElement(const Key &key, int which = 1);

        // operations
        private:
        Sequence<Key, Info> merge(const Sequence<Key, Info> seq) const;


        public:
        class Iterator;

        Iterator begin() const
        {
            Iterator it(head);
            return it;
        }
        const Iterator constBegin() const
        {
            Iterator it(head);
            return it;
        }
        Iterator end() const
        {
            Iterator it(nullptr);
            return it;
        }
        const Iterator constEnd() const
        {
            Iterator it(nullptr);
            return it;
        }

};

template<typename Key, typename Info>
class Sequence<Key, Info>::Iterator{

private:
    Node *current;

public:
    Iterator():current(nullptr){};
    Iterator(Node *node):current(node){};
    ~Iterator(){};
    Iterator(const Iterator &temp){
        this->current = temp.current;
    }

    Iterator & operator=(const Iterator &temp){
    this->current = temp.current;
    }

    bool operator==(const Iterator &temp) const{
        if(this->current == temp.current)
            return true;

        return false;
    }

    bool operator!=(const Iterator &temp) const{
        return !(*this == temp);
    }

    Iterator operator++(int){
    if(current) current = current->next;
        return *this;
    }

    Info showInfo() const{
        if(current)
            return current->info;

        throw "Empty Iterator showInfo";
        return 0;
    }

    Key showKey() const{
        if(current)
            return current->key;

        throw "Empty Iterator showKey";
        return 0;
    }


};


//operators
template<typename Key, typename Info>
Sequence<Key, Info> & Sequence<Key, Info>::operator=(const Sequence<Key, Info> &seq){
    if(this == &seq)
        return *this;

        clear();
        Node *current = seq.head;
        while(current){
            this->pushBack(current->key, current->info);
            current = current->next;
        }

    return *this;

}

template<typename Key, typename Info>
ostream& operator<<(ostream& os, const Sequence<Key, Info>& seq){
    typename Sequence<Key, Info>::Node *current = seq.head;

    while(current){
        os << current->key << " " << current->info << "\n";
        current = current->next;
    }

    return os;
}

template<typename Key, typename Info>
bool Sequence<Key, Info>::operator==(const Sequence<Key, Info> & seq) const noexcept{
    if(length != seq.length){
        return false;
    }
    Node *left = head;
    Node *right = seq.head;

    while(left){
        if(left->key != right->key || left->info != right->info){
            return false;
        }
        left = left->next;
        right = right->next;
    }
    return true;
}

//capacity
template<typename Key, typename Info>
bool Sequence<Key, Info>::isEmpty() const{return length == 0;}

template<typename Key, typename Info>
int Sequence<Key, Info>::size() const{return length;}

template<typename Key, typename Info>
int Sequence<Key, Info>::contain(const Key &key){
    int howMuch = 0;
    Node *temp = head;
    while(temp){
        if(temp->key == key)
            howMuch++;
        temp = temp->next;
    }

    return howMuch;
}


//modifiers

template<typename Key, typename Info>
void Sequence<Key, Info>::pushFront(const Key &key, const Info &info){

        if(isEmpty()){
            head = new Node(key, info, nullptr);
            length++;
            return;
        }

        Node *newElement = new Node(key, info, head);
        head = newElement;
        length++;


}

template<typename Key, typename Info>
void Sequence<Key, Info>::pushBack(const Key &key, const Info &info){

    if(isEmpty()){
        head = new Node(key, info, nullptr);
        length++;
        return;
    }

    Node *current = head;
        while(current->next)
            current = current->next;

            Node *newElement = new Node(key, info, nullptr);
            current->next = newElement;
            length++;

}

template<typename Key, typename Info>
void Sequence<Key, Info>::popFront(){
    if(isEmpty())
        return;

    Node *current = head;
    head = head->next;
    length--;
    delete current;

}

template<typename Key, typename Info>
void Sequence<Key, Info>::popBack(){
    if(isEmpty())
        return;

    if(!head->next){
    delete head;
    head = nullptr;
    length--;
    return;
    }

    Node *current = head;
    while(current->next->next)
        current = current->next;

    delete current->next;
    current->next = nullptr;
    length--;

}

template<typename Key, typename Info>
void Sequence<Key, Info>::insertAfter(const Key& newKey, const Info& newInfo, const Key& loc,int which){
    if(isEmpty() || which < 1)
        cout << ("Wrong range") << endl;

    Node *current = head;
    int nowWhich = 0;
    while(current){
        if(current->key == loc){
            nowWhich++;
            if(which == nowWhich){
                Node *newElement = new Node{newKey, newInfo, current->next};
                current->next = newElement;
                length++;
                return;
            }
        }
        current = current->next;

    }

}

template<typename Key, typename Info>
bool Sequence<Key, Info>::remove(const Key &key, int which){

    if(isEmpty() || which < 1){
        return false;
    }

    Node *current = head;
    int nowWhich = 0;

    if(key == head->key){
        nowWhich++;
        if(which == nowWhich){
            head = head->next;
            delete current;
            length--;
            return true;
        }
    }

    while(current->next){
        if(current->next->key == key){
            nowWhich++;
            if(nowWhich == which){
                Node *newElement = current->next->next;
                delete current->next;
                current->next = newElement;
                length--;
                return true;
            }
        }
        current = current->next;
    }

    return false;

}


template<typename Key, typename Info>
void Sequence<Key, Info>::clear(){
    Node *current = head;

    while(current){
        head = head->next;
        delete current;
        current = head;
    }

    length = 0;

}

// access to elements
template<typename Key, typename Info>
Info & Sequence<Key, Info>::front(){
    if(isEmpty()){
        throw runtime_error("Empty sequence");
    }

    return head->info;
}

template<typename Key, typename Info>
Info & Sequence<Key, Info>::back(){
    if(isEmpty()){
        throw runtime_error("Empty sequence");
    }

    Node *current = head;

    while(current->next)
        current = current->next;

    return current->info;
}

template<typename Key, typename Info>
Info & Sequence<Key, Info>::getElement(const Key &key, int which){

    if(which <= 0){
        throw invalid_argument("Negative parameter!");

    }


    Node *temp = head;
    int whichOne = 0;
    while(temp){
        if(temp->key == key){
            whichOne++;
                if(whichOne == which){
                    return temp->info;
                }
        }
    temp = temp->next;
    }
    throw invalid_argument("There is less object with that key than your parameter or object with that key not exist!");

}

//operations
template<typename Key, typename Info>
Sequence<Key, Info> Sequence<Key, Info>::merge(const Sequence<Key, Info> seq) const {
    Sequence<Key, Info> returnSeq(*this);

    Node *current = seq.head;
    while(current){
        returnSeq.pushBack(current->key, current->info);
        current = current->next;
    }
    return returnSeq;
}


#endif // SEQUENCE_H
