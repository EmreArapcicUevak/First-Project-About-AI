#ifndef customList
#define customList

#ifndef NULL 
#define NULL 0
#endif


template<typename VT> struct listNode{
	listNode<VT> *next = NULL, *previous = NULL;
	VT value;
};


template<typename VT> class list;
template<typename VT> class listItterator{
	private:
		list<VT> *trackingList;
		listNode<VT> *currentNode;

		void changeTrackingList(list<VT>* trackingList){
			this->trackingList = trackingList;
			if (this->trackingList != NULL)
				this->currentNode = this->trackingList->start;
			else
				this->currentNode = NULL;
		}
	public:
		listItterator(list<VT>& trackingList){changeTrackingList(&trackingList);}
		listItterator(list<VT>* trackingList = NULL){changeTrackingList(trackingList);}

		VT& operator*(){
			if (this->currentNode != NULL)
				return this->currentNode->value;
			else
				throw "Invalid itterator * operator, NODE IS NULL";
		}

		void operator++(int){
			if (this->trackingList != NULL && this->currentNode != NULL)
				this->currentNode = this->currentNode->next;
		}

		void operator--(int){
			if (this->trackingList != NULL && this->currentNode != NULL)
				this->currentNode = this->currentNode->previous;
		}

		listItterator<VT>& operator=(listItterator<VT>& listItteratorToCopy){
			this->trackingList = listItteratorToCopy.trackingList;
			this->currentNode = listItteratorToCopy.currentNode;
			return *this;
		}

		listItterator<VT>& operator=(list<VT>& listToCopy){
			this->trackingList = &listToCopy;
			this->currentNode = listToCopy.start;
			return *this;
		}

		bool atFirstElement(){
			if (this->trackingList != NULL)
				return this->currentNode == this->trackingList->start;
			else
				throw "no list is being tracked";
		}

		bool atLastElement(){
			if (this->trackingList != NULL)
				return this->currentNode == this->trackingList->end;
			else
				throw "no list is being tracked";
		}

		void putAtStart() {
			if (this->trackingList != NULL)
				this->currentNode = this->trackingList->start;
		}

		void putAtEnd() {
			if (this->trackingList != NULL)
				this->currentNode = this->trackingList->end;
		}

		bool isOutside() {
			if (this->trackingList != NULL)
				return this->currentNode == NULL;
			else
				throw "Itterator isn't tracking any list, can not be outside!";
		}
};


template<typename VT> class list {
	protected:
		listNode<VT> *start, *end;
		unsigned int size;

		listNode<VT> *getNode(unsigned int index){
			listNode<VT> *returningNode = start;

			for (unsigned int i = 0; i < index; i++, returningNode = returningNode->next);
			return returningNode;
		}
	public:
		friend listItterator<VT>;

		void add(VT value, unsigned int index = 0){
			if (index > this->size)
				throw "Invalid Index, index can't be bigger then size";
			else if (start == NULL){
				end = start = new listNode<VT>;
				start->value = value;
			} else if (index == 0) {
				listNode<VT> *oldStart = start;
				start = new listNode<VT>;

				oldStart->previous = start;
				start->next = oldStart;

				start->value = value;
			} else if (index == size) {
				listNode<VT> *oldEnd = end;
				end = new listNode<VT>;

				oldEnd->next = end;
				end->previous = oldEnd;

				end->value = value;
			} else {
				listNode<VT> *selectedNode = getNode(index), *newNode = new listNode<VT>;
				newNode->value = value;

				selectedNode->previous->next = newNode;
				newNode->previous = selectedNode->previous;


				newNode->next = selectedNode;
				selectedNode->previous = newNode;
			}

			this->size++;
		}

		void remove(unsigned int index = 0){
			if (index > this->size)
				throw "Invalid index, index must be <= size";

			listNode<VT> *selectedNode = getNode(index);

			if (selectedNode == this->start)
				this->start = selectedNode->next;

			if (selectedNode == this->end)
				this->end = selectedNode->previous;

			if (selectedNode->next != NULL)
				selectedNode->next->previous = selectedNode->previous;

			if (selectedNode->previous != NULL)
				selectedNode->previous->next = selectedNode->next;

			delete selectedNode;
			this->size--;
		}

		list(VT* arr = NULL, unsigned int size = 0){
			start = end = NULL;
			this->size = 0;

			if (arr != NULL)
				for (unsigned int i = 0; i < size; i++)
					add(*(arr + i),this->size);
		}

		list(list<VT>& listToCopy){
			start = end = NULL;
			this->size = 0;
		
			for (listItterator<VT> i(listToCopy); !i.isOutside(); i++)
				add(*i, this->size);
		}

		~list(){
			while(this->size > 0)
				remove();
		}

		unsigned int getSize() { return this->size;}

		list<VT>& operator=(list<VT>& listToCopy){

			while(this->size > 0)
				remove();

			for (listItterator<VT> i(listToCopy); !i.isOutside(); i++)
				add(*i, this->size);

			return *this;
		}

		VT& operator[](unsigned int index){
			if (index >= this->size)
				throw "Invalid index, can't grab the value (operator [])";
				
			return getNode(index)->value; 
		}
};

#endif
