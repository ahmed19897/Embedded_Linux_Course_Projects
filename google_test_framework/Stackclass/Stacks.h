#ifndef STACKS_H
#define STACKS_H

    #include "List.h"

    template < typename STACKTYPE>
    class Stacks:private List<STACKTYPE>
    {
        public:
            // push calls the List function insertAtFront 
            void push(const STACKTYPE &data)
            {
                //VIP using just insertAtFront call didn't work ,using this worked
                this->insertAtFront(data);
            } // end function push

            // pop calls the List function removeFromFront 
            bool pop( STACKTYPE &data)
            {
                return this->removeFromFront(data );
            } // end function pop

            // isStackEmpty calls the List function isEmpty 
            bool isStackEmpty() const
            {
                return this->isEmpty();
            } // end function isStackEmpty

            // printStack calls the List function print 
            void printStack() const
            {
                this->print();
            } // end function print
            
            STACKTYPE Top(void)
            {
                return this->ListTop();
            }

    }; // end class Stack
#endif