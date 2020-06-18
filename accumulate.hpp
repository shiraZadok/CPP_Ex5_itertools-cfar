//
// Created by shira on 18/06/2020.
//

#pragma once
#include <iostream>
#include <vector>
#include <iterator>

namespace itertools {
    typedef struct {
        template <typename T>
        auto operator()(const T& x , const T& y) const{
            return x+y;
        }

    }add;

    template<class T,class FUNC = add>
    class accumulate {
        const  T& tank;
        const FUNC& function;
    public:

        accumulate(const T& con, const FUNC& f= add() ) : tank(con),function(f){}

        class iterator{
            decltype(tank.begin()) iter;
            typename std::decay<decltype(*(tank.begin()))>::type sum;
            const accumulate& acc;


        public:
            iterator(decltype(tank.begin()) curr,const accumulate& acc): iter(curr),acc(acc) {
                if (curr != acc.tank.end())sum = *curr;
            }

            iterator& operator++(){
                ++iter;
                if(iter==acc.tank.end())return *this;
                sum=acc.function(sum,*iter);
                return *this;
            }

            const iterator operator++(int){
                iterator temp = *this;
                sum=acc.function(sum,*(iter++));
                return temp;
            }

            bool operator==(const iterator &it) const {
                return iter==it.iter;
            }

            bool operator!=(const iterator &it) const {
                return !(iter==it.iter);
            }

            auto operator*(){
                return sum;
            }

            iterator& operator=(const iterator &temp_iter)
            {
                return *this;
            }

        };

        iterator begin() const {
            return iterator(tank.begin(),*this);

        }
        iterator end() const {
            return iterator(tank.end(),*this);
        }
    };

}