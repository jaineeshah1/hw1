#include <cstddef>
#include <stdexcept>
#include "ulliststr.h"

ULListStr::ULListStr()
{
    head_ = NULL;
    tail_ = NULL;
    size_ = 0;
}

ULListStr::~ULListStr()
{
    clear();
}

bool ULListStr::empty() const
{
    return size_ == 0;
}

size_t ULListStr::size() const
{
    return size_;
}

// WRITE YOUR CODE HERE

void ULListStr::set(size_t loc, const std::string& val)
{
    std::string* ptr = getValAtLoc(loc);
    if (ptr == NULL) {
        throw std::invalid_argument("Bad location");
    }
    *ptr = val;
}

std::string& ULListStr::get(size_t loc)
{
    std::string* ptr = getValAtLoc(loc);
    if (ptr == NULL) {
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

std::string const& ULListStr::get(size_t loc) const
{
    std::string* ptr = getValAtLoc(loc);
    if (ptr == NULL) {
        throw std::invalid_argument("Bad location");
    }
    return *ptr;
}

void ULListStr::clear()
{
    while (head_ != NULL) {
        Item* temp = head_->next;
        delete head_;
        head_ = temp;
    }
    tail_ = NULL;
    size_ = 0;
}

void ULListStr::push_back(const std::string& val)
{
    if (this->size_ == 0) {
        head_ = new Item();
        head_->val[0] = val;
        head_->first = 0;
        head_->last = 1;
        head_->prev = nullptr;
        head_->next = nullptr;
        tail_ = head_;
    }
    else {
        if (tail_->val[ARRSIZE - 1] != "") {
            tail_->next = new Item();
            tail_->next->val[0] = val;
            tail_->next->first = 0;
            tail_->next->last = 1;
            tail_->next->prev = tail_;
            tail_->next->next = nullptr;

            tail_ = tail_->next;
        }
        else {
            tail_->val[tail_->last] = val;
            tail_->last += 1;
        }
    }
    this->size_ += 1;
}

void ULListStr::push_front(const std::string& val)
{
    if (this->size_ == 0) {
        head_ = new Item();
        head_->val[ARRSIZE - 1] = val;
        head_->first = ARRSIZE - 1;
        head_->last = ARRSIZE;
        head_->prev = nullptr;
        head_->next = nullptr;
        tail_ = head_;
    }
    else {
        if (head_->val[0] != "") {
            head_->prev = new Item();
            head_->prev->val[ARRSIZE - 1] = val;
            head_->prev->first = ARRSIZE - 1;
            head_->prev->last = ARRSIZE;
            head_->prev->prev = nullptr;
            head_->prev->next = head_;
            
            head_ = head_->prev;
        }
        else {
            head_->val[head_->first - 1] = val;
            head_->first -= 1;
        }
    }
    this->size_ += 1;
}

void ULListStr::pop_back() {
    if (this->size_ == 1) {
        clear();
    }
    else {
        tail_->val[tail_->last - 1] = "";
        tail_->last -= 1;

        this->size_ -= 1;

        if (tail_->last == 0) {
            Item* temp = tail_->prev;
            delete tail_;
            tail_ = temp;
            tail_->next = nullptr;
        }
    }
}

void ULListStr::pop_front() {
    if (this->size_ == 0) {
        clear();
    }
    else {
        head_->val[head_->first] = "";
        head_->first += 1;

        this->size_ -= 1;

        if (head_->first == ARRSIZE) {
            Item* temp = head_->next;
            //Item* temp2 = head_->next->next;
            delete head_;
            head_ = temp;
            head_->prev = nullptr;
        }
    }
}

std::string const& ULListStr::back() const {
    return tail_->val[tail_->last - 1];
}

std::string const& ULListStr::front() const {
    return head_->val[head_->first];
}

std::string* ULListStr::getValAtLoc(size_t loc) const {
    Item* temp = head_;
    std::string* s = nullptr;
    unsigned int i = 0;
    while (temp != NULL) {
        for (unsigned int j = temp->first; j < temp->last; j++) {
            if (i == loc) {
                return &(temp->val[j]);
            }
            i += 1;
        }
        temp = temp->next;
    }
    return s;
}