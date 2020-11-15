#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Node {
  Node *next;
  string name;

  Node(string name_ = "") : next(NULL), name(name_) {}
};

Node *nil;

void init() {
  nil = new Node();
  nil->next = nil;
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
  p->next = v;
}

int main(int argc, char *argv[]) {
  init();

  vector<string> names = {("yamamoto"), ("watanabe"), ("ito"),
                          ("takahashi"), ("suzuki"), ("sato")};

  for (int n = 0; n < (int)names.size(); n++) {
    Node *node = new Node(names[n]);

    insert(node);

    cout << "Step " << n << ": ";
    printList();
  }

  return 0;
}
