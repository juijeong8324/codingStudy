#include <iostream>

using namespace std;

void swap(int& a, int& b);
void sort(int left, int right, struct Attack *data);

struct Attack{
    int power;
    int hp;
};
int main(void) {
    int monster; // 몬스터 목숨
    int count; // 무기 개수 
    int num = 0; // 공격 횟수 

    cin >> monster >> count;
    Attack *monster_a = new Attack[count];

    for (int i = 0; i < count; i++) { // 배열에 값 저장
        cin >> monster_a[i].power >> monster_a[i].hp;
    }
 
    sort(0, count - 1, monster_a);

    int i = 0;
     // 몬스터가 작을 때까지 계산          
    while (monster > 0) {
             int c = monster / (monster_a[i].power);

             if (c >= monster_a[i].hp) {
                 monster = monster - monster_a[i].power * monster_a[i].hp;
                 num = num + monster_a[i].hp;
             }
             else { // c < monster_a[i].hp
                 if (monster % monster_a[i].power != 0) {
                        monster = monster - monster_a[i].power*(c+1);
                        num = num + (c+1);
                 }
                 else {
                     monster = monster - monster_a[i].power *c;
                     num = num + c;
                 }
                 
             }
             i++;
     }


    delete []monster_a;
    cout << num;

    return 0;
}

void swap(int& a, int& b) {
    int temp = a;
    a = b;
    b = temp;
}
void sort(int left, int right, struct Attack* data) {
    int p = left; // 기준 인덱스
    int i = p + 1; // 왼쪽 출발
    int j = right; // 오른쪽 출발

    while (i <= j) {
        while (i <= right && data[i].power >= data[p].power) {
            i++; // i가 끝부분보다 전이고 i의 power가 pivot 보다 크면 냅둔다
        }

        while (j > left && data[j].power <= data[p].power) {
            j--;
        }

        if (i > j) { // 즉 i와 j가 엇갈린 상황이라면 
            swap(data[j].power, data[p].power);
            swap(data[j].hp, data[p].hp);
        }
        else {
            swap(data[j].power, data[i].power);
            swap(data[j].hp, data[i].hp);
        }

        sort(left, j-1, data); // 왼쪽 다시 정렬
        sort(j + 1, right, data); //오른쪽 정렬
    }
}
