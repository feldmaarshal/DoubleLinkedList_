#include "List.hpp"


// конструкторы
List::List(){
    head = NULL;
    tail = NULL;
    size = 0;
}
// Декструкторы
List::~List(){
    while (head != NULL){
        pop_front();
    }
}
// Методы
void List::push_front(const Circle* other){
    Node* ptr = new Node(other);
    ptr->pNext = head;
    
    if (head != NULL){
        head->pPrev = ptr;
    }
    if (tail == NULL){
        tail = ptr;
    }
    
    head = ptr;
    size++;
}

void List::push_back(const Circle* other){
    Node* ptr = new Node(other);
    ptr->pPrev = tail;
    
    if (tail != NULL){
        tail->pNext = ptr;
    }
    if (head == NULL){
        head = ptr;
    }
    
    tail = ptr;
    size++;
}

Node* List::getAt(int index){
    Node* ptr = head;
    int n = 0;
    
    while (n != index){
        if (ptr == NULL){return ptr;}
        ptr = ptr->pNext;
        n++;
    }
    return ptr;
}

void List::insert(int index, const Circle* other){
    Node* right = getAt(index);
    if (right == NULL){
        push_back(other);
    }
    Node* left = right->pPrev;
    if (left == NULL) {
        push_front(other);
    }
    
    Node* ptr = new Node(other);
    
    ptr->pNext = right;
    ptr->pPrev = left;
    right->pPrev = ptr;
    left->pNext = ptr;
    
    size++;
}

void List::pop_front(){
    if (head == NULL){return;}
    
    Node* ptr = head->pNext;
    
    if (ptr !=  NULL){
        ptr->pPrev = NULL;
    }
    else{
        tail = NULL;
    }
    delete head;
    head = ptr;
    
    size--;
}

void List::pop_back(){
    if (tail == NULL){return;}
    
    Node* ptr = tail->pPrev;
    if (ptr !=  NULL){
        ptr->pNext = NULL;
    }
    else{
        head = NULL;
    }
    delete tail;
    tail = ptr;
    
    size--;
}

void List::erase(Node* ptr){
    if (ptr == NULL){return;}
    if (ptr->pPrev == NULL){
        pop_front();
        return;
    }
    if(ptr->pNext == NULL){
        pop_back();
        return;
    }

    Node* left = ptr->pPrev;
    Node* right = ptr->pNext;

    left->pNext = right;
    right->pPrev = left;

    size--;
    delete ptr;
}

void List::clear(){
    while(head != NULL){
        pop_front();
    }
    size = 0;
    
}

bool List::if_del(Circle* other){
    int index = 0;
    Node* ptr = head;
    while(ptr != NULL){
        if (ptr->m_data == other){
            erase(ptr);
            return true;
        }
        ptr = ptr->pNext;
        index++;
    }
    return false;
}

int List::all_if_del(Circle *other){
    int cnt = 0;
    Node* ptr = head;
    while(ptr != NULL){
        if (ptr->m_data == other){
            erase(ptr);
            cnt++;
        }
    }
    return cnt;
}

void List::sort(){
    bool swapped;
        Node* ptr1 = head;
        Node* lptr = nullptr;
        do {
            swapped = false;
            while (ptr1->pNext != lptr) {
                if (ptr1->m_data > ptr1->pNext->m_data) {
                    Node* temp = ptr1->pNext;
                    ptr1->pNext = temp->pNext;
                    if (temp->pNext != nullptr) {
                        temp->pNext->pPrev = ptr1;
                    }
                    temp->pPrev = ptr1->pPrev;
                    if (ptr1->pPrev != nullptr) {
                        ptr1->pPrev->pNext = temp;
                    } else {
                        head = temp;
                    }
                    ptr1->pPrev = temp;
                    temp->pNext = ptr1;
                    swapped = true;
                } else {
                    ptr1 = ptr1->pNext;
                }
            }
            lptr = ptr1;
            ptr1 = head;
        } while (swapped);
    }

//  Операторы

Node* List::operator[](int index){
    return getAt(index);
}


ostream& operator<<(ostream& file,List& some){
    for (int i = 0; i < some.Get_size(); i++){
        file << "--" << " radius = " << some[i]->m_data.Get_radius() << ", x = " << some[i]->m_data.Get_center().GetX() <<
        ", y = " << some[i]->m_data.Get_center().GetY() << std::endl;
    }
    return file;
}

istream& operator>>(istream& is, List& list){
    std::string line;
    while (std::getline(is, line))
    {
        std::istringstream iss(line);
        std::string word;
        int* ptr = new int[3];
        for (int i = 0; i < 3; i++){
            ptr[i] = -100;
        }
        while (iss >> word) // разбиваем строку на слова
        {
            std::istringstream ss(word);
            int num;
            if (ss >> num) // пытаемся прочитать число из слова
            {
                
                for(int i = 0; i < 3; i++){
                    if (ptr[i] == -100){
                        ptr[i] = num;
                        break;
                    }
                    
                }
                
            }
            
        }
        Circle krug(ptr[0],ptr[1], ptr[2]);
        list.push_front(&krug);
        delete[] ptr;
    }
    return is;
}

