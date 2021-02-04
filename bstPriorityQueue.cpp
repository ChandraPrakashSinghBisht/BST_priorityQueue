#include <iostream>
using namespace std;

//Declare template and class for BST
template<class T>
class BST{

    //Declare the node for the BST
    struct Node{
        T data;
        //Node Pointers
        Node* lChildptr;
        Node* rChildptr;

        Node(T dataNew){ //Constructor to initialize data
            data = dataNew;
            lChildptr = NULL;
            rChildptr = NULL;
        }
    };  //struct node ends here

    private:
        //Declare root node pointer
        Node* root; 

        //Function to insert into the BST
        void Insert(T newData, Node* &theRoot){
            //For empty tree
            if(theRoot == NULL)
            {
                theRoot = new Node(newData);
                return;
            }

            //Store either in left or right sub-tree
            if(newData < theRoot->data)
                Insert(newData, theRoot->lChildptr);
            else
                Insert(newData, theRoot->rChildptr);;
        }

        //Function to Print the BST
        void PrintTree(Node* p){
            if(p != NULL){
                if(p->rChildptr) 
                    PrintTree(p->rChildptr);

                cout<<" "<<p->data<<" ";

                if(p->lChildptr) 
                    PrintTree(p->lChildptr);
	        }
	        else
                cout<<"\nEmpty BST";
        }

        struct Node* search(Node* root, T key) 
        { 
            // Base Cases: root is null or key is present at root 
            if (root == NULL || root->data == key) 
            return root; 
            
            // Key is greater than root's key 
            if (root->data < key) 
            return search(root->rChildptr, key); 
        
            // Key is smaller than root's key 
            return search(root->lChildptr, key); 
        }

    public:
        BST(){
            root = NULL;
        }

        void AddItem(T newData){
            Insert(newData, root);
        }

        void PrintTree(){
            PrintTree(root);
        }
        
        //search a given key in a given BST 
        bool search(T key) 
        { 
            // Base Cases: root is null or key is present at root 
            if (root == NULL || root->data == key) 
            return true; 
            
            // Key is greater than root's key 
            if (root->data < key) 
            return search(root->rChildptr, key); 
        
            // Key is smaller than root's key 
            return search(root->lChildptr, key); 
        }

        //Pop the highest element
        int pop(){
            int ele;
            Node* prevNode = root;
            Node* traverser = root;
            while(traverser->rChildptr != NULL){
                prevNode = traverser;
                traverser = traverser->rChildptr;
                ele = traverser->data;
            }

            if(traverser->lChildptr != NULL) {
                prevNode->rChildptr = traverser->lChildptr;
            }else {
                prevNode->rChildptr = NULL;
            }
            return ele;
        }

};  //BST body ends here

int main(){
    //Create a BST object 
    BST<int> *myBT = new BST<int>();

    //create a integer var to nput element values
    int data;

    char ch = 'y';
    do{
        cout<<"\n\n***MENU FOR BST OPERATIONS***\n\n";
        cout<<"1. Insert an element\n";
        cout<<"2. Search for an element\n";
        cout<<"3. Pop an element\n";
        cout<<"4. Traverse the BST\n";
        cout<<"5. Exit\n";
        cout<<"Enter your choice: ";
        int choice;
        cin>>choice;

        switch(choice){
            case 1:{
                //input data from user
                cout<<"\nEnter values in the BST";
                cout<<"(-1 to end input):\n";
                cin>>data;
                while(data != -1){
                    //Insert values
                    myBT->AddItem(data);
                    cin>>data; //input more data till -1 is input
                }
                break;
            }
            case 2:{
                cout<<"\nEnter value to be searched for : ";
                int key;
                cin>>key; //input the value to be searched for
                bool var = myBT->search(key);
                if(var){
                    cout<<"\nElement is Present...\n";
                }
                else{
                    cout<<"\nElement Not Found!\n";
                }
                break;
            }
            case 3:{
                cout<<"\nPopped element : "<<myBT->pop();
                break;
            }
            case 4:{
                cout<<"\nBST: ";
                myBT->PrintTree();
                break;
            }
            case 5:{
                cout<<"\nGood Bye have a great time...";
                ch = 'n';
                break;
            }
            default:
                cout<<"Wrong option! Please select again\n";
        }
        
    }while(ch == 'y' || ch == 'Y');
    cout<<"\n";
    return 0;
}
