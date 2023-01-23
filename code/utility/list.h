#ifndef customList
#define customList

#define NULL 0

template<typename VT> struct listNode{
	listNode<VT> *next, *previous;
	VT value;
};


template<typename VT> class list;
template<typename VT> class listItterator{
	private:
		list<VT> *trackingList;
		listNode<VT> *currentNode;

		void changeTrackingList(list<VT> trackingList){
			this->trackingList = trackingList;
			if (this->trackingList != NULL)
				this->currentNode = this->trackingList->start;
			else
				this->currentNode = NULL;
		}
	public:
		listItterator(list<VT> trackingList= NULL){changeTrackingList(trackingList);}

		VT& operator*(){
			if (this->currentNode != NULL)
				return this->currentNode->value;
			else
				throw "Invalid itterator * operator, NODE IS NULL";
		}

		void operator++(){
			if (this->trackingList != NULL && this->currentNode != NULL && this->currentNode != this->trackingList->end)
				this->currentNode = this->currentNode->next;
		}

		void operator--(){
			if (this->trackingList != NULL && this->currentNode != NULL && this->currentNode != this->trackingList->start)
				this->currentNode = this->currentNode->previous;
		}

		listItterator<VT>& operator=(listItterator<VT>& listItteratorToCopy){
			this->trackingList = listItteratorToCopy.trackingList;
			this->currentNode = listItteratorToCopy.currentNode;
			return *this;
		}
};


template<typename VT> class list {
	protected:
		listNode<VT> *start, *end;
		unsigned int size;
	public:
		friend listItterator<VT>;
};

#endif
