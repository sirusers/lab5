// Copyright 2021 siruser agamesok@gmail.com

#ifndef INCLUDE_EXAMPLE_HPP_
#define INCLUDE_EXAMPLE_HPP_
#include <iostream>

auto example() -> void;
template <typename T>
class Stack {
 private:
  struct Node
  {
    T field;
    struct Node *next;
  };
  Node * node;
  T * mass;

  void push(T&& value);
  void push(const T& value);
  void pop();
  const T& head() const;
  template <typename ... Args>
  void push_emplace(Args&&... value);
  Stack(const Stack& st) = delete;
  Stack& operator=(const Stack& st) = delete;
  Stack(Stack&& st);
  Stack& operator=(Stack&& st) noexcept;

 public:
  Stack() {
    mass = new T[10];
    node = new Node;
  }
};

template <typename T>
void Stack<T>::push(T&& value)
{
  node->field=std::move(value);
  node->next=std::move(node);
}
template <typename T>
void Stack<T>::push(const T& value){
  node->field= value;
  node->next= node;
}

template <typename T>
void Stack<T>::pop(){
  Node* a;
  if (node != NULL) {
    a = node;
    node = a->next;
    return a->value;
  } else {
    throw "Stack is empty!";
  }
}

template <typename T>
const T& Stack<T>::head() const{
  return node->value;
}
template <typename T>
template <typename ... Args>
void Stack<T>::push_emplace(Args&&... value)
{
  node->field= T(std::forward<Args>(value)...);
  node->next=node;
}
#endif // INCLUDE_EXAMPLE_HPP_
