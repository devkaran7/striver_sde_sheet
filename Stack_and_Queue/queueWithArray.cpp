class Queue {
private:
    int *arr;
    int capacity;
    int frt, rear;
public:
    Queue() {
        // Implement the Constructor
        arr = new int[1];
        capacity = 1;
        frt = -1;
        rear = 0;
    }

    /*----------------- Public Functions of Queue -----------------*/

    bool isEmpty() {
        // Implement the isEmpty() function
        return (frt + 1 == rear);
    }

    void enqueue(int data) {
        // Implement the enqueue() function
        if(rear == capacity){
            int new_capacity = 2 * capacity;
            int *temp = new int[new_capacity];
            for(int i = 0; i < capacity; i++){
                temp[i] = arr[i];
            }
            arr = temp;
            capacity = new_capacity;
        }
        arr[rear] = data;
        rear++;
    }

    int dequeue() {
        // Implement the dequeue() function
        if(frt + 1 == rear){
            return -1;
        }
        frt++;
        return arr[frt];
    }

    int front() {
        // Implement the front() function
        if(frt + 1 == rear){
            return -1;
        }
        return arr[frt + 1];
    }
};
