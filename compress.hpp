//
// Created by shira on 18/06/2020.
//

#ifndef EX5A_COMPRESS_HPP
#define EX5A_COMPRESS_HPP

#pragma once

#include <iostream>
#include <string>
using namespace std;

namespace itertools {
    template<typename cont, typename cont2>
    class compress {
        //private:
        cont container;
        cont2 cont_flags;
    public:
        compress(cont c, cont2 f) : container(c), cont_flags(f) {}

        class iterator {
            typename cont::iterator start_it;
            typename cont::iterator end_it;
            typename cont2::iterator startF_it;
            typename cont2::iterator endF_it;
        public:
            iterator(typename cont::iterator s_it, typename cont::iterator e_it, typename cont2::iterator sF_it,
                     typename cont2::iterator eF_it) :
                    start_it(s_it), end_it(e_it), startF_it(sF_it), endF_it(eF_it) {}

            decltype(*(container.begin())) operator*() {
                if (!(*startF_it))
                    ++(*this);
                return *start_it;
            }

            iterator &operator++() {
                do {
                    ++start_it;
                    ++startF_it;
                }
                while (start_it != end_it && !(*startF_it));
                return *this;
            }

            const iterator operator++(int) {
                iterator tmp = *this;
                ++(*this);
                return tmp;
            }

            bool operator==(const iterator &other) const {
                return (start_it == other.start_it) && (startF_it == other.startF_it);
            }

            bool operator!=(const iterator &other) const {
                return (start_it != other.start_it) || (startF_it != other.startF_it);
            }
        }; // END OF CLASS ITERATOR

        iterator begin() {
            return iterator{container.begin(), container.end(), cont_flags.begin(), cont_flags.end()};
        }

        iterator end() {
            return iterator{container.end(), container.end(), cont_flags.end(), cont_flags.end()};
        }
    };
}

#endif //EX5A_COMPRESS_HPP
