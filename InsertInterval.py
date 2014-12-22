class Interval:
	def __init__(self, s=0, e=0):
         self.start = s
         self.end = e

class Solution:
    # @param intervals, a list of Intervals
    # @param newInterval, a Interval
    # @return a list of Interval
	def insert(self, intervals, newInterval):
		result = []
		result.append(newInterval)
		start = newInterval.start
		end = newInterval.end
		index = 0
		for i in intervals:
			if i.end < start:
				index += 1
				result.insert(index-1, i)
			elif i.start > end:
				result.append(i)
			else:
				start = result[index].start = min(result[index].start, i.start)
				end = result[index].end	= max(result[index].end, i.end)
		# for i in result:
		# 	print str(i.start) + " " + str(i.end)
		return result


def main():
	s = Solution()
	intervals = []
	intervals.append(Interval(2, 6))
	intervals.append(Interval(7, 9))
	s.insert(intervals, Interval(15, 18))
main()
