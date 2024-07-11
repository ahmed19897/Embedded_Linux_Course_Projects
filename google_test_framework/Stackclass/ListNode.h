#ifndef LISTNODE_H
#define LISTNODE_H
    // forward declaration of class List required to announce that class 
    // List exists so it can be used in the friend declaration at line 13 
    template<typename NODETYPE > class List;

    template<typename NODETYPE >
    class ListNode
    {
        friend class List< NODETYPE >; // make List a friend
        public:
            explicit ListNode( const NODETYPE &info) // constructor 
            : data(info), nextPtr( nullptr )
            {
            // empty body
            } // end ListNode constructor
            NODETYPE getData() const// return data in node
            {
                return data;
            }
        private:
            NODETYPE data; // data
            ListNode< NODETYPE > *nextPtr; // next node in list
    }; // end class ListNode
#endif
