class Solution:
    def exclusiveTime(self, n: int, logs: List[str]) -> List[int]:
        prev_time = 0
        ans = [0] * n
        st = []
        for s in logs:
            fun_id, action, time = s.split(':')
            fun_id = int(fun_id)
            time = int(time)
            if action == "start":
                if len(st) > 0:
                    ans[st[-1]] += time - prev_time
                st.append(fun_id)
                prev_time = time
            else:
                ans[st[-1]] += time - prev_time + 1
                st.pop()
                prev_time = time + 1

        return ans