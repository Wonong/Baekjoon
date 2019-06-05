#include <cstdio>
#include <stdlib.h>

using namespace std;

typedef struct node node;

struct node{
    int id;     // id가 2이면, 포인터 확인
    int childNum[4];        // 각 4분면의 숫자, 2면 분할된 거.
    node* child[4];
    bool isTerminal;
};
int video[64][64];
int n;

int quadTree(node *nd, int fromR, int fromV, int dist);
void printQuadTree(node *nd);

int main(){
    node root;

    scanf("%d", &n);
    for(int i=0; i<n; i++){
        for(int j=0; j<n; j++){
            scanf("%1d", &video[i][j]);
        }
    }

    root.id = 2;

    quadTree(&root, 0, 0, n);
    printQuadTree(&root);
    printf("\n");
}

int quadTree(node *nd, int fromR, int fromV, int dist){

    if(dist == 1){
        nd->id = video[fromR][fromV];
        return nd->id;
    }

    // 배열 내 최초값으로 초기화, id가 2인 경우 현재 node의 요소들이 다 같은 값은 아님
    nd->id = video[fromR][fromV];

    for(int i=fromR; i<fromR+dist && nd->id != 2; i++){
        for(int j=fromV; j<fromV+dist; j++){
            if(nd->id != video[i][j]){
                nd->id = 2;
                break;
            }
        }
    }

    // 하나라도 다른 값 발견시, 각각의 4분면 재귀호출.
    if(nd->id == 2){
        // 이중for문으로 각각의 4분면 확인.
        for(int i=0; i<2; i++){
            for(int j=0; j<2; j++){
                nd->child[i*2+j] = (node*)malloc(sizeof(node));
                nd->childNum[i*2+j] = quadTree(nd->child[i*2+j], fromR+(dist/2)*i, fromV+(dist/2)*j, dist/2);
            }
        }
    }
    return nd->id;
    
}

void printQuadTree(node *nd){
    
    
    if(nd->id != 2){
        printf("%d", nd->id);
    }else{
        printf("(");
        for(int i=0; i<4; i++){
            if(nd->childNum[i] != 2){
                printf("%d", nd->childNum[i]);
            }else{
                printQuadTree(nd->child[i]);
            }
        }
        printf(")");
    }
    
}
