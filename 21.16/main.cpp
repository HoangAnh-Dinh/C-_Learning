#include <iostream>

struct Node {
  int x;
  Node* next;
};

// ====== MemoryPool đơn giản ======
struct MemoryPool {
  // con trỏ tới block trống đầu tiên
  Node* freeList;

  // vùng nhớ thô (mảng Node)
  Node* pool;

  // tổng số block
  int size;

  MemoryPool(int n) : size(n) {
    pool = new Node[n]; 

    // Tạo free list: pool[0] -> pool[1] -> ... -> pool[n-1]
    freeList = &pool[0];
    for (int i = 0; i < n - 1; i++)
      pool[i].next = &pool[i + 1];

    pool[n - 1].next = nullptr;
  }

  ~MemoryPool() {
    delete[] pool;
  }

  // Lấy 1 block
  void* allocate() {
    if (!freeList) return nullptr;    // hết block
    Node* p = freeList;         // lấy block đầu
    freeList = freeList->next;      // freeList trỏ sang block tiếp theo
    return p;              // trả vùng nhớ cho placement-new
  }

  // Trả block về free list
  void deallocate(void* ptr) {
    Node* p = (Node*)ptr;
    p->next = freeList;         // block này sẽ là đầu free list
    freeList = p;
  }
};
// ==================================


int main() {
  MemoryPool pool(3);  // pool chứa 3 block Node

  // tạo object dùng placement-new
  Node* a = new (pool.allocate()) Node{10, nullptr};
  Node* b = new (pool.allocate()) Node{20, nullptr};

  std::cout << a->x << ", " << b->x << "\n";

  // hủy object nhưng không giải phóng memory
  a->~Node();
  b->~Node();

  // trả block về pool
  pool.deallocate(a);
  pool.deallocate(b);

  return 0;
}