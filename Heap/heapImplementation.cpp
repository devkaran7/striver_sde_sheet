class MinHeap{
private:
    vector<int> array;
    int size;
public:
    MinHeap(){
        array.push_back(0);
        size = 0;
    }
    void push(int x){
        array.push_back(x);
        size++;
        int index = size;
        while(index != 1){
            int parent = index/2;
            if(array[index] < array[parent]){
                swap(array[index], array[parent]);
            }
            index = parent;
        }
    }
    bool empty(){
        return (size == 0);
    }
    int top(){
        if(size >= 1){
            return array[1];
        }
        return INT_MIN;
    }
    void pop(){
        if(size == 0){
            return;
        }
        swap(array[1], array[size]);
        array.pop_back();
        size--;
        int index = 1;
        while(index <= size){
            int leftChild = (2 * index > size) ? INT_MAX : array[2*index];
            int rightChild = (2 * index + 1 > size) ? INT_MAX : array[2*index+1];
            int mini = min(leftChild, rightChild);
            if(array[index] <= mini){
                break;
            }else{
                if(mini == leftChild){
                    swap(array[index], array[2*index]);
                    index = 2 * index;
                }else{
                    swap(array[index], array[2*index + 1]);
                    index = 2 * index + 1;
                }
            }
        }
    }
    int getSize(){
        return size;
    }
};
