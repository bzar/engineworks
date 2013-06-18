#ifndef INTERFACEMAP_H
#define INTERFACEMAP_H

#include <unordered_map>
#include <unordered_set>
#include <typeinfo>

class InterfaceMap
{
public:

  InterfaceMap() = default;
  InterfaceMap(InterfaceMap const& other) = delete;
  InterfaceMap& operator=(InterfaceMap const& other) = delete;

  template<typename T>
  void set(T* t) { items[typeid(T).hash_code()] = t; }

  template<typename T>
  void remove() { items.erase(typeid(T).hash_code()); }

  template<typename T>
  T* get() { return static_cast<T*>(items[typeid(T).hash_code()]); }

private:
  std::unordered_map<int, void*> items;
};

class InterfaceMultimap
{
public:
  template<typename T>
  class IterableProxy
  {
  public:
    typedef T value_type;
    typedef T* pointer;
    typedef const T* const_pointer;
    typedef T& reference;
    typedef const T& const_reference;
    typedef size_t size_type;
    typedef std::unordered_set<void*>::difference_type difference_type;

    class iterator
    {
    public:
      typedef std::forward_iterator_tag iterator_type;
      typedef IterableProxy::value_type value_type;
      typedef IterableProxy::pointer pointer;
      typedef IterableProxy::const_pointer const_pointer;
      typedef IterableProxy::reference reference;
      typedef IterableProxy::const_reference const_reference;
      typedef IterableProxy::size_type size_type;
      typedef IterableProxy::difference_type difference_type;

      iterator(std::unordered_set<void*>::iterator i) : i(i) {}
      iterator() : i() {}
      iterator(iterator const& other) = default;
      iterator& operator=(iterator const& other) = default;

      bool operator==(iterator const& other) { return i == other.i; }
      bool operator!=(iterator const& other) { return i != other.i; }

      T& operator*() { return t = static_cast<T>(*i); }
      T* operator->() { return &(operator*()); }

      iterator& operator++() { ++i; return *this; }
      iterator operator++(int c) { return iterator(i.operator++(c)); }
    private:
      T t;
      std::unordered_set<void*>::iterator i;
    };

    IterableProxy(std::unordered_set<void*>* p) : p(p) {}
    iterator begin() { return iterator(p->begin()); }
    iterator end() { return iterator(p->end()); }

  private:
      std::unordered_set<void*>* p;
  };


  InterfaceMultimap() = default;
  InterfaceMultimap(InterfaceMultimap const& other) = delete;
  InterfaceMultimap& operator=(InterfaceMultimap const& other) = delete;

  template<typename T>
  void insert(T* t) { items[typeid(T).hash_code()].insert(t); }

  template<typename T>
  void remove(T* t) { items[typeid(T).hash_code()].erase(t); }

  template<typename T>
  void clear() { items[typeid(T).hash_code()].clear(); }

  template<typename T>
  IterableProxy<T*> get() { return IterableProxy<T*>(&items[typeid(T).hash_code()]); }

private:
  std::unordered_map<int, std::unordered_set<void*>> items;
};

#endif // INTERFACEMAP_H
