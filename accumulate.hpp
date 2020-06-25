
//
// Created by nati on 08/06/2020.
//

#ifndef CPPEX5_ITERTOOLS_ACCUMULATE_HPP
#define CPPEX5_ITERTOOLS_ACCUMULATE_HPP
namespace itertools{
    typedef struct{
        template <typename T>
        T operator ()(T a, T b) const{
            return a+b;
        }
    } plus;

    template <typename CONT, typename  FUNC = plus>
    class accumulate{
        CONT _container;
        FUNC _function;
        typedef typename CONT::value_type value_type;
    public:
        explicit accumulate(CONT container, FUNC func = plus())
                : _container(container), _function(func){}

        class iterator{
            typename CONT::value_type _data;
            typename CONT::iterator _iter;
            typename CONT::iterator _end;
            FUNC _function;
        public:
            explicit iterator(typename CONT::iterator iter, typename CONT::iterator end, FUNC func)
                    : _iter(iter), _end(end), _function(func){
                if(_iter != _end)
                    _data = *iter;
            };
            iterator(const iterator& other) = default;
            iterator& operator=(const iterator& other){
                if(this != &other) {
                    this->_data = other._data;
                    this->_iter = other._iter;
                    this->_end = other._end;
                    this->_function = other._function;
                }
                return *this;
            };
            iterator& operator ++(){
                ++_iter;
                if(_iter != _end) // TODO irrelevant?
                    _data = _function(_data, *_iter);
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

            auto operator *(){
                return _data;
            }
        };


        iterator begin(){
            return iterator(_container.begin(), _container.end(), _function);
        }
        iterator end(){
            return iterator(_container.end(), _container.end(), _function);
        }

    };
}

#endif //CPPEX5_ITERTOOLS_ACCUMULATE_HPP