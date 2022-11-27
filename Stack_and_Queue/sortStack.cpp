void sortStack(stack<int> &st)
{
	// Write your code here
    if(st.empty()){
        return;
    }
    int node = st.top();
    st.pop();
    sortStack(st);
    stack<int> temp;
    while(st.empty() == false && st.top() > node){
        temp.push(st.top());
        st.pop();
    }
    st.push(node);
    while(temp.empty() == false){
        st.push(temp.top());
        temp.pop();
    }
}
