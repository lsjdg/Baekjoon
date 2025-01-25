from collections import deque

trucks, length, max_weight = map(int, input().split())
queue = deque(map(int, input().split()))

bridge = deque()
timestamp = 0
weight_sum = 0


def test_and_push_truck():
    global weight_sum
    if queue and weight_sum + queue[0] <= max_weight:
        truck_weight = queue.popleft()
        bridge.append([truck_weight, 0])
        weight_sum += truck_weight


def pass_time_and_pop_truck():
    global weight_sum
    for i in range(len(bridge)):
        bridge[i][1] += 1

    if bridge and bridge[0][1] == length:
        weight_sum -= bridge[0][0]
        bridge.popleft()


while queue or bridge:
    pass_time_and_pop_truck()
    test_and_push_truck()
    timestamp += 1

print(timestamp)
