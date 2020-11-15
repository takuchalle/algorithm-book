#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
  Node *next;
  Node *prev;
  string name;

  Node(string name_ = "") : next(NULL), prev(NULL), name(name_) {}
};

Node *nil;

void init() {
  nil = new Node();
  nil->next = nil;
  nil->prev = nil;
}

void printList() {
  Node *cur = nil->next;

  for (; cur != nil; cur = cur->next) {
    cout << cur->name << " -> ";
  }
  cout << endl;
}

void insert(Node *v, Node *p = nil) {
  v->next = p->next;
  p->next->prev = v;
  p->next = v;
  v->prev = p;
}

void erase(Node *v) {
	if(v == nil) return;
	v->prev->next = v->next;
	v->next->prev = v->prev;
	delete v;
}

int main(int argc, char *argv[]) {
  init();

  vector<string> names = {("yamamoto"), ("watanabe"), ("ito"),
                          ("takahashi"), ("suzuki"), ("sato")};

  Node *watanabe;
  for (int n = 0; n < (int)names.size(); n++) {
    Node *node = new Node(names[n]);

    insert(node);

	if(names[n] == "watanabe") watanabe = node;
  }

  cout << "before" << endl;
  printList();
  erase(watanabe);
  cout << "after" << endl;
  printList();
  return 0;
}
