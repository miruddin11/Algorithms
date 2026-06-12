class Solution:
    def reorderLogFiles(self, logs: List[str]) -> List[str]:
        def custom_sort(log):
            identifier, rest = log.split(' ', 1)
            # digit log
            if rest[0].isdigit():
                return (1,)
            #letter log
            else:
                return (0, rest, identifier)

        return sorted(logs, key = custom_sort)
            


            