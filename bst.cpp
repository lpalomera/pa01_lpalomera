
// bst.cpp
// Lorenzo Palomera 5/5/19

#include "bst.h"

#include <iostream>
using std::cout;

// constructor sets up empty tree
BST::BST() : root(0) { }

// destructor deletes all nodes
BST::~BST() {
    clear(root);
}

// recursive helper for destructor
void BST::clear(Node *n) {
    if (n) {
	clear(n->left);
	clear(n->right);
	delete n;
    }
}

// insert value in tree; return false if duplicate
void BST::bstInsert(string name) {
    // handle special case of empty tree first
    if (!root) {
	root = new Node(name);
	root->word.second=root->word.second+1;
    cout<< root->word.first<< " inserted, count = "<<root->word.second<<endl;
    return;
    }
    // otherwise use recursive helper
    return insert(name, root);
}

// recursive helper for insert (assumes n is never 0)
void BST::insert(string name, Node *n) {
    if (name == n->word.first){
	n->word.second=n->word.second+1;
    //cout<<"insert "<< name<<endl;
    cout<< n->word.first<< " inserted, new count = "<<n->word.second<<endl;
    return;
    }
    //return false;
    if (name.compare(n->word.first)<0) {
	if (n->left)
	    return insert(name, n->left);
	else {
        n->left = new Node(name);
	    n->left->parent = n;
	    n->left->word.second=n->left->word.second+1;
        cout<< n->left->word.first<< " inserted, new count = "<<n->left->word.second<<endl;
        return;
        //return true;
	}
    }
    else {
	if (n->right)
	    return insert(name, n->right);
	else {
	    n->right = new Node(name);
	    n->right->parent = n;
        n->right->word.second=n->right->word.second+1;
        cout<< n->right->word.first<< " inserted, new count = "<<n->right->word.second<<endl;
        return;
        //return true;
        }
    }
}


void BST::bstInsert2(string name){
    // handle special case of empty tree first
    if (!root) {
	root = new Node(name);
	root->word.second=root->word.second+1;
    return;
    }
    // otherwise use recursive helper
    return insert2(name, root);
}


void BST::insert2(string name, Node *n){
    if (name == n->word.first){
	n->word.second=n->word.second+1;
    return;
    }
    //return false;
    if (name.compare(n->word.first)<0) {
	if (n->left)
	    return insert2(name, n->left);
	else {
        n->left = new Node(name);
	    n->left->parent = n;
	    n->left->word.second=n->left->word.second+1;
        return;
        //return true;
	}
    }
    else {
	if (n->right)
	    return insert2(name, n->right);
	else {
	    n->right = new Node(name);
	    n->right->parent = n;
        n->right->word.second=n->right->word.second+1;
        return;
        //return true;
        }
    }
}

// print tree data in-order, with helper
void BST::printInOrder() const {
    printInOrder(root);
}
void BST::printInOrder(Node *n) const {
    if (n){
    printInOrder(n->left);
    cout << n->word.first <<endl;
    printInOrder(n->right);
    }
}



void BST::bstRangeSearch(string begin, string end){
    printRangeSearch(root, begin, end);
    }

void BST::printRangeSearch(Node* n, string begin, string end) const{
    if(n==NULL){
        return;}

    if(n->word.first.compare(begin)>0){
        printRangeSearch(n->left,begin,end);
        }
    if(n->word.first.compare(begin)>=0 && n->word.first.compare(end)<=0){
        cout<<n->word.first<<endl;
        }
    if(n->word.first.compare(end)<0){
        printRangeSearch(n->right,begin,end);
        }

    }

BST::Node* BST::getNodeFor(string name, Node* n) const{
    if(n==NULL){return 0;}
    while(n!=NULL){
        if(n->word.first==name){
           return n;
           }
        if(name.compare(n->word.first)<0){
           return getNodeFor(name,n->left);}
        if(name.compare(n->word.first)>0){
           return getNodeFor(name,n->right);}
           }     
  return NULL;
   }

// returns true if value is in the tree; false if not
void BST::bstSearch(string name) const {
    Node* p1=getNodeFor(name,root);
    if(p1){
        cout<<p1->word.first<<" found, count = "<<p1->word.second<<endl;
        return;
        //return true;
        }
    else{
        cout<<"Not found"<<endl;
        return;
        //return false;
        }
}



// returns the Node containing the predecessor of the given value
BST::Node* BST::getPredecessorNode(string name) const{
    Node* p1 = getNodeFor(name,root);
    Node* p2=NULL;
    Node* p3=NULL;
    if(p1->left!=NULL){
        p1=p1->left;
        while(p1->right!=NULL){
            p1=p1->right;}
            p2=p1;
            return p1;
            }
            if(p1->left==NULL){
                p2=p1->parent;
                while(name.compare(p2->word.first)<0 ){ //fix rn
                    if(p2->parent==NULL){return p3;}
                    p2=p2->parent;}
                    return p2;}
                    return NULL;; // REPLACE THIS NON-SOLUTION
}

// returns the predecessor value of the given value or 0 if there is none
string BST::getPredecessor(string name) const{
   Node* n = root;
   if (n)
   {
       Node* i= getPredecessorNode(name);
        
       if (getPredecessorNode(name)==NULL){
            return "";
       }
       else
           return i->word.first;
   }
   else
   return ""; // REPLACE THIS NON-SOLUTION
}

// returns the Node containing the successor of the given value
BST::Node* BST::getSuccessorNode(string name) const{
    Node* p1 = getNodeFor(name,root);
    Node* p2=NULL;
    Node* p3=NULL;

    if(p1->right!=NULL){
        p1=p1->right;
        while(p1->left!=NULL){p1=p1->left;}
        p2=p1;
        return p1;}
      
    if(p1->right==NULL){
        p2=p1->parent;
        while(name.compare(p2->word.first)>0 ){ //fix rn
            if(p2->parent==NULL){return p3;}
            p2=p2->parent;}
            return p2;}
  return NULL;; // REPLACE THIS NON-SOLUTION
}

// returns the successor value of the given value or 0 if there is none
string BST::getSuccessor(string name) const{
   Node* n = root;
   if (n)
   {
       Node* i= getSuccessorNode(name);
        
       if (getSuccessorNode(name)==NULL){
            return "";
       }
       else
           return i->word.first;
   }
   else
    return ""; // REPLACE THIS NON-SOLUTION
}


// deletes the Node containing the given value from the tree
// returns true if the node exist and was deleted or false if the node does not exist
void BST::bstDelete(string name){
   Node *p1 = getNodeFor(name,root);
   if(p1->word.second !=1){
       p1->word.second=p1->word.second-1;
       //cout<<"delete "<<p1->word.first<<endl;
       cout<<p1->word.first<<" deleted, new count = "<<p1->word.second<<endl;
       return;
       }

   if(p1) {
       Node *p2 = p1->parent; 
       bool R=false;
       if(!p2){
           R=true;} 
           bool b=false;
           if(!R){ 
               b=( (p1->word.first).compare(p2->word.first) >0);//p1->info > p2->info);
               }
               if(!(p1->left) && !(p1->right)){
                   if(R){
                       cout<<root->word.first<<" deleted"<<endl;
                       //cout<<root->word.first<<" deleted, new count = "<<root->word.second<<endl;
                       delete root;
                       root = 0;
                       return;
                       //return true;
                       }
                       if(b){
                           p2->right = 0;
                           }
                           else { 
                               p2->left = 0;
                               }
                               cout<< p1->word.first<<" deleted"<<endl;
                               delete p1;
                               }
                               else if(p1->left && !(p1->right)) {
                                   if(R) {
                                       Node *p3 = p1->right;
                                       p3->parent = 0;
                                       cout<<root->word.first<<" deleted"<<endl;
                                       //cout<<root->word.first<<" deleted, new count = "<<root->word.second<<endl;
                                       delete root;
                                       root = p3;
                                       return;
                                       //return true;               //check this
                                }
                                if(b) { 
                                    p2->right = p1->left;
                                    }
                                    else { 
                                        p2->left = p1->left;
                                        }
                                        p1->left->parent = p1->parent;
                                        cout<< p1->word.first<<" deleted"<<endl; //Maybeeeee
                                        delete p1;
                                        }
                                        else if(!(p1->left) && p1->right) { 
                                            if(R) { 
                                                Node *p3 = p1->right;
                                                p3->parent = 0;
                                                cout<< root->word.first<<" deleted"<<endl;
                                                //cout<<root->word.first<<" deleted, new count = "<<root->word.second<<endl;
                                                delete root;
                                                root = p3;
                                                return;
                                                //return true;             //check this
                                                }
                                                if(b) { 
                                                    p2->right = p1->right;
                                                    }
                                                    else {
                                                        p2->left = p1->right;
                                                        }
                                                        p1->right->parent = p1->parent;
                                                        cout<< p1->word.first<<" deleted"<<endl;
                                                        delete p1;
                                                        }
                                                        else {
                                                            Node *p3 = getSuccessorNode(name);
                                                            string temp = p3->word.first;
                                                            bstDelete(temp);
                                                            p1->word.first = temp;
                                                            }
                                                            return;
                                                            //return true;               //check this
                                                            }
                                                            return;
                                                            //return false;               //check this
                                                            } 
