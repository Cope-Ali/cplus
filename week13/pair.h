/*****************************************************
 * File: pair.h
 *
 * Purpose: Defines a Pair template class that can hold
 *   two items of arbitrary data types.
 ******************************************************/

#ifndef PAIR_H
#define PAIR_H

// TODO: Fill in this class
// Put all of your method bodies right in this file
template <class T1, class T2>
class Pair
{
  public:
    Pair(T1, T2) {}
    T1 getFirst() const { return t1;}

    void setFirst(const T1 & t1) {}

    T2 getSecond() const {return t2;}

    void setSecond(const T2 &t2) {}

    void display() const {}

  private:
    T1 t1;
    T2 t2;
};

template <class T1, class T2>
void Pair<T1, T2> :: setFirst(const T1 & t1)
{
    this->t1 = t1;
}

template <class T1, class T2>
void Pair<T1, T2> :: setSecond(const T2 &t2) 
{ 
    this->t2 = t2; 
}

template <class T1, class T2>
void Pair<T1, T2> :: display() const
{
    cout << t1 << " - " << t2 << endl;
}

#endif // PAIR_H
