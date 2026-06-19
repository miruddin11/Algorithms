class Solution:
    def largestAltitude(self, gain: List[int]) -> int:
        max_altitude = 0
        pref = 0
        for g in gain:
            pref += g
            max_altitude = max(max_altitude, pref)
        return max_altitude