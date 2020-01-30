// lang: Cpp

#include "object.h"
#include "queue.h"
#include "string.h"

#include <iostream>


void FAIL() {
    exit(1);
}

void OK(const char* test_num) {
    std::cout << "Test " << test_num << "passed.\n";
}

void t_true(bool p) {
    if (!p) {
        FAIL();
    }
}

void t_false(bool p) {
    if (p) {
        FAIL();
    }
}

/**
 * Tests for String
 */
void test1() {
    String* a = new String("a");
    String* a1 = new String("a");
    String* b = new String("b");
    String* c = a->concat(b);
    // equals
    t_true(a->equals(a));
    t_true(a->equals(a1));
    t_false(a->equals(b));
    t_false(a->equals(c));
    // hash
    t_true(a->hash() == a1->hash());
    t_false(a->hash() == b->hash());
    t_false(a->hash() == c->hash());
    //compare
    t_true(a->compare(a) == 0);
    t_true(a->compare(a1) == 0);
    t_true(a->compare(b) < 0);
    t_true(b->compare(a) > 0);
    // size
    t_true(a->size() == 1);
    t_true(a1->size() == 1);
    t_true(b->size() == 1);
    t_true(c->size() == 2);

    OK("1");
}

/**
 * Tests for Queue of String
 */
void test2() {
    String* a = new String("a");
    String* a1 = new String("a");
    String* b = new String("b");
    String* c = new String("c");

    Queue* q = new Queue();
    Queue* q1 = new Queue();

    // no elements
    t_true(q->size() == 0);
    t_true(q1->size() == 0);
    t_true(q->equals(q1));
    t_true(q->hash() == q1->hash());
    t_true(q->peek() == nullptr);
    t_true(q1->peek() == nullptr);

    t_true(q->dequeue() == nullptr);
    t_true(q1->dequeue() == nullptr);

    q->remove_all();
    q1->remove_all();
    t_true(q->size() == 0);
    t_true(q1->size() == 0);
    t_true(q->equals(q1));
    t_true(q->hash() == q1->hash());
    t_true(q->peek() == nullptr);
    t_true(q1->peek() == nullptr);

    q->enqueue(a);
    q1->enqueue(a1);
    // with q = ["a"] and q1 = ["a"]
    t_true(q->size() == 1);
    t_true(q1->size() == 1);
    t_true(q->equals(q1));
    t_true(q->hash() == q1->hash());
    t_true(q->peek() == a);
    t_true(q1->peek() == a1);

    q->enqueue(b);
    q1->enqueue(c);
    // with q = ["a", "b"] and q1 = ["a", "c"]
    t_true(q->size() == 2);
    t_true(q1->size() == 2);
    t_false(q->equals(q1));
    t_false(q->hash() == q1->hash());
    t_true(q->peek() == a);
    t_true(q1->peek() == a1);

    t_true(q->dequeue() == a);
    t_true(q1->dequeue() == a1);
    // with q = ["b"] and q1 = ["c"]
    t_true(q->size() == 1);
    t_true(q1->size() == 1);
    t_false(q->equals(q1));
    t_false(q->hash() == q1->hash());
    t_true(q->peek() == b);
    t_true(q1->peek() == c);

    q->remove_all();
    q1->remove_all();
    // with no elements
    t_true(q->size() == 0);
    t_true(q1->size() == 0);
    t_true(q->equals(q1));
    t_true(q->hash() == q1->hash());
    t_true(q->peek() == nullptr);
    t_true(q1->peek() == nullptr);

    t_true(q->dequeue() == nullptr);
    t_true(q1->dequeue() == nullptr);

    OK("2");
}

/**
 * Tests for Queue of Queue
 */
void test3() {
    Queue* outer = new Queue();
    Queue* inner1 = new Queue();
    Queue* inner2 = new Queue();

    t_true(outer->size() == 0);
    t_true(outer->peek() == nullptr);
    t_true(outer->dequeue() == nullptr);

    outer->remove_all();
    t_true(outer->size() == 0);
    t_true(outer->peek() == nullptr);
    t_true(outer->dequeue() == nullptr);

    outer->enqueue(inner1);
    t_true(outer->size() == 1);
    t_true(outer->peek() == inner1);

    outer->enqueue(inner2);
    t_true(outer->size() == 2);
    t_true(outer->peek() == inner1);

    t_true(outer->dequeue() == inner1);
    t_true(outer->size() == 1);
    t_true(outer->peek() == inner2);

    outer->remove_all();
    t_true(outer->size() == 0);
    t_true(outer->peek() == nullptr);
    t_true(outer->dequeue() == nullptr);  

    OK("3");
}

/**
 * Tests for Queue of Object
 */
void test4() {
    Queue* q = new Queue();
    Object* o1 = new Object();
    Object* o2 = new Object();

    t_true(q->size() == 0);
    t_true(q->peek() == nullptr);
    t_true(q->dequeue() == nullptr);

    q->remove_all();
    t_true(q->size() == 0);
    t_true(q->peek() == nullptr);
    t_true(q->dequeue() == nullptr);

    q->enqueue(o1);
    t_true(q->size() == 1);
    t_true(q->peek() == o1);

    q->enqueue(o2);
    t_true(q->size() == 2);
    t_true(q->peek() == o1);

    t_true(q->dequeue() == o1);
    t_true(q->size() == 1);
    t_true(q->peek() == o2);

    q->remove_all();
    t_true(q->size() == 0);
    t_true(q->peek() == nullptr);
    t_true(q->dequeue() == nullptr);  

    OK("4");
}


int main() {
    test1();
    test2();
    test3();
    test4();
    return 0;
}

