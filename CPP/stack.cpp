#include <iostream>

class stack_t{

    public:

        stack_t(){
            head = NULL;
        }

        void push(int val){

            stack_t *s = new stack_t;
            s->value = val;
            s->next = head;
            
            head = s;
            
            if(head ==NULL){
                throw "Could not push value\n";
            }

        };

        float top(){

            return head->value;

        };  

        void pop(){

            stack_t *temp;

            if(head == NULL){

                throw "List is already empty\n";

            }

            temp = head;
            head = head->next;

            delete temp;

        }

        void print_stack(){

            stack_t *temp = head; 

            while(temp != NULL){

                std::cout<<"Value: "<< temp->value << std::endl;

                temp = temp->next;

            }     

        }

    private:
        
        int value;
        stack_t* next;
        
        stack_t *head = NULL;
};


int main(){

    stack_t  entitiy;

    try{
        
        entitiy.push(1);
        entitiy.push(2);
        entitiy.push(3);


        entitiy.print_stack();

        entitiy.pop();

        entitiy.print_stack();

    }

    catch(char const *e)
    {
        std::cerr << e << '\n';
    }
    
    
   
    

    printf("Hello World\n");

    return 0;

}
