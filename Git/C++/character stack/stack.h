#define STACK_CAPACITY 1000
class Stack
{
private:       
    int topIndex;  
    char stackInput[STACK_CAPACITY];
public:
Stack()
{
    this->topIndex = -1;
}
void push(char c)
{
    if (!isFull())
    {
        topIndex++; //move to next index
        stackInput[topIndex] = c; //input the char
    }
}
char top()
{
    if(topIndex>=0){
       return stackInput[topIndex];
    }
    else
    {
        return 'N';
    }
}
bool isEmpty()
{
    
    if(topIndex > -1)
    {
        return false;
    }
    else return true;
}
bool isFull()
{
    if( topIndex == 999)
    {
        return true;
    }
    else return false;
}
char pop ()
{
    if(!isEmpty())
    {
        char res;
        res = stackInput[topIndex]; 
        topIndex--;
        return res;
    }
    else
    {
        return 'N';
    }
}
 ~Stack() {}
};