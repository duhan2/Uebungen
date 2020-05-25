#include <iostream>

class heap_t{

    public:

        heap_t()
        {
            head = NULL;
        }

        void insert(int val)
        {

            heap_t *s = new heap_t;
            s->value = val;
            s->next = NULL;
                        
            if(head ==NULL)
            {
                s->next = head;
                head = s;
                size +=1;
                return;
            }

            heap_t* temp = head;

            while(temp != NULL)
            {
                if(temp->next == NULL)
                {
                    break;
                }
                temp = temp->next;
            }

            s->next = temp->next;
            temp->next = s;
            
            if(s->next != NULL)
            {
                std::cout << "Next value" << s->next->value <<std::endl;
            }
            

            size +=1;

        };

        void extractmin()
        {

            heap_t *temp;

            if(head == NULL)
            {
                throw "Liste ist leer\n";
                return;

            }

            temp = head;
            
            head = temp->next;

            delete temp;

        }

        void print_heap()
        {

            heap_t *temp = head; 

            while(temp != NULL)
            {

                std::cout<<"Value: "<< temp->value << std::endl;

                temp = temp->next;

            }     

        }

        int returnsize()
        {
            return size;
        }

    private:
        int size = 0;
        int value;
        heap_t* next;
        
        heap_t *head = NULL;
};


int main(){

    heap_t entitiy;

    try{
        
        entitiy.insert(1);
        entitiy.insert(2);
        entitiy.insert(3);

        //std::cout<<"size:"<<entitiy.returnsize()<<std::endl;

        entitiy.print_heap();

        entitiy.extractmin();

        entitiy.print_heap();

    }

    catch(char const *e)
    {
        std::cerr << e << '\n';
    }
    
    
    printf("Hello World\n");

    return 0;

}
