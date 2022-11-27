class Stack {
    vector<int> arr;
    int capacity;
    int ptr;
public:
    
    Stack(int capacity) {
        // Write your code here.
        this->capacity = capacity;
        arr.resize(capacity);
        ptr = -1;
    }

    void push(int num) {
        // Write your code here.
        if(ptr + 1 < capacity){
            ptr++;
            arr[ptr] = num;
        }
    }

    int pop() {
        // Write your code here.
        if(ptr == -1){
            return -1;
        }
        int topElement = arr[ptr];
        ptr--;
        return topElement;
    }
    
    int top() {
        // Write your code here.
        if(ptr == -1){
            return -1;
        }
        return arr[ptr];
    }
    
    int isEmpty() {
        // Write your code here.
        return (ptr == -1);
    }
    
    int isFull() {
        // Write your code here.
        return (ptr + 1 == capacity);
    }
    
};
