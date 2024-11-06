import collections

n,m = [int(x) for x in input().split()]

largo_task = [int(x) for x in input().split()]
break_time = [int(x) for x in input().split()]

break_time.sort()
largo_task.sort()

break_time = collections.deque(break_time)
largo_task = collections.deque(largo_task)

ans = 0

while break_time and largo_task:
    if break_time.popleft() >= largo_task[0]:
        ans += 1
        largo_task.popleft()

print(ans)