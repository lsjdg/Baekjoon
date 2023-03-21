#include <iostream>
using namespace std;

int s; // (큐가 담을 수 있는 원소 개수)클래스 내에서도 사용해 줄거라서 전역변수로 선언

class Node {
public:
    Node* next = nullptr;
    int value;
};

class Queue {
public:
    Node* head = nullptr;
    Node* tail = nullptr;
    int size = 0;

    int getSize() { return size; }
    bool isEmpty() { return size == 0; }
    int front() {
        if (isEmpty()) { // 문제 조건 따라 비어있는 경우 에러처리
            return -1;
        }
        else {
            return head->value;
        }
    }
    int rear() {
        if (isEmpty()) { // 문제 조건 따라 비어있는 경우 에러처리
            return -1;
        }
        else {
            return tail->value;
        }
    }
    void enQueue(int value) { // tail에만 추가하는 경우
        
        
            Node* newNode = new Node;
            newNode->value = value; // 새 노드 생성 후 값 할당

            if (isEmpty()) { // 빈 경우
                head = tail = newNode; // head와 tail 모두 그 노드로 설정
            }
            else { // 노드가 있었다면
                tail->next = newNode; // 기존 tail 뒤에 새 노드 연결
                tail = newNode; // tail 업데이트
            }

            size++; // 사이즈 증가
        
    }
    void deQueue() { // head만 삭제하는 경우
        if (isEmpty()) { // 문제 조건 따라 비어있는 경우 에러처리
            cout << "Empty\n";
        }
        else {
            Node* deleteNode = head; // 삭제할 노드 지정 후 삭제할 값 출력
           // cout << deleteNode->value << "\n"; // 또는 head->value

            if (size == 1) { // 삭제하면 비게될 경우
                head = tail = nullptr; // head와 tail 모두 아무것도 안가리키게 설정
            }
            else { // 삭제해도 노드 존재할 경우 head 업데이트
                head = deleteNode->next; //또는 head->next
            }

            delete deleteNode; // head 삭제하는거 X
            size--; // delete 후 사이즈 감소
        }
    }
};

int main()
{
	int n, k;
	cin >> n >> k;
	
	Queue circle = Queue();
	Queue answer = Queue();
	for (int i{ 1 }; i <= n; i++)
	{
		circle.enQueue(i);
	}
	while (circle.getSize() > 0)
	{

		for (int i = 0; i < k - 1; i++) {

			circle.enQueue(circle.front());
			circle.deQueue();
		}
		answer.enQueue(circle.front());
		circle.deQueue();
	}

	cout << '<';
	for (int i{0}; i<n-1; i++)
	{
		cout << answer.front() << ", ";
		answer.deQueue();
	}
	cout << answer.front() << '>';
}