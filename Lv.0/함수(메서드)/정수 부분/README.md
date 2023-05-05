## [링크](https://school.programmers.co.kr/learn/courses/30/lessons/181850)

![image](https://user-images.githubusercontent.com/63052097/236385397-b6cf533f-c83f-4eea-908a-5e22bfadd5aa.png)

---

<br>

## [형변환에 대해서](https://code-lab1.tistory.com/163) 
- 묵시적 형변환 : 컴파일러에 의해 결정, 데이터 표현이 넓은 범위에서 좁은 범위로 형변환 시 (ex. double -> int) 데이터 손실이 발생할 수 있음
```c++
float n = 55.55;
int n2 = n; // 55
bool n3 = n; // 1
```

- 명시적 형변환 : 사용자가 직접 데이터 타입을 변경
```c++
    float n = 12.13;
    int n2 = (int)n; // 12
    bool n3 = (bool)n; // 1
```
