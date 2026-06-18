class Solution:
    def angleClock(self, hour: int, minutes: int) -> float:
        #There are 60 points that makes 360 degree so each point 6 degree
        # the angle of the minute hand from 12:00
        minute_angle = minutes * 6.0
        # the angle of the hour hand from 12:00
        # % 12 ensures that 12 o'clock is treated as 0 degrees
        hour_angle = (hour % 12 * 30) + (minutes * 0.5)

        diff = abs(hour_angle - minute_angle)

        return round(min(diff, 360 - diff), 5)
