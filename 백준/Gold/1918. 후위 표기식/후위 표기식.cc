#include <iostream>
#include <string>
using namespace std;

const int MAX_STACK_SIZE = 100;
class ArrayStack {
private:
   int top;
   char data[MAX_STACK_SIZE];
public:
   ArrayStack() { top = -1; } // top의 초기값은 -1로 설정 돼있음 // 하나 채워지면 배열의 시작인 0부터
   ~ArrayStack() {}
   bool isEmpty() { return top == -1; }
   bool isFull() { return top == MAX_STACK_SIZE; }

   void push(double e) { data[++top] = e; }// 원래 탑보다 한 칸 추가된 곳에 e 삽입
   char pop() { return data[top--]; }// data를 리턴하고 탑 값 하나 내림(요소 삭제)
   char peek() { return data[top]; } // 요소 삭제하지 않고 값만 리턴
   
};
// 연산자 우선순위 계산
inline int precedence(char op) {
   switch (op) {
   case '(': case ')': return 0;
   case '+': case '-': return 1;
   case '*': case '/': return 2;
   }
   return -1;
}
int main() {
   ArrayStack dudtls;
   string s;
   cin >> s;
   char op; // op = 탑스택에 있는 연산자
   for (int i = 0; i < s.length();i++) {
      if (s[i] >= 'A' && s[i] <= 'Z') cout << s[i]; // 숫자면 바로 출력

      else if (s[i] == '(') dudtls.push(s[i]); // 왼쪽 괄호는 우선순위 제일 낮음
      else if (s[i] == ')') { // 오른쪽 괄호 나오면 stack에 들어있는 연산자 전부 출력(왼쪽괄호 빼고)
         while (!dudtls.isEmpty()) {
            op = dudtls.pop();
            if (op == '(') break;
            else cout << op;
         }
      }
      else if (s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/') { // 연산자 우선순위 비교해서 스택에 넣음
         while (!dudtls.isEmpty()) {
            op = dudtls.peek();
            if (precedence(s[i]) <= precedence(op)) { // 탑스택의 우선순위가 더 높으면 출력하고 새로 들어온 걸 스택에 넣음
               cout << op;
               dudtls.pop();
            }
            else break;
         }
         dudtls.push(s[i]);
      }
   }

   while (!dudtls.isEmpty()) cout << dudtls.pop(); // 스택에 남아있는 연산자들 모두 출력

}