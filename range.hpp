//
// Created by shira on 18/06/2020.
//

#ifndef EX5A_RANGE_HPP
#define EX5A_RANGE_HPP

namespace itertools {
    class range{
        int r_start,r_end;
    public:
        range(int s=0,int e=0):r_start(s),r_end(e){}

    public:
        class iterator {

        private:
            int current_value;

        public:
            iterator(int value = 0): current_value(value) {}

            int operator*(){
                return current_value;
            }

            // ++i;
            iterator& operator++() {
                current_value = current_value+1;
                return *this;
            }

            // i++;
            const iterator operator++(int) {
                iterator tmp= *this;
                current_value= current_value+1;
                return tmp;
            }

            bool operator==(const iterator& rhs) const {
                return current_value == rhs.current_value;
            }

            bool operator!=(const iterator& rhs) const {
                return current_value != rhs.current_value;
            }


        }; // END OF CLASS ITERATOR

        iterator begin() const{
            return iterator(r_start);
        }

        iterator end() const {
            return iterator(r_end);
        }

    };  // END OF CLASS RANGE

}


#endif //EX5A_RANGE_HPP
