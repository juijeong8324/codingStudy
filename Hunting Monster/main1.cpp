// 전략 버블 정렬 후 그리디 알고리즘  
// 문제점 시간과 메모리 낭비가 너무 크다.. 만약 첫 번째 무기 공격력으로 몬스터가 죽는다면 굳이 무기를 모두 정렬할 필요가 
#include <iostream>

using namespace std;

void swap(int& a, int& b); // 자리 바꾸는 함수
void sort(int left, int right, struct Attack *data); // 버블 정렬 

struct Attack{ // 하나의 무기의 공격력 + HP 
    int power;
    int hp;
};

int main(void) {
    int monster; // 몬스터 목숨
    int count; // 무기 개수 
    int num = 0; // 공격 횟수 

    cin >> monster >> count;
    Attack *monster_a = new Attack[count]; // 주의!! 동적할당 

    for (int i = 0; i < count; i++) { // 배열에 값 저장
        cin >> monster_a[i].power >> monster_a[i].hp;
    }
 
    sort(0, count - 1, monster_a); // 버블 정렬

    int i = 0;
     // 몬스터가 작을 때까지 계산          
    while (monster > 0) {
             int c = monster / (monster_a[i].power); // 몫을 저장

             if (c >= monster_a[i].hp) { // 무기의 hp가 현재 monster 목숨을 다 없애지 못 하는 경우 
                 monster = monster - monster_a[i].power * monster_a[i].hp; // 일단 hp라도 다 쓰자^^
                 num = num + monster_a[i].hp;
             }
             else { // c < monster_a[i].hp 즉 무기의 hp가 현재 monster 목숨을 다 없애고도 남는 경우
                 if (monster % monster_a[i].power != 0) { // 만약 몬스터의 목숨이(=나머지) 0이라면 
                        monster = monster - monster_a[i].power*(c+1); // 몫 + 1 값으로 나머지를 다 없애주자!
                        num = num + (c+1);
                 }
                 else {
                     monster = monster - monster_a[i].power *c; // 몬스터의 목숨이 남지 않는다면 그냥 몫만큼의 개수만큼 없애준다! 
                     num = num + c;
                 }
                 
             }
             i++; // 다음 무기 공격력으로 
     }


    delete []monster_a; // 주의 동적할당 해제 
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

        if (i > j) { // 즉 i와 j가 엇갈린 상황이라면 pivot과 j를 바꿔준다! 
            swap(data[j].power, data[p].power);
            swap(data[j].hp, data[p].hp);
        }
        else { // 엇갈리지 않았다면 i와 j를 바꿔준다! 
            swap(data[j].power, data[i].power);
            swap(data[j].hp, data[i].hp);
        }

        
    }
    sort(left, j-1, data); // 왼쪽 다시 정렬
    sort(j + 1, right, data); //오른쪽 정렬
}
