//
// Created by nati on 08/06/2020.
//

#ifndef CPPEX5_ITERTOOLS_COMPRESS_HPP
#define CPPEX5_ITERTOOLS_COMPRESS_HPP

#include <iostream>
#include <vector>

namespace itertools{
    template<typename CONT1, typename CONT2>
    class compress {
        CONT1 _container;
        CONT2 _bool_container;
        typedef typename CONT1::value_type value_type;

    public:
        compress(CONT1 cont, CONT2 bool_cont): _container(cont), _bool_container(bool_cont){}

        class iterator{
            typename CONT1::iterator _iter;
            typename CONT1::iterator _end;
            typename CONT2::iterator _bool_iter;
        public:
            explicit iterator(typename CONT1::iterator iter, typename CONT1::iterator end, typename CONT2::iterator bool_iter)
                : _iter(iter), _end(end), _bool_iter(bool_iter){
                while (_iter != _end && !(*_bool_iter)){
                    ++_iter;
                    ++_bool_iter;
                }
            }
            iterator(const iterator& other) = default;

            iterator& operator=(const iterator& other){
                if(this != &other){
                    this->_iter = other._iter;
                }
                return *this;
            };
            iterator& operator ++(){
                do{
                    ++_iter;
                    ++_bool_iter;
                } while (_iter != _end && !(*_bool_iter));
                return *this;
            }
            iterator operator ++(int){
                iterator tmp = *this;
                ++(*this);
                return tmp;
            }
            bool operator ==(const iterator& other) {
                return (_iter == other._iter);
            }
            bool operator !=(const iterator& other) {
                return (_iter != other._iter);
            }
            value_type operator *(){
                return *_iter;
            }

        };
        iterator begin(){
            return iterator(_container.begin(), _container.end(), _bool_container.begin());
        }
        iterator end(){
            return iterator(_container.end(), _container.end(), _bool_container.end());
        }
    };
}


#endif //CPPEX5_ITERTOOLS_COMPRESS_HPP
