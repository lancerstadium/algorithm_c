/**
 * @file c6_2.c
 * @author your name (you@domain.com)
 * @brief 0-1背包问题
 * @version 0.1
 * @date 2023-12-28
 * @attention
 * 操作系统：Linux  \n
 * 编译器：GCC     \n
 * C标准：C11     \n
 * @copyright Copyright (c) 2023
 * 
 * # 0-1背包问题：分支限界
 * 
 */

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <time.h>

#define MAX(a, b) (((a) > (b))? (a) : (b))

#define N 8         /** 物品种类 */
#define C 50        /** 书包容量 */
int w[N];           /** 物品重量 */
int v[N];           /** 物品价值 */
bool selected[N];
int max_value;

// N+1 层树，选或者不选

typedef struct node {
    struct node* parent;    /** 父节点 */
    bool flag;              /** 选择父节点 */
    bool selected[N];       /** 物品选择 */
    int stage;              /** 层数 */
    int value;              /** 总价值 */
    int weight;             /** 总重量 */
    int max_value;          /** 最大总价值 */
}node;


void node_init(node* np, node* pnp, bool flag) {
    np->flag = flag;
    if(!pnp) {
        np->parent = NULL;
        np->stage = 0;
        np->value = 0;
        np->weight = 0;
        np->max_value = 0;
        return;
    }
    np->parent = pnp;
    np->stage = pnp->stage + 1;
    np->selected[pnp->stage] = flag;
    if(flag) {
        np->value = pnp->value + v[pnp->stage];
        np->weight = pnp->weight + w[pnp->stage];
    }
    np->max_value = MAX(np->value, pnp->value);
}

node* queue[100];
int front = 0, rear = 0;
void enqueue(node* np) {
    queue[++rear] = np;
}
node* dequeue() {
    return queue[++front]; 
}
bool is_qempty() {
    return front == rear;
}

int get_retird_value(int stage) {
    int sum = 0;
    for(int i = stage; i < N; i++) {
        sum += v[stage];
    }
    return sum;
}

bool refresh_max(node* np) {
    if(np->max_value > max_value) {
        max_value = np->max_value;
        for(int i=0; i<np->stage; i++) {
            selected[i] = np->selected[i];
        }
        return true;
    }
    return false;
}


void bfs_bag() {
    node* root = (node*)malloc(sizeof(node));;
    node_init(root, NULL, true);
    enqueue(root);
    while(!is_qempty()) {
        node* temp = dequeue();
        if(temp->stage > N) {
            break;
        }
        refresh_max(temp);
        bool flag = true;
        if(temp->weight + w[temp->stage] > C) {
            flag = false;
        }
        node* lnp = (node*)malloc(sizeof(node));;
        if(flag) {  // 左子树
            node_init(lnp, temp, true); // 选择 temp
            enqueue(lnp);
        }
        if(temp->value + get_retird_value(temp->stage) > temp->max_value) {
            node* rnp = (node*)malloc(sizeof(node));
            node_init(rnp, temp, false); // 不选择 temp
            if(flag) {
                rnp->max_value = lnp->max_value;
            }
            enqueue(rnp);
        }
    }
}



int main() {
    printf("c6_2:  w   v   | w   v");
    // 生成随机种子
    srand(time(0));
    // 生成随机的重量和价值
    for (int i = 0; i < N; i++) {  /** 数据 0~N-1 */
        w[i] = rand() % 100 + 1; // 随机生成1到100的重量
        v[i] = rand() % 100 + 1; // 随机生成1到100的价值
        if(i % 2 == 0) {
            printf("\n       %-3d %-3d", w[i], v[i]);
        }else{
            printf(" | %-3d %-3d", w[i], v[i]);
        }
    }

    bfs_bag();
    printf("\n       Cap = %d, Value = %d\n", C, max_value);
    return 0;
}