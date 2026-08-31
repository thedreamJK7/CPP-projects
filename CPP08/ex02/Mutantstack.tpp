#ifndef MUTANTSTACK_TPP
#define MUTANTSTACK_TPP

#include "Mutantstack.hpp"

template <typename T> MutantStack<T>::MutantStack(void) { };

template <typename T> MutantStack<T>::MutantStack(MutantStack<T> const &rhs) { 
	(void)rhs;
	return ;
}

template <typename T> MutantStack<T> & MutantStack<T>::operator=(MutantStack<T> const &rhs) {
	(void)rhs;
	return (*this);
}

template <typename T > MutantStack<T>::~MutantStack(void) { }

#endif
