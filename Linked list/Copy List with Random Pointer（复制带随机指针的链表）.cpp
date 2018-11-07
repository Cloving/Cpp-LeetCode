/**
 * Definition for singly-linked list with a random pointer.
 * struct RandomListNode {
 *     int label;
 *     RandomListNode *next, *random;
 *     RandomListNode(int x) : label(x), next(NULL), random(NULL) {}
 * };
 */

/* 第一种 */
class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (head == NULL) {
      return NULL;
    }
    RandomListNode *res = new RandomListNode(head->label);
    RandomListNode *node = res;
    RandomListNode *cur = head->next;
    unordered_map<RandomListNode*, RandomListNode*> m;
    m[head] = res;
    while (cur != NULL) {
      RandomListNode* temp = new RandomListNode(cur->label);
      node->next = temp;
      m[cur] = temp;
      node = node->next;
      cur = cur->next;
    }
    node = res;
    cur = head;
    while (node != NULL) {
      node->random = m[cur->random];
      node = node->next;
      cur = cur->next;
    }
    return res;
  }
};

/* 第二种 */
class Solution {
public:
  RandomListNode *copyRandomList(RandomListNode *head) {
    if (head == NULL) {
      return NULL;
    }
    /* 在链表每个节点后面复制结点（不包括random指针，默认为空） */
    RandomListNode* cur = head;
    while (cur != NULL) {
      RandomListNode* node = new RandomListNode(cur->label);
      node->next = cur->next;
      cur->next = node;
      cur = node->next;
    }
    /* 为每个复制的结点添加random指针 */
    cur = head;
    while (cur != NULL) {
      if (cur->random) {
        cur->next->random = cur->random->next;
      }
      cur = cur->next->next;
    }
    /* 断开链表 */
    cur = head;
    RandomListNode* res = cur->next;
    while (cur != NULL) {
      RandomListNode* temp = cur->next;
      cur->next = temp->next;
      if (temp->next) {
        temp->next = temp->next->next;
      }
      cur = cur->next;
    }
    return res;
  }
};