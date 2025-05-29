#include <iostream>

using namespace std;

class Node{
    public:
        int data;
        Node* next;
        Node (int val){
            data = val;
            next=NULL;
        }
};

class SortedLinkedList{
    private:
        Node* head;


    public:
        SortedLinkedList(){
            head = NULL;
        }

        void insert(int value){
            Node* newNode = new Node (value);

             if (head==NULL || value < head->data){
                newNode->next = head;
                head=newNode;
                return;
            }
            else{
                Node* current=head;
                while(current!=NULL){

                    if(value>=current->data &&( current->next == NULL || value < current->next->data  )){
                            newNode->next=current->next;
                            current->next = newNode;
                            return;

                    }

                    current = current -> next;
                }
            }
        }

        void remove(int index) {

            if (head == NULL) {
                cout << "List is empty!" << endl;
                return;
            }

            Node* current = head;

            if (index == 0) {
                head = head->next;
                delete current;
                return;
            }

            Node* prev = head;
            current = current->next;
            int count = 1;

            while (count < index && current != NULL) {
                prev = current;
                current = current->next;
                count++;
            }

            if (current == NULL) {
                return;
            }

            prev->next = current->next;
            delete current;
        }



        friend ostream& operator<<(ostream& stream, const SortedLinkedList& list) {
            Node* current = list.head;
            while (current != NULL) {
                stream << current->data;
                if (current->next != NULL) {
                    stream << " -> ";
                }
                current = current->next;
            }
            return stream;
        }

        int& operator[](int index) {
            Node* current = head;
            int count = 0;

            while (current != NULL) {
                if (count == index) {
                    return current->data;
                }
                current = current->next;
                count++;
            }

           throw out_of_range("Index " +to_string(index)+" out of range");
        }


       void display() {
            cout << *this << endl;
        }


         ~SortedLinkedList(){
             Node* c =head;
             while (c!=NULL){
                c=head->next;
                delete head;
                head=c;
             }
             head=NULL;
         }

};

int main()
{
    SortedLinkedList List;
    List.insert(1);
    List.insert(3);
    List.insert(2);
    List.insert(5);
    cout << "List after inset some elements:\n";
    List.display();
    cout << "try to display number using index:\n";
    int index ;
    cin >> index ;
    try{
       cout <<List[index] << endl ;
    }
    catch (const out_of_range& e) {
       cout << e.what() << endl;


    }
     cout << "Delete first element\n";
    List.remove(0);
    cout << "List after deletion:\n";
    List.display();
    cout<< "Delete third element\n";
    List.remove(2);
    cout << "List after deletion:\n";
    List.display();
    cout << "Delete first element again\n";
    List.remove(0);
    cout << "List after deletion:\n";
    List.display();



    return 0;
}
